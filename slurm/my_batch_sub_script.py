# Author Tiziano Bevilacqua (05/13/2022) 
# Script to submit Phase1PixelHistoMaker jobs to slurm, tested on PSI tier3 
# The script that is run in the jobs require a consistent amount of memory, a small number of input files per job is suggested

import re, os, sys, glob, time, logging, multiprocessing, socket, subprocess, shlex, getpass, math, shutil, math
from optparse import OptionParser

# ---------------------- A few helping functions  ----------------------

def colored_text(txt, keys=[]):
    _tmp_out = ''
    for _i_tmp in keys:
        _tmp_out += '\033['+_i_tmp+'m'
    _tmp_out += txt
    if len(keys) > 0: _tmp_out += '\033[0m'

    return _tmp_out

def KILL(log):
    raise RuntimeError('\n '+colored_text('@@@ FATAL', ['1','91'])+' -- '+log+'\n')

def WARNING(log):
    print ('\n '+colored_text('@@@ WARNING', ['1','93'])+' -- '+log+'\n')

def MKDIRP(dirpath, verbose=False, dry_run=False):
    if verbose: print ('\033[1m'+'>'+'\033[0m'+' os.mkdirs("'+dirpath+'")')
    if dry_run: return
    try:
      os.makedirs(dirpath)
    except OSError:
      if not os.path.isdir(dirpath):
        raise
    return

def EXE(cmd, suspend=True, verbose=False, dry_run=False):
    if verbose: print ('\033[1m'+'>'+'\033[0m'+' '+cmd)
    if dry_run: return

    _exitcode = os.system(cmd)
    _exitcode = min(255, _exitcode)

    if _exitcode and suspend:
       raise RuntimeError(_exitcode)

    return _exitcode


color_dict = {
    "cyan": '\033[96m',
    "green": '\033[92m',
    "red": '\033[91m',
    "yellow": '\33[33m',
    "blue": '\33[34m',
    "white": '\033[37m',
    "bold": '\033[01m',
    "end": '\033[0m'    
}

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#
#- USAGE: ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#
#- python3 my_batch_sub_script.py --taskname [taskname] --input [txt file with list of input files] --nfile [number of files per job] --prog [program to execute] --outdir [directory to save output to] --create -#
#- python3 my_batch_sub_script.py --taskname [taskname] --status --------------------------------------------------------------------------------------------------------------------------------------------------#
#- python3 my_batch_sub_script.py --taskname [taskname] --submit --------------------------------------------------------------------------------------------------------------------------------------------------#
#- python3 my_batch_sub_script.py --taskname [taskname] --resubmit ------------------------------------------------------------------------------------------------------------------------------------------------#
#- python3 my_batch_sub_script.py --taskname [taskname] --missing -------------------------------------------------------------------------------------------------------------------------------------------------#
#- python3 my_batch_sub_script.py --taskname [taskname] --hadd ----------------------------------------------------------------------------------------------------------------------------------------------------#
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#

