// Standard C++ libraries
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
// ROOT libraries
#include "TChain.h"
#include "TChainElement.h"
#include "TCanvas.h"
#include "TStopwatch.h"
#include "TFile.h"

// Own classes
#if DATASTRUCT_VER == 28
#include "../interface/DataStruct_v28.h"
#elif DATASTRUCT_VER == 29
#include "../interface/DataStruct_v29.h"
#elif DATASTRUCT_VER == 34
#include "../interface/DataStruct_v34.h"
#elif DATASTRUCT_VER == 35
#include "../interface/DataStruct_v35.h"
#elif DATASTRUCT_VER == 36
#include "../interface/DataStruct_v36.h"
#elif DATASTRUCT_VER == 105
#include "../interface/DataStruct_Phase1_v5.h"
#elif DATASTRUCT_VER == 108
#include "../interface/DataStruct_Phase1_v8.h"
#elif DATASTRUCT_VER == 109
#include "../interface/DataStruct_Phase1_v9.h"
#endif
#if TREEREADER_VER == 29
#include "../interface/TreeReader_v29.h" // Must follow DataStruct
#elif TREEREADER_VER >= 30 && TREEREADER_VER <= 36
#include "../interface/TreeReader_v30.h"
#elif TREEREADER_VER >= 37 && TREEREADER_VER <= 38
#include "../interface/TreeReader_v38.h"
#elif TREEREADER_VER == 39
#include "../interface/TreeReader_v39.h"
#elif TREEREADER_VER == 104
#include "../interface/TreeReader_Phase1_v4.h"
#endif
#include "../interface/Variables.h" // Must follow DataStruct
#include "../interface/SmartHistos.h"
#include "TEnv.h"

class TreeLooper {

 public:

  TreeLooper(TreeReader* tr, Variables* var, int evtloop, int trajloop, int clustloop,
             Long64_t maxevt=-1, Long64_t maxhit=-1, Long64_t maxclu=-1) {
    tr_=tr;
    var_=var;
    evtloop_=evtloop; 
    trajloop_=trajloop;
    clustloop_=clustloop;
    maxevt_=maxevt;
    maxhit_=maxhit;
    maxclu_=maxclu;
    build_();
    gEnv->SetValue("TFile.Recover", 0);
  }
  ~TreeLooper() { }
  
 private:
  TreeReader* tr_;
  Variables* var_;
  
  int evtloop_;
  int trajloop_;
  int clustloop_;
  Long64_t maxevt_;
  Long64_t maxhit_;
  Long64_t maxclu_;
  
  TStopwatch* sw_;
  bool sw_reset_;
  bool buffer_entries_;
  
  std::vector<TChain*> filechain_;
  
  int nfile_;
  Long64_t allruns_;
  Long64_t alllumis_;
  Long64_t allevents_;
  Long64_t allhits_;
  Long64_t allclusters_;
  Long64_t allentries_;
  Long64_t totalentries_;
  int totalevent_;
  int totallumi_;
  int percentdone_;
  int thousandthdone_;
  int lscheck_;
  int evtcheck_;
  int runcheck_;
  int evt_lscheck_;
  int evt_runcheck_;

  std::vector<int> run_list_;
  std::map<int, size_t > run_index_;

  std::string outfile_;

  void build_() {
    nfile_ = 0;
    allruns_ = 0;
    alllumis_ = 0;
    allevents_ = 0;
    allhits_ = 0;
    allclusters_ = 0;
    totalentries_ = 0;
    totalevent_ = 0;
    totallumi_ = 0;
    percentdone_ = 0;
    thousandthdone_ = 0;
    lscheck_ = 0;
    evtcheck_ = 0;
    runcheck_ = 0;
    evt_lscheck_ = 0;
    evt_runcheck_ = 0;
    sw_reset_=0;
    buffer_entries_=0;
  }
  
