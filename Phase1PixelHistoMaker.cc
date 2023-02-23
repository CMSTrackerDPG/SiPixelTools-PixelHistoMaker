/*
  Author:
    Janos Karancsi
  E-mail:
    janos.karancsi@cern.ch, karancsij@atomki.mta.hu
  
  Description:
    The program is used to creat histograms
    from the TimingStudy output files
  
  Version Info:
  VER   TimingStudy Ntuple version                 Date created
 -2 :   v2928 SPLIT 0                              (used for 2010/2011 Data)
 -1 :   v3029 SPLIT 0                              (used for 2010/2011 Data)
  0 :   v3431 SPLIT 0                              (2012                - by Alberto/Janos/Joco/Silvia)
  1 :   v3533 SPLIT 0                              (2013 Apr24          - by Viktor)
  2 :   v3533 SPLIT 1 + alpha/beta                 (2013 Apr28-May3     - by Viktor)
  3 :   v3734 SPLIT 1 + occupancy                  (2013 May 13)
  4 :   v3735 SPLIT 1 + pileup reweighting         (2014 Feb 04)
  5 :   v3836 SPLIT 1 + resolution                 (2014 Jun 16)
  6 :   v3938 SPLIT 1 + sizeXY always saved        (2016 Apr 27)
  7 :   Phase1 v0405 First  Phase 1 ntuple version (2017 May 16)
  8 :   Phase1 v0407 + inactive, muons, simhit/trk (2019 Oct 08) 
  9 :   Phase1 v0408 + 2nd cluster distance        (2020 Dec 17) 
  
  Note:
    From VER 3 and up, you can use this new PixelHistoMaker version
    for the previous Ntuple versions, use the old file (PixelHistoMaker_old.cc)
*/

// Set this if you only want to run on each Nth file
// This is used to do quick tests of binning on low statistics
#define NTHFILE 1
// Set on which trees you want to run on
// For now, only select 1, set others to 0
#define EVT_LOOP 1
#define TRAJ_LOOP 1
#define CLUST_LOOP 1

#define DCL_MISSING     0.1 // 1000 um
#define DCL_MISSING_NEW 0.1 // 1000 um - same for new hit efficiency

#define APPROVAL 0

#define PU_REWEIGHT_MC 0 // Using [0,60] flat distribution, reweight to Fill 6677
#define MAX_PU 60

// TimingStudy versions
#define VER 9
#if VER == -2 // v2928 backported
#define SPLIT 0
#define TREEREADER_VER 29
#define DATASTRUCT_VER 28
#elif VER == -1 // v3029 backported
#define SPLIT 0
#define TREEREADER_VER 30
#define DATASTRUCT_VER 29
#elif VER == 3
#define SPLIT 1
#define TREEREADER_VER 37
#define DATASTRUCT_VER 34
#elif VER == 4
#define SPLIT 1
#define TREEREADER_VER 37
#define DATASTRUCT_VER 35
#elif VER == 5
#define SPLIT 0
#define TREEREADER_VER 38
#define DATASTRUCT_VER 36
#elif VER == 6
#define SPLIT 1
#define TREEREADER_VER 39
#define DATASTRUCT_VER 36
#elif VER == 7
#define TREEREADER_VER 104
#define DATASTRUCT_VER 105
#elif VER == 8
#define TREEREADER_VER 104
#define DATASTRUCT_VER 108
#elif VER == 9
#define TREEREADER_VER 104
#define DATASTRUCT_VER 109
#endif

#if DATASTRUCT_VER > 100
#define PHASE 1
#else
#define PHASE 0
#endif

//#define COMPLETE 0
//#define EXPRESS 1

#include "interface/TreeLooper.h"

#include <fstream>

std::string strip(std::string line)
{
  int l = line.size();
  if ( l == 0 ) return std::string("");
  int n = 0;
  while (((line[n] == 0)    ||
          (line[n] == ' ' ) ||
          (line[n] == '\n') ||
          (line[n] == '\t')) && n < l) n++;

  int m = l-1;
  while (((line[m] == 0)    ||
          (line[m] == ' ')  ||
          (line[m] == '\n') ||
          (line[m] == '\t')) && m > 0) m--;
  return line.substr(n,m-n+1);
}