# Read options from command line
usage = "Usage: python %prog filelists [options]"
parser = OptionParser(usage=usage)
parser.add_option("--slurm_file",  dest="job_template",type="string",       default="slurm_template.sh", help="Slurm job template")
parser.add_option("--input",       dest="input",       type="string",       default="",    help="input filelist")
parser.add_option("--nfile",       dest="NFILE",       type="int",          default=1,     help="Tells how many input files to run in a single job (Default=1)")
parser.add_option("--sleep",       dest="SLEEP",       type="int",          default=3,     help="Wait for this number of seconds between submitting each batch job (Default 3s)")
parser.add_option("--create",      dest="create",      action="store_true", default=False, help="create taskdir under PHM_PHASE1_out/ and prepare submission scripts, it divide the input filelist (provided with --input) according to the number of file for each job (specified with --nfile)")
parser.add_option("--submit",      dest="submit",      action="store_true", default=False, help="submit jobs from task")
parser.add_option("--resubmit",    dest="resubmit",    action="store_true", default=False, help="prepare resubmit script with missing jobs")
parser.add_option("--status",      dest="status",      action="store_true", default=False, help="check status of submitted jobs (R, PD, Completed")
parser.add_option("--missing",     dest="missing",     action="store_true", default=False, help="look for missing jobs")
parser.add_option("--hadd",        dest="hadd",        action="store_true", default=False, help="Submit hadding job")
parser.add_option("--step_two",    dest="step_2",      action="store_true", default=False, help="Option to merge merged outputs")
parser.add_option("--step_three",  dest="step_3",      action="store_true", default=False, help="Option to merge merged merged outputs")
parser.add_option("--step_four",   dest="step_4",      action="store_true", default=False, help="Option to merge merged merged outputs")
parser.add_option("--step_five",   dest="step_5",      action="store_true", default=False, help="Option to merge merged merged outputs")
parser.add_option("--summary",     dest="summary",     action="store_true", default=False, help="Print info about job")
parser.add_option("--debug",       dest="debug",       action="store_true", default=False, help="Debug verbosity and skip removing of some intermediate files")
parser.add_option("--outdir",      dest="OUTDIR",      type="string",       default="/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixeltest", help="Output directory (Default: pnfs/.../pxeltest)")
parser.add_option("--queue",       dest="queue",       type="string",       default="standard", help="slurm queue to submit jobs to, default: standard, if this needs to be changed one should also have a look at the --time option")
parser.add_option("--time",        dest="time",        type="string",       default="12:00:00", help="slurm job time limit, default: 12:00:00, make sure not to exceed time limit for each partition (for limits ref to https://wiki.chipp.ch/twiki/bin/view/CmsTier3/SlurmUsage) ")
parser.add_option("--mem",         dest="mem",         type="string",       default="16000",    help="slurm job memory, default: 16000")
parser.add_option("--taskname",    dest="TASKNAME",    type="string",       default="HISTO_MAKER_DEFAULT", help="Output directory (Default: HISTO_MAKER_DEFAULT)")
parser.add_option("--prog",        dest="PROG",        type="string",       default="Phase1PixelHistoMaker", help="The main program to run")
(opt,args) = parser.parse_args()

# --------------------- Proxy check ----------------------

os.system("voms-proxy-info --timeleft > proxy.txt")
with open('proxy.txt') as proxyfile:
    lines = proxyfile.readlines()
    if len(lines)==1:
        if not "Proxy not found" in lines[0]:
            timeleft = int(lines[0])
os.remove('proxy.txt')
if timeleft<172800:
    print ("-"*60)
    print ("New proxy needed")
    print ("suggest to use: voms-proxy-init -voms cms -valid 168:00")
    print ("-"*60)
    raise RuntimeError("PROXY ERROR")
else:
    print ("-"*60)
    print ("Current proxy is long enough")
    print ("-"*60)

# ----------------------  Settings -----------------------
# Some further (usually) fixed settings, should edit them in this file

# Output directories/files
SUBTIME = time.strftime("%Y_%m_%d_%Hh%Mm%S", time.localtime())
if opt.OUTDIR == "":
    KILL("no output directory specified")

# Working directory, during running we cd here and back
OUT_PATH = opt.OUTDIR#+"/PixelHistoMaker"
EXEC_PATH = "../PHM_PHASE1_out/"+opt.TASKNAME

