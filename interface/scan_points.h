#define NOVAL_I -9999
#define NOVAL_F -9999.0

namespace scans {
  
  //________________________________________________________________________________________
  //                                 Time Delay Scans
  
  int delay_scan_no(int run, int ls) {
    switch (run) {
      // Delay Scan - 2011
    case 160413: return 0;
    case 160497: return 0; 
    case 160577: return 0;
    case 160578: return 0;
      // 2012 - April
    case 190411: return 1;
    case 190456: return 1;
      // 2012 - July
    case 198022: return 2; // New Vana Settings
    case 198023: return 2;
    case 198048: return 3; // Old Vana Settings
      
      // 2015 - 03 June - 0T
    case 246908: return 4;
    case 246919: return 4;
    case 246920: return 4;
    case 246923: return 4;
    case 246926: return 4;
    case 246930: return 4;
    case 246936: return 4;
      
      // 2015 - July - 3.8T
    case 251027: return 5;
    case 251028: return 5;
    case 251131: return 5;
    case 251134: return 5;

      // 2016 - April - 0T
    case 271188: return 6;
    case 271191: return 6;
    case 271192: return 6;
    case 271193: return 6;

      // 2016 - April - 3.8T
    case 272021: return 7;

      // 2016 - May   - 3.8T
    case 272761: return 7;
    case 272762: return 7;
      
      // 2016 - Aug
    case 277984: return 8;
    case 277990: return 8;

      // PHASE 1
      // 2017 - May
      // Scan 1
    case 294928: return 9;
    case 294929: return 9;
    case 294931: return 9;
    case 294932: return 9;
    case 294933: return 9;
    case 294934: return 9;
    case 294935: return 9;
    case 294936: return 9;
    case 294937: return 9;
    case 294939: return 9;
    case 294940: return 9;
    case 294947: return 9;
    case 294949: return 9;
    case 294950: return 9;
    case 294951: return 9;
    case 294952: return 9;
    case 294953: return 9;
    case 294954: return 9;
    case 294955: return 9;
    case 294956: return 9;
    case 294957: return 9;
    case 294960: return 9;
      // Scan 2
    case 294987: return 10;
    case 294986: return 10;
    case 294988: return 10;
      // Scan 3
    case 295123: return 11;
    case 295124: return 11;
    case 295125: return 11;
    case 295126: return 11;
    case 295133: return 11;
    case 295134: return 11;
    case 295135: return 11;
      // Scan 4
    case 295194: return 12;
    case 295197: return 12;
    case 295199: return 12;
    case 295200: return 12;
    case 295201: return 12;
    case 295202: return 12;
    case 295203: return 12;
      // Scan 5
    case 295340: return 13;
    case 295341: return 13;
    case 295342: return 13;
    case 295343: return 13;
      // Scan 6
    case 295344: return 14;
    case 295345: return 14;
    case 295346: return 14;
    case 295347: return 14;
    case 295348: return 14;
    case 295349: return 14;
      // Run 295371
    case 295371: return 15;
      // Scan 7
    case 295366: return 16;
    case 295377: return 16;
    case 295378: return 16;
    case 295379: return 16;
    case 295380: return 16;
      // Scan 8(-11) - http://cmsonline.cern.ch/cms-elog/987183
    case 295437: return 17;
    case 295438: return 17;
    case 295436: return 17;
    case 295460: return 17;
      // Scan 9
    case 295440: return 18;
    case 295445: return 18;
    case 295446: return 18;
    case 295439: return 18;
    case 295449: return 18;
    case 295447: return 18;
    case 295448: return 18;
      // Scan 10
    case 295450: return 19;
    case 295453: return 19;
    case 295454: return 19;
    case 295455: return 19;
    case 295456: return 19;
      // Scan 11
    case 295459: return 20;
    case 295458: return 20;
    case 295457: return 20;
      // Scan 12
    case 295642: return 21;
    case 295632: return 21;
    case 295628: return 21;
    case 295634: return 21;
    case 295644: return 21;
      // Scan 13
    case 295638: return 22;
    case 295649: return 22;
    case 295636: return 22;
    case 295650: return 22;
    case 295635: return 22;
    case 295645: return 22;
      // Scan 14
    case 295639: return 23;
    case 295648: return 23;
    case 295640: return 23;
    case 295647: return 23;
    case 295641: return 23;
    case 295646: return 23;
      // Scan 15
    case 296075: return 24;
    case 296083: return 24;
    case 296084: return 24;
    case 296085: return 24;
    case 296087: return 24;
    case 296088: return 24;
    case 296089: return 24;
    case 296090: return 24;
    case 296091: return 24;
    case 296111: return 24;
    case 296112: return 24;
    case 296113: return 24;
    case 296115: return 24;
    case 296116: return 24;
      // Scan 16
    case 296092: return 25;
    case 296093: return 25;
    case 296095: return 25;
    case 296096: return 25;
    case 296097: return 25;
      // Scan 17
    case 296098: return 26;
    case 296099: return 26;
    case 296100: return 26;
    case 296101: return 26;
    case 296103: return 26;
      // Scan 18
    case 296104: return 27;
    case 296107: return 27;
    case 296108: return 27;
    case 296109: return 27;
    case 296110: return 27;
      // Scan 19:
    case 296644: return 28;
    case 296646: return 28;
    case 296647: return 28;
    case 296642: return 28;
    case 296643: return 28;
      // Scan 20:
    case 296665: return 29;
    case 296666: return 29;
    case 296668: return 29;
    case 296669: return 29;
    case 296674: return 29;
    case 296664: return 29;
    case 296675: return 29;
    case 296676: return 29;
    case 296678: return 29;
    case 296679: return 29;
    case 296680: return 29;
      // Scan 21
    case 297004: return 30;
    case 297006: return 30;
    case 297007: return 30;
  //case 297009: return 30;
    case 297010: return 30;
    case 297011: return 30;
  //case 297020: return 30; // No Express
    case 297012: return 30;
    case 297015: return 30;
  //case 297016: return 30;
    case 297017: return 30;
    case 297018: return 30;
    case 297019: return 30;
    case 297048: return 30;
    case 297047: return 30;
    case 297049: return 30;
      // Scan 22
    case 297179: return 31;
    case 297180: return 31;
    case 297181: return 31;
    case 297211: return 31;
    case 297215: return 31;
      // Scan 23
    case 297281: return 32;
    case 297282: return 32;
    case 297283: return 32;
    case 297284: return 32;
    case 297285: return 32;
    case 297286: return 32;
    case 297287: return 32;
    case 297288: return 32;
    case 297289: return 32;
    case 297290: return 32;
    case 297291: return 32;
      // Scan 24
    case 299316: return 33;
    case 299317: return 33;
    case 299318: return 33;
    case 299324: return 33;
    case 299325: return 33;
    case 299326: return 33;
      // Scan 25
    case 300364: return 34;
    case 300365: return 34;
    case 300366: return 34;
    case 300367: return 34;
    case 300368: return 34;
    case 300369: return 34;
    case 300370: return 34;
    case 300371: return 34;
    case 300373: return 34;
    case 300374: return 34;
      // Scan 26
    case 300389: return 35;
    case 300390: return 35;
    case 300391: return 35;
    case 300392: return 35;
    case 300393: return 35;
    case 300394: return 35;
    case 300395: return 35;
    case 300396: return 35;
    case 300397: return 35;
    case 300398: return 35;

      // Scan 27 and 28
    case 303794: return 36;
    case 303795: return 36+(ls>95);

      // Scan 29 - 27 Oct 2017
      // http://cmsonline.cern.ch/cms-elog/1018019
//  case 305745: return 38; // ECAL TESTS
//  case 305746: return 38; // ECAL TESTS
    case 305747: return 38;
    case 305748: return 38;
    case 305749: return 38;
    case 305750: return 38;
    case 305751: return 38;
    case 305752: return 38;
    case 305753: return 38;
    case 305754: return 38;
    case 305755: return 38;

      // 2018
      // Scan 1 - 17 Apr 2018
      // https://mail.google.com/mail/u/0/#inbox/162d46b69fe1d2ed
    case 314496: return 39;
//  case 314497: return 39;
    case 314498: return 39;
//  case 314499: return 39;
    case 314500: return 39;
//  case 314501: return 39;
    case 314502: return 39;
//  case 314503: return 39;
    case 314504: return 39;
//  case 314506: return 39;
//  case 314507: return 39;
    case 314508: return 39;
//  case 314509: return 39;
    case 314510: return 39;
//  case 314511: return 39;
    case 314512: return 39;
//  case 314513: return 39;
//  case 314515: return 39;
      // Scan 2 - 17 Apr 2018
      // https://mail.google.com/mail/u/0/#inbox/162d8c0492f37458
    case 314515: return 40;
    case 314524: return 40;
    case 314527: return 40;
      // Scan 3 - 19 Apr 2018 (Additional points, replacing scan 1)
      // http://cmsonline.cern.ch/cms-elog/1037026
    case 314652: return 39;
    case 314653: return 39;
    case 314654: return 39;
    case 314655: return 39;
    case 314656: return 39;
    case 314657: return 39; // 0.5 L1-2, 1.5 L3-4/FPix
    case 314658: return 39;
    case 314659: return 39;
    case 314660: return 39;
    case 314661: return 39;
      // Scan 4 - 06 Jun 2018
      // http://cmsonline.cern.ch/cms-elog/1046496
    case 317475: return 41;
    case 317480: return 41;
    case 317481: return 41;
    case 317482: return 41;

      // 2021
      // Scan 1 - Oct 2021
      // http://cmsonline.cern.ch/cms-elog/1127350
    case 346373: return 42;
    case 346374: return 42;
    case 346375: return 42;
    case 346377: return 42;
    case 346378: return 42;
    case 346379: return 42;
    case 346380: return 42;
    case 346383: return 42;
    case 346384: return 42;
    case 346389: return 42;
      //-----------------------------------------
      // Following the scan, the default timing set to +3ns
      // for all layers/disk after the scan
      // (http://cmsonline.cern.ch/cms-elog/1127357).
      // Used in fills 7517-7524
      //-----------------------------------------
      // Default changed to +3/6/9/9 ns (L1/L2/L3/L4) and
      // +9ns for FPix starting from the fill 7525
      // (http://cmsonline.cern.ch/cms-elog/1127699)
      //-----------------------------------------
      // Scan 2 - Nov 2021 mini scan
      // http://cmsonline.cern.ch/cms-elog/1127922
    case 346508: return 43;
    case 346509: return 43;
    case 346510: return 43;
    case 346511: return 43;
    case 346512: return 43;

      // 2022
      // Scan 1 - june 2022 mini scan
      // http://cmsonline.cern.ch/cms-elog/1142142
    case 352903: return 44;
    case 352906: return 44;
    case 352907: return 44;
    case 352908: return 44;
    case 352909: return 44;

    case 352931: return 44;

      // 2022
      // Scan 2 - July 2022 full scan
      // http://cmsonline.cern.ch/cms-elog/1145828
    case 355103: return 45;
    case 355104: return 45;
    case 355105: return 45;
    case 355106: return 45;
    case 355107: return 45;
    case 355108: return 45;
    case 355109: return 45;
    case 355110: return 45;
    case 355111: return 45;
    case 355112: return 45;
    case 355113: return 45;
    case 355114: return 45;
    case 355117: return 45;
    case 355118: return 45;
    case 355119: return 45;
    case 355120: return 45;
    case 355121: return 45;
    case 355122: return 45;
    case 355123: return 45;
    case 355124: return 45;
    case 355127: return 45;
    case 355128: return 45;
    case 355129: return 45;
      // 2022
      // Scan 3 - Sep 2022 mini scan
      // http://cmsonline.cern.ch/cms-elog/1157556
    case 359576: return 46;
    //.
    //.
    //. Fill here the new run numbers
    //. and scan id
    //.
    //.

    default:
      return -1;
    }
  }