int main(int argc, char* argv[]) {
  int debug = 0;

  // Get arguments from shell
  std::vector<std::string> filelist;
  std::string outputfile="";
  size_t opt_n = 0;
  // -n <number> option:
  // Set so the postfix that uses the v.pf_file_add
  // get overwritten by <number>-1
  // default is opt_n=0 - use with files added by editing this file
  // -o <output file> option:
  // Specify the output root filename
  // Rest of the arguments are treated as files added
  // Note:
  // If using postfixes with the v.pf_file_add variable
  // each added file will increase this variable so when using *
  // add ""-s so instead of the shell TChain will parse the argument
  // -b option:
  // Former BADROC_RUN
  // Do not create any histos (except for ROC efficiency) to run faster
  bool BADROC_RUN = 0;
  bool is_o = false, is_n = false, is_a = false, is_b = false;
  for(int i=1; i<argc; i++) {
    std::string arg = argv[i];
    // Check existence of an option
    if (arg[0]=='-'&&arg.size()==2) { 
      is_n = (arg[1]=='n'); 
      is_o = (arg[1]=='o'); 
      if (arg[1]=='a') is_a = 1;
      if (arg[1]=='b') is_b = 1;
    }
    // Check second argument after option
    else if (is_n) { std::stringstream ss; ss<<arg; ss>>opt_n; is_n=0; } 
    else if (is_o) { outputfile=arg; is_o=0; }
    else filelist.push_back(arg);
  }
  if (is_b) BADROC_RUN = 1;
  if (debug) std::cout<<"Phase1PixelHistoMaker - command line arguments ok"<<std::endl;
  
  // Data structs holding variables read from TTrees
  RunData run; LumiData lumi; EventData e; TrajMeasurement t; Cluster c;
  if (debug) std::cout<<"Phase1PixelHistoMaker - containers ok"<<std::endl;
  
  // Variables that are derived from Data struct members
  Variables v;
  if (debug) std::cout<<"Phase1PixelHistoMaker - variables ok"<<std::endl;
  
  // TTree reader
  TreeReader tr(&run,&lumi,&e,&e,&t,&e,&c);
  if (debug) std::cout<<"Phase1PixelHistoMaker - treereader ok"<<std::endl;
  
  // Histogram storage class
  SmartHistos sh;
  if (EVT_LOOP   ||  BADROC_RUN) sh.AddHistoType("evt",  "Events");
  if (TRAJ_LOOP  ||  BADROC_RUN) sh.AddHistoType("traj", "On-track Clusters");
  if (CLUST_LOOP && !BADROC_RUN) sh.AddHistoType("clust","Clusters");
  if (debug) std::cout<<"Phase1PixelHistoMaker - smarthistos ok"<<std::endl;

  std::string prelim2016 = APPROVAL ? "Approval83" : "";
  std::string prelim2017 = APPROVAL ? "Approval93" : "";
  std::string CMSprelim  = APPROVAL ? prelim2017 : "";
  
  // Colors
  // 400 kYellow  800 kOrange
  // 416 kGreen	  820 kSpring
  // 432 kCyan	  840 kTeal
  // 600 kBlue	  860 kAzure
  // 616 kMagenta 880 kViolet
  // 632 kRed     900 kPink

  std::string col3_red_to_blue = "633,618,601,"; // red, purple, blue
  std::string col4_cyan_to_red = "434,601,618,633,"; // cyan, blue, purple, red
  std::string col4_red_to_cyan = "633,618,601,434,"; // red, purple, blue, cyan
  std::string col5_green_to_red = "418,434,601,618,633,"; // green, cyan, blue, purple, red
  std::string col5_red_to_green = "633,618,601,434,418,"; // red, purple, blue, cyan, green
  std::string col6_rainbow_dark = "601,434,418,402,633,618,"; // blue, cyan, green, yellow, red, purple
  std::string col8 = "1,601,434,418,402,807,633,618,"; // above plus black and orange
  std::string col10 = "4,6,2,800,402,417,433,9,618,633,";
  std::string col12 = "1,4,6,2,800,402,417,433,9,618,633,924,"; // black, blue, magenta, red, orange, darker yellow, darker green, darker cyan, blue-purple, dark purple, dark red
  std::string col12_rainbow = "402,416,433,600,617,632,802,813,833,863,883,892,"; // Go around first bright and then dark colors
  std::string col18 = col12_rainbow+col6_rainbow_dark;
  std::string col_lay = "633,417,601,799,433,633,418,601"; // Red, Green, Blue, Orange, Cyan, and again the same colors
  std::string col_lay_phase1 = col4_red_to_cyan + "799,402,417,"; // Red to Cyan, Orange, DYellow, Green
  std::string col_lay_oldnew = "634,632,618,601,434,799,402,417,"; // DRed, Red, Purple, Blue, Cyan, Orange, DYellow, Green

  // Tree Looper class, that uses the TreeReader
  // and Variables classes to obtain values to Data containers
  TreeLooper looper(&tr, &v, EVT_LOOP, TRAJ_LOOP, CLUST_LOOP); // Set these in the beginning of this file
#if PHASE == 0
  sh.AddNewPostfix("Layers",            [&v]{ return v.pf_layers;       }, "Lay[1to3]", "BPix, Layer [1to3]", APPROVAL ? "1,633,418" : col3_red_to_blue);
  sh.AddNewPostfix("Ladders",           [&v]{ return v.pf_ladders;      }, "Lad[1to22]", "Ladder [1to22]", col12+col12_rainbow);
  sh.AddNewPostfix("Disks",             [&v]{ return v.pf_disks;        }, "Disk1;Disk2", "Disk 1;Disk 2", "600,617");
  sh.AddNewPostfix("DisksInOut",        [&v]{ return v.pf_disksio;      }, "Disk1In;Disk1Out;Disk2In;Disk2Out", "Disk 1 - Inner 3 Plq;Disk 1 - Outer 4 Plq;Disk 2 - Inner 3 Plq;Disk 2 - Outer 4 Plq", col4_cyan_to_red);
  sh.AddNewPostfix("LayersDisksInOut",  [&v]{ return v.pf_lays_disksio; }, "Lay[1to3];Disk1In;Disk1Out;Disk2In;Disk2Out", "Layer [1to3];Disk 1 - Inner 3 Plq;Disk 1 - Outer 4 Plq;Disk 2 - Inner 3 Plq;Disk 2 - Outer 4 Plq", col8);
  sh.AddNewPostfix("LayersDisks",       [&v]{ return v.pf_lays_disks;   }, "Lay[1to3];Disk[1to2]", "BPix, Layer [1to3];FPix, Disk [1to2]", col_lay);
  //sh.AddNewPostfix("LayersDisksOldNew", [&v]{ return v.pf_lays_disks_oldnew; }, "Lay[1to3]Old;Disk[1to2]Old;Lay[1to3]New", "Layer [1to3];Disk [1to2];L[1to3] (New)", col5_red_to_green+"632,616,600");
  sh.AddNewPostfix("LayersDisksOld",    [&v]{ return v.pf_lays_disks_oldnew< 6 ? v.pf_lays_disks_oldnew   : (size_t)-1; }, "Lay[1to3]Old;Disk[1to2]Old", "Layer [1to3];Disk [1to2]", col_lay);
  sh.AddNewPostfix("LayersNew",         [&v]{ return v.pf_lays_disks_oldnew>=6 ? v.pf_lays_disks_oldnew-5 : (size_t)-1; }, "Lay[1to3]New",               "Layer [1to3]",             col_lay);
  sh.AddNewPostfix("BPixNew",           [&v]{ return (size_t)(v.pf_new_modules ? 0 : -1); }, "BPixNew", "New modules", "1");
  sh.AddNewPostfix("LayersAllDisks",    [&v]{ return v.layers_disks-1;  }, "Lay[1to3];Diskm2;Diskm1;Diskp1;Diskp2", "BPix, Layer [1to3];FPix, Disk [-2to-1];FPix, Disk [1to2]", col8);
  sh.AddNewPostfix("HVGroupsScanned",   [&v]{ return v.pf_lays_disks;   }, "L[1to3]OneHVGrp;D[1to2]OneHVGrp", "Layer [1to3] (One HV group);Disk [1to2] (One HV group)", col5_red_to_green);
#elif PHASE == 1
  sh.AddNewPostfix("Layers",            [&v]{ return v.pf_layers;       }, "Lay[1to4]", "Layer [1to4]", col4_red_to_cyan);
  sh.AddNewPostfix("LayersOldNew",      [&v]{ if (v.pf_det==1) return (size_t)-1; return v.pf_lays_disks_oldnew; },   "Lay1Old;Lay1New;Lay[2to4]", "Layer 1 - Old;Layer 1 - New;Layer [2to4]", col_lay_oldnew);
  sh.AddNewPostfix("Ladders",           [&v]{ return v.pf_ladders;      }, "Lad[1to34]", "Ladder [1to34]", col12+col12_rainbow+col12+col12_rainbow);
  sh.AddNewPostfix("Disks",             [&v]{ return v.pf_disks;        }, "Disk[1to3]", "Disk [1to3]", col3_red_to_blue);
  sh.AddNewPostfix("DisksRings",        [&v]{ if (v.pf_det==0) return (size_t)-1; return (size_t)(v.pf_disks*2+(v.ring==2)); }, "Disk1_Ring[1to2];Disk2_Ring[1to2];Disk3_Ring[1to2]", "Disk 1 Ring [1to2];Disk 2 Ring [1to2];Disk 3 Ring [1to2]", col6_rainbow_dark);
  sh.AddNewPostfix("Ring1Disks",        [&v]{ if (v.ring!=1) return (size_t)-1; return v.pf_disks; }, "Ring1_Disk1;Ring1_Disk2;Ring1_Disk3", "Ring 1 Disk 1;Ring 1 Disk 2;Ring 1 Disk 3", "601,418,633");
  sh.AddNewPostfix("Ring2Disks",        [&v]{ if (v.ring!=2) return (size_t)-1; return v.pf_disks; }, "Ring2_Disk1;Ring2_Disk2;Ring2_Disk3", "Ring 2 Disk 1;Ring 2 Disk 2;Ring 2 Disk 3", "434,402,618");
  sh.AddNewPostfix("Rings",             [&v]{ if (v.pf_det==0) return (size_t)-1; return (size_t)(v.ring-1); }, "Ring[1to2]", "Ring [1to2]", "633,601,");
  sh.AddNewPostfix("LayersDisks",       [&v]{ return v.pf_lays_disks_phase1;   }, "Lay[1to4];Disk[1to3]", "Layer [1to4];Disk [1to3]", col_lay_phase1);
  sh.AddNewPostfix("LayersDisksOldNew", [&v]{ return v.pf_lays_disks_oldnew; },   "Lay1Old;Lay1New;Lay[2to4];Disk[1to3]", "Layer 1 - Old;Layer 1 - New;Layer [2to4];Disk [1to3]", col_lay_oldnew);
  sh.AddNewPostfix("LayersAllDisks",    [&v]{ return v.layers_disks_phase1-1;  }, "Lay[1to4];Diskm3;Diskm2;Diskm1;Diskp1;Diskp2;Diskp3", "Layer [1to4];Disk [-3to-1];Disk [1to3]", col12);
  sh.AddNewPostfix("AllDisks",          [&v]{ return v.layers_disks_phase1>4?v.layers_disks_phase1-5:(size_t)-1;  }, "Diskm3;Diskm2;Diskm1;Diskp1;Diskp2;Diskp3", "Disk [-3to-1];Disk [1to3]", col6_rainbow_dark);
#endif
  sh.AddNewPostfix("Layer1",            [&v]{ return (size_t)(v.layer==1 ? 0 : -1); }, "Layer1", "Layer 1", "1");
  sh.AddNewPostfix("Layer2",            [&v]{ return (size_t)(v.layer==2 ? 0 : -1); }, "Layer2", "Layer 2", "1");
  sh.AddNewPostfix("Layer3",            [&v]{ return (size_t)(v.layer==3 ? 0 : -1); }, "Layer3", "Layer 3", "1");
  sh.AddNewPostfix("Layer4",            [&v]{ return (size_t)(v.layer==4 ? 0 : -1); }, "Layer4", "Layer 4", "1");
  sh.AddNewPostfix("Layer12/34",        [&v]{ return (size_t)(v.layer==1||v.layer==2 ? 0 : v.layer==3||v.layer==4 ? 1 : -1); }, "Lay12;Lay34", "Layer 1-2;Layer 3-4", "1,2");
  sh.AddNewPostfix("Mods",              [&v]{ return v.pf_mods;         }, "Mod[1to4]", "Mod[1to4]", col4_cyan_to_red);
  sh.AddNewPostfix("AllMods",           [&v]{ return v.pf_allmods;      }, "Modm[4to1--1];Modp[1to4]", "Ring [-4to-1];Ring [1to4]", col8);
  sh.AddNewPostfix("Mod12/34",          [&v]{ return v.pf_mods>=2;      }, "Mod12;Mod34", "Mod 1,2;Mod 3,4", "633,601");
  sh.AddNewPostfix("InnerOuter",        [&v]{ return v.pf_outer;        }, "InnerLadders;OuterLadders", "Inner ladders;Outer ladders", "633,601,");
  sh.AddNewPostfix("Rings",             [&v]{ return v.ring-1;          }, "Ring[1to2]", "Ring[1to2]", "601,633,");
  sh.AddNewPostfix("BPixFPix",          [&v]{ return v.is_fpix;         }, "BPix;FPix", "Barrel Pixels;Forward Pixels", "633,601");
  sh.AddNewPostfix("AllROCs",           []  { return 0;                 }, "AllROCs",  "All ROCs", "1");
  sh.AddNewPostfix("ExclMods",          []  { return 0;                 }, "ExclMods", "No bad modules", "1");
  sh.AddNewPostfix("NewModules",        [&v]{ return v.pf_new_modules;  }, "OldModules;NewModules", "Old Modules;New Modules", "633,417");

  sh.AddNewPostfix("ValidHit",          [&t]{ return (size_t)(t.validhit); }, "missing;valid", "Missing hit;Valid hit", "633,418");
  sh.AddNewPostfix("Eta",               [&t]{ 
                     float abseta = std::abs(t.trk.eta);
                     return size_t(abseta>=2.4 ? -1 : abseta/0.4);
                   }, "Eta[0to2.0++0.4]to[0.4to2.4++0.4]", "|#eta| #subset [[0to2.0++0.4],[0.4to2.4++0.4]]", col6_rainbow_dark);
  sh.AddNewPostfix("TrkBeta",           [&t]{ 
		       double beta = std::abs(3.1416/2 - std::abs(t.beta));
		       return (size_t)(beta<0.1 ? 0 : beta>1.2 ? 1 : -1);
		     }, "TrkBeta0p1;TrkBeta1p2", "#beta<0.1;#beta>1.2", "633,417");
  sh.AddNewPostfix("OnTrack",           []{   return 0;                 }, "OnTrackClu", "On-track clusters", "1");
  sh.AddNewPostfix("Shell",             [&v]{ return v.pf_shell;        }, "BpI;BpO;BmI;BmO", "BpI;BpO;BmI;BmO", col4_cyan_to_red);
  sh.AddNewPostfix("Sectors",           [&v]{ return v.pf_sector;       }, "Sec[1to8]", "Sector [1to8]", col8);
  sh.AddNewPostfix("RingsROGs",         [&v]{ return v.pf_ring_rog;     }, "Ring1_Rog[1to4];Ring2_Rog[1to4]", "Ring1 ROG[1to4];Ring2 ROG[1to4]", col8);
  sh.AddNewPostfix("FPixRadius",        [&t,&v]{
                     if (t.glz<25) return (size_t)-1;
                     double r = std::sqrt(t.glx*t.glx+t.gly*t.gly); 
                     if      (v.ring==1) return (size_t)(r>=8.);
                     else if (v.ring==2) return (size_t)(2+(r>=13.));
                     else return (size_t)-1;
                   }, "Ring1_4to8cm;Ring1_8o12cm;Ring2_9to13cm;Ring2_13to17cm", "Ring1 4-8 cm;Ring1 8-12 cm;Ring2 9-13 cm;Ring2 13-17 cm", col4_red_to_cyan);

  sh.AddNewPostfix("Pileup",            [&v]{ return v.pf_pileup;       }, "pu[2.5to47.5++5]", "[2.5to47.5++5] pile-up", col12_rainbow);
  sh.AddNewPostfix("Pileup5",           [&v]{ return (size_t)v.pileup>89? -1 : (size_t)(v.pileup/5); }, "pu[0to85++5]to[5to90++5]", "#LTpu#GT #subset [[0to85++5],[5to90++5]]", col18);
  sh.AddNewPostfix("Pileup4",           [&v]{ return (size_t)v.pileup>71? -1 : (size_t)(v.pileup/4); }, "pu[0to68++4]to[4to72++4]", "#LTpu#GT #subset [[0to68++4],[4to72++4]]", col18);
  sh.AddNewPostfix("Pileup3",           [&v]{ return (size_t)v.pileup>53? -1 : (size_t)(v.pileup/3); }, "pu[0to51++3]to[3to54++3]", "#LTpu#GT #subset [[0to51++3],[3to54++3]]", col18);
  sh.AddNewPostfix("Pileup2",           [&v]{ return (size_t)v.pileup>47? -1 : (size_t)(v.pileup/2); }, "pu[0to46++2]to[2to48++2]", "#LTpu#GT #subset [[0to46++2],[2to48++2]]", col12_rainbow+col12);
  //sh.AddNewPostfix("InstLumi",          [&v]{ return v.pf_instlumi;     }, "[0to10]invnbHz", "[0to10] nb^{-1}s^{-1}", col12_rainbow);
  sh.AddNewPostfix("InstLumi",          [&v]{ return v.pf_instlumi2;     }, "[0to28++2]to[2to30++2]invnbHz", "Inst. Lumi. #subset [[0to28++2], [2to30++2]] nb^{-1}Hz", col12_rainbow+col12);
  //sh.AddNewPostfix("InstLumi",          [&v]{ return v.pf_instlumi3;     }, "[0to12++2]to[2to14++2]invnbHz", "Inst. Lumi. #subset [[0to12++2], [2to14++2]] nb^{-1}Hz", col12_rainbow+"1");
  //sh.AddNewPostfix("InstLumi",          [&v]{ return v.pf_instlumi;     }, "[0to20++2]invnbHz", "[0to20++2] nb^{-1}s^{-1}", col12_rainbow);
  //sh.AddNewPostfix("InstLumi",          [&v]{ return v.pf_instlumi2;     }, "0to2invnbHz;4to6invnbHz;[12to18++2]to[14to20++2]invnbHz", "Inst. Lumi. #subset [[0], [2]] nb^{-1}Hz;Inst. Lumi. #subset [[4], [6]] nb^{-1}Hz;Inst. Lumi. #subset [[12to18++2], [14to20++2]] nb^{-1}Hz", col6_rainbow_dark);
  sh.AddNewPostfix("AvgInstLumi",       [&v]{ return (size_t)(v.instlumi>=10.0&&v.instlumi<12? 0 : -1); }, "AvgInstlumi", "Inst. lumi. #subset [[10], [12]] nb^{-1}Hz", "1");
  sh.AddNewPostfix("L1Rate",            [&v]{ return v.pf_l1rate;       }, "[0to120++10]kHz", "[0to120++10]kHz", col12_rainbow);
  //sh.AddNewPostfix("NBx",               [&v]{ return (size_t)(v.nbx==NOVAL_F||v.nbx>=2500) ? -1 : v.nbx/50; }, "NBx[25to2475++50]", "[25to2475++50]#pm25b", col12+col12_rainbow+col12+col12_rainbow);
  sh.AddNewPostfix("NBx",          [&v]{ return (size_t)(v.nbx==NOVAL_F||v.nbx>=3000) ? -1 : v.nbx/100; }, "NBx[50to2950++100]", "[50to2950++100]#pm50b", col12+col12_rainbow+col12+col12_rainbow);
  sh.AddNewPostfix("LowNBx",       [&v]{ return (size_t)(v.nbx==NOVAL_F||v.nbx>=350) ? -1 : v.nbx/10;      }, "NBx[5to345++10]",   "[5to345++10]#pm5b", col12+col12_rainbow+col12+col12_rainbow);
  //sh.AddNewPostfix("SelectedNBx",   [&v]{ return (size_t)(v.nbx==NOVAL_F||v.nbx>=2500) ? -1 : v.nbx/50; }, "NBx2225;NBx1825;NBx1475;NBx1025;NBx525", "2232b;1813b;1453b;1021b;517b", "633,618,601,434,1");
  //sh.AddNewPostfix("SelectedNBx",          [&v,&e]()
  //      	   { 
  //      	     size_t result=-1;
  //      	     //if (v.main_filling_schemes_2015) result=0;
  //      	     //else if (fabs(v.nbx-1813)<100) result=1;
  //      	     //else if (fabs(v.nbx-1453)<70) result=2;
  //      	     //else if (fabs(v.nbx-1021)<70) result=3;
  //      	     if (e.run>=260424&&e.run<=260627) result=0;
  //      	     else if (e.run>=260099&&e.run<=260235) result=0;
  //      	     else if (e.run>=262270&&e.run<=262328) result=1;
  //      	     else if (e.run>=259809&&e.run<=259891) result=1;
  //      	     else if (e.run>=259681&&e.run<=259686) result=1;
  //      	     else if (e.run>=258655&&e.run<=258656) result=1;
  //      	     else if (e.run>=262248&&e.run<=262254) result=2;
  //      	     else if (e.run>=257804&&e.run<=258215) result=2;
  //      	     else if (e.run>=256842&&e.run<=256843) result=3;
  //      	     else if (e.run>=256630&&e.run<=256734) result=3;
  //      	     //else if (e.run==259721) result=4;
  //      	     return result;
  //      	   }, "2232b;1813b;1453b;1021b;517b", "2232b;1813b;1453b;1021b;517b", "633,618,601,434,1");
  //sh.AddNewPostfix("SelectedNBx",   [&v]{ return (size_t)(v.nbx==NOVAL_F||v.nbx>=2500) ? -1 : v.nbx/50; }, "NBx2250;NBx2050;NBx1750;NBx550;NBx50", "2232b;1813b;1453b;1021b;517b", "633,618,601,434,1");
  //sh.AddNewPostfix("SelectedNBx",          [&v,&e]()
  //      	   { 
  //      	     size_t result=-1;
  //      	     // 2017 Low lumi Fills
  //      	     if      (e.run>=306546&&e.run<=306550) result=0;
  //      	     else if (e.run>=306553&&e.run<=306554) result=1;
  //      	     else if (e.run>=306563&&e.run<=306572) result=2;
  //      	     else if (e.run>=306772&&e.run<=306777) result=2;
  //      	     else if (e.run>=306793&&e.run<=306802) result=3;
  //      	     else if (e.run>=306580&&e.run<=306709) result=4;
  //      	     return result;
  //      	   }, "22b;512b;1280b;1536b;1824b", "22b;512b;1280b;1536b;1824b", "1,434,601,618,633");
  sh.AddNewPostfix("SelectedNBx",          [&v,&e]()
        	   { 
        	     size_t result=-1;
		     // 2018 Early fills (2018Comm/2018A)
        	     if      (e.run>=314556&&e.run<=314576) result=0;
        	     else if (e.run>=314747&&e.run<=314764) result=1;
        	     else if (e.run>=314889&&e.run<=314890) result=2;
        	     else if (e.run>=315239&&e.run<=315259) result=3;
        	     else if (e.run>=315262&&e.run<=315273) result=4;
        	     else if (e.run>=315360&&e.run<=315366) result=5;
        	     else if (e.run>=315487&&e.run<=315490) result=6;
        	     else if (e.run>=315503&&e.run<=315512) result=7;
        	     else if (e.run>=315640&&e.run<=315648) result=8;
        	     else if (e.run>=315741)                result=9;
        	     return result;
        	   }, "2b;62b;326b;590b;974b;1214b;1538b;1874b;2162b;2544b", "2b;62b;326b;590b;974b;1214b;1538b;1874b;2162b;2544b", col10);
  
  sh.AddNewPostfix("BX>500",            [&e]{ return e.bx>500;          }, "Bx0to500;Bx500to3600",   "BX<500;BX>500", "601,633");
  sh.AddNewPostfix("TSFirst3BX",         [&e]{ return 
		       (e.bx==289||e.bx==1183||e.bx==2077) ? 0 :
		       (e.bx==290||e.bx==1184||e.bx==2078) ? 1 :
		       (e.bx==291||e.bx==1185||e.bx==2079) ? 2 :
		       (size_t)-1; }, "BXm1;BX0;BXp1", "First BX -1;First BX;First BX +1", "601,418,633");
  
  sh.AddNewPostfix("FedErrorEvent",     [&e]{ return e.federrs_size>0; }, "NoFedErrorInEvt;FedErrorInEvt",   "No FED error in event;Fed error in event",   "418,633");
  sh.AddNewPostfix("FedErrorModule",    [&v]{ return v.federr_mod;     }, "NoFedError;Timeout;Overflow",   "No FED error on module;Timeout;Overflow", "418,633,807,");
  sh.AddNewPostfix("First4BX",          [&e,&v]()
		   { return
		       (e.bx==v.first_filled_bx-2) ? 0 :
		       (e.bx==v.first_filled_bx-1) ? 1 :
		       (e.bx==v.first_filled_bx)   ? 2 :
		       (e.bx==v.first_filled_bx+1) ? 3 :
		       (size_t)-1; 
		   }, "BXm2;BXm1;BX0;BXp1", "First BX -2;First BX -1;First BX;First BX +1", "1,601,633,802");
  
  // Same category, but used widely to compare plots
  sh.AddNewPostfix("DcolScan",      [&v]{ return v.pf_file_add; }, "Dcol[80,90,95,97,98,99,99.3,99.6,99.9,100]", "MC Dcol Eff = [80,90,95,97,98,99,99.3,99.6,99.9,100]%", "1-11");
  sh.AddNewPostfix("DColScan",      [&v]{ return v.pf_file_add; }, "Dcol[75,78,81,87,90,92,95,97,99,100]", "DCol [75,78,81,87,90,92,95,97,99,100]%", col12);
  
  //sh.AddNewPostfix("Years",         [&v]{ return v.pf_year;     },     "2011;2012;2015", "2011 Data @ 7 TeV;2012 Data @ 8 TeV;", "4,2,1");
  sh.AddNewPostfix("Years",         [&v]{ 
		     if (v.year==2011) return (size_t)0;
		     else if (v.year==2012) return (size_t)1;
		     else if (v.year==2015) return (size_t)2;
		     else if (v.year==2016) return (size_t)3;
		     else return (size_t)-1;
		   }, "2011;2012;2015;2016", "2011 Data @ 7 TeV;2012 Data @ 8 TeV;2015 Data;2016 Data", col4_cyan_to_red);
  //sh.AddNewPostfix("DataYears", [&e,&v]{ if (e.run!=1&&v.pf_file_add==0&&v.year==2015) return (size_t)0; else return (size_t)-1; }, "2015Data", "2015 Data", "1");
  //sh.AddNewPostfix("DataYears", [&e]{ if (e.run!=1) return (size_t)0; return (size_t)-1; }, "2017Data", "2017 Data", "1");
  //sh.AddNewPostfix("DataYears", [&e]{ if (e.run!=1) return (size_t)0; return (size_t)-1; }, "2018Data", "2018 Data", "1");
  sh.AddNewPostfix("DataYears", [&e]{ 
                     if (e.run==1) return (size_t)-1;
                     //return (size_t)(e.run>=307510); 
                   //}, "2017Data;2018Data", "2017 Data;2018 Data", "601,633,");
                     return (size_t)(e.run>=307510); 
                   }, "2017Data;2021Data", "2017 Data;2021 Data", "601,633,");

  sh.AddNewPostfix("Data2022", [&e]{ 
                     if (e.run==1) return (size_t)-1;
                     //return (size_t)(e.run>=307510); 
                   //}, "2017Data;2018Data", "2017 Data;2018 Data", "601,633,");
                     return (size_t)(e.run>=355000); 
                   }, "1984Data;2022Data", "1984 Data;2022 Data", "601,633,");
  //sh.AddNewPostfix("DataYears", [&e,&v]{ 
  //                   if (e.run==1) return (size_t)-1;
  //                   else if (v.year==2011) return (size_t)0;
  //                   else if (v.year==2012) return (size_t)1;
  //                   else if (v.year==2015) return (size_t)2;
  //                   else if (v.year==2016) return (size_t)3;
  //                   else return (size_t)-1;
  //                 }, "2011Data;2012Data;2015Data;2016Data", "2011;2012;2015;2016", col4_cyan_to_red);
  // Above postfix is placeholder for future comparisons, use the one below instead
  //sh.AddNewPostfix("2232bData", [&e,&v]{ if (e.run!=1&&v.pf_file_add==1&&v.main_filling_schemes_2015) return (size_t)0; else return (size_t)-1; }, "2232bData", "High lumi data", "1");
  sh.AddNewPostfix("MainFills", [&e,&v]{ return (size_t)(v.main_filling_schemes ? 0 : -1); }, "MainFills", "", "1");
  sh.AddNewPostfix("Months", [&e,&v]{ 
		     if (e.run==1) return (size_t)-1;
		     else if (v.month<1||v.month>12) return (size_t)-1;
		     else return (size_t)v.month-1;
		   }, "Jan;Feb;Mar;Apr;May;Jun;Jul;Aug;Sep;Oct;Nov;Dec", "January;February;March;April;May;June;July;August;September;October;November;December", col12);
  sh.AddNewPostfix("IntLumiRunII", [&e,&v]{
		     double run2_lumi = v.intlumi-29.9261;
		     if (run2_lumi<0||run2_lumi>4.5) return (size_t)-1; 
		     else return (size_t)((run2_lumi)*2); 
		   }, "IntLumi[0to4++0.5]to[0.5to4.5++0.5]", "[[0to4++0.5], [0.5to4.5++0.5]] fb^{-1}", col12_rainbow);
  sh.AddNewPostfix("IntLumiRunIII", [&e,&v]{
		     double run2_lumi = v.intlumi;
		     if (run2_lumi<0) return (size_t)-1; 
		     else return (size_t)((run2_lumi)*2); 
		   }, "IntLumi[0to4++0.5]to[0.5to4.5++0.5]", "[[0to4++0.5], [0.5to4.5++0.5]] fb^{-1}", col12_rainbow);
  
  //sh.AddNewPostfix("Validation",    [&v]{ return v.pf_file_add; }, "Data;MC_Old;MC;MC_New", "Data;MC - No Dyn. Ineff.;MC - Current Version;MC - New Version", "1,2,4,3");
  //sh.AddNewPostfix("Validation",    [&v]{ return v.pf_file_add; }, "Data;MC_Old;MC", "Data;MC - No Dyn. Ineff.;MC - Current Version", "1,2,4");
  //sh.AddNewPostfix("Validation",    [&v]{ return v.pf_file_add; }, "Data;MC_New", "Data;MC - with FPix DynIneff", "1,2,4,3");
  //sh.AddNewPostfix("Validation",    [&v]{ return v.pf_file_add; }, "MC;MC_New", "MC - Current Version;MC - New Version", "4,3");
  sh.AddNewPostfix("Validation",    [&v]{ return v.pf_file_add; }, "Data;MC;MC_New", "Data;MC - No DynIneff;MC - with BPix+FPix DynIneff", "1,2,4,3");
  sh.AddNewPostfix("8and13TeV",     [&v]{ return v.pf_file_add; }, "Data_8TeV;MC_8TeV;MC_13TeV_50ns;MC_13TeV_50ns_PSI;MC_13TeV_25ns", "Data 8TeV;MC 8TeV;MC 13TeV (50ns);MC 13TeV (50ns) - PSI Sim.;MC 13TeV (25ns)", "1,2,4,618,3");
  sh.AddNewPostfix("Data",         [&e]{ if (e.run!=1) return (size_t)0; else return (size_t)-1; }, "Data", "", "1");
  //sh.AddNewPostfix("DatavsMC2015", [&v]{ return v.pf_file_add; }, "Data_50ns;MC_50ns;Data_25ns;MC_25ns", "Data - 50ns;MC - 50ns;Data - 25ns;MC - 25ns", "1,632,1,601");
  //sh.AddNewPostfix("DatavsMC", [&v]{ return !v.is_data; }, "Data;MC", "Data;MC", "1,633");
  sh.AddNewPostfix("DatavsMC2016", [&e,&v]{ return (e.run==1) ? v.pf_file_add : 0; }, "Data2016;MC2016;MC2016Tune", "Data;Simulation (Previous);Simulation", "1,418,633");
  sh.AddNewPostfix("DatavsMC2017", [&e,&v]{ return (e.run==1) ? 1 : 0; }, "Data2017;MC2017", "Data;Simulation", "1,633");
  sh.AddNewPostfix("DatavsMC2018", [&e,&v]{ return (e.run==1) ? 1 : 0; }, "Data2018;MC2018", "Data;Simulation", "1,633");
  sh.AddNewPostfix("BunchSpacing", [&v]{ return v.pf_file_add>=2; }, "50ns;25ns", "50ns;25ns", "633,601");
  //sh.AddNewPostfix("Special", [&v]{ return 0; }, "Data_8TeV;MC_8TeV;Data_50ns_50ns;MC_50ns_50ns;data;MC_25ns", "8 TeV Data - 50ns;8 TeV MC - 50ns;13 TeV Data - 50ns;13 TeV MC - 50ns;13 TeV Data - 25ns;13 TeV MC - 25ns", "1,14,602,433,633,910");
  //sh.AddNewPostfix("data",         []{ return 0; }, "data", "", "1");
  //sh.AddNewPostfix("2016Pred", [&v]{ return v.pf_file_add; }, "Data_8TeV;Data;MC;MCPred", "Data - 2012;Data - 2015;MC - 2015 (1655b - average);MC - 2016 (2700b)", "1,418,601,633");
  sh.AddNewPostfix("DataMCComp",      [&v]{ return v.pf_file_add; }, "Data2015;MC;MC2015;MC2016", "Data - 2015 (2232b);MC - 2015 (2232b);MC - 2015 Tune (2232b);MC - 2016 (2736b)", "1,633,418,601");
  sh.AddNewPostfix("BestAndAllVertices", [&v]{ return v.pf_file_add; }, "BestVtx;AllVtx", "Tracks from best vertex;All vertices", "633,418");
  //sh.AddNewPostfix("DatavsMC",      [&v]{ return v.pf_file_add; }, "Data2015;Data2232b;MC2015", "Data - 2015;Data - 2015 (2232b);MC - 2015 Tune (2232b)", "1,12,633");
  //sh.AddNewPostfix("DatavsMCApproval", [&v]{ return (size_t)-1; }, "Data2232b;MC2015", "Data;Simulation", "1,633");
  sh.AddNewPostfix("AllDatavsMC",   [&v]{ 
		     if (v.pf_file_add==1) return (size_t)-1;
		     else if (v.pf_file_add==0) return v.pf_new_modules;
		     else return (size_t)2;
		   }, "Data2015_OldModules;Data2015_NewModules;MC2015", "2015 Data, Old modules;2015 Data, New modules;Simulation", "1,418,633");
  sh.AddNewPostfix("DatavsMC",   [&v]{
		     if (v.pf_file_add==0) return (size_t)-1;
		     else if (v.pf_file_add==1) return v.pf_new_modules;
		     else return (size_t)2;
		   }, "Data2232b_OldModules;Data2232b_NewModules;MC2015", "Data, Old modules;Data, New modules;Simulation", "1,418,633");
  sh.AddNewPostfix("GainCalib",   [&v]{ return v.pf_file_add; }, "OldGain;NewGain", "Gain 2017_v2;Gain 2017_v3", "633,418");
  sh.AddNewPostfix("VCalCalib",   [&v]{ return v.pf_file_add; }, "MCOldVCal;MCNewVCal;DataOldVCal;DataNewVCal", "MC - Old VCal;MC - New VCal;Data - Old VCal;Data - New VCal", "1,601,634,418");
  sh.AddNewPostfix("DatavsMC2016_2076or2208b",   [&e,&v]{ return (e.run==1) ? v.pf_file_add : v.main_filling_schemes; },
                   "2076bData2016;Data2016;MC2016Curr;MC2016", "Data (2076b);Data (2208b);MC (Current);MC (Moriond)", "418,1,633,601");
  sh.AddNewPostfix("GainValidation",  [&v]{ return v.pf_file_add; }, "Gainsv2;Gainsv4", "Gains 2017_v2;Gains 2017_v4", "1,601,634,418");
  sh.AddNewPostfix("TBMReset",  [&e]{ 
		     if (e.run<299479||(e.run>=299614&&e.run<=300088)) return (size_t)0;
		     else if (e.run==299479) return (size_t)1;
		     else if (e.run==299480) return (size_t)2;
		     else if (e.run==299481) return (size_t)2;
		     else if (e.run>=299592&&e.run<=299598) return (size_t)2;
		     else if (e.run>=299592&&e.run<=299598) return (size_t)2;
		     else if (e.run>=300105&&e.run<=300157) return (size_t)2;
		     else if (e.run>=300226&&e.run<=301183) return (size_t)3;
		     else if (e.run>=301281&&e.run<=304508) return (size_t)4;
		     else if (e.run>=304562&&e.run<=304740) return (size_t)5;
		     else if (e.run>=304776) return (size_t)4;
		     return (size_t)-1;
		   }, "Disabled;TBMReset;TBMResetPrescale6;TBMResetBGo50;TBMResetBGo70;TBMResetBGo100", "Disabled;L1Rate/256;L1Rate/1536;50 Hz (via B-go);70 Hz (via B-go);100 Hz (via B-go)", "1,434,418,601,618,633,");
  sh.AddNewPostfix("EffLossStudy",  [&e,&v]{ 
		     if (e.run==1) return v.pf_file_add;
		     else if (e.run==299479) return (size_t)-1;
		     else if (e.run<299479||(e.run>=299614&&e.run<=300088)) return (size_t)8;
		     else if (e.run>=300226) return (size_t)10;
		     else return (size_t)9;
		   }, "Roc0p975;Roc0p95;Pix0p95;Pix0p9;Pix0p8;DCol0p95;DCol0p9;DCol0p81;Disabled;TBMResetPrescale6;TBMResetBGo14", "MC - ROC 97.5%;MC - ROC 95%;MC - Pixel 95%;MC - Pixel 90%;MC - Pixel 80%;MC - DCol 95%;MC - DCol 90%;MC - DCol 81%;Data - TBM R. Disabled;Data - TBM R. Prescale 6;TBM Reset - via B-go 14", col12);
  sh.AddNewPostfix("TBMReset2",  [&e]{ return 0; }, "Layer1_Disabled;Layer1_TBMReset;Layer1_TBMResetPrescale6", "Disabled;TBM Reset;TBM Reset - prescale 6", "634,601,418");
  sh.AddNewPostfix("EffLossMC",  [&e,&v]{ if (e.run==1) return v.pf_file_add;  else return (size_t)-1; }, 
		   "DCol0p95;DCol0p9;DCol0p81;Roc0p975;Roc0p95;Pix0p95;Pix0p9;Pix0p8",
		   "MC - DCol 95%;MC - DCol 90%;MC - DCol 81%;MC - ROC 97.5%;MC - ROC 95%;MC - Pixel 95%;MC - Pixel 90%;MC - Pixel 80%", col8);
  sh.AddNewPostfix("EffLossData",  [&e,&v]{ 
		     if (e.run==1) return (size_t)-1;
		     else if (e.run==299479) return (size_t)-1;
		     else if (e.run<299479||(e.run>=299614&&e.run<=300088)) return (size_t)0;
		     else if (e.run>=300226) return (size_t)2;
		     else return (size_t)1;
		   }, "Disabled;TBMResetPrescale6;TBMResetBGo14", "Data - TBM R. Disabled;Data - TBM R. Prescale 6;TBM Reset - via B-go 14", "634,418,1");
  sh.AddNewPostfix("DatavsMCs2017", [&e,&v]{ return (e.run!=1) ? 0 : v.pf_file_add; }, "Data2017;MC2017Old;MC2017;MCThr", "Data;MC - Current (No ineff);MC - New (DCol ineff);MC - New + Higher Thresholds", "1,633,418,601");
  //sh.AddNewPostfix("DynIneffDB", [&e,&v]{ return (e.run!=1) ? 0 : v.pf_file_add; }, "Data2017;MC2017v2;MC2017v3;MC2017v3L1Thr3k;MC2017v3L1Thr4k;MC2017v3L1Thr5k;MC2017v3L1Thr6k", "Data;MC - v2;MC - v3;MC - v3 + Tuned Thr (L1 3k);MC - v3 + Tuned Thr (L1 4k);MC - v3 + Tuned Thr (L1 5k);MC - v3 + Tuned Thr (L1 6k)", "1,633,418,601,434,618,633");
  //sh.AddNewPostfix("DynIneffDBValid", [&e,&v]{ return (e.run!=1) ? 0 : v.pf_file_add; }, "Data2017;MC2017v2;MC2017v3", "Data;MC - v2;MC - v3", "1,633,418,601,434,618,633");
  //sh.AddNewPostfix("DynIneffDBValid", [&e,&v]{ return (e.run!=1) ? 0 : v.pf_file_add; }, "Data2018;MC2017v3;MC2018v4", "Data;MC - Phase1 v3;MC - Phase1 v4", "1,633,418");
  sh.AddNewPostfix("PostTS1Cond", [&e,&v]{ return v.pf_file_add; }, "Run317626;Run317661", "317626 - preTS1;317661 - postTS1 ReReco", "633,418");
  sh.AddNewPostfix("DynIneffDBValid", [&e,&v]{ return (e.run!=1) ? 0 : v.pf_file_add; }, "Data2018;MC2017v3;MC2018v4;MC2018v6;RelValQCD;PrivateQCD", "Data;MC - Phase1 v3;MC - Phase1 v4;MC - Phase1 v6;MC - RelVal QCD;MC - Private QCD", "1,632,634,418,601,618");
  
  //sh.AddNewPostfix("Run3Simulation",  [&e,&v]{ return v.pf_file_add; }, "RelVarTTBar_2018;MinBias_2021;MinBias_2023;MinBias_2024", "RelValTTBar - 2018;MinBias - 2021;MinBias - 2023;MinBias - 2023", col4_red_to_cyan);
  sh.AddNewPostfix("Run3Simulation",  [&e,&v]{ return v.pf_file_add; }, "MinBias_2021;MinBias_2023;MinBias_2024", "MinBias - 2021;MinBias - 2023;MinBias - 2023", col4_red_to_cyan);
  //sh.AddNewPostfix("VersionCompare", [&e,&v]{ return v.pf_file_add; }, "MinBias_102X_Phase1_v6;MinBias_106X_Phase1_v6;MinBias_102X_Phase1_v8;MinBias_106X_Phase1_v8", "MinBias 102X - Phase1 v6;MinBias 106X - Phase1 v6;MinBias 102X - Phase1 v8;MinBias 106X - Phase1 v8", col5_green_to_red);
  //sh.AddNewPostfix("VersionCompare", [&e,&v]{ return v.pf_file_add; }, "MinBias_101X_Phase1_v6;MinBias_102X_Phase1_v6;MinBias_106X_Phase1_v6;MinBias_102X_Phase1_v8;MinBias_106X_Phase1_v8", "MinBias 101X - Phase1 v6;MinBias 102X - Phase1 v6;MinBias 106X - Phase1 v6;MinBias 102X - Phase1 v8;MinBias 106X - Phase1 v8", col5_green_to_red);
  //sh.AddNewPostfix("VersionCompare", [&e,&v]{ return v.pf_file_add; }, "MinBias_102X_Phase1_v6;MinBias_106X_Phase1_v6;MinBias_106X_Phase1_v6_BothOn;MinBias_106X_Phase1_v6_NoReweighting;MinBias_106X_Phase1_v6_NoStuckTBM;MinBias_106X_Phase1_v8", "102X;106X;106X - Both On;106X - No Reweighting;106X - No Stuck TBM;106X - Phase1 v8", col6_rainbow_dark);
  sh.AddNewPostfix("VersionCompare", [&e,&v]{ return v.pf_file_add; }, "MinBias_106X_Phase1_v6;MinBias_106X_Phase1_v8;TTBar_106X_Phase1_v6;TTBar_106X_Phase1_v8", "MinBias - Phase1 v6;MinBias - Phase1 v8;TTbar   - Phase1 v6;TTbar   - Phase1 v8", col4_red_to_cyan);
  sh.AddNewPostfix("NewEffStudy",    [&e,&v]{ return v.pf_file_add; }, "TTBar_l1roc0p75;TTBar_106X_Phase1_v6;SingleMuon_Data", "TTBar - L1 75% ROC eff;TTbar - Phase1 v6;SingleMuon Data", col4_red_to_cyan);
  sh.AddNewPostfix("ALCARECOTight",  [&e,&v]{ return v.pf_file_add; }, "ALCARECOTight_allmuon;ALCARECOTight_default;RECO", "ALCARECO (all muon);ALCARECO (default);RECO", "633,601,418");
  if (debug) std::cout<<"Phase1PixelHistoMaker - postfixes ok"<<std::endl;

  //sh.AddNewPostfix("8and13TeV",     [&v]{ return v.pf_file_add; }, "MC_13TeV_25ns", "MC 13TeV (25ns)", "3");
  //const char* main = "8and13TeV";
  //const char* main1 = "DatavsMC";
  //const char* main2 = "BunchSpacing";
  //const char* main12 = "DataMCComp";
  //const char* main12 = "BestAndAllVertices";
  //const char* main12 = "DatavsMCApproval";
  //const char* main12 = "DatavsMC";
  //const char* main12 = "DataYears";
  //const char* main12 = "DatavsMC2016";
  //const char* main12 = "DatavsMC2016_2076or2208b";
  //const char* main12 = "GainCalib";
  //const char* main12 = "VCalCalib";
  //const char* main12 = "GainValidation";
  //const char* main12 = "EffLossStudy";
  //const char* main12 = "DColScan";
  //const char* main12 = "DatavsMCs2017";
  //const char* main12 = "EffLossMC";
  //const char* main12 = "DynIneffDB";
  //const char* main12 = "TBMReset";
  //const char* main12 = "DatavsMC2017";
  //const char* main12 = "SelectedNBx";
  //const char* main12 = "DatavsMC2017";
  //const char* main1 = "EffLossData";
  //const char* main2 = "EffLossMC";
  //const char* main12 = "PostTS1Cond";
  //const char* main12 = "DatavsMC2018";
  //const char* main12 = "DynIneffDBValid";
  //const char* main12 = "Run3Simulation";
  //const char* main12 = "NewEffStudy";
  //const char* main12 = "VersionCompare";
  const char* main12 = "ALCARECOTight";

  // Define histo parameters and filling variable
  // X/Y/Z - axis parameters:
  sh.AddNewFillParams("NVertices",        { .nbin=MAX_PU, .bins={    0, MAX_PU}, .fill=[&e]{ return e.nvtx; }, .axis_title="N_{Vertices}"});
  sh.AddNewFillParams("NVerticesRwg",     { .nbin=MAX_PU, .bins={    0, MAX_PU}, .fill=[&e]{ return e.nvtx; }, .axis_title="Reweighted N_{Vertices}"});
  sh.AddNewFillParams("NPileup",          { .nbin=MAX_PU, .bins={    0, MAX_PU}, .fill=[&v]{ return v.pileup; }, .axis_title="N_{Pile-up}"});
  sh.AddNewFillParams("NPileupRwg",       { .nbin=MAX_PU, .bins={    0, MAX_PU}, .fill=[&v]{ return v.pileup; }, .axis_title="N_{Pile-up}"});
  sh.AddNewFillParams("NTracks",          { .nbin=100,  .bins={      0,   1000}, .fill=[&e]{ return e.ntracks;         }, .axis_title="N_{Tracks}"});
  sh.AddNewFillParams("NTracksLay1",      { .nbin=100,  .bins={      0,   1000}, .fill=[&e]{ return e.ntrackBPix[0];   }, .axis_title="N_{Tracks crossing Layer 1}"});
  sh.AddNewFillParams("NTracksDsk1",      { .nbin=100,  .bins={      0,   1000}, .fill=[&e]{ return e.ntrackFPix[0];   }, .axis_title="N_{Tracks crossing Disk 1}"});
#if DATASTRUCT_VER > 28
  sh.AddNewFillParams("NClu",             { .nbin= 80,  .bins={      0,   8000}, .fill=[&v]{ return v.nclu;            }, .axis_title="N_{Clusters}"});
  sh.AddNewFillParams("NPix",             { .nbin=125,  .bins={      0,  25000}, .fill=[&v]{ return v.npix;            }, .axis_title="N_{Pixels}"});
  sh.AddNewFillParams("NCluBPix",         { .nbin=100,  .bins={      0,   5000}, .fill=[&v]{ return v.nclu_bpix;       }, .axis_title="N_{Clusters} - BPix"});
  sh.AddNewFillParams("NPixBPix",         { .nbin=100,  .bins={      0,  20000}, .fill=[&v]{ return v.npix_bpix;       }, .axis_title="N_{Pixels} - BPix"});
  sh.AddNewFillParams("NCluFPix",         { .nbin=100,  .bins={      0,   2000}, .fill=[&e]{ return e.nclu[0];         }, .axis_title="N_{Clusters} - FPix"});
  sh.AddNewFillParams("NPixFPix",         { .nbin=100,  .bins={      0,   5000}, .fill=[&e]{ return e.npix[0];         }, .axis_title="N_{Pixels} - FPix"});
#endif

#if PHASE == 0
  sh.AddNewFillParams("LayersDisks",      { .nbin=   7, .bins={    0.5,    7.5}, .fill=[&v]{ return v.layers_disks; }, .axis_title="", .def_range={}, .bin_labels={
					      {1, "Layer 1"}, {2, "Layer 2"}, {3, "Layer 3"}, {4, "Disk -2"},
					      {5, "Disk -1"}, {6, "Disk +1"}, {7, "Disk +2"}
					     }});
#else
  sh.AddNewFillParams("LayersDisks",      { .nbin=  10, .bins={    0.5,   10.5}, .fill=[&v]{ return v.layers_disks_phase1; }, .axis_title="", .def_range={}, .bin_labels={
					       {1, "Layer 1"}, {2, "Layer 2"}, { 3, "Layer 3"}, {4, "Layer 4"}, 
					       {5, "Disk -3"}, {6, "Disk -2"}, { 7, "Disk -1"}, 
					       {8, "Disk +1"}, {9, "Disk +2"}, {10, "Disk +3"}
					     }});
#endif

  sh.AddNewFillParams("LayersDisksInOut", { .nbin=   7, .bins={    0.5,    7.5}, .fill=[&v]{ return v.layers_disks_inout; }, .axis_title=""});
  sh.AddNewFillParams("DisksInOut",       { .nbin=   4, .bins={    0.5,    4.5}, .fill=[&v]{ return v.disks_inout;     }, .axis_title=""});
  sh.AddNewFillParams("Ladders",            { .nbin=  65, .bins={  -32.5,   32.5}, .fill=[&v]{ return v.ladder;        }, .axis_title="Ladders"});
  sh.AddNewFillParams("Modules",          { .nbin=   9, .bins={   -4.5,    4.5}, .fill=[&v]{ return v.module;          }, .axis_title="Modules"});
  sh.AddNewFillParams("Pileup",           { .nbin=  60, .bins={      0,    120}, .fill=[&v]{ return v.pileup;          }, .axis_title="Average Pile-up", .def_range={0,70}});
  //sh.AddNewFillParams("InstLumi",         { .nbin=  80, .bins={      0,     20}, .fill=[&v]{ return v.instlumi;        }, .axis_title="Instantaneous luminosity (nb^{-1}s^{-1})", .def_range={0,8}});
  sh.AddNewFillParams("InstLumi",         { .nbin=  30, .bins={      0,     30}, .fill=[&v]{ return v.instlumi;        }, .axis_title="Instantaneous luminosity [#scale[0.8]{#times10^{33}cm^{-2}s^{-1}}]", .def_range={0,20}});
  sh.AddNewFillParams("InstLumi0p5",      { .nbin=  60, .bins={      0,     30}, .fill=[&v]{ return v.instlumi;        }, .axis_title="Instantaneous luminosity [#scale[0.8]{#times10^{33}cm^{-2}s^{-1}}]", .def_range={0,20}});
  sh.AddNewFillParams("InstLumi1p0",      { .nbin=  31, .bins={   -0.5,   30.5}, .fill=[&v]{ return v.instlumi;        }, .axis_title="Instantaneous luminosity [#scale[0.8]{#times10^{33}cm^{-2}s^{-1}}]", .def_range={0,20}});
  sh.AddNewFillParams("InstLumiNorm",     { .nbin=  60, .bins={      0,     30}, .fill=[&v]{ return v.rel_fluence_l1*v.instlumi; }, .axis_title="Rel. fluence #times Inst. Lumi. [#scale[0.8]{#times10^{33}cm^{-2}s^{-1}}]", .def_range={0,20}});
  sh.AddNewFillParams("LowInstLumi",      { .nbin=  50, .bins={      0,   5000}, .fill=[&v]{ return v.instlumi*1000;   }, .axis_title="Instantaneous Luminosity [#scale[0.8]{#times10^{30}cm^{-2}s^{-1}}]", .def_range={0,2000}});
  sh.AddNewFillParams("PileupNorm",       { .nbin=  50, .bins={      0,    100}, .fill=[&v]{ return v.rel_fluence_l1*v.pileup;   }, .axis_title="Rel. fluence #times Average Pile-up", .def_range={0,70}});
  sh.AddNewFillParams("NBx",              { .nbin= 360, .bins={      0,   3600}, .fill=[&v]{ return v.nbx;             }, .axis_title="Number of bunch-crossings"});
  sh.AddNewFillParams("IntLumi",          { .nbin= 250, .bins={      0,    250}, .fill=[&v]{ return v.intlumi;         }, .axis_title="Delivered luminosity [fb^{-1}]"});
  sh.AddNewFillParams("IntLumiRunII",     { .nbin= 200, .bins={      0,    200}, .fill=[&v]{ return v.intlumi-29.9261; }, .axis_title="Delivered luminosity - Run 2 [fb^{-1}]"});
  sh.AddNewFillParams("IntLumiRunIII",    { .nbin= 212, .bins={      0,    212}, .fill=[&v]{ return v.intlumi;         }, .axis_title="Delivered luminosity - Run 3 [fb^{-1}]"});
  sh.AddNewFillParams("IntLumi2016",      { .nbin= 200, .bins={      0,    200}, .fill=[&v]{ return v.intlumi-34.1252; }, .axis_title="Delivered luminosity - 2016 [fb^{-1}]", .def_range={0,150}});
  sh.AddNewFillParams("IntLumi2017",      { .nbin= 100, .bins={      0,    200}, .fill=[&v]{ return v.intlumi;         }, .axis_title="Delivered luminosity - Phase-1 [fb^{-1}]", .def_range={0,125}});
  sh.AddNewFillParams("IntLumi2017Fine",  { .nbin=1000, .bins={      0,    200}, .fill=[&v]{ return v.intlumi;         }, .axis_title="Delivered luminosity - Phase-1 [fb^{-1}]", .def_range={0,125}});
  sh.AddNewFillParams("IntLumi2018",      { .nbin= 200, .bins={      0,    200}, .fill=[&v]{ return v.intlumi-51.671;  }, .axis_title="Delivered luminosity - 2018 [fb^{-1}]", .def_range={0,70}});
  sh.AddNewFillParams("NPixL1",           { .nbin= 100, .bins={      0,  50000}, .fill=[&e]{ return e.npix[0];         }, .axis_title="N_{Pixels} - Layer 1"});
  sh.AddNewFillParams("NCluL1",           { .nbin= 200, .bins={      0,  20000}, .fill=[&e]{ return e.nclu[0];         }, .axis_title="N_{Clusters} - Layer 1"});
  sh.AddNewFillParams("LowNCluL24",       { .nbin=  50, .bins={      0,  10000}, .fill=[&e]{ return e.nclu[1]+e.nclu[2]+e.nclu[3]; }, .axis_title="N_{Clusters} - Layer 2-4", .def_range={0,2500}});
  sh.AddNewFillParams("NCluL24",          { .nbin=  50, .bins={      0,  50000}, .fill=[&e]{ return e.nclu[1]+e.nclu[2]+e.nclu[3]; }, .axis_title="N_{Clusters} - Layer 2-4", .def_range={0,20000}});
  //sh.AddNewFillParams("Days",             { .nbin= 365, .bins={    0.5,  365.5}, .fill=[&v]{ return v.day;             }, .axis_title="Days"});
  //sh.AddNewFillParams("Months",           { .nbin=  12, .bins={    0.5,   12.5}, .fill=[&v]{ return v.month;           }, .axis_title="Months"});
  sh.AddNewFillParams("Days",             { .nbin= 366, .bins={    0,  366 *86400}, .fill=[&v]{ return v.time;             }, .axis_title="",     .def_range={100*86400, 150*86400} });
  sh.AddNewFillParams("Weeks",            { .nbin=  53, .bins={    0,  53*7*86400}, .fill=[&v]{ return v.weektime;         }, .axis_title="Week", .def_range={100*86400, 150*86400} });
  sh.AddNewFillParams("Months",           { .nbin=  12, .bins={   0  *86400, 31 *86400, 59 *86400, 90 *86400,
								 120*86400, 151*86400, 181*86400, 212*86400,
								 243*86400, 273*86400, 304*86400, 334*86400, 365*86400
		       }, .fill=[&v]{ return v.monthtime; }, .axis_title="", .def_range={90*86400, 365*86400} });
  sh.AddNewFillParams("Time_Fill5934",    { .nbin= 150, .bins={      3,      8}, .fill=[&e] {
					      double time  = -9999;
					      if      (e.run==298853) time =  2.9758 + e.ls*0.006476;
					      else if (e.run==298854) time =  6.7722 + e.ls*0.006476;
					      else if (e.run==298855) time =  7.2825 + e.ls*0.006476;
					      return time;
					    }, .axis_title="Time - Fill 5934 (h)"});
  sh.AddNewFillParams("Time_Fill5942",    { .nbin=  90, .bins={      7,     10}, .fill=[&e] {
					      double time  = -9999;
					      if      (e.run==298996) time =  7.3792 + e.ls*0.006476;
					      else if (e.run==298997) time =  8.8508 + e.ls*0.006476;
					      else if (e.run==298998) time =  9.1822 + e.ls*0.006476;
					      else if (e.run==299000) time =  9.3122 + e.ls*0.006476;
					      return time;
					    }, .axis_title="Time - Fill 5934 (h)"});

  sh.AddNewFillParams("TriggerRate_Fill5934",    { .nbin= 120, .bins={       0,   120}, .fill=[&e] {
						     double time  = -9999;
						     if      (e.run==298853) time =  2.9758 + e.ls*0.006476;
						     else if (e.run==298854) time =  6.7722 + e.ls*0.006476;
						     else if (e.run==298855) time =  7.2825 + e.ls*0.006476;
						     double rate = -1;
						     if      (time>=3.00&&time<3.10) rate =   4;
						     else if (time>=3.10&&time<3.25) rate =  13;
						     else if (time>=3.25&&time<3.37) rate =  30;
						     else if (time>=3.37&&time<3.45) rate =  -1;
						     else if (time>=3.45&&time<4.00) rate =  29;
						     else if (time>=4.00&&time<4.50) rate =  28;
						     else if (time>=4.50&&time<5.00) rate =  27;
						     else if (time>=5.00&&time<5.25) rate =  25;
						     else if (time>=5.25&&time<5.50) rate =  24;
						     else if (time>=5.50&&time<5.60) rate =  -1;
						     else if (time>=5.60&&time<5.75) rate =  14;
						     else if (time>=5.75&&time<6.75) rate =  12;
						     else if (time>=6.75&&time<6.80) rate =  -1;
						     else if (time>=5.80&&time<6.90) rate =  45;
						     else if (time>=6.90&&time<7.11) rate =  85;
						     else if (time>=7.11&&time<7.40) rate = 103;
						     else if (time>=7.40)            rate = 100;
						     return rate;
						   }, .axis_title="Trigger Rate [kHz]"});

  sh.AddNewFillParams("TriggerRate_Fill5942",    { .nbin= 120, .bins={       0,   120}, .fill=[&e] {
						     double time  = -9999;
						     if      (e.run==298996) time =  7.3792 + e.ls*0.006476;
						     else if (e.run==298997) time =  8.8508 + e.ls*0.006476;
						     else if (e.run==298998) time =  9.1822 + e.ls*0.006476;
						     else if (e.run==299000) time =  9.3122 + e.ls*0.006476;
						     double rate = -1;
						     if      (time>=7.00&&time<7.50) rate =   4;
						     else if (time>=7.50&&time<7.57) rate =  23;
						     else if (time>=7.57&&time<7.63) rate =  -1;
						     else if (time>=7.63&&time<7.70) rate =  71;
						     else if (time>=7.70&&time<7.76) rate =  70;
						     else if (time>=7.76&&time<7.83) rate =  69;
						     else if (time>=7.83&&time<7.92) rate =  -1;
						     else if (time>=7.92&&time<8.06) rate =  68;
						     else if (time>=8.06&&time<8.20) rate =  67;
						     else if (time>=8.20&&time<8.35) rate =  65;
						     else if (time>=8.35&&time<8.49) rate =  64;
						     else if (time>=8.49&&time<8.63) rate =  63;
						     else if (time>=8.63&&time<8.78) rate =  62;
						     else if (time>=8.78&&time<8.90) rate =  -1;
						     else if (time>=8.90&&time<8.95) rate =  31;
						     else if (time>=8.95&&time<9.06) rate =  30;
						     else if (time>=9.12&&time<9.16) rate =  29;
						     return rate;
						   }, .axis_title="Trigger Rate [kHz]"});
  sh.AddNewFillParams("TrigRate",         { .nbin= 150, .bins={       0,   150}, .fill=[&v]{ return v.l1rate;          }, .axis_title="Trigger Rate [kHz]"});
  sh.AddNewFillParams("TriggerRate",      { .nbin=  30, .bins={       0,   150}, .fill=[&v]{ return v.l1rate;          }, .axis_title="Trigger Rate [kHz]"});
  sh.AddNewFillParams("TriggerRateBins",  { .nbin=  15, .bins={       0,   150}, .fill=[&v]{ return v.l1rate;          }, .axis_title="Trigger Rate [kHz]"});
  sh.AddNewFillParams("NCollPerTrig",     { .nbin= 200, .bins={      0, 100000}, .fill=[&v]{ return v.ncoll_per_trig;  }, .axis_title="Avg. N_{Collisions} / Trigger latency"});
  
  sh.AddNewFillParams("OnCluSize",        { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&t]{ return t.clu.size;        }, .axis_title="on-track cluster size [pixel]", .def_range={0,20}});
  sh.AddNewFillParams("OnCluSizeX",       { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&t]{ return t.clu.sizeX;       }, .axis_title="on-track cluster size x [pixel]"});
  sh.AddNewFillParams("OnCluSizeY",       { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&t]{ return t.clu.sizeY;       }, .axis_title="on-track cluster size y [pixel]"});
  //sh.AddNewFillParams("OnCluCharge",      { .nbin=  50, .bins={      0,    500}, .fill=[&v]{ return v.clu_charge;      }, .axis_title="on-track cluster charge [ke]"});
  //sh.AddNewFillParams("OnCluChargeNorm",  { .nbin=  40, .bins={      0,    200}, .fill=[&t]{ return t.norm_charge;     }, .axis_title="norm. on-trk clu. charge [ke]"});
  sh.AddNewFillParams("OnCluCharge",      { .nbin=  500, .bins={      0,    500}, .fill=[&v]{ return v.clu_charge;      }, .axis_title="on-track cluster charge [ke]"});
  sh.AddNewFillParams("OnCluChargeNorm",  { .nbin=  400, .bins={      0,    200}, .fill=[&t]{ return t.norm_charge;     }, .axis_title="norm. on-trk clu. charge [ke]"});
  sh.AddNewFillParams("CluSize",          { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&c]{ return c.size;            }, .axis_title="Cluster size [pixel]"});
  sh.AddNewFillParams("CluSizeX",         { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&c]{ return c.sizeX;           }, .axis_title="Cluster size x [pixel]"});
  sh.AddNewFillParams("CluSizeY",         { .nbin=  26, .bins={   -0.5,   25.5}, .fill=[&c]{ return c.sizeY;           }, .axis_title="Cluster size y [pixel]"});
  sh.AddNewFillParams("CluCharge",        { .nbin=  50, .bins={      0,    500}, .fill=[&c]{ return c.charge/1e3;      }, .axis_title="Cluster charge [ke]", .def_range={0, 200}});
  sh.AddNewFillParams("MCDColEff",        { .nbin=1001, .bins={-0.0005, 1.0005}, .fill=[&v]{ return v.dcol_eff;        }, .axis_title="DCol Efficiency"});
  sh.AddNewFillParams("BunchCrossing5",   { .nbin= 720, .bins={      0,   3600}, .fill=[&e]{ return e.bx;              }, .axis_title="Bunch-crossing"});
  sh.AddNewFillParams("BunchCrossing12",  { .nbin= 300, .bins={      0,   3600}, .fill=[&e]{ return e.bx;              }, .axis_title="Bunch-crossing"});
  sh.AddNewFillParams("BunchCrossing60",  { .nbin=  60, .bins={      0,   3600}, .fill=[&e]{ return e.bx;              }, .axis_title="Bunch-crossing"});
  sh.AddNewFillParams("NBxPerTrig",       { .nbin=  80, .bins={      0,   2000}, .fill=[&v]{ return v.nbx_per_trig;    }, .axis_title="Avg. N_{Bunch-crossing} / Trigger latency"});
  sh.AddNewFillParams("NColPerTrig",      { .nbin= 200, .bins={      0, 100000}, .fill=[&v]{ return v.ncol_per_trig;   }, .axis_title="Avg. N_{Collisions} / Trigger latency"});
  sh.AddNewFillParams("Runs",             { .nbin= 170, .bins={ 246000, 263000}, .fill=[&e]{ return e.run;             }, .axis_title="Runs"});
  sh.AddNewFillParams("LumiSection",      { .nbin= 100, .bins={      0,  10000}, .fill=[&e]{ return e.ls;              }, .axis_title="LumiSection", .def_range={0,1000}});
  sh.AddNewFillParams("LS",               { .nbin= 2000,.bins={      0,   2000}, .fill=[&e]{ return e.ls;              }, .axis_title="LumiSection", .def_range={0,500}});
  sh.AddNewFillParams("RunIntLumi",       { .nbin= 100, .bins={      0,   1000}, .fill=[&v]{ return v.intlumi_run;     }, .axis_title="Integrated Luminosity - Run [1/pb]"});
  sh.AddNewFillParams("TMuon",            { .nbin=  10, .bins={    -40,     60}, .fill=[&e]{ return e.tmuon;           }, .axis_title="t_{muon} @ Int. Point (ns)"});