  // Run on run and lumi trees to get some variables
  void preloop_(bool debug=0) {
    if (debug) { std::cout<<"TreeLooper::preloop_: start\n"; }
    for (size_t i_add=0; i_add<filechain_.size(); ++i_add) {
      if (debug) { std::cout<<"TreeLooper::preloop_: Sample"<<i_add<<"\n"; }
      TObjArray* fileElements=filechain_[i_add]->GetListOfFiles();
      TIter next(fileElements);
      TChainElement* chEl=0; int nfile = 0;
      while (( chEl=(TChainElement*)next() )) {
	if (nfile%NTHFILE==0) {
          FILE* lastfile  = fopen("lastfile.txt","w");
          fprintf(lastfile, chEl->GetTitle()); fclose(lastfile);
	  std::string subdir = chEl->GetName();
	  if (subdir.find("filechain")==0) subdir="";
	  else subdir +="/";
	  if (debug) { std::cout<<"TreeLooper::preloop_: Opening file "<<chEl->GetTitle()<<"\n"; }
          TFile* f = TFile::Open(chEl->GetTitle());
          tr_->readtrees(f);
	  if (debug) { std::cout<<"TreeLooper::preloop_: TreeRead::readtrees\n"; }
#if DATASTRUCT_VER < 100
	  allruns_     += ((TTree*)f->Get((subdir+"runTree").c_str()))->GetEntries();
	  alllumis_    += ((TTree*)f->Get((subdir+"lumiTree").c_str()))->GetEntries();
#endif
	  allevents_   += ((TTree*)f->Get((subdir+"eventTree").c_str()))->GetEntries();
#if TRAJ_LOOP == 1
	  allhits_     += ((TTree*)f->Get((subdir+"trajTree").c_str()))->GetEntries();
#endif
#if CLUST_LOOP == 1
	  allclusters_ += ((TTree*)f->Get((subdir+"clustTree").c_str()))->GetEntries();
#endif
#if DATASTRUCT_VER < 100
          // loop on runTree
          for (Long64_t i=0; i<tr_->nrun(); ++i) {
            tr_->run_read(i);
            var_->count_runs_fills(tr_->run());
	    if (!run_index_.count(tr_->run().run)) {
	      run_list_.push_back(tr_->run().run);
	      run_index_[tr_->run().run] = run_index_.size();
	    }
          }
	  if (debug) { std::cout<<"TreeLooper::preloop_: runloop ok\n"; }
          // loop on lumiTree
          for (Long64_t i=0; i<tr_->nls(); ++i) {
            tr_->lumi_read(i);
            var_->count_runs_lumis(tr_->lumi());
            var_->instlumi_preloop_(tr_->lumi().run, tr_->lumi().ls);
            totallumi_++;
          }
#endif
	  if (debug) { std::cout<<"TreeLooper::preloop_: lumiloop ok\n"; }
	  // loop on eventTree
	  for (Long64_t i=0; i<tr_->nevt(); ++i) {
	    tr_->evt_read(i);
	    if (var_->pf_data!=(size_t)-1) var_->count_pileup_events(i_add, tr_->evt());
	    var_->preloop_events(tr_->evt());
#if DATASTRUCT_VER > 100
	    if (!run_index_.count(tr_->evt().run)) {
	      run_list_.push_back(tr_->evt().run);
	      run_index_[tr_->evt().run] = run_index_.size();
	    }
            var_->instlumi_preloop_(tr_->evt().run, tr_->evt().ls);
#endif
	  }
	  if (debug) { std::cout<<"TreeLooper::preloop_: evtloop ok\n"; }
          nfile_++;
	  }
	nfile++;
      }
    }
    if (debug) { std::cout<<"TreeLooper::preloop_: looping on files ok\n"; }
    if (var_->pf_data!=(size_t)-1) var_->calc_weights();
    if (debug) { std::cout<<"TreeLooper::preloop_: calc_weights ok\n"; }
    var_->init();
    if (debug) { std::cout<<"TreeLooper::preloop_: var_->init() ok\n"; }
    //  // Sort runs and their indices
    //  std::sort(var_->run_list.begin(),var_->run_list.end());
    //  for (size_t i=0; i<var_->run_list.size(); ++i) var_->run_index[var_->run_list[i]] = i+1;
    //  if (debug) { std::cout<<"TreeLooper::preloop_: sort runs ok\n"; }
    // New method
    std::sort(run_list_.begin(), run_list_.end());
    size_t i=0; for (auto run : run_list_) run_index_[run]=i++;
    if (debug) { std::cout<<"TreeLooper::preloop_: Done\n"; }
  }
  