  float delay(int run, int ls, int orbit) {
    switch (run) {
      // Delay Scan - 2011
    case 160413:
      return 
        orbit   <  11531874 ?  25
        : orbit <  22836667 ?   0
        : orbit <  36525473 ? NOVAL_I // BAD
        : orbit <  47699601 ?   7 
        : orbit <  60471838 ?   8
        : orbit <  71445138 ?  10
        : orbit <  84930036 ? -25
        : orbit < 100147197 ? NOVAL_I // BAD
        : orbit < 114600000 ?  14
        : orbit < 129039651 ?  16
        : orbit < 145100000 ? -12
        : orbit < 160586081 ?  10
        : orbit < 174462084 ?  -6
        : orbit < 191550000 ?  -8
        : 12;
    case 160497:
      return
        orbit   < 11923615 ? NOVAL_I
        : orbit < 23009846 ? -4
        : orbit < 34154357 ? -2
        : NOVAL_I; // BAD 
    case 160577:
      return
        orbit   < 10359519 ? NOVAL_I
        : orbit < 26677701 ? 4
        : orbit < 40220000 ? 18
        : orbit < 53440000 ? 20
        : orbit < 66319978 ? 22
        : 14;
    case 160578:
      return
        orbit   <   1245694 ? NOVAL_I
        : orbit <  14309529 ? 14
        : orbit <  43223561 ? 16
        : orbit <  71862094 ? 15
        : orbit < 108617422 ? 13
        : NOVAL_I;
      // 2012 - April
    case 190411 :
      return
        ls   <  26 ?  13
        : ls <  44 ?  -6
        : ls <  63 ? -12
        : ls <  80 ? -18
        : ls <  94 ?   6
        : ls < 108 ?  12
        : ls < 127 ?  NOVAL_I
        : ls < 150 ?  13
        : ls < 175 ?  14
        : ls < 196 ?  15
        : ls < 214 ?  16
        : ls < 230 ?  12
        : ls < 246 ?  17
        : ls < 261 ?  18
        : ls < 277 ?  20
        : ls < 292 ?   0
        : ls < 309 ?  -2
        : -4;
    case 190456:
      return
        ls   <  70  ?  13
        : ls <  88  ?   2
        : ls < 108  ?   6
        : ls < 132  ?  10
        : ls < 149  ?  11
        : ls < 164  ?  38
        : ls < 174  ? -12
        : NOVAL_I;
      // 2012 - July
    case 198022: // New Vana Settings
      return 
        orbit   < 47500000 ? NOVAL_I
        : orbit < 49500000 ? 13
        : orbit < 53000000 ?  1
        : orbit < 56500000 ? 24
        : orbit < 60000000 ? 22
        : 20  ;
    case 198023:
      return
        orbit   <  4906628 ? 18
        : orbit <  9006831 ? 16
        : orbit < 12767345 ? 14
        : orbit < 16996865 ? 12
        : orbit < 21167493 ? 10
        : orbit < 25000000 ?  8
        : NOVAL_I;
    case 198048: // Old Vana Settings
      return
        orbit   <  2600000 ?  1
        : orbit <  5600000 ? 24
        : orbit <  8600000 ? 22
        : orbit < 12000000 ? 20
        : orbit < 15200000 ? 18
        : 16;
      // 2015 - 03 June - 0T
    case 246908:
      return ls<70 ? NOVAL_I : 11;
    case 246919:
      return
        ls   < 10 ? -10 // 11ns, but somehow l1 efficiencies are different
        : ls < 24 ? NOVAL_I // somehow l1 efficiencies are different - l1 occupancy ~0
        : ls < 38 ? 47
        : -3;
    case 246920:
      return NOVAL_I; // Bad run
    case 246923:
      return
        ls   <   9 ? NOVAL_I // Supposed to be 34ns
        : ls <  22 ? 10
        : 28;
    case 246926:
      return
	ls   <   7 ? NOVAL_I // Supposed to be 28ns, but the point is well off
        : ls <  20 ? 16
        : ls <  32 ? 26
        : ls <  43 ? 24
        : ls <  56 ? 20
        : ls <  67 ? 18
        : ls <  79 ? 14
        : ls <  91 ? 12
        : ls < 102 ? 30
        : ls < 113 ?  8
        : ls < 124 ?  6
        : ls < 135 ?  2
        : ls < 147 ?  0
        : ls < 160 ? -2
        : ls < 172 ? -5
        : ls < 183 ? 36
        : ls < 196 ? 32
        : ls < 210 ? 19
        : ls < 242 ? 16
        : 18;
    case 246930:
      return 22;
    case 246936:
      return NOVAL_I; // Supposed to be 14ns, but it likely remained at 11ns
      
      // 2015 - July - 3.8T
    case 251027:
      return NOVAL_I; // 22ns
    case 251028:
      return ls<20? 22 : 20;
    case 251131:
      return
        ls   < 25 ? 22
        : ls < 40 ? 21
        : 23;
    case 251134:
      return
        ls   < 21 ? 24
        : ls < 35 ? 25
        : ls < 48 ? 26
        : ls < 63 ? 27
        : 20;

      // 2016 - April - 0T
    case 271188: 
      return 22;
    case 271191: 
      return
	ls  >=15 && ls<= 56 ? 21
	: ls>=68 && ls<=110 ? 19
	: NOVAL_I;
    case 271192: 
      return
	ls  >= 3 && ls<= 46 ? 23
	: NOVAL_I;
    case 271193: 
      return
	ls  >= 4 && ls<= 44 ? 24
	: ls>=47 && ls<= 92 ? 25
	: ls>=95 && ls<=110 ? 20
	: NOVAL_I;
      
      // 2016 - April - 3.8T
    case 272021: 
      return
	ls  >=  5 && ls<= 17 ? 21
	: ls>= 19 && ls<= 28 ? 22
	: ls>= 29 && ls<= 38 ? 23
	: ls>= 40 && ls<= 48 ? 24
	: ls>= 50 && ls<= 58 ? 25
	: ls>= 60 && ls<= 69 ? 26
	: ls>= 71 && ls<= 80 ? 27
	: ls>= 81 && ls<= 90 ? 28
	: ls>= 92 && ls<=101 ? 29
	: ls>=102 && ls<=111 ? 30
	: ls>=113 && ls<=123 ? 31
	: NOVAL_I;
      
      // 2016 - May - 3.8T
    case 272761: 
      return
	ls  >=  5 && ls<= 14 ? 32
	: ls>= 16 && ls<= 24 ? 33
	: ls>= 25 && ls<= 34 ? 34
	: ls>= 35 && ls<= 43 ? 35
	: ls>= 45 && ls<= 53 ? 36
	: ls>= 54 && ls<= 63 ? 37
	: ls>= 64 && ls<= 72 ? 38
	: NOVAL_I;
      
    case 272762: 
      return
	ls  >=  3 && ls<=  11 ? 39
	: ls>= 12 && ls<=  21 ? 40
	: ls>= 22 && ls<=  30 ? 42
	: ls>= 32 && ls<=  40 ? 44
	: ls>= 41 && ls<=  49 ? 46
	: ls>= 51 && ls<=  59 ? 28
	: ls>= 60 && ls<=  69 ? 24
	: ls>= 70 && ls<=  78 ? 20
	: ls>= 79 && ls<=  85 ? 41
	: ls>= 86 && ls<=  92 ? 43
	: ls>= 93 && ls<=  98 ? 45
	: ls>= 99 && ls<= 104 ? 47
	: NOVAL_I;
      
    case 277984: 
      return
	ls  >= 1 && ls<= 15 ? 22
	: NOVAL_I;
      
    case 277990: 
      return
	ls  >=   4 && ls<=  27 ? 21
	: ls>=  30 && ls<=  57 ? 23
	: ls>=  59 && ls<=  84 ? 24
	: ls>=  87 && ls<= 111 ? 25
	: ls>= 115 && ls<= 140 ? 20
	: ls>= 144 && ls<= 164 ? 26
	: ls>= 167 && ls<= 181 ? 19
	: ls>= 184 && ls<= 197 ? 27
	: NOVAL_I;

      // 2017 - May 23 - Coarse Timing Scan
      /*
	// Scan 1 - http://cmsonline.cern.ch/cms-elog/985548
	294928    162    +6 ns     31
	294929    163    +6 ns      6
	294931    164    +6 ns    -19
	294932    162   +18 ns     43
	294933    163   +18 ns     18
	294934    164   +18 ns     -7
	294935    165   +18 ns    -32
	294936    164    +0 ns    -25
	294937    162    +0 ns     25
	294939    164   +12 ns    -13
	294940    163   +12 ns     12
	294947    163    +0 ns      0
	294949    162    +3 ns     28
	294950    163   +21 ns     21
	294951    163   +15 ns     15
	294952    163    +9 ns      9
	294953    163    +3 ns      3
	294954    164   +21 ns     -4
	294955    164   +15 ns    -10
	294956    164    +3 ns    -22
	294957    163    +0 ns      0
	294960    163    +6 ns      6
	// Scan 2 - http://cmsonline.cern.ch/cms-elog/985617
	294987    163    +0 ns      0
	294986    163    +3 ns      3
	294988    163    +6 ns      6
	// Scan 3 - http://cmsonline.cern.ch/cms-elog/985940
	295123    163    +0 ns      0
	295124    163    +2 ns      2
	295125    163   +18 ns     18
	295126    163   +21 ns     21
	295133    163    +4 ns      4
	295134    163    +8 ns      8
	295135    163   +10 ns     10
	// Scan 4 - http://cmsonline.cern.ch/cms-elog/986220
        295194    163    +0 ns      0
        295197    163    +2 ns      2
        295199    163    +4 ns      4
        295200    163    +8 ns      8
        295201    163   +10 ns     10
        295202    163   +12 ns     12
        295203    163   +18 ns     18
	// Scan 5 - http://cmsonline.cern.ch/cms-elog/986619
        295342    164   +18 ns     18
        295341    163    +0 ns      0
        295340    163    +6 ns      6
        295343    164   +12 ns    -13
	// Scan 6 - http://cmsonline.cern.ch/cms-elog/986619
        295344    164   +18 ns     -7
        295346    163    +0 ns      0
        295347    163    +0 ns      0
        295348    163    +6 ns      6
        295345    164   +12 ns    -13
        295349    163    +3 ns      3
	// Scan 7 - http://cmsonline.cern.ch/cms-elog/986797
	295366    163    +6 ns      6
	295377    163    +0 ns      0
	295378    164   +21 ns     -4
	295379    164   +18 ns     -7
	295380    164   +12 ns    -13
	// Scan 8(-11) - http://cmsonline.cern.ch/cms-elog/987183
        295437    163    +0 ns      0
        295438    163    +3 ns      3
        295436    163    +6 ns      6
        295460    163   +12 ns     12
        // Scan 9
        295440    163    +0 ns      0
        295445    163    +3 ns      3
        295446    163    +5 ns      5
        295439    163    +6 ns      6
        295449    163    +7 ns      7
        295447    163    +9 ns      9
        295448    163   +12 ns     12
        // Scan 10
        295450    163    +0 ns      0
        295453    163    +3 ns      3
        295454    163    +6 ns      6
        295455    163    +9 ns      9
        295456    163   +12 ns     12
        // Scan 11
        295459    163    +0 ns      0
        295458    163    +6 ns      6
        295457    163   +12 ns     12
	// Scan 12(-14) - http://cmsonline.cern.ch/cms-elog/987662
	295642    163    +0 ns      0
	295632    163    +3 ns      3
	295628    163    +6 ns      6
	295634    163    +9 ns      9
	295644    163   +12 ns     12
	// Scan 13
	295638    163    +3 ns      3
	295649    163  +4.5 ns    4.5
	295636    163    +6 ns      6
	295650    163  +7.5 ns    7.5
	295635    163    +9 ns      9
	295645    163   +12 ns     12
	// Scan 14
	295639    163    +3 ns      3
	295648    163  +4.5 ns    4.5
	295640    163    +6 ns      6
	295647    163  +7.5 ns    7.5
	295641    163    +9 ns      9
	295646    163   +12 ns     12
	// Scan 15(-18) - http://cmsonline.cern.ch/cms-elog/988907
        296075    163    +6 ns      6
        296083    163    +3 ns      3
        296084    163  +4.5 ns    4.5
        296085    163  +7.5 ns    7.5
        296087    163    +9 ns      9
        296088    163 +10.5 ns   10.5
        296089    163   +12 ns     12
        296090    163   +15 ns     15
        296091    163   +18 ns     18
        296111    163  +1.5 ns    1.5
        296112    163    +0 ns      0
        296113    164   +21 ns     -4
        296115    164   +18 ns     -7
	// Scan 16
        296092    163    +3 ns      3
        296093    163  +4.5 ns    4.5
        296095    163    +6 ns      6
        296096    163  +7.5 ns    7.5
        296097    163    +9 ns      9
	// Scan 17
        296098    163    +3 ns      3
        296099    163  +4.5 ns    4.5
        296100    163    +6 ns      6
        296101    163  +7.5 ns    7.5
        296103    163    +9 ns      9
	// Scan 18
        296104    163    +3 ns      3
        296107    163  +4.5 ns    4.5
        296108    163    +6 ns      6
        296109    163  +7.5 ns    7.5
        296110    163    +9 ns      9	
      */

      // Scan 1
    case 294928: return   31;
    //case 294929: return    6;
    case 294931: return  -19;
    case 294932: return   43;
    case 294933: return   18;
    case 294934: return   -7;
    case 294935: return  -32;
    case 294936: return  -25;
    case 294937: return   25;
    case 294939: return  -13;
    case 294940: return   12;
    //case 294947: return    0;
    case 294949: return   28;
    case 294950: return   21;
    case 294951: return   15;
    case 294952: return    9;
    case 294953: return    3;
    case 294954: return   -4;
    case 294955: return  -10; // missing run
    case 294956: return  -22; // was -10
    case 294957: return    0;
    case 294960: return    6;
      // Scan 2
    case 294987: return    0;
    case 294986: return    3;
    case 294988: return    6;
      // Scan 3
    case 295123: return    0;
    case 295124: return    2;
    case 295125: return   18;
    case 295126: return   21;
    case 295133: return    4;
    case 295134: return    8;
    case 295135: return   10;
      // Scan 4
    case 295194: return    0;
    case 295197: return    2;
    case 295199: return    4;
    case 295200: return    8;
    case 295201: return   10;
    case 295202: return   12;
    case 295203: return   18;
      // Scan 5
    case 295342: return   -7;
    case 295341: return    0;
    case 295340: return    6;
    case 295343: return  -13;
      // Scan 6
    case 295344: return   -7;
    case 295346: return    0;
    case 295347: return    0;
    case 295348: return    6;
    case 295345: return  -13;
    case 295349: return    3;
      // Run 295371
    case 295371: return    6;
      // Scan 7
    case 295366: return    6; 
    case 295377: return    0;
    case 295378: return   -4;
    case 295379: return   -7;
    case 295380: return  -13;
      // Scan 8
    case 295437: return    0;
    case 295438: return    3;
    case 295436: return    6;
    case 295460: return   12;
      // Scan 9
    case 295440: return    0;
    case 295445: return    3;
    case 295446: return    5;
    case 295439: return    6;
    case 295449: return    7;
    case 295447: return    9;
    case 295448: return   12;
      // Scan 10
    case 295450: return    0;
    case 295453: return    3;
    case 295454: return    6;
    case 295455: return    9;
    case 295456: return   12;
      // Scan 11
    case 295459: return    0;
    case 295458: return    6;
    case 295457: return   12;
      // Scan 12(-14)
    case 295642: return    0;
    case 295632: return    3;
    case 295628: return    6;
    case 295634: return    9;
    case 295644: return   12;
      // Scan 13
    case 295638: return    3;
    case 295649: return  4.5;
    case 295636: return    6;
    case 295650: return  7.5;
    case 295635: return    9;
    case 295645: return   12;
      // Scan 14
    case 295639: return    3;
    case 295648: return  4.5;
    case 295640: return    6;
    case 295647: return  7.5;
    case 295641: return    9;
    case 295646: return   12;
      // Scan 15
    //case 296075: return    6;
    case 296083: return    3;
    case 296084: return  4.5;
    case 296085: return  7.5;
    case 296087: return    9;
    case 296088: return 10.5;
    case 296089: return   12;
    case 296090: return   15;
    case 296091: return   18;
    case 296111: return  1.5;
    case 296112: return    0;
    case 296113: return   -4;
    case 296115: return   -7;
    case 296116: return    6;
      // Scan 16
    case 296092: return    3;
    case 296093: return  4.5;
    case 296095: return    6;
    case 296096: return  7.5;
    case 296097: return    9;
      // Scan 17
    case 296098: return    3;
    case 296099: return  4.5;
    case 296100: return    6;
    case 296101: return  7.5;
    case 296103: return    9;
      // Scan 18
    case 296104: return    3;
    case 296107: return  4.5;
    case 296108: return    6;
    case 296109: return  7.5;
    case 296110: return    9;
      // Scan 19:
    case 296644: return   18;
    case 296646: return   14;
    case 296647: return   11;
    case 296642: return    6;
    case 296643: return    6;
      // Scan 20:
    case 296665: return   18;
    case 296666: return   14;
    case 296668: return   11;
    case 296669: return    9;
    case 296674: return  7.5;
    case 296664: return    6;
    case 296675: return  4.5;
    case 296676: return  1.5;
    case 296678: return    0;
    case 296679: return   -3;
    case 296680: return   -7;
      // Scan 21
    case 297004: return   -7;
    case 297006: return   -4;
    case 297007: return    0;
  //case 297009: return  1.5;
    case 297010: return    3;
    case 297011: return  4.5;
  //case 297020: return    6; // No Express
    case 297012: return  7.5;
    case 297015: return    9;
  //case 297016: return 10.5;
    case 297017: return   12;
    case 297018: return   15;
    case 297019: return   18;
    case 297048: return  1.5;
    case 297047: return    6;
    case 297049: return 10.5;
      // Scan 22
    case 297179: return   11;
    case 297180: return   10;
    case 297181: return    9;
    case 297211: return   12;
    case 297215: return   11;
      // Scan 23
    case 297281: return    6;
    case 297282: return   -4;
    case 297283: return   -1;
    case 297284: return    2;
    case 297285: return    4;
    case 297286: return    8;
    case 297287: return   10;
    case 297288: return   13;
    case 297289: return   16;
    case 297290: return  5.5;
    case 297291: return  6.5;
      // Scan 24
    case 299316: return    6;
    case 299317: return    9;
    case 299318: return    9;
    case 299324: return    3;
    case 299325: return   12;
    case 299326: return   15;
      // Scan 25
    case 300364: return    6;
    case 300365: return    1;
    case 300366: return    3;
    case 300367: return    4;
    case 300368: return    5;
    case 300369: return    7;
    case 300370: return    8;
    case 300371: return    9;
    case 300373: return   11;
    case 300374: return   13;
      // Scan 26
    case 300389: return    6;
    case 300390: return    1;
    case 300391: return    3;
    case 300392: return    4;
    case 300393: return    5;
    case 300394: return    7;
    case 300395: return    8;
    case 300396: return    9;
    case 300397: return   11;
    case 300398: return   13;
      // Scan 27,28
    case 303794:
      return
	// Scan 27
	ls  >=   4 && ls<=  16 ?  1.5 
	: ls>=  17 && ls<=  22 ?  0
	: NOVAL_I;
    case 303795:
      return NOVAL_I; // Bad scan points
      /*
      return
	ls  >=   2 && ls<=  11 ?  0
	: ls>=  13 && ls<=  22 ? -2
	: ls>=  25 && ls<=  35 ? -4
	: ls>=  38 && ls<=  47 ? -6
	: ls>=  50 && ls<=  59 ?  3
	: ls>=  62 && ls<=  71 ?  5
	: ls>=  73 && ls<=  82 ?  7
	: ls>=  85 && ls<=  94 ?  9
	// Scan 28
	: ls>=  96 && ls<= 105 ?  1.5
	: ls>= 107 && ls<= 117 ? -4
	: ls>= 119 && ls<= 128 ? -2
	: ls>= 130 && ls<= 139 ?  0
	: ls>= 141 && ls<= 149 ?  3
	: ls>= 152 && ls<= 161 ?  5
	: ls>= 163 && ls<= 170 ?  7
	: ls>= 173 && ls<= 181 ? -6
	: ls>= 184 && ls<= 192 ?  9
	: NOVAL_I;
      */

      // Scan 29 - 27 Oct 2017
      // http://cmsonline.cern.ch/cms-elog/1018019
    case 305745: return  1.5;
    case 305746: return  1.5;
    case 305747: return  1.5;
    case 305748: return  0; 
    case 305749: return -2;
    case 305750: return -4;
    case 305751: return -6;
    case 305752: return  3;
    case 305753: return  5;
    case 305754: return  7;
    case 305755: return  9;
      
      // 2018
      // Scan 1 - 17 Apr 2018
      // https://mail.google.com/mail/u/0/#inbox/162d46b69fe1d2ed
    case 314496: return  13.5;
//  case 314497: return -10.5;
    case 314498: return   7.5;
//  case 314499: return  -4.5;
    case 314500: return   4.5;
//  case 314501: return  -1.5;
    case 314502: return   3.5;
//  case 314503: return  -0.5;
    case 314504: return   2.5;
//  case 314506: return   0.5;
//  case 314507: return   1.5;
    case 314508: return   9.5;
//  case 314509: return  -6.5;
    case 314510: return  11.5;
//  case 314511: return  -8.5;
    case 314512: return   5.5;
//  case 314513: return  -2.5;
//  case 314515: return   1.5;
      // Scan 2 - 17 Apr 2018
      // https://mail.google.com/mail/u/0/#inbox/162d8c0492f37458
    case 314515: return   1.5;
    case 314524: return   2.5;
    case 314527: return   0.5;
      // Scan 3 - 19 Apr 2018
      // http://cmsonline.cern.ch/cms-elog/1037026
    case 314652: return  -2.5;
    case 314653: return  -1.5;
    case 314654: return  -0.5;
    case 314655: return   0.5;
    case 314656: return   1.5;
    case 314657: return   1.0; // 0.5 L1-2, 1.5 L3-4/FPix
    case 314658: return  -4.5;
    case 314659: return  -6.5;
    case 314660: return  -8.5;
    case 314661: return -10.5;
      // Scan 4 - 06 Jun 2018
      // http://cmsonline.cern.ch/cms-elog/1046496
    case 317475: return  0;
    case 317480: return  8;
    case 317481: return -6;
    case 317482: return  6;

      // 2021
      // Scan 1 - Oct 2021
      // http://cmsonline.cern.ch/cms-elog/1127350
    case 346373: return   0;
    case 346374: return  12;
    case 346375: return -12;
    case 346377: return   6;
    case 346378: return  -6;
    case 346379: return   9;
    case 346380: return  -9;
    case 346383: return  18;
    case 346384: return   3;
    case 346389: return 3.5; // new reference (actually 3, using 3.5 for plotting purposes)
      //-----------------------------------------
      // Following the scan, the default timing set to +3ns
      // for all layers/disk after the scan
      // (http://cmsonline.cern.ch/cms-elog/1127357).
      // Used in fills 7517-7524
      //-----------------------------------------
      // Default changed to +3/6/9/9 ns (L1/L2/L3/L4) and
      // +9ns for FPix starting from the fill 7525
      // (http://cmsonline.cern.ch/cms-elog/1127699)
      //-----------------------------------------
      // Scan 2 - Nov 2021 mini scan
      // http://cmsonline.cern.ch/cms-elog/1127922
    case 346508: return  -3;
    case 346509: return   3;
    case 346510: return   6;
    case 346511: return   9;
    case 346512: return   0;

      // 2022
      // Scan 1 - june 2022 mini scan
      // http://cmsonline.cern.ch/cms-elog/1142142
    case 352903: return   3.5;
    case 352906: return   6.5;
    case 352907: return   9.5;
    case 352908: return   -2.5; //the elog states 22.5 ns, some configuration tricks were used to achieve a -2.5 ns delay
    case 352909: return   0.5;

      // 2022
      // Scan 2 - July 2022 full scan
      // http://cmsonline.cern.ch/cms-elog/1145828
    case 355103: return   0;
    case 355104: return   -2;
    case 355105: return   -5;
    case 355106: return   -9;
    case 355107: return   -13;
    case 355108: return   2;
    case 355109: return   5;
    case 355110: return   9;
    case 355111: return   13;
    case 355112: return   -1.;
    case 355113: return   1.;
    case 355114: return   -3;
    case 355117: return   -3;
    case 355118: return   3;
    case 355119: return   4;
    case 355120: return   -7;
    case 355121: return   6;
    case 355122: return   7;
    case 355123: return   -11;
    case 355124: return   11;
    case 355127: return   -15;
    case 355128: return   -17;
    case 355129: return   -19;

      // 2022
      // Scan 3 - Sep 2022 mini scan
      // http://cmsonline.cern.ch/cms-elog/1157556
    case 359576: return 5.;
    //.
    //.
    //. Fill here the new run numbers and delays
    //.
    //.
    case 359584: return 0.;

      /*
    case 2: 
      return
	ls  >=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: ls>=     && ls<=     ? 
	: NOVAL_I;
      */

    default:
      return NOVAL_I;
    }
  }
  