if opt.create:
    # Check input filelist
    if opt.input == "": KILL("no input filelist provided (--input files.txt)")
    # Summary file 
    os.system("echo \"process "+opt.TASKNAME+" summary\" > "+EXEC_PATH+"/summary.txt")
    os.system("echo \"\\n\" >> "+EXEC_PATH+"/summary.txt")


    # Create Task dir and copy input filelist and slurm template
    opt.input = os.path.abspath(opt.input)
    opt.job_template = os.path.abspath(opt.job_template)
    MKDIRP(EXEC_PATH+"/filelists")
    os.chdir(EXEC_PATH) 
    EXEC_PATH = os.getcwd()

    os.system("cp "+opt.input+" "+EXEC_PATH+"/all_input.txt")
    os.system("cp "+opt.job_template+" "+EXEC_PATH+"/slurm_jobscript.sh")

    # Summary file 
    os.system("echo \"Task name: "+opt.TASKNAME+"\" >> "+EXEC_PATH+"/summary.txt")
    os.system("echo \"Output dir: "+opt.OUTDIR+"\" >> "+EXEC_PATH+"/summary.txt")
    os.system("echo \"Input filelist: all_input.txt\" >> "+EXEC_PATH+"/summary.txt")
    os.system("echo \"Slurm jobs template: slurm_jobscript.sh\" >> "+EXEC_PATH+"/summary.txt")

    # Create filelist dir and filelists files to divide input files to jobs
    with open(opt.input) as fl:
        files = fl.readlines()
        njobs = int(len(files)/opt.NFILE)
        print ("-"*60)
        print ("number of jobs: "+str(njobs))
        print ("total input files: "+str(len(files)))

        # Summary file 
        os.system("echo \"Number of files per job: "+str(opt.NFILE)+"\" >> "+EXEC_PATH+"/summary.txt" )
        os.system("echo \"Number of jobs: "+str(njobs)+"\" >> "+EXEC_PATH+"/summary.txt")
        os.system("echo \"Total number of input files: "+str(len(files))+"\" >> "+EXEC_PATH+"/summary.txt")
        os.system("echo \"Program to run: "+opt.PROG+"\" >> "+EXEC_PATH+"/summary.txt")

        if os.path.isdir("./filelists"):
            if not os.listdir("./filelists"):
                print("Filelist directory is empty")
            else:    
                print("Filelist directory is not empty, removing old filelists...")
                os.system("rm filelists/*")
        else:
            print("Given filelist directory doesn't exist")

        for i, filename in enumerate(files):
            #idx = (int((i/(float(len(files))/100)) // 1) if (len(files) > 2) else 100)
            idx = int(i/opt.NFILE)
            ash = int(100.0/(njobs)*idx)
            print ("preparing file lists "+color_dict["cyan"]+"|"+"#"*ash+" "*(99-ash)+"|"+color_dict["end"], end="\r")
            EXE("echo "+filename[:-1]+" | awk '{ print $1 }' >> filelists/filelist_"+f'{idx:04}'+".txt")
        print ("\nprepared "+str(njobs)+" temporary filelists at: ")
        print (os.getcwd()+"/filelists")

    #change queue and execution time if needed
    if opt.queue != "standard":
        os.system("sed \"s;\#SBATCH --partition=standard;\#SBATCH --partition="+opt.queue+";g\" slurm_jobscript.sh > tmp")
        os.system("mv tmp "+EXEC_PATH+"/slurm_jobscript.sh")
    if opt.time != "12:00:00":
        os.system("sed -E \"s;\#SBATCH --time=([0-9]+):00:00;\#SBATCH --time="+opt.time+";g\" "+EXEC_PATH+"/slurm_jobscript.sh > tmp")
        os.system("mv tmp "+EXEC_PATH+"/slurm_jobscript.sh")
    if opt.mem != "16000":
        os.system("sed -E \"s;\#SBATCH --mem=([0-9]+)000;\#SBATCH --mem="+opt.mem+";g\" "+EXEC_PATH+"/slurm_jobscript.sh > tmp")
        os.system("mv tmp "+EXEC_PATH+"/slurm_jobscript.sh")
    
    # Prepare submission script with "sbatch [job name] [out-log] [out-err] slurm_jobscript.sh [stringa inutile] [job_label] [input_files_list] [output dir] [executable_name]  
    print ("")
    print ("Job Script file: "+opt.job_template)
    os.system("ls -l filelists | awk '{ print $NF }' | tail -n +2 | head -n -1 > filelists/job_list.txt")
    os.system("cat -n filelists/job_list.txt | awk '{ printf \"%.4d %s\\n\", $1, $2 }' | awk '{ print \"sbatch --job-name="+opt.TASKNAME+"_\"$1\" -o /work/%u/test/.slurm/%x_%A_\"$1\".out -e /work/%u/test/.slurm/%x_%A_\"$1\".err slurm_jobscript.sh "+opt.TASKNAME+"_JOB\"$1\" \"$1\" "+EXEC_PATH+"/filelists/\"$2\" "+OUT_PATH+"/"+opt.TASKNAME+" "+opt.PROG+"\"}' > alljobs.sh")
    os.system("head -1 alljobs.sh | sed \"s;0001;test;g;\" > test.sh")
    print 
    print ("jobs prepared at:", os.getcwd() )
    print ("as: alljobs.sh" )
    print ("or test 1 job with: test.sh")
    print ("-"*60)

    print ("-"*60)

    # Option to submit jobs right away
    answ = input("Do you want to directly submit the jobs to slurm (all jobs or 1 test job)? (y/n/test) \n")
    if str(answ) == "y":
        os.system("wc -l alljobs.sh | awk '{print \"submitting \"$1\" jobs from \"$2\" ...\"}'")
        EXE("sh alljobs.sh")   
    elif str(answ) == "test":
        os.system("wc -l test.sh | awk '{print \"submitting \"$1\" jobs from \"$2\" ...\"}'")
        EXE("sh test.sh") 
    print ("-"*60)