  void run_progress_(int progress, const EventData &evt) {
    if (progress==0) {
      std::cout<<"------------------- Total Number of Runs           : "
	       <<var_->run_list.size()<<std::endl;
      std::cout<<"------------------- Total Number of Lumisections   : "
	       <<alllumis_<<std::endl;
      std::cout<<"------------------- Total Number of Events         : "
	       <<allevents_<<std::endl;
#if EVT_LOOP == 1
      allentries_ += allevents_;
#endif
#if TRAJ_LOOP == 1
      std::cout<<"------------------- Total Number of Hits           : "
	       <<allhits_<<std::endl;
      allentries_ += allhits_;
#endif
#if CLUST_LOOP == 1
      std::cout<<"------------------- Total Number of Clusters       : "
	       <<allclusters_<<std::endl;
      allentries_ += allclusters_;
#endif
      sw_ = new TStopwatch;
      sw_->Start(kFALSE);
    } else if (progress==1) {
      totalentries_++;
      if (allentries_<100000000&&totalentries_>(allentries_/100*(percentdone_+1))) {
	percentdone_++;
	sw_->Stop();
	double totaltime = sw_->RealTime();
	double hitspersec = (totalentries_-buffer_entries_)/totaltime;
	if (!sw_reset_) {
	  if (percentdone_>1) sw_reset_ = 1;
	  sw_->Reset();
	  sw_->Start(kFALSE);
	  buffer_entries_ = totalentries_;
	} else {
	  sw_->Continue();
	}
	double timeleft = (allentries_-totalentries_) / hitspersec;
	int time_h = int(timeleft/3600);
	int time_m = (timeleft-(time_h*3600))/60;
	int time_s = timeleft-(time_h*3600)-(time_m)*60;
	if (timeleft > 3600.0) { 
	  std::cout<<"\r-------------------- "<<std::setprecision(3)
		   <<percentdone_<<"% Done ( "<<time_h<<"h "
		   <<time_m<<"m Left ) --------------------"<<std::flush; 
	} else if (timeleft > 60.0) { 
	  std::cout<<"\r-------------------- "<<std::setprecision(3)
		   <<percentdone_<<"% Done ( "<<time_m<<"m "
		   <<time_s<<"s Left ) --------------------"<<std::flush; 
	} else {	while (timeleft>1.0) { timeleft -= 1.0; time_s++; }
	  std::cout<<"\r-------------------- "<<std::setprecision(3)
		   <<percentdone_<<"% Done ( "<<time_s
		   <<"s Left ) --------------------"<<std::flush; 
	}
      } else if (allentries_>=100000000&&totalentries_>(allentries_/1000*(thousandthdone_+1))) {
	thousandthdone_++;
	sw_->Stop();
	double percent = thousandthdone_/10.0 ;
	double totaltime = sw_->RealTime();
	double hitspersec = (totalentries_-buffer_entries_)/totaltime;	sw_->Stop();
	if (!sw_reset_) {
	  if (thousandthdone_>1) sw_reset_ = 1;
	  sw_->Reset();
	  sw_->Start(kFALSE);
	  buffer_entries_ = totalentries_;
	} else {
	  sw_->Continue();
	}
	double timeleft = (allentries_-totalentries_) / hitspersec;
	int time_h = int(timeleft/3600);
	int time_m = (timeleft-(time_h*3600))/60;
	int time_s = timeleft-(time_h*3600)-(time_m)*60;
	if (timeleft > 3600.0) { 
	  std::cout<<"\r-------------------- "<<percent<<"% Done ( "
		   <<time_h<<"h "<<time_m
		   <<"m Left ) --------------------"<<std::flush; 
	} else if (timeleft > 60.0) { 
	  std::cout<<"\r-------------------- "<<percent
		   <<"% Done ( "<<time_m<<"m "<<time_s
		   <<"s Left ) --------------------"<<std::flush; 
	} else {
	  std::cout<<"\r-------------------- "<<percent
		   <<"% Done ( "<<time_s<<"s Left ) --------------------"
		   <<std::flush; 
	}
      }
      if (evt.evt!=evtcheck_) totalevent_++;
      evtcheck_ = evt.evt;
      lscheck_ = evt.ls;
      runcheck_ = evt.run;
    } else if (progress==2) {
      std::cout<<std::endl;
      std::cout<<"Finished Processing "<<nfile_<<" Files."<<std::endl;
      std::cout<<"Total Lumisections = "<<totallumi_<<std::endl;  
      std::cout<<"Total Processed Events = "<<totalevent_
	       <<" Total Processed Entries = "<<totalentries_<<std::endl;
      std::cout<<"-----------------------------------------------------------------"
	       <<std::endl;
      delete sw_;
    }
  }