  //________________________________________________________________________________________
  //                                  HV Bias Scans
  
  int hv_scan_no(int run) {
    switch (run) {
    case 132599: return 0; // 2010 April 05 - L3,D1 (1 hv group)
    case 132601: return 0;
    case 132602: return 0;
    case 149182: return 1; // 2010 Oct 28 - L1,L3,D1 (1 hv group)
    case 160431: return 2; // 2011 March 14,16,18 - L1,L3,D1 (1 hv group)
    case 160578: return 2;
    case 160579: return 2;
    case 160819: return 2;
    case 160827: return 2;
    case 160835: return 2;
    case 165098: return 3; // 2011 May 15 - L1 (1 hv group)
    case 165099: return 3;
    case 170000: return 4; // 2011 July 14 - L1 (Full)
    case 171897: return 5; // 2011 July 28 - L3 (Full)
    case 172488: return 6; // 2011 August 03 - L2 (Full)
    case 175834: return 7; // 2011 September 07 - L1,D1 (1 hv group)
    case 178367: return 8; // 2011 October 12 - L1 (1 hv group)
    case 180076: return 9; // 2011 October 27 - L1 (1 hv group)
    case 180093: return 9;
    case 180241: return 10; // 2011 October 30 - D1 (1 hv group)
    case 180250: return 10;
    case 190538: return 11; // 2012 April 06 - L1-3, D1-2 (Full)
    case 190539: return 11;
    case 190591: return 11;
    case 190592: return 11;
    case 190593: return 11;
    case 190595: return 11;
    case 198023: return 12; // 2012 July 02 - L1-3, D1-2 (Full)
    case 198041: return 12;
    case 198044: return 12;
    case 198045: return 12;
    case 200786: return 13; // 2012 August 13 - L1 (Full)
    case 203739: return 14; // 2012 September 27 - L1 (Full)
    case 208392: return 15; // 2012 Dec 02 - L1-3,D1-2 (Full)
    case 208393: return 15;
    case 208394: return 15;
    case 208395: return 15;
    case 208397: return 15;
    case 210534: return 16; // 2013 Jan 21 - L1-3,D1 (1 hv group)
    case 247073: return 17; // 2015 Jun 08 - L1-3,D1-2 (Full)
    case 247078: return 17;
    case 247079: return 17;
    case 247081: return 17;
    case 247266: return 17;
    case 247267: return 17;
    case 247398: return 17;
    case 272008: return 19; // 2016 Apr 28 - L1-3, D1-2 (Full)
    case 272010: return 19;
    case 272011: return 19;
    case 272012: return 19;
    case 272014: return 19;
    case 272016: return 19;
    case 274998: return 20; // 2016 Jun 13 - L1-3, D1 (1 hv group)
    case 274999: return 20;
    case 276315: return 21; // 2016 Jul 04 - L1-3, D1 (1 hv group)
    case 276317: return 21;
    case 276318: return 21;
    case 283553: return 22; // 2016 Oct 20 - L1-3, D1-2 (Full)
    case 283560: return 22;
    default: return -1;
    }
  }