#if PHASE == 0
  sh.AddNewFillParams("ROCLadders",       { .nbin= 136, .bins={    -34,     34}, .fill=[&v]{ return v.roc_ladder;      }, .axis_title="Ladders"});
  sh.AddNewFillParams("ROCModules",       { .nbin=  72, .bins={   -4.5,    4.5}, .fill=[&v]{ return v.roc_module;      }, .axis_title="Modules"});
  sh.AddNewFillParams("ROCBladesInner",   { .nbin=  72, .bins={    0.5,   12.5}, .fill=[&v]{ return v.roc_blade;       }, .axis_title="Blades in Inner Halves"});
  sh.AddNewFillParams("ROCBladesOuter",   { .nbin=  72, .bins={  -12.5,   -0.5}, .fill=[&v]{ return v.roc_blade;       }, .axis_title="Blades in Outer Halves"});
  sh.AddNewFillParams("ROCSideDiskPanel", { .nbin=  72, .bins={  -4.5,     4.5}, .bin_labels={
					      { 1, "Disk-2 Pnl2"}, { 9, "Disk-2 Pnl1"}, {19, "Disk-1 Pnl2"}, {27, "Disk-1 Pnl1"},
					      {41, "Disk+1 Pnl1"}, {49, "Disk+1 Pnl2"}, {59, "Disk+2 Pnl1"}, {67, "Disk+2 Pnl2"}
					    }, .fill=[&v]{ return v.roc_sdp;         }, .axis_title="" });
  sh.AddNewFillParams("ROCBinX",       { .nbin=  64, .bins={      1,     65}, .fill=[&v]{ return v.rocbin_x;      }, .axis_title="ROC Bin-X"});
  sh.AddNewFillParams("ROCBinY",       { .nbin=  84, .bins={      1,     85}, .fill=[&v]{ return v.rocbin_y;      }, .axis_title="ROC Bin-Y"});
  sh.AddNewFillParams("ROCNumber",     { .nbin=15840,.bins={      0,  15840}, .fill=[&v]{ return v.roc_number;    }, .axis_title="ROC number"});
#elif PHASE == 1
  sh.AddNewFillParams("ROC_L1_Ladder",        { .nbin=  26, .bins={  -6.5,     6.5}, .fill=[&v]{ return v.ladder_coord;                  }, .axis_title="Layer 1 - ROC / Ladder"});
  sh.AddNewFillParams("ROC_L2_Ladder",        { .nbin=  58, .bins={ -14.5,    14.5}, .fill=[&v]{ return v.ladder_coord;                  }, .axis_title="Layer 2 - ROC / Ladder"});
  sh.AddNewFillParams("ROC_L3_Ladder",        { .nbin=  90, .bins={ -22.5,    22.5}, .fill=[&v]{ return v.ladder_coord;                  }, .axis_title="Layer 3 - ROC / Ladder"});
  sh.AddNewFillParams("ROC_L4_Ladder",        { .nbin= 130, .bins={ -32.5,    32.5}, .fill=[&v]{ return v.ladder_coord;                  }, .axis_title="Layer 4 - ROC / Ladder"});
  sh.AddNewFillParams("Module",               { .nbin=  72, .bins={  -4.5,     4.5}, .fill=[&v]{ return v.module_coord;                  }, .axis_title="ROC / Module"});
  sh.AddNewFillParams("ROC_Ring1_BladePanel", { .nbin=  92, .bins={ -11.5,    11.5}, .fill=[&v]{ return v.blade_panel_coord-v.blade*0.5; }, .axis_title="Ring 1 - ROC / Blade"});
  sh.AddNewFillParams("ROC_Ring2_BladePanel", { .nbin= 140, .bins={ -17.5,    17.5}, .fill=[&v]{ return v.blade_panel_coord;             }, .axis_title="Ring 2 - ROC / Blade"});
  sh.AddNewFillParams("Disk",                 { .nbin=  56, .bins={  -3.5,     3.5}, .fill=[&v]{ return v.disk_coord;                    }, .axis_title="ROC / Disk"});
#endif
  
  sh.AddNewFillParams("TrkPt",            { .nbin=  21, .bins={0, 0.2, 0.4, 0.6, 0.8, 1, 1.5, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 25, 30, 50, 100, 500}, .fill=[&t]{ return t.trk.pt; }, .axis_title="Track p_{T} (GeV/c)", .def_range={0.2,12} });
  sh.AddNewFillParams("TrkNStrip",        { .nbin=  18, .bins={0, 2, 4, 6, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25, 35, 50}, .fill=[&t]{ return t.trk.strip; }, .axis_title="N_{strip hits}"});
  sh.AddNewFillParams("TrkD0",            { .nbin=  11, .bins={0, 0.001, 0.002, 0.005, 0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 2, 20}, .fill=[&t]{ return fabs(t.trk.d0); }, .axis_title="Track Impact Parameter D0 (cm)"});
  sh.AddNewFillParams("TrkDZ",            { .nbin=  10, .bins={0, 0.002, 0.005, 0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 2, 20}, .fill=[&t]{ return fabs(t.trk.dz); }, .axis_title="Track Impact Parameter DZ (cm)"});
  sh.AddNewFillParams("TrackPt",          { .nbin= 200, .bins={0, 20},     .fill=[&t]{ return t.trk.pt;      }, .axis_title="Track p_{T} (GeV)", .def_range={0,2} });
  sh.AddNewFillParams("TrackEta",         { .nbin=  52, .bins={-2.6, 2.6}, .fill=[&t]{ return t.trk.eta; }, .axis_title="Track #eta" });
  sh.AddNewFillParams("TrackAlpha",       { .nbin=  64, .bins={   0, 1.6}, .fill=[&t]{ return std::abs(3.1416/2 - std::abs(t.alpha)); }, .axis_title="Track #alpha" });
  sh.AddNewFillParams("TrackBeta",        { .nbin=  32, .bins={   0, 1.6}, .fill=[&t]{ return std::abs(3.1416/2 - std::abs(t.beta));  }, .axis_title="Track #beta" });
  sh.AddNewFillParams("TrackBetaBins",    { .nbin=  16, .bins={   0, 1.6}, .fill=[&t]{ return std::abs(3.1416/2 - std::abs(t.beta));  }, .axis_title="Track #beta" });
  sh.AddNewFillParams("TrackTheta",       { .nbin=  32, .bins={   0, 1.6}, .fill=[&v]{ return v.theta;                                }, .axis_title="Track #theta" });
  sh.AddNewFillParams("TrackNStrip",      { .nbin=  50, .bins={0, 50},     .fill=[&t]{ return t.trk.strip;   }, .axis_title="N_{strip hits}",    .def_range={0,30} });
  sh.AddNewFillParams("TrackD0",          { .nbin= 100, .bins={0, 1},      .fill=[&t]{ return fabs(t.trk.d0); }, .axis_title="Track Impact Parameter D0 (cm)", .def_range={0, 0.5} });
  sh.AddNewFillParams("TrackDZ",          { .nbin= 200, .bins={0, 2},      .fill=[&t]{ return fabs(t.trk.dz); }, .axis_title="Track Impact Parameter DZ (cm)", .def_range={0, 1.0} });
  sh.AddNewFillParams("ValidPixHit",      { .nbin=  15, .bins={      0,     15}, .fill=[&t]{ return t.trk.validpixhit[0]+t.trk.validpixhit[1]; }, .axis_title="Valid pixel hits" });
  sh.AddNewFillParams("NTimeoutEvt",      { .nbin=  51, .bins={   -0.5,   50.5}, .fill=[&v]{ return v.n_timeout;       }, .axis_title="N_{Time-out}/Event"});
  sh.AddNewFillParams("NOverflowEvt",     { .nbin=  51, .bins={   -0.5,   50.5}, .fill=[&v]{ return v.n_overflow;      }, .axis_title="N_{Overflow}/Event"});
  sh.AddNewFillParams("TimeoutMod",       { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&v]{ return v.federr_mod==1;   }, .axis_title="Time-out/Module"});
  sh.AddNewFillParams("OverflowMod",      { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&v]{ return v.federr_mod==2;   }, .axis_title="Overflow/Module"});
  sh.AddNewFillParams("DClu",             { .nbin= 200, .bins={      0,  10000}, .fill=[&t]{ return t.missing ? t.d_cl*1e4 : NOVAL_F; }, .axis_title="Distance of nearest cluster (#mum)", .def_range={0, 2000} });
#if DATASTRUCT_VER >= 109
  sh.AddNewFillParams("DClu2",            { .nbin= 200, .bins={      0,  10000}, .fill=[&t]{ return t.missing ? t.d_cl2*1e4 : NOVAL_F; }, .axis_title="Distance of 2nd nearest cluster (#mum)", .def_range={0, 2000} });
#endif
  sh.AddNewFillParams("DXClu",            { .nbin= 200, .bins={      0,  10000}, .fill=[&t]{ return t.missing ? t.dx_cl*1e4 : NOVAL_F; }, .axis_title="#DeltaX nearest cluster (#mum)",     .def_range={0, 2000} });
  sh.AddNewFillParams("DYClu",            { .nbin= 200, .bins={      0,  10000}, .fill=[&t]{ return t.missing ? t.dy_cl*1e4 : NOVAL_F; }, .axis_title="#DeltaY nearest cluster (#mum)",     .def_range={0, 2000} });
  sh.AddNewFillParams("DTraj",            { .nbin= 200, .bins={      0,     10}, .fill=[&t]{ return t.d_tr; }, .axis_title="Distance of nearest trajectory (cm)", .def_range={0, 2} });
#if DATASTRUCT_VER >= 108
  sh.AddNewFillParams("DSimHit",          { .nbin= 200, .bins={      0,     10}, .fill=[&t]{ return std::sqrt(t.dx_simhit*t.dx_simhit+t.dy_simhit*t.dy_simhit)*10; }, .axis_title="Distance of nearest simhit (mm)", .def_range={0, 2} });
  sh.AddNewFillParams("DRSimTrk",         { .nbin= 200, .bins={      0,     10}, .fill=[&t]{ return t.dr_simtrk; }, .axis_title="#DeltaR_{sim-track}",   .def_range={0, 2} });
  sh.AddNewFillParams("DRTrk",            { .nbin= 200, .bins={      0,     10}, .fill=[&t]{ return t.dr_trk;    }, .axis_title="#DeltaR_{other track}", .def_range={0, 2} });
#endif
  sh.AddNewFillParams("FPixR",            { .nbin=  40, .bins={      0,     20}, .fill=[&t]{
                                               if (t.glz<25) return -9999.;
                                               return (double)std::sqrt(t.glx*t.glx+t.gly*t.gly); 
                                             }, .axis_title="Hit R (cm)", .def_range={4, 17} });
  if (debug) std::cout<<"Phase1PixelHistoMaker - normal fillparams ok"<<std::endl;

  // Special Y/Z axis parameters:
  //sh.AddSpecial({ .name="DColEfficiency", .name_plus_1d="Validhit", .axis="DCol Efficiency", .axis_plus_1d="Valid Hit"});
  //sh.AddSpecial({ .name="HitEfficiency",  .name_plus_1d="ValidHitOld", .axis="Hit Efficiency (old)",  .axis_plus_1d="Valid Hit (old)"});
  sh.AddSpecial({ .name="HitEfficiency",  .name_plus_1d="ValidHitOld", .axis="Hit Efficiency",  .axis_plus_1d="Valid Hit"});
  sh.AddSpecial({ .name="DColEfficiency",  .name_plus_1d="ColParity", .axis="Double Column Efficiency",  .axis_plus_1d="First Pixel Column Parity"});
#if PHASE == 0
  // Recover missing hits within 500 um
  //sh.AddNewFillParams("DColEfficiency",   { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t]{ return t.missing==1 ? t.clust_near : 1; }, .axis_title="DCol Efficiency" });  
  sh.AddNewFillParams("HitEfficiency",    { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t]{ return t.missing==1 ? t.clust_near : 1; }, .axis_title="Hit Efficiency (old)", .def_range={0.9, 1} });
#else
  // Recover missing hits within 1 mm - Currently does not work
  //sh.AddNewFillParams("DColEfficiency",   { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t]{ return t.missing==1 ? t.d_cl>=0 && t.d_cl<DCL_MISSING : 1; }, .axis_title="DCol Efficiency" });  
  //sh.AddNewFillParams("HitEfficiency",    { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t]{ return t.missing==1 ? t.d_cl>=0 && t.d_cl<DCL_MISSING : 1; }, .axis_title="Hit Efficiency (old)", .def_range={0.9, 1} });
  sh.AddNewFillParams("HitEfficiency",    { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t]{ return t.missing==1 ? t.d_cl>=0 && t.d_cl<DCL_MISSING : 1; }, .axis_title="Hit Efficiency", .def_range={0.9, 1} });
  sh.AddNewFillParams("DColEfficiency",   { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t]{ if (t.clu.size!=2) return -1; if (((int)t.clu.pix[0][1])%52>=50||((int)t.clu.pix[0][1])%52<2) return -1; return (((int)t.clu.pix[0][1])%52)%2; }, .axis_title="Double Column Efficiency", .def_range={0, 1} });
