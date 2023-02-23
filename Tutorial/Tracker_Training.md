# Tracker Training - Phase1PixelHistoMaker
This file contains instruction to run a simple example that (hopefully) will make clearer hot to run an analysis using the [CMSTrackerDPG/SiPixelTools-PixelHistoMaker](https://github.com/CMSTrackerDPG/SiPixelTools-PixelHistoMaker). The two main use cases of the script in this directory are the measurement of the performance of the CMS Pixel Tracker via the Hit Efficiency and Cluster Properties monitoring, and performing the Timing Scans, needed to study the performances of the detector as a function of the delay applied to different parts of the  Pixel Tracker. These tasks are performed running two scripts: `Phase1PixelHistoMaker` and `Phase1ScanHistoMaker`.

For the sake of this demonstration we will try to provide instrusctions to run a MiniTiming scan using data from Run3 (September 2022).

## Installation

This tool is based on `CMSSW`, as a first step we will create an environment to work whith on `lxplus`:

connect to `lxplus` and move to the work directory of your choice (`workdir` in the following)
```
ssh -XY [your-cern-username]@lxplus.cern.ch
cd /path/to/workdir
```
then we will set up a scram area and move in the `src` directory.
```
cmsrel CMSSW_10_2_16_UL
cd CMSSW_10_2_16_UL/src
cmsenv
```
The next step is to clone the package directory from GitHub
```
git clone -b TrackerTraining git@github.com:TizianoBevilacqua/SiPixelTools-PixelHistoMaker.git SiPixelTools/PixelHistoMaker
cd SiPixelTools/PixelHistoMaker
```
we also create a directory to store output files and build the desired script with `cmake`
```
mkdir PHM_PHASE1_out
make clean
```
last step is to set up a proxy to be able to access the grid
```
voms-proxy-init --voms cms:/cms --valid 168:00 --rfc
```
## Run the Mini-Timing-Scan

To run an analysis with the scripts in this directory, input NTuples containing flat trees produced with [CMSTrackerDPG/SiPixelTools-Phase1PixelNtuplizer](https://github.com/CMSTrackerDPG/SiPixelTools-PhaseIPixelNtuplizer) have to be provided. For the sake of time this step has already been performed, and the files can be accessed via `xrdroot` (see next steps).

Now let's have a look to the structure of the code we will be using, opening a few random files in this directory you will notice on the spot that these are not crystal clear and that additions have built up in layers over time. Here are listed a few interesting places that are worhty of being pointed out to understand how this analysis is performed.

### Phase1ScanHistoMaker.cc

The first ~90 lines of this file are used to configure the scan: 
* define which version of the included files has to be used $\rightarrow$ [lines](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L40) 40-71, 
* choose the type of scan `Timing` or `Bias` to be performed and select which class of histograms we want to "activate" and save in the ouput $\rightarrow$ [lines](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L83) 83-86,
* define the configuration of the Pixel detector $\rightarrow$ [lines](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L74) 74-79,
* select which class of trees has to be used in the scan $\rightarrow$ [lines](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L30) 30-32 [lines](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L129) 129-133
* define the distance between the track and the cluster to consider an Hit as valid in the Hit Efficiency calculation $\rightarrow$ [line](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L37) 37 and [lines](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L418) 418-419.

The last bullet introduces an important point. The scan script makes use of a `SmartHisto` (`sh`) class (defined in the `interface/SmartHistos.h` [file](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/interface/SmartHistos.h)), two of the main features that are used here are the `FillParameter`s, that basically define the structure of the histograms to be produced, such as binning, range, fill criteria and so on, and the `PostFix`es that consist in the parameter to be explored in the histograms.

The actual histogram definition is done combining the previously defined parameters (`FillParameter`s and `PostFix`es) using the `AddHisto` method of the `sh`, examples can be seen all over the place but in particular let's have a look at [line 557](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L557) where the histograms for the TimingScan are defined. When using `AddHistos` other things can/have to be specified, such as:
* `cuts` to be used to select the tracks, this are defined via another method of the `sh` class, `sh.AddNewCut()`, and can be specified directly (as can be seen at [line 436](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L436) for a cut regarding the belonging of an hit to a specific layer or taken from other input files as for the HitEfficiency cuts, [line 428](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L428)
* options for drawing and other matters such as particular error handling cases, 
* ranges to be shown by default in the TCanvas.

Apart from the histogram definition that is the main part to edit when trying to implement changes in the code, in this file the other relevant classes and variables that are used are:
```
RunData run; LumiData lumi; EventData e; TrajMeasurement t; Cluster c; 
```
that comes from the inclusion of `interface/DataStruct_Phase1_v9.h`, and that hold variables read from TTrees and are passed to the instance of the `TreeReader` (included from `interface/TreeReader_Phase1_v4.h`) at [line 127](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L127);

```
TreeLooper looper(&tr, &v, EVT_LOOP, TRAJ_LOOP, CLUST_LOOP);
```
that as the name suggest has the task of looping over the entries of the trees ([line 1024](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L1024)); and

```
Variables v;
```
that is an object defined in `interface/Variables.h` that contains variables derived from `DataStruct` members.

### interface/scan_points.h

This file is crucial to the good outcome of the scans, it encodes timing and bias informations for the scans. Every time a new scan is performed, new information about the scan points and corresponding run numbers and delays have to be added:
* **run numbers** and related scan numbers at the bottom of `delay_scan_number()` function, [line 9](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/interface/scan_points.h#L9), 
* **delays** at the bottom of the `delay()` one, [line 428](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/interface/scan_points.h#L428)

the scan number set in the `delay_scan_number()` has to be the same as the one set for the `"DelayScans"` `PostFix` at [line 207](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/Phase1ScanHistoMaker.cc#L207) of `Phase1ScanHistoMaker.cc`.

### Luminosity informations

This section is more relevant for the `Phase1PixelHistoMaker` script than for the production of the TimingScan, but still very important. To allow the code to be aware of the luminosity informations of different runs a file obtained using `brilcalc` to extract the delivered luminosity and PileUp of each lumisection (ls) is stored in the `input` directory. The structure of this file has changed during the ages but for Run3 the relevant file is `input/run_ls_intlumi_pileup_phase1_Run3.txt`, it basically contains 4 columns of number that should correspond to the 4 quantities stated in the name of the file itself.

To update this file when new runs are analysed one can run these command after having installed brilcalc:
```
brilcalc lumi --byls -u /nb --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_BRIL.json --begin "01/01/22 00:00:00" --end "12/31/25 23:59:59" |& tee brilcalc_Run3.log

cat brilcalc_Run3.log | head -n-8 | tail -n+5 | sed "s;|;;g;s;:; ;g" | awk '{ print $1" "$3" "$(NF-3)" "$(NF-1) }' > run_ls_intlumi_pileup_phase1_Run3.txt
```
where the `--begin` and `--end` points has to be changed according to one's needs, and can be set as dates, fill numbers or run numbers.

This file is then loaded and used in the script in the `interface/Variables.h` file at [line 907](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/interface/Variables.h#L907), the integrated luminosity of each ls is given in nb and used to extract the instantaneous one as well. These numbers are used when producing HitEfficiency VS InstLumi, HitEfficiency VS Pileup and trend plots as a function of the integrated luminosity.

### Bad ReadOutChips (ROCs) exclusion

Again this section is more relevant for the `Phase1PixelHistoMaker` script than for the Scans but is fundamental to get sensible results. In our analysis of the performances of the Pixel we want to exclude ROCs that are not behaving properly in the run for whatever reason. To do so we use a bookkeeping file that stores the information about the ROCs that are marked as bad in each run. This file is placed in the `input` directory as `input/Badroc_List.root`. It stores histograms for each analysed run containing the ID numbers of the incriminated ROCs (in an arcane and mysterious scheme) and a distribution of the HitEfficiency of the ROCs in the run. The list is loaded every time the code is used, and updated when a new run is processed or more statistycs is accumulated for an already processed one. Thus whenever one is interested in results concerning new runs the code has to be run twice to account for and exclude bad ROCs (the `-b` flag can be use to speed up the process in the first iteration of the execution).

The handling of loading and updating of the file is dealt with in the `interface/Variables.h` file at [line 1084](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/interface/Variables.h#L1084), with the `load_roc_sel()` function and in the `interface/TreeLooper.h` at [line 512](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/interface/TreeLooper.h#L512) with the `badroc_run_()` function.

The Bad ROCs for the event are instead excluded at [line 1677](https://github.com/TizianoBevilacqua/SiPixelTools-PixelHistoMaker/blob/TrackerTraining/interface/Variables.h#L1677) of the `interface/Variables.h` file.

### Hands on

Now that we have had a look at the basic concepts we can try to reproduce the results for the September 2022 MiniTimingScan. First of all we have to recover informations about the delays set in each run by looking at the [elog](https://cmsonline.cern.ch/webcenter/portal/cmsonline/Common/Elog?_piref683379043.strutsAction=/viewMessageDetails.do?msgId=1157556) of the scan.

Once we know the setting of the scan we can update the `interface/scan_points.h` file with the new values for our scan, making sure to link the run numbers with both the scan number and delays (hint: add new entries to both `delay_scan_number()` and `delay()` functions).

Then we can update the `"DelayScans"` `PostFix` to match the number of our newly created entry of `interface/scan_points.h`, is good practice not to directly change the numbers but to copy the line and comment out the older one to keep track easily of previous scans.

Now we can run the code at last, first we compile our changes
```
make -j8 Phase1ScanHistoMaker
```
then we can run the Timing Scan on the NTuples starting with run 359576, we run it twice (first with the `-b` flag to speed up) to update the BadROCs list. 
``` 
#root://t3dcachedb03.psi.ch:1094/pnfs/psi.ch/cms/trivcat should be an alternative to root://cms-xrd-global.cern.ch/
./Phase1ScanHistoMaker -b -o PHM_PHASE1_out/Histo_TimingScan_Sep2022_run359576_badrocrun.root root://cms-xrd-global.cern.ch//store/user/bevila_t/TrackerTutorial/input_files/NTuple_run359576.root

./Phase1ScanHistoMaker -o PHM_PHASE1_out/Histo_TimingScan_Sep2022_run359576.root root://cms-xrd-global.cern.ch//store/user/bevila_t/TrackerTutorial/input_files/NTuple_run359576.root
``` 
in principle each run should be processed but for the sake of time we already provide you with the outputs for the other runs, that can be accessed via `xrootd`. 
Once we have all the outputs for the different runs we have to combine them, so we run the `Phase1ScanHistoMaker` once more with the `-a` flag, providing the script with all the paths to the other files (two in this case)
```
./Phase1ScanHistoMaker -o PHM_PHASE1_out/Histo_TimingScan_Sep2022_merged.root -a PHM_PHASE1_out/Histo_TimingScan_Sep2022_run359576.root root://cms-xrd-global.cern.ch//store/user/bevila_t/TrackerTutorial/input_files/merged_Histos_SepTS_runs359577_359584.root
```

### Plotting

Now if everything proceeded smoothly our output file will contain a ton of histograms of whom a few are interesting to our pourposes, to select them and save them nicely to `.png`s we can use the `MakeTimingScanTutorialPlots.py` script
```
python Tutorial/MakeTimingScanTutorialPlots.py PHM_PHASE1_out/Histo_TimingScan_Sep2022_merged.root
```

### Running on the cluster

When you have to run on a big number of files it is useful to split the workload in different jobs, since the `PahseI*HistoMaker` scripts would probably crush otherwise (for `PixelHistoMaker` expecially this problem is quite severe). To help doing there are different option: older version of the script was run with `HTCondor`, this submissions script however are not maintained anymore (and also not updated), I am currently running the jobs on the cluster using [slurm workload manager](https://slurm.schedmd.com/documentation.html) and some scripts to help create and babysit the jobs can be found in the `slurm` directory. 

The `batch_sub_script.py` file takes care of the creation submission and babysitting of the jobs, its usage is rather simple and should work out of the box. It takes some input files and options that are described inside:
```
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#
#- USAGE: --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#
#- python my_batch_sub_script.py --taskname [taskname] --input [txt file with list of input files] --nfile [number of files per job] --prog [program to execute] --outdir [directory to save output to] --create -#
#- python my_batch_sub_script.py --taskname [taskname] --status --------------------------------------------------------------------------------------------------------------------------------------------------#
#- python my_batch_sub_script.py --taskname [taskname] --submit --------------------------------------------------------------------------------------------------------------------------------------------------#
#- python my_batch_sub_script.py --taskname [taskname] --resubmit ------------------------------------------------------------------------------------------------------------------------------------------------#
#- python my_batch_sub_script.py --taskname [taskname] --missing -------------------------------------------------------------------------------------------------------------------------------------------------#
#- python my_batch_sub_script.py --taskname [taskname] --hadd ----------------------------------------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#

```
the other script, `slurm_template.sh` is basically a template that is taken and given to the cluster to build a `scram` environment with `CMSSW` and run the job.

 

