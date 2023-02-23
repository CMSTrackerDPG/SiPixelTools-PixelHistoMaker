#include "LumiReweightingStandAlone.h" // Must copy this from "PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h"
#include <iostream> 
#include "scan_points.h"

class Variables {
  
public:
  Variables() { 
    build_(); 
    init_();
#ifndef TREEREADER_VER
    std::cout<<"Please #include Treereader before Variables"<<std::endl;
#endif
  }
  ~Variables() {}
  
  //_______________________________________________________________________________
  //                             Variables from runTree
  
  // run variables (read from file)
  std::map<int, double> totallumi;
  std::map<int, double> totallumi_2012;
  std::vector<std::vector<std::vector<int> > > goodroc_list; // VER2 >= 27
  
  // runTree variables
  std::map<int, std::string> run_fillname;
  std::map<int, int> run_fill_index;
  int run_nfill;
  std::map<int, int> run_index;
  std::vector<int> run_list;
  std::map<int, int> run_firstrun;
  
  std::vector<std::string> str_fill;
  std::vector<std::string> str_Fill;
  std::vector<std::string> str_Fill2;
  
  //_______________________________________________________________________________
  //                             Variables from lumiTree
  
  // lumi variables
  double lumi_totlumi;
  double lumi_totlumi_2012;
  double lumi_time_in_fill;
  std::map<unsigned long int, double> fromfile_intlumi;
  std::map<unsigned long int, double> fromfile_intlumi_run;
  std::map<unsigned long int, double> fromfile_instlumi;
  std::map<unsigned long int, double> fromfile_pileup;
  double lumi_pileup;
  double lumi_instlumi;
  double lumi_intlumi;
  double lumi_intlumi_run;
  int first_filled_bx;
  int lumi_day, lumi_month, lumi_year, lumi_time, lumi_weektime, lumi_monthtime;
  
  // lumi variables (fill, time etc)
  std::map<int, int> lumi_firstrun;
  std::map<int, unsigned int> lumi_fillstart;
  std::map<int, int> filldef;
  int lumi_fill;
  std::map<int, TH1D*> instlumi_ls_map;
  std::map<unsigned long int, bool> runls_count;
  bool lumi_good_instlumi;
  
  //_______________________________________________________________________________
  //                             Variables from eventTree
  // ToDo: Redo all evt variables to either load from traj/clust/eventTrees
  //       (once for each new event)
  
  // evt variables
  int evt_run_binx;
  double evt_totlumi;
  std::vector<int> evt_federr_type;
  std::vector<int> evt_federr_mult;
  int evt_fill; // using filldef
  
  //_______________________________________________________________________________
  //                             Variables from trajTree
  
  float dr_hit;
  float dr_clu;
  float dr_cluclu;
  int inactive;
  float clu_charge;
  
  double dcol_eff;
  
  // ***********  Event variables ***********
  int newevt;
  int newls;
  int run_bin;
  int fill;
  int n_timeout;
  int n_overflow;
  
  // ********** Geometry variables **********
  int shl;
  int sec;
  int sdp_x; // side-disk-panel
  int mod_index_x;
  int mod_index_y;
  int mod_x;
  int mod_y;
  int roc;
  int tbm;
  int roc_binx;
  int roc_biny;
  int roc_new_binx;
  int roc_new_biny;
  double phi;
  double theta;
  double angle_alpha;
  double angle_beta;
  double angle_incidence;
  //double year;
  float module_coord;
  float ladder_coord;
  float disk_coord;
  float disk_ring_coord;
  float blade_panel_coord;
  
  // ************ Scans variables ***********
  int p2_secdisk;
  int p3_layrog;
  int hv_p1;
  int hv_p2;
  int hv_group;
  int hv_IO;
  int hv_l1_p1;
  int hv_l2_p1;
  int hv_l3_p1;
  int hv_d1_p1;
  int hv_l1full_p1;
  int hv_l2full_p1;
  int hv_l3full_p1;
  int hv_d1full_p1;
  int hv_d2full_p1;
  
  //std::stringstream l1_col;
  //std::stringstream l2_col;
  //std::stringstream l3_col;
  //std::stringstream d1_col;
  //std::stringstream l1full_col;
  //std::stringstream l2full_col;
  //std::stringstream l3full_col;
  //std::stringstream d1full_col;
  //std::stringstream d2full_col;
  std::vector<std::vector<double> > totlumi_scan;
  std::vector<double> totlum_fb;
  
  // *************** Cuts *******************
  
  // Efficiency Selections separately
  // Track Selections
  bool hp;
  bool pt;
  bool nstrip;
  bool d0;
  bool dz;
  bool pixhit;
  // Module Exclusions
  bool noscan;
  bool goodmod;
  bool goodmod_scans;
  bool goodroc;
  // Module/ROC Fiducial Region Selections
  bool lx_fid;
  bool ly_fid;
  // Efficiency Related Selections
  bool valmis;
  bool hitsep;
  bool dcol_clu_cuts;

  bool pt_new;
  bool d0_new;
  bool dz_new;
  bool hitsep_new;
  
  // Merged Cuts
  bool effcut_all;
  bool effcut_allmod;
  bool effcut_trig;
  bool effcut_nvtx;
  bool effcut_federr;
  bool effcut_raw;
  bool effcut_pt;
  bool effcut_nstrip;
  bool effcut_d0;
  bool effcut_dz;
  bool effcut_d0_dz;
  bool effcut_scans;
  bool effcut_scans_loose;
  bool effcut_startup;
  bool effcut_ly_fid;
  bool effcut_lx_fid;
  bool effcut_lxly_fid;
  bool effcut_hitsep;
  bool effcut_beta  ;
  bool new_effcut_all;
  bool new_effcut_presel;
  bool new_effcut_pt;
  bool new_effcut_nstrip;
  bool new_effcut_d0;
  bool new_effcut_dz;
  bool new_effcut_hitsep;
  bool new_effcut_muon;
  bool dcol_effcut_all;
  bool dcol_effcut_valpix;
  bool dcol_effcut_pt;
  bool dcol_effcut_d0;
  bool dcol_effcut_dz;
  bool dcol_effcut_alpha;
  bool dcol_effcut_beta;
  bool dcol_effcut_scans;
  bool dcol_effcut_allmod;
  
  // old
  int p1_detshl;
  int p2_seclyrldr;
  int p2_dskbld;
  int p3_modroc;
  int p3_pnlplqroc;
  int p3_pnlroc;
  int p1_rocid;
  int p2_rocid;
  int p3_rocid;
  int p1_modid;
  int p2_modid;
  int p3_modid;
  size_t rocid;

  //_______________________________________________________________________________
  //                             Variables from clustTree
  //                    convention: put clu_ in front to distinguish
  //                                from trajTree variables
  
  int clu_p1_rocid;
  int clu_p2_rocid;
  int clu_p3_rocid;
  int clu_fill;
  int clu_p1_fill;
  int clu_det_x;
  int clu_lay_x;
  int clu_sdp_x;
  int clu_mod_indexx;
  int clu_mod_indexy;
  int clu_mod_p1;
  int clu_roc_p1;
  int clu_roc_binx;
  int clu_roc_biny;
  int clu_roc_new_binx;
  int clu_roc_new_biny;
  
  //_______________________________________________________________________________
  //                               Commomn Variables

  size_t pf_data; // value given in TreeLooper::AddDataPileupHisto
  size_t pf_file_add; // value given in TreeLooper::LoopOnTrees
  
  std::vector<double> theLadderEfficiency_BPix[3];
  std::vector<double> theModuleEfficiency_BPix[3];
  std::vector<double> thePUEfficiency_BPix[3];
  double theInnerEfficiency_FPix;
  double theOuterEfficiency_FPix;
  
  // *************** Geometry **************
  // Cuts
  bool is_l1;
  bool is_bpix;
  bool is_fpix;
  bool is_fpix_inner;
  bool is_fpix_outer;
  
  // Variables
  int layers_disks;
  int layers_disks_phase1;
  int layers_disks_inout;
  int disks_inout;
  int side;
  int layer;
  int ladder;
  int module;
  int offline_ladder;
  int offline_module;
  int sector;
  int rog;
  int ring;
  int blade;
  float roc_ladder;
  float roc_module;
  float roc_blade;
  float roc_sdp;
  int federr_mod;
  int rocbin_x;
  int rocbin_y;
  int roc_number;
  float rel_fluence_l1;
  
  // Postfix indices
  size_t pf_layers;
  size_t pf_mods;
  size_t pf_allmods;
  size_t pf_ladders;
  size_t pf_shell;
  size_t pf_layer_disk;
  size_t pf_sector_rog;
  size_t pf_sector;
  size_t pf_flipped;
  size_t pf_outer;
  size_t pf_ring_rog;
  size_t pf_new_modules;
  
  // ************ Event variables  **********
  // Cuts
  bool cut_zb;
  bool cut_nvtx;
  bool cut_federr;
  bool cut_highpu;
  
  bool is_data;
  bool is_run203002;
  bool main_filling_schemes_2011;
  bool main_filling_schemes_2012;
  bool main_filling_schemes_2015;
  bool main_filling_schemes_2016;
  bool main_filling_schemes_2017;
  bool main_filling_schemes_2018;
  bool main_filling_schemes;
  bool is_full_hv_scan;
  bool is_one_hv_group_scan;
  
  // Variables
  int nclu;
  int npix;
  int nclu_bpix;
  int npix_bpix;
  float pu_weight;
  float corr_pu_weight;
  float vtx_weight;
  float norm_factor;
  double instlumi;
  double intlumi;
  double intlumi_run;
  double pileup;
  double nbx;
  double nbx_per_trig;
  double ncol_per_trig;
  float delay;
  int bias_voltage;
  int day, month, year, time, weektime, monthtime;
  int lastrun, lastls, lastorb, lastbx, lastevt;
  double l1rate, ncoll_per_trig;
  
  // Postfix indices
  size_t pf_instlumi_old;
  size_t pf_instlumi05;
  size_t pf_instlumi;
  size_t pf_instlumi2;
  size_t pf_instlumi3;
  size_t pf_l1rate;
  size_t pf_pileup;
  size_t pf_disks;
  size_t pf_all_disks;
  size_t pf_disksio;
  size_t pf_lays_disks;
  size_t pf_lays_disks_phase1;
  size_t pf_lays_disks_oldnew;
  size_t pf_lays_disksio;
  size_t pf_det;
  size_t pf_year;
  size_t pf_wbc;
  int pf_delay_scan;
  int pf_delay;
  int pf_voltage;
  int pf_hv_scan;
  
 private:
  