if not opt.create:
    # change queue and execution time if needed and only if you're not creating the 
    # job, otherwise it is handled in the previous section
    if opt.queue != "standard":
        os.system("sed \"s;\#SBATCH --partition=standard;\#SBATCH --partition="+opt.queue+";g\" "+EXEC_PATH+"/slurm_jobscript.sh > tmp")
        os.system("mv tmp "+EXEC_PATH+"/slurm_jobscript.sh")
    if opt.time != "12:00:00":
        os.system("sed -E \"s;\#SBATCH --time=([0-9]+):00:00;\#SBATCH --time="+opt.time+";g\" "+EXEC_PATH+"/slurm_jobscript.sh > tmp")
        os.system("mv tmp "+EXEC_PATH+"/slurm_jobscript.sh")
    if opt.mem != "16000":
        os.system("sed -E \"s;\#SBATCH --mem=([0-9]+)000;\#SBATCH --time="+opt.mem+";g\" "+EXEC_PATH+"/slurm_jobscript.sh > tmp")
        os.system("mv tmp "+EXEC_PATH+"/slurm_jobscript.sh")

# Same as before, ask for submission of jobs
if opt.submit:
    os.chdir(EXEC_PATH) 
    EXEC_PATH = os.getcwd()
    
    print ("-"*60)
    answ = input("Do you want to directly submit the jobs to slurm (all jobs or 1 test job)? (y/n/test) \n")
    if str(answ) == "y":
        os.system("wc -l alljobs.sh | awk '{print \"submitting \"$1\" jobs from \"$2\" ...\"}'")
        EXE("sh alljobs.sh")   
    elif str(answ) == "test":
        os.system("wc -l test.sh | awk '{print \"submitting \"$1\" jobs from \"$2\" ...\"}'")
        EXE("sh test.sh") 
    print ("-"*60)
    