  void process_lumi_(Long64_t i) {
    tr_->lumi_read(i);
    var_->load_lumi_var(tr_->lumi());
  }

  void process_evt_(SmartHistos* sh, Long64_t i, Long64_t &lumientry) {
    tr_->evt_read(i);
    var_->load_evt_var(tr_->evt());
    if (alllumis_>0) if (tr_->evt().ls!=evt_lscheck_||tr_->evt().run!=evt_runcheck_) { // if new lumisection found
      process_lumi_(lumientry);
      // Get same ls as in eventTree
      while ((tr_->lumi().ls!=tr_->evt().ls||tr_->lumi().run!=tr_->evt().run)&&lumientry<tr_->nls()-1) {
	lumientry++; process_lumi_(lumientry);
      }
    }
    sh->Fill("evt");
    run_progress_(1,tr_->evt());
    evt_lscheck_ = tr_->evt().ls;
    evt_runcheck_ = tr_->evt().run;
  }

  
  Int_t process_hit_(SmartHistos* sh, Long64_t i, Long64_t &lumientry, Long64_t &clustentry, bool debug=0) {
    if (debug) { std::cout<<"process_hit ...\n"; }
    Int_t succ = tr_->traj_read(i);
    if (debug) { std::cout<<"traj_read ok\n"; }
    var_->load_traj_var(tr_->traj_evt(),tr_->traj());
    if (debug) { std::cout<<"load_traj_var ok\n"; }
    // Parallel loop on lumiTree (need for RAW)
#ifndef EXPRESS
    if (alllumis_>0) if (tr_->traj_evt().ls!=lscheck_||tr_->traj_evt().run!=runcheck_) { // if new lumisection found
      process_lumi_(lumientry);
      // Get same ls as in trajTree
      while ((tr_->lumi().ls!=tr_->traj_evt().ls||tr_->lumi().run!=tr_->traj_evt().run)&&lumientry<tr_->nls()-1) {
	lumientry++; process_lumi_(lumientry);
      }
    }
#endif
    if (debug) { std::cout<<"parallel loop ok\n"; }
    Int_t clust_succ = 1;
    //if (clustloop_==2) {
    //  // For every new event, do a loop on the clustTree to count pixels
    //  if (tr_->traj_evt().evt!=evtcheck_) {
    //    clust_succ = process_clu_(sh, clustentry);
    //    // Get same event as in trajTree
    //    while (tr_->clu_evt().evt!=tr_->traj_evt().evt&&clustentry<tr_->nclu()&&clust_succ!=-1) {
    //      clustentry++; 
    //      clust_succ = process_clu_(sh, clustentry);
    //    }
    //    while (tr_->clu_evt().evt==tr_->traj_evt().evt&&clust_succ!=-1) {
    //      if (clustentry<tr_->nclu()-1) {
    //        clustentry++; 
    //        clust_succ = process_clu_(sh, clustentry);
    //      } else break;
    //    }
    //  }
    //}
    run_progress_(1,tr_->traj_evt());
    if (debug) { std::cout<<"run progress ok\n"; }
    // In a possibility for double processed lumisections
    // check if certain lumisection was processed earlier
    // and avoid processing again
    succ = (succ==-1) ? -1 : (clust_succ==-1) ? -1 : 1;
    if (succ!=-1) {
      if (debug) { std::cout<<"successful read ok\n"; }
      sh->Fill("traj");
      if (var_->effcut_badroc) {
	int validhit = (tr_->traj().missing==1 ? tr_->traj().d_cl>=0 && tr_->traj().d_cl<DCL_MISSING : 1);
	++run_rocid_validhit_[tr_->traj_evt().run][var_->rocid][validhit];
      }
      // if (var_->no_double_ls)  ah.fill_traj(tr,var);
      // else if (var_->traj_isnewls==1&&!var_->no_double_ls)
      //   std::cout<<"Double Lumisection Foundin Fill: "<<var_->lumi_fill<<" Run: "
      //   	 <<tr_->traj_evt().run<<" LS: "<<tr_->traj_evt().ls<<std::endl;
    } else tr_->severity++;
    if (debug) { std::cout<<"Histo Fill ok\n"; }
    return succ;
  }
  
#if CLUST_LOOP > 0
  Int_t process_clu_(SmartHistos* sh, Long64_t i) {
    Int_t succ = tr_->clu_read(i);
    var_->load_clu_var(tr_->clu_evt(),tr_->clu());
    run_progress_(1,tr_->clu_evt());
    sh->Fill("clust");
    return succ;
  }
#endif
  