  void common_evt_(const EventData& e) {
    // Load lumi var (new for Phase 1)
    load_lumi_var_phase1(e);

    //_____________________________________
    //               Cuts
    
    // Eff: ZeroBias trigger
    cut_zb = e.trig >> 0 & 1;
    
    // Eff: Number of Primary Verices >= 1 (where VtxZ<24 cm, VtxD0 < 2 cm, VtxNdof > 4)
    cut_nvtx = e.nvtx>=1;
    
    // Eff: No FED Error in the Event (pevious cut: t.mod_on.federr==0)
    cut_federr = e.federrs_size==0;
    
    // Other
    is_data = (e.run!=1);
    is_run203002 = (pf_file_add>0||(e.run==203002&&!(e.ls<77||(e.ls>128&&e.ls<130)||(e.ls>141&&e.ls<144)||(e.ls>207&&e.ls<209)||(e.ls>267&&e.ls<270)||(e.ls>360&&e.ls<362)||(e.ls>501&&e.ls<504)||(e.ls>641&&e.ls<643)||(e.ls>669&&e.ls<671)||(e.ls>671&&e.ls<674)||(e.ls>717&&e.ls<720)||(e.ls>1034&&e.ls<1037)||(e.ls>1070&&e.ls<1073)||(e.ls>1370&&e.ls<1372)||(e.ls>1392&&e.ls<1395)||(e.ls>1410&&e.ls<1413)||e.ls>1596)));
    
    // Cut on the main, 1300+ bx filling schemes:
    // 2011:
    // 50ns_1380b_1331_0_1320_144bpi12inj
    // 50ns_1380b+1small_1318_39_1296_144bpi13inj
    // 50ns_1380b_1331_0_1320_144bpi12inj
    main_filling_schemes_2011 = (e.run>=167898&&e.run<=167913)||(e.run>=170826&&e.run<=173692)||(e.run>=175906&&e.run<=177878)||(e.run>=178078&&e.run<=178162)||(e.run>=178365&&e.run<=178985)||(e.run>=179410&&e.run<=180252);
    
    // 2012:
    // 50ns_1380b_1331_0_1320_144bpi12inj
    // 50ns_1380b_1377_0_1274_144bpi12inj
    // 50ns_1380b_1380_0_1274_144bpi12inj
    // 50ns_1374_1368_0_1262_144bpi12inj
    // 50ns_1374_1368_0_1262_144bpi12inj_V2
    main_filling_schemes_2012 = (e.run>=191691&&e.run<=191859)||(e.run>=193878&&e.run<=196531)||(e.run>=198229&&e.run<=198523)||(e.run>=198941&&e.run<=199021)||(e.run>=199318&&e.run<=200381)||(e.run>=200473&&e.run<=200798)||(e.run>=200990&&e.run<=201476)||(e.run>=201554&&e.run<=202504)||(e.run>=202970&&e.run<=203002)||(e.run>=203830&&e.run<=204601)||(e.run>=205111&&e.run<=207518)||(e.run>=207897&&e.run<=208487)||(e.run>=208538&&e.run<=208686);
    
    main_filling_schemes_2015 = (e.run>=260099&&e.run<=260235)||(e.run>=260424&&e.run<=260627);
    
    main_filling_schemes_2016 = (e.run>=278820&&e.run<=278986)||(e.run>=279115&&e.run<=279116)||(e.run>=279588&&e.run<=280385)||(e.run>=281663&&e.run<=282092)||(e.run>=282707&&e.run<=283067)||(e.run>=283270&&e.run<=283359)||(e.run>=283407&&e.run<=283481)||(e.run>=283672&&e.run<=284044);
    
    // 2017: Struggled with 2544b --> 1866b
    main_filling_schemes_2017 = (e.run>=304505&&e.run<=305636)||(e.run>=305766&&e.run<=306462)||(e.run>=306936&&e.run<=307082);
    // 2018: 2544b
    main_filling_schemes_2018 = (e.run>=315741&&e.run<=316271)||e.run==316505||e.run==316569||e.run==316590||(e.run>=316664);//&&e.run<=)||(e.run>=&&e.run<=)||(e.run>=&&e.run<=)||(e.run>=&&e.run<=)||(e.run>=&&e.run<=)||(e.run>=&&e.run<=);
    main_filling_schemes_2018 = main_filling_schemes_2018==1 && e.run>=316569; // Select only fills after the pxFEC f/w update
    
    // first filled bx
    first_filled_bx = run_firstbx_[e.run];
    //std::cout<<first_filled_bx<<std::endl;
    
    //_____________________________________
    //              Variables
    // event weights
#if DATASTRUCT_VER > 29 && PHASE == 0
    pu_weight = is_data ? 1.0 : e.weight;
    corr_pu_weight = (pf_data!=(size_t)-1&&EVT_LOOP!=0) ? (is_data ? 1 : reweight_[pf_file_add]->weight(e.pileup)) : 1;
#else
    pu_weight = 1.0;
    corr_pu_weight = 1.0;
#endif
    norm_factor = (pf_data!=(size_t)-1&&EVT_LOOP!=0) ? (is_data ? 1 : norm_factor_[pf_file_add]) : 1;
    
    // other
#if DATASTRUCT_VER > 28
    nclu_bpix = e.nclu[1] + e.nclu[2] + e.nclu[3];
    npix_bpix = e.npix[1] + e.npix[2] + e.npix[3];
    nclu = e.nclu[0] + nclu_bpix;
    npix = e.npix[0] + npix_bpix;
#else
    nclu_bpix = NOVAL_F;
    npix_bpix = NOVAL_F;
    nclu = NOVAL_F;
    npix = NOVAL_F;
#endif
    
    // Dates (use info from lumi pre/parallel loop)
    day = lumi_day;
    month = lumi_month;
    int mc_year = 2017;
    year = (e.run==1) ? mc_year : lumi_year;
    //  7 TeV total - 73.15 mb (TOTEM - EPL 101 (2013) 21002)
    //  8 TeV total - 74.70 mb (TOTEM - Phys. Rev. Lett. 111, 012001)
    // 13 TeV total - 78.10 mb (ATLAS - Phys.Rev.Lett. 117 (2016) no.18, 182002)
    float xsec_mb = ((year==2011) ? 73.15 : (year==2012) ? 74.70 : 78.10) * 1e6; // nb
    time = lumi_time;
    weektime = lumi_weektime;
    monthtime = lumi_monthtime;
    
    // nbx 2012 = 1368
    // nbx 2015 50ns pred      = 1370
    // nbx 2015 25ns pred      = 2500
    // nbx 2015 25ns (peak)    = 2232
    // nbx 2016 25ns pred      = 2736
    // conv_factor Run I       = 0.0001623
    // conv_factor Run II 2015 = 0.0001405 - brilcalc 2015 - 80 mb
    // conv_factor Run II 2016 = 0.0001576 - brilcalc 2015 - scaled to 71.3 mb
    // scale factor 2012 = 0.222
    // scale factor 2015 (50ns Pred) = 0.200
    // scale factor 2015 (25ns Pred) = 0.364
    // scale factor 2015 (Marton) = 0.1767
    // scale factor 2015 (Mean - Dec18 Silver JSON) = 0.232543
    // scale factor 2015 (Peak) = 0.3136
    // scale factor 2016 (2040b) = 0.3216
    // scale factor 2017 (2544b) = 0.3663

    /*
      New Calculation
      
      nbx = 2544
      c = 299792.458 km/s
      l_lhc = 26.658883 km
      mb_xsec = 7.81e7 nb
      nbx_lhc = 3564
      LS = 2^18 orbit = 262144 * 26.658883 / 299792.458 = 23.311 s
      1 orbit = 0.08924462 ms
      -->
      instlumi/<pile-up> [nb-1s-1/pu] = nbx * c / ( l_lhc * mb_xsec )
      = 2544 * 299792.458 / ( 26.658883 * 7.81e7 ) = 0.3663 [nb-1s-1/pile-up OR 10e33 cm-2s-1/pile-up]
      --> 
      conv_factor = c / ( l_LHC * xsec_mb ) = 0.00014399
    */

    pileup = NOVAL_F;
    instlumi = NOVAL_F;
    nbx = NOVAL_F;
    double instlumi_invnb_per_pileup_per_nbx_conv_factor = NOVAL_F;
    if (e.run==1) {
      instlumi_invnb_per_pileup_per_nbx_conv_factor = (mc_year<2015) ? 0.0001623 : 299792.458 / ( 26.658883 * xsec_mb );
      nbx = (mc_year<=2014) ? 1368 : (mc_year==2015) ? 2232 : (mc_year==2016) ? 2208 : 2554;
#if DATASTRUCT_VER > 29
      pileup   = e.pileup;
      instlumi = instlumi_invnb_per_pileup_per_nbx_conv_factor * pileup * nbx;
#endif
    } else {
      pileup   = lumi_pileup;
      instlumi = lumi_instlumi;
      instlumi_invnb_per_pileup_per_nbx_conv_factor = (e.run<238474) ? 0.0001623 : 299792.458 / ( 26.658883 * xsec_mb );
      if (instlumi!=NOVAL_F) nbx = instlumi / pileup / instlumi_invnb_per_pileup_per_nbx_conv_factor;
    }

    //
    main_filling_schemes = (e.run==1) ? 1 : main_filling_schemes_2011 || main_filling_schemes_2012 || main_filling_schemes_2015 || main_filling_schemes_2016 || main_filling_schemes_2017 || main_filling_schemes_2018;

    intlumi  = (e.run==1) ? NOVAL_F : lumi_intlumi;
    intlumi_run  = (e.run==1) ? NOVAL_F : lumi_intlumi_run;
    
    cut_highpu = is_data ? pileup>27 && pileup<29 : pileup>39 && pileup<41;
#if PHASE == 0
    nbx_per_trig = (e.run==1) ? NOVAL_F : (nbx==NOVAL_F) ? NOVAL_F : 40000000/3564 * nbx / e.l1_rate;
    ncol_per_trig = (e.run==1) ? NOVAL_F : (nbx_per_trig==NOVAL_F) ? NOVAL_F : nbx_per_trig * pileup;
#endif
    n_timeout  = 0;
    n_overflow = 0;
    for (int i=0; i<e.federrs_size; i++) {
      if (e.federrs[i][1]==29) n_timeout  = e.federrs[i][0];
      if (e.federrs[i][1]==40) n_overflow = e.federrs[i][0];
    }
    
    // postfix indices
    //pf_instlumi_old  = (instlumi<10&&instlumi>0) ? (size_t)instlumi : (size_t)-1;
    //pf_instlumi05 = (instlumi<10&&instlumi>0) ? (size_t)(instlumi/0.5) : (size_t)-1;
    pf_instlumi  = (instlumi<10.5&&instlumi>=0) ? (size_t)(instlumi+0.5) : (size_t)-1;
    pf_instlumi2 = (instlumi<30  &&instlumi>=0) ? (size_t)(instlumi/2.0) : (size_t)-1;
    pf_instlumi3 = (instlumi<14  &&instlumi>=0) ? (size_t)(instlumi/2.0) : (size_t)-1;
    //pf_pileup = (instlumi<2*0.222) ? (is_data?(size_t)-1:0) : ((instlumi>2&&instlumi<2.5) ? 1 : ((instlumi>6&&instlumi<6.5) ? 2 : (size_t)-1));
    pf_pileup = (pileup==NOVAL_F) ? (size_t)-1 : (pileup<50) ? (size_t)(pileup/5) : (size_t)-1;
    pf_year = (e.run==1) ? (size_t)-1 : (e.run<149711 ? (size_t)-1 : (e.run>180296) + (e.run>=238474) );

    pf_wbc = (e.run>=233947&&e.run<=234052) ? 1 : (e.run>=234192&&e.run<=234207) ? 2 : (e.run>=234224) ? 3 : 0;

    if (e.evt!=lastevt) {
      if (lastevt==0||e.run!=lastrun) {
	      l1rate = -1;
	      ncoll_per_trig = -1;
      } else {
	      l1rate = (e.evt - lastevt)/((e.orb - lastorb + (e.bx - lastbx)/3564.0)*0.089482); // (kHz) orbit time: l_lhc (26.658883) / c (299792.458) = 0.089482 ms
	      ncoll_per_trig = instlumi * xsec_mb / l1rate;
      }
      if (l1rate<0) l1rate = 0;
      //std::cout<<e.run<<" "<<e.ls<<" "<<e.evt<<" "<<lastevt<<" "<<e.orb<<" "<<lastorb<<" "<<l1rate<<std::endl;
      lastrun = e.run;
      lastls  = e.ls; 
      lastorb = e.orb; 
      lastbx  = e.bx; 
      lastevt = e.evt;
    }

#if PHASE == 0
    pf_l1rate     = (e.run==1) ? -1 : ((e.l1_rate<105000) ? (size_t)((e.l1_rate+5000)/10000) : (size_t)-1);
#else
    pf_l1rate     = (e.run==1) ? -1 : ((l1rate<125) ? (size_t)((l1rate+5)/10) : (size_t)-1);
#endif

  }
  
  void common_(const EventData& e, const ModuleData& m) {
    //_____________________________________
    //               Cuts
    is_bpix = m.det==0;
    is_fpix = m.det;
    is_fpix_inner = m.det && (m.blade>0);
    is_fpix_outer = m.det && (m.blade<0);
    is_l1 = m.layer==1;
    
    //_____________________________________
    //              Variables
    layers_disks = (m.det==0) ? m.layer :  m.disk + 5 + (m.disk<0);
    layers_disks_phase1 = (m.det==0) ? m.layer :  7 + m.disk + (m.disk<0);
    layers_disks_inout = (m.det==0) ? m.layer :  3 + abs(m.disk)*2 - ((m.panel+m.module)<4);
    disks_inout = (m.det==0) ? (size_t)-1 :  abs(m.disk)*2 - ((m.panel+m.module)<4);
    side    = m.side;
    layer   = (m.det==1) ? NOVAL_I : m.layer;
    ladder  = m.ladder;
    module  = m.module;
    // Timing and HV Scans
    pf_delay_scan = scans::delay_scan_no(e.run, e.ls);
    delay = scans::delay(e.run, e.ls, e.orb);
    pf_hv_scan = scans::hv_scan_no(e.run);
    bias_voltage = scans::bias_voltage(pf_hv_scan, e.run, e.ls, e.orb, m.det, m.layer, abs(m.disk));
    is_one_hv_group_scan = scans::is_one_hv_group_scan(pf_hv_scan, bias_voltage, m.det, m.layer, m.ladder, m.module, m.disk, m.blade, m.panel);
    is_full_hv_scan = scans::is_full_hv_scan(pf_hv_scan);
    pf_delay = (delay>=10&&delay<=30&&(int(delay))%2==0) ? (int(delay) -10)/2 : -1;
    pf_voltage = bias_voltage < 20 ? bias_voltage / 5 : 2 + bias_voltage / 10;
    // Sector
    int bld = abs(m.blade);
#if PHASE == 0
    int lad = abs(m.ladder);
    sector = (m.det) ? NOVAL_I : (m.layer==1) ? lad - 1 + (lad==1) - (lad==10) : (m.layer==2) ? (lad+1)/2 : (lad+2+(lad>11)*2)/3;
    rog = (m.det==0) ? NOVAL_I : (bld+2)/3;
    ring = (m.det==0) ? NOVAL_I : 1+(m.panel+m.module>3);
#else
    sector = (m.det) ? NOVAL_I : m.sec;
    rog = (m.det==0) ? NOVAL_I : (m.ring==1) ? (bld+2+(bld>5))/3 : (bld+3-(bld>8))/4;
    ring = (m.det==0) ? NOVAL_I : m.ring;
#endif
    blade = m.blade;
    // Shell - BpI: 0,  BpO: 1, BmI: 2, BmO: 3
    pf_shell = (m.det==0) ? 2 * (m.module<0) + (m.ladder<0) : 2 * (m.disk<0) + (m.blade<0);
    pf_sector_rog = (m.det==0) ? sector-1 : 7+rog;
    pf_ring_rog = (m.det==0) ? -1 : rog-1 + (ring>1)*4;
    pf_sector = (m.det==0) ? sector-1 : -1;
    pf_outer = (m.det==0) ? m.flipped : -1;

    hv_IO = (m.det==1) ? ((m.panel==1) ? m.module>2 : m.module>1 ) : NOVAL_I; // 0: inner, 1: outer
    hv_group = (m.det==1) ? (bld+2)/3 : NOVAL_I; // Same as Readout group
    
    offline_ladder =
      (m.layer==1) ? ( (m.ladder>=6&&m.ladder<=10) ? 26-m.ladder : (m.ladder>=1&&m.ladder<=5) ? 6-m.ladder : 5-m.ladder ) :
      (m.layer==2) ? ( (m.ladder>=9&&m.ladder<=16) ? 41-m.ladder : (m.ladder>=1&&m.ladder<=8) ? 9-m.ladder : 8-m.ladder ) :
      (m.layer==3) ? ( (m.ladder>=12&&m.ladder<=22) ? 56-m.ladder : (m.ladder>=1&&m.ladder<=11) ? 12-m.ladder : 11-m.ladder ) : NOVAL_I;
    offline_module = (m.module>0) ? m.module+4 : m.module +5;
    federr_mod = (m.federr==29) + (m.federr==40)*2;
    roc_number = (rocbin_x == NOVAL_I || rocbin_y == NOVAL_I) ? NOVAL_I :
      (m.det==0) ? rocbin_y - 1 + (rocbin_x-1) * (m.layer*6+3) * 4 +
      (m.layer>=2) * 64 * 36 +
      (m.layer>=3) * 64 * 60 : 
      rocbin_y -1 + (rocbin_x-1) * 24 +
      (m.disk>=-2) * 64 * (36+60+84) +
      (m.disk>=-1) * 45 * 24 +
      (m.disk>= 1) * 45 * 24 +
      (m.disk>= 2) * 45 * 24;

    module_coord      = m.module_coord;
    ladder_coord      = m.ladder_coord;
    disk_coord        = m.disk_coord;
    disk_ring_coord   = m.disk_ring_coord;
    blade_panel_coord = m.blade_panel_coord;

    rel_fluence_l1 = 1;
    if (m.layer==1) {
      if      (m.ladder==-6) rel_fluence_l1 = 0.7267612;
      else if (m.ladder==-5) rel_fluence_l1 = 0.9493437;
      else if (m.ladder==-4) rel_fluence_l1 = 0.7931179;
      else if (m.ladder==-3) rel_fluence_l1 = 0.9827834;
      else if (m.ladder==-2) rel_fluence_l1 = 0.8119277;
      else if (m.ladder==-1) rel_fluence_l1 = 1.0000260;
      else if (m.ladder== 1) rel_fluence_l1 = 0.7215362;
      else if (m.ladder== 2) rel_fluence_l1 = 0.9822609;
      else if (m.ladder== 3) rel_fluence_l1 = 0.7763981;
      else if (m.ladder== 4) rel_fluence_l1 = 0.9493437;
      else if (m.ladder== 5) rel_fluence_l1 = 0.7899830;
      else if (m.ladder== 6) rel_fluence_l1 = 0.9430738;
    }

    //_____________________________________
    //              Postfixes
    pf_layers = (m.det==0) ? m.layer-1 : (size_t)-1;
    pf_mods  = (m.det==0) ? abs(m.module)-1 : (size_t)-1;
    pf_allmods  = (m.det==0) ? m.module+4-(m.module>0) : (size_t)-1;
    pf_ladders = (m.det==0) ? abs(m.ladder)-1 : (size_t)-1;
    pf_disks = (m.det==0) ? (size_t)-1 :  abs(m.disk)-1;
    pf_disksio = (m.det==0) ? (size_t)-1 :  abs(m.disk)*2  - ((m.panel+m.module)<4) - 1;
    pf_all_disks = (m.det==0) ? (size_t)-1 : m.disk+2+PHASE-(m.disk>0);
    pf_lays_disks        = (m.det==0) ? m.layer-1 :  2 + abs(m.disk);
    pf_lays_disks_phase1 = (m.det==0) ? m.layer-1 :  3 + abs(m.disk);
    pf_lays_disksio = (m.det==0) ? m.layer-1 :  2 + abs(m.disk)*2 - ((m.panel+m.module)<4);
    pf_det = m.det;
#if PHASE == 0    
    pf_new_modules = e.run>240000 &&
      ( m.layer==1 ?
        (m.module== 2 && m.ladder== 2)||
        (m.module== 3 && m.ladder== 2)||
        (m.module== 1 && m.ladder== 3)||
        (m.module== 1 && m.ladder== 5)||
        (m.module== 3 && m.ladder== 5)||
        (m.module== 1 && m.ladder== 7)||
        (m.module== 2 && m.ladder== 7)||
        (m.module== 2 && m.ladder== 9)||
        (m.module== 3 && m.ladder==10) :
        m.layer==2 ?
        (m.module== 4 && m.ladder== 1)||
        (m.module== 1 && m.ladder== 2)||
        (m.module== 2 && m.ladder== 2)||
        (m.module== 1 && m.ladder== 3)||
        (m.module== 2 && m.ladder== 4)||
        (m.module== 4 && m.ladder== 4)||
        (m.module== 2 && m.ladder== 5)||
        (m.module== 2 && m.ladder== 6)||
        (m.module== 2 && m.ladder== 7)||
        (m.module== 2 && m.ladder== 8)||
        (m.module== 3 && m.ladder== 8)||
        (m.module== 2 && m.ladder==10)||
        (m.module== 3 && m.ladder==10)||
        (m.module== 2 && m.ladder== 9)||
        (m.module== 3 && m.ladder== 9)||
        (m.module== 4 && m.ladder== 9)||
        (m.module== 1 && m.ladder==12)||
        (m.module== 2 && m.ladder==12) :
        m.layer==3 ?
        (m.module== 4 && m.ladder== 2)||
        (m.module== 1 && m.ladder== 3)||
        (m.module== 4 && m.ladder== 3)||
        (m.module== 1 && m.ladder== 6)||
        (m.module== 4 && m.ladder== 8)||
        (m.module== 2 && m.ladder==12)||
        (m.module== 3 && m.ladder==13)||
        (m.module== 4 && m.ladder==13)||
        (m.module== 2 && m.ladder==15)||
        (m.module== 1 && m.ladder==18)||
        (m.module== 4 && m.ladder==22)||
        (m.module== 2 && m.ladder== 3)||
        (m.module== 1 && m.ladder==11)||
        (m.module== 4 && m.ladder==11)||
        (m.module==-3 && m.ladder== 5)||
        (m.module==-3 && m.ladder== 4)||
        (m.module==-1 && m.ladder== 9)||
        (m.module==-1 && m.ladder==11)||
        (m.module==-2 && m.ladder==11)||
        (m.module==-4 && m.ladder==11)||
        (m.module==-2 && m.ladder==13) :
        0);
    pf_lays_disks_oldnew = (m.det==0) ? (pf_new_modules ? m.layer+4 : m.layer-1) :  2 + abs(m.disk);
#else
    pf_new_modules = e.run>=314472 && // First 2018 run
      ( m.rawid==303054856 || //BPix_BmO_SEC1_LYR1_LDR1F_MOD3
        m.rawid==303054864 || //BPix_BmO_SEC2_LYR1_LDR1F_MOD1
        m.rawid==303063056 || //BPix_BmO_SEC4_LYR1_LDR3F_MOD1
        m.rawid==303071248 || //BPix_BmO_SEC7_LYR1_LDR5F_MOD1
        m.rawid==303054876 || //BPix_BpO_SEC1_LYR1_LDR1F_MOD3
        m.rawid==303063068 ); //BPix_BpO_SEC4_LYR1_LDR3F_MOD3
    pf_lays_disks_oldnew = (m.det==0) ? (pf_new_modules ? 0 : m.layer) :  4 + abs(m.disk);
#endif
  }
  
