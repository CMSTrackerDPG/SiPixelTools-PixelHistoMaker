# Workflow for Automated Batch Submission on PSI Tier-3 with SLURM

This README describes the workflow used to automate batch job submission of the **PhaseIPixelHistoMaker** on the **PSI Tier-3** cluster using **SLURM**.  

Generally, the PixelHistoMaker analyzes the ntuples produced from PixelNtuplizer, as explained [here](https://github.com/nVassakis/SiPixelTools-PhaseIPixelNtuplizer/blob/dev_2025/test/batch/readme.md), produces plots stored in many ROOT files is used to merge the output succesively until there is one ROOT file for convenience with all the plots that are to be plotted. 


Details of the PixelHistoMaker itself, installation process and how it is used can be found on this [README](https://github.com/CMSTrackerDPG/SiPixelTools-PixelHistoMaker).  
**This document focuses only on the submission workflow used for processing *2025 data*.** It is *not* a full description of all script features.

## The workflow

### 1. Check the input ntuples exsits

The output from Ntuplizer should be in the specified directory, where each root file corresponds to one run in the structure:

```
taskname/
├── logs/
├── Ntuple_0001.root
├── Ntuple_0002.root
├── ...
└── Ntuple_XXXX.root
```

---

### 2. Create filelist

A filelist txt, eg. `Muon01_2025D.txt`, that will serve as input for the next step should be created. This txt can contain both `Muon0` and `Muon1` datastreams since they correspond to the same runs.

A usefull command for printing the locations of a file within a dir:
```
ls -p | grep -v / | sed "s|^|$(pwd)/|"
```

---

### 3. Create the task directory

By running:
```
python3 slurm/my_batch_sub_script.py --taskname Muon01_2025D --input filelists_tmp/Muon01_2025D.txt --create
```

This will read the `filelists_tmp/Muon01_2025D.txt` and create a new task directory at:
```
PHM_PHASE1_out/Muon01_2025D/
├── filelists/         
├── all_input.txt      
├── slurm_jobscript.sh  # Copy of SLURM template
├── alljobs.sh          
├── test.sh             
└── summary.txt         
```

After the creation it will prompt for immediate submission (`y / n / test`)

---

### 4. Submitting the jobs

By prompting `y`, all the jobs for all runs are immediately submitted.

If `n` is chosen, the runs can be submitted later by running:
```
python3 my_batch_sub_script.py --taskname Muon01_2025D.txt --submit
```

A few things to have in mind during the submission:
* Make sure the CMSSW release specified in the `PHM_PHASE1_out/Muon01_2025D/slurm_jobscript.sh` corresponds to the appropriate release that was querried  through  **DAS → Configs** for the specific era that is analyzed.
* When running PixelHistoMaker running out of memory is a possibility. Empirically specifying `SBATCH --mem=16000` at `slurm_jobscript.sh` seems to suffice.
* The default output directory should be changed in `my_batch_sub_script.py` script, or otherwise can be specified with the `--outdir` option. Also, the log output directory is defined in the `my_batch_sub_script.py` script.

---

### 5. Monitoring job status

Check job progress with:
```
python3 my_batch_sub_script.py --taskname Muon01_2025D  --status
```

The script reports:

- **Pending (PD)** jobs  
- **Running (R)** jobs  
- **Done** (STDOUT log exists)  
- **Completed** (output ROOT file exists)

If the number of Jobs and  number of Completed jobs match, then analyzing was most likely successfull. Perhaps a quick scan through the log files that have been copied in the output directory can help as well.

---

### 6. Output directory structure

The following output directory structure once every job is completed

```
{OUT_PATH}/Muon01_2025D/
├── logs/                 
│   ├── {JOBNAME}_{JOBID}_0001.out
│   ├── {JOBNAME}_{JOBID}_0001.err
│   └── ...
├── badrocs/                   
│   ├── Badroc_List_0001.root
│   ├── Badroc_List_0002.root
│   └── ...
├── merged/             
│ 
├── Histos_0001.root          
├── Histos_0002.root
└── ...
```

---


### 7. Merging files

After all analysis jobs complete successfully the next step is to merge the individual `Histos_*.root` files into a single output file using `hadd` utility. Since merging dozens of files in one step can fail, the script uses a staged approach:

**Step 1: Initial merge**
```
python3 slurm/my_batch_sub_script.py --taskname Muon01_2025D --hadd --nfile 5
```
* Each merge job will combine 5 `Histos_*.root` files (specified by `--nfile`)
* Submits parallel merge jobs to SLURM
* Outputs: {OUT_PATH}/Muon01_2025D/merged/merged_histos_*.root

**Step 2-5: Successive merging**
```
python3 slurm/my_batch_sub_script.py --taskname Muon01_2025D --hadd --nfile 5 --step_two
python3 slurm/my_batch_sub_script.py --taskname Muon01_2025D --hadd --nfile 5 --step_three
# ... and so on
```


