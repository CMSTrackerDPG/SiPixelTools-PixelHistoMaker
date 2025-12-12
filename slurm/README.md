# Workflow for Automated Batch Submission on PSI Tier-3 with SLURM

This README describes the workflow used to automate batch submission of the **PhaseIPixelHistoMaker**, as tested on PSI Tier-3 cluster using SLURM.

In short, the PixelHistoMaker analyzes ntuples produced by the `PhaseIPixelNtuplizer` [described here](https://github.com/nVassakis/SiPixelTools-PhaseIPixelNtuplizer/blob/dev_2025/test/batch/readme.md)
It produces many ROOT output files containing plots, these are later merged until a single ROOT file remains for convenience.

Details about the PixelHistoMaker itself, including installation instructions and usage, can be found in the corresponding [README](https://github.com/CMSTrackerDPG/SiPixelTools-PixelHistoMaker).  

**This document focuses only on the submission workflow used for processing *2025 data*.** It is *not* a complete description of all script features.

## The workflow

### 1. Check the input ntuples exsits

The output of the PixelNtuplizer must be available in the expected directory.
Each ROOT file corresponds to a single run and the directory should look like:

```
taskname/
├── logs/
├── Ntuple_0001.root
├── Ntuple_0002.root
├── ...
└── Ntuple_XXXX.root
```

---

### 2. Create a filelist

Create a `.txt` file (e.g. Muon01_2025D.txt) containing the full paths to all ROOT files that will be processed. This file can include both `Muon0` and `Muon1` datastreams, since they correspond to the same runs.

A useful command to generate a list of absolute file paths inside a directory:
```
ls -p | grep -v / | sed "s|^|$(pwd)/|"
```

---

### 3. Create the task directory

Run:
```
python3 slurm/my_batch_sub_script.py --taskname Muon01_2025D --input filelists_tmp/Muon01_2025D.txt --create
```

This reads `filelists_tmp/Muon01_2025D.txt` and creates a new task directory:
```
PHM_PHASE1_out/Muon01_2025D/
├── filelists/         
├── all_input.txt      
├── slurm_jobscript.sh  # Copy of SLURM template
├── alljobs.sh          
├── test.sh             
└── summary.txt         
```

After creation, the script will prompt for immediate submission (`y / n / test`)

---

### 4. Submitting the jobs

By prompting `y`, all jobs (one per run) will be submitted immediately.

If `n` is chosen, jobs can be submitted later with:
```
python3 my_batch_sub_script.py --taskname Muon01_2025D.txt --submit
```


**Before submission**

Each SLURM job clones and compiles PixelHistoMaker from scratch in the worker node's scratch space (`/scratch/${USER}/slurm/...`). To use the correct version, specify the repository and branch in `slurm_jobscript.sh`:
```
git clone -b <branch_name> <repository_url> SiPixelTools/PixelHistoMaker
```
The `<repository_url>` and `<branch_name>` should be replaced with the target repository and branch. This determines which version of the code is compiled and executed on the batch nodes. Therefore, make sure all changes are committed and pushed to the remote repository before submitting jobs, as only the code present in the remote branch will be included in the build.


**Luminosity Updates**

Also before submission, update the luminosity configuration as described in the top-level README:
* Ensure `input/run_ls_intlumi_pileup_phase1_Run3_2025.txt` includes only the runs being analyzed.
* Confirm that the updated `.txt` file is correctly imported in `interface/Variables.h`. 
* In `PhaseIPixelHistoMaker.cc`, verify the integrated-luminosity range at `IntLumiRunIII` for trend plots, ensuring that each bin corresponds to 1 fb⁻¹ and that the total range fully covers the integrated-luminosity interval of all runs under analysis.


**Additional notes for submission**

* Ensure that the CMSSW release set inside `PHM_PHASE1_out/Muon01_2025D/slurm_jobscript.sh` matches the release obtained from  **DAS → Configs** for the dataset/era being analyzed.
* PixelHistoMaker can run out of memory. Empirically, setting `#SBATCH --mem=16000` in `slurm_jobscript.sh` works reliably.
* The default output directory is defined inside `my_batch_sub_script.py`. It can be overwritten using the `--outdir` option. Also, log output paths are also configured inside this script.

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

If the numbers of `Jobs` and `Completed` jobs match, the analysis most likely finished successfully. A quick scan of the copied log files in the output directory is also recommended.

---

### 6. Output directory structure

Once all jobs have completed, the output directory will have the following structure:


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
* Outputs: `{OUT_PATH}/Muon01_2025D/merged/merged_histos_*.root`

**Step 2-5: Successive merging**
```
python3 slurm/my_batch_sub_script.py --taskname Muon01_2025D --hadd --nfile 5 --step_two
python3 slurm/my_batch_sub_script.py --taskname Muon01_2025D --hadd --nfile 5 --step_three
python3 slurm/my_batch_sub_script.py --taskname Muon01_2025D --hadd --nfile 5 --step_four
python3 slurm/my_batch_sub_script.py --taskname Muon01_2025D --hadd --nfile 5 --step_five
```
* Each step merges outputs from the previous step into nested `merged/` directories
* Merging jobs require more memory than analysis jobs. For `--nfile 5`, it may be needed to increase memory allocation to `SBATCH --mem=32000` in `slurm_jobscript.sh`

---

### 8. Final output structure

After completing all merging steps, the final directory structure will be:

```
{OUT_PATH}/{TASKNAME}/
├── logs/                 
│   ├── {JOBNAME}_{JOBID}_0001.out
│   ├── {JOBNAME}_{JOBID}_0001.err
│   └── ...
├── badrocs/                   
│   ├── Badroc_List_0001.root
│   └── ...
├── merged/             
│   ├── merged_histos_0001.root
│   ├── merged_histos_0002.root
│   └── merged/                # --step_two outputs
│       └── merged/            # --step_three outputs
│           └── merged/        # --step_four outputs
│               └── merged/    # --step_five outputs    
├── Histos_0001.root          
├── Histos_0002.root
└── Histos_XXXX.root
```

The final merged ROOT file, the deepest nested `merged_histos_0001.root`,  contains all histograms from all runs and is ready for plotting.

---

### 9.  Merging across eras (or years)

Since data processing is performed separately for different eras (e.g., 2025B, 2025C, 2025D), all era-specific merged files can be combined into a single ROOT file for the entire year.

This step is performed manually using the Phase1PixelHistoMaker executable. For example, to merge outputs from three eras:
```
./Phase1PixelHistoMaker -o /histomaker/merged_2025.root \
-a /histomaker/Muon01_2025B/merged/merged/merged/merged/merged_histos_0001.root \
/histomaker/Muon01_2025C/merged/merged/merged/merged/merged_histos_0001.root \
/histomaker/Muon01_2025D/merged/merged/merged/merged/merged_histos_0001.root
```

### 10. Plotting

The final merged ROOT file from all eras is used as input for the plotting script `scripts/MakePerformancePlots.py`.

**For trend plots:** 
* Update the `metadata_int` dictionary with the filepath to the all-eras merged ROOT file
* Update detector condition markers according to relevant changes (CPE updates, HV changes, technical stops). The detector condition updates can be found [here](https://twiki.cern.ch/twiki/bin/viewauth/CMS/PixelOfflineConditionUpdates).


**For cluster property plots:**
* Update the `metadata` dictionary with the filepath to the ROOT file containing runs from a single fill
* Set the `int_lumi` value corresponding to that fill