  // Define Layer 1 Scans below
  int hv_l1(int run, int ls, int orbit) {
    switch (run) {
      // hv scan 2010 Oct 28 - L1,L3,FPix modules
    case 149182:
      return
        ls  < 16 ? 130
        : ls< 30 ? 110
        : ls< 47 ? 100
        : ls< 64 ?  90
        : ls< 81 ?  80
        : ls< 98 ?  70
        : ls<115 ?  60
        : ls<134 ?  50
        : ls<150 ?  40
        : ls<169 ?  30
        : 150;
      // hv scan 2011 March 14,16,18 - L1,L3,FPix modules
    case 160431:
      return 150;
    case 160578:
      return orbit<108617422 ? NOVAL_I : 30; // Exclude Delay scan
    case 160579:
      return
        orbit  < 10060929 ? 40
        : orbit< 20603100 ? 50
        : orbit< 30368455 ? 60
        : orbit< 36726096 ? 70
        : orbit< 41127055 ? 80
        : 90;
    case 160819:
      return
        orbit  <   734481 ?  NOVAL_I
        : orbit<  4945473 ? 150
        : orbit<  9184218 ?  70
        : orbit< 13531251 ?  80
        : orbit< 21375662 ?  90
        : orbit< 27850887 ? 100
        : NOVAL_I;
    case 160827:
      return 130;
    case 160835:
      return 150;
      // hv scan 2011 may 15 - Bpix_BmO_SEC6_LYR1-2_HV1
    case 165098:
      return
        ls  <169 ? 150
        : ls<235 ?  60
        : ls<302 ?  50
        : ls<379 ?  70
        : 40;
    case 165099:
      return ls< 33 ? 40 : 80;
      // voltage scan 2011 July 14 - L1
    case 170000:
      return
        orbit  <   75305 ? NOVAL_I
        : orbit< 6600594 ? 150
        : orbit<13798045 ?  20
        : orbit<20548946 ?  30
        : orbit<27295775 ?  40
        : orbit<34043021 ?  50
        : orbit<40787479 ?  60
        : orbit<47534688 ?  70
        : orbit<54281248 ?  80
        : orbit<61029618 ?  90
        : orbit<67777302 ? 100
        : 110;
      // voltage scan 2011 Sep 07 - L1, FPix module
    case 175834:
      return
        // L1 scan
        orbit  < 4600000 ? 150
        : orbit< 8000000 ? 100
        : orbit<11400000 ?  80
        : orbit<14800000 ?  70
        : orbit<18200000 ?  60
        : orbit<21600000 ?  50
        : orbit<25000000 ?  40
        : orbit<28300000 ?  30
        : orbit<31600000 ?  20
        : orbit<35000000 ?  10
        : orbit<38300000 ?   0
        : 150;
      // voltage scan 2011 Oct 12 - L1 module
    case 178367:
      return
        orbit  <22121144 ? 150
        : orbit<28980545 ? 130
        : orbit<35632848 ? 110
        : orbit<42301525 ?  90
        : orbit<49144222 ?  80
        : orbit<55705743 ?  70
        : orbit<62453171 ?  60
        : orbit<69382373 ?  50
        : orbit<75990540 ?  40
        : orbit<82987680 ?  30
        : orbit<89595172 ?  20
        : orbit<96264991 ?  10
        : orbit<102930200 ?  0
        : NOVAL_I;
      // voltage scan 2011 Oct 27 - L1 module
    case 180076:
      return
        orbit  <65271702 ? 150
        : orbit<69554218 ? 100
        : orbit<75434312 ?  70
        : orbit<79819278 ?  50
        : orbit<85070175 ?  40
        : orbit<89517576 ?  30
        : 20;
    case 180093:
      return
        orbit  < 3257552 ?  20
        : orbit< 7805011 ?  15
        : orbit<11807013 ?  10
        : orbit<16433020 ?   5
        : orbit<21057541 ?   0
        : orbit<22826117 ? NOVAL_I
        : 150;
      // voltage scan 2012 Apr 06 - L1, L2, L3, D1, D2
    case 190538:
      return
        ls< 50 ? 150 // L1
        : ls< 66 ?   0
        : ls< 78 ?   5
        : ls< 91 ?  10
        : ls<104 ?  15
        : ls<117 ?  20
        : 30;
    case 190539:
      return
        ls  <  3 ? NOVAL_I
        : ls< 17 ?  30
        : ls< 30 ?  40
        : ls< 47 ?  50
        : ls< 62 ?  70
        : ls< 75 ? 100
        : 150;
      // voltage scan 2012 Jul 02 - L1, L2, L3, D1, D2
    case 198023:
      return
        orbit  <25000000 ? NOVAL_I // L1
        : orbit<28800000 ? 150
        : orbit<30600000 ? 100
        : orbit<32800000 ?  80
        : orbit<35600000 ?  70
        : orbit<38200000 ?  60
        : orbit<39700000 ?  50
        : orbit<41100000 ?  40
        : orbit<42350000 ?  30
        : orbit<43900000 ?  20
        : 10;
    case 198041:
      return orbit  < 2600000 ?   5 : 150; // L2
      // voltage scan 2012 Aug 13 - Full Layer 1
    case 200786:
      return
        orbit  < 4000000 ? 150
        : orbit< 7400000 ? 100
        : orbit<11300000 ?  80
        : orbit<14200000 ?  70
        : orbit<17500000 ?  60
        : orbit<21500000 ?  50
        : orbit<24800000 ?  40
        : orbit<28300000 ?  30
        : orbit<31600000 ?  20
        : orbit<35100000 ?  10
        : orbit<38400000 ?   5
        : NOVAL_I;
      // voltage scan 2012 Sep 27 - Full Layer 1
    case 203739:
      return
        orbit  < 7500000 ? NOVAL_I
        : orbit<11400000 ? 100
        : orbit<14600000 ?  80
        : orbit<18000000 ?  60
        : orbit<21800000 ?  40
        : orbit<25400000 ?  30
        : orbit<29500000 ?  20
        : orbit<32200000 ?  10
        : orbit<36500000 ?   5
        : orbit<40494167 ? 150
        : NOVAL_I;
      // voltage scan 2012 Dec 02 - Full Layer 1-3, Disk 1-2
    case 208392:
      return
        orbit  < 5600000 ? 300
        : orbit< 7500000 ? 150
        : orbit<10300000 ? 100
        : 80;
    case 208393:
      return
        orbit  < 4300000 ?  70
        : orbit< 6300000 ?  60
        : orbit< 8600000 ?  50
        : orbit<11300000 ?  40
        : orbit<14300000 ?  30
        : orbit<16500000 ?  20
        : orbit<18800000 ?  10
        : orbit<20800000 ?   5
        : 150;
      // voltage scan 2013 Jan 21 - Layer 1-3, Disk 1 (1 HV Group)
    case 210534:
      return
        orbit  <15500000 ? 150
        : orbit<19150000 ? 100
        : orbit<23150000 ?  90
        : orbit<26650000 ?  80
        : orbit<30600000 ?  70
        : orbit<34550000 ?  60
        : orbit<37850000 ?  50
        : orbit<41700000 ?  40
        : orbit<45900000 ?  30
        : orbit<49400000 ?  20
        : orbit<53450000 ?  10
        : 150;
      // 2015 Jun 08 - L1-3, D1-2 (Full)
    case 247078:
      return 
	orbit<  10000000 ? 200  
	: orbit<55700000 ? NOVAL_I
	: 10;
    case 247079:
      return
	orbit<   1200000 ?  NOVAL_I
        : orbit< 5300000 ?  20
        : orbit< 9200000 ?  30
        : orbit<12300000 ?  40
        : orbit<15800000 ?  50
        : orbit<19200000 ?  60
	: 70;
    case 247081:
      return
        orbit<   4800000 ?  70
        : orbit< 8400000 ?  80
        : orbit<11900000 ?  90
        : 100;
    case 247266:
      return
        orbit<   6500000 ? NOVAL_I
        : orbit<10500000 ? 125
	: 150;
      // 2016 Apr 28 - L1-3, D1-2 (Full)
    case 272011:
      return
      	ls  >= 119 && ls<= 132 ?  10
	: ls>= 135 && ls<= 147 ?  20
	: ls>= 150 && ls<= 162 ?  30
	: ls>= 163 && ls<= 176 ?  40
	: ls>= 176 && ls<= 189 ?  50
	: NOVAL_I;
    case 272012:
      return
      	ls  >=   1 && ls<=  12 ?  60
	: ls>=  15 && ls<=  28 ?  70
	: ls>=  30 && ls<=  42 ?  80
	: ls>=  43 && ls<=  56 ?  90
	: ls>=  57 && ls<=  70 ? 100
	: ls>=  71 && ls<=  83 ? 125
	: ls>=  84 && ls<=  97 ? 150
	: ls>=  98 && ls<= 113 ? 250
	: NOVAL_I;
    case 272016:
      return 
	ls  >=  21 && ls<=  37 ? 200
	: NOVAL_I;
      // 2016 Jun 13 - L1-3, D1 (1 hv group)
    case 274998:
      return
	ls  >= 741 && ls<= 754 ?  10
	: ls>= 756 && ls<= 769 ?  20
	: ls>= 772 && ls<= 781 ?  30
	: ls>=   1 && ls<= 739 ? 200
	: NOVAL_I;
    case 274999:
      return
	ls  >=   3 && ls<=  30 ?  40
	: ls>=  35 && ls<=  49 ?  50
	: ls>=  52 && ls<=  67 ?  60
	: ls>=  70 && ls<=  82 ?  70
	: ls>=  85 && ls<=  97 ?  80
	: ls>= 100 && ls<= 112 ?  90
	: ls>= 115 && ls<= 131 ? 100
	: NOVAL_I;
      // 2016 Jul 04 - L1-3, D1 (1 hv group)
    case 276315:
      return
	ls  >=   1 && ls<= 149 ? 200
	: ls>= 152 && ls<= 164 ?  10
	: ls>= 167 && ls<= 178 ?  20
	: ls>= 182 && ls<= 194 ?  30
	: ls>= 196 && ls<= 214 ?  40
	: NOVAL_I;
    case 276317:
      return
	ls  >=   8 && ls<=  19 ?  50
	: ls>=  23 && ls<=  33 ?  60
	: ls>=  38 && ls<=  50 ?  70
	: ls>=  54 && ls<=  65 ?  80
	: ls>=  69 && ls<=  79 ?  90
	: ls>=  83 && ls<=  93 ? 100
	: NOVAL_I;
      // 2016 Oct 20 - L1-3, D1-2 (Full)
    case 283553:
      return
      	ls  >= 112 && ls<= 117 ?  10
	: ls>= 121 && ls<= 127 ?  20
	: ls>= 128 && ls<= 134 ?  30
	: ls>= 137 && ls<= 142 ?  40
	: ls>= 145 && ls<= 152 ?  50
	: ls>= 155 && ls<= 161 ?  60
	: ls>= 164 && ls<= 169 ?  70
	: ls>= 172 && ls<= 177 ?  80
	: ls>= 180 && ls<= 186 ?  90
	: ls>= 189 && ls<= 195 ? 100
	: ls>= 199 && ls<= 205 ? 125
	: ls>= 208 && ls<= 215 ? 150
	: ls>= 103 && ls<= 109 ? 200
	: NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_l1

  // Define Layer 2 Scans below
  int hv_l2(int run, int ls, int orbit) {
    switch (run) {
      // voltage scan 2011 Aug 03 - L2
    case 172488:
      return
        orbit  <14400000 ?  NOVAL_I
        : orbit<17500000 ?  80
        : orbit<20900000 ?  50
        : orbit<24200000 ?  20
        : orbit<27600000 ?  70
        : orbit<31100000 ?  40
        : orbit<34500000 ?  60
        : orbit<39600000 ?  30
        : 150;
      // voltage scan 2012 Apr 06 - L1, L2, L3, D1, D2
    case 190539:
      return
        ls  < 91 ? 150
        : ls<105 ?   0 // L2
        : ls<120 ?   5
        : ls<135 ?  10
        : ls<150 ?  15
        : ls<165 ?  20
        : ls<180 ?  30
        : ls<196 ?  40
        : ls<211 ?  50
        : ls<225 ?  70
        : ls<240 ? 100
        : 150;
      // voltage scan 2012 Jul 02 - L1, L2, L3, D1, D2
    case 198041:
      return
        orbit< 4700000 ? 150 // L2
        : orbit< 6700000 ? 100
        : orbit< 8700000 ?  80
        : orbit<12100000 ?  70
        : orbit<14100000 ?  60
        : 50;
    case 198044:
      return
        orbit  < 1300000 ?  50
        : orbit< 4000000 ?  40
        : orbit< 6000000 ?  30
        : orbit< 8000000 ?  20
        : orbit<10700000 ?  10
        : orbit<12800000 ?   5
        : 150;
      // voltage scan 2012 Dec 02 - Full Layer 1-3, Disk 1-2
    case 208393:
      return
        orbit  <21100000 ? 150
        : orbit<25900000 ? 300
        : orbit<28200000 ? 100
        : orbit<30700000 ?  80
        : orbit<32700000 ?  70
        : orbit<35500000 ?  60
        : orbit<37700000 ?  50
        : orbit<40300000 ?  40
        : orbit<42300000 ?  30
        : orbit<44500000 ?  20
        : orbit<48300000 ?  10
        : orbit<50600000 ?   5
        : 150;
      // voltage scan 2013 Jan 21 - Layer 1-3, Disk 1 (1 HV Group)
    case 210534:
      return hv_l1(run, ls, orbit);
      // 2015 Jun 08 - L1-3, D1-2 (Full)
    case 247266:
      return
        orbit<  15300000 ? 200
        : orbit<18900000 ?  10
        : orbit<21500000 ?  20
        : orbit<25000000 ?  30
        : orbit<28400000 ?  40
        : orbit<31900000 ?  50
	: 60;
    case 247267:
      return orbit<19200000 ?  60 : 70;
    case 247398:
      return
        orbit<   5500000 ? NOVAL_I
        : orbit< 9300000 ? NOVAL_I
        : orbit<12800000 ?  90
        : orbit<16000000 ? 100
        : orbit<19600000 ? 125
	: orbit<23800000 ? 150
	: NOVAL_I;
      // 2016 Apr 28 - L1-3, D1-2 (Full)
    case 272012:
      return
	ls  >=  84 && ls<= 113 ? 200 
      	: ls>= 116 && ls<= 123 ?  10
	: ls>= 124 && ls<= 131 ?  20
	: ls>= 132 && ls<= 139 ?  30
	: ls>= 141 && ls<= 148 ?  40
	: ls>= 151 && ls<= 158 ?  50
	: ls>= 161 && ls<= 168 ?  60
	: ls>= 170 && ls<= 176 ?  70
	: ls>= 178 && ls<= 185 ?  80
	: ls>= 187 && ls<= 194 ?  90
	: ls>= 196 && ls<= 201 ? 100
	: NOVAL_I;
    case 272014:
      return
      	ls  >=   2 && ls<=  10 ? 125
	: ls>=  12 && ls<=  20 ? 150
	: ls>=  22 && ls<=  29 ? 250
	: NOVAL_I;
      // 2016 Jun 13 - L1-3, D1 (1 hv group)
    case 274998:
      return
	ls  >=   1 && ls<= 739 ? 200
	: NOVAL_I;
    case 274999:
      return
	ls  >= 319 && ls<= 329 ?  10
	: ls>= 333 && ls<= 344 ?  20
	: ls>= 348 && ls<= 358 ?  30
	: ls>= 363 && ls<= 373 ?  40
	: ls>= 378 && ls<= 388 ?  50
	: ls>= 395 && ls<= 406 ?  60
	: ls>= 410 && ls<= 424 ?  70
	: ls>= 428 && ls<= 439 ?  80
	: ls>= 443 && ls<= 454 ?  90
	: ls>= 459 && ls<= 470 ? 100
	: NOVAL_I;
      // 2016 Jul 04 - L1-3, D1 (1 hv group)
    case 276315:
      return
	ls  >=   1 && ls<= 149 ? 200
	: NOVAL_I;
    case 276318:
      return
	ls  >= 244 && ls<= 254 ?  10
	: ls>= 258 && ls<= 269 ?  20
	: ls>= 274 && ls<= 285 ?  30
	: ls>= 289 && ls<= 299 ?  40
	: ls>= 304 && ls<= 315 ?  50
	: ls>= 319 && ls<= 337 ?  60
	: ls>= 342 && ls<= 352 ?  70
	: ls>= 356 && ls<= 368 ?  80
	: ls>= 373 && ls<= 383 ?  90
	: ls>= 387 && ls<= 398 ? 100
	: NOVAL_I;
      // 2016 Oct 20 - L1-3, D1-2 (Full)
    case 283553:
      return
      	ls  >=   4 && ls<=  14 ?  10
	: ls>=  17 && ls<=  21 ?  20
	: ls>=  24 && ls<=  31 ?  30
	: ls>=  33 && ls<=  38 ?  40
	: ls>=  43 && ls<=  48 ?  50
	: ls>=  50 && ls<=  57 ?  60
	: ls>=  60 && ls<=  65 ?  70
	: ls>=  68 && ls<=  74 ?  80
	: ls>=  76 && ls<=  81 ?  90
	: ls>=  85 && ls<=  90 ? 100
	: ls>=  94 && ls<= 100 ? 125
	: ls>= 103 && ls<= 109 ? 150
	: ls>= 210 && ls<= 215 ? 200
	: NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_l2
  
  // Define Layer 3 Scans below
  int hv_l3(int run, int ls, int orbit) {
    switch (run) {
      // hv scan 2010 April 05 - L3,FPix modules
    case 132599:
      return 
        ls  < 75 ? 150
        : ls<126 ? 140
        : ls<178 ? 130
        : ls<233 ? 120
        : ls<283 ? 110
        : ls<332 ? 100
        : ls<385 ?  90
        : 80;
    case 132601:
      return
        ls  < 50 ? 70
        : ls<105 ? 60
        : ls<155 ? 50
        : ls<207 ? 40
        : ls<258 ? 30 
        : 150;
      // hv scan 2010 Oct 28 - L1,L3,FPix modules
    case 149182:
      return hv_l1(run, ls, orbit);
      // hv scan 2011 March 14,16,18 - L1,L3,FPix modules
    case 160431:
      return hv_l1(run, ls, orbit);
    case 160578:
      return hv_l1(run, ls, orbit);
    case 160579:
      return hv_l1(run, ls, orbit);
    case 160819:
      return hv_l1(run, ls, orbit);
    case 160827:
      return hv_l1(run, ls, orbit);
    case 160835:
      return hv_l1(run, ls, orbit);
    // voltage scan 2011 July 28 - L3
    case 171897:
      return
        orbit  < 6600000 ?  NOVAL_I
        : orbit<13600000 ?  70
        : orbit<20400000 ?  60
        : orbit<27200000 ?  50
        : orbit<33900000 ?  40
        : orbit<40800000 ?  30
        : orbit<47500000 ?  20
        : orbit<54100000 ?  80
        : 150;
      // voltage scan 2012 Apr 06 - L1, L2, L3, D1, D2
    case 190539:
      return
        ls<263 ? 150
        : ls<280 ?   0 // L3
        : ls<295 ?   5
        : ls<315 ?  10
        : 15;
    case 190591:
      return
        ls  < 87 ?  15
        : ls<104 ?  20
        : ls<118 ?  30
        : ls<134 ?  40
        : ls<150 ?  50
        : ls<163 ?  70
        : ls<178 ? 100
        : 150;
      // voltage scan 2012 Jul 02 - L1, L2, L3, D1, D2
    case 198044:
      return
        orbit<14800000 ? 150 // L3
        : 100;
    case 198045:
      return
        orbit  < 1200000 ? 100
        : orbit< 3200000 ?  80
        : orbit< 5800000 ?  70
        : orbit< 7900000 ?  60
        : orbit<10600000 ?  50
        : orbit<12600000 ?  40
        : orbit<14600000 ?  30
        : orbit<16700000 ?  20
        : orbit<18661675 ?  10
        : orbit<20700000 ?   5
        : 150;
      // voltage scan 2012 Dec 02 - Full Layer 1-3, Disk 1-2
    case 208392:
      return
        orbit  < 5600000 ? 300
        : orbit< 7500000 ? 150
        : orbit<10300000 ? 100
        : 80;
    case 208393:
      return
        orbit  <50600000 ? 150
        : orbit<55200000 ? 300
        : 100;
    case 208394:
      return orbit< 2200000 ? 100 : 80;
    case 208395:
      return
        orbit  < 2100000 ?  80
        : orbit< 4700000 ?  70
        : orbit< 7000000 ?  60
        : orbit< 9400000 ?  50
        : orbit<11500000 ?  40
        : orbit<13700000 ?  30
        : orbit<15500000 ?  20
        : orbit<18100000 ?  10
        : orbit<19900000 ?   5
        : 150 ;
      // voltage scan 2013 Jan 21 - Layer 1-3, Disk 1 (1 HV Group)
    case 210534:
      return hv_l1(run, ls, orbit);
      // 2015 Jun 08 - L1-3, D1-2 (Full)
    case 247398:
      return
        orbit<  23800000 ? 200
        : orbit<28800000 ?  10
        : orbit<31300000 ?  20
        : orbit<35000000 ?  30
        : orbit<39500000 ?  40
        : orbit<43000000 ?  50
        : orbit<46300000 ?  60
        : orbit<50300000 ?  70
        : orbit<54200000 ?  80
        : orbit<57700000 ?  90
        : orbit<61300000 ? 100
        : orbit<64800000 ? 125
	: 150;
    case 272012:
      return 
	ls  >=  84 && ls<= 113 ? 200 
	: NOVAL_I;
    case 272014:
      return
      	ls  >=  32 && ls<=  40 ?  10
	: ls>=  42 && ls<=  48 ?  20
	: ls>=  50 && ls<=  57 ?  30
	: ls>=  59 && ls<=  65 ?  40
	: ls>=  67 && ls<=  73 ?  50
	: ls>=  76 && ls<=  82 ?  60
	: ls>=  85 && ls<=  91 ?  70
	: ls>=  94 && ls<= 100 ?  80
	: ls>= 102 && ls<= 109 ?  90
	: NOVAL_I;
    case 272016:
      return
      	ls  >=   1 && ls<=  11 ? 100
	: ls>=  12 && ls<=  20 ? 125
	: ls>=  21 && ls<=  28 ? 150
	: ls>=  29 && ls<=  37 ? 250
	: ls>=  40 ? 200
	: NOVAL_I;
      // 2016 Jun 13 - L1-3, D1 (1 hv group)
    case 274998:
      return
	ls  >=   1 && ls<= 739 ? 200
	: NOVAL_I;
    case 274999:
      return
	ls  >= 146 && ls<= 156 ?  10
	: ls>= 161 && ls<= 172 ?  20
	: ls>= 177 && ls<= 187 ?  30
	: ls>= 191 && ls<= 201 ?  40
	: ls>= 206 && ls<= 215 ?  50
	: ls>= 220 && ls<= 230 ?  60
	: ls>= 235 && ls<= 246 ?  70
	: ls>= 250 && ls<= 261 ?  80
	: ls>= 266 && ls<= 277 ?  90
	: ls>= 284 && ls<= 296 ? 100
	: NOVAL_I;
      // 2016 Jul 04 - L1-3, D1 (1 hv group)
    case 276315:
      return
	ls  >=   1 && ls<= 149 ? 200
	: NOVAL_I;
    case 276317:
      return
	ls  >= 107 && ls<= 118 ?  10
	: ls>= 122 && ls<= 133 ?  20
	: NOVAL_I;
    case 276318:
      return
	ls  >=   9 && ls<=  20 ?  30
	: ls>=  24 && ls<=  34 ?  40
	: ls>=  39 && ls<=  50 ?  50
	: ls>=  55 && ls<=  65 ?  60
	: ls>=  71 && ls<=  81 ?  70
	: ls>=  85 && ls<=  96 ?  80
	: ls>= 101 && ls<= 111 ?  90
	: ls>= 116 && ls<= 126 ? 100
	: NOVAL_I;
      // 2016 Oct 20 - L1-3, D1-2 (Full)
    case 283553:
      return
      	ls  >= 220 && ls<= 226 ?  10
	: ls>= 230 && ls<= 235 ?  20
	: ls>= 238 && ls<= 243 ?  30
	: ls>= 247 && ls<= 252 ?  40
	: ls>= 255 && ls<= 260 ?  50
	: ls>= 262 && ls<= 270 ?  60
	: ls>= 272 && ls<= 278 ?  70
	: ls>= 281 && ls<= 287 ?  80
	: ls>= 290 && ls<= 296 ?  90
	: ls>= 299 && ls<= 306 ? 100
	: ls>= 310 && ls<= 315 ? 125
	: ls>= 319 && ls<= 326 ? 150
	: ls>= 208 && ls<= 215 ? 200
	: NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_l3
  
  
  // Define Disk 1 Scans below
  int hv_d1(int run, int ls, int orbit) {
    switch (run) {
      // hv scan 2010 April 05 - L3,FPix modules
    case 132599:
      return 
        ls  < 75 ? 300
        : ls<126 ? 250
        : ls<178 ? 200
        : ls<233 ? 150
        : ls<283 ? 110
        : ls<332 ? 100
        : ls<385 ?  90
        : 80;
    case 132601:
      return
        ls  < 50 ? 70
        : ls<105 ? 60
        : ls<155 ? 50
        : ls<207 ? 40
        : ls<258 ? 30
        : 300;
      // hv scan 2010 Oct 28 - L1,L2,FPix modules
    case 149182:
      return
        ls  < 16 ? 200
        : ls< 30 ? 130
        : ls< 47 ? 100
        : ls< 64 ?  90
        : ls< 81 ?  80
        : ls< 98 ?  70
        : ls<115 ?  60
        : ls<134 ?  50
        : ls<150 ?  40
        : ls<169 ?  30
        : 300;
      // hv scan 2011 March 14,16,18 - L1,L2,FPix modules
    case 160431:
      return 150;
    case 160578:
      return orbit<108617422 ? NOVAL_I : 20; // Exclude Delay scan
    case 160579:
      return
        orbit  < 10060929 ? 30
        : orbit< 20603100 ? 35
        : orbit< 30368455 ? 40
        : orbit< 36726096 ? 50
        : orbit< 41127055 ? 60
        : 70;
    case 160819:
      return
        orbit  <  4945473 ? 300
        : orbit<  9184218 ?  50
        : orbit< 13531251 ?  60
        : orbit< 21375662 ?  70
        : orbit< 27850887 ?  80
        : NOVAL_I;
    case 160827:
      return 120;
    case 160835:
      return orbit< 22377196 ? 120 : 300;
      // voltage scan 2011 Sep 07 - L1, FPix module
    case 175834:
      return
        // FPix scan
        orbit  < 70200000 ? 300
        : orbit< 75800000 ? 150
        : orbit< 79200000 ?  80
        : orbit< 82500000 ?  70
        : orbit< 86000000 ?  60
        : orbit< 89300000 ?  50
        : orbit< 92500000 ?  40
        : orbit< 98500000 ?  30
        : orbit<101900000 ?  20
        : orbit<105300000 ?  10
        : orbit<108800000 ?   0
        : NOVAL_I;
    // voltage scan 2011 Oct 3 - FPix module
    case 180241:
      return
        orbit  < 99822153 ? 300
        : orbit<103299446 ?  15
        : orbit<106987682 ?  10
        : 70;
    case 180250:
      return
        orbit  <15726839 ? NOVAL_I
        : orbit<19447884 ?  70
        : orbit<23554126 ?  50
        : orbit<27501036 ?  40
        : orbit<31867338 ?  30
        : orbit<34939336 ?  20
        : orbit<38504259 ?  15
        : orbit<42213474 ?  10
        : orbit<45793856 ?   5
        : orbit<51126926 ?   0
        : 150;
      // voltage scan 2012 Apr 06 - L1, L2, L3, D1, D2
    case 190591:
      return
        ls  <191 ? 300
        : ls<203 ?   0 // D1
        : 5;
    case 190592:
      return
        ls  < 14 ?  10
        : ls< 29 ?  15
        : 20;
    case 190593:
      return 20;
    case 190595:
      return
        ls  < 16 ?  20
        : ls< 30 ?  30
        : ls< 43 ?  40
        : ls< 56 ?  50
        : ls< 69 ?  70
        : ls< 82 ? 100
        : ls< 95 ? 150
        : 300;
      // voltage scan 2012 Jul 02 - L1, L2, L3, D1, D2
    case 198045:
      // D1
      return
        orbit  <20700000 ? 300
        : orbit<23200000 ? 150
        : orbit<25200000 ? 100
        : orbit<27200000 ?  80
        : orbit<29281687 ?  70
        : orbit<31300000 ?  60
        : orbit<33261006 ?  50
        : orbit<35400000 ?  40
        : orbit<37338482 ?  30
        : orbit<39418496 ?  20
        : orbit<41343074 ?  10
        : orbit<43500000 ?   5
        : 300;
      // voltage scan 2012 Dec 02 - Full Layer 1-3, Disk 1-2
    case 208397:
      return
        orbit  < 1400000 ? NOVAL_I
        : orbit< 4400000 ? 150
        : orbit< 6200000 ? 100
        : orbit< 8400000 ?  80
        : orbit<10200000 ?  70
        : orbit<12300000 ?  60
        : orbit<14500000 ?  50
        : orbit<16500000 ?  40
        : orbit<18600000 ?  30
        : orbit<20950000 ?  20
        : orbit<23300000 ?  10
        : orbit<25950000 ?   5
        : 300;
      // voltage scan 2013 Jan 21 - Layer 1-3, Disk 1 (1 HV Group)
    case 210534:
      return
        orbit  <15500000 ? 300
        : orbit<19150000 ? 100
        : orbit<23150000 ?  90
        : orbit<26650000 ?  80
        : orbit<30600000 ?  70
        : orbit<34550000 ?  60
        : orbit<37850000 ?  50
        : orbit<41700000 ?  40
        : orbit<45900000 ?  30
        : orbit<49400000 ?  20
        : orbit<53450000 ?  10
        : 300;
      // 2015 Jun 08 - L1-3, D1-2 (Full)
    case 247073:
      return
        orbit<  41800000 ? 300
        : orbit<42700000 ? NOVAL_I
        : orbit<46600000 ?  10
        : orbit<51000000 ?  20
        : orbit<54800000 ?  30
        : orbit<58500000 ?  40
        : orbit<63300000 ?  50
        : orbit<66800000 ?  60
        : orbit<70700000 ?  70
        : orbit<74200000 ?  80
        : orbit<78000000 ?  90
	: 100;
    case 247078:
      return
        orbit<   1900000 ? NOVAL_I
        : orbit< 5700000 ? 125
	: 150;
    case 272008:
      return
      	ls  >=  10 && ls<=  17 ?  10
	: ls>=  19 && ls<=  25 ?  20
	: ls>=  26 && ls<=  34 ?  30
	: NOVAL_I;
    case 272010:
      return
      	ls  >=   4 && ls<=  13 ?  40
	: ls>=  14 && ls<=  24 ?  50
	: NOVAL_I;
    case 272011:
      return
      	ls  >=   2 && ls<=   9 ?  70
	: ls>=  12 && ls<=  18 ?  90
	: ls>=  21 && ls<=  30 ? 125
	: ls>=  31 && ls<=  38 ? 250
	: NOVAL_I;
    case 272012:
      return 
	ls  >=  84 && ls<= 113 ? 300
	: NOVAL_I;
      // 2016 Jun 13 - L1-3, D1 (1 hv group)
    case 274998:
      return
	ls  >=   1 && ls<= 739 ? 200
	: NOVAL_I;
    case 274999:
      return
	ls  >= 485 && ls<= 496 ?  10
	: ls>= 500 && ls<= 512 ?  20
	: ls>= 517 && ls<= 527 ?  30
	: ls>= 534 && ls<= 543 ?  40
	: ls>= 548 && ls<= 558 ?  50
	: ls>= 563 && ls<= 580 ?  60
	: ls>= 584 && ls<= 594 ?  70
	: ls>= 598 && ls<= 609 ?  80
	: ls>= 613 && ls<= 623 ?  90
	: ls>= 628 && ls<= 638 ? 100
	: NOVAL_I;
      // 2016 Jul 04 - L1-3, D1 (1 hv group)
    case 276315:
      return
	ls  >=   1 && ls<= 149 ? 200
	: NOVAL_I;
    case 276318:
      return
	ls  >= 413 && ls<= 423 ?  10
	: ls>= 428 && ls<= 438 ?  20
	: ls>= 442 && ls<= 452 ?  30
	: ls>= 457 && ls<= 467 ?  40
	: ls>= 472 && ls<= 482 ?  50
	: ls>= 487 && ls<= 497 ?  60
	: ls>= 502 && ls<= 512 ?  70
	: ls>= 516 && ls<= 527 ?  80
	: ls>= 531 && ls<= 541 ?  90
	: ls>= 545 && ls<= 556 ? 100
	: NOVAL_I;
      // 2016 Oct 20 - L1-3, D1-2 (Full)
    case 283553:
      return
      	ls  >= 332 && ls<= 337 ?  10
	: ls>= 339 && ls<= 343 ?  20
	: ls>= 345 && ls<= 349 ?  30
	: ls>= 351 && ls<= 355 ?  40
	: ls>= 357 && ls<= 360 ?  50
	: ls>= 362 && ls<= 366 ?  60
	: ls>= 369 && ls<= 374 ?  70
	: ls>= 376 && ls<= 381 ?  80
	: ls>= 319 && ls<= 326 ? 200
	: NOVAL_I;
    case 283560:
      return
      	ls  >=   3 && ls<=   7 ?  90
	: ls>=  10 && ls<=  14 ? 100
	: ls>=  16 && ls<=  20 ? 125
	: ls>=  23 && ls<=  27 ? 150
	: NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_d1
  
  
  // Define Disk 2 Scans below
  int hv_d2(int run, int ls, int orbit) {
    switch (run) {
      // voltage scan 2012 Apr 06 - L1, L2, L3, D1, D2
    case 190595:
      return
        ls  <107 ? 300
        : ls<119 ?   0 // D2
        : ls<132 ?   5
        : ls<147 ?  10
        : ls<161 ?  15
        : ls<175 ?  20
        : ls<187 ?  30
        : ls<199 ?  40
        : ls<210 ?  50
        : ls<223 ?  70
        : ls<237 ? 100
        : ls<250 ? 150
        : 300;
      // voltage scan 2012 Jul 02 - L1, L2, L3, D1, D2
    case 198045:
      // D2
      return
        orbit<43500000 ? 300
        : orbit<45500000 ? 150
        : orbit<47600000 ? 100
        : orbit<49650000 ?  80
        : orbit<51450000 ?  70
        : orbit<53550000 ?  60
        : orbit<55400000 ?  50
        : orbit<57450000 ?  40
        : orbit<59450000 ?  30
        : orbit<61500000 ?  20
        : orbit<63500000 ?  10
        : orbit<65600000 ?   5
        : NOVAL_I;
      // voltage scan 2012 Dec 02 - Full Layer 1-3, Disk 1-2
    case 208397:
      return
        orbit<25950000 ? 300
        : orbit<29750000 ? 150
        : orbit<32000000 ? 100
        : orbit<34500000 ?  80
        : orbit<36800000 ?  70
        : orbit<38600000 ?  60
        : orbit<41000000 ?  50
        : orbit<42700000 ?  40
        : orbit<44700000 ?  30
        : orbit<46700000 ?  20
        : orbit<49500000 ?  10
        : orbit<52650000 ?   5
        : 300;
      // 2015 Jun 08 - L1-3, D1-2 (Full)
    case 247078:
      return
        orbit<  10100000 ? 300
        : orbit<13500000 ?  10
        : orbit<17300000 ?  20
        : orbit<20900000 ?  30
        : orbit<24600000 ?  40
        : orbit<28200000 ?  50
        : orbit<31500000 ?  60
        : orbit<34900000 ?  70
        : orbit<38500000 ?  80
        : orbit<42200000 ?  90
        : orbit<45400000 ? 100
        : orbit<49400000 ? 125
	: 150;
    case 272011:
      return
      	ls  >=  42 && ls<=  49 ?  10
	: ls>=  51 && ls<=  57 ?  20
	: ls>=  59 && ls<=  65 ?  30
	: ls>=  67 && ls<=  73 ?  40
	: ls>=  75 && ls<=  81 ?  50
	: ls>=  83 && ls<=  90 ?  70
	: ls>=  93 && ls<=  98 ?  90
	: ls>= 101 && ls<= 107 ? 125
	: ls>= 110 && ls<= 116 ? 250
	: NOVAL_I;
    case 272012:
      return 
	ls  >=  84 && ls<= 113 ? 300
	: NOVAL_I;
    case 283560:
      return
      	ls  >=  31 && ls<=  35 ?  10
	: ls>=  37 && ls<=  41 ?  20
	: ls>=  43 && ls<=  46 ?  30
	: ls>=  49 && ls<=  53 ?  40
	: ls>=  55 && ls<=  58 ?  50
	: ls>=  61 && ls<=  65 ?  60
	: ls>=  67 && ls<=  70 ?  70
	: ls>=  71 && ls<=  76 ?  80
	: ls>=  78 && ls<=  82 ?  90
	: ls>=  84 && ls<=  88 ? 100
	: ls>=  91 && ls<=  94 ? 125
	: ls>=  97 && ls<= 104 ? 150
	: ls>= 106 && ls<= 115 ? 200
	: NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_d2
  
  
  int bias_voltage(int hv_scan_no, int run, int ls, int orbit, int det, int lay, int disk) {
    if (hv_scan_no==-1) return det ? 300 : (run<238474 ? 150 : 200);
    return (det==1) ? ((disk==1) ? hv_d1(run, ls, orbit) : (disk==2) ? hv_d2(run, ls, orbit) : NOVAL_I) :
      ((lay==1) ? hv_l1(run, ls, orbit) : (lay==2) ? hv_l2(run, ls, orbit) : (lay==3) ? hv_l3(run, ls, orbit) : NOVAL_I);
  }
  
  bool is_full_hv_scan(int n) {
    return n==4||n==5||n==6||n==11||n==12||n==13||n==14||n==15||(n>=17&&n<=19)||n==22;
  }
  
  bool is_one_hv_group_scan(int hv_scan_no, int hv, bool det, int layer, int ladder, int module, int disk, int blade, int panel) {
    if (hv_scan_no==-1) return 0;
    if (hv==NOVAL_I) return 0;
    if (det) {
      // FPix_BmI_D1_ROG1_HV1
      if (disk==-1) return blade>0 && blade<4 && (panel+module)<4;
      else return 0;
    } else {
      //BPIX_BmO_SEC2/6_LYR1-2_HV1
      if (layer==1) return module<0  && ((hv_scan_no==1 && ladder==-3)||(hv_scan_no!=1 &&ladder==-7));
      //BPix_BpI_SEC7_LYR1-2_HV2 
      else if (layer==2) return module>0 && (ladder==13||ladder==14);
      //BPix_BpO_SEC2_LYR3_HV1
      else if (layer==3) return module>0 && (ladder==-4||ladder==-5||ladder==-6);
      else return 0;
    }
  }
  
}// namespace scans