#endif
  sh.AddSpecial({ .name="NewHitEfficiency",  .name_plus_1d="ValidHit", .axis="Hit Efficiency",  .axis_plus_1d="Valid Hit"});
  sh.AddNewFillParams("NewHitEfficiency", { .nbin=   2, .bins={   -0.5,    1.5}, .fill=[&t,&c]
                                                                                    { return t.missing!=1 ? 1 : 
                                                                                      t.d_cl>=0 && (c.mod_on.det==0 && std::abs(t.trk.eta)>= 1.0 ? 
                                                                                                    t.d_cl<DCL_MISSING_NEW : t.d_cl<0.05); 
                                                                                    }, .axis_title="Hit Efficiency", .def_range={0.7, 1} });
  if (debug) std::cout<<"Phase1PixelHistoMaker - special fillparams ok"<<std::endl;

  // Define Cuts here:
  sh.AddNewCut("Nvtx",                [&v]{ return v.cut_nvtx;             });
  sh.AddNewCut("ZeroBias",            [&v]{ return v.cut_zb;               });
  //sh.AddNewCut("ZeroBias",            [&v]{ return 1;                      });
  sh.AddNewCut("Random",              [&e]{ return (e.trig>>2)&1;          });
  sh.AddNewCut("EffCuts",             [&v]{ return v.effcut_all;           });
  sh.AddNewCut("EffCutsAllROC",       [&v]{ return v.effcut_allmod;        });
  sh.AddNewCut("EffCutsScans",        [&v]{ return v.effcut_scans;         });
  sh.AddNewCut("EffCutsNoNStrip",     [&v]{ return v.effcut_nstrip;        });
  sh.AddNewCut("EffCutsNoPt",         [&v]{ return v.effcut_pt;            });
  sh.AddNewCut("EffCutsNoD0",         [&v]{ return v.effcut_d0;            });
  sh.AddNewCut("EffCutsNoDZ",         [&v]{ return v.effcut_dz;            });
  sh.AddNewCut("EffCutsNoFederr",     [&v]{ return v.effcut_federr;        });
  sh.AddNewCut("EffCutsNoHitSep",     [&v]{ return v.effcut_hitsep;        });
  sh.AddNewCut("EffCutsNoBeta",       [&v]{ return v.effcut_beta;          });
  sh.AddNewCut("NewEffCuts",          [&v]{ return v.new_effcut_all;       });
  sh.AddNewCut("NewEffCutsPreSel",    [&v]{ return v.new_effcut_presel;    });
  sh.AddNewCut("NewEffCutsNoD0",      [&v]{ return v.new_effcut_d0;        });
  sh.AddNewCut("NewEffCutsNoDZ",      [&v]{ return v.new_effcut_dz;        });
  sh.AddNewCut("NewEffCutsNoPt",      [&v]{ return v.new_effcut_pt;        });
  sh.AddNewCut("NewEffCutsNoNStrip",  [&v]{ return v.new_effcut_nstrip;    });
  sh.AddNewCut("NewEffCutsNoHitSep",  [&v]{ return v.new_effcut_hitsep;    });
  sh.AddNewCut("NewEffCutsNoMuon",    [&v]{ return v.new_effcut_muon;      });
  sh.AddNewCut("DColEffCuts",         [&v]{ return v.dcol_effcut_all;      });
  sh.AddNewCut("DColEffCutsNoValPix", [&v]{ return v.dcol_effcut_valpix;   });
  sh.AddNewCut("DColEffCutsNoPt",     [&v]{ return v.dcol_effcut_pt;       });
  sh.AddNewCut("DColEffCutsNoD0",     [&v]{ return v.dcol_effcut_d0;       });
  sh.AddNewCut("DColEffCutsNoDZ",     [&v]{ return v.dcol_effcut_dz;       });
  sh.AddNewCut("DColEffCutsNoAlpha",  [&v]{ return v.dcol_effcut_alpha;    });
  sh.AddNewCut("DColEffCutsNoBeta",   [&v]{ return v.dcol_effcut_beta;     });
  sh.AddNewCut("BPix",                [&v]{ return v.is_bpix;              });
  sh.AddNewCut("FPix",                [&v]{ return v.is_fpix;              });
  sh.AddNewCut("FPixInner",           [&v]{ return v.is_fpix_inner;        });
  sh.AddNewCut("FPixOuter",           [&v]{ return v.is_fpix_outer;        });
  sh.AddNewCut("Lay1",                [&v]{ return v.layer==1;             });
  sh.AddNewCut("Lay2",                [&v]{ return v.layer==2;             });
  sh.AddNewCut("Lay3",                [&v]{ return v.layer==3;             });
  sh.AddNewCut("Lay4",                [&v]{ return v.layer==4;             });
  sh.AddNewCut("Ring1",               [&v]{ return v.ring==1;              });
  sh.AddNewCut("Ring2",               [&v]{ return v.ring==2;              });
  sh.AddNewCut("Data",                [&v]{ return v.is_data;              });
  sh.AddNewCut("MC",                  [&v]{ return !v.is_data;             });
  sh.AddNewCut("Run203002",           [&v]{ return v.is_run203002;         });
  sh.AddNewCut("NStrip>10",           [&t]{ return t.trk.strip>10;         });
  sh.AddNewCut("Pt>0.6GeV",           [&t]{ return t.trk.pt>0.6;           });
  sh.AddNewCut("Pt>1.0GeV",           [&t]{ return t.trk.pt>1.0;           });
  sh.AddNewCut("MainFills",           [&v]{ return v.main_filling_schemes; });
  sh.AddNewCut("HighPU",              [&v]{ return v.cut_highpu;           });
  sh.AddNewCut("GlobalMuon",          [&e]{ return e.tmuon!=-9999;         });
  sh.AddNewCut("Lay3",                [&v]{ return v.pf_layers==2;         });
  sh.AddNewCut("ValidHit",            [&t]{ return t.validhit==1; });
  //sh.AddNewCut("ValidHit",            [&t]{ return t.clu.size>0;           });
  sh.AddNewCut("CluSize>1",           [&c]{ return c.size>1;               });
  sh.AddNewCut("OnCluSize>1",         [&t]{ return t.clu.size>1;           });
  sh.AddNewCut("NoNoiseCosmics",      [&c]{ 
		 if (c.mod_on.layer==2 && c.mod_on.module==-4 && c.mod_on.ladder==  9) return 0;
		 if (c.mod_on.layer==2 && c.mod_on.module== 2 && c.mod_on.ladder== 10) return 0;
		 if (c.mod_on.layer==2 && c.mod_on.module== 4 && c.mod_on.ladder== -2) return 0;
		 if (c.mod_on.layer==3 && c.mod_on.module==-2 && c.mod_on.ladder== 18) return 0;
		 if (c.mod_on.layer==3 && c.mod_on.module==-1 && c.mod_on.ladder== -1) return 0;
		 if (c.mod_on.layer==3 && c.mod_on.module==-4 && c.mod_on.ladder== -7) return 0;
		 if (c.mod_on.layer==3 && c.mod_on.module== 3 && c.mod_on.ladder==-17) return 0;
		 if (c.mod_on.layer==3 && c.mod_on.module== 3 && c.mod_on.ladder== 16) return 0;
		 if (c.mod_on.layer==3 && c.mod_on.module==-1 && c.mod_on.ladder== 11) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module==-1 && c.mod_on.ladder==-26) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module==-1 && c.mod_on.ladder==-11) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module== 1 && c.mod_on.ladder== 16) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module== 4 && c.mod_on.ladder== 32) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module==-4 && c.mod_on.ladder==-22) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module==-3 && c.mod_on.ladder==-22) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module==-4 && c.mod_on.ladder==-29) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module==-4 && c.mod_on.ladder==-31) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module== 2 && c.mod_on.ladder==-26) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module==-3 && c.mod_on.ladder== 17) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module== 1 && c.mod_on.ladder==  1) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module== 2 && c.mod_on.ladder==  8) return 0;
		 if (c.mod_on.layer==4 && c.mod_on.module== 4 && c.mod_on.ladder==  9) return 0;
		 if (c.mod_on.disk==-3 && c.mod_on.ring==1 && c.mod_on.blade== -3 && c.mod_on.panel==1) return 0;
		 return 1;
	       });
  sh.AddNewCut("HasLay2ValidHit", [&t]{ return t.trk.validbpix[1]>0;   });
  sh.AddNewCut("ExclRing34",      [&t]{ if (t.mod_on.det==1) return true; else return (abs(t.mod_on.module)<3); });
  sh.AddNewCut("Phase1History",      [&v]{ 
		 //if (v.intlumi) return 0;
		 return 1;
	       });

  
  sh.AddNewCut("Run247992&&LS>182",   [&e]{ return e.run==247992&&e.ls>182; });
  if (debug) std::cout<<"Phase1PixelHistoMaker - cuts ok"<<std::endl;

  // ROC Curves
  /*
  // GenParticles for GenTruth matching
  std::map<std::string, std::function<int()> > gen_leptons;
  gen_leptons["Truth_SimTrack"] = [] { return (int)muMatchGenMuFromW[i_Muon]; };
  // GenTruth for Leptons
  sh.AddNewFillParams("GenTruth_SimTrk", { .nbin= 2, .bins={-0.5,1.5}, .fill=[&t] { return return; }});
  // cuts not for comparison
  sh.AddNewFillParams("mupt5_cut",            { .nbin=1,  .bins={5 ,5000}, .fill=[&d] { return d.Muon[i_Muon].pt; }, .axis_title="p_{T}^{#mu}", .def_range={5, 5000}});
  sh.AddNewFillParams("mueta_cut",            { .nbin=1,  .bins={1,2}, .fill=[&d] { return std::abs(d.Muon[i_Muon].eta)<2.4; }, .axis_title="#eta_{#mu}", .def_range={1,2}});
  sh.AddNewFillParams("muip_loose_cut",       { .nbin=1,  .bins={1,2}, .fill=[&d] { return std::abs(d.Muon[i_Muon].dz)<0.50&&std::abs(d.Muon[i_Muon].dxy)<0.2; }, .axis_title="vtx. d_{xy,#mu}/d_{z,#mu}", .def_range={1,2}});
  sh.AddNewFillParams("muip_medium_cut",      { .nbin=1,  .bins={1,2}, .fill=[&d] { return std::abs(d.Muon[i_Muon].dz)<0.10&&std::abs(d.Muon[i_Muon].dxy)<0.05; }, .axis_title="vtx. d_{xy,#mu}/d_{z,#mu}", .def_range={1,2}});
  sh.AddNewFillParams("muip_tight_cut",       { .nbin=1,  .bins={1,2}, .fill=[&d] { return std::abs(d.Muon[i_Muon].dz)<0.10&&std::abs(d.Muon[i_Muon].dxy)<0.05&&d.Muon[i_Muon].sip3d<4; }, .axis_title="vtx. d_{xy,#mu}/d_{z,#mu}", .def_range={1,2}});
  sh.AddNewFillParams("muminiiso_loose_cut",  { .nbin=1,  .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].miniPFRelIso_all<0.4; }, .axis_title="#mu Mini iso.", .def_range={1,2}});
  sh.AddNewFillParams("muminiiso_medium_cut", { .nbin=1,  .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].miniPFRelIso_all<0.2; }, .axis_title="#mu Mini iso.", .def_range={1,2}});
  sh.AddNewFillParams("muid_soft_cut",        { .nbin=1,  .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].softId; }, .axis_title="Soft (Cut-based) ID", .def_range={1,2}});
  sh.AddNewFillParams("muid_medium_cut",      { .nbin=1,  .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].mediumId; }, .axis_title="Medium (Cut-based) ID", .def_range={1,2}});
  sh.AddNewFillParams("muid_tight_cut",       { .nbin=1,  .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].tightId; }, .axis_title="Tight (Cut-based) ID", .def_range={1,2}});
  sh.AddNewFillParams("muid_mva_loose_cut",   { .nbin=1,  .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].mvaId>0; }, .axis_title="#mu MVA Loose ID", .def_range={1,2}});
  sh.AddNewFillParams("muid_mva_medium_cut",  { .nbin=1,  .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].mvaId>1; }, .axis_title="#mu MVA Medium ID", .def_range={1,2}});
  // pt/eta - can easily be tuned
  // pt      - black 1
  // eta     - green 418
  sh.AddNewFillParams("mupt5",                   { .nbin=23,  .bins={0,5,10,15,20,25,30,35,40,45,50,60,70,80,100,125,150,200,250,300,400,500,1000,5000}, .fill=[&d] { return d.Muon[i_Muon].pt; }, .axis_title="p_{T}^{#mu}", .def_range={5, 5000, 1}});
  // impact parameters - simple pick
  // ip      - green 418;
  sh.AddNewFillParams("muip_loose",              { .nbin=3, .bins={1,4}, .fill=[&d] {
                                                      if      (std::abs(d.Muon[i_Muon].dz)>=0.50||std::abs(d.Muon[i_Muon].dxy)>=0.20) return 0;
                                                      else if (std::abs(d.Muon[i_Muon].dz)>=0.10||std::abs(d.Muon[i_Muon].dxy)>=0.05) return 1;
                                                      else if (d.Muon[i_Muon].sip3d>=4) return 2;
                                                      else                              return 3; 
                                                    }, .axis_title="Impact param.", .def_range={0.9,4, 418}});
  sh.AddNewFillParams("muip_medium",             { .nbin=3, .bins={1,4}, .fill=[&d] {
                                                      if      (std::abs(d.Muon[i_Muon].dz)>=0.50||std::abs(d.Muon[i_Muon].dxy)>=0.20) return 0;
                                                      else if (std::abs(d.Muon[i_Muon].dz)>=0.10||std::abs(d.Muon[i_Muon].dxy)>=0.05) return 1;
                                                      else if (d.Muon[i_Muon].sip3d>=4) return 2;
                                                      else                              return 3; 
                                                    }, .axis_title="Impact param.", .def_range={2,4, 418}});
  sh.AddNewFillParams("muip_tight",              { .nbin=3, .bins={1,4}, .fill=[&d] {
                                                      if      (std::abs(d.Muon[i_Muon].dz)>=0.50||std::abs(d.Muon[i_Muon].dxy)>=0.20) return 0;
                                                      else if (std::abs(d.Muon[i_Muon].dz)>=0.10||std::abs(d.Muon[i_Muon].dxy)>=0.05) return 1;
                                                      else if (d.Muon[i_Muon].sip3d>=4) return 2;
                                                      else                              return 3; 
                                                    }, .axis_title="Impact param.", .def_range={3,4, 418}});
  // isolations - mini iso recommended, but we can cross-check others
  // pfiso   - yellow 402
  // miniiso - orange 801
  // 2diso   - gray   921
  sh.AddNewFillParams("mupfiso",                 { .nbin=8, .bins={-1,7}, .fill=[&d] { return d.Muon[i_Muon].pfIsoId; }, .axis_title="#mu PF iso.", .def_range={0,7}}); 
  sh.AddNewFillParams("muminiiso",               { .nbin=4, .bins={1,5}, .fill=[&d] {
                                                      float miniIso = d.Muon[i_Muon].miniPFRelIso_all;
                                                      if      (miniIso>=0.40) return 0;
                                                      else if (miniIso>=0.20) return 1;
                                                      else if (miniIso>=0.10) return 2;
                                                      else if (miniIso>=0.05) return 3;
                                                      else                    return 4;
                                                    }, .axis_title="Mini iso.", .def_range={0,5, 801}});
  sh.AddNewFillParams("muminiiso_loose",         { .nbin=4, .bins={1,5}, .fill=[&d] {
                                                      float miniIso = d.Muon[i_Muon].miniPFRelIso_all;
                                                      if      (miniIso>=0.40) return 0;
                                                      else if (miniIso>=0.20) return 1;
                                                      else if (miniIso>=0.10) return 2;
                                                      else if (miniIso>=0.05) return 3;
                                                      else                    return 4;
                                                    }, .axis_title="Mini iso.", .def_range={0.9,5, 801}});
  sh.AddNewFillParams("muminiiso_medium",        { .nbin=4, .bins={1,5}, .fill=[&d] {
                                                      float miniIso = d.Muon[i_Muon].miniPFRelIso_all;
                                                      if      (miniIso>=0.40) return 0;
                                                      else if (miniIso>=0.20) return 1;
                                                      else if (miniIso>=0.10) return 2;
                                                      else if (miniIso>=0.05) return 3;
                                                      else                    return 4;
                                                    }, .axis_title="Mini iso.", .def_range={2,5, 801}});
  // id with/without isolation
  // id      - cyan to red 434,601,618,633
  sh.AddNewFillParams("muid_soft_comp",          { .nbin=1, .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].softId; }, .axis_title="Soft (Cut-based) ID", .def_range={0,  2, 434}});
  sh.AddNewFillParams("muid_soft",               { .nbin=1, .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].softId; }, .axis_title="Soft (Cut-based) ID", .def_range={0.9,2, 434}});
  sh.AddNewFillParams("muid_medium_comp",        { .nbin=2, .bins={1,3}, .fill=[&d] { 
                                                      if      (!d.Muon[i_Muon].mediumId)       return 0;
                                                      else if (!d.Muon[i_Muon].mediumPromptId) return 1;
                                                      else                                     return 2;
                                                    }, .axis_title="Medium (Cut-based) ID", .def_range={0,3, 601}});
  sh.AddNewFillParams("muid_medium",             { .nbin=2, .bins={1,3}, .fill=[&d] { 
                                                      if      (!d.Muon[i_Muon].mediumId)       return 0;
                                                      else if (!d.Muon[i_Muon].mediumPromptId) return 1;
                                                      else                                     return 2;
                                                    }, .axis_title="Medium (Cut-based) ID", .def_range={0.9,3, 601}});
  sh.AddNewFillParams("muid_tight_comp",         { .nbin=1, .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].tightId; }, .axis_title="Tight (Cut-based) ID", .def_range={0,  2, 618}});
  sh.AddNewFillParams("muid_tight",              { .nbin=1, .bins={1,2}, .fill=[&d] { return d.Muon[i_Muon].tightId; }, .axis_title="Tight (Cut-based) ID", .def_range={0.9,2, 618}});
  sh.AddNewFillParams("muid_mva",                { .nbin=3, .bins={1,4}, .fill=[&d] { return d.Muon[i_Muon].mvaId; }, .axis_title="MVA ID", .def_range={0,  4, 633}});
  sh.AddNewFillParams("muid_mva_loose",          { .nbin=3, .bins={1,4}, .fill=[&d] { return d.Muon[i_Muon].mvaId; }, .axis_title="MVA ID", .def_range={0.9,4, 633}});
  sh.AddNewFillParams("muid_mva_medium",         { .nbin=3, .bins={1,4}, .fill=[&d] { return d.Muon[i_Muon].mvaId; }, .axis_title="MVA ID", .def_range={2,  4, 633}});
  sh.AddNewFillParams("muid_mva_tight",          { .nbin=3, .bins={1,4}, .fill=[&d] { return d.Muon[i_Muon].mvaId; }, .axis_title="MVA ID", .def_range={3,  4, 633}});
  */

 
  // --------------------------------------------------------------------------
  //                           Vertex Reweighting
  
  sh.SetHistoWeights({});
  std::function<void()> add_special_histos = [&sh]{};
  std::vector<std::string> AllCluCuts      = {"ZeroBias","Nvtx"};
  std::vector<std::string> OnCluCutsPt0p6  = {"ZeroBias","Nvtx","Pt>0.6GeV","ValidHit"};
  std::vector<std::string> OnCluCutsPt1p0  = {"ZeroBias","Nvtx","Pt>1.0GeV","ValidHit"};
  //std::vector<std::string> AllCluCuts      = {"NoNoiseCosmics","CluSize>1"};
  //std::vector<std::string> OnCluCutsPt0p6  = {"Pt>0.6GeV","ValidHit"};
  //std::vector<std::string> OnCluCutsPt1p0  = {"Pt>1.0GeV","ValidHit"};
  std::vector<double> pu_weights;
  
  if (!BADROC_RUN) {
    sh.AddHistos("evt", { .fill="NVertices",   .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="", .opt="LogNorm", .ranges={0,50, 0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NPileup",     .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="", .opt="LogNorm", .ranges={0,50, 0,0, 0.5,0.9} });
  
#if PU_REWEIGHT_MC == 1
    bool norm = 0; // Normalize also to the number of events in Data
    //TFile *f_data = TFile::Open("input/pileup_data_2232b_80mb.root");
    //TFile *f_data = TFile::Open("input/pileup_data_2232b_69mb.root");
    //TFile *f_data = TFile::Open("input/pileup_data_Fill5026_5078_2076b_71p3mb.root");
    //TFile *f_data = TFile::Open("input/pileup_data_Fill5026_5078_5105_2076b_71p3mb.root");
    //TFile *f_data = TFile::Open("input/pileup_data_Fill6024_2544b_78p1mb.root"); // 2017
    TFile *f_data = TFile::Open("input/pileup_data_Fill6024_2544b_78p1mb.root"); // 2018
    TH1D* Data = (TH1D*)f_data->Get("pileup");
    TH1D* MC = new TH1D("mc_pileup","",100,0,100);
    for (int pu=0; pu<=MAX_PU; ++pu) MC->Fill(pu);
    if (Data!=0&&MC!=0) {
      if (!norm) {
        if (Data->Integral()>0) Data->Scale(1/Data->Integral());
        if (MC->Integral()>0) MC->Scale(1/MC->Integral());
      }
      //std::cout<<"Pileup weights:\n";
      for (int npu=0; npu<MAX_PU; ++npu) {
        pu_weights.push_back(MC->GetBinContent(npu+1)>0 ? Data->GetBinContent(npu+1) / MC->GetBinContent(npu+1) : 0);
        //std::cout<<"Npu="<<npu<<" weight="<<pu_weights[npu]<<std::endl;
      }
    }
    f_data->Close();
    // Set weights for all Histos, except Background estimate, where MC is scaled to MC_Expected_IntLumi_invfb
    sh.SetHistoWeights({[&v,&pu_weights]{
  			 if (v.is_data==1) return (double)1;
  			 else if (v.pileup>=0&&v.pileup<MAX_PU) return pu_weights[(int)v.pileup];
  			 else return (double)0;
  		       }});
#endif
    if (debug) std::cout<<"Phase1PixelHistoMaker - reweighting ok"<<std::endl;
    
    //__________________________________________________________________________________
    //                           New Hit Efficiency Plots
    
    sh.SetHistoWeights({});
#if DATASTRUCT_VER >= 108
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_LayersDisks", .pfs={},       .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1", .opt="", .ranges={0,0, 0.7,1} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_LayersDisks", .pfs={main12}, .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1", .opt="", .ranges={0,0, 0.7,1} });
#endif
    if (debug) std::cout<<"Phase1PixelHistoMaker - new hiteff plots ok"<<std::endl;
    // ---------------------------------------------------------------------------------
    //                             Histogram Definitions
    //__________________________________________________________________________________
    //
    //                                  Event Plots
    
#if PU_REWEIGHT_MC == 1
    sh.AddHistos("evt", { .fill="NVerticesRwg", .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,60, 0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NPileupRwg",   .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,60, 0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NTracks",      .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,0,  0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NTracksLay1",  .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,0,  0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NTracksDsk1",  .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,0,  0,0, 0.5,0.9} });
#if DATASTRUCT_VER > 28
    sh.AddHistos("evt", { .fill="NClu",         .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,0,  0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NPix",         .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,0,  0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NCluBPix",     .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,0,  0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NPixBPix",     .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,0,  0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NCluFPix",     .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,0,  0,0, 0.5,0.9} });
    sh.AddHistos("evt", { .fill="NPixFPix",     .pfs={main12}, .cuts={"ZeroBias","Nvtx"}, .draw="HIST", .opt="LogNorm", .ranges={0,0,  0,0, 0.5,0.9} });
#endif
#endif
    
    // Federror stuff (evt)
    sh.AddHistos("evt", { .fill="AvgNTimeoutEvt_vs_InstLumi",          .pfs={"DataYears"},               .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={0,0} });
    sh.AddHistos("evt", { .fill="AvgNTimeoutEvt_vs_Pileup",            .pfs={"DataYears"},               .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={0,25, 0,0, 0.15,0.7} });
    sh.AddHistos("evt", { .fill="AvgNTimeoutEvt_vs_Pileup",            .pfs={"NBx","DataYears"}, .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={0,25, 0,0, 0.15,0.7} });
    sh.AddHistos("evt", { .fill="AvgNTimeoutEvt_vs_NBx",               .pfs={"DataYears"},               .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={} });
    sh.AddHistos("evt", { .fill="AvgNTimeoutEvt_vs_BunchCrossing60",   .pfs={"DataYears"},               .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={} });
    sh.AddHistos("evt", { .fill="AvgNTimeoutEvt_vs_BunchCrossing60",   .pfs={"NBx","DataYears"}, .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={} });
    sh.AddHistos("evt", { .fill="AvgNOverflowEvt_vs_InstLumi",         .pfs={"DataYears"},               .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={0,0} });
    sh.AddHistos("evt", { .fill="AvgNOverflowEvt_vs_Pileup",           .pfs={"DataYears"},               .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.15,0.7} });
    sh.AddHistos("evt", { .fill="AvgNOverflowEvt_vs_Pileup",           .pfs={"NBx","DataYears"}, .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.15,0.7} });
    sh.AddHistos("evt", { .fill="AvgNOverflowEvt_vs_NBx",              .pfs={"DataYears"},               .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={} });
    sh.AddHistos("evt", { .fill="AvgNOverflowEvt_vs_BunchCrossing60",  .pfs={"DataYears"},               .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={} });
    sh.AddHistos("evt", { .fill="AvgNOverflowEvt_vs_BunchCrossing60",  .pfs={"NBx","DataYears"}, .cuts={"ZeroBias","Nvtx"}, .draw="PE1", .opt="", .ranges={} });
    
    // Federror stuff (traj)
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={"FedErrorEvent", "DataYears"}, .cuts={"ZeroBias","EffCutsNoFederr"}, .draw="PE1", .opt="", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={"FedErrorModule","DataYears"}, .cuts={"ZeroBias","EffCutsNoFederr"}, .draw="PE1", .opt="", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="AvgTimeoutMod_vs_InstLumi",           .pfs={"LayersDisks",   "DataYears"}, .cuts={"ZeroBias","Nvtx"},            .draw="PE1", .opt="TwoCol43", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="AvgTimeoutMod_vs_Pileup",             .pfs={"LayersDisks",   "DataYears"}, .cuts={"ZeroBias","Nvtx"},            .draw="PE1", .opt="TwoCol43", .ranges={0,25,  0,0} });
    sh.AddHistos("traj", { .fill="AvgTimeoutMod_vs_NBx",                .pfs={"LayersDisks",   "DataYears"}, .cuts={"ZeroBias","Nvtx"},            .draw="PE1", .opt="TwoCol43", .ranges={0,0,  0,0} });
    sh.AddHistos("traj", { .fill="AvgTimeoutMod_vs_BunchCrossing60",    .pfs={"LayersDisks",   "DataYears"}, .cuts={"ZeroBias","Nvtx"},            .draw="PE1", .opt="TwoCol43", .ranges={0,0,  0,0} });
    sh.AddHistos("traj", { .fill="AvgOverflowMod_vs_InstLumi",          .pfs={"LayersDisks",   "DataYears"}, .cuts={"ZeroBias","Nvtx"},            .draw="PE1", .opt="TwoCol43", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="AvgOverflowMod_vs_Pileup",            .pfs={"LayersDisks",   "DataYears"}, .cuts={"ZeroBias","Nvtx"},            .draw="PE1", .opt="TwoCol43", .ranges={0,25,  0,0} });
    sh.AddHistos("traj", { .fill="AvgOverflowMod_vs_NBx",               .pfs={"LayersDisks",   "DataYears"}, .cuts={"ZeroBias","Nvtx"},            .draw="PE1", .opt="TwoCol43", .ranges={0,0,  0,0} });
    sh.AddHistos("traj", { .fill="AvgOverflowMod_vs_BunchCrossing60",   .pfs={"LayersDisks",   "DataYears"}, .cuts={"ZeroBias","Nvtx"},            .draw="PE1", .opt="TwoCol43", .ranges={0,0,  0,0} }); 

    sh.AddHistos("evt", { .fill="NBx",                                  .pfs={"DataYears"},                  .cuts={"ZeroBias","Nvtx"},            .draw="HIST",.opt="", .ranges={0,0, 0,0} });

    // Average L2-4 Cluster occupancy vs InstLumi
    sh.AddHistos("evt", { .fill="AvgLowNCluL24_vs_LowInstLumi",         .pfs={"DataYears"},                  .cuts={"ZeroBias"},                   .draw="PE1",.opt="", .ranges={0,0, 0,0} });
    sh.AddHistos("evt", { .fill="AvgNCluL24_vs_InstLumi",               .pfs={"DataYears"},                  .cuts={"ZeroBias"},                   .draw="PE1",.opt="", .ranges={0,0, 0,0} });
    sh.AddHistos("evt", { .fill="AvgLowNCluL24_vs_LowInstLumi",         .pfs={main12,"DataYears"},           .cuts={"ZeroBias"},                   .draw="PE1",.opt="", .ranges={0,0, 0,0} });
    sh.AddHistos("evt", { .fill="AvgNCluL24_vs_InstLumi",               .pfs={main12,"DataYears"},           .cuts={"ZeroBias"},                   .draw="PE1",.opt="", .ranges={0,0, 0,0} });
    if (debug) std::cout<<"Phase1PixelHistoMaker - event plots ok"<<std::endl;
    
    //__________________________________________________________________________________
    //
    //                     Cluster Plots (traj - on-track, clust - all)
    