  void postfixes_cuts_(const EventData &e, const TrajMeasurement &t) { common_evt_(e); common_(e, t.mod_on); }
  void clu_postfixes_cuts_(const EventData &e, const Cluster &c) { common_evt_(e); common_(e, c.mod_on); }
  
  int evt_lastevt_;
  int evt_lastls_;
  int evt_lastrun_;
  int evt_lastfill_;
  int lumi_lastrun_;
  int lumi_lastfill_;
  unsigned long int lumi_lastrunls_;
  int run_lastfill_;
  int run_lastrun_;

  int clu_lastfill_;

  int debug_;

  void init_() {
    lumi_totlumi = 0.0;
    lumi_totlumi_2012 = 0.0;
    
    layers_disks = NOVAL_I;
    sdp_x = NOVAL_I;
    mod_index_x = NOVAL_I;
    mod_index_y = NOVAL_I;
    mod_x = NOVAL_I;
    mod_y = NOVAL_I;
    roc_binx = NOVAL_I;
    roc_biny = NOVAL_I;
    run_bin = NOVAL_I; 
    inactive = NOVAL_I;
    delay = NOVAL_I;
    p2_secdisk = NOVAL_I;
    p3_layrog = NOVAL_I;
    
    clu_det_x = NOVAL_I;
    clu_sdp_x = NOVAL_I;
    clu_mod_indexx = NOVAL_I;
    clu_mod_indexy = NOVAL_I;
    clu_mod_p1 = NOVAL_I;
    clu_roc_p1 = NOVAL_I;
    clu_roc_binx = NOVAL_I;
    clu_roc_biny = NOVAL_I;
    
    lumi_lastrun_ = 0;
    lumi_lastfill_ = -1;
    lumi_lastrunls_ = 0;
    run_lastfill_ = -1;
    run_lastrun_ = 0;
    evt_lastfill_ = -1;
    evt_lastrun_ = NOVAL_I;
    evt_lastls_ = NOVAL_I;
    evt_lastevt_ = NOVAL_I;
    
    lastevt = 0;
    lastbx  = 0;
    lastorb = 0;
    lastls  = 0;
    lastrun = 0;

    clu_lastfill_ = -1;
    
    cut_zb = 0;
    cut_nvtx = 0;
    cut_federr = 0;
    pt = 0;
    hp = 0;
    nstrip = 0;
    d0 = 0;
    dz = 0;
    pixhit = 0;
    noscan = 0;
    goodmod = 0;
    goodroc = 0;
    lx_fid = 0;
    ly_fid = 0;
    valmis = 0;
    hitsep = 0;
    dcol_clu_cuts = 0;
    pt_new = 0;
    d0_new = 0;
    dz_new = 0;
    hitsep_new = 0;
    
    effcut_all= 0;
    effcut_trig= 0;
    effcut_nvtx= 0;
    effcut_federr= 0;
    effcut_pt= 0;
    effcut_nstrip= 0;
    effcut_d0= 0;
    effcut_dz= 0;
    effcut_d0_dz= 0;
    effcut_scans= 0;
    effcut_scans_loose= 0;
    effcut_ly_fid= 0;
    effcut_lx_fid= 0;
    effcut_lxly_fid= 0;
    effcut_hitsep= 0;
    effcut_beta= 0;
    new_effcut_all= 0;
    new_effcut_presel= 0;
    dcol_effcut_all= 0;
    dcol_effcut_scans= 0;
    dcol_effcut_allmod= 0;
  }
  
  void build_() {
    debug_ = 0;
    // Read Integrated Luminosity values for 2011 runs
    // Calculate total integrated luminosity for all runs
    //FILE* input = fopen ("input/total_intlumi_ub.txt","r");
    //double intlumi = 0.0, total = 0.0;
    //int run, a = 1;
    //while (a==1) {
    //  a = fscanf (input, "%d", &run);
    //  a = fscanf (input, "%lf", &intlumi);
    //  if (a==1) { total += intlumi; totallumi[run] = total; }
    //}
    //fclose (input);
    //input = fopen ("input/total_intlumi_ub_2012.txt","r");
    //intlumi = 0.0; total = 0.0; a = 1;
    //while (a==1) {
    //  a = fscanf (input, "%d", &run);
    //  a = fscanf (input, "%lf", &intlumi);
    //  if (a==1) { total += intlumi; totallumi_2012[run] = total; }
    //}
    //fclose (input);
    
    // Read Luminosity/Pileup info
    FILE* input;
    int run, ls, a = 1, lastrun = 0;
    double intl = 0, instl = 0, pileup = 0, tot_intlumi_invnb = 0, intlumi_run_invnb = 0;
    unsigned long int runls = 0;
    // total int lumi
    input = fopen ("input/run_ls_intlumi_phase0.txt","r");
    while (a==1) {
      a = fscanf (input, "%d", &run);
      a = fscanf (input, "%d", &ls);
      a = fscanf (input, "%lf", &intl);
      if (a==1) {
	runls = run * 100000 + ls;
	tot_intlumi_invnb += intl;
	fromfile_intlumi[runls] = tot_intlumi_invnb / 1e6; // convert to fb^-1
      }
    }
    fclose (input);
    // instlumi pileup
    a = 1;
    input = fopen ("input/run_ls_instlumi_pileup_phase0.txt","r");
    while (a==1) {
      a = fscanf (input, "%d", &run);
      a = fscanf (input, "%d", &ls);
      a = fscanf (input, "%lf", &instl);
      a = fscanf (input, "%lf", &pileup);
      if (a==1) {
	runls = run * 100000 + ls;
	fromfile_instlumi[runls] = instl / 23.311; // convert to Hz/nb
	fromfile_pileup[runls] = pileup;
	if (run != lastrun) intlumi_run_invnb = 0;
	intlumi_run_invnb += instl;
	fromfile_intlumi_run[runls] = intlumi_run_invnb / 1e3; // convert to pb^-1
	lastrun = run;
      }
    }
    fclose (input);
    // Phase 1
    tot_intlumi_invnb = 0;
    //input = fopen ("input/run_ls_instlumi_pileup_2017.txt","r");
    input = fopen ("input/run_ls_instlumi_pileup_phase1.txt","r");
    //input = fopen ("input/run_ls_intlumi_pileup_phase1_Run3.txt","r");
    a = 1;
    while (a==1) {
      a = fscanf (input, "%d", &run);
      a = fscanf (input, "%d", &ls);
      a = fscanf (input, "%lf", &instl);
      a = fscanf (input, "%lf", &pileup);
      if (a==1) {
        runls = run * 100000 + ls;
        tot_intlumi_invnb += instl;
        fromfile_intlumi[runls] = tot_intlumi_invnb / 1e6; // convert to fb^-1
        fromfile_instlumi[runls] = instl / 23.311; // (Hz/nb)
        fromfile_pileup[runls] = pileup;
        if (run != lastrun) intlumi_run_invnb = 0;
        intlumi_run_invnb += instl;
        fromfile_intlumi_run[runls] = intlumi_run_invnb / 1e3; // convert to pb^-1
        lastrun = run;
      }
    }
    fclose (input);

    // create correct size of arrays for GoodRocList
    goodroc_list.resize(8);
    for (size_t i=0; i<8; i++) {
#if PHASE == 0
      if (i<4) { goodroc_list[i].resize(48);
	for (size_t j=0; j<goodroc_list[i].size(); j++) goodroc_list[i][j].resize(64);
      } else { goodroc_list[i].resize(24);
	for (size_t j=0; j<goodroc_list[i].size(); j++) goodroc_list[i][j].resize(45);
      }
#else
      if (i<4) { goodroc_list[i].resize(74);
	for (size_t j=0; j<goodroc_list[i].size(); j++) goodroc_list[i][j].resize(64);
      } else { goodroc_list[i].resize(84);
	for (size_t j=0; j<goodroc_list[i].size(); j++) goodroc_list[i][j].resize(32);
      }
#endif
    }
    
    evt_federr_type.resize(19);
    evt_federr_type[0]=1;
    evt_federr_type.resize(19);
    evt_federr_mult.resize(19);
    evt_federr_type[0]=1;
    evt_federr_mult[0]=1;
    run_nfill = 0;
    
    pf_data = -1;
    
    // DynIneff factors
    //theLadderEfficiency_BPix[0] = {
    //  0.978351, 0.971877, 0.974283, 0.969328, 0.972922,
    //  0.970964, 0.975762, 0.974786, 0.980244, 0.978452,
    //  0.982129, 0.979737, 0.984381, 0.983971, 0.98186,
    //  0.983283, 0.981485, 0.979753, 0.980287, 0.975195
    //};
    //theLadderEfficiency_BPix[1] = {
    //  0.996276, 0.993354, 0.993752, 0.992948, 0.993871,
    //  0.992317, 0.997733, 0.992516, 0.992649, 0.993425,
    //  0.994065, 0.993481, 0.993169, 0.994223, 0.992397,
    //  0.99509, 0.995177, 0.995319, 0.994925, 0.992933,
    //  0.994111, 0.9948, 0.994711, 0.994294, 0.995392,
    //  0.994229, 0.994414, 0.995271, 0.993585, 0.995264,
    //  0.992977, 0.993642
    //};
    //theLadderEfficiency_BPix[2] = {
    //  0.996206, 0.998039, 0.995801, 0.99665, 0.996414,
    //  0.995755, 0.996518, 0.995584, 0.997171, 0.998056,
    //  0.99595, 0.997473, 0.996858, 0.996486, 0.997442,
    //  0.998002, 0.995429, 0.997939, 0.996896, 0.997434,
    //  0.996616, 0.996439, 0.996546, 0.997597, 0.995435,
    //  0.996396, 0.99621, 0.998316, 0.998431, 0.99598,
    //  0.997063, 0.996245, 0.997502, 0.996254, 0.997545,
    //  0.997553, 0.996722, 0.996107, 0.996588, 0.996277,
    //  0.99785, 0.997087, 0.998139, 0.997139
    //};
    theLadderEfficiency_BPix[0] = {
      0.979259, 0.976677, 0.979259, 0.976677, 0.979259, 0.976677,
      0.979259, 0.976677, 0.979259, 0.976677, 0.979259, 0.976677,
      0.979259, 0.976677, 0.979259, 0.976677, 0.979259, 0.976677,
      0.979259, 0.976677
    };
    theLadderEfficiency_BPix[1] = {
      0.994321, 0.993944, 0.994321, 0.993944, 0.994321, 0.993944, 0.994321, 0.993944,
      0.994321, 0.993944, 0.994321, 0.993944, 0.994321, 0.993944, 0.994321, 0.993944,
      0.994321, 0.993944, 0.994321, 0.993944, 0.994321, 0.993944, 0.994321, 0.993944,
      0.994321, 0.993944, 0.994321, 0.993944, 0.994321, 0.993944, 0.994321, 0.993944
    };
    theLadderEfficiency_BPix[2] = {
      0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945,
      0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945,
      0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945,
      0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945,
      0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945, 0.996787, 0.996945,
      0.996787, 0.996945, 0.996787, 0.996945
    };
    theModuleEfficiency_BPix[0] = { 1.00361, 0.999371, 0.961242, 0.952364 };
    theModuleEfficiency_BPix[1] = { 1.00069, 0.999792, 0.99562,  1.00341 }; //0.955627 };
    theModuleEfficiency_BPix[2] = { 1.00006, 0.999744, 0.998147, 1.00039 }; // 1.00314 };
    theInnerEfficiency_FPix = 0.994015;
    theOuterEfficiency_FPix = 0.996454;
    thePUEfficiency_BPix[0] = { 1.0181, -2.28345e-07, -1.30042e-09 };
    thePUEfficiency_BPix[1] = { 1.00648, -1.28515e-06, -1.85915e-10 };
    thePUEfficiency_BPix[2] = { 1.0032, -1.96206e-08, -1.99009e-10 };
  }
  
  std::map<int, int> run_firstbx_;

  // Pileup reweighting
  std::vector<int> nevt_;
  std::vector<float> norm_factor_;
  std::vector<std::vector<float> > pileup_;
  std::vector<std::vector<double> > pileup_dbl_;
  std::vector<reweight::LumiReWeighting*> reweight_;
  
public:
  void preloop_events(const EventData &e) {
    // ZeroBias events - count filled bunches
    if (e.trig&1) {
      if (!run_firstbx_.count(e.run)) run_firstbx_[e.run] = e.bx;
      else if(e.bx<run_firstbx_[e.run])	run_firstbx_[e.run] = e.bx;
    }
  }
  
  void set_nevt_data(size_t size, size_t i_data, size_t nevt_data = 0) {
    nevt_ = std::vector<int>(size,0);
    norm_factor_ = std::vector<float>(size,0);
    pf_data = i_data;
    if (nevt_data!=0) nevt_[pf_data] = nevt_data;
  }
  