 public:
  void AddFile(std::string fileaddress, int new_loop=1) {
    size_t size = filechain_.size();
    if (new_loop!=0) {
      std::stringstream ss;
      ss<<"_"<<size+1;
      filechain_.push_back(new TChain((std::string("filechain")+ss.str()).c_str()));
      size = filechain_.size();
    }
    if (new_loop!=-1) filechain_[size-1]->Add(fileaddress.c_str());
  }
  
  void AddDataPileupHisto(size_t i_data, const char* filename, const char* hname, size_t nevt_data = 0) {
    if (evtloop_==0) std::cout<<"Warning!: #define EVT_LOOP "<<EVT_LOOP<<" has to be used, Set it to 1 to loop on eventTree! ... all event weights are set to 1"<<std::endl;
    var_->add_data_pileup_histo(filechain_.size(), i_data, filename, hname, nevt_data);
  }
  
  void SetData(size_t i_data, size_t nevt_data = 0) { var_->set_nevt_data(filechain_.size(), i_data, nevt_data); }
  
  void LoopOnTrees(SmartHistos* sh, std::function<void()>& add_special_histos, size_t parallel=0) {
    int debug = 0;
    if (debug) { std::cout<<"TreeLooper::LoopOnTrees: start\n"; }
    preloop_(debug);
    if (debug) { std::cout<<"TreeLooper::LoopOnTrees: preloop ok\n"; }
    // New bad roc list creation
    badroc_init_(*sh, tr_->traj_evt().run);
    if (debug) { std::cout<<"TreeLooper::LoopOnTrees: badroc_init_() ok\n"; }
    add_special_histos();
    if (debug) { std::cout<<"TreeLooper::LoopOnTrees: add_special_histos() ok\n"; }
    run_progress_(0,tr_->traj_evt());
    if (debug) { std::cout<<"TreeLooper::LoopOnTrees: progress done\n"; }
    for (size_t i_add=0; i_add<filechain_.size(); ++i_add) {
      if (debug) { std::cout<<"TreeLooper::LoopOnTrees: Sample"<<i_add<<"\n"; }
      var_->pf_file_add = (parallel==0) ? i_add : parallel-1;
      TObjArray* fileElements=filechain_[i_add]->GetListOfFiles();
      TIter next(fileElements);
      TChainElement* chEl=0;
      int nfile = 0;
      while (( chEl=(TChainElement*)next() )) {
	if (nfile%NTHFILE==0) {
	  if (debug) { std::cout<<"TreeLooper::LoopOnTrees: Opening file "<<chEl->GetTitle()<<"\n"; }
	  FILE* lastfile  = fopen("lastfile.txt","w");
	  fprintf(lastfile, chEl->GetTitle());
	  fclose(lastfile);
	  TFile *f = TFile::Open(chEl->GetTitle());
	  std::string subdir = chEl->GetName();
	  if (subdir.find("filechain")==0) subdir="";
	  else subdir +="/";
	  tr_->readtrees(f);
	  if (debug) { std::cout<<"TreeLooper::LoopOnTrees: TreeRead::readtrees\n"; }
	  Long64_t lumientry = 0, clustentry = 0;
    if (trajloop_==1) for (Long64_t i=0, nhit=(maxhit_>=0 ? std::min(tr_->nhit(), maxhit_) : tr_->nhit()); i<nhit; ++i) {
	  //if (trajloop_==1) for (Long64_t i=0, nhit=tr_->nhit()/10; i<nhit; ++i) {
	  //if (trajloop_==1) for (Long64_t i=0; i<tr_->nhit(); i+=100000) {
	    if (debug>1) { std::cout<<"TreeLooper::LoopOnTrees: hit"<<i<<"\n"; }
	    Int_t succ = process_hit_(sh, i, lumientry, clustentry, (debug>1));
	    if (debug>1) { std::cout<<"TreeLooper::LoopOnTrees: process_hit_ ok\n"; }
	    if (succ==-1) {
	      std::cout<<"Problematic entry found: "<<i<<" in File: "<<chEl->GetTitle()<<std::endl;
	      i+=(int)pow(10,tr_->severity+3); clustentry+=(int)pow(10,tr_->severity+3);
	    }
	  }
	  if (debug) { std::cout<<"TreeLooper::LoopOnTrees: trajloop ok\n"; }
	  if (tr_->severity) std::cout<<"Severity: "<<tr_->severity<<std::endl;
    if (evtloop_>0) { lumientry = 0; for (Long64_t i=0, nevt=(maxevt_>=0 ? std::min(tr_->nevt(), maxevt_) : tr_->nevt()); i<nevt; ++i) process_evt_(sh, i, lumientry); }
	  if (debug) { std::cout<<"TreeLooper::LoopOnTrees: evtloop ok\n"; }
#if CLUST_LOOP > 0
    if (clustloop_==1) for (Long64_t i=0, nclu=(maxclu_>=0 ? std::min(tr_->nclu(), maxclu_) : tr_->nclu()); i<nclu; ++i) process_clu_(sh,i);
	  //if (clustloop_==1) for (Long64_t i=0, nclu=tr_->nclu(); i<nclu; i+=40) process_clu_(sh,i);
	  if (debug) { std::cout<<"TreeLooper::LoopOnTrees: clustloop ok\n"; }
#endif
	}
	nfile++;
      }
    }
    sh->CalcSpecials();
    run_progress_(2,tr_->traj_evt());
    badroc_run_(*sh);
  }