#if PHASE == 0
    // Occupancy
    sh.AddHistos("clust", { .fill="ROCLadders_vs_ROCModules",           .pfs={main12,"Layers"},  .cuts=AllCluCuts,             .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("clust", { .fill="ROCBladesInner_vs_ROCSideDiskPanel", .pfs={main12},           .cuts={"ZeroBias","FPixInner"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("clust", { .fill="ROCBladesOuter_vs_ROCSideDiskPanel", .pfs={main12},           .cuts={"ZeroBias","FPixOuter"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("traj",  { .fill="ROCLadders_vs_ROCModules",           .pfs={main12,"Layers","OnTrack"}, .cuts={"ZeroBias","ValidHit"},             .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("traj",  { .fill="ROCBladesInner_vs_ROCSideDiskPanel", .pfs={main12,"OnTrack"},          .cuts={"ZeroBias","ValidHit","FPixInner"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("traj",  { .fill="ROCBladesOuter_vs_ROCSideDiskPanel", .pfs={main12,"OnTrack"},          .cuts={"ZeroBias","ValidHit","FPixOuter"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("clust", { .fill="ROCBinY_vs_ROCBinX",                 .pfs={main12,"LayersAllDisks"},  .cuts=AllCluCuts,             .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
#elif PHASE == 1
#if CLUST_LOOP==1
    sh.AddHistos("clust", { .fill="ROC_L1_Ladder_vs_Module",                             .pfs={main12},          .cuts={"ZeroBias","Nvtx","Lay1"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("clust", { .fill="ROC_L2_Ladder_vs_Module",                             .pfs={main12},          .cuts={"ZeroBias","Nvtx","Lay2"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("clust", { .fill="ROC_L3_Ladder_vs_Module",                             .pfs={main12},          .cuts={"ZeroBias","Nvtx","Lay3"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("clust", { .fill="ROC_L4_Ladder_vs_Module",                             .pfs={main12},          .cuts={"ZeroBias","Nvtx","Lay4"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("clust", { .fill="ROC_Ring1_BladePanel_vs_Disk",                        .pfs={main12},          .cuts={"ZeroBias","Nvtx","Ring1"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("clust", { .fill="ROC_Ring2_BladePanel_vs_Disk",                        .pfs={main12},          .cuts={"ZeroBias","Nvtx","Ring2"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
#endif
    sh.AddHistos("traj", { .fill="ROC_L1_Ladder_vs_Module",                             .pfs={main12,"OnTrack"},          .cuts={"ZeroBias","Nvtx","Pt>1.0GeV","ValidHit","Lay1"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("traj", { .fill="ROC_L2_Ladder_vs_Module",                             .pfs={main12,"OnTrack"},          .cuts={"ZeroBias","Nvtx","Pt>1.0GeV","ValidHit","Lay2"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("traj", { .fill="ROC_L3_Ladder_vs_Module",                             .pfs={main12,"OnTrack"},          .cuts={"ZeroBias","Nvtx","Pt>1.0GeV","ValidHit","Lay3"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("traj", { .fill="ROC_L4_Ladder_vs_Module",                             .pfs={main12,"OnTrack"},          .cuts={"ZeroBias","Nvtx","Pt>1.0GeV","ValidHit","Lay4"},  .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("traj", { .fill="ROC_Ring1_BladePanel_vs_Disk",                        .pfs={main12,"OnTrack"},          .cuts={"ZeroBias","Nvtx","Pt>1.0GeV","ValidHit","Ring1"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
    sh.AddHistos("traj", { .fill="ROC_Ring2_BladePanel_vs_Disk",                        .pfs={main12,"OnTrack"},          .cuts={"ZeroBias","Nvtx","Pt>1.0GeV","ValidHit","Ring2"}, .draw="COLZ", .opt="Log", .ranges={0,0, 0,0, 0,0} });
#endif
    
    // Distributions
    // Historical plots (Data, Use pt>1.0)
    // Years
    sh.AddHistos("clust", { .fill="CluSize",         .pfs={"DataYears","LayersAllDisks"},              .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={"DataYears","LayersAllDisks"},              .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,10, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={"DataYears","LayersAllDisks"},              .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluCharge",       .pfs={"DataYears","LayersAllDisks"},              .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={ 0,250, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"DataYears","LayersAllDisks"},              .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={"DataYears","MainFills","LayersAllDisks"},  .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={  0,10, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={"DataYears","MainFills","LayersAllDisks"},  .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"DataYears","LayersAllDisks"},              .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={  0,60, 0,0, 0.6,0.8} });
    // Months
    sh.AddHistos("clust", { .fill="CluSize",         .pfs={"Layers", "DataYears","Months"},           .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={"Layers", "DataYears","Months"},           .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,10, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={"Layers", "DataYears","Months"},           .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluCharge",       .pfs={"Layers", "DataYears","Months"},           .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={ 0,250, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSize",         .pfs={"DisksRings","DataYears","Months"},           .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={"DisksRings","DataYears","Months"},           .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,10, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={"DisksRings","DataYears","Months"},           .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluCharge",       .pfs={"DisksRings","DataYears","Months"},           .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={ 0,250, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSize",         .pfs={"Months",    "DataYears","LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={"Months",    "DataYears","LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,10, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={"Months",    "DataYears","LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("clust", { .fill="CluCharge",       .pfs={"Months",    "DataYears","LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={ 0,250, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"Layers","DataYears","Months"},           .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={"Layers","DataYears","MainFills","Months"},.cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,10, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={"Layers","DataYears","MainFills","Months"},.cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"Layers","DataYears","Months"},           .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,60, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"DisksRings","DataYears","Months"},           .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={"DisksRings","DataYears","MainFills","Months"},.cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,10, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={"DisksRings","DataYears","MainFills","Months"},.cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"DisksRings","DataYears","Months"},           .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,60, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"Months",    "DataYears","LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={"Months",    "DataYears","MainFills","LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,10, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={"Months",    "DataYears","MainFills","LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,20, 0,0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"Months",    "DataYears","LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm",  .ranges={  0,60, 0,0, 0.6,0.8} });
    // New Modules (Data)
    //sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"NewModules","Layers","DataYears","MainFills"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={ 0,20, 0,0, 0.6,0.8} });
    //sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={"NewModules","Layers","DataYears","MainFills"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={ 0,20, 0,0, 0.6,0.8} });
    //sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={"NewModules","Layers","DataYears","MainFills"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={ 0,20, 0,0, 0.6,0.8} });
    //sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"NewModules","Layers","DataYears","MainFills"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={ 0,60, 0,0, 0.6,0.8} });
    //sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"NewModules","Layers","DataYears","IntLumiRunII"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={ 0,20, 0,0, 0.6,0.8} });
    //sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"NewModules","Layers","DataYears","IntLumiRunII"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={ 0,60, 0,0, 0.6,0.8} });
    
    // Comparison
    sh.AddHistos("clust", { .fill="CluCharge",       .pfs={main12,"LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluCharge",       .pfs={main12,"Layers","Mods" }, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSize",         .pfs={main12,"LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSize",         .pfs={main12,"Layers","Mods" }, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={main12,"LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={main12,"Layers","Mods" }, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={main12,"LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={main12,"Layers","Mods" }, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    
    sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={main12,"LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=CMSprelim+"Norm", .ranges={ 0,60, 0,0.09, 0.55,0.7} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={main12,"Layers","Mods" }, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,60, 0,   0, 0.55,0.7} });
    sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={main12,"LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=CMSprelim+"Norm", .ranges={ 0,20, 0,0.35, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={main12,"Layers","Mods" }, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,20, 0,   0, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={main12,"LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=CMSprelim+"Norm", .ranges={ 0,20, 0,0.80, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={main12,"Layers","Mods" }, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,20, 0,   0, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={main12,"LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=CMSprelim+"Norm", .ranges={ 0,20, 0,0.35, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={main12,"Layers","Mods" }, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,20, 0,   0, 0.5,0.75} });

    // Layers/Disks
    sh.AddHistos("clust", { .fill="CluCharge",       .pfs={"Layers",main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluCharge",       .pfs={"DisksRings",  main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluCharge",       .pfs={"AllDisks",    main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSize",         .pfs={"Layers",main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSize",         .pfs={"DisksRings",  main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSize",         .pfs={"AllDisks",    main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={"Layers",main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={"DisksRings",  main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={"AllDisks",    main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={"Layers",main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={"DisksRings",  main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={"AllDisks",    main12}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0, 0.6,0.9} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"Layers",main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,60, 0,   0, 0.55,0.7} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"DisksRings",  main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,60, 0,   0, 0.55,0.7} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"AllDisks",    main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=CMSprelim+"Norm", .ranges={ 0,60, 0,0.09, 0.55,0.7} });
    sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"Layers",main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,20, 0,   0, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"DisksRings",  main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,20, 0,   0, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"AllDisks",    main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=CMSprelim+"Norm", .ranges={ 0,20, 0,0.35, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={"Layers",main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,20, 0,   0, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={"DisksRings",  main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,20, 0,   0, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={"AllDisks",    main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=CMSprelim+"Norm", .ranges={ 0,20, 0,0.80, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={"Layers",main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,20, 0,   0, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={"DisksRings",  main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=          "Norm", .ranges={ 0,20, 0,   0, 0.5,0.75} });
    sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={"AllDisks",    main12}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt=CMSprelim+"Norm", .ranges={ 0,20, 0,0.35, 0.5,0.75} });
    if (debug) std::cout<<"Phase1PixelHistoMaker - normal cluster plots ok"<<std::endl;

    // Time evolution plots (Data)
    std::vector<std::string> time_types = {"InstLumi", "LowInstLumi", "Pileup", "NCluL24", "LowNCluL24", "IntLumi2017", "IntLumi2017Fine", "IntLumi2018", "IntLumi", "IntLumiRunIII", "Months", "Weeks", "Days"/*, "Runs"*/ };
    //std::vector<std::string> plot_pfs   = {"LayersDisks", "DisksRings", "AllDisks", "BPixFPix"};
    std::vector<std::string> plot_pfs   = {"Layers", "Disks", "Rings", "DisksRings", "Ring1Disks", "Ring2Disks", "AllDisks", "BPixFPix"};
    std::vector<double> xmins = {  0, 0, 0, 0,  0,  0, 0, 0, 0, 0, 0 };
    std::vector<double> xmaxs = {  0, 0, 0, 0,  0,  0, 0, 0, 0, 0, 0 };
    for (size_t i=0, n=time_types.size(); i<n; ++i) {
      std::string time = time_types[i];
      //double xmin = xmins[i], xmax = xmaxs[i];
      double xmin = 0, xmax = 0; // use defaults
      //std::string prelim = "";
      std::string prelim = CMSprelim;
      std::string prelim17 = prelim2017;
      std::vector<std::string> onclucuts = OnCluCutsPt1p0;
      for (std::string plot_pf : plot_pfs) {
	      std::string opts = (time_types[i]=="Months"||time_types[i]=="Days") ? "Months" : (time_types[i]=="Weeks") ? "Weeks" : "";
	      double x1 = 0.1;
	      if (plot_pf=="LayersDisksOldNew") {
	        opts += "TwoCol53";
	        x1 = 0;
	      } else if (plot_pf=="LayersDisks") {
	        opts += "TwoCol43";
	        x1 = 0;
	      }
	      // Layers/Disks
	      // All Clusters
	      if (time_types[i]=="IntLumi2017"||time_types[i]=="IntLumi2017Fine"||time_types[i]=="IntLumi2018"||time_types[i]=="IntLumi"||time_types[i]=="IntLumiRunIII") {
	        // IntLumi
	        sh.AddHistos("clust", { .fill=std::string("AvgCluCharge_vs_")+time,       .pfs={plot_pf},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,  20, 80, 0.55+x1,0.91} });
	        sh.AddHistos("clust", { .fill=std::string("CluChargeMPV_vs_")+time,       .pfs={plot_pf},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,   0, 60, 0.50+x1,0.80} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSize_vs_")+time,         .pfs={plot_pf},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,   0,  6, 0.55+x1,0.35} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeX_vs_")+time,        .pfs={plot_pf},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax, 1.2,2.5, 0.55+x1,0.35} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeY_vs_")+time,        .pfs={plot_pf},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax, 0.0,4.0, 0.55+x1,0.35} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluCharge_vs_")+time,       .pfs={plot_pf,"InstLumi"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,  20, 80, 0.55+x1,0.91} });
	        sh.AddHistos("clust", { .fill=std::string("CluChargeMPV_vs_")+time,       .pfs={plot_pf,"InstLumi"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,   0, 60, 0.50+x1,0.80} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSize_vs_")+time,         .pfs={plot_pf,"InstLumi"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,   0,  6, 0.55+x1,0.35} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeX_vs_")+time,        .pfs={plot_pf,"InstLumi"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax, 1.2,2.5, 0.55+x1,0.35} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeY_vs_")+time,        .pfs={plot_pf,"InstLumi"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax, 0.0,4.0, 0.55+x1,0.35} });
	      } else if (time_types[i]=="Months"||time_types[i]=="Weeks"||time_types[i]=="Days") {
	        // Date
	        sh.AddHistos("clust", { .fill=std::string("AvgCluCharge_vs_")+time,       .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,  25, 55, 0.30+x1,0.60} });
	        sh.AddHistos("clust", { .fill=std::string("CluChargeMPV_vs_")+time,       .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,   0, 60, 0.50+x1,0.80} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSize_vs_")+time,         .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,   2,  5, 0.30+x1,0.50} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeX_vs_")+time,        .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax, 1.8,2.4, 0.30+x1,0.63} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeY_vs_")+time,        .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax, 1.0,4.0, 0.30+x1,0.45} });
	      } else {
	        // InstLumi/Pileup
	        sh.AddHistos("clust", { .fill=std::string("AvgCluCharge_vs_")+time,       .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,  25, 55, 0.30+x1,0.60} });
	        sh.AddHistos("clust", { .fill=std::string("CluChargeMPV_vs_")+time,       .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,   0, 60, 0.50+x1,0.80} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSize_vs_")+time,         .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,   2,  5, 0.30+x1,0.50} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeX_vs_")+time,        .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 1.8,2.4, 0.30+x1,0.63} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeY_vs_")+time,        .pfs={plot_pf,"DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 1.0,4.0, 0.30+x1,0.45} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluCharge_vs_")+time,       .pfs={plot_pf,"DataYears","MainFills"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,  25, 55, 0.30+x1,0.60} });
	        sh.AddHistos("clust", { .fill=std::string("CluChargeMPV_vs_")+time,       .pfs={plot_pf,"DataYears","MainFills"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,   0, 60, 0.50+x1,0.80} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSize_vs_")+time,         .pfs={plot_pf,"DataYears","MainFills"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,   2,  5, 0.30+x1,0.50} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeX_vs_")+time,        .pfs={plot_pf,"DataYears","MainFills"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 1.8,2.4, 0.30+x1,0.63} });
	        sh.AddHistos("clust", { .fill=std::string("AvgCluSizeY_vs_")+time,        .pfs={plot_pf,"DataYears","MainFills"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 1.0,4.0, 0.30+x1,0.45} });
	      }
	      // On-Trk Clusters
	      if (time_types[i]=="IntLumi2017"||time_types[i]=="IntLumi2017Fine"||time_types[i]=="IntLumi2018") {
	        // IntLumi
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluChargeNorm_vs_")+time, .pfs={plot_pf},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax,  10, 30, 0.30+x1,0.30} });
	        sh.AddHistos("traj",  { .fill=std::string("OnCluChargeNormMPV_vs_")+time, .pfs={plot_pf},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax,   5, 25, 0.30+x1,0.30} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSize_vs_")+time,       .pfs={plot_pf},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax, 2.0,5.5, 0.30+x1,0.30} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeX_vs_")+time,      .pfs={plot_pf},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax, 1.4,2.6, 0.55+x1,0.91} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeY_vs_")+time,      .pfs={plot_pf},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax, 0.0,4.5, 0.50+x1,0.60} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluChargeNorm_vs_")+time, .pfs={plot_pf,"InstLumi"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax,   0, 50, 0.55+x1,0.65} });
	        sh.AddHistos("traj",  { .fill=std::string("OnCluChargeNormMPV_vs_")+time, .pfs={plot_pf,"InstLumi"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax,   8, 28, 0.20+x1,0.35} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSize_vs_")+time,       .pfs={plot_pf,"InstLumi"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax, 0.0,5.0, 0.55+x1,0.35} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeX_vs_")+time,      .pfs={plot_pf,"InstLumi"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax, 1.4,2.2, 0.55+x1,0.91} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeY_vs_")+time,      .pfs={plot_pf,"InstLumi"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim+"Wide", .ranges={xmin,xmax, 0.0,4.5, 0.55+x1,0.35} });
	      } else if (time_types[i]=="Months"||time_types[i]=="Weeks"||time_types[i]=="Days") {
	        // Date
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluChargeNorm_vs_")+time, .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,   0, 50, 0.35+x1,0.65} });
	        sh.AddHistos("traj",  { .fill=std::string("OnCluChargeNormMPV_vs_")+time, .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax,   8, 20, 0.55+x1,0.90} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSize_vs_")+time,       .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax, 0.0,5.0, 0.55+x1,0.35} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeX_vs_")+time,      .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax, 1.2,2.0, 0.35+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeY_vs_")+time,      .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim, .ranges={xmin,xmax, 1.0,4.0, 0.35+x1,0.65} });
	      } else {
	        // InstLumi/Pileup
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluChargeNorm_vs_")+time, .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,   0, 40, 0.15+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("OnCluChargeNormMPV_vs_")+time, .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,   8, 20, 0.15+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSize_vs_")+time,       .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 0.0,5.0, 0.15+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeX_vs_")+time,      .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 0.5,2.5, 0.15+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeY_vs_")+time,      .pfs={plot_pf,"DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 0.0,5.0, 0.15+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluChargeNorm_vs_")+time, .pfs={plot_pf,"DataYears","MainFills"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,   0, 40, 0.15+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("OnCluChargeNormMPV_vs_")+time, .pfs={plot_pf,"DataYears","MainFills"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax,   8, 20, 0.15+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSize_vs_")+time,       .pfs={plot_pf,"DataYears","MainFills"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 0.0,5.0, 0.15+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeX_vs_")+time,      .pfs={plot_pf,"DataYears","MainFills"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 0.5,2.5, 0.15+x1,0.40} });
	        sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeY_vs_")+time,      .pfs={plot_pf,"DataYears","MainFills"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts+prelim17, .ranges={xmin,xmax, 0.0,5.0, 0.15+x1,0.40} });
	      }
      }
      //++  // New Modules
      //++  // All Clusters
      //++  sh.AddHistos("clust", { .fill=std::string("AvgCluCharge_vs_")+time,       .pfs={"NewModules","Layers","DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts, .ranges={xmin,xmax, 0,60, 0.6,0.8} });
      //++  sh.AddHistos("clust", { .fill=std::string("CluChargeMPV_vs_")+time,       .pfs={"NewModules","Layers","DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts, .ranges={xmin,xmax, 0,60, 0.6,0.8} });
      //++  sh.AddHistos("clust", { .fill=std::string("AvgCluSize_vs_")+time,         .pfs={"NewModules","Layers","DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts, .ranges={xmin,xmax, 0,5,  0.6,0.8} });
      //++  sh.AddHistos("clust", { .fill=std::string("AvgCluSizeX_vs_")+time,        .pfs={"NewModules","Layers","DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts, .ranges={xmin,xmax, 0,5,  0.6,0.8} });
      //++  sh.AddHistos("clust", { .fill=std::string("AvgCluSizeY_vs_")+time,        .pfs={"NewModules","Layers","DataYears"},  .cuts=AllCluCuts, .draw="PE1", .opt=opts, .ranges={xmin,xmax, 0,5,  0.6,0.8} });
      //++  // On-Trk Clusters
      //++  if (i==0) {
      //++    sh.AddHistos("traj",  { .fill=std::string("AvgOnCluChargeNorm_vs_")+time, .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax,   0, 50, 0.6,0.65} });
      //++    sh.AddHistos("traj",  { .fill=std::string("OnCluChargeNormMPV_vs_")+time, .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax,  16, 20, 0.6,0.65} });
      //++    sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSize_vs_")+time,       .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax, 3.0,5.0, 0.6,0.65} });
      //++    sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeX_vs_")+time,      .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax, 1.5,2.5, 0.6,0.65} });
      //++    sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeY_vs_")+time,      .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax, 2.5,4.5, 0.6,0.65} });
      //++  } else {
      //++    sh.AddHistos("traj",  { .fill=std::string("AvgOnCluChargeNorm_vs_")+time, .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax,   0, 50, 0.6,0.65} });
      //++    sh.AddHistos("traj",  { .fill=std::string("OnCluChargeNormMPV_vs_")+time, .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax,  16, 20, 0.6,0.65} });
      //++    sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSize_vs_")+time,       .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax, 3.0,5.0, 0.6,0.65} });
      //++    sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeX_vs_")+time,      .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax, 1.5,2.5, 0.6,0.65} });
      //++    sh.AddHistos("traj",  { .fill=std::string("AvgOnCluSizeY_vs_")+time,      .pfs={"NewModules","Layers","DataYears"},  .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt=opts, .ranges={xmin,xmax, 2.5,4.5, 0.6,0.65} });
      //++  }
    }
    
    // Data vs MC
    sh.AddHistos("traj",  { .fill="AvgCluCharge_vs_InstLumi",           .pfs={main12,"Layers"}, .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNormMPV_vs_InstLumi",     .pfs={main12,"Layers"}, .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });

    sh.AddHistos("traj",  { .fill="AvgCluSize_vs_InstLumi",             .pfs={main12,"Layers"}, .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeX_vs_InstLumi",            .pfs={main12,"Layers"}, .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeY_vs_InstLumi",            .pfs={main12,"Layers"}, .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgCluSize_vs_InstLumi",             .pfs={main1,"Layers"},  .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgCluSizeX_vs_InstLumi",            .pfs={main1,"Layers"},  .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgCluSizeY_vs_InstLumi",            .pfs={main1,"Layers"},  .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgCluSize_vs_InstLumi",             .pfs={main2,"Layers"},  .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgCluSizeX_vs_InstLumi",            .pfs={main2,"Layers"},  .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgCluSizeY_vs_InstLumi",            .pfs={main2,"Layers"},  .cuts=AllCluCuts,     .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSize_vs_InstLumi",           .pfs={main12,"Layers"}, .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeX_vs_InstLumi",          .pfs={main12,"Layers"}, .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeY_vs_InstLumi",          .pfs={main12,"Layers"}, .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgOnCluSize_vs_InstLumi",           .pfs={main1,"Layers"},  .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgOnCluSizeX_vs_InstLumi",          .pfs={main1,"Layers"},  .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgOnCluSizeY_vs_InstLumi",          .pfs={main1,"Layers"},  .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgOnCluSize_vs_InstLumi",           .pfs={main2,"Layers"},  .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgOnCluSizeX_vs_InstLumi",          .pfs={main2,"Layers"},  .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
  //sh.AddHistos("traj",  { .fill="AvgOnCluSizeY_vs_InstLumi",          .pfs={main2,"Layers"},  .cuts=OnCluCutsPt1p0, .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });

    sh.AddHistos("traj",  { .fill="AvgCluCharge_vs_InstLumi",           .pfs={main12,"Layers","Mods"}, .cuts=AllCluCuts,      .draw="PE1TwoCol55", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSize_vs_InstLumi",             .pfs={main12,"Layers","Mods"}, .cuts=AllCluCuts,      .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeX_vs_InstLumi",            .pfs={main12,"Layers","Mods"}, .cuts=AllCluCuts,      .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeY_vs_InstLumi",            .pfs={main12,"Layers","Mods"}, .cuts=AllCluCuts,      .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNormMPV_vs_InstLumi",     .pfs={main12,"Layers","Mods"}, .cuts=OnCluCutsPt1p0,  .draw="PE1TwoCol55", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSize_vs_InstLumi",           .pfs={main12,"Layers","Mods"}, .cuts=OnCluCutsPt1p0,  .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeX_vs_InstLumi",          .pfs={main12,"Layers","Mods"}, .cuts=OnCluCutsPt1p0,  .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeY_vs_InstLumi",          .pfs={main12,"Layers","Mods"}, .cuts=OnCluCutsPt1p0,  .draw="PE1TwoCol55", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluCharge_vs_InstLumi",           .pfs={"Mods","Layers",main12}, .cuts=AllCluCuts,      .draw="PE1", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSize_vs_InstLumi",             .pfs={"Mods","Layers",main12}, .cuts=AllCluCuts,      .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeX_vs_InstLumi",            .pfs={"Mods","Layers",main12}, .cuts=AllCluCuts,      .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeY_vs_InstLumi",            .pfs={"Mods","Layers",main12}, .cuts=AllCluCuts,      .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNormMPV_vs_InstLumi",     .pfs={"Mods","Layers",main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSize_vs_InstLumi",           .pfs={"Mods","Layers",main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeX_vs_InstLumi",          .pfs={"Mods","Layers",main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeY_vs_InstLumi",          .pfs={"Mods","Layers",main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });

    // Layer/Disks Comparison
    sh.AddHistos("traj",  { .fill="AvgCluCharge_vs_InstLumi",           .pfs={"Layers",     main12}, .cuts=AllCluCuts,  .draw="PE1", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluCharge_vs_InstLumi",           .pfs={"DisksRings", main12}, .cuts=AllCluCuts,  .draw="PE1", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSize_vs_InstLumi",             .pfs={"Layers",     main12}, .cuts=AllCluCuts,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSize_vs_InstLumi",             .pfs={"DisksRings", main12}, .cuts=AllCluCuts,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeX_vs_InstLumi",            .pfs={"Layers",     main12}, .cuts=AllCluCuts,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeX_vs_InstLumi",            .pfs={"DisksRings", main12}, .cuts=AllCluCuts,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeY_vs_InstLumi",            .pfs={"Layers",     main12}, .cuts=AllCluCuts,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgCluSizeY_vs_InstLumi",            .pfs={"DisksRings", main12}, .cuts=AllCluCuts,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNormMPV_vs_InstLumi",     .pfs={"Layers",     main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="OnCluChargeNormMPV_vs_InstLumi",     .pfs={"DisksRings", main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0,  15, 25, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSize_vs_InstLumi",           .pfs={"Layers",     main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSize_vs_InstLumi",           .pfs={"DisksRings", main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeX_vs_InstLumi",          .pfs={"Layers",     main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeX_vs_InstLumi",          .pfs={"DisksRings", main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeY_vs_InstLumi",          .pfs={"Layers",     main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    sh.AddHistos("traj",  { .fill="AvgOnCluSizeY_vs_InstLumi",          .pfs={"DisksRings", main12}, .cuts=OnCluCutsPt1p0,  .draw="PE1", .opt="", .ranges={0,0, 3.0,5.0, 0.6,0.8} });
    if (debug) std::cout<<"Phase1PixelHistoMaker - special cluster plots ok"<<std::endl;
    
    // Random events
    //sh.AddHistos("clust", { .fill="AvgCluCharge_vs_Runs",         .pfs={"First4BX","LayersDisks","DataYears"}, .cuts={"Random"}, .draw="PE1", .opt="", .ranges={0,0, 0,0} });
    //sh.AddHistos("clust", { .fill="AvgCluSize_vs_Runs",           .pfs={"First4BX","LayersDisks","DataYears"}, .cuts={"Random"}, .draw="PE1", .opt="", .ranges={0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="AvgOnCluChargeNorm_vs_Runs",         .pfs={"First4BX","LayersDisks","DataYears"}, .cuts={"Random"}, .draw="PE1", .opt="", .ranges={0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="AvgOnCluSize_vs_Runs",           .pfs={"First4BX","LayersDisks","DataYears"}, .cuts={"Random"}, .draw="PE1", .opt="", .ranges={0,0, 0,0} });
    
    add_special_histos = [&sh,&AllCluCuts,&OnCluCutsPt0p6,&OnCluCutsPt1p0]() {
      //sh.AddHistos("clust", { .fill="CluCharge",                  .pfs={"First4BX","LayersDisks","Runs","DataYears"}, .cuts={"Random"}, .draw="HIST", .opt="", .ranges={0,0, 0,5} });
      //sh.AddHistos("clust", { .fill="CluSize",                    .pfs={"First4BX","LayersDisks","Runs","DataYears"}, .cuts={"Random"}, .draw="HIST", .opt="", .ranges={0,0, 0,5} });
      
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",   .pfs={"Runs"},                        .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="", .ranges={0,0, 0,1} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",      .pfs={"Runs","LayersDisks"},          .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",        .pfs={"Runs","LayersDisks"},          .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_NPixL1",        .pfs={"Runs"},                        .cuts={"ZeroBias","EffCuts","Lay1"}, .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCluL1",        .pfs={"Runs"},                        .cuts={"ZeroBias","EffCuts","Lay1"}, .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",   .pfs={"Runs","LayersDisks"},          .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",   .pfs={"Runs","Layers","InnerOuter"},  .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",   .pfs={"LayersDisks","Runs"},          .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="TwoCol43", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",   .pfs={"InnerOuter","Layers","Runs"},  .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"Runs","LayersDisks"},          .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"Runs","Layers","InnerOuter"},  .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"LayersDisks","Runs"},          .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="TwoCol43", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"InnerOuter","Layers","Runs"},  .cuts={"ZeroBias","EffCuts"},        .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LayersDisks",  .pfs={"Runs"},                        .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0.5,4.5, 0,0} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",     .pfs={"Runs","Layers"},               .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",       .pfs={"Runs","Layers"},               .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TriggerRate",  .pfs={"Runs","Layers"},               .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TriggerRate",  .pfs={"Runs","Layers","InnerOuter"},  .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TriggerRate",  .pfs={"Layers","Runs"},               .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TriggerRate",  .pfs={"InnerOuter","Layers","Runs"},  .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_NCollPerTrig", .pfs={"Runs","Layers"},               .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_NCollPerTrig", .pfs={"Runs","Layers","InnerOuter"},  .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_NCollPerTrig", .pfs={"Layers","Runs"},               .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_NCollPerTrig", .pfs={"InnerOuter","Layers","Runs"},  .cuts={"ZeroBias","DColEffCuts"},    .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      // LumiSection plots
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_LS",  .pfs={"Runs","LayersDisks"},           .cuts={"ZeroBias","EffCuts"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_LS",  .pfs={"Runs","LayersDisks","AllROCs"}, .cuts={"ZeroBias","EffCutsAllROC"}, .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_LS",  .pfs={"Layers","Runs"},                .cuts={"ZeroBias","EffCuts"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_LS",  .pfs={"Layers","Runs","AllROCs"},      .cuts={"ZeroBias","EffCutsAllROC"}, .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_LS",  .pfs={"DisksRings", "Runs"},                .cuts={"ZeroBias","EffCuts"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="HitEfficiency_vs_LS",  .pfs={"DisksRings", "Runs","AllROCs"},      .cuts={"ZeroBias","EffCutsAllROC"}, .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LS", .pfs={"Runs","Layers"},                .cuts={"ZeroBias","DColEffCuts"},       .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LS", .pfs={"Runs","LayersDisks","AllROCs"}, .cuts={"ZeroBias","DColEffCutsAllROC"}, .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LS", .pfs={"Layers","Runs"},                .cuts={"ZeroBias","DColEffCuts"},       .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LS", .pfs={"Layers","Runs","AllROCs"},      .cuts={"ZeroBias","DColEffCutsAllROC"}, .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LS", .pfs={"DisksRings", "Runs"},                .cuts={"ZeroBias","DColEffCuts"},       .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
      //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LS", .pfs={"DisksRings", "Runs","AllROCs"},      .cuts={"ZeroBias","DColEffCutsAllROC"}, .draw="PE1", .opt="", .ranges={0,0, 0,0, 0.4,0.4} });

      sh.AddHistos("traj", { .fill="AvgOnCluSize_vs_LS",       .pfs={"Runs","LayersDisks"},       .cuts=OnCluCutsPt1p0, .draw="PE1", .opt="", .ranges={0,0, 0,7,  0.4,0.4} });
      sh.AddHistos("traj", { .fill="AvgOnCluSize_vs_LS",       .pfs={"Layers","Runs"},            .cuts=OnCluCutsPt1p0, .draw="PE1", .opt="", .ranges={0,0, 0,7,  0.4,0.4} });
      sh.AddHistos("traj", { .fill="AvgOnCluSize_vs_LS",       .pfs={"DisksRings", "Runs"},            .cuts=OnCluCutsPt1p0, .draw="PE1", .opt="", .ranges={0,0, 0,7,  0.4,0.4} });
      sh.AddHistos("traj", { .fill="AvgOnCluChargeNorm_vs_LS", .pfs={"Runs","LayersDisks"},       .cuts=OnCluCutsPt1p0, .draw="PE1", .opt="", .ranges={0,0, 0,60, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="AvgOnCluChargeNorm_vs_LS", .pfs={"Layers","Runs"},            .cuts=OnCluCutsPt1p0, .draw="PE1", .opt="", .ranges={0,0, 0,60, 0.4,0.4} });
      sh.AddHistos("traj", { .fill="AvgOnCluChargeNorm_vs_LS", .pfs={"DisksRings", "Runs"},            .cuts=OnCluCutsPt1p0, .draw="PE1", .opt="", .ranges={0,0, 0,60, 0.4,0.4} });
      
      sh.AddHistos("clust", { .fill="CluSize",         .pfs={"Runs","LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
      sh.AddHistos("clust", { .fill="CluSizeX",        .pfs={"Runs","LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,10, 0,0, 0.6,0.8} });
      sh.AddHistos("clust", { .fill="CluSizeY",        .pfs={"Runs","LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
      sh.AddHistos("clust", { .fill="CluCharge",       .pfs={"Runs","LayersAllDisks"}, .cuts=AllCluCuts, .draw="HIST", .opt="Norm", .ranges={ 0,250, 0,0, 0.6,0.8} });
      sh.AddHistos("traj",  { .fill="OnCluSize",       .pfs={"Runs","LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
      sh.AddHistos("traj",  { .fill="OnCluSizeX",      .pfs={"Runs","LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={  0,10, 0,0, 0.6,0.8} });
      sh.AddHistos("traj",  { .fill="OnCluSizeY",      .pfs={"Runs","LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={  0,20, 0,0, 0.6,0.8} });
      sh.AddHistos("traj",  { .fill="OnCluChargeNorm", .pfs={"Runs","LayersAllDisks"}, .cuts=OnCluCutsPt1p0, .draw="HIST", .opt="Norm", .ranges={  0,60, 0,0, 0.6,0.8} });
      
      sh.AddHistos("traj", { .fill="TrackD0",     .pfs={"Runs"},                    .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="TrackD0",     .pfs={"Runs","LayersDisks"},      .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="TrackDZ",     .pfs={"Runs"},                    .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="TrackDZ",     .pfs={"Runs","LayersDisks"},      .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="TrackPt",     .pfs={"Runs"},                    .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="TrackPt",     .pfs={"Runs","LayersDisks"},      .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="TrackEta",    .pfs={"Runs"},                    .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="TrackEta",    .pfs={"Runs","LayersDisks"},      .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="TrackNStrip", .pfs={"Runs"},                    .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="TrackNStrip", .pfs={"Runs","LayersDisks"},      .cuts={"ZeroBias"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="DClu",        .pfs={"Runs"},                    .cuts={"ZeroBias","EffCutsScans"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="DClu",        .pfs={"Runs","LayersDisks"},      .cuts={"ZeroBias","EffCutsScans"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="DClu",        .pfs={"Layers","Runs"},           .cuts={"ZeroBias","EffCutsScans"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="DClu",        .pfs={"Mods","Layers","Runs"},    .cuts={"ZeroBias","EffCutsScans"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
      sh.AddHistos("traj", { .fill="DClu",        .pfs={"InnerOuter","Layers","Runs"}, .cuts={"ZeroBias","EffCutsScans"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });

      // Bad ROCs
#if PHASE == 0
      sh.AddHistos("clust", { .fill="LumiSection",                               .pfs={"Runs"}, .cuts=AllCluCuts,        .draw="HIST", .opt="", .ranges={0,0, 0,0, 0,0} });
      sh.AddHistos("clust", { .fill="RunIntLumi",                                .pfs={"Runs"}, .cuts=AllCluCuts,        .draw="HIST", .opt="", .ranges={0,0, 0,0, 0,0} });
      sh.AddHistos("clust", { .fill="ROCNumber",                                 .pfs={"Runs"}, .cuts=AllCluCuts,        .draw="HIST", .opt="", .ranges={0,0, 0,0, 0,0} });
      sh.AddHistos("clust", { .fill="ROCNumber_vs_LumiSection",                  .pfs={"Runs"}, .cuts=AllCluCuts,        .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
      sh.AddHistos("clust", { .fill="ROCNumber_vs_RunIntLumi",                   .pfs={"Runs"}, .cuts=AllCluCuts,        .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
      sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROCNumber",                .pfs={"Runs"}, .cuts={"EffCutsAllROC"}, .draw="HIST", .opt="", .ranges={0,0, 0,0, 0,0} });
      sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROCNumber_vs_LumiSection", .pfs={"Runs"}, .cuts={"EffCutsAllROC"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
      sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROCNumber_vs_RunIntLumi",  .pfs={"Runs"}, .cuts={"EffCutsAllROC"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
#endif
    };
    if (debug) std::cout<<"Phase1PixelHistoMaker - special hiteff plots ok"<<std::endl;
    
    //__________________________________________________________________________________
    //
    //                             Hit Efficiency Plots
    
    // Pileup reweighting dependent plots
    // Layer/Disk Average Plots
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={},                              .cuts={"EffCuts"},            .draw="PE1", .opt="",        .ranges={0,0, 0.95,1} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={"Mod12/34"},                    .cuts={"EffCuts"},            .draw="PE1", .opt="",        .ranges={0,0, 0.95,1} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={main12},                        .cuts={"ZeroBias","EffCuts"}, .draw="PE1", .opt=CMSprelim, .ranges={0,0, 0.95,1, 0.4,0.5} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={main12,"SelectedNBx"},                  .cuts={"ZeroBias","EffCuts"}, .draw="PE1", .opt="",        .ranges={0,0, 0.95,1, 0.4,0.5} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={main12,"InstLumi"},             .cuts={"ZeroBias","EffCuts"}, .draw="PE1", .opt="",        .ranges={0,0, 0.95,1, 0.4,0.5} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={main12,"Mod12/34"},             .cuts={"ZeroBias","EffCuts"}, .draw="PE1", .opt="",        .ranges={0,0, 0.95,1, 0.4,0.5} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={main12,"InstLumi","Mod12/34"},  .cuts={"ZeroBias","EffCuts"}, .draw="PE1", .opt="",        .ranges={0,0, 0.95,1, 0.4,0.5} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LayersDisks",       .pfs={},                              .cuts={"DColEffCuts"},            .draw="PE1", .opt="",        .ranges={0.5,4.5, 0,0} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LayersDisks",       .pfs={"Mod12/34"},                    .cuts={"DColEffCuts"},            .draw="PE1", .opt="",        .ranges={0.5,4.5, 0,0} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LayersDisks",       .pfs={main12},                        .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1", .opt=CMSprelim, .ranges={0.5,4.5, 0,0, 0.4,0.5} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LayersDisks",       .pfs={main12,"SelectedNBx"},                  .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1", .opt="",        .ranges={0.5,4.5, 0,0, 0.4,0.5} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LayersDisks",       .pfs={main12,"InstLumi"},             .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1", .opt="",        .ranges={0.5,4.5, 0,0, 0.4,0.5} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LayersDisks",       .pfs={main12,"Mod12/34"},             .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1", .opt="",        .ranges={0.5,4.5, 0,0, 0.4,0.5} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LayersDisks",       .pfs={main12,"InstLumi","Mod12/34"},  .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1", .opt="",        .ranges={0.5,4.5, 0,0, 0.4,0.5} });
    
    // Geometry Plots: Ladder, Ring, Module, ROC Efficiencies
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Modules",            .pfs={"Layers",main12},                        .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0.98,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders",            .pfs={"Layers",main12},                        .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0.98,1, 0.4,0.4} });

    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Modules",            .pfs={main12,"Layers"},                        .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0.98,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Modules",            .pfs={main12,"InstLumi","Layers"},             .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0.98,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders",            .pfs={main12,"Layers"},                        .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0.98,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders",            .pfs={main12,"Layers","Mod12/34"},            .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0.98,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders",            .pfs={main12,"InstLumi","Layers"},             .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0.98,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders",            .pfs={main12,"InstLumi","Layers","Mod12/34"}, .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0.98,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders_vs_Modules", .pfs={main12,"Layers"},                        .cuts={"ZeroBias","EffCuts"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0.97,1} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Modules",           .pfs={"Layers",main12},                        .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders",           .pfs={"Layers",main12},                        .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Modules",           .pfs={main12,"Layers"},                        .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Modules",           .pfs={main12,"InstLumi","Layers"},             .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders",           .pfs={main12,"Layers"},                        .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders",           .pfs={main12,"Layers","Mod12/34"},            .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders",           .pfs={main12,"InstLumi","Layers"},             .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0,0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders",           .pfs={main12,"InstLumi","Layers","Mod12/34"}, .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders_vs_Modules",.pfs={main12,"Layers"},                        .cuts={"ZeroBias","DColEffCuts"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });  
#if PHASE == 0
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_ROCLadders_vs_ROCModules",           .pfs={main12,"Layers"},        .cuts={"ZeroBias","EffCuts"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_ROCBladesInner_vs_ROCSideDiskPanel", .pfs={main12},                 .cuts={"ZeroBias","EffCuts","FPixInner"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_ROCBladesOuter_vs_ROCSideDiskPanel", .pfs={main12},                 .cuts={"ZeroBias","EffCuts","FPixOuter"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
#elif PHASE == 1
    // ROC Maps
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L1_Ladder_vs_Module",            .pfs={main12},           .cuts={"ZeroBias","EffCutsAllROC","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L2_Ladder_vs_Module",            .pfs={main12},           .cuts={"ZeroBias","EffCutsAllROC","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L3_Ladder_vs_Module",            .pfs={main12},           .cuts={"ZeroBias","EffCutsAllROC","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L4_Ladder_vs_Module",            .pfs={main12},           .cuts={"ZeroBias","EffCutsAllROC","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",       .pfs={main12},           .cuts={"ZeroBias","EffCutsAllROC","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",       .pfs={main12},           .cuts={"ZeroBias","EffCutsAllROC","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L1_Ladder_vs_Module",            .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","EffCuts","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L2_Ladder_vs_Module",            .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","EffCuts","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L3_Ladder_vs_Module",            .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","EffCuts","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_L4_Ladder_vs_Module",            .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","EffCuts","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",       .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","EffCuts","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    sh.AddHistos("traj",  { .fill="HitEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",       .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","EffCuts","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });

    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L1_Ladder_vs_Module",           .pfs={main12},           .cuts={"ZeroBias","DColEffCutsAllROC","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L2_Ladder_vs_Module",           .pfs={main12},           .cuts={"ZeroBias","DColEffCutsAllROC","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L3_Ladder_vs_Module",           .pfs={main12},           .cuts={"ZeroBias","DColEffCutsAllROC","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L4_Ladder_vs_Module",           .pfs={main12},           .cuts={"ZeroBias","DColEffCutsAllROC","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",      .pfs={main12},           .cuts={"ZeroBias","DColEffCutsAllROC","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",      .pfs={main12},           .cuts={"ZeroBias","DColEffCutsAllROC","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L1_Ladder_vs_Module",           .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","DColEffCuts","Lay1"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L2_Ladder_vs_Module",           .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","DColEffCuts","Lay2"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L3_Ladder_vs_Module",           .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","DColEffCuts","Lay3"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_L4_Ladder_vs_Module",           .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","DColEffCuts","Lay4"},  .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_Ring1_BladePanel_vs_Disk",      .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","DColEffCuts","Ring1"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
    //sh.AddHistos("traj",  { .fill="DColEfficiency_vs_ROC_Ring2_BladePanel_vs_Disk",      .pfs={main12,"ExclMods"}, .cuts={"ZeroBias","DColEffCuts","Ring2"}, .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,0} });
#endif
    if (debug) std::cout<<"Phase1PixelHistoMaker - normal hiteff plots ok"<<std::endl;
    
#if DATASTRUCT_VER >= 108
    // New Efficiency N-1 plots
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrkNStrip",     .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","NewEffCutsNoNStrip"},     .draw="PE1",  .opt="",     .ranges={0,30,  0.7,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrkNStrip",     .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","NewEffCutsNoNStrip"},     .draw="PE1",  .opt="TwoCol43",     .ranges={0,30,  0.7,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrkPt",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","NewEffCutsNoPt"},         .draw="PE1",  .opt="logX", .ranges={0,0,   0.7,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrkPt",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","NewEffCutsNoPt"},         .draw="PE1",  .opt="logXTwoCol43", .ranges={0,0,   0.7,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrkD0",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","NewEffCutsNoD0"},         .draw="PE1",  .opt="logX", .ranges={0,0.1, 0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrkD0",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","NewEffCutsNoD0"},         .draw="PE1",  .opt="logXTwoCol43", .ranges={0,0.1, 0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrkDZ",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","NewEffCutsNoDZ"},         .draw="PE1",  .opt="logX", .ranges={0,1,   0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrkDZ",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","NewEffCutsNoDZ"},         .draw="PE1",  .opt="logXTwoCol43", .ranges={0,1,   0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_DRTrk",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","NewEffCutsNoHitSep"},     .draw="PE1",  .opt="", .ranges={0,1,   0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_DRTrk",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","NewEffCutsNoHitSep"},     .draw="PE1",  .opt="TwoCol43", .ranges={0,1,   0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_DTraj",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","NewEffCutsNoHitSep"},     .draw="PE1",  .opt="logX", .ranges={0,1,   0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_DTraj",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","NewEffCutsNoHitSep"},     .draw="PE1",  .opt="logXTwoCol43", .ranges={0,1,   0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackAlpha",    .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","NewEffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackAlpha",    .pfs={"Layers",main12},           .cuts={"ZeroBias","NewEffCuts"},               .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackAlpha",    .pfs={"DisksRings",main12},                     .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackAlpha",    .pfs={"InnerOuter","Layers",main12},            .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBeta",     .pfs={main12,"LayersDisks"},                    .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBeta",     .pfs={main12,"Layers","InstLumi"},              .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBeta",     .pfs={main12,"Layers","InnerOuter"},            .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBeta",     .pfs={main12,"Layers","InnerOuter","InstLumi"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBeta",     .pfs={"Layers",main12},                         .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBeta",     .pfs={"InnerOuter","Layers",main12},            .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBetaBins", .pfs={"Mods",    "Layers",main12},              .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBetaBins", .pfs={"InstLumi","Layers",main12},              .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBetaBins", .pfs={"InstLumi","Layers","InnerOuter",main12}, .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBetaBins", .pfs={"Pileup4", "Layers",main12},              .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackBeta",     .pfs={"DisksRings",main12},                     .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackTheta",    .pfs={main12,"LayersDisks"},                    .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackTheta",    .pfs={main12,"Layers","InstLumi"},              .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackTheta",    .pfs={main12,"Layers","InnerOuter"},            .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackTheta",    .pfs={main12,"Layers","InnerOuter","InstLumi"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackTheta",    .pfs={"Layers",main12},                         .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackTheta",    .pfs={"InnerOuter","Layers",main12},            .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackTheta",    .pfs={"InstLumi","Layers",main12},              .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackTheta",    .pfs={"InstLumi","Layers","InnerOuter",main12}, .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackTheta",    .pfs={"DisksRings",main12},                     .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackEta",      .pfs={main12,"LayersDisks"},                    .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0,   0.99,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="NewHitEfficiency_vs_TrackEta",      .pfs={"LayersDisks",main12},                    .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt="TwoCol43", .ranges={0,0,   0.99,1, 0.4,0.4} });
    // Denominator
    sh.AddHistos("traj", { .fill="TrkNStrip",                   .pfs={main12,"LayersDisks"},            .cuts={"ZeroBias","NewEffCuts"},         .draw="HIST",  .opt="",             .ranges={0,30,  0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="TrkNStrip",                   .pfs={"LayersDisks",main12},            .cuts={"ZeroBias","NewEffCuts"},         .draw="HIST",  .opt="TwoCol43",     .ranges={0,30,  0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="TrkPt",                       .pfs={main12,"LayersDisks"},            .cuts={"ZeroBias","NewEffCutsNoPt"},     .draw="HIST",  .opt="logX", .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="TrkPt",                       .pfs={"LayersDisks",main12},            .cuts={"ZeroBias","NewEffCutsNoPt"},     .draw="HIST",  .opt="logXTwoCol43", .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="TrkD0",                       .pfs={main12,"LayersDisks"},            .cuts={"ZeroBias","NewEffCutsNoD0"},     .draw="HIST",  .opt="logX", .ranges={0,0.1, 0,0, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="TrkD0",                       .pfs={"LayersDisks",main12},            .cuts={"ZeroBias","NewEffCutsNoD0"},     .draw="HIST",  .opt="logXTwoCol43", .ranges={0,0.1, 0,0, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="TrkDZ",                       .pfs={main12,"LayersDisks"},            .cuts={"ZeroBias","NewEffCutsNoDZ"},     .draw="HIST",  .opt="logX", .ranges={0,1,   0,0, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="TrkDZ",                       .pfs={"LayersDisks",main12},            .cuts={"ZeroBias","NewEffCutsNoDZ"},     .draw="HIST",  .opt="logXTwoCol43", .ranges={0,1,   0,0, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={main12},                          .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={main12,"LayersDisks"},            .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={"Layers",main12},                 .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={main12,"ValidHit"},               .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={main12,"LayersDisks","ValidHit"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={"Layers",main12,"ValidHit"},      .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={"ValidHit","Layers",main12},      .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={"Mods","Layers",main12},          .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={"InnerOuter","Layers",main12},    .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
#if DATASTRUCT_VER >= 109
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={main12},                          .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={main12,"LayersDisks"},            .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={"Layers",main12},                 .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={main12,"ValidHit"},               .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={main12,"LayersDisks","ValidHit"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={"Layers",main12,"ValidHit"},      .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={"ValidHit","Layers",main12},      .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={"Mods","Layers",main12},          .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={"InnerOuter","Layers",main12},    .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={"Eta",main12,"LayersDisks"},      .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu2",                       .pfs={"Eta",main12,"LayersDisks","ValidHit"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
#endif
    sh.AddHistos("traj", { .fill="DTraj",                       .pfs={main12},                          .cuts={"ZeroBias","NewEffCutsNoHitSep"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DTraj",                       .pfs={main12,"LayersDisks"},            .cuts={"ZeroBias","NewEffCutsNoHitSep"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DTraj",                       .pfs={"Layers",main12},                 .cuts={"ZeroBias","NewEffCutsNoHitSep"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DTraj",                       .pfs={"Mods","Layers",main12},          .cuts={"ZeroBias","NewEffCutsNoHitSep"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DTraj",                       .pfs={"InnerOuter","Layers",main12},    .cuts={"ZeroBias","NewEffCutsNoHitSep"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DSimHit",                     .pfs={main12,"ValidHit"},               .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DSimHit",                     .pfs={main12,"LayersDisks","ValidHit"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DSimHit",                     .pfs={"Layers",main12,"ValidHit"},      .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DSimHit",                     .pfs={"ValidHit","Layers",main12},      .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DRSimTrk",                    .pfs={main12,"ValidHit"},               .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DRSimTrk",                    .pfs={main12,"LayersDisks","ValidHit"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DRSimTrk",                    .pfs={"Layers",main12,"ValidHit"},      .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DRSimTrk",                    .pfs={"ValidHit","Layers",main12},      .cuts={"ZeroBias","NewEffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DRTrk",                       .pfs={main12,"ValidHit"},               .cuts={"ZeroBias","NewEffCutsNoHitSep"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DRTrk",                       .pfs={main12,"LayersDisks","ValidHit"}, .cuts={"ZeroBias","NewEffCutsNoHitSep"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DRTrk",                       .pfs={"Layers",main12,"ValidHit"},      .cuts={"ZeroBias","NewEffCutsNoHitSep"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DRTrk",                       .pfs={"ValidHit","Layers",main12},      .cuts={"ZeroBias","NewEffCutsNoHitSep"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
#endif

    // Efficiency N-1 plots
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrkNStrip",     .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCutsNoNStrip"},     .draw="PE1",  .opt="",     .ranges={0,30,  0.99,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrkNStrip",     .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCutsNoNStrip"},     .draw="PE1",  .opt="TwoCol43",     .ranges={0,30,  0.99,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrkPt",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCutsNoPt"},         .draw="PE1",  .opt="logX", .ranges={0,0,   0.99,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrkPt",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCutsNoPt"},         .draw="PE1",  .opt="logXTwoCol43", .ranges={0,0,   0.99,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackAlpha",    .pfs={main1, "LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackAlpha",    .pfs={main2, "LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackAlpha",    .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackAlpha",    .pfs={"Layers",main12},           .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackAlpha",    .pfs={"DisksRings",main12},            .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackAlpha",    .pfs={"InnerOuter","Layers",main12}, .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBeta",     .pfs={main1, "LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBeta",     .pfs={main2, "LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBeta",     .pfs={main12,"LayersDisks"},                    .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBeta",     .pfs={main12,"Layers","InstLumi"},              .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBeta",     .pfs={main12,"Layers","InnerOuter"},            .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBeta",     .pfs={main12,"Layers","InnerOuter","InstLumi"}, .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBeta",     .pfs={"Layers",main12},                         .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBeta",     .pfs={"InnerOuter","Layers",main12},            .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBetaBins", .pfs={"Mods",    "Layers",main12},              .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBetaBins", .pfs={"InstLumi","Layers",main12},              .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBetaBins", .pfs={"InstLumi","Layers","InnerOuter",main12}, .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBetaBins", .pfs={"Pileup4", "Layers",main12},              .cuts={"ZeroBias","EffCutsNoBeta","MainFills"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackBeta",     .pfs={"DisksRings",main12},                     .cuts={"ZeroBias","EffCutsNoBeta"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TracksTheta",   .pfs={main1, "LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={main2, "LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={main12,"Layers","InstLumi"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={main12,"Layers","InnerOuter"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={main12,"Layers","InnerOuter","InstLumi"}, .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={"Layers",main12},           .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={"InnerOuter","Layers",main12}, .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={"InstLumi","Layers",main12}, .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={"InstLumi","Layers","InnerOuter",main12}, .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackTheta",    .pfs={"DisksRings",main12},            .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackEta",      .pfs={main1, "LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="logX", .ranges={0,0,   0.99,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackEta",      .pfs={main2, "LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="logX", .ranges={0,0,   0.99,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackEta",      .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="logX", .ranges={0,0,   0.99,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrackEta",      .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="logXTwoCol43", .ranges={0,0,   0.99,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrkD0",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCutsNoD0"},         .draw="PE1",  .opt="logX", .ranges={0,0.1, 0.98,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrkD0",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCutsNoD0"},         .draw="PE1",  .opt="logXTwoCol43", .ranges={0,0.1, 0.98,1, 0.2,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrkDZ",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCutsNoDZ"},         .draw="PE1",  .opt="logX", .ranges={0,1,   0.99,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TrkDZ",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCutsNoDZ"},         .draw="PE1",  .opt="logXTwoCol43", .ranges={0,1,   0.99,1, 0.2,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_DRTrk",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,1,   0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_DRTrk",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="TwoCol43", .ranges={0,1,   0.7,1, 0.2,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_DTraj",         .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCutsNoHitSep"},     .draw="PE1",  .opt="logX", .ranges={0,1,   0.7,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_DTraj",         .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCutsNoHitSep"},     .draw="PE1",  .opt="logXTwoCol43", .ranges={0,1,   0.7,1, 0.2,0.4} });
    
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrkNStrip",     .pfs={main12,"Layers"},         .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="",     .ranges={0,30,  0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrkNStrip",     .pfs={"Layers",main12},         .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="",     .ranges={0,30,  0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrkPt",         .pfs={main12,"Layers"},         .cuts={"ZeroBias","DColEffCutsNoPt"},     .draw="PE1",  .opt="",     .ranges={0,5,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrkPt",         .pfs={"Layers",main12},         .cuts={"ZeroBias","DColEffCutsNoPt"},     .draw="PE1",  .opt="",     .ranges={0,5,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackEta",      .pfs={main1, "Layers"},         .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackEta",      .pfs={main2, "Layers"},         .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackEta",      .pfs={main12,"Layers"},         .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackEta",      .pfs={"Layers",main12},         .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackAlpha",    .pfs={main1, "Layers"},         .cuts={"ZeroBias","DColEffCutsNoAlpha"},  .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackAlpha",    .pfs={main2, "Layers"},         .cuts={"ZeroBias","DColEffCutsNoAlpha"},  .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackAlpha",    .pfs={main12,"Layers"},         .cuts={"ZeroBias","DColEffCutsNoAlpha"},  .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackAlpha",    .pfs={"Layers",main12},         .cuts={"ZeroBias","DColEffCutsNoAlpha"},  .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackBeta",     .pfs={main1, "Layers"},         .cuts={"ZeroBias","DColEffCutsNoBeta"},   .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackBeta",     .pfs={main2, "Layers"},         .cuts={"ZeroBias","DColEffCutsNoBeta"},   .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackBeta",     .pfs={main12,"Layers"},         .cuts={"ZeroBias","DColEffCutsNoBeta"},   .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackBeta",     .pfs={"Layers",main12},         .cuts={"ZeroBias","DColEffCutsNoBeta"},   .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackBetaBins", .pfs={"Mods","Layers",main12},  .cuts={"ZeroBias","DColEffCutsNoBeta"},   .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackTheta",    .pfs={main1, "Layers"},         .cuts={"ZeroBias","DColEffCuts"},  .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackTheta",    .pfs={main2, "Layers"},         .cuts={"ZeroBias","DColEffCuts"},  .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackTheta",    .pfs={main12,"Layers"},         .cuts={"ZeroBias","DColEffCuts"},  .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrackTheta",    .pfs={"Layers",main12},         .cuts={"ZeroBias","DColEffCuts"},  .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrkD0",         .pfs={main12,"Layers"},         .cuts={"ZeroBias","DColEffCutsNoD0"},     .draw="PE1",  .opt="",     .ranges={0,0.5, 0,0, 0.2,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrkD0",         .pfs={"Layers",main12},         .cuts={"ZeroBias","DColEffCutsNoD0"},     .draw="PE1",  .opt="",     .ranges={0,0.5, 0,0, 0.2,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrkDZ",         .pfs={main12,"Layers"},         .cuts={"ZeroBias","DColEffCutsNoDZ"},     .draw="PE1",  .opt="",     .ranges={0,0.5, 0,0, 0.2,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TrkDZ",         .pfs={"Layers",main12},         .cuts={"ZeroBias","DColEffCutsNoDZ"},     .draw="PE1",  .opt="",     .ranges={0,0.5, 0,0, 0.2,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_ValidPixHit",   .pfs={main12,"Layers"},         .cuts={"ZeroBias","DColEffCutsNoValPix"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.2,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_ValidPixHit",   .pfs={"Layers",main12},         .cuts={"ZeroBias","DColEffCutsNoValPix"}, .draw="PE1",  .opt="",     .ranges={0,0,   0,0, 0.2,0.4} });
    
    // Denominator
    sh.AddHistos("traj", { .fill="TrkNStrip",                   .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCutsNoNStrip"}, .draw="PE1",  .opt="",     .ranges={0,30,  0.99,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="TrkNStrip",                   .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCutsNoNStrip"}, .draw="PE1",  .opt="TwoCol43",     .ranges={0,30,  0.99,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="TrkPt",                       .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCutsNoPt"},     .draw="PE1",  .opt="logX", .ranges={0,0,   0.99,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="TrkPt",                       .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCutsNoPt"},     .draw="PE1",  .opt="logXTwoCol43", .ranges={0,0,   0.99,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="TrkD0",                       .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCutsNoD0"},     .draw="PE1",  .opt="logX", .ranges={0,0.1, 0.98,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="TrkD0",                       .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCutsNoD0"},     .draw="PE1",  .opt="logXTwoCol43", .ranges={0,0.1, 0.98,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="TrkDZ",                       .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCutsNoDZ"},     .draw="PE1",  .opt="logX", .ranges={0,1,   0.99,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="TrkDZ",                       .pfs={"LayersDisks",main12},      .cuts={"ZeroBias","EffCutsNoDZ"},     .draw="PE1",  .opt="logXTwoCol43", .ranges={0,1,   0.99,1, 0.2,0.4} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={main12},                    .cuts={"ZeroBias","EffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={main12,"LayersDisks"},      .cuts={"ZeroBias","EffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={"Layers",main12},           .cuts={"ZeroBias","EffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={"Mods","Layers",main12},    .cuts={"ZeroBias","EffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    sh.AddHistos("traj", { .fill="DClu",                        .pfs={"InnerOuter","Layers",main12}, .cuts={"ZeroBias","EffCuts"}, .draw="HIST", .opt="Norm", .ranges={0,0, 0,0} });
    if (debug) std::cout<<"Phase1PixelHistoMaker - N-1 hiteff plots ok"<<std::endl;

    // Plots that doesn't need reweighting
    sh.SetHistoWeights({});
    //sh.SetHistoWeights({}); // Do not need to weight instlumi histo
#if DATASTRUCT_VER >= 108
    std::vector<std::string> yvalues = {"HitEfficiency", "NewHitEfficiency"};//, "DColEfficiency"};
#else
    std::vector<std::string> yvalues = {"HitEfficiency"};//, "DColEfficiency"};
#endif
    std::vector<std::string> xvalues = {"InstLumi", "InstLumi0p5", "Pileup", "LowInstLumi", "NCluL24", "LowNCluL24", "BunchCrossing5", "BunchCrossing12", "BunchCrossing60", "TriggerRate"};
    //std::vector<double> y_mins = {0, 0};
    //std::vector<double> y_maxs = {0, 0};
    std::vector<double> x_mins = { 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> x_maxs = { 0, 0, 0, 0, 0, 0, 0, 0};
    for (size_t i=0, ni=yvalues.size(); i<ni; ++i) {
      if (i==0) sh.AddHistos("traj",   { .fill="FPixR", .pfs={"DisksRings", main12}, .cuts={"ZeroBias","EffCuts"},   .draw="HIST",.opt="", .ranges={4,17, 0,0, 0.4,0.4} });
      else      sh.AddHistos("traj",   { .fill="FPixR", .pfs={"DisksRings", main12}, .cuts={"ZeroBias","NewEffCuts"},.draw="HIST",.opt="", .ranges={4,17, 0,0, 0.4,0.4} });
      for (size_t j=0, nj=xvalues.size(); j<nj; ++j)  {
	      std::string yvalue = yvalues[i];
	      std::string xvalue = xvalues[j];
	      //double x1 = x_mins[j], x2 = x_maxs[j], y1 = y_mins[j], y2 = y_maxs[j];
	      double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	      std::vector<std::string> c, c_all;
	      c.push_back("ZeroBias");
	      c_all.push_back("ZeroBias");
	      std::string Layers = "Layers";
	      std::string lopt = "";
	      if (i==0) {
	        c.push_back("EffCuts");
	        c_all.push_back("EffCutsAllROC");
	        Layers += "Disks";
	        lopt = "TwoCol43";
	      } else if (i==1) {
	        //c.push_back("DColEffCuts");
	        //c_all.push_back("DColEffCuts");
	        c.push_back("NewEffCuts");
	        c_all.push_back("NewEffCuts");
	      }
	      //sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main1,          Layers                                  }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      //sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main1,          Layers,              "TrkBeta"          }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      //sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main1,          Layers,              "MainFills"        }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      //sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main1,         "Layers","Mod12/34",  "MainFills"        }, .cuts=c,    .draw="PE1",.opt="",               .ranges={x1,x2, y1,y2, 0.4,0.4} });
        sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main12,         Layers                                  }, .cuts=c,    .draw="PE1TwoCol55",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
        sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main12,         Layers,              "TrkBeta"          }, .cuts=c,    .draw="PE1TwoCol55",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
        sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main12,         Layers,"InnerOuter", "TrkBeta"          }, .cuts=c,    .draw="PE1TwoCol55",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
        sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main12,         Layers,              "InnerOuter"       }, .cuts=c,    .draw="PE1TwoCol55",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
        sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main12,         Layers,              "MainFills"        }, .cuts=c,    .draw="PE1TwoCol55",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
        sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={main12,        "Layers","Mod12/34",  "MainFills"        }, .cuts=c,    .draw="PE1TwoCol55",.opt="",               .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={Layers,         main12                                  }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={Layers,         main12,              "MainFills"        }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={Layers,         main12,              "AllROCs"          }, .cuts=c_all,.draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
//      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={Layers,        "DataYears"                              }, .cuts=c,    .draw="PE1",.opt=lopt+"",               .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={Layers,        "DataYears",          "TrkBeta"          }, .cuts=c,    .draw="PE1",.opt=lopt+"",               .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={Layers,        "DataYears",          "SelectedNBx"      }, .cuts=c,    .draw="PE1",.opt=lopt+"",               .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={Layers,        "DataYears",          "Mod12/34"         }, .cuts=c,    .draw="PE1",.opt=lopt+"",               .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"DisksRings",                         main12            }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"DisksRings",   "DataYears"                             }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"DisksRings",   "DataYears",         "MainFills"        }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"DisksRings",   "DataYears",          main12            }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"FPixRadius",   main12                                  }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"FPixRadius",   "Disks",              main12            }, .cuts=c,    .draw="PE1",.opt=lopt+prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=xvalue,               .pfs={"FPixRadius",   "Disks",              main12            }, .cuts=c,    .draw="HIST",.opt=lopt,                 .ranges={x1,x2, 0,0, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"InnerOuter",  "Layer1",              main12            }, .cuts=c,    .draw="PE1",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
//      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"InnerOuter",  "Layer1","Mod12/34",   main12            }, .cuts=c,    .draw="PE1",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"InnerOuter",  "Layer1","L1Rate",     main12            }, .cuts=c,    .draw="PE1",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"InnerOuter",  "Mod12/34","Layer1",   main12            }, .cuts=c,    .draw="PE1",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"Mods",        "Layers",              main12            }, .cuts=c,    .draw="PE1",.opt="",               .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"Mods",        "Layers",              main12,"MainFills"}, .cuts=c,    .draw="PE1",.opt="",               .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"L1Rate",      "Layers","InnerOuter", main12            }, .cuts=c,    .draw="PE1",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"SelectedNBx",  Layers,              "DataYears"        }, .cuts=c,    .draw="PE1",.opt=prelim2017+"Keep",.ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"SelectedNBx", "Layers","Mod12/34",  "DataYears"        }, .cuts=c,    .draw="PE1",.opt="Keep",           .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      if (xvalue=="Pileup") {
	        sh.AddHistos("traj", { .fill=yvalue+"_vs_"+xvalue, .pfs={"SelectedNBx","BX>500", Layers,              "DataYears"        }, .cuts=c,    .draw="PE1",.opt=prelim2017+"Keep",.ranges={x1,x2, y1,y2, 0.4,0.4} });
	        sh.AddHistos("traj", { .fill=yvalue+"_vs_"+xvalue, .pfs={"SelectedNBx","BX>500","Layers","Mod12/34",  "DataYears"        }, .cuts=c,    .draw="PE1",.opt="Keep",           .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      }
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"InstLumi",    "Layers",             "DataYears"        }, .cuts=c,    .draw="PE1",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"InstLumi",    "Layers",             main12             }, .cuts=c,    .draw="PE1",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"Pileup5",     "Layers",             "DataYears"        }, .cuts=c,    .draw="PE1",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
	      sh.AddHistos("traj",   { .fill=yvalue+"_vs_"+xvalue, .pfs={"Pileup5",     "Layers",             main12             }, .cuts=c,    .draw="PE1",.opt=prelim2017,       .ranges={x1,x2, y1,y2, 0.4,0.4} });
      }
    }
    if (debug) std::cout<<"Phase1PixelHistoMaker - hiteff trend plots ok"<<std::endl;

    // IntLumi
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_IntLumi2017",   .pfs={"InstLumi", "LayersDisks", "IntLumiRunIII"},                     .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0.95,1.00, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_IntLumi2017",   .pfs={"InstLumi", "DisksRings", "IntLumiRunIII"},                      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0.95,1.00, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_IntLumi2018",   .pfs={"InstLumi", "LayersDisks", "IntLumiRunIII"},                     .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0.95,1.00, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_IntLumi2018",   .pfs={"InstLumi", "DisksRings", "IntLumiRunIII"},                      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0.95,1.00, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_IntLumiRunIII", .pfs={main12, "LayersDisks" },                                         .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0.95,1.00, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_IntLumiRunIII", .pfs={"Data2022" , "LayersDisks"},                                     .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0.95,1.00, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_IntLumiRunIII", .pfs={},                                                               .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0.95,1.00, 0.4,0.4} });

    // Normalized by fluence
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumiNorm",  .pfs={main1,       "Layer1"        },                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumiNorm",  .pfs={main1,       "Layer1","TrkBeta"},               .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumiNorm",  .pfs={main12,      "Layer1"        },                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumiNorm",  .pfs={main12,      "Layer1","TrkBeta"},               .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumiNorm",  .pfs={             "Layer1", main12},                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumiNorm",  .pfs={             "TBMReset2"     },                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumiNorm",  .pfs={"InnerOuter","Layer1", main12},                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumiNorm",  .pfs={"Ladders",   "Layer1", main12},                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_PileupNorm",    .pfs={main1,       "Layer1"        },                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_PileupNorm",    .pfs={main12,      "Layer1"        },                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_PileupNorm",    .pfs={             "Layer1", main12},                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_PileupNorm",    .pfs={"InnerOuter","Layer1", main12},                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_PileupNorm",    .pfs={"Ladders",   "Layer1", main12},                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumiNorm", .pfs={main1,       "Layer1"        },                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumiNorm", .pfs={main12,      "Layer1"        },                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumiNorm", .pfs={             "Layer1", main12},                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumiNorm", .pfs={"InnerOuter","Layer1", main12},                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumiNorm", .pfs={"Ladders",   "Layer1", main12},                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_PileupNorm",   .pfs={main1,       "Layer1"        },                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_PileupNorm",   .pfs={main12,      "Layer1"        },                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_PileupNorm",   .pfs={             "Layer1", main12},                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_PileupNorm",   .pfs={"InnerOuter","Layer1", main12},                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_PileupNorm",   .pfs={"Ladders",   "Layer1", main12},                 .cuts={"ZeroBias","DColEffCuts"},         .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });

    // InstLumi vs Ladders/Modules
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Modules_vs_InstLumi0p5", .pfs={main12,"Layers"},                      .cuts={"ZeroBias","EffCuts"},             .draw="COLZ", .opt="", .ranges={0,0, -4,4, 0,0} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders_vs_InstLumi0p5", .pfs={main12,"Layers"},                      .cuts={"ZeroBias","EffCuts"},             .draw="COLZ", .opt="", .ranges={0,0,  0,0, 0,0} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders_vs_InstLumi0p5", .pfs={main12,"Layers","Mods"},              .cuts={"ZeroBias","EffCuts"},             .draw="COLZ", .opt="", .ranges={0,0,  0,0, 0,0} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Modules_vs_InstLumi0p5", .pfs={main12,"Layers"},                      .cuts={"ZeroBias","DColEffCuts"},             .draw="COLZ", .opt="", .ranges={0,0, -4,4, 0,0} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders_vs_InstLumi0p5", .pfs={main12,"Layers"},                      .cuts={"ZeroBias","DColEffCuts"},             .draw="COLZ", .opt="", .ranges={0,0,  0,0, 0,0} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders_vs_InstLumi0p5", .pfs={main12,"Layers","Mods"},              .cuts={"ZeroBias","DColEffCuts"},              .draw="COLZ", .opt="", .ranges={0,0,  0,0, 0,0} });

    // BunchCrossing
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing5",    .pfs={main12, "LayersDisks"},                     .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing12",   .pfs={main12, "LayersDisks"},                     .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing60",   .pfs={main12, "LayersDisks"},                     .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing5",    .pfs={main12, "Layers", "Pileup3"},               .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="TwoCol55", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing12",   .pfs={main12, "Layers", "Pileup3"},               .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="TwoCol55", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing60",   .pfs={main12, "Layers", "Pileup3"},               .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="TwoCol55", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing5",    .pfs={"LayersDisks","DataYears"},                 .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing12",   .pfs={"LayersDisks","DataYears"},                 .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing60",   .pfs={"LayersDisks","DataYears"},                 .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing5",    .pfs={"InnerOuter","Layers","DataYears"},         .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing12",   .pfs={"InnerOuter","Layers","DataYears"},         .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing60",   .pfs={"InnerOuter","Layers","DataYears"},         .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing5",    .pfs={"Pileup5","LayersDisks","DataYears"},       .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing12",   .pfs={"Pileup5","LayersDisks","DataYears"},       .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing60",   .pfs={"Pileup5","LayersDisks","DataYears"},       .cuts={"ZeroBias","EffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing60",   .pfs={"Pileup3",    "LayersDisks","DataYears"},   .cuts={"ZeroBias","EffCuts","MainFills"}, .draw="PE1",  .opt="",                .ranges={0,0, 0.98,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing60",   .pfs={"InstLumi",   "LayersDisks","DataYears"},   .cuts={"ZeroBias","EffCuts","MainFills"}, .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0.80,1, 0.3,0.5} }); // APPROVAL
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing60",   .pfs={"SelectedNBx","LayersDisks","DataYears"},           .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="Keep",            .ranges={0,0, 0.98,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_BunchCrossing60",   .pfs={"SelectedNBx","Pileup3","LayersDisks","DataYears"}, .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017+"Keep", .ranges={0,0, 0.98,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing5",   .pfs={"Layers","DataYears"},                      .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing12",  .pfs={"Layers","DataYears"},                      .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing60",  .pfs={"Layers","DataYears"},                      .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing5",   .pfs={"InnerOuter","Layers","DataYears"},         .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing12",  .pfs={"InnerOuter","Layers","DataYears"},         .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing60",  .pfs={"InnerOuter","Layers","DataYears"},         .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing5",   .pfs={"Pileup5","Layers","DataYears"},            .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing12",  .pfs={"Pileup5","Layers","DataYears"},            .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing60",  .pfs={"Pileup5","Layers","DataYears"},            .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing60",  .pfs={"Pileup3",    "Layers","DataYears"},        .cuts={"ZeroBias","DColEffCuts","MainFills"}, .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing60",  .pfs={"InstLumi",   "Layers","DataYears"},        .cuts={"ZeroBias","DColEffCuts","MainFills"}, .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.3,0.5} }); // APPROVAL
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing60",  .pfs={"SelectedNBx","Layers","DataYears"},                .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="Keep",            .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_BunchCrossing60",  .pfs={"SelectedNBx","Pileup3","Layers","DataYears"},      .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017+"Keep", .ranges={0,0, 0,0, 0.4,0.4} });

    // Trigger Rate
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",  .pfs={"InnerOuter","Layers","InstLumi",main12}, .cuts={"ZeroBias","EffCuts"},       .draw="PE1",  .opt="", .ranges={0,0, 0.9,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",  .pfs={"InstLumi","Layers","InnerOuter",main12}, .cuts={"ZeroBias","EffCuts"},       .draw="PE1",  .opt="", .ranges={0,0, 0.9,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",  .pfs={"LayersDisks"},                           .cuts={"ZeroBias","EffCuts"},       .draw="PE1", .opt="TwoCol43", .ranges={0,0, 0.9,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",  .pfs={"Mods","Layers"},                         .cuts={"ZeroBias","EffCuts","Lay1"},.draw="PE1", .opt="", .ranges={0,0, 0.9,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",  .pfs={"Mods","Layers","Mod12/34"},              .cuts={"ZeroBias","EffCuts","Lay1"},.draw="PE1", .opt="", .ranges={0,0, 0.9,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",  .pfs={"InnerOuter","Layers"},                   .cuts={"ZeroBias","EffCuts","Lay1"},.draw="PE1", .opt="", .ranges={0,0, 0.9,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate",  .pfs={"InnerOuter","Layers","Mod12/34"},        .cuts={"ZeroBias","EffCuts","Lay1"},.draw="PE1", .opt="", .ranges={0,0, 0.9,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TriggerRate", .pfs={"InnerOuter","Layers","InstLumi",main12}, .cuts={"ZeroBias","DColEffCuts"},   .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TriggerRate", .pfs={"InstLumi","Layers","InnerOuter",main12}, .cuts={"ZeroBias","DColEffCuts"},   .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRateBins_vs_InstLumi0p5",       .pfs={"Layers",main12}, .cuts={"ZeroBias","EffCuts"},       .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_TriggerRateBins_vs_InstLumi0p5",      .pfs={"Layers",main12}, .cuts={"ZeroBias","DColEffCuts"},   .draw="COLZ", .opt="", .ranges={0,0, 0,0, 0,1} });

    // Collisions per Trigger
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"InnerOuter","Layers","InstLumi",main12}, .cuts={"ZeroBias","EffCuts"},       .draw="PE1",  .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"InstLumi","Layers","InnerOuter",main12}, .cuts={"ZeroBias","EffCuts"},       .draw="PE1",  .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"LayersDisks"},                           .cuts={"ZeroBias","EffCuts"},       .draw="PE1", .opt="TwoCol43", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"Mods","Layers"},                         .cuts={"ZeroBias","EffCuts","Lay1"},.draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"Mods","Layers","Mod12/34"},              .cuts={"ZeroBias","EffCuts","Lay1"},.draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"InnerOuter","Layers"},                   .cuts={"ZeroBias","EffCuts","Lay1"},.draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCollPerTrig",  .pfs={"InnerOuter","Layers","Mod12/34"},        .cuts={"ZeroBias","EffCuts","Lay1"},.draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });    
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_NCollPerTrig", .pfs={"InnerOuter","Layers","InstLumi",main12}, .cuts={"ZeroBias","DColEffCuts"},   .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_NCollPerTrig", .pfs={"InstLumi","Layers","InnerOuter",main12}, .cuts={"ZeroBias","DColEffCuts"},   .draw="PE1",  .opt="", .ranges={0,0, 0,0, 0.4,0.4} });

    // L1 Occupancy
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NPixL1",      .pfs={main12},                  .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCluL1",      .pfs={main12},                  .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NPixL1",      .pfs={"Mods"},                  .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCluL1",      .pfs={"Mods"},                  .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NPixL1",      .pfs={"Mods","Mod12/34"},       .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCluL1",      .pfs={"Mods","Mod12/34"},       .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NPixL1",      .pfs={"InnerOuter"},            .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCluL1",      .pfs={"InnerOuter"},            .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NPixL1",      .pfs={"InnerOuter","Mod12/34"}, .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_NCluL1",      .pfs={"InnerOuter","Mod12/34"}, .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    if (debug) std::cout<<"Phase1PixelHistoMaker - special hiteff plots ok"<<std::endl;

    // Historical and Time evolution plots (IntLumi, Date, etc)
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={"DataYears"},          .cuts={"ZeroBias","EffCuts"}, .draw="PE1", .opt="", .ranges={0,0, 0.98,1} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={"DataYears","Months"}, .cuts={"ZeroBias","EffCuts"}, .draw="PE1", .opt="", .ranges={0,0, 0,0} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_LayersDisks",       .pfs={"DataYears","Months"}, .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1", .opt="", .ranges={0.5,4.5, 0,0} });
    for (size_t i=0, n=time_types.size(); i<n; ++i) {
      std::string time = time_types[i];
      double xmin = xmins[i], xmax = xmaxs[i];
      std::string opts = (i<2) ? "" : (i==3) ? "Weeks" : "Months";
      if (!(std::string(main12)=="DataYears"&&(time=="InstLumi"||time=="Pileup"))) {
	      sh.AddHistos("traj", { .fill=std::string("HitEfficiency_vs_")+time,    .pfs={"LayersDisks","DataYears", "IntLumiRunII"}, .cuts={"ZeroBias","EffCuts"},    .draw="PE1",  .opt=opts+"TwoCol43", .ranges={xmin,xmax, 0,0, 0.40,0.45} });
	      sh.AddHistos("traj", { .fill=std::string("HitEfficiency_vs_")+time,    .pfs={"DataYears","LayersDisks", "IntLumiRunII"}, .cuts={"ZeroBias","EffCuts"},    .draw="PE1",  .opt=opts,            .ranges={xmin,xmax, 0,0, 0.40,0.45} });
	      sh.AddHistos("traj", { .fill=std::string("NewHitEfficiency_vs_")+time, .pfs={"LayersDisks","DataYears", "IntLumiRunII"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt=opts+"TwoCol43", .ranges={xmin,xmax, 0,0, 0.40,0.45} });
	      sh.AddHistos("traj", { .fill=std::string("NewHitEfficiency_vs_")+time, .pfs={"DataYears","LayersDisks", "IntLumiRunII"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt=opts,            .ranges={xmin,xmax, 0,0, 0.40,0.45} });
	      sh.AddHistos("traj", { .fill=std::string("NewHitEfficiency_vs_")+time, .pfs={"LayersDisks","AvgInstLumi","DataYears", "IntLumiRunII"}, .cuts={"ZeroBias","NewEffCuts"}, .draw="PE1",  .opt=opts+"TwoCol43", .ranges={xmin,xmax, 0,0, 0.40,0.45} });
	      //sh.AddHistos("traj", { .fill=std::string("DColEfficiency_vs_")+time, .pfs={"Layers","DataYears"}, .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt=opts, .ranges={xmin,xmax, 0,0, 0.40,0.45} });
	      //sh.AddHistos("traj", { .fill=std::string("DColEfficiency_vs_")+time, .pfs={"DataYears","Layers"}, .cuts={"ZeroBias","DColEffCuts"}, .draw="PE1",  .opt=opts, .ranges={xmin,xmax, 0,0, 0.40,0.45} });
      }
    }
    if (debug) std::cout<<"Phase1PixelHistoMaker - historical hiteff plots ok"<<std::endl;

    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Time_Fill5942",        .pfs={"LayersDisks"},                    .cuts={"ZeroBias","EffCuts"},              .draw="PE1", .opt="TwoCol43", .ranges={0,0, 0,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Time_Fill5942",        .pfs={"Mods","Layers"},                  .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Time_Fill5942",        .pfs={"Mods","Layers","Mod12/34"},       .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Time_Fill5942",        .pfs={"InnerOuter","Layers"},            .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Time_Fill5942",        .pfs={"InnerOuter","Layers","Mod12/34"}, .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate_Fill5942", .pfs={"LayersDisks"},                    .cuts={"ZeroBias","EffCuts"},              .draw="PE1", .opt="TwoCol43", .ranges={0,0, 0,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate_Fill5942", .pfs={"Mods","Layers"},                  .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate_Fill5942", .pfs={"Mods","Layers","Mod12/34"},       .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate_Fill5942", .pfs={"InnerOuter","Layers"},            .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_TriggerRate_Fill5942", .pfs={"InnerOuter","Layers","Mod12/34"}, .cuts={"ZeroBias","EffCuts","Lay1"},       .draw="PE1", .opt="", .ranges={0,0, 0,1, 0.4,0.4} })

    /*
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={main12,"LayersDisks"},                            .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=CMSprelim,         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={main12,"LayersDisks","TrkBeta"},                  .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=CMSprelim,         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={main12,"LayersDisks","MainFills"},                .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=CMSprelim,         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={main12,"Layers","Mod12/34","MainFills"},          .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"LayersDisks", main12},                           .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017+"TwoCol43",        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"LayersDisks", main12,    "MainFills"},           .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017+"TwoCol43",        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"LayersDisks", main12,    "AllROCs"},             .cuts={"ZeroBias","EffCutsAllROC"},       .draw="PE1",  .opt=prelim2017+"TwoCol43",        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"LayersDisks","DataYears"},                       .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="TwoCol43",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"LayersDisks","DataYears","TrkBeta"},             .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="TwoCol43",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"LayersDisks","DataYears","SelectedNBx"},         .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="TwoCol43",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"LayersDisks","DataYears","Mod12/34"},           .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="TwoCol43",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"InnerOuter",   "Layers", main12},               .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"InnerOuter","Mod12/34","Layers", main12},       .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"InnerOuter","Layers","L1Rate",main12},          .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"Mods",      "Layers", main12},                  .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"Mods",      "Layers", main12,"MainFills"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"SelectedNBx","LayersDisks","DataYears"},                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017+"Keep", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"SelectedNBx","Layers","Mod12/34","DataYears"},          .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="Keep",            .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",    .pfs={"L1Rate","Layers","InnerOuter",main12},          .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });

    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={main12,"Layers"},                            .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=CMSprelim,         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={main12,"Layers","MainFills"},                .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=CMSprelim,         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={main12,"Layers","Mod12/34","MainFills"},         .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"Layers", main12},                           .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"Layers", main12,    "MainFills"},           .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"Layers", main12,    "AllROCs"},             .cuts={"ZeroBias","DColEffCutsAllROC"},       .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"Layers","DataYears"},                      .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"Layers","DataYears","SelectedNBx"},                 .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"Layers","DataYears","Mod12/34"},           .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"InnerOuter",   "Layers", main12},               .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"InnerOuter","Layers","L1Rate",   main12},       .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"InnerOuter","Mod12/34","Layers", main12},       .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"Mods",      "Layers", main12},                  .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"Mods",      "Layers", main12,"MainFills"},      .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",                .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"SelectedNBx","Layers","DataYears"},                 .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017+"Keep", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"SelectedNBx","Layers","Mod12/34","DataYears"},          .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="Keep",            .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi",   .pfs={"L1Rate","Layers","InnerOuter",main12},       .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017,        .ranges={0,0, 0,0, 0.4,0.4} });
    
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={main12,"LayersDisks"},                            .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={main12,"LayersDisks","TrkBeta"},                  .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={main12,"LayersDisks","MainFills"},                .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={main12,"Layers","Mod12/34","MainFills"},         .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"LayersDisks", main12},                           .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017+"TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"LayersDisks","DataYears"},                      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017+"TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"LayersDisks","DataYears","TrkBeta"},            .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017+"TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"LayersDisks","DataYears","SelectedNBx"},                .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017+"TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"LayersDisks","DataYears","Mod12/34"},           .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017+"TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"InnerOuter",   "Layers", main12},                  .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"Mods",      "Layers", main12},                  .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"Mods",      "Layers", main12,"MainFills"},      .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"SelectedNBx","LayersDisks","DataYears"},                 .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="Keep",     .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi0p5", .pfs={"SelectedNBx","Layers","Mod12/34","DataYears"},          .cuts={"ZeroBias","EffCuts"},             .draw="PE1",  .opt="Keep",     .ranges={0,0, 0,0, 0.4,0.4} });

    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={main12,"Layers"},                            .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={main12,"Layers","MainFills"},                .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={main12,"Layers","Mod12/34","MainFills"},         .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={"Layers", main12},                           .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={"Layers","DataYears"},                      .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={"Layers","DataYears","SelectedNBx"},                .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={"Layers","DataYears","Mod12/34"},           .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={"InnerOuter",   "Layers", main12},                  .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={"Mods",      "Layers", main12},                  .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={"Mods",      "Layers", main12,"MainFills"},      .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={"SelectedNBx","Layers","DataYears"},                 .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="Keep",     .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p5", .pfs={"SelectedNBx","Layers","Mod12/34","DataYears"},          .cuts={"ZeroBias","DColEffCuts"},             .draw="PE1",  .opt="Keep",     .ranges={0,0, 0,0, 0.4,0.4} });

    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={main12,"LayersDisks"},                            .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt=CMSprelim,  .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={main12,"LayersDisks","TrkBeta"},                  .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt=CMSprelim,  .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={main12,"LayersDisks","MainFills"},                .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt=CMSprelim,  .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={main12,"Layers","Mod12/34","MainFills"},         .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"LayersDisks", main12},                           .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt=prelim2017+"TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"LayersDisks","DataYears"},                       .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt=prelim2017+"TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"LayersDisks","DataYears","TrkBeta"},             .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt=prelim2017+"TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"LayersDisks","DataYears","SelectedNBx"},                 .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt=prelim2017+"TwoCol43", .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"LayersDisks","DataYears","Mod12/34"},           .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt="TwoCol43",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"InnerOuter",  "Layers", main12},                .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"InnerOuter","Mod12/34","Layers", main12},       .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"Mods",     "Layers", main12},                   .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"Mods",     "Layers", main12,"MainFills"},       .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"SelectedNBx","LayersDisks","DataYears"},                 .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"SelectedNBx","Layers","Mod12/34","DataYears"},          .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"SelectedNBx","BX>500","LayersDisks","DataYears"},        .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="HitEfficiency_vs_Pileup",      .pfs={"SelectedNBx","BX>500","Layers","Mod12/34","DataYears"}, .cuts={"ZeroBias","EffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });

    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={main12,"Layers"},                            .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt=CMSprelim,  .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={main12,"Layers","MainFills"},                .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt=CMSprelim,  .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={main12,"Layers","Mod12/34","MainFills"},         .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"Layers", main12},                           .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"Layers","DataYears"},                      .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"Layers","DataYears","SelectedNBx"},                 .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"Layers","DataYears","Mod12/34"},           .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"InnerOuter",  "Layers", main12},                .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"InnerOuter","Mod12/34","Layers", main12},       .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt=prelim2017, .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"Mods",     "Layers", main12},                   .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"Mods",     "Layers", main12,"MainFills"},       .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"SelectedNBx","Layers","DataYears"},                 .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"SelectedNBx","Layers","Mod12/34","DataYears"},          .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"SelectedNBx","BX>500","Layers","DataYears"},        .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    sh.AddHistos("traj", { .fill="DColEfficiency_vs_Pileup",      .pfs={"SelectedNBx","BX>500","Layers","Mod12/34","DataYears"}, .cuts={"ZeroBias","DColEffCuts"},     .draw="PE1",  .opt="",         .ranges={0,0, 0,0, 0.4,0.4} });
    */
    
    // DCol Scan
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_LayersDisks",        .pfs={"DcolScan"},                 .cuts={"ZeroBias","EffCuts","ExclRing34"}, .draw="", .opt="", .ranges={0,0, 0,0} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders",            .pfs={"Layers","DataYears"},       .cuts={"ZeroBias","EffCuts","ExclRing34"}, .draw="", .opt="", .ranges={0,0, 0,0} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Modules",            .pfs={"Layers","DataYears"},       .cuts={"ZeroBias","EffCuts"},              .draw="", .opt="", .ranges={0,0, 0,0} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders_vs_Modules", .pfs={"DcolScan","Layers"},        .cuts={"ZeroBias","EffCuts"},              .draw="", .opt="", .ranges={0,0, 0,0} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",           .pfs={"Layers","DataYears"},       .cuts={"ZeroBias","EffCuts","ExclRing34"}, .draw="", .opt="", .ranges={0,0, 0,0} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_InstLumi",           .pfs={"Layers","Mods","DataYears"}, .cuts={"ZeroBias","EffCuts"},              .draw="", .opt="", .ranges={0,0, 0,0} });
    
    // Dcol Efficiency
    //sh.AddHistos("traj", { .fill="AvgMCDColEff_vs_Pileup",                   .pfs={main12,"LayersDisks"},       .cuts={"ZeroBias","EffCuts","MC"},              .draw="P",    .opt="", .ranges={0,50, 0,1} });
    //sh.AddHistos("traj", { .fill="AvgMCDColEff_vs_InstLumi",                 .pfs={"LayersDisks",main12},       .cuts={"ZeroBias","EffCuts","MC"},              .draw="P",    .opt="TwoCol43", .ranges={0,0, 0,1} });
    //sh.AddHistos("traj", { .fill="AvgMCDColEff_vs_InstLumi",                 .pfs={main12,"LayersDisks"},       .cuts={"ZeroBias","EffCuts","MC"},              .draw="P",    .opt="", .ranges={0,0, 0,1} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_NBxPerTrig",              .pfs={"DataYears","LayersDisks"},  .cuts={"ZeroBias","EffCuts"},            .draw="PE1",  .opt="", .ranges={0,0, 0.9,1} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_NColPerTrig",             .pfs={"DataYears","LayersDisks"},  .cuts={"ZeroBias","EffCuts"},            .draw="PE1",  .opt="", .ranges={0,0, 0.9,1} });
    
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_InstLumi0p25", .pfs={"Mods"},               .cuts={"ZeroBias","EffCuts","Lay","Data"}, .draw="PE1",  .opt="", .ranges={0,0,         0.8,1} });
    //sh.AddHistos("traj", { .fill="AvgMCDColEff_vs_InstLumi0p25",   .pfs={"Mods"},               .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={0,0,        0.85,1} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Modules",       .pfs={"InstLumi0.5"},         .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={0,0,    0.95,1} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Modules",      .pfs={"InstLumi0.5"},         .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={0,0,    0.85, 1.05} });
    //sh.AddHistos("traj", { .fill="AvgMCDColEff_vs_Modules",        .pfs={"InstLumi0.5"},         .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={0,0,    0.8, 1} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders",       .pfs={"InstLumi0.5"},         .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={-10,10, 0.95,1} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders",      .pfs={"InstLumi0.5"},         .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={-10,10, 0.95,1} });
    //sh.AddHistos("traj", { .fill="AvgMCDColEff_vs_Ladders",        .pfs={"InstLumi0.5"},         .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={-10,10, 0.8, 1} });
    //sh.AddHistos("traj", { .fill="HitEfficiency_vs_Ladders",       .pfs={"InstLumi0.5","Mods"}, .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={-10,10, 0.95,1} });
    //sh.AddHistos("traj", { .fill="DColEfficiency_vs_Ladders",      .pfs={"InstLumi0.5","Mods"}, .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={-10,10, 0.8, 1} });
    //sh.AddHistos("traj", { .fill="AvgMCDColEff_vs_Ladders",        .pfs={"InstLumi0.5","Mods"}, .cuts={"ZeroBias","EffCuts","Lay1","Data"}, .draw="PE1",  .opt="", .ranges={-10,10, 0.8, 1} });
    
    //__________________________________________________________________________________
    //
    //                             Cosmics Time Alignment
    
    //++  //sh.SetHistoWeights({});
    //++  sh.AddHistos("traj", { .fill="HitEfficiency_vs_Runs",       .pfs={},      .cuts={"GlobalMuon","Lay3"},            .draw="PE1", .opt="", .ranges={0,0, 0,1} });
    //++  sh.AddHistos("traj", { .fill="AvgOnCluChargeNorm_vs_Runs",  .pfs={},      .cuts={"GlobalMuon","Lay3","ValidHit"}, .draw="PE1", .opt="", .ranges={0,0, 0,60} });
    //++  sh.AddHistos("traj", { .fill="AvgOnCluSize_vs_Runs",        .pfs={},      .cuts={"GlobalMuon","Lay3","ValidHit"}, .draw="PE1", .opt="", .ranges={0,0, 0,6} });
    //++  sh.AddHistos("traj", { .fill="HitEfficiency_vs_TMuon",      .pfs={"WBC"}, .cuts={"GlobalMuon","Lay3"},            .draw="PE1", .opt="", .ranges={0,0, 0,1} });
    //++  sh.AddHistos("traj", { .fill="AvgOnCluChargeNorm_vs_TMuon", .pfs={"WBC"}, .cuts={"GlobalMuon","Lay3","ValidHit"}, .draw="PE1", .opt="", .ranges={0,0, 0,60} });
    //++  sh.AddHistos("traj", { .fill="AvgOnCluSize_vs_TMuon",       .pfs={"WBC"}, .cuts={"GlobalMuon","Lay3","ValidHit"}, .draw="PE1", .opt="", .ranges={0,0, 0,6} });
    //++  sh.AddHistos("traj", { .fill="TMuon",                       .pfs={"WBC"}, .cuts={"GlobalMuon","Lay3"},            .draw="",.opt="Norm", .ranges={0,0, 0,0} });
    //++  //"OnCluCharge""SelectedRuns"

  }// end of ! BADROC_RUN
  
  //std::cout<<"-----------------------------------------------------------------\n";
  //std::cout<<"Creating the following plots:\n"; sh.PrintNames();
  //std::cout<<"-----------------------------------------------------------------\n";
  //std::cout<<"  Total cell count for each SmartHisto:"<<std::endl;
  //sh.GetTotalNCells();
  std::cout<<"-----------------------------------------------------------------\n";
  
  if (filelist.size()&&!is_a) {
    std::cout<<"Adding "<<filelist.size()<<" files from the shell arguments:\n";
    for (size_t i=0; i<filelist.size(); ++i) {
      std::cout<<filelist[i]<<std::endl;
      if (TString(filelist[i]).Contains(".txt")) {
        bool first = 1;
        std::ifstream stream(filelist[i].c_str());
        std::string filename;
        while (stream >> filename) {
          if (strip(filename) != "") {
            looper.AddFile(filename,first);
            first = 0;
          }
        }
      } else {
        looper.AddFile(filelist[i]);
      }
    }
    if (debug) std::cout<<"Phase1PixelHistoMaker - Adding input files ok"<<std::endl;
  } else {
    // Add input files here
    //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3836_INC_SPL1_ns0_710pre9_DYToMuMu_13TeV_Spring14dr_RECO/Ntuple_1_1_CiR.root");
    
    // trajTree only (VER 4) - unfortunately directory wildcards doesn't work
    //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3735_INC_SPL1_ns11_5314_MB_2012C_22JanRR_RECO_201278/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/100/*/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/99_9/*/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/99_6/*/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/99_3/*/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/99/*/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/98/*/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/97/*/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/95/*/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/90/*/*.root");
    //looper.AddFile("/data/gridout/tvami/SiPixelDigitizer/DynIneff3/80/*/*.root");
    
    // Data + Dcol scan - with clustTree (VER 5) 
    //looper.AddFile("/data/gridout/mbartok/DynIneff/TimingStudy_clusttree_Run2012C-22Jan2013-v1_RECO/*.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol100.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol99_9.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol99_6.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol99_3.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol99.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol98.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol97.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol95.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol90.root");
    //looper.AddFile("/data/bartokm/DynamicIneff/eff_loss/clustercharge/CMSSW_7_1_0_pre6/src/DPGAnalysis/PixelTimingStudy/dcol80.root");
    
    // DynIneff Validation
    // FPix DynIneff Validation
    if (VER == -1) { 
      // L1Rate test
      // 2011 data 7 TeV
      //std::vector<std::string> lowlumi = lowlumi_runs_2011(); for (size_t i=0; i<lowlumi.size(); ++i) looper.AddFile(lowlumi[i], i==0); // lowlumi fills
      looper.AddFile("/data/gridout/jkarancs/TimingStudy/2011/v2928_INC_SPL0_ns0_442p2_MB_2011A_08Nov2011_RECO/*.root");  // full 2011 data
      looper.AddFile("/data/gridout/jkarancs/TimingStudy/2011/v2928_INC_SPL0_ns0_442p2_MB_2011B_19Nov2011_RECO/*.root",0);
    } else if (VER == 4) {
      // Data
      //looper.AddFile("dummy_file",-1);
      // Run 201278
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3735_INC_SPL1_ns11_5314_MB_2012C_22JanRR_RECO_201278/*.root");
      looper.AddFile("/data/gridout/mbartok/DynIneff/TimingStudy_clusttree_Run2012C-22Jan2013-v1_RECO/*.root"); // same with clustTree
      // Run 203002
      //std::vector<std::string> v_str = run_203002(); for (size_t i=0; i<v_str.size(); ++i) looper.AddFile(v_str[i], i==0);
      // Full 2012
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3735_INC_SPL2_ns11_5315p1_MB_2012A_22JanRR_RECO_ZB_13may07JSON/*.root");
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3735_INC_SPL2_ns11_5315p1_MB_2012B_22JanRR_RECO_ZB_13may07JSON/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3735_INC_SPL2_ns11_5315p1_MB_2012C_22JanRR_RECO_ZB_13may07JSON/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3735_INC_SPL2_ns11_5315p1_MB_2012D_22JanRR_RECO_ZB_13may07JSON/*.root",0);
      
      // MCs
      //looper.AddFile("dummy_file",-1);
      //looper.AddFile("/data/gridout/mbartok/DynIneff/MC_pre6_final_new_ringfactor_validation_all_dyn_ineff_factors/*.root"); // current (710_pre8), no fpix, no clustTree
      //looper.AddFile("dummy_file",-1);
    } else if (VER==5) {
      // Data
      //+++ looper.AddFile("dummy_file",-1);
      
      // 8 TeV MC
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3836_INC_SPL1_ns0_710pre9_MB_8TeV_noDynIneff_RECO_resol/*.root"); // no DynIneff (MC_Old)
      //looper.AddFile("/data/gridout/mbartok_2/DynIneff/Timingstudy_no_dynineff_CMSSW_7_2_0_pre5_clusttree/*.root");         // no DynIneff with clustTree
      //+++ looper.AddFile("dummy_file",-1); //(MC - VER 4)
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3836_INC_SPL1_ns11_720pre1_MB_GENSIM_201278_flatPU_ViktorPU/*.root"); // with ViktorPU (MC_New)
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3836_INC_SPL1_ns11_720pre1_MB_GENSIM_201278_flatPU_ViktorPU/Marton_run/*.root",0); // with ViktorPU more stats
      //looper.AddFile("/data/gridout/mbartok/DynIneff/pu_viktor_validation_flatpu0-10/*.root",0);
      //looper.AddFile("/data/gridout/mbartok/DynIneff/pu_viktor_validation_noPU/*.root",0);
      //looper.AddFile("/data/gridout/mbartok_2/DynIneff/FPix/fpix_ineff_lay23_newring4factor/*.root"); // current (710_pre8) + fixed ring4 (lay2,3) + fpix ineff 8TeV 50ns
      
      // 13 TeV MC
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3836_COMP_SPL1_ns0_720pre5_MB_GENSIM_flatPU_13TeV_50ns/*.root"); // fpix+ring4+beamspot+13TeV/50ns (8TeV*1.18)
      ////looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3836_COMP_SPL1_ns0_720pre5_MB_GENSIM_flatPU_13TeV_25ns/*.root"); // fpix+ring4+beamspot+13TeV/25ns (8TeV*1.18*2)
      //looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2validation/MinBias_13TeV_BS25_GEN_SIM_RECO_ntuple_FlatPU_DynIneff/*.root"); // fpix+ring4+beamspot+13TeV/25ns (8TeV*1.18*1.82)
      //looper.AddFile("dummy_file",-1);
      //looper.AddFile("/data/gridout/mbartok_2/DynIneff/RUN2validation/MinBias_13TeV_BS50_GEN_SIM_RECO_ntuple_FlatPU_DynIneff/*.root"); // fpix+ring4+beamspot+13TeV/50ns (8TeV*1.1)
      //+++ looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2validation/v3836_COMP_SPL1_ns0_720pre5_MB_GENSIM_flatPU_13TeV_50ns_PSI/*.root"); // Final 13TeV/50ns
      //+++ looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3836_COMP_SPL1_ns0_720pre5_MB_GENSIM_flatPU_13TeV_25ns_PSI/*.root");            // Final 13TeV/25ns-PSI
      
      // 13 TeV 50ns PSI Sim
      // looper.AddFile("dummy_file",-1);
      // looper.AddFile("dummy_file",-1);
      // looper.AddFile("dummy_file",-1);
      // //looper.AddFile("dummy_file",-1);
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2validation/MB_GENSIM_flatPU_13TeV_50ns_PSI_2015_jan/*.root");
      // looper.AddFile("dummy_file",-1);
      
      // run 203002 MC
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/v3836_COMP_SPL2_ns0_712_RelValSingleNuE10_GENSIMRECO_203002PU/*.root");
      
      // Cosmics Time alignment test
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/ExpressCosmics/crab_v3836_COMP_SPL1_ns0_732_Express/150214_164514/0000/*.root/TimingStudy");
      
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/TimingScan2015/ExpressPhysics/v3836_INC_SPL2_ns0_744p1_GR_R_74/150603_192816/0000/*.root");
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/TimingScan2015/batch_v3836_COMP_SPL2_ns0_744p1_GR_R_74_TimingScan_Express_246908_2/*.root"); // COMP - 908
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/TimingScan2015/ExpressPhysics/TimingScan2015_Express_01/150603_144545/0000/*.root"); // COMP
      
      // --------------------------- RUN II --------------------------------
      
      //--------------- SPEC DATA ------------------
      
      // HV Scan 18 - 2015 June 08
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/HV18_ZB1/*.root");
      
      //--------------- 2015 DATA ------------------
      //looper.AddFile("Dummy - 50ns Data",-1);
      //looper.AddFile("Dummy - 25ns Data",-1);
      
      // 13 TeV Data - 3.8T - 50ns - 2015B     (INC SPL1 ns0 10thclu)
      //looper.AddFile("/data/gridout/mbartok/HitEff/Run2015B/MinimumBias/v3836_INC_SPL1_ns0_10thclu_746p6_74X_dataRun2_Prompt_v0_HitEff/150713_111608/0000/*.root");
      //looper.AddFile("/data/gridout/mbartok/HitEff/Run2015B/ZeroBias/v3837_INC_SPL1_ns0_10thclu_746p6_74X_dataRun2_Prompt_v0_HitEff_ZB_50ns_38T_full2015/150902_143559/0000/*.root");
      
      // 13 TeV Data - 3.8T - 25ns - 2015C     (INC SPL1 ns0 10thclu)
      //looper.AddFile("/data/gridout/mbartok/HitEff/Run2015C/ZeroBias/v3837_INC_SPL1_ns0_10thclu_746p6_74X_dataRun2_Prompt_v0_HitEff_ZB_25ns_38T/150902_120925/0000/*.root");
      
      // 13 TeV Data - 3.8T - 25ns - Full 2015 (INC SPL0 ns11 100thclu)
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/v3836_INC_SPL0_ns11_100thclu_7415p1_74X_dataRun2_v4_Nov13SilverJSON/ZB_Run2015C_25ns/0000/*.root");
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/v3836_INC_SPL0_ns11_100thclu_7415p1_74X_dataRun2_v4_Nov13SilverJSON/ZB_Run2015D_PRv3/0000/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/v3836_INC_SPL0_ns11_100thclu_7415p1_74X_dataRun2_v4_Nov13SilverJSON/ZB_Run2015D_PRv3/0001/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/v3836_INC_SPL0_ns11_100thclu_7415p1_74X_dataRun2_v4_Nov13SilverJSON/ZB_Run2015D_PRv3/0002/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/v3836_INC_SPL0_ns11_100thclu_7415p1_74X_dataRun2_v4_Nov13SilverJSON/ZB_Run2015D_PRv3/0003/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/v3836_INC_SPL0_ns11_100thclu_7415p1_74X_dataRun2_v4_Nov13SilverJSON/ZB_Run2015D_PRv4/0000/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/v3836_INC_SPL0_ns11_100thclu_7415p1_74X_dataRun2_v4_Nov13SilverJSON/ZB_Run2015D_PRv4/0001/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/v3836_INC_SPL0_ns11_100thclu_7415p1_74X_dataRun2_v4_Nov13SilverJSON/ZB_Run2015D_PRv4/0002/*.root",0);
      // Contains 2232b fills
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/v3836_INC_SPL0_ns11_100thclu_7415p1_74X_dataRun2_v4_Nov13SilverJSON/ZB_Run2015D_PRv4/0002/*.root");
      
      //---------------- 2015 MC -------------------
      //looper.AddFile("Dummy - 50ns MC",-1);
      //looper.AddFile("Dummy - 25ns MC",-1);
      
      // DCol scan
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/08/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_08/150909_080454/0000/*.root");
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/09/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_09/150908_081340/0000/*.root");
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/095/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_095/150907_090057/0000/*.root");
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/097/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_097/150902_222906/0000/*.root");
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/098/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_098/150902_101845/0000/*.root");
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/099/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_099/150901_141509/0000/*.root");
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/0993/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_0993/150831_113523/0000/*.root");
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/0996/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_0996/150831_222112/0000/*.root");
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/0999/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_0999/150831_085351/0000/*.root");
      // looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/DcolScan/1/MinBias_DcolScan/v3837_INC_SPL1_ns0_10thclu_750_75X_mcRun2_asymptotic_v1_DcolScan_1/150830_151425/0000/*.root");
      
      // 2015 Prediction - 50ns
      //looper.AddFile("/data/gridout/mbartok/DynIneff/RUN2_13TeV_50ns/HitEff/2014factors/MinBias_TuneCUETP8M1_13TeV-pythia8/v3837_INC_SPL1_ns0_10thclu_741p1_MCRUN2_74_V9_All_13TeV50nsMinBias/150830_162738/0000/Ntuple_*.root");
      
      // 2015 Prediction (DynIneff v1)
      //looper.AddFile("/data/gridout/ahunyadi/dyn_ineff/MinBias_TuneCUETP8M1_13TeV-pythia8/default_fill_CMSSW76X/160212_155025/0000/*.root");
      //looper.AddFile("/data/gridout/ahunyadi/dyn_ineff/MinBias_TuneCUETP8M1_13TeV-pythia8/default_fill_CMSSW76X/160212_155025/0001/*.root",0);
      //looper.AddFile("/data/gridout/ahunyadi/dyn_ineff/MinBias_TuneCUETP8M1_13TeV-pythia8/default_fill_CMSSW76X/160212_155025/0002/*.root",0);
      
      // 2015 Tune (DynIneff v2)
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/MinBias_TuneCUETP8M1_13TeV-pythia8/v3836_INC_SPL2_pt0_763p2_76X_mcRun2_asymptotic_v14_DynIneffDBv2/160303_121841/0000/*.root");
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/MinBias_TuneCUETP8M1_13TeV-pythia8/v3836_INC_SPL2_pt0_763p2_76X_mcRun2_asymptotic_v14_DynIneffDBv2/160303_121841/0000/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/MinBias_TuneCUETP8M1_13TeV-pythia8/v3836_INC_SPL2_pt0_763p2_76X_mcRun2_asymptotic_v14_DynIneffDBv2/160303_121841/0000/*.root",0);
      
      // 2015 Tune (Adam 2015)
      //looper.AddFile("/data/gridout/ahunyadi/dyn_ineff/MinBias_TuneCUETP8M1_13TeV-pythia8/dcolscan_dynIneff_fill_2015_CMSSW76X/160206_140309/0000/*.root");
      //looper.AddFile("/data/gridout/ahunyadi/dyn_ineff/MinBias_TuneCUETP8M1_13TeV-pythia8/dcolscan_dynIneff_fill_2015_CMSSW76X/160206_140309/0001/*.root",0);
      //looper.AddFile("/data/gridout/ahunyadi/dyn_ineff/MinBias_TuneCUETP8M1_13TeV-pythia8/dcolscan_dynIneff_fill_2015_CMSSW76X/160206_140309/0002/*.root",0);
      
      // 2016 (Adam 2016)
      //looper.AddFile("/data/gridout/ahunyadi/dyn_ineff/MinBias_TuneCUETP8M1_13TeV-pythia8/dcolscan_dynIneff_fill_2016_CMSSW76X/160208_115541/0000/*.root");
      //looper.AddFile("/data/gridout/ahunyadi/dyn_ineff/MinBias_TuneCUETP8M1_13TeV-pythia8/dcolscan_dynIneff_fill_2016_CMSSW76X/160208_115541/0001/*.root",0);
      //looper.AddFile("/data/gridout/ahunyadi/dyn_ineff/MinBias_TuneCUETP8M1_13TeV-pythia8/dcolscan_dynIneff_fill_2016_CMSSW76X/160208_115541/0002/*.root",0);
      
    } else if (VER == 6) {
      
      // 2015
      // looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3836_INC_SPL2_ns0_10thclu_746p6_74X_dataRun2_Prompt_v0_CoarseDelayScan2015_ZB1/*.root"); // 0T
      // looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3836_INC_SPL2_ns0_10thclu_746p6_74X_dataRun2_Prompt_v0_FineDelayScan2015_ZB1/run_251027/*.root"); // 3.8T
      // looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3836_INC_SPL2_ns0_10thclu_746p6_74X_dataRun2_Prompt_v0_FineDelayScan2015_ZB1/*.root",0);
      
      // TimingScan2016
      //  // 0T [19-25]
      //  //looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3936_INC_SPL1_def_805_80X_dataRun2_Prompt_v5_TimingScan16_Express/*.root");
      //  looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3936_INC_SPL1_def_805p1_80X_dataRun2_Prompt_v6_TimingScan16_0T_RECO/*.root");
      //  // 3.8T [21-31]
      //  looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3936_INC_SPL1_def_806_80X_dataRun2_Prompt_v8_TimingScan16_38T_RECO/*.root");
      //  // 3.8T Extension [20,24,28,32-47]
      //  looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3936_INC_SPL1_def_808_80X_dataRun2_Prompt_v8_TimingScan16_38T_Ext_RECO/ZeroBias1/*.root");
      //  looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3936_INC_SPL1_def_808_80X_dataRun2_Prompt_v8_TimingScan16_38T_Ext_RECO/ZeroBias2/*.root");
      //  looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3936_INC_SPL1_def_808_80X_dataRun2_Prompt_v8_TimingScan16_38T_Ext_RECO/ZeroBias3/*.root");
      //  looper.AddFile("/data/gridout/jkarancs/TimingStudy/Scans/v3936_INC_SPL1_def_808_80X_dataRun2_Prompt_v8_TimingScan16_38T_Ext_RECO/ZeroBias4/*.root");
      
      // Bad Threshold - Old FPix Timing
      //  looper.AddFile("/data/gridout/mbartok/HitEfficiency/2016/Run2016B_272022/ZeroBias1/v3936_INC_SPL1_def_806_80X_dataRun2_Prompt_v8_HitEfficiency16_38T_RECO/160502_140740/0000/*.root"); // no lumiTree
      // Bad Threshold - New FPix Timing
      //  looper.AddFile("/data/gridout/mbartok/HitEfficiency/2016/ExpressPhysics/v3936_INC_SPL1_def_807_80X_dataRun2_Express_v7_TimingStudy_273017_16_38T_Ext_Express/160511_171446/0000/*.root"); // no lumiTree
      //  looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_808_80X_dataRun2_Prompt_v8_Run273158/*.root"); // no lumiTree
      
      // 2016B - Express-v1
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_808_80X_dataRun2_Express_v7_Run2016Bv1/*.root");
      
      // 2016B - Express-v2
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_808_80X_dataRun2_Express_v7_Run273725/*.root");
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_808p1_80X_dataRun2_Express_v7_Run274094/*.root");
      //looper.AddFile("/data/gridout/mbartok_2/HitEfficiency/2016/Run2016B_274387-274388/ZeroBias/v3936_INC_SPL1_def_808_80X_dataRun2_Prompt_v8_TimingStudy16_38T_Ext_RECO/160608_101128/0000/*.root");
      
      // 6e33
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_8011_80X_dataRun2_Express_v8_Run275309/*.root");
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_8011_80X_dataRun2_Express_v8_Run275310/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_8011_80X_dataRun2_Express_v8_Run275311/*.root",0);
      // 8.0e33
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_8012_80X_dataRun2_Prompt_v8_Fill5013Runs/*.root");
      // 8.4e33 - BAD
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_8012_80X_dataRun2_Express_v8_Fill5020Runs/*.root");
      // 9.4e33
      //looper.AddFile("/data/gridout/mbartok/HitEfficiency/2016/Run2016C_275828-275847/ExpressPhysics/v3936_INC_SPL1_def_8012_80X_dataRun2_Express_v10_TimingStudy16_38T_Ext_Express/160629_114744/0000/*.root");

      // DynIneff plot approval dataset
      looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_8011_80X_dataRun2_Express_v8_Run275309/*.root");
      looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_8011_80X_dataRun2_Express_v8_Run275310/*.root",0);
      looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_8011_80X_dataRun2_Express_v8_Run275311/*.root",0);
      looper.AddFile("/data/gridout/jkarancs/TimingStudy/2016/v3936_INC_SPL1_def_8012_80X_dataRun2_Express_v10_Fill5078/*.root",0);

      // Simulation - DynIneff v2 (VER 5)
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/MinBias_TuneCUETP8M1_13TeV-pythia8/v3836_INC_SPL2_pt0_763p2_76X_mcRun2_asymptotic_v14_DynIneffDBv2/160303_121841/0000/*.root");
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/MinBias_TuneCUETP8M1_13TeV-pythia8/v3836_INC_SPL2_pt0_763p2_76X_mcRun2_asymptotic_v14_DynIneffDBv2/160303_121841/0001/*.root",0);
      //looper.AddFile("/data/gridout/jkarancs/TimingStudy/2015/MinBias_TuneCUETP8M1_13TeV-pythia8/v3836_INC_SPL2_pt0_763p2_76X_mcRun2_asymptotic_v14_DynIneffDBv2/160303_121841/0002/*.root",0);
      
      // Low Hit Efficiency Fill5339 after TS2
      //looper.AddFile("/data/gridout/mbartok/HitEfficiency/2016/Run2016H-Fill5339/ZeroBias/v3936_INC_SPL1_def_8020_80X_dataRun2_Prompt_v14_TimingStudy16_38T_Fill5339/161003_074550/0000/*.root");
      
    }
    // This comes last, it is needed for event weight, set to match pileup distribution of data that is used
    //looper.AddDataPileupHisto(0, "../../PileupHistogram_201278.root", "pileup", 501269);
    //looper.SetData(0, 353769); // 2nd arg (Nevt) is optional
    //looper.AddDataPileupHisto(0, "PileupHistogram_2012Data_FlatPUMC.root", "pileup", 51743715);
    if (debug) std::cout<<"Phase1PixelHistoMaker - manually adding input files ok"<<std::endl;
  }
  
  // Load/Add Histos from a file
  if (!is_a) {
    // Dcol Scan:
    // sh.Load("CluCharge_DcolScan_MConly.root");
    //sh.Add("New_*.root");
    //sh.Add("new.root");
    // DynIneff Validation:
    //sh.Add("PHM_out/Validation_Data_CurrMC.root");
    //sh.Add("PHM_out/Validation_OldMC_NewMC.root");
    //sh.Add("PHM_out/Validation_NewMC.root");
    //sh.Add("PHM_out/Validation_0PU_NewMC.root");
    //sh.Add("PHM_out/Validation_with_OldMC.root");
    //sh.Load("PHM_out/Validation_OldMC.root");
    //sh.Load("PHM_out/test.root");
    //sh.Add("PHM_out/Validation2_VER4.root");
    //sh.Add("PHM_out/Validation2_VER5.root");
    //sh.Add("PHM_out/Validation3_Data_2012*.root");
    //sh.Add("PHM_out/Validation3_VER4.root");
    //sh.Add("PHM_out/Validation3_VER5.root");
    //sh.Add("PHM_out/Validation4_Data.root");
    //sh.Add("PHM_out/Validation4_Data_2012*.root");
    //sh.Add("PHM_out/Data_vs_MC_trajonly_VER4_53X.root");
    //sh.Add("PHM_out/Data_vs_MC_trajonly_VER5.root");
    //sh.Add("PHM_out/Data_vs_MC_trajonly.root");
    // sh.Add("PHM_out/FPixValidation_2012Data.root");
    // //sh.Add("PHM_out/FPixValidation_201278.root");
    // sh.Add("PHM_out/FPixValidation_MCs.root");
    // sh.Load("PHM_out/FPixValidation_MC_Curr.root");
    // //sh.Load("PHM_out/FPixValidation_MC_NoIneff.root");
    //sh.Add("PHM_out/L1Rate_2011Data.root");
    //sh.Add("PHM_out/L1Rate_2012Data.root");
    //sh.Load("PHM_out/Bunches_4th.root");
    
    //sh.Load("PHM_out/13TeV_CurrMC_hack.root");
    //sh.Load("PHM_out/13TeV_NewMC_hack_4th.root");
    
    //sh.Add("PHM_out/PSI_Data_clu.root");
    ////sh.Add("PHM_out/PSI_Data.root");
    //sh.Load("PHM_out/13TeV_2012Data.root");
    //sh.Add("PHM_out/13TeV_CurrMC.root");
    //sh.Add("PHM_out/13TeV_NewMC_corr3.root");
    //sh.Load("PHM_out/PSI_MC25ns.root");
    //sh.Add("New.root");
    //sh.Load("PHM_out/Run2015D_part0002_vs_MC_25ns_4th.root");
    //sh.Add("PHM_out/Run2015D_part0_fullstat.root");
    //sh.Add("PHM_out/Run2015D_part1_1_fullstat.root");
    //sh.Add("PHM_out/Run2015D_part1_3_fullstat.root");
    //sh.Add("PHM_out/Run2015D_part1_2_fullstat.root");
    //sh.Add("PHM_out/Run2015D_part2_fullstat.root");
    //sh.Add("PHM_out/MC_25ns_fullstat.root");
    
    //LAST //sh.Load("PHM_out/Data_vs_MC_50_and_25ns_fullstat.root");
    //LAST //sh.Load("PHM_out/Run2015D_vs_MC_25ns_Comparison_fullstat.root");
    //LAST sh.Load("PHM_out/PSI_50ns_Added.root");
    //LAST //sh.Load("PHM_out/HitEff_13TeV_ZB_Run2015D_25ns_2ndrun_part1and2.root");
    //LAST 
    //LAST //sh.Load("HitEff_13TeV_ZB_Run2015D_25ns_2ndrun_259721.root");
    //LAST //sh.Add("PHM_out/*2ndrun.root");
    //LAST //sh.Add("PHM_out/2015_25ns_Data_merged.root");
    //LAST sh.Load("PHM_out/2015_25ns_Data_Part1.root");
    //LAST sh.Add("PHM_out/2015_25ns_Data_Part2.root");
    //LAST sh.Add("PHM_out/2015_25ns_Data_Part3.root");
    //LAST //sh.Add("PHM_out/2015_25ns_Data_with_FedErrors_part1.root");
    //LAST //sh.Add("PHM_out/2015_25ns_Data_with_FedErrors_part2.root");
    //LAST //sh.Add("PHM_out/2015_25ns_Data_with_FedErrors_part3.root");
    
    //sh.Add("PHM_out/DataMCComp_*.root");

    //sh.Load("PHM_out/2015_25ns_Data.root");

    //sh.Add("PHM_out/NewTimingValidation.root");
    
  } else {
    std::cout<<"Adding histograms from "<<filelist.size()<<" files from the shell arguments:\n";
    for (size_t i=0; i<filelist.size(); ++i) {
      std::cout<<filelist[i]<<std::endl;
      sh.Add(filelist[i]);
    }
  }
  if (debug) std::cout<<"Phase1PixelHistoMaker - loading previous histos ok"<<std::endl;
  
  // Loop on trees and fill histograms
  if (!is_a) looper.LoopOnTrees(&sh, add_special_histos, opt_n);
  if (debug) std::cout<<"Phase1PixelHistoMaker - filling plots ok"<<std::endl;
  
  // Write histograms and canvases in an output file
  TFile* f_out = new TFile(outputfile.size()?outputfile.c_str():"PHM_out/test.root","recreate"); 
  sh.DrawPlots();
  if (debug) std::cout<<"Phase1PixelHistoMaker - drawing plots ok"<<std::endl;
  sh.Write();
  if (debug) std::cout<<"Phase1PixelHistoMaker - writing histos ok"<<std::endl;
  f_out->Close();
  std::cout<<"Writing plots to file: "<<f_out->GetName()<<" done.\n";
  
  return 0;
}