  void add_data_pileup_histo(size_t size, size_t i_data, const char* filename, const char* hname, size_t nevt_data = 0) {
    std::cout<<"PileupHistogram added! Doing preloop on eventTrees to obtain weights...\n";
    nevt_ = std::vector<int>(size,0);
    norm_factor_ = std::vector<float>(size,0);
    pileup_= std::vector<std::vector<float> >(size,std::vector<float>(50,0));
    pileup_dbl_= std::vector<std::vector<double> >(size,std::vector<double>(50,0));
    reweight_.resize(size);
    pf_data = i_data;
    if (nevt_data!=0) nevt_[pf_data] = nevt_data;
    TFile* f = TFile::Open(filename);
    TH1D* h = (TH1D*)f->Get(hname);
    for (int i=1; i<=50; ++i) pileup_dbl_[pf_data][i-1] = h->GetBinContent(i);
    f->Close();
  }
  
  void count_pileup_events(size_t i_add, const EventData &e) {
    // count only zerobias events that has at lease 1 good vtx
    if ((e.trig&1)&&(e.nvtx>=1)) {
      //if (i_add>0||(e.run==203002&&!(e.ls<77||(e.ls>128&&e.ls<130)||(e.ls>141&&e.ls<144)||(e.ls>207&&e.ls<209)||(e.ls>267&&e.ls<270)||(e.ls>360&&e.ls<362)||(e.ls>501&&e.ls<504)||(e.ls>641&&e.ls<643)||(e.ls>669&&e.ls<671)||(e.ls>671&&e.ls<674)||(e.ls>717&&e.ls<720)||(e.ls>1034&&e.ls<1037)||(e.ls>1070&&e.ls<1073)||(e.ls>1370&&e.ls<1372)||(e.ls>1392&&e.ls<1395)||(e.ls>1410&&e.ls<1413)||e.ls>1596))) {
      ++nevt_[i_add];
      //if (nevt_[i_add]%100000==1) std::cout<<i_add<<" "<<nevt_[i_add]<<std::endl;
      // get pileup dist for mc
#if DATASTRUCT_VER > 29
      if (pileup_dbl_.size()>0&&e.run==1&&e.pileup!=NOVAL_F) ++pileup_dbl_[i_add][std::min((int)e.pileup,49)];
#endif
    }
  }
  void calc_weights() {
    for (size_t i_add=0; i_add<pileup_dbl_.size(); ++i_add) for (int i=0; i<50; ++i) pileup_[i_add][i] = pileup_dbl_[i_add][i]; // convert double to float (no loss)
    for (size_t i=0; i<pileup_.size(); ++i) if(i!=pf_data&&nevt_[i]>0) {
      // Normally the line below will print out pileup weights, but this is commented out in the header
      std::cout<<"Lumi weights for MC"<<i<<":"<<std::endl;
      reweight_[i] = new reweight::LumiReWeighting(pileup_[i],pileup_[pf_data]); // prints factors
    }
    for (size_t i=0; i<norm_factor_.size(); ++i) {
      norm_factor_[i] = nevt_[i]>0 ? (double)nevt_[pf_data] / (double)nevt_[i] : 0;
      std::cout<<"N_evt_data = "<<nevt_[pf_data]<<" N_evt["<<i<<"] = "<<nevt_[i]<<" --> Normalisation factor = "<<norm_factor_[i]<<std::endl;
    }
    //for (int i=0; i<50; ++i) std::cout<<i<<" "<<reweight_[1]->weight(0.5+i)<<std::endl;
    std::cout<<"Calculating weights, done.\n";
  }
 
  void load_roc_sel_(int fill, int run, int era = 1) {
    //std::cout<<"Loading ROC selection for run: "<<run<<std::endl;
    for (size_t i=0; i<8; i++) for (size_t j=0; j<goodroc_list[i].size(); j++)
      for (size_t k=0; k<goodroc_list[i][j].size(); k++) goodroc_list[i][j][k]=1;
    if (era == 1) {
      //std::cout<<"loading roc selection for fill: "<<fill<<std::endl;
      if (fill!=-1&&fill!=0) {
        FILE* input;
        std::stringstream ss;
        ss<<"input/BADROC_EXCL/"
          <<run_fillname[fill]<<".txt";
        input = fopen(ss.str().c_str(),"r");
        if (input==0) {
          //std::cout<<"No Bad ROC List exists for Fill "<<run_fillname[fill]<<std::endl;
        } else {
          int a=1;
          while (a==1) { int p1,p2,p3;
            a = fscanf (input, "%d", &p1); a = a* fscanf (input, "%d", &p2);
            a = a* fscanf (input, "%d", &p3); if (a==1) { goodroc_list[p1][p2][p3] = 0; }
          }
          fclose(input);
        }
      }
    } else if (era == 2) {
      TFile *f = TFile::Open("input/Badroc_List.root");
      if (f) {
        std::stringstream name; name<<"run_"<<run;
        TH1D* badroc_list = (TH1D*)f->Get(name.str().c_str());
	if (badroc_list) for (int bin=1; bin<=badroc_list->GetBinContent(0); ++bin) {
          int rocid = badroc_list->GetBinContent(bin);
          int p1 = (rocid/10000)%100, p2 = (rocid/100)%100, p3 = rocid%100;
          goodroc_list[p1][p2][p3] = 0;
        }
        f->Close();
      }
    }
  }
  
  bool is_instlumi_good_(int run, int ls) {
    std::vector<double> vec;
    double mean=0;
    double rms=0;
    double val = instlumi_ls_map[run]->GetBinContent(ls);
    for (int i=1; i<=10; i++) {
      double cont=0;
      int bin = i<6? ls+i-6 : ls+i-5;
      if (bin>0) cont = instlumi_ls_map[run]->GetBinContent(bin);
      if (cont>0) {
        vec.push_back(cont);
        mean += cont;
      }
    }
    if (vec.size()) {
      mean /= vec.size();
      for (size_t i=0; i<vec.size(); i++) rms += (vec[i]-mean) * (vec[i]-mean);
      rms = sqrt(rms/vec.size());
    }
    return vec.size() ? (vec.size()>1 ? (fabs(val-mean)/rms < 2.0) : 1) && (fabs(val/mean - 1)<0.04) : 1;
  }
  
  // Modifiers
  void load_lumi_var(const LumiData &lumi) {
    // For some reason lumiTree was not filled in new MC 720pre5
    int run_corr = (lumi.run==NOVAL_I) ? 1 : lumi.run;
    int ls_corr = (lumi.ls==NOVAL_I) ? 1 : lumi.ls;

    // Look for lumisections with bad instlumi values
    lumi_good_instlumi = (run_corr==1) ? 0 : is_instlumi_good_(run_corr, ls_corr);
    unsigned long int runls = run_corr*100000+ls_corr;
    lumi_instlumi    = NOVAL_F;
    lumi_intlumi     = NOVAL_F;
    lumi_intlumi_run = NOVAL_F;
    lumi_pileup      = NOVAL_F;
    if (run_corr>=160403 && fromfile_instlumi.count(runls) && lumi_good_instlumi) { // First run in txt files, also check that measurement is similar to nearby ls
      lumi_instlumi    = fromfile_instlumi[runls];    // (Hz/nb)
      lumi_intlumi     = fromfile_intlumi[runls];     // (/fb)
      lumi_intlumi_run = fromfile_intlumi_run[runls]; // (/pb)
      lumi_pileup      = fromfile_pileup[runls];
    }

    // Fill number definition (to account for RAW problem and older versions)
    if (filldef.count(run_corr)) lumi_fill = filldef[run_corr];
    else { std::cout<<"Variables::load_lumi_var_: Problem with filldef with run "<<run_corr<<std::endl; lumi_fill = -1; }
#if DATASTRUCT_VER >= 27
    lumi_time_in_fill = (lumi.time - lumi_fillstart[lumi_fill])/3600.0;
#else
    lumi_time_in_fill = (((run_corr>=176201&&run_corr<=176207) ? (run_corr>176201)*666 + (run_corr>176202)*301 + (run_corr>176206)*109
		  : (run_corr>=176304&&run_corr<=176309) ? (run_corr>176304)*619.2 + (run_corr>176308)*308 : 0) + ls_corr)* 23.311 / 3600.0;
#endif
    
    // // Calculate total luminosity (/fb)
    // int r = run_corr;
    // if ((totallumi.count(r))) lumi_totlumi = totallumi[r]/1000000000.0;
    // else if (r>132440) { while(!(totallumi.count(r))) r--; lumi_totlumi = totallumi[r]/1000000000.0; }
    // else if (r==NOVAL_I) { if (!debug_) std::cout<<"run_corr = NOVAL_I"<<r<<std::endl; debug_++; lumi_totlumi = NOVAL_F; }
    // else if (r!=1) { std::cout<<"Warning: Early run before 132440 Run = "<<r<<std::endl; lumi_totlumi = NOVAL_F; }
    // // 2012 only (/fb)
    // r = run_corr;
    // if ((totallumi_2012.count(r))) lumi_totlumi_2012 = totallumi_2012[r]/1000000000.0;
    // else if (r>187452) { while(!(totallumi_2012.count(r))) r--; lumi_totlumi = totallumi_2012[r]/1000000000.0; }
    // else if (r==NOVAL_I) { if (!debug_) std::cout<<"run_corr = NOVAL_I"<<r<<std::endl; debug_++; lumi_totlumi = NOVAL_F; }
    // else if (r!=1) { lumi_totlumi = 0; }
    
    // Load new ROC selection
#ifndef EXPRESS
    if (lumi.run<238474) { 
      // Run I
      if (lumi_fill!=lumi_lastfill_) load_roc_sel_(lumi_fill, lumi.run, 1);
      if (lumi_fill==-1) std::cout<<"run not defined as any fill: "<<run_corr<<std::endl;
    } else {
      // New Simplified run dependent Bad ROC list
      load_roc_sel_(lumi_fill, lumi.run, 2);
    }
    lumi_lastfill_ = lumi_fill;
#endif
    
    // Calculate the Dates
    // day 1-366
    // month 1-12
    // year 1970-2038
    // Every 4th year from 1972 is leap year (1972,1976, ... ,2012,2016 ... etc.)
    int days_since_1973 = lumi.time/86400-3*365-1;
    int nleap_since_1973 = days_since_1973/1461;
    int days_since_leap_year = days_since_1973 - nleap_since_1973*1461;
    int year_offset = (nleap_since_1973*1461 + (days_since_leap_year/365 - (days_since_leap_year==1460)+3)*365+1)*86400;
    lumi_day = (lumi.time-year_offset)/86400 + 1;
    lumi_month = (lumi_day>=0) + (lumi_day>=31) + (lumi_day>=59) + (lumi_day>=90) +
      (lumi_day>=120) + (lumi_day>=151) + (lumi_day>=181) + (lumi_day>=212) +
      (lumi_day>=243) + (lumi_day>=273) + (lumi_day>=304) + (lumi_day>=334)-(days_since_leap_year>1152);
    lumi_year = 1973 + nleap_since_1973*4 + days_since_leap_year/365 - (days_since_leap_year==1460);
    lumi_time = lumi.time - year_offset;
    lumi_weektime = lumi_time + (year_offset/86400-4)%7*86400; // Monday correction
    lumi_monthtime = lumi_time - (days_since_leap_year>1152)*86400; // Leap month correction
  }

  void load_lumi_var_phase1(const EventData &e) {
    // Only calculate stuff, if it is a new lumisection
    unsigned long int runls = e.run * 100000 + e.ls;
    if (runls!=lumi_lastrunls_) {
    // Look for lumisections with bad instlumi values
      //lumi_good_instlumi = (e.run==1) ? 0 : is_instlumi_good_(e.run, e.ls);
      lumi_good_instlumi = 1;
      lumi_instlumi    = NOVAL_F;
      lumi_intlumi     = NOVAL_F;
      lumi_intlumi_run = NOVAL_F;
      lumi_pileup      = NOVAL_F;
      if (e.run>=160403 && fromfile_instlumi.count(runls) && lumi_good_instlumi) { // First run in txt files, also check that measurement is similar to nearby ls
	lumi_instlumi    = fromfile_instlumi[runls];    // (Hz/nb)
	lumi_intlumi     = fromfile_intlumi[runls];     // (/fb)
	lumi_intlumi_run = fromfile_intlumi_run[runls]; // (/pb)
	lumi_pileup      = fromfile_pileup[runls];
      }

      // Calculate the Dates - Not yet ok in ntuple
      // day 1-366
      // month 1-12
      // year 1970-2038
      // Every 4th year from 1972 is leap year (1972,1976, ... ,2012,2016 ... etc.)

      //    int days_since_1973 = e.time/86400-3*365-1;
      //    int nleap_since_1973 = days_since_1973/1461;
      //    int days_since_leap_year = days_since_1973 - nleap_since_1973*1461;
      //    int year_offset = (nleap_since_1973*1461 + (days_since_leap_year/365 - (days_since_leap_year==1460)+3)*365+1)*86400;
      //    lumi_day = (e.time-year_offset)/86400 + 1;
      //    lumi_month = (lumi_day>=0) + (lumi_day>=31) + (lumi_day>=59) + (lumi_day>=90) +
      //      (lumi_day>=120) + (lumi_day>=151) + (lumi_day>=181) + (lumi_day>=212) +
      //      (lumi_day>=243) + (lumi_day>=273) + (lumi_day>=304) + (lumi_day>=334)-(days_since_leap_year>1152);
      //    lumi_year = 1973 + nleap_since_1973*4 + days_since_leap_year/365 - (days_since_leap_year==1460);
      //    lumi_time = e.time - year_offset;
      //    lumi_weektime = lumi_time + (year_offset/86400-4)%7*86400; // Monday correction
      //    lumi_monthtime = lumi_time - (days_since_leap_year>1152)*86400; // Leap month correction

      //        // Fill number definition (to account for RAW problem and older versions)
      //        if (filldef.count(e.run)) lumi_fill = filldef[e.run];
      //        else { std::cout<<"Variables::load_lumi_var_: Problem with filldef with run "<<e.run<<std::endl; lumi_fill = -1; }
      //  #if DATASTRUCT_VER >= 27
      //        lumi_time_in_fill = (lumi.time - lumi_fillstart[lumi_fill])/3600.0;
      //  #else
      //        lumi_time_in_fill = (((e.run>=176201&&e.run<=176207) ? (e.run>176201)*666 + (e.run>176202)*301 + (e.run>176206)*109
      //  			    : (e.run>=176304&&e.run<=176309) ? (e.run>176304)*619.2 + (e.run>176308)*308 : 0) + e.ls)* 23.311 / 3600.0;
      //  #endif

      // Load new ROC selection
#ifndef EXPRESS
      if (e.run<238474) { 
	// Run I
	if (lumi_fill!=lumi_lastfill_) load_roc_sel_(lumi_fill, e.run, 1);
	if (lumi_fill==-1) std::cout<<"run not defined as any fill: "<<e.run<<std::endl;
      } else {
	// New Simplified run dependent Bad ROC list
	load_roc_sel_(0, e.run, 2);
      }
      lumi_lastfill_ = lumi_fill;
#endif
    }
    lumi_lastrunls_ = runls;
  }