  // For badroc list
  std::map<size_t, std::map<size_t, std::array<size_t, 2 > > > run_rocid_validhit_;
  
  // New method to automatically create Bad roc lists
  void badroc_init_(SmartHistos& sh, const int& run) {
    // Make ROCMaps for each run
    std::stringstream pf, leg, col;
    size_t n = 0;
    for (auto run : run_list_) {
      pf<<run<<";";
      leg<<"Run "<<run<<";";
      if (n%12==0) col<<"402,416,433,600,617,632,802,813,833,863,883,892,";
      n++;
    }
    sh.AddNewPostfix("Runs", [&run,this](){ return run_index_[run]; }, pf.str(), leg.str(), col.str());
#if PHASE == 0
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROCLadders_vs_ROCModules",           .pfs={"Runs","Layers"}, .cuts={"EffCutsAllROC","BPix"},      .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROCBladesInner_vs_ROCSideDiskPanel", .pfs={"Runs"},          .cuts={"EffCutsAllROC","FPixInner"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROCBladesOuter_vs_ROCSideDiskPanel", .pfs={"Runs"},          .cuts={"EffCutsAllROC","FPixOuter"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
#elif PHASE == 1
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L1_Ladder_vs_Module",              .pfs={"Runs"},            .cuts={"ZeroBias","EffCutsAllROC","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L2_Ladder_vs_Module",              .pfs={"Runs"},            .cuts={"ZeroBias","EffCutsAllROC","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L3_Ladder_vs_Module",              .pfs={"Runs"},            .cuts={"ZeroBias","EffCutsAllROC","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L4_Ladder_vs_Module",              .pfs={"Runs"},            .cuts={"ZeroBias","EffCutsAllROC","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",         .pfs={"Runs"},            .cuts={"ZeroBias","EffCutsAllROC","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",         .pfs={"Runs"},            .cuts={"ZeroBias","EffCutsAllROC","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L1_Ladder_vs_Module",              .pfs={"Runs","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L2_Ladder_vs_Module",              .pfs={"Runs","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L3_Ladder_vs_Module",              .pfs={"Runs","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L4_Ladder_vs_Module",              .pfs={"Runs","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",         .pfs={"Runs","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",         .pfs={"Runs","ExclMods"}, .cuts={"ZeroBias","EffCutsScans","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
#endif
  }
  
  void badroc_run_(SmartHistos& sh, bool test=0) {
    // Old threshold: mean - 1.0 * RMS
    // New threshold: min ( mean - 1.0 * RMS, 0.9 ), so maximum eff = 0.9, and exclude 1.0 bin for mean/rms
    // New (v2) threshold: min ( mean - 0.5 * RMS, 0.95 ), so maximum eff = 0.95, and exclude 1.0 bin for mean/rms
    double N_sig_threshold = 0.5;
    TFile *f = TFile::Open(test ? "input/Badroc_List_test.root" : "input/Badroc_List.root", "UPDATE");
    for (auto& run_roclist : run_rocid_validhit_) { // loop on runs
      size_t run = run_roclist.first, nbad = 0;
      std::stringstream name; name<<"run_"<<run;
      std::stringstream name2; name2<<"run_"<<run<<"_roceffdist";
      TH1D* badroc_list = (TH1D*)f->Get(name.str().c_str());
      double stat = 0, old_stat = badroc_list ? badroc_list->GetEntries() : 0;
      double old_thr = badroc_list ? badroc_list->GetBinError(0) : 0;
      if (old_stat==0) badroc_list = new TH1D(name.str().c_str(), ";ROCs;ROC ID (id1*1e4 + id2*1e2 + id3)", 1000,0,1000);
      // First loop on all ROCs to determine mean, rms, statistics in run
      TH1D* roceff_dist = new TH1D(name2.str().c_str(), ";Hit Efficiency;ROCs", 1001,-0.0005,1.0005);
      TH1D for_mean_rms("h", ";Hit Efficiency;ROCs", 1000,-0.0005,0.9995);
      for (auto& rocid_hitcount : run_roclist.second) { // loop on ROC IDs
	double mis = rocid_hitcount.second[0], val = rocid_hitcount.second[1];
	stat += val+mis;
	roceff_dist->Fill(val/(val+mis));
	for_mean_rms.Fill(val/(val+mis));
      }
      // If old list is not found or equal or more statistics is available make a new bad ROC list
      // Or the list was made earlier with higher threshold, which could cause to exclude too many ROCs
      if (stat>=old_stat||old_thr>1) {
	delete badroc_list;
	badroc_list = new TH1D(name.str().c_str(), ";ROCs;ROC ID (id1*1e4 + id2*1e2 + id3)", 1000,0,1000);
	double mean = for_mean_rms.GetMean(), rms = for_mean_rms.GetRMS();
	double threshold = std::min(mean - N_sig_threshold*rms, 0.95);
	std::cout<<"Run "<<run<<" mean "<<mean<<" rms "<<rms<<std::endl;
	for (auto& rocid_hitcount : run_roclist.second) { // loop on ROC IDs
	  size_t rocid = rocid_hitcount.first;
	  double mis = rocid_hitcount.second[0], val = rocid_hitcount.second[1];
	  if (val/(val+mis)<threshold&&(val+mis)>1) badroc_list->SetBinContent(++nbad, rocid);
	}
	badroc_list->SetBinContent(0, nbad);
	badroc_list->SetBinError(0, threshold);
	badroc_list->SetEntries(stat);
	std::cout<<(old_stat ? "Updating Bad ROC list" : "New Bad ROC list created")<<" for run="<<run<<" Mean="<<mean<<" RMS="<<rms<<" Thr="<<threshold
		 <<" Nbad="<<nbad<<" stat="<<stat; if (old_stat) std::cout<<" old stat="<<old_stat<<" old thr="<<old_thr; std::cout<<std::endl;
	badroc_list->Write(badroc_list->GetName(), TObject::kOverwrite);
	roceff_dist->Write(roceff_dist->GetName(), TObject::kOverwrite);
      }
    }
    f->Close();
  }

};