# Check the status of submitted jobs, it recover job info from summary file in the task directory 
# and query squeue for pending and running jobs. Then check the output dir to look for completed jobs.
elif opt.status:
    print ("-"*60)
    with open(EXEC_PATH+"/summary.txt") as fl:
        lines = fl.readlines()
        for line in lines:
            fields = re.split(": |\n", line)
            if fields[0] == "Number of jobs":
                njobs = int(fields[1])
            elif fields[0] == "Task name":
                TASKNAME = fields[1]
            elif fields[0] == "Output dir":
                OUT_PATH = fields[1]
                
    os.system("( squeue -n `cat "+EXEC_PATH+"/alljobs.sh | awk '{print $2}' | sed 's;--job-name=;;g;' | sed ':label1 ; N ; $! b label1;s;\\n;,;g'` > taskjobs ) > /dev/null")
    os.system("grep PD taskjobs > Pending")
    os.system("grep \" R \" taskjobs > Running")
    os.system("( ls "+OUT_PATH+"/"+TASKNAME+" | grep .root > Completed ) >  /dev/null")
    os.system("sort -u Completed > Comp")
    os.system("mv Comp Completed")
    os.system("ls -l "+OUT_PATH+"/"+TASKNAME+"/logs | grep -v test | grep .out > Done")
    os.system("echo \"Status of Task "+TASKNAME+": ("+str(njobs)+" Jobs)\"")
    os.system("echo \"Jobs - Pending                : `wc -l Pending | awk '{ print $1}'`\"")
    os.system("echo \"     - Running                : `wc -l Running | awk '{ print $1}'`\"")
    os.system("echo \"     - Done (with STDOUT)     : `wc -l Done | awk '{ print $1}'`\"")
    os.system("echo \"------------------------------------\"")
    os.system("echo \"     - Completed (has output) : `wc -l Completed | awk '{ print $1}'`\"")
    os.system("rm taskjobs Pending Running Completed Done")
    print ("-"*60)
    
# Look for finished jobs and then prints number of jobs that are not in the output dir
elif opt.missing:
    print ("-"*60)
    with open(EXEC_PATH+"/summary.txt") as fl:
        lines = fl.readlines()
        for line in lines:
            fields = re.split(": |\n", line)
            if fields[0] == "Number of jobs":
                njobs = int(fields[1])
            elif fields[0] == "Task name":
                TASKNAME = fields[1]
            elif fields[0] == "Output dir":
                OUT_PATH = fields[1]

    os.system("ls "+OUT_PATH+"/"+TASKNAME+" | grep .root >> output")
    os.system("cat output | sort -u | sed 's;_; ;g;s;\.; ;g' | awk '{ printf \"%d\\n\", $(NF-1) }' > jobnums")
    os.system("seq 1 "+str(njobs)+" > Seq")
    os.system("diff Seq jobnums | grep \"<\" | awk '{ printf \"%d,\", $2 }' | sed 's;,$;\\n;'")
    os.system("rm Seq jobnums output")
    print ("-"*60)

# same as missing option but also prepare a resubmission script for such jobs
elif opt.resubmit:
    print ("-"*60)
    with open(EXEC_PATH+"/summary.txt") as fl:
        lines = fl.readlines()
        for line in lines:
            fields = re.split(": |\n", line)
            if fields[0] == "Number of jobs":
                njobs = int(fields[1])
            elif fields[0] == "Task name":
                TASKNAME = fields[1]
            elif fields[0] == "Output dir":
                OUT_PATH = fields[1]
    os.chdir(EXEC_PATH) 
    EXEC_PATH = os.getcwd()

    if opt.queue != "standard":
        os.system("sed \"s;\#SBATCH --partition=standard;\#SBATCH --partition="+opt.queue+";g\" slurm_jobscript.sh > tmp")
        os.system("mv tmp slurm_jobscript.sh")
    if opt.time != "12:00:00":
        os.system("sed -E \"s;\#SBATCH --time=([0-9]+):00:00;\#SBATCH --time="+opt.time+";g\" "+EXEC_PATH+"/slurm_jobscript.sh > tmp")
        os.system("mv tmp slurm_jobscript.sh")

    os.system("ls "+OUT_PATH+"/"+TASKNAME+" | grep .root >> output")
    os.system("cat output | sort -u | sed 's;_; ;g;s;\.; ;g' | awk '{ printf \"%d\\n\", $(NF-1) }' > jobnums")
    os.system("seq 1 "+str(njobs)+" > Seq")
    os.system("diff Seq jobnums | grep \"<\" | awk '{ printf \"%.4d,\", $2 }' | sed 's;,$;\\n;' > resubmit ")
    os.system("rm "+EXEC_PATH+"/resubmit.sh")
    with open("resubmit") as fl:
        files = fl.readlines()
        files = re.split(',|\n',files[0])
        for i,job in enumerate(files):
            if job == '': break
            ash = int(100.0/(len(files))*(i+2))
            print ("preparing resubmission jobs "+color_dict["cyan"]+"|"+"#"*ash+" "*(99-ash)+"|"+color_dict["end"], end="\r")
            os.system("grep ' "+job+" ' "+EXEC_PATH+"/alljobs.sh >> "+EXEC_PATH+"/resubmit.sh")
    os.system("rm Seq jobnums output resubmit")
    print("\nDone: resubmit.sh file created at "+EXEC_PATH+"/resubmit.sh")
    print ("-"*60) 