  void load_evt_var(const EventData &e) {
    // Run
    evt_run_binx = run_index.count(e.run) ? run_index[e.run] : NOVAL_I;
    
    // Calculate total luminosity (/pb) - from 2010
    //int r = e.run;
    //if ((totallumi.count(r))) evt_totlumi = totallumi[r]/1000000.0;
    //else if (r>160404) { while(!(totallumi.count(r))) r--; evt_totlumi = totallumi[r]/1000000.0; }
    //else if (r!=1) { evt_totlumi = 0; }
    
    // Fill
    // Warning: evt_p1_fill depends on evt_fill
    if (filldef.count(e.run)) evt_fill = filldef[e.run];
    else { std::cout<<"Variables::load_evt_: Problem with filldef for run "<<e.run<<std::endl; evt_fill = -1; filldef[e.run]=-1; }
    //if (evt_fill!=evt_lastfill_) evt_p1_fill = run_fill_index[evt_fill];
    evt_lastfill_ = evt_fill;
    
    // Fed error variable: tells the number of errors of a certain type in the event
    for (int i=1; i<19; i++) evt_federr_mult[i]=0;
    evt_federr_mult[1]=(e.federrs_size==0);
    evt_federr_mult[2]=e.federrs_size;
    for (int i=0; i<e.federrs_size; i++)
      evt_federr_mult[e.federrs[i][1]-22] += 1;
    // Fed error variable: tells whether event has certain FED error
    for (int i=1; i<19; i++) evt_federr_type[i]=0;
    evt_federr_type[1]=(e.federrs_size==0);
    evt_federr_type[2]=(e.federrs_size>0);
    for (int i=0; i<e.federrs_size; i++)
      evt_federr_type[e.federrs[i][1]-22] = 1;
    
    common_evt_(e);
  }
  
  // Same as TimingStudy::get_RocID_from_local_coords
  int roc_(const float &lx, const float &ly, const ModuleData &m) {
    if (m.det==0) {
      if (fabs(ly)<3.24&&((m.half==0&&fabs(lx)<0.8164)||(m.half==1&&fabs(lx)<0.4082))) {
	int nroc_y = (int)(ly / 0.81 + 4);
	int roc = (m.half) ? ((m.module<0)*8+nroc_y) : ((m.module>0) ? ((lx>0.0) ? nroc_y : 15-nroc_y) : ((lx>0.0) ? 8+nroc_y : 7-nroc_y));
	return roc;
      } else return NOVAL_I;
    } else if (m.det==1) {
      int nrocly = m.module + m.panel;
      if (fabs(ly)<(nrocly*0.405) && ( ( !(m.panel==1&&(m.module==1||m.module==4)) && fabs(lx)<0.8164 ) || (fabs(lx)<0.4082) )) {
	int rocy = (int)((ly+(nrocly%2)*0.405)/0.81+nrocly/2);
	int roc = ((m.panel==2 && lx<0.0)
		   || (m.panel==1 && (m.module==1||m.module==4))
		   || (m.panel==1 && (m.module==2||m.module==3) && lx>0.0 )) ? rocy
	  : 2*nrocly -1 - rocy;
	return roc;
      } else return NOVAL_I;
    } else return NOVAL_I;
  }
  
  // Same as TimingStudy::get_RocID_from_cluster_coords
  int clu_roc_(const float &x, const float &y, const ModuleData &m) {
    if (x!=NOVAL_F&&y!=NOVAL_F) {
      if (m.det==0) {
	int nroc_y = (int)(y / 52.0);
	int roc = (m.half) ? ((m.module<0)*8+nroc_y) : ((m.module>0) ? ((x>80.0) ? nroc_y : 15-nroc_y) : ((x>80.0) ? 8+nroc_y : 7-nroc_y));
	return roc;
      } else if (m.det==1) {
	int nrocly = m.module + m.panel;
	int rocy = (int)(y/52.0);
	int roc = ((m.panel==2 && x<80.0)
		   || (m.panel==1 && (m.module==1||m.module==4))
		   || (m.panel==1 && (m.module==2||m.module==3) && x>80.0 )) ? rocy
	  : 2*nrocly -1 - rocy;
	return roc;
      } else return NOVAL_I;
    } else {
      if (!debug_) std::cout<<"TReereader error: Please SetBrancStatus On"
			    <<" for branch: clust_xy in clustTree"<<std::endl;
      debug_++;
      return NOVAL_I;
    }
  }
  
  int roc2_(const float x, const float y, const ModuleData &m) {
    if (m.det==0) { // Barrel pixel
      int nroc_y = (int)(y / 52); // Nth ROC along local y
      int roc = (m.half) ? ((m.module<0)*8+nroc_y) // Half modules (Ladder +-1 etc)
	: ((m.module>0) ? ((x>80.0) ? nroc_y // +Z (BpI,BpO), TBM A
			   : 15-nroc_y ) // +Z, TBM B
	   : ((x>80.0) ? 8+nroc_y  // -Z (BmI,BmO), TBM B
	      : 7-nroc_y)); // -Z, TBM A
      return roc;
    } else if (m.det==1) { // Forward pixel
      int nroc = m.module + m.panel; // Number of Rocs along local y coordinate
      int nroc_y = (int)(y / 52.0); // Nth ROC along local y
      int roc = ((m.panel==2 && x<80.0) // -ly side of 2xN Panel 2 Plaquettes
		 || (m.panel==1 && (m.module==1||m.module==4)) // 1x2, 1x5 Plaquettes on Panel 1
		 || (m.panel==1 && (m.module==2||m.module==3) && x>80.0 )) ? nroc_y // +ly side of 2xN Panel 1 Plaquettes
	: 2*nroc -1 - nroc_y; // Opposite side of 2xN Plaquettes
      return roc;
    } else return NOVAL_I;
  }
  
  void load_traj_var(const EventData &e, const TrajMeasurement &t) {
    const ModuleData& m = t.mod_on;

    //if (m.layer==1) std::cout<<" "<<t.norm_charge<<std::endl;
    dr_hit = (t.dx_hit  !=NOVAL_F) ? sqrt(  t.dx_hit *   t.dx_hit +   t.dy_hit *   t.dy_hit) : NOVAL_F;
#if DATASTRUCT_VER < 100
    dr_clu = (t.dx_cl[0]!=NOVAL_F) ? sqrt(t.dx_cl[0] * t.dx_cl[0] + t.dy_cl[0] * t.dy_cl[0]) : NOVAL_F;
    dr_cluclu = (t.dx_cl[0]!=NOVAL_F&&t.dx_cl[1]) ? sqrt((t.dx_cl[0]-t.dx_cl[1]) * (t.dx_cl[0]-t.dx_cl[1]) + (t.dy_cl[0]-t.dy_cl[1]) * (t.dy_cl[0]-t.dy_cl[1])) : NOVAL_F;
#else
    dr_clu = t.d_cl;
    dr_cluclu = NOVAL_F;
#endif
    inactive = (t.validhit!=1&&t.missing!=1);
    clu_charge = 0;
    for (int i=0; i<t.clu.size; i++) clu_charge+=t.clu.adc[i];
    //std::cout<<t.clu.size<<" "<<t.clu.sizeX<<" "<<t.clu.sizeY<<std::endl;
    
    //________________________________________________________________________________________
    //                                    Event variables
    
    // Event
    newevt = (e.evt!=evt_lastevt_);
    // if (newevt) { // Do on every new event
    //   for (int i=1; i<19; i++) federr_type[i]=0;
    //   federr_type[1]=(e.federrs_size==0);
    //   federr_type[2]=(e.federrs_size!=0);
    //   for (int i=0; i<e.federrs_size; i++)
    //     federr_type[e.federrs[i][1]-22] = 1;
    // }
    evt_lastevt_=e.evt;
    
    // LumiSection
    newls = (evt_lastls_!=e.ls||e.run!=evt_lastrun_);
    evt_lastls_ = e.ls;
    
    // Run
    if (e.run!=evt_lastrun_) { 
      run_bin = 0;
      if ((run_index.count(e.run))) run_bin = run_index[e.run];
#ifdef EXPRESS
      load_roc_sel_(0, e.run, 2);
#endif
    }
    evt_lastrun_ = e.run;
    
    // Fill
    fill = filldef[e.run];
    
    //________________________________________________________________________________________
    //                                   Geometry variables
    
    // Online naming convention
    int LYR  = m.layer;
    int LDR  = abs(m.ladder);
    int MOD  = abs(m.module);
    int DSK  = abs(m.disk);
    int BLD  = abs(m.blade);
    int PNL  = m.panel;
    int RNG  = m.ring;
    int SEC  = m.sec;
    // Shell
    int shl = (m.det==0) ? 2 * (m.module<0) + (m.ladder<0)
      : 2 * (m.disk<0) + (m.blade<0);
    bool BpI = (shl==0);
    bool BpO = (shl==1);
    bool BmI = (shl==2);
    bool BmO = (shl==3);

    // Side-Disk-Panel number - similar to module_on.module
    sdp_x = ((m.disk>0) ? 1 : -1) * (2 * (DSK - 1) + m.panel);
    
    // Module number
    mod_index_x = ((m.det) ? sdp_x : m.module) + 4;
    mod_index_y = (m.det) ? ((m.blade>0) ? m.blade-1 : m.blade + 12)*4 +
      + m.module-1 : m.layer * 6 + 4 + m.ladder;
    mod_x = (m.det) ? sdp_x : m.module;
    mod_y = (m.det) ? m.blade : m.ladder;
    
    // ROC number
#if PHASE == 0
    roc = roc_(t.lx, t.ly, t.mod_on);
#else
    roc = m.roc;    
#endif
    
    // TBM side
    tbm = roc>7; // 0: TBM A, 1: TBM B

    // Module/ROC online format: BPix_BmI_SEC7_LYR1_LDR8F_MOD2_ROC0 / FPix_BmI_D1_BLD1_PNL2_PLQ2_ROC0
    // BPix - [Det][Shl][Sec][Lyr][Ldr][MOD][ROC] --> [Det-Shl][Sec-Lyr-Ldr][Mod-Roc] (gap on half modules)
    // FPix - [Det][Shl][Dsk][Bld][Pnl][PLQ][ROC] --> [Det_Shl][Dsk-Bld][Pnl-Plq-Roc] (no gap)
    p1_detshl = m.det*4 + shl;
    p1_rocid = p1_detshl;    

#if PHASE == 0
    p2_seclyrldr = (m.det==0) ? LDR-1 + (m.layer>1)*10 + (m.layer>2)*16 : NOVAL_I;
    //p3_modroc = (m.det==0) ? (roc!=NOVAL_I ? (MOD-1)*16 + roc : NOVAL_I) : NOVAL_I;
    p3_modroc = (m.det==0) ? (MOD-1)*16 + roc : NOVAL_I;
    p2_dskbld = (m.det==1) ? (DSK-1)*12 + BLD-1 : NOVAL_I;
    //p3_pnlplqroc = (m.det==1) ? (roc!=NOVAL_I ? ((m.panel==1) ? (m.module>1)*2 + (m.module>2)*6 + (m.module>3)*8
    //    					 : 21 + (m.module>1)*6 + (m.module>2)*8) + roc : NOVAL_I) : NOVAL_I;
    p3_pnlplqroc = (m.det==1) ? ((m.panel==1) ? (m.module>1)*2 + (m.module>2)*6 + (m.module>3)*8
				 : 21 + (m.module>1)*6 + (m.module>2)*8) + roc : NOVAL_I;
    p2_rocid = (m.det) ? p2_dskbld : p2_seclyrldr;
    p3_rocid = (m.det) ? p3_pnlplqroc : p3_modroc;
#else
    p2_seclyrldr = (m.det==0) ? LDR-1 + (m.layer>1)*6 + (m.layer>2)*14 + (m.layer>2)*22 : NOVAL_I;
    p3_modroc = (m.det==0) ? (MOD-1)*16 + roc : NOVAL_I;
    p2_dskbld = (m.det==1) ? (DSK-1)*28 + BLD-1 + (m.ring>1)*11 : NOVAL_I;
    p3_pnlroc = (m.det==1) ? (m.panel==2)*16 + roc : NOVAL_I;
    p2_rocid = (m.det) ? p2_dskbld : p2_seclyrldr;
    p3_rocid = (m.det) ? p3_pnlroc : p3_modroc;
#endif

    rocid = p1_rocid * 10000 + p2_rocid*100 + p3_rocid;
    p1_modid = p1_rocid;
    p2_modid = p2_rocid;
#if PHASE == 0
    p3_modid = (m.det==0) ? MOD-1 : m.module-1 + (m.panel>1)*4;
#else
    p3_modid = (m.det==0) ? MOD-1 : (m.panel>1);
#endif
    
    // Roc BinX number for ROC map plots (traj branch)
    roc_binx = NOVAL_I;
    if (m.det==0) {
      roc_binx = (fabs(t.ly)<3.24) ? (int)((m.module+4)*8 - t.ly / 0.81 + 5)  : NOVAL_I;
    } else if (m.det==1) {
      // Roc is left (0) or right (1) on the ROC map plot (+Z side)
      int binselx = (m.panel==1&&(m.module==1||m.module==4)) ?
        ((fabs(t.lx)<0.4082) ? (m.module==1) : NOVAL_I ) 
        : ((fabs(t.lx)<0.8164) ? ((m.panel==1&&t.lx<0.0)||(m.panel==2&&t.lx>=0.0)) : NOVAL_I);
      // Gives the Roc location inside a panel (0 to 5 on +Z side)
      int nperpan = 2 * m.module + m.panel - 1 + binselx;
      roc_binx = (binselx!=NOVAL_I) ? ((m.disk>0) ? nperpan : 9 - nperpan) + (sdp_x + 4) * 8 
        - 2 * ((DSK==1) ? m.disk : 0) : NOVAL_I;
    }
    // Roc BinY number for ROC map plots (traj branch)
    roc_biny = NOVAL_I;
    if (m.det==0) {
      if ((m.half==0&&fabs(t.lx)<0.8164)||(m.half==1&&fabs(t.lx)<0.4082)) {
        // Roc is in bottom (0) or top bin (1) inside a ladder on th ROC map plot
        int binsely = ((m.half==1&&((m.ladder<0&&m.ladder%2==0)||m.ladder%2==1))
		       ||(m.half==0&&((m.ladder<0 &&((m.ladder%2==-1&&t.lx<0.0)
								   ||(m.ladder%2==0&&t.lx>0.0)))
					     ||(m.ladder>0 &&((m.ladder%2==0&&t.lx<0.0)
								     ||(m.ladder%2==1&&t.lx>0.0))))));
	roc_biny = (m.layer * 6 + m.ladder + 4) * 2 + 1 + binsely;
      }
    } else if (m.det==1) {
      // Gives the number of ROCs along ly
      int nrocly = m.module + m.panel;
      if (fabs(t.ly)<(nrocly*0.405)) {
	int rocy = (int)((t.ly+(nrocly%2)*0.405)/0.81+nrocly/2);
	roc_biny = 7 - nrocly + 2 * ((m.disk<0) ? rocy : nrocly - 1 - rocy) 
	  + (m.blade-1 + (m.blade<0)*13)*12;
      }
    }
    roc_ladder = (m.det==0) ? (roc_biny==NOVAL_I ? NOVAL_I : (roc_biny-1.5)/2.0 - (m.layer*6+4) ) : NOVAL_I;
    roc_module = (m.det==0) ? (roc_binx==NOVAL_I ? NOVAL_I : (roc_binx-36.5)/8.0) : NOVAL_I;
    roc_blade = (m.det==1) ? (roc_biny==NOVAL_I ? NOVAL_I : (roc_biny+m.module+m.panel-7)/12.0 - (m.blade<0)*13 + 0.54167) : NOVAL_I;
    roc_sdp = (m.det==1) ? (roc_binx==NOVAL_I ? NOVAL_I : (roc_binx-36.5)/8.0) : NOVAL_I;
    
    roc_new_binx = (m.det==0) ? (roc_binx==NOVAL_I ? NOVAL_I : roc_binx - (roc_binx>32)*8 ) : 
      roc + 1 + (m.panel==2&&m.module==1)*2 + (m.panel==1&&m.module==2)*8
      + (m.panel==2&&m.module==2)*14 + (m.panel==1&&m.module==3)*22
      + (m.panel==2&&m.module==3)*30 + (m.panel==1&&m.module==4)*40;
    roc_new_biny = (m.det==0) ? (roc_biny==NOVAL_I ? NOVAL_I : roc_biny - (roc_biny>=m.layer*12+8)*4 - 1 ) : m.blade+13-(m.blade>0);
    rocbin_x = roc_new_binx;
    rocbin_y = roc_new_biny;
    
    // Incidence angles in degrees, defined 0-90 deg (0 deg: perpendicular to module plane, 90 deg: parallel)
    phi = atan2(tan(t.beta),tan(t.alpha));
    theta = atan(sqrt(1.0/(  1.0/(  tan(t.alpha)*tan(t.alpha)) + 1.0/(tan(t.beta)*tan(t.beta))  ) ) );
    angle_alpha = fabs(90.0 - fabs(t.alpha) / 3.14159265 * 180);
    angle_beta  = fabs(90.0 - fabs(t.beta)  / 3.14159265 * 180);
    angle_incidence = 90.0 - theta / 3.14159265 * 180.0; // or angle_theta
    //year = (e.run<=149711) ? 1 : (e.run<=180296) ? 2 : 3;
    
    //=========================================================================================
    //                                    Efficiency Cuts
    //=========================================================================================
    //__________________________________________________________________________________________
    //                                    Event Selections
    
    // Moved here:
    postfixes_cuts_(e,t);
    
    //__________________________________________________________________________________________
    //                                    Track Selections
    
    // Track quality bit: HighPurity track
    hp = (t.trk.quality&4)!=0;
    
    // Hit originates from track with Pt > 2.0 GeV
    // Previous pt cuts:
    // BPix - 1.0 GeV
    // 0.6 GeV
    pt = t.trk.pt>2.0; // increased from 1.0
    bool pt_dcol = t.trk.pt>0.6;
    pt_new = t.trk.pt>=2.0;

    // Number of hits in the Silicon Strip Tracker > 10
    nstrip = t.trk.strip>10;
    
    //bool nstrip_loose = t.trk.strip>6;
    bool nstrip_vloose = t.trk.strip>=8;

    bool trk_beta_cut = std::abs(3.1416/2 - std::abs(t.beta))<0.8;
    
    // Track Impact parameters (track to vertex D0/Z distance)
    //d0 = m.det==0 ?
    //  (m.layer==1 ? fabs(t.trk.d0)<0.01 // L1
    //   : fabs(t.trk.d0)<0.02 ) // L2,3(,4)
    //  : m.det==1 && fabs(t.trk.d0)<0.05; // FPix
    
    d0 = std::abs(t.trk.d0) < 0.002;
    //d0_new = std::abs(t.trk.d0)<0.2;
    d0_new = m.det==0 ? std::abs(t.trk.d0)<0.05 : std::abs(t.trk.d0)<0.2;
    
    //dz = (m.det==0 && fabs(t.trk.dz)<0.1) 
    //  ||(m.det==1 && fabs(t.trk.dz)<0.5);
    dz = std::abs(t.trk.dz) < 0.01;
    //dz_new = sm.det==0 ? std::abs(t.trk.dz)<0.1 : std::abs(t.trk.dz)<0.5;
    dz_new = std::abs(t.trk.dz)<0.5;

    //bool d0_loose = m.det==0 ?
    //  (m.layer==1 ? fabs(t.trk.d0)<0.1 // L1
    //   : fabs(t.trk.d0)<0.3 ) // L2,3
    //  : m.det==1 && fabs(t.trk.d0)<0.5; // FPix
    //
    //bool dz_loose = (m.layer==1 && t.trk.dz>0.2&&t.trk.dz<1) 
    //  ||((m.layer==2||m.layer==3)&&fabs(t.trk.dz)<0.8)
    //  ||(m.det==1 && fabs(t.trk.dz)<3);

    bool d0_vloose = m.det==0 ? fabs(t.trk.d0)<0.5 : fabs(t.trk.d0)<0.4;
    bool dz_vloose = (m.det==0 && fabs(t.trk.dz)<2) 
      ||(m.det==1 && fabs(t.trk.dz)<0.6);

    bool d0_dcol = std::abs(t.trk.d0)<0.02;
    bool dz_dcol = std::abs(t.trk.dz)<0.02;

    // Require 2 Valid hit on 2 other layer(s) and/or disk(s)
#if PHASE == 0
    pixhit = m.det==0 ?
      ( // BPix
       m.layer==1 ?
       (t.trk.validbpix[1]>0 && t.trk.validbpix[2]>0) // L2 + L3
       || (t.trk.validbpix[1]>0 && t.trk.validfpix[0]>0) // L2 + D1
       || (t.trk.validfpix[0]>0 && t.trk.validfpix[1]>0) // D1 + D2
       : m.layer==2 ?
       (t.trk.validbpix[0]>0 && t.trk.validbpix[2]>0) // L1 + L3
       || (t.trk.validbpix[0]>0 && t.trk.validfpix[0]>0) // L1 + D1
       : m.layer==3 &&
       t.trk.validbpix[0]>0 && t.trk.validbpix[1]>0 ) // L1 + L2
      : m.det==1 &&
      ( // FPix
       DSK==1 ?
       (t.trk.validbpix[0]>0 && t.trk.validfpix[1]>0) // L1 + D2
       || (t.trk.validbpix[1]>0 && t.trk.validfpix[1]>0) // or L2 + D2
       : DSK==2 &&
       t.trk.validbpix[0]>0 && t.trk.validfpix[0]>0 ); // L1 + D1
#else
    pixhit = m.det==0 ?
      ( // BPix
       m.layer==1 ?
       (   t.trk.validbpix[1]>0 && t.trk.validbpix[2]>0 && t.trk.validbpix[3]>0) // L2 + L3 + L4
       || (t.trk.validbpix[1]>0 && t.trk.validbpix[2]>0 && t.trk.validfpix[0]>0) // L2 + L3 + D1
       || (t.trk.validbpix[1]>0 && t.trk.validfpix[0]>0 && t.trk.validfpix[1]>0) // L2 + D1 + D2
       || (t.trk.validfpix[0]>0 && t.trk.validfpix[1]>0 && t.trk.validfpix[2]>0) // D1 + D2 + D3
       : m.layer==2 ?
       (   t.trk.validbpix[0]>0 && t.trk.validbpix[2]>0 && t.trk.validbpix[3]>0) // L1 + L3 + L4
       || (t.trk.validbpix[0]>0 && t.trk.validbpix[2]>0 && t.trk.validfpix[0]>0) // L1 + L3 + D1
       || (t.trk.validbpix[0]>0 && t.trk.validfpix[0]>0 && t.trk.validfpix[1]>0) // L1 + D1 + D2
       : m.layer==3 ?
       (   t.trk.validbpix[0]>0 && t.trk.validbpix[1]>0 && t.trk.validbpix[3]>0) // L1 + L2 + L4
       || (t.trk.validbpix[0]>0 && t.trk.validbpix[1]>0 && t.trk.validfpix[0]>0) // L1 + L2 + D1
       : m.layer==4
       &&  t.trk.validbpix[0]>0 && t.trk.validbpix[1]>0 && t.trk.validbpix[2]>0) // L1 + L2 + L3
      : m.det==1 &&
      ( // FPix
       DSK==1 ?
       (   t.trk.validbpix[0]>0 && t.trk.validbpix[1]>0 && t.trk.validbpix[2]>0) // L1 + L2 + L3
       || (t.trk.validbpix[0]>0 && t.trk.validbpix[1]>0 && t.trk.validfpix[1]>0) // L1 + L2 + D2
       || (t.trk.validbpix[0]>0 && t.trk.validfpix[1]>0 && t.trk.validfpix[2]>0) // L1 + D2 + D3
       : DSK==2 ?
       (   t.trk.validbpix[0]>0 && t.trk.validbpix[1]>0 && t.trk.validfpix[0]>0) // L1 + L2 + D1
       || (t.trk.validbpix[0]>0 && t.trk.validfpix[0]>0 && t.trk.validfpix[2]>0) // L1 + D1 + D3
       : DSK==3
       &&  t.trk.validbpix[0]>0 && t.trk.validfpix[0]>0 && t.trk.validfpix[1]>0);// L1 + D1 + D2
#endif
    bool val_pixhit = (t.trk.validpixhit[0]+t.trk.validpixhit[1])>=4;
    
    bool alpha = std::abs(3.1416/2 - std::abs(t.alpha))<0.2;
    bool beta  = std::abs(3.1416/2 - std::abs(t.beta))>=0.35 && std::abs(3.1416/2 - std::abs(t.beta))<0.55;

    //__________________________________________________________________________________________
    //                                 Bad Module/ROC Exclusions
    
    // Exclude Modules affected by Timing and HV Scans
    bool excl_hv = (pf_hv_scan == -1);
    bool excl_delay = ( pf_delay_scan == -1 ||
			(e.run==272762 && delay==24 ) ||
			(e.run<238474 && delay==13) || 
			(e.run>=295371 && delay==6) )
      // One Module scanned (WBC scan)
      && !((e.run==161310||e.run==161311) && m.layer==2&&m.ladder==-5&&m.module==2);
    
    noscan = excl_hv && excl_delay;
    
    // Exclude some known bad modules
    bool goodmod_RunI = 
      m.det==0 ?
      ( // BPix
       m.layer==1 ?
       !(m.ladder==  4 && m.module==-4 && t.lx>0.0)
       : m.layer==2 ?
       !(m.ladder== -8 && m.module== 1 && t.lx>0.0) &&
       !(m.ladder==-13 && m.module== 3 && t.lx<0.0)
       : m.layer==3 && 
       !(m.ladder==14&&m.module==-4&&e.run>=141956&&e.run<160404) &&
       !(e.run>=162713&&( (m.ladder== 13 &&(m.module==-1 || m.module==-2 || m.module==-3)) ||
                          (m.ladder== 12 &&(m.module==-1 || m.module==-2)) ||
                          (m.ladder==-17 && m.module==-3) ) ) )
      : m.det==1 &&
      ( // FPix
       m.disk==-2 ?
       !(m.blade==10 && m.panel==1)
       : m.disk==-1 ?
       !(m.blade==6  && m.panel==1)
       : m.disk==1 ?
       !(e.run==146644&&( m.blade==-1 || m.blade==-2 || m.blade==-3)) && // Whole ROG out
       !(e.run>=163655&&  m.blade==-5 && m.panel==2 && m.module==2 ) // 4x2 PLQ problem
       : m.disk==2 &&
       !(e.run>=147752&&( m.blade== 4 || m.blade== 5 || m.blade== 6)))
      // Exclude Disk1 1x2 and 2x3 modules from measurement due to bad eta coverage
      && !(DSK==1&&(m.panel+m.module)<4);
    
    bool goodmod_RunII_phase0 = 
      m.det==0 ? 
      // Large parts (sectors)
      !(m.layer<3&&m.module<0&&m.ladder<0&&sector==3&&e.run>=250989) && // BmO SEC3 (L1+2 is off, but L3 also excluded) - problem appeared in 3.8T
      !(m.layer>0&&m.module<0&&m.ladder<0&&sector==7&&e.run>=250989&&e.run<=251134) && // FED 30 (BmO SEC7) out for the duration of the Fine delay scan
      // Layer 1 modules
      //!(m.layer==1&&m.module==3&&m.ladder==-10) &&       // FED  8 Ch   12 - SOLVED
      !(m.layer==1&&m.module==2&&m.ladder==-3&&tbm==0) &&  // FED  6 Ch    5 - Missing ROC header (firmware update)
      // Layer 2 modules
      //!(m.layer==2&&m.module==4&&m.ladder==-14) &&       // FED  9 Ch 4,12 - SOLVED
      !(m.layer==2&&m.module==3&&m.ladder==-13&&tbm==1) && // FED  9 Ch   15 - Too many out-of-syncs (rerouting)
      !(m.layer==2&&m.module==-1&&m.ladder==2&&tbm==1) &&  // FED 23 Ch   19 - Too many out-of-syncs, 6th address level (rerouting)
      !(m.layer==2&&m.module==-1&&m.ladder==1) &&          // FED 23 Ch   20 - Missing ROC header (firmware update)
      !(m.layer==2&&m.module==4&&m.ladder==-1) &&          // FED  7 Ch   20 - No HV
      !(m.layer==2&&m.module==4&&m.ladder==-16) &&         // FED  8 Ch    5 - No HV
      !(m.layer==2&&m.module==1&&m.ladder==-5&&tbm==1) &&  // FED  5 Ch    9 - Unstable amplitude (rerouting)
      !(m.layer==2&&m.module==3&&m.ladder==-3&&tbm==1) &&  // FED  6 Ch    2 - Unstable amplitude (rerouting)
      // Layer 3 modules
      //!(m.layer==3&&m.module==2&&m.ladder==-19) &&       // FED  9 Ch   36 - SOLVED
      !(m.layer==3&&m.module==1&&m.ladder==3)              // FED  0 Ch   33 - Missing ROC header (firmware update)
      : // FPix - Exclude Disk1 1x2 and 2x3 modules from measurement due to bad eta coverage
      !(DSK==1&&(m.panel+m.module)<4);

    bool goodmod_RunII_phase1 =
      m.det==0 ? 
      ( LYR==1 ?
	!(BmI && LDR== 4 && MOD==2 && m.roc>=12) &&
	!(BmO && LDR== 4 && MOD==2 && m.roc>= 8 && m.roc<12) &&
	!(BpI && LDR== 1 && MOD==4 && m.roc>=12) &&
	!(BpI && LDR== 2 && MOD==1) &&
	!(BpO && LDR== 5 && MOD==4 && m.roc>=12) :
	LYR==2 ?
	!(BmI && LDR== 1 && MOD==4 && m.roc< 8) &&
	!(BmI && LDR== 3 && MOD==3 && m.roc< 8) &&
	!(BmI && LDR== 4 && MOD==1 && m.roc>=8) &&
	!(BmI && LDR== 7 && MOD==1) &&
	!(BmI && LDR== 7 && MOD==2 && m.roc< 8) &&
	!(BmO && LDR== 2 && MOD==1) &&
	!(BmO && LDR== 9 && MOD==2 && m.roc< 8) &&
	!(BpI && LDR== 2 && MOD==2 && m.roc>=8) &&
	!(BpI && LDR==14 && MOD==1 && m.roc>=8) &&
	!(BpI && LDR==14 && MOD==2 && m.roc< 8) &&
	!(BpI && SEC==5) &&
	!(BpO && LDR==  1 && MOD==1) :
	LYR==3 ?
	!(BmI && LDR==18 && MOD==2) &&
	!(BmI && LDR==20 && MOD==2) &&
	!(BpI && LDR== 9 && MOD==2) &&
	!(BpI && LDR==19 && MOD==4 && m.roc< 8) &&
	!(BpO && LDR== 3 && MOD==2 && m.roc>=8) :
	LYR==4 &&
	!(BmI && LDR== 2 && MOD==2) &&
	!(BmI && LDR== 6 && MOD==4 && m.roc< 8) &&
	!(BmI && LDR==10 && MOD==2) &&
	!(BmI && LDR==24 && MOD==1 && m.roc< 8) &&
	!(BmI && LDR==19 && MOD==3 && (m.roc<4||m.roc>=12)) &&
	!(BpI && LDR==10 && MOD==3) &&
	!(BpI && LDR==14 && MOD==2 && m.roc< 8) &&
	!(BpI && LDR==32 && MOD==2) &&
	!(BpO && LDR==32 && MOD==2 && m.roc>=8) &&
	!(BpO && LDR==18 && MOD==2 && m.roc>=8) ) :
      ( DSK==1 ? 	
	!(BpI && BLD==11 && PNL==1 && RNG==1 && m.roc==2) &&
	!(BpO && BLD==10 && PNL==1 && RNG==1) &&
	!(BpO && BLD==13 && PNL==1 && RNG==2 && m.roc< 8) &&
	!(BpI && BLD==11 && PNL==1 && RNG==1 && m.roc==2) :
	DSK==2 ? 
	!(BmI && BLD== 1 && PNL==1 && RNG==1 && m.roc>=8) &&
	!(BmI && BLD== 6 && PNL==1 && RNG==2 && m.roc>=8) &&
	!(BpI && BLD== 1 && PNL==2 && RNG==1 && m.roc< 8) &&
	!(BpI && BLD==11 && PNL==1 && RNG==1 && m.roc==2) :
	DSK==3 &&
	!(BmI && BLD== 5 && PNL==2 && RNG==1 && m.roc< 8) &&
	!(BpI && BLD== 9 && PNL==1 && RNG==2 && m.roc< 8) &&
	!(BpI && BLD==11 && PNL==1 && RNG==1 && m.roc==2) );

    bool goodmod_RunIII_phase1 = m.det==0 ? 
      ( LYR==2 ?
	!(BmI && LDR== 1 && MOD==4 && m.roc< 8) &&
	!(BmI && LDR== 3 && MOD==3 && m.roc< 8) &&
	!(BmI && LDR== 4 && MOD==1 && m.roc>=8) &&
	!(BmI && LDR== 7 && MOD==1) &&
	!(BmI && LDR== 7 && MOD==2 && m.roc< 8) &&
	!(BmO && LDR== 2 && MOD==1) &&
	!(BmO && LDR== 9 && MOD==2 && m.roc< 8) &&
	!(BpI && LDR== 2 && MOD==2 && m.roc>=8) &&
	!(BpI && LDR==14 && MOD==1 && m.roc>=8) &&
	!(BpI && LDR==14 && MOD==2 && m.roc< 8) &&
	!(BpI && SEC==5) &&
	!(BpO && LDR==  1 && MOD==1) :
	LYR==3 ?
	!(BmI && LDR==18 && MOD==2) &&
	!(BmI && LDR==20 && MOD==2) &&
	!(BpI && LDR== 9 && MOD==2) &&
	!(BpI && LDR==19 && MOD==4 && m.roc< 8) &&
	!(BpO && LDR== 3 && MOD==2 && m.roc>=8) :
	LYR==4 &&
	!(BmI && LDR== 2 && MOD==2) &&
	!(BmI && LDR== 6 && MOD==4 && m.roc< 8) &&
	!(BmI && LDR==10 && MOD==2) &&
	!(BmI && LDR==24 && MOD==1 && m.roc< 8) &&
	!(BmI && LDR==19 && MOD==3 && (m.roc<4||m.roc>=12)) &&
	!(BpI && LDR==10 && MOD==3) &&
	!(BpI && LDR==14 && MOD==2 && m.roc< 8) &&
	!(BpI && LDR==32 && MOD==2) &&
	!(BpO && LDR==32 && MOD==2 && m.roc>=8) &&
	!(BpO && LDR==18 && MOD==2 && m.roc>=8) ) :
      ( DSK==1 ? 	
	!(BpI && BLD==11 && PNL==1 && RNG==1 && m.roc==2) &&
	!(BpO && BLD==10 && PNL==1 && RNG==1) &&
	!(BpO && BLD==13 && PNL==1 && RNG==2 && m.roc< 8) &&
	!(BpI && BLD==11 && PNL==1 && RNG==1 && m.roc==2) :
	DSK==2 ? 
	!(BmI && BLD== 1 && PNL==1 && RNG==1 && m.roc>=8) &&
	!(BmI && BLD== 6 && PNL==1 && RNG==2 && m.roc>=8) &&
	!(BpI && BLD== 1 && PNL==2 && RNG==1 && m.roc< 8) &&
	!(BpI && BLD==11 && PNL==1 && RNG==1 && m.roc==2) :
	DSK==3 &&
	!(BmI && BLD== 5 && PNL==2 && RNG==1 && m.roc< 8) &&
	!(BpI && BLD== 9 && PNL==1 && RNG==2 && m.roc< 8) &&
	!(BpI && BLD==11 && PNL==1 && RNG==1 && m.roc==2) );
    
    goodmod = (e.run==1) ? 1 : e.run<238474 ? goodmod_RunI : e.run<285000 ? goodmod_RunII_phase0 : e.run<355095 ? goodmod_RunII_phase1 : goodmod_RunIII_phase1;
    
    // Good roc selecton
    goodroc = (e.run==1) ? 1: goodroc_list[p1_rocid][p2_rocid][p3_rocid];
    
    //__________________________________________________________________________________________
    //                          Module/ROC Fiducial Region Selections:
    //                       Cut on the local coordinates of a hit LX/LY
    //             Exclude Module/ROC edges and regions where nearby modules overlap
    
#if PHASE == 0
    // Module Edge Cut - LX
    bool edge_lx = m.det==0 ? 
      ( // BPix
       m.half==0 ? fabs(t.lx)<0.65
       : m.half==1 && t.lx>-0.3 && t.lx<0.25 )
      : m.det==1 &&
      ( // FPix
       m.panel==1 ?
       ( // Panel 1
	m.module== 1 ? t.lx>-0.15 && t.lx<0.3
	: m.module==2 ? (DSK==1  ? t.lx>-0.55 && t.lx<0.6 :
				 DSK==2 && t.lx>-0.6 && t.lx<0.3)
	: m.module==3 ? (DSK==1  ? t.lx> 0.3 && t.lx<0.6 :
				 DSK==2 && t.lx>-0.6 && t.lx<0.5)
	: m.module==4 && t.lx>-0.3 && t.lx<0.15 )
       : m.panel==2 &&
       ( // Panel 2
	m.module==1 ? t.lx>-0.55 && t.lx<0.6
	: m.module==2 ? (DSK==1  ? fabs(t.lx)<0.55 :
				 DSK==2 && t.lx>-0.6 && t.lx<0.55)
	: m.module==3 && fabs(t.lx)<0.55) );
    
    // ROC Edge cut - LX
    bool rocedge_lx = !((m.half==0||(m.det==1&&!(m.panel==1&&(m.module==1||m.module==4))))
			&& fabs(t.lx)<0.06);
#else
    // Module Edge Cut - LX
    bool edge_lx = m.det==0 ? fabs(t.lx)<0.65 : fabs(t.lx)<0.65 && fabs(t.lx)<(0.81+(t.ly-3.24)/8*0.85);
    
    // ROC Edge cut - LX
    bool rocedge_lx = fabs(t.lx)>=0.06;
#endif
    lx_fid = edge_lx && rocedge_lx;
    
    
#if PHASE == 0
  // Module Edge Cut - LY
  bool edge_ly = m.det==0 ? fabs(t.ly)<3.1 :
      : m.det==1 &&
      ( // FPix
       m.panel==1 ?
       ( // Panel 1
	m.module==1 ? fabs(t.ly)<0.7
	: m.module==2 ? fabs(t.ly)<1.1 
	&& !(m.disk==-1 && t.lx>0.25 && t.ly> 0.75)
	&& !(m.disk== 1 && t.lx>0.25 && t.ly<-0.75)
	: m.module==3 ? fabs(t.ly)<1.5
	&& !(m.disk==-1 && t.ly > 1.1)
	&& !(m.disk== 1 && t.ly <-1.0)
	&& !(m.disk==-2 && t.lx>0.15 && t.ly> 1.1)
	&& !(m.disk== 2 && t.lx>0.15 && t.ly<-1.1)
	: m.module==4 && fabs(t.ly)<1.9
	&& !(m.disk==-2 && t.ly> 1.5)
	&& !(m.disk== 2 && t.ly<-1.5) )
       : m.panel==2 &&
       ( // Panel 2
	m.module==1 ? fabs(t.ly)<0.7
	: m.module==2 ? fabs(t.ly)<1.1
	: m.module==3 && fabs(t.ly)<1.6
	&& !(m.disk>0 && t.ly>1.5)
	&& !(m.disk<0 && t.ly<-1.5) ) );
    
    // ROC Edge cut - LY
    float ly_mod = fabs(t.ly) + (m.det==1&&(m.panel+m.module)%2==1)*0.405;
    float d_rocedge = fabs(fabs(fmod(ly_mod,0.81)-0.405)-0.405);
    bool rocedge_ly = d_rocedge >= 0.06;
#else
    // Module Edge Cut - LY
    bool edge_ly = fabs(t.ly)<3.1;

    // ROC Edge cut - LY
    float d_rocedge = fabs(fabs(fmod(fabs(t.ly),0.81)-0.405)-0.405);
    bool rocedge_ly = d_rocedge >= 0.06;
#endif

    ly_fid = edge_ly && rocedge_ly;
    
    //__________________________________________________________________________________________
    //                            Efficiency Related Selections
    
    // Valid or Missing hit (not Inactive, Invalid or Bad)
    // Previous: ( ( m.layer==1&&t.lxmatch!=NOVAL_F ||m.layer!=1 ) 
    //             &&t.validhit==1 ) || t.missing==1
    valmis = t.validhit==1||t.missing==1;
    
#if TREEREADER_VER > 100
    // Nearest other hit (on-track) is far away (D_hit > 0.5 cm)
    //hitsep = sqrt(t.dx_tr*t.dx_tr + t.dy_tr*t.dy_tr)>0.5;
    hitsep     = t.d_tr>=1.2 && t.dr_trk>=0.15;
    hitsep_new = t.dr_trk>=0.1;
#elif TREEREADER_VER >= 29
    // Nearest other hit is far away (D_hit > 0.5 cm)
    hitsep = t.hit_near==0;
#else
    // Nearest other hit is far away (D_hit > 0.5 cm)
    hitsep = t.dx_hit==NOVAL_F||sqrt(t.dx_hit*t.dx_hit+t.dy_hit*t.dy_hit)>0.5; 
#endif
    
    // Cuts for dcol efficiency
    // Size 2 clusters with big pixels near ROC edges excluded
    dcol_clu_cuts = 0;
    if (t.clu.size==2&&t.clu.sizeY==2) {
      if (((int)t.clu.pix[0][1])%52<50||((int)t.clu.pix[0][1])%52>1) {
	dcol_clu_cuts = 1;
      }
    }
    //pix[][1]%52>1&&pix[][1]%52<50&&size==2&&sizeY==2&&abs(3.1416/2 - abs(alpha))<0.3&&abs(3.1416/2 - abs(beta))>=0.35&&abs(3.1416/2 - abs(beta))<0.55&&pt>1&&validpixhit[0]>3&&abs(dz)<0.1&&abs(d0)<0.02&&layer==1
    
    // Note:
    // noscan - can stay, but Good-LS JSON takes care of this, needto update for fresh data if modules fail
    // goodmod - should update in Run II, remove repaired modules, add new failing modules (but ReReco will take care of this)
    // goodroc - have to analyse fill efficiencies to remove SEU-s, until the SEU-s are dealt with during tracking
    
    //                   zb,   nvtx,       federr,       hp,   pt,   nstrip,   d0,   dz,   pixhit,   noscan,   goodmod,   goodroc,   lx_fid,   ly_fid,   valmis,   hitsep
    effcut_all         =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_allmod      =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 && dz && pixhit                                 && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_trig        =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_nvtx        =                   cut_federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_federr      =       cut_nvtx &&               hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_pt          =       cut_nvtx && cut_federr && hp &&       nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_nstrip      =       cut_nvtx && cut_federr && hp && pt &&           d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_d0          =       cut_nvtx && cut_federr && hp && pt && nstrip &&       dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_dz          =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 &&       pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_d0_dz       =       cut_nvtx && cut_federr && hp && pt && nstrip &&             pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_scans       =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 && dz && pixhit           && goodmod            && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_scans_loose =                   cut_federr && hp && pt && nstrip &&                                goodmod             && lx_fid && ly_fid && valmis && hitsep && trk_beta_cut; // looser cuts to track selection to be used in case there are missing points in the timing scan as a cross check
    effcut_startup     =       cut_nvtx && cut_federr && hp && pt && nstrip_vloose && d0_vloose && dz_vloose && pixhit &&            lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_raw         =       cut_nvtx &&               hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod &&            lx_fid && ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_lx_fid      =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc &&           ly_fid && valmis && hitsep && trk_beta_cut;
    effcut_ly_fid      =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid &&           valmis && hitsep && trk_beta_cut;
    effcut_lxly_fid    =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc &&                     valmis && hitsep && trk_beta_cut;
    effcut_hitsep      =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis           && trk_beta_cut;
    effcut_beta        =       cut_nvtx && cut_federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep;

    dcol_effcut_all    =       cut_nvtx && val_pixhit && hp && pt_dcol && d0_dcol && dz_dcol &&      noscan && goodmod && goodroc && alpha && beta && dcol_clu_cuts;
    dcol_effcut_valpix =       cut_nvtx &&               hp && pt_dcol && d0_dcol && dz_dcol &&      noscan && goodmod && goodroc && alpha && beta && dcol_clu_cuts;
    dcol_effcut_pt     =       cut_nvtx && val_pixhit && hp &&            d0_dcol && dz_dcol &&      noscan && goodmod && goodroc && alpha && beta && dcol_clu_cuts;
    dcol_effcut_d0     =       cut_nvtx && val_pixhit && hp && pt_dcol &&            dz_dcol &&      noscan && goodmod && goodroc && alpha && beta && dcol_clu_cuts;
    dcol_effcut_dz     =       cut_nvtx && val_pixhit && hp && pt_dcol && d0_dcol &&                 noscan && goodmod && goodroc && alpha && beta && dcol_clu_cuts;
    dcol_effcut_alpha  =       cut_nvtx && val_pixhit && hp && pt_dcol && d0_dcol && dz_dcol &&      noscan && goodmod && goodroc &&          beta && dcol_clu_cuts;
    dcol_effcut_beta   =       cut_nvtx && val_pixhit && hp && pt_dcol && d0_dcol && dz_dcol &&      noscan && goodmod && goodroc && alpha &&         dcol_clu_cuts;
    dcol_effcut_scans  =       cut_nvtx && val_pixhit && hp && pt_dcol && d0_dcol && dz_dcol &&                goodmod &&            alpha && beta && dcol_clu_cuts;
    dcol_effcut_allmod =       cut_nvtx && val_pixhit && hp && pt_dcol && d0_dcol && dz_dcol &&                                      alpha && beta && dcol_clu_cuts;

#if DATASTRUCT_VER >= 108
    new_effcut_presel = cut_nvtx && cut_federr && hp &&                                     pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis;
    new_effcut_all    = new_effcut_presel && pt_new && nstrip && d0_new && dz_new && t.trk.muon_id_tight>0 && t.trk.muon_iso_pf>0 && hitsep_new;
    new_effcut_pt     = new_effcut_presel &&           nstrip && d0_new && dz_new && t.trk.muon_id_tight>0 && t.trk.muon_iso_pf>0 && hitsep_new;
    new_effcut_nstrip = new_effcut_presel && pt_new &&           d0_new && dz_new && t.trk.muon_id_tight>0 && t.trk.muon_iso_pf>0 && hitsep_new;
    new_effcut_d0     = new_effcut_presel && pt_new && nstrip &&           dz_new && t.trk.muon_id_tight>0 && t.trk.muon_iso_pf>0 && hitsep_new;
    new_effcut_dz     = new_effcut_presel && pt_new && nstrip && d0_new &&           t.trk.muon_id_tight>0 && t.trk.muon_iso_pf>0 && hitsep_new;
    new_effcut_hitsep = new_effcut_presel && pt_new && nstrip && d0_new &&           t.trk.muon_id_tight>0 && t.trk.muon_iso_pf>0;
    new_effcut_muon   = new_effcut_presel && pt_new && nstrip && d0_new && dz_new &&                                                 hitsep_new;
#else
    new_effcut_presel = 0;
    new_effcut_all    = 0;
    new_effcut_pt     = 0;
    new_effcut_d0     = 0;
    new_effcut_dz     = 0;
    new_effcut_hitsep = 0;
    new_effcut_muon   = 0;
#endif

    //std::cout<<"nvtx="<<cut_nvtx<<" federr="<<cut_federr<<" hp="<<hp<<" pt="<<pt<<" nstrip="<<nstrip<<" d0="<<d0<<" dz="<<dz<<" pixhit="<<pixhit<<" noscan="<<noscan<<" goodmod="<<goodmod<<" goodroc="<<goodroc<<" lx_fid="<<lx_fid<<" ly_fid="<<ly_fid<<" valmis="<<valmis<<" hitsep="<<hitsep<<std::endl;
    //if (effcut_all!=t.pass_effcuts) std::cout<<"PHM: "<<effcut_all<<" Ntuple: "<<t.pass_effcuts<<" nvtx="<<cut_nvtx<<" federr="<<cut_federr<<" hp="<<hp<<" pt="<<pt<<" nstrip="<<nstrip<<" d0="<<d0<<" dz="<<dz<<" pixhit="<<pixhit<<" noscan="<<noscan<<" goodmod="<<goodmod<<" goodroc="<<goodroc<<" lx_fid="<<lx_fid<<" ly_fid="<<ly_fid<<" valmis="<<valmis<<" hitsep="<<hitsep<<" zb(off): "<<(e.trig >> 0 & 1)<<std::endl;
   
#if DATASTRUCT_VER > 29
    // Dcol Efficiency (Dynamic Inefficiency)
    // Warning!: This has to come after module variables (for offline_ladder)
    double pu_scale[3];
    //double instlumi_scalefactor = (pf_file_add==1) ? 222 : (pf_file_add==2) ? 262 : (pf_file_add==3) ? 523.9 : 0; // temp hack to fix 2/1.82 issue
    //double instlumi_scalefactor = (pf_file_add==1) ? 222 : (pf_file_add==2) ? 262 : (pf_file_add==3) ? 476.8 : 0;
    double instlumi_scalefactor = (pf_file_add==1) ? 222 : (pf_file_add==2) ? 244.2 : (pf_file_add==3) ? 244.2 : 0;
    for (size_t i=0; i<3; i++) {
      double instlumi_invubhz = (e.pileup-1) * instlumi_scalefactor;
      double instlumi_pow=1.;
      pu_scale[i] = 0;
      for  (size_t j=0; j<thePUEfficiency_BPix[i].size(); j++){
        pu_scale[i]+=instlumi_pow*thePUEfficiency_BPix[i][j];
        instlumi_pow*=instlumi_invubhz;
      }
    }
    //dcol_eff = (m.det) ? 0.999 : theLadderEfficiency_BPix[m.layer-1][offline_ladder-1]*theModuleEfficiency_BPix[m.layer-1][MOD-1]*pu_scale[m.layer-1];
    dcol_eff = (m.det) ? (((m.panel+m.module)<4) ? theInnerEfficiency_FPix*pu_scale[1] : theOuterEfficiency_FPix*pu_scale[2] ) : 
      theLadderEfficiency_BPix[m.layer-1][offline_ladder-1]*theModuleEfficiency_BPix[m.layer-1][MOD-1]*pu_scale[m.layer-1];
    dcol_eff = std::min(dcol_eff,1.0);
#else
    dcol_eff = NOVAL_F;
#endif
  }
  