# Submit hadd job for files in the output directory
elif opt.hadd:
    print ("-"*60)
    print("Merging step")
    with open(EXEC_PATH+"/summary.txt") as fl:
        lines = fl.readlines()
        for line in lines:
            fields = re.split(": |\n", line)
            if fields[0] == "Number of jobs":
                njobs = int(fields[1])
            elif fields[0] == "Task name":
                TASKNAME = fields[1]
            elif fields[0] == "Output dir":
                OUT_PATH = fields[1]
            elif fields[0] == "Program to run":
                PROG = fields[1]

    os.chdir(EXEC_PATH) 
    EXEC_PATH = os.getcwd()
    nfile_pj = 11
    if opt.NFILE != 1:
        nfile_pj = opt.NFILE
    if opt.step_2:
        merged_dir = "/merged"
        merg = "merged | grep "
        import subprocess as sp  
        if int(sp.getoutput('ls -l filelists | grep merging | wc -l')) > 0: 
            print("removing old filelists")
            os.system("rm filelists/merging* ")
        njobs = int(sp.getoutput('ls -l '+OUT_PATH+'/'+TASKNAME+merged_dir+' | grep .root | wc -l'))
    elif opt.step_3:
        merged_dir = "/merged/merged"
        merg = "merged | grep "
        import subprocess as sp  
        if int(sp.getoutput('ls -l filelists | grep merging | wc -l')) > 0: 
            print("removing old filelists")
            os.system("rm filelists/merging* ")
        njobs = int(sp.getoutput('ls -l '+OUT_PATH+'/'+TASKNAME+merged_dir+' | grep .root | wc -l'))
    elif opt.step_4:
        merged_dir = "/merged/merged/merged"
        merg = "merged | grep "
        import subprocess as sp  
        if int(sp.getoutput('ls -l filelists | grep merging | wc -l')) > 0: 
            print("removing old filelists")
            os.system("rm filelists/merging* ")
        njobs = int(sp.getoutput('ls -l '+OUT_PATH+'/'+TASKNAME+merged_dir+' | grep .root | wc -l'))
    elif opt.step_5:
        merged_dir = "/merged/merged/merged/merged"
        merg = "merged | grep "
        import subprocess as sp  
        if int(sp.getoutput('ls -l filelists | grep merging | wc -l')) > 0: 
            print("removing old filelists")
            os.system("rm filelists/merging* ")
        njobs = int(sp.getoutput('ls -l '+OUT_PATH+'/'+TASKNAME+merged_dir+' | grep .root | wc -l'))
    else:
        merg = ""  
        merged_dir = ""   
    if njobs > 10:
        os.system("ls -l "+OUT_PATH+"/"+TASKNAME+merged_dir+" | grep "+merg+".root | awk '{ print \"/\" $9}' | sed \"s:^:"+OUT_PATH+"/"+TASKNAME+merged_dir+":\" | sed \"s:/pnfs/psi.ch/cms/trivcat/:root\://t3se01.psi.ch//:\" > filelists/tmp")
    else:
        os.system("ls -l "+OUT_PATH+"/"+TASKNAME+merged_dir+" | grep "+merg+".root | awk '{ print \"/\" $9}' | sed \"s:^:"+OUT_PATH+"/"+TASKNAME+merged_dir+":\" | sed \"s:/pnfs/psi.ch/cms/trivcat/:root\://t3se01.psi.ch//:\" > filelists/tmp")
    for i in range(int(math.ceil(float(njobs)/float(nfile_pj))) if math.ceil(njobs/nfile_pj) >= 1 else 1):
        os.system("tail -n "+str(nfile_pj)+" filelists/tmp > filelists/merging_"+str(i))
        os.system("head -n -"+str(nfile_pj)+" filelists/tmp > tmptmp")
        os.system("mv tmptmp filelists/tmp")
    
    os.system("rm filelists/tmp")

    os.system("ls -l filelists | grep merging | grep -v merging_job_list.txt | awk '{ print $NF }' > filelists/merging_job_list.txt")
                                           #$1              $2      $3      $4     $5       $6
    #sbatch jobname .out .log slurm.sh jobname(redundant) job_ID filelist outdir program --hadd
    os.system("cat -n filelists/merging_job_list.txt | awk '{ printf \"%.4d %s\\n\", $1, $2 }' | awk '{ print \"sbatch --job-name="+TASKNAME+"_MERGING_\"$1\" -o /work/%u/test/.slurm/%x_%A_\"$1\".out -e /work/%u/test/.slurm/%x_%A_\"$1\".err slurm_jobscript.sh "+TASKNAME+"_JOBMERGING\"$1\" \"$1\" "+EXEC_PATH+"/filelists/\"$2\" "+OUT_PATH+"/"+TASKNAME+merged_dir+" "+PROG+" --hadd\"}' > merging_alljobs.sh")
    os.system("head -1 merging_alljobs.sh | sed \"s;0001;test;g;\" > merging_test.sh")

    if opt.queue != "standard":
        os.system("sed \"s;\#SBATCH --partition=standard;\#SBATCH --partition="+opt.queue+";g\" slurm_jobscript.sh > tmp")
        os.system("mv tmp slurm_jobscript.sh")
    if opt.time != "12:00:00":
        os.system("sed -E \"s;\#SBATCH --time=([0-9]+):00:00;\#SBATCH --time="+opt.time+";g\" "+EXEC_PATH+"/slurm_jobscript.sh > tmp")
        os.system("mv tmp slurm_jobscript.sh")
    
    answ = input("Do you want to directly submit the jobs to slurm (all jobs or 1 test job)? (y/n/test) \n")
    if str(answ) == "y":
        os.system("wc -l merging_alljobs.sh | awk '{print \"submitting \"$1\" jobs from \"$2\" ...\"}'")
        EXE("sh merging_alljobs.sh")   
        os.system("wc -l merging_alljobs.sh | awk '{print \"submitted \"$1\" jobs from \"$2\" ...\"}'")
    elif str(answ) == "test":
        os.system("wc -l merging_test.sh | awk '{print \"submitting \"$1\" jobs from \"$2\" ...\"}'")
        EXE("sh merging_test.sh") 

    if not opt.debug:
        os.system("rm filelists/merging_job_list.txt")
        #os.system("rm filelists/merging*")

    print ("-"*60)
    #print "submitting merging job..."
    #os.chdir(EXEC_PATH) 
    #os.system("sbatch --job-name="+TASKNAME+"_MERGING -o /work/%u/test/.slurm/%x_%A_MERGING.out -e /work/%u/test/.slurm/%x_%A_MERGING.err slurm_jobscript.sh "+TASKNAME+"_JOBMERGING MERGING "+EXEC_PATH+"/filelists/dummystring "+OUT_PATH+"/"+TASKNAME+" "+PROG+" --hadd")
    #print ("-"*60)

elif opt.summary:
    os.system(f"cat {EXEC_PATH}/summary.txt") 