  void load_clu_var(const EventData &cluevt, const Cluster &clust) {
    
    //__________________________________________________________________________________________
    //                                   Geometry variables
    
    // Shell
    int shl = (clust.mod_on.det==0) ? 2 * (clust.mod_on.module<0) + (clust.mod_on.ladder<0)
      : 2 * (clust.mod_on.disk<0) + (clust.mod_on.blade<0);
    
    // Roc Number
#if PHASE == 0
    int clust_roc = clu_roc_(clust.x, clust.y, clust.mod_on);
#else
    int clust_roc = clust.mod_on.roc;    
#endif

    int clu_p1_detshl = clust.mod_on.det*4 + shl;
    clu_p1_rocid = clu_p1_detshl;

#if PHASE == 0
    int clu_p2_seclyrldr = (clust.mod_on.det==0) ? abs(clust.mod_on.ladder)-1 + (clust.mod_on.layer>1)*10 + (clust.mod_on.layer>2)*16 : NOVAL_I;
    int clu_p3_modroc = (clust.mod_on.det==0) ? (abs(clust.mod_on.module)-1)*16 + clust_roc : NOVAL_I;
    int clu_p2_dskbld = (clust.mod_on.det==1) ? (abs(clust.mod_on.disk)-1)*12 + abs(clust.mod_on.blade)-1 : NOVAL_I;
    int clu_p3_pnlplqroc = (clust.mod_on.det==1) ? ((clust.mod_on.panel==1) ? (clust.mod_on.module>1)*2 + (clust.mod_on.module>2)*6 + (clust.mod_on.module>3)*8
						    : 21 + (clust.mod_on.module>1)*6 + (clust.mod_on.module>2)*8) + clust_roc : NOVAL_I;
    clu_p2_rocid = (clust.mod_on.det) ? clu_p2_dskbld : clu_p2_seclyrldr;
    clu_p3_rocid = (clust.mod_on.det) ? clu_p3_pnlplqroc : clu_p3_modroc;
#else
    int clu_p2_seclyrldr = (clust.mod_on.det==0) ? abs(clust.mod_on.ladder)-1 + (clust.mod_on.layer>1)*6 + (clust.mod_on.layer>2)*14 + (clust.mod_on.layer>2)*22 : NOVAL_I;
    int clu_p3_modroc = (clust.mod_on.det==0) ? (abs(clust.mod_on.module)-1)*16 + clust_roc : NOVAL_I;
    int clu_p2_dskbld = (clust.mod_on.det==1) ? (abs(clust.mod_on.disk)-1)*28 + abs(clust.mod_on.blade)-1 + (clust.mod_on.ring>1)*11 : NOVAL_I;
    int clu_p3_pnlroc = (clust.mod_on.det==1) ? (clust.mod_on.panel==2)*16 + clust_roc : NOVAL_I;
    clu_p2_rocid = (clust.mod_on.det) ? clu_p2_dskbld : clu_p2_seclyrldr;
    clu_p3_rocid = (clust.mod_on.det) ? clu_p3_pnlroc : clu_p3_modroc;
#endif

    
    //__________________________________________________________________________________________
    //                                        Other
    
    clu_fill = filldef[cluevt.run];
    if (clu_fill!=clu_lastfill_)
      clu_p1_fill = run_fill_index[clu_fill];
    clu_lastfill_ = clu_fill;
    // Detector and layer number
    clu_det_x = clust.mod_on.det + 1;
    // Side-Disk-Panel number - similar to module_on.module
    clu_sdp_x = ((clust.mod_on.disk>0) ? 1 : -1) * (2 * (abs(clust.mod_on.disk) - 1) + clust.mod_on.panel);
    // Module number
    clu_mod_indexx = ((clust.mod_on.det) ? clu_sdp_x : clust.mod_on.module) + 4;
    clu_mod_indexy = (clust.mod_on.det) ? ((clust.mod_on.blade>0) ? clust.mod_on.blade-1 : clust.mod_on.blade + 12)*4 +
      + clust.mod_on.module-1 : clust.mod_on.layer * 6 + 4 + clust.mod_on.ladder;
    // Select which histogram does the module/roc belong to
    clu_mod_p1 = (clust.mod_on.det) ? 3 : clust.mod_on.layer - 1;
    clu_roc_p1 = (clust.mod_on.det) ? ((clust.mod_on.blade>0) ? 3 : 4 ) : clust.mod_on.layer - 1;
    // Roc BinX number for ROC map plots (clust branch)
    clu_roc_binx = NOVAL_I;
    if (clust.mod_on.det==0) {
      for (int i=1;i<=8;i++) if (clust.y>=((8-i)*52.0)&&clust.y<((9-i)*52.0))
        clu_roc_binx = (clust.mod_on.module+4)*8 + i;
    } else if (clust.mod_on.det==1) {
      // Roc is left (0) or right (1) on the ROC map plot (+Z side)
      int binselx = (clust.mod_on.panel==1&&(clust.mod_on.module==1||clust.mod_on.module==4)) ? (clust.mod_on.module==1)
        : ((clust.mod_on.panel==1&&clust.x<80.0)||(clust.mod_on.panel==2&&clust.x>=80.0));
      // Gives the Roc location inside a panel (0 to 5 on +Z side)
      int nperpan = 2 * clust.mod_on.module + clust.mod_on.panel - 1 + binselx;
      clu_roc_binx = ((clust.mod_on.disk>0) ? nperpan : 9 - nperpan) + (clu_sdp_x + 4) * 8 
        - 2 * ((abs(clust.mod_on.disk)==1) ? clust.mod_on.disk : 0);
    }
    // Roc BinY number for ROC map plots (clust branch)
    clu_roc_biny = NOVAL_I; 
    if (clust.mod_on.det==0) {
      // Roc is in bottom (0) or top bin (1) inside a ladder on th ROC map plot

      //bool top_row = 0;
      //if (half_module) {
      //  if ((ladder<0&&ladder%2==0)||ladder%2==1) top_row = 1;
      //} else {
      //  if (ladder<0) {
      //    if (ladder%2==-1&&row<<80) top_row = 1;
      //    else if (ladder%2==0&&row>=80) rop_row = 1;
      //  } else if (ladder>0) {
      //    if (ladder%2==0&&row<80) top_row = 1;
      //    else if (ladder%2==1&&row>=80) top_row = 1;
      //  }
      //}

      int binsely = ((clust.mod_on.half==1&&((clust.mod_on.ladder<0&&clust.mod_on.ladder%2==0)||clust.mod_on.ladder%2==1))
      	       ||(clust.mod_on.half==0&&((clust.mod_on.ladder<0 &&((clust.mod_on.ladder%2==-1&&clust.x<80.0)
      								   ||(clust.mod_on.ladder%2==0&&clust.x>=80.0)))
      					 ||(clust.mod_on.ladder>0 &&((clust.mod_on.ladder%2==0&&clust.x<80.0)
      								     ||(clust.mod_on.ladder%2==1&&clust.x>=80.0))))));
      clu_roc_biny = (clust.mod_on.layer * 6 + clust.mod_on.ladder + 4) * 2 + 1 + binsely;
    } else if (clust.mod_on.det==1) {
      // Gives the number of ROCs along ly
      int nrocly = clust.mod_on.module + clust.mod_on.panel;
      for (int i=0; i<nrocly; i++) {
        // ROC number = nrocly - 1 - i for + LX and nrocly + i for -LX.
        int j = (clust.mod_on.disk<0) ? i : nrocly - 1 - i;
        if (clust.y>=(j*52.0)&&clust.y<((j+1)*52.0))
          clu_roc_biny = 6 - nrocly + 2 * i + ((clust.mod_on.blade>0) ? clust.mod_on.blade-1 : clust.mod_on.blade + 12)*12 + 1;
      }
    }
    clu_roc_new_binx = (clust.mod_on.det==0) ? (clu_roc_binx==NOVAL_I ? NOVAL_I : clu_roc_binx - (clu_roc_binx>32)*8 ) : 
      clust_roc + 1 + (clust.mod_on.panel==2&&clust.mod_on.module==1)*2 + (clust.mod_on.panel==1&&clust.mod_on.module==2)*8
      + (clust.mod_on.panel==2&&clust.mod_on.module==2)*14 + (clust.mod_on.panel==1&&clust.mod_on.module==3)*22
      + (clust.mod_on.panel==2&&clust.mod_on.module==3)*30 + (clust.mod_on.panel==1&&clust.mod_on.module==4)*40;
    clu_roc_new_biny = (clust.mod_on.det==0) ? (clu_roc_biny==NOVAL_I ? NOVAL_I : clu_roc_biny - (clu_roc_biny>=clust.mod_on.layer*12+8)*4 - 1 ) : 
      clust.mod_on.blade+13-(clust.mod_on.blade>0);
    rocbin_x = clu_roc_new_binx;
    rocbin_y = clu_roc_new_biny;
    
    roc_ladder = (clust.mod_on.det==0) ? (clu_roc_biny==NOVAL_I ? NOVAL_I : (clu_roc_biny-1.5)/2.0 - (clust.mod_on.layer*6+4) ) : NOVAL_I;
    roc_module = (clust.mod_on.det==0) ? (clu_roc_binx==NOVAL_I ? NOVAL_I : (clu_roc_binx-36.5)/8.0) : NOVAL_I;
    roc_blade = (clust.mod_on.det==1) ? (clu_roc_biny==NOVAL_I ? NOVAL_I : (clu_roc_biny+clust.mod_on.module + clust.mod_on.panel-7)/12.0 - (clust.mod_on.blade<0)*13 + 0.54167) : NOVAL_I;
    roc_sdp = (clust.mod_on.det==1) ? (clu_roc_binx==NOVAL_I ? NOVAL_I : (clu_roc_binx-36.5)/8.0) : NOVAL_I;
    
    // common variables
    clu_postfixes_cuts_(cluevt, clust);
  }

  void init() { init_(); }

  void count_runs_fills(const RunData& run) {
    // Count fills - now works for all version
    if (run.fill!=run_lastfill_&&run_fill_index.count(run.fill)==0) {
      run_nfill++;
      run_fill_index[run.fill] = run_nfill; // postfix index
      std::stringstream ss;
      if (run.fill==NOVAL_I) ss<<"_UNDEF";
      else ss<<"_"<<run.fill;
      str_fill.push_back(ss.str());
      std::string s = ss.str();
      s.erase(0,1);
      run_fillname[run.fill]=s;
      str_Fill.push_back(s);
      str_Fill2.push_back("Fill "+s);
    }
    run_lastfill_ = run.fill;
    // Count runs
    if (run.run!=run_lastrun_&&run_index.count(run.run)==0) {
      filldef[run.run] = run.fill;
      run_list.push_back(run.run);
      run_index[run.run] = run_list.size();
    }
    run_lastrun_ = run.run;
  }
  
  void count_runs_lumis(const LumiData &lumi) {
    int run_corr = (lumi.run==NOVAL_I) ? 1 : lumi.run;
    int ls_corr = (lumi.ls==NOVAL_I) ? 1 : lumi.ls;
    int fill = filldef[run_corr];
#if DATASTRUCT_VER >= 27
    if (lumi_firstrun.count(fill)==0) {
      lumi_firstrun[fill] = run_corr;
      lumi_fillstart[fill] = (unsigned int)(lumi.time - ls_corr*23.311);
    } else if (lumi_firstrun[fill]>run_corr) {
      lumi_firstrun[fill] = run_corr;
      lumi_fillstart[fill] = (unsigned int)(lumi.time - ls_corr*23.311);
    }
#else
    if (lumi_firstrun.count(fill)==0) lumi_firstrun[fill] = run_corr;
    else if (lumi_firstrun[fill]>run_corr) lumi_firstrun[fill] = run_corr;
#endif
  }
  
  void instlumi_preloop_(int run, int ls) {
    int Run = (run==NOVAL_I) ? 1 : run;
    int Ls = (ls==NOVAL_I) ? 1 : ls;
    unsigned long int runls = Run * 100000 + Ls;
    if (!runls_count.count(runls)) {
      double instlumi = fromfile_instlumi[runls];
      if (!instlumi_ls_map.count(Run)) {
	std::stringstream ss;
	ss<<"instlumi_ls_"<<Run;
	instlumi_ls_map[Run] = new TH1D(ss.str().c_str(),ss.str().c_str(),10000,0.5,10000.5);
	instlumi_ls_map[Run]->SetDirectory(0);
      }
      if (!instlumi_ls_map[Run]->GetBinContent(Ls))
	instlumi_ls_map[Run]->SetBinContent(Ls, instlumi);
      runls_count[runls] = 1;
    }
  }
  
};
