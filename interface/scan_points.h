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
    case 359577: return 46;
    case 359578: return 46;
    case 359579: return 46;
    case 359580: return 46;
    case 359581: return 46;
    case 359582: return 46;
    case 359584: return 46;

      // 2023
      // Scan 1 - Apr 2023 mini scan
      // http://cmsonline.cern.ch/cms-elog/1177502
    case 365835: return 47;
    case 365836: return 47;
    case 365837: return 47;
    case 365838: return 47;
    case 365839: return 47;
    case 365840: return 47;
    case 365841: return 47;
    case 365842: return 47;

      // 2023
      // Scan 2 - Apr 2023 full scan
      // hhttp://cmsonline.cern.ch/cms-elog/1179227
    case 366406: return 48;
    case 366409: return 48;
    case 366410: return 48;
    case 366413: return 48;
    case 366419: return 48;
    case 366422: return 48;
    case 366424: return 48;
    case 366426: return 48;
    case 366427: return 48;
    case 366429: return 48;
    case 366432: return 48;
    case 366436: return 48;
    case 366437: return 48;
    case 366438: return 48;
    case 366439: return 48;
    case 366440: return 48;
    case 366441: return 48;
    case 366442: return 48;


	  // Scan 3 - Apr 2024 full scan
      // https://cmsonline.cern.ch/webcenter/portal/cmsonline/Common/Elog?_piref683379043.strutsAction=%2FviewMessageDetails.do%3FmsgId%3D1208943
	case 378994: return 49;
	case 378995: return 49;
	case 378996: return 49;
	case 378997: return 49;
	case 378998: return 49;
	case 378999: return 49;
	case 379000: return 49;
	case 379001: return 49;
	case 379003: return 49;
	case 379004: return 49;
	case 379005: return 49;
	case 379006: return 49;
	case 379007: return 49;
	case 379008: return 49;
	case 379009: return 49;
	case 379010: return 49;
  
	  // Scan - May 2025
	  //http://cmsonline.cern.ch/cms-elog/1258657
	case 391674: return 50;
	case 391675: return 50;
	case 391676: return 50;
	case 391677: return 50;
	case 391678: return 50;
	case 391679: return 50;
	case 391683: return 50;
	case 391684: return 50;
	case 391685: return 50;
	case 391686: return 50;
	case 391687: return 50;

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
    case 359577: return 3.;
    case 359578: return 2.;
    case 359579: return 1.;
    case 359580: return -3.;
    case 359581: return -2.;
    case 359582: return -1.;
    case 359584: return 0.;

      // 2023
      // Scan 1 - Apr 2022 mini scan
      // http://cmsonline.cern.ch/cms-elog/1177502
    case 365835: return -3.;
    case 365836: return -2.;
    case 365837: return -1.;
    case 365838: return 1.;
    case 365839: return 2.;
    case 365840: return 3.;
    case 365841: return 5.;
    case 365842: return 0.;

      // 2023
      // Scan 2 - Apr 2023 full scan
      // http://cmsonline.cern.ch/cms-elog/1179227
    case 366406: return 1.;
    case 366409: return 2.;
    case 366410: return 3.;
    case 366413: return 4.;
    case 366419: return 5.;
    case 366422: return 6.;
    case 366424: return 7.;
    case 366426: return 9.;
    case 366427: return -1.;
    case 366429: return -2.;
    case 366432: return -3.;
    case 366436: return -5.;
    case 366437: return -7.;
    case 366438: return -9.;
    case 366439: return -11.;
    case 366440: return -13.;
    case 366441: return -15.;
    case 366442: return 0.;


	  // Scan 3 - Apr 2024 full scan
	  // https://cmsonline.cern.ch/webcenter/portal/cmsonline/Common/Elog?_piref683379043.strutsAction=%2FviewMessageDetails.do%3FmsgId%3D1208943
	case 378994: return -13.;
	case 378995: return -11.;
	case 378996: return -9.;
	case 378997: return -7.;
	case 378998: return -5.;
	case 378999: return -3.;
	case 379000: return -2.;
	case 379001: return -1.;
	case 379003: return 0.;
	case 379004: return 1.;
	case 379005: return 2.;
	case 379006: return 3.;
	case 379007: return 4.;
	case 379008: return 5.;
	case 379009: return 6.;
	case 379010: return 7.;
  
  	  // 2025
	  // Scan - May 2025 mini scan
	  // http://cmsonline.cern.ch/cms-elog/1258657
	case 391674: return   -9;
	case 391675: return   -7;
	case 391676: return   -5;
	case 391677: return   -3;
	case 391678: return   -2;
	case 391679: return   -1;
	case 391683: return   0;
	case 391684: return   1;
	case 391685: return   2;
	case 391686: return   3;
	case 391687: return   4;

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
    case 295127: return 23; // 2017 May24-25 - FPix Only http://cmsonline.cern.ch/cms-elog/985913
    case 295128: return 23;
    case 295130: return 23;
    case 295131: return 23;
    case 295132: return 23;
    case 301086: return 24; //2017 Aug 14 - BPix only http://cmsonline.cern.ch/cms-elog/1003856
    case 301665: return 24; //2017 Aug 23: http://cmsonline.cern.ch/cms-elog/1005678
    case 301912: return 24; //2017 Aug 26: http://cmsonline.cern.ch/cms-elog/1006265
    case 303795: return 25; //2017 Sep 23 - BPix + Disk 2 http://cmsonline.cern.ch/cms-elog/1011175 
    case 304366: return 26; //2017 Oct 04 - BPix Layer 1 http://cmsonline.cern.ch/cms-elog/1013433
    case 305757: return 27; //2017 Oct 27 - BPix Layer 1 http://cmsonline.cern.ch/cms-elog/1018019
    case 306458: return 28; //2017 Nov 09 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1020953
    case 314649: return 29; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 314650: return 29; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 314663: return 29; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 315764: return 30; //2018 May 05 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1040372
    case 316199: return 31; //2018 May 12 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1041847
    case 316876: return 32; //2018 May 25 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1044475
    case 317640: return 33; //2018 Jun 09 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1047188
    case 319503: return 34; //2018 Jul 11 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1052076
    case 320500: return 35; //2018 Jul 30-31 - BPix+D1+D2 http://cmsonline.cern.ch/cms-elog/1055335 http://cmsonline.cern.ch/cms-elog/1055391 http://cmsonline.cern.ch/cms-elog/1055560
    case 320570: return 35; //2018 Jul 30-31 - BPix+D1+D2 http://cmsonline.cern.ch/cms-elog/1055335 http://cmsonline.cern.ch/cms-elog/1055391 http://cmsonline.cern.ch/cms-elog/1055560
    case 321396: return 36; //2018 Aug 17 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1058599
    case 322022: return 37; //2018 Sep 01 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1061220
    case 322381: return 38; //2018 Sep 07 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1062364
    case 323524: return 39; //2018 Sep 26 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1065392
    case 324980: return 40; //2018 Oct 20 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1069539
    case 326483: return 41; //2018 test HI run
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////               RUN 3              //////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    case 352931: return 42; //2022 Jun 03 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1142167
    case 355135: return 43; //2022 Jul 06 - FullScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1145911
    case 357900: return 44; //2022 Aug 23 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1153528
    case 359343: return 45; //2022 Sep 26 - FullScan Layer 1 http://cmsonline.cern.ch/cms-elog/1157147
    case 359571: return 46; //2022 Sep 29 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1157552
    case 359575: return 46; //2022 Sep 29 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1157552
    case 359998: return 47; //2022 Oct 07 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1158888
    case 360295: return 48; //2022 Oct 13 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1159838
    case 360796: return 49; //2022 Oct 20 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1161388
    case 361223: return 50; //2022 Oct 27 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1163868
    case 361475: return 51; //2022 Nov 03 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1164925
    case 361890: return 52; //2022 Nov 10 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1165854
    case 362085: return 53; //2022 Nov 15 - FullScan Layer 1 http://cmsonline.cern.ch/cms-elog/1167096
    case 362087: return 53; //2022 Nov 15 - FullScan Layer 1 http://cmsonline.cern.ch/cms-elog/1167096
    case 362617: return 54; //2022 Nov 24 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1169428
    case 362696: return 55; //2022 Nov 26 - FullScan Layer 1 http://cmsonline.cern.ch/cms-elog/1169673
    case 365775: return 56; //2023 Apr 06 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1177336
    case 366450: return 57; //2023 Apr 22 - FullScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1179231
    case 366451: return 57; //2023 Apr 22 - FullScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1179231
    case 367262: return 58; //2023 May 09 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1181802
    case 367691: return 59; //2023 May 18 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1183189
    case 367693: return 59; //2023 May 18 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1183189
    case 367696: return 59; //2023 May 18 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1183189
    case 368318: return 60; //2023 Jun 01 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1185055
    case 368320: return 60; //2023 Jun 01 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1185055
    case 368636: return 61; //2023 Jun 09 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1186157
    case 370169: return 62; //2023 Jul 05 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1189385
    case 370772: return 63; //2023 Jul 16 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1191016
    case 372597: return 64; //2023 Sep 01 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1194078
    case 372598: return 64; //2023 Sep 01 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1194078
    case 372601: return 64; //2023 Sep 01 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1194078
    case 372602: return 64; //2023 Sep 01 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1194078
    case 375697: return 65; //2023 Oct 26 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1200756

    default: return -1;
    }
  }
  
  int hv_scan_badroc_runnumber(int run) {
    //Default badroc exclusion method is: use same run as scan but excluding scan data
    //With the following you can define a specific run for the badroc exclusion, this method was used in 2017-2018
    switch (run) {
    case 306458: return 306126; //2017 Nov 09 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1020953
    case 314649: return 314664; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 314650: return 314664; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 314663: return 314664; //2018 Apr 19 - BPix+FPix http://cmsonline.cern.ch/cms-elog/1037063
    case 316199: return 316201; //2018 May 12 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1041847
    case 316876: return 316877; //2018 May 25 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1044475
    case 317640: return 317641; //2018 Jun 09 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1047188
    case 319503: return 319486; //2018 Jul 11 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1052076
    case 320500: return 320571; //2018 Jul 30-31 - BPix+D1+D2 http://cmsonline.cern.ch/cms-elog/1055335 http://cmsonline.cern.ch/cms-elog/1055391 http://cmsonline.cern.ch/cms-elog/1055560
    case 320570: return 320571; //2018 Jul 30-31 - BPix+D1+D2 http://cmsonline.cern.ch/cms-elog/1055335 http://cmsonline.cern.ch/cms-elog/1055391 http://cmsonline.cern.ch/cms-elog/1055560
    case 321396: return 321393; //2018 Aug 17 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1058599
    case 322381: return 322381; 
    case 323524: return 323525; //2018 Sep 26 - MiniScan BPix+FPix http://cmsonline.cern.ch/cms-elog/1065392
    default: return -1;
    }
  }

  // Define Layer 1 Scans below
  int hv_l1(int run, int ls, int orbit, size_t new_module=0) {
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
      //2017 Aug 14- BPix only
    case 301086:
      return
      	ls  >= 44 && ls<= 72 ?  200
        : orbit>= 25893295 && orbit<= 27555262 ? 20
        : orbit>= 28330958 && orbit<= 30839245 ? 40
        : orbit>= 31086371 && orbit<= 33101923 ? 60
        : orbit>= 33306543 && orbit<= 35318926 ? 80
        : orbit>= 35540868 && orbit<= 37585784 ? 100
        : orbit>= 37852370 && orbit<= 39959311 ? 125
        : orbit>= 40202874 && orbit<= 42720431 ? 150
	  : NOVAL_I;
    case 301665:
      return
        orbit>= 77324157 && orbit<= 79419701 ? 250
        //: orbit>= 80455017 && orbit<= 82826044 ? 300
	  : NOVAL_I;
    case 301912:
      return
        orbit>= 13917167 && orbit<= 15973020 ? 300
        : orbit>= 16174936 && orbit<= 18219321 ? 350
        : orbit>= 18422306 && orbit<= 20510907 ? 400
	  : NOVAL_I;
    case 303795:
      return
        orbit>= 53187072 && orbit<= 54926159 ? 100
        : orbit>= 55109298 && orbit<= 56829492 ? 150
        : orbit>= 57013653 && orbit<= 58709677 ? 200
        : orbit>= 58946988 && orbit<= 60681763 ? 250
        : orbit>= 60815499 && orbit<= 62466968 ? 300
        : orbit>= 62654706 && orbit<= 64322635 ? 400
        : orbit>= 51050070 && orbit<= 52540652 ? 350
	  : NOVAL_I;
    case 304366:
      return
        orbit>= 361573631 && orbit<= 363516914 ? 350
        : orbit>= 364797641 && orbit<= 365891215 ? 400
        : orbit>= 366475549 && orbit<= 367517242 ? 300
        : orbit>= 367754247 && orbit<= 368789142 ? 250
        : orbit>= 369031937 && orbit<= 370069599 ? 200
        : orbit>= 370284665 && orbit<= 371345448 ? 150
        : orbit>= 371508198 && orbit<= 372549884 ? 100
	  : NOVAL_I;
    case 305757:
      return
        orbit>= 322449 && orbit<= 2318208 ? 350
        : orbit>= 2695515 && orbit<= 4688758 ? 200
        : orbit>= 4930843 && orbit<= 6965323 ? 300
        : orbit>= 7258275 && orbit<= 9263379 ? 400
        : orbit>= 9531219 && orbit<= 11597950 ? 450
        : orbit>= 11810975 && orbit<= 13835041 ? 500
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 350
        : orbit>= 33508938 && orbit<= 34863045 ? 200
        : orbit>= 35029055 && orbit<= 36385601 ? 250
        : orbit>= 36578714 && orbit<= 37900572 ? 300
        : orbit>= 38096453 && orbit<= 39448792 ? 400
        : orbit>= 39615128 && orbit<= 40968785 ? 450
        : orbit>= 41189573 && orbit<= 42519606 ? 500
        : orbit>= 65564341 && orbit<= 66916772 ? 550
        : orbit>= 67303535 && orbit<= 68633680 ? 350
	  : NOVAL_I;
	case 314650: if (!new_module) {
	  return
	    orbit>= 6420813 && orbit<= 8920028 ? 40
	    : orbit>= 9079479 && orbit<= 11564280 ? 80
	    : orbit>= 11697253 && orbit<= 14173543 ? 120
	    : orbit>= 14305228 && orbit<= 16805427 ? 160
	    : orbit>= 16938685 && orbit<= 19429425 ? 200
	    : orbit>= 19592404 && orbit<= 22037920 ? 240
	    : orbit>= 22230759 && orbit<= 24653670 ? 280
	    : orbit>= 24845652 && orbit<= 27291213 ? 320
	    : orbit>= 27425927 && orbit<= 29896275 ? 350
	    : orbit>= 30083588 && orbit<= 38039473 ? 400
	    : orbit>= 38093140 && orbit<= 40650759 ? 450
	    : orbit>= 40704334 && orbit<= 43263306 ? 500
	    : orbit>= 43317589 && orbit<= 45901087 ? 550
	    : orbit>= 45954366 && orbit<= 48526405 ? 600
	      : NOVAL_I;
		}
		else {
	return
	    orbit>= 6420813 && orbit<= 8920028 ? 40
	    : orbit>= 9079479 && orbit<= 11564280 ? 80
	    : orbit>= 11697253 && orbit<= 14173543 ? 120
	    : orbit>= 14305228 && orbit<= 16805427 ? 160
	    : orbit>= 16938685 && orbit<= 19429425 ? 200
	    : orbit>= 19592404 && orbit<= 22037920 ? 240
	    : orbit>= 22230759 && orbit<= 24653670 ? 280
	    : orbit>= 24845652 && orbit<= 27291213 ? 320
	    : orbit>= 27425927 && orbit<= 29896275 ? 350
	      : NOVAL_I;
		}
	case 314663: if (!new_module) {
	  return
	    orbit>= 911898 && orbit<= 3421960 ? 20
	    : orbit>= 3661667 && orbit<= 6308404 ? 60
	    : orbit>= 6498162 && orbit<= 8924156 ? 100
	    : orbit>= 9109692 && orbit<= 11550884 ? 140
	    : orbit>= 11738499 && orbit<= 14167802 ? 180
	    : orbit>= 52232541 && orbit<= 54814596 ? 220
	    : orbit>= 55027775 && orbit<= 57434463 ? 260
	    : orbit>= 57621826 && orbit<= 60041253 ? 300
	    : orbit>= 60282248 && orbit<= 62926161 ? 375
	    : orbit>= 62979440 && orbit<= 65587041 ? 425
	    : orbit>= 65614586 && orbit<= 68183155 ? 475
	    : orbit>= 68236952 && orbit<= 70799702 ? 525
	    : orbit>= 70853442 && orbit<= 73430481 ? 575
	      : NOVAL_I;
		}
		else {
	return
	    orbit>= 911898 && orbit<= 3421960 ? 20
	    : orbit>= 3661667 && orbit<= 6308404 ? 60
	    : orbit>= 6498162 && orbit<= 8924156 ? 100
	    : orbit>= 9109692 && orbit<= 11550884 ? 140
	    : orbit>= 11738499 && orbit<= 14167802 ? 180
	    : orbit>= 52232541 && orbit<= 54814596 ? 220
	    : orbit>= 55027775 && orbit<= 57434463 ? 260
	    : orbit>= 57621826 && orbit<= 60041253 ? 300
	      : NOVAL_I;
		}
  case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 20
	    : orbit>= 41825841 && orbit<= 44322177 ? 40
	    : orbit>= 44480767 && orbit<= 46948744 ? 60
	    : orbit>= 47135051 && orbit<= 49565502 ? 80
	    : orbit>= 49728746 && orbit<= 52187784 ? 100
	    : orbit>= 52322198 && orbit<= 54804994 ? 120
	    : orbit>= 54969957 && orbit<= 57440386 ? 140
	    : orbit>= 57553203 && orbit<= 60043347 ? 160
	    : orbit>= 60176652 && orbit<= 62671231 ? 180
	    : orbit>= 62830841 && orbit<= 65299490 ? 200
	    : orbit>= 65460761 && orbit<= 67931853 ? 240
	    : orbit>= 68119359 && orbit<= 70522726 ? 280
	    : orbit>= 70683404 && orbit<= 73153756 ? 320
	    : orbit>= 73311203 && orbit<= 75775055 ? 350
	    : orbit>= 75933126 && orbit<= 78397728 ? 400
	    : orbit>= 78988711 && orbit<= 81533957 ? 10
	      : NOVAL_I;
	case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 20
	    : orbit>= 27391881 && orbit<= 29910318 ? 40
	    : orbit>= 30048261 && orbit<= 32528621 ? 60
	    : orbit>= 32692410 && orbit<= 35184550 ? 80
	    : orbit>= 35347550 && orbit<= 37766749 ? 100
	    : orbit>= 37964504 && orbit<= 40393240 ? 120
	    : orbit>= 40564372 && orbit<= 43001725 ? 140
	    : orbit>= 43111459 && orbit<= 45637231 ? 160
	    : orbit>= 45800722 && orbit<= 48263040 ? 180
	    : orbit>= 48454863 && orbit<= 50886070 ? 200
	    : orbit>= 51052187 && orbit<= 53510050 ? 240
	    : orbit>= 53672834 && orbit<= 56130806 ? 280
	    : orbit>= 56294595 && orbit<= 58752882 ? 320
	    : orbit>= 58889269 && orbit<= 61372970 ? 350
	    : orbit>= 61571382 && orbit<= 63995005 ? 400
	    : orbit>= 64601416 && orbit<= 67138847 ? 10
	    : orbit>= 67357410 && orbit<= 70015053 ? 30
	    : orbit>= 70179388 && orbit<= 72631784 ? 50
	    : orbit>= 72823108 && orbit<= 75250636 ? 70
	    : orbit>= 75639209 && orbit<= 75775182 ? 400
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 20
	    : orbit>= 47613845 && orbit<= 50105260 ? 40
	    : orbit>= 50188211 && orbit<= 52709208 ? 60
	    : orbit>= 52895444 && orbit<= 55339608 ? 80
	    : orbit>= 55500867 && orbit<= 57952349 ? 100
	    : orbit>= 58141198 && orbit<= 60574900 ? 120
	    : orbit>= 60717816 && orbit<= 63221110 ? 140
	    : orbit>= 63329551 && orbit<= 65809487 ? 160
	    : orbit>= 65969746 && orbit<= 68435462 ? 180
	    : orbit>= 68575779 && orbit<= 71053332 ? 200
	    : orbit>= 71220080 && orbit<= 73688468 ? 240
	    : orbit>= 73877439 && orbit<= 76301206 ? 280
	    : orbit>= 76461185 && orbit<= 78925237 ? 320
	    : orbit>= 79058767 && orbit<= 81554007 ? 350
	    : orbit>= 81740951 && orbit<= 84170667 ? 400
	    : orbit>= 84770465 && orbit<= 87321138 ? 10
	    : orbit>= 87514391 && orbit<= 89930989 ? 30
	    : orbit>= 90122374 && orbit<= 92565760 ? 50
	    : orbit>= 92754465 && orbit<= 95185550 ? 70
	    : orbit>= 95563605 && orbit<= 95697795 ? 400
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 20
	    : orbit>= 47854891 && orbit<= 50359955 ? 40
	    : orbit>= 50522239 && orbit<= 52977308 ? 60
	    : orbit>= 53113522 && orbit<= 55616572 ? 80
	    : orbit>= 55755315 && orbit<= 58228213 ? 100
	    : orbit>= 58372274 && orbit<= 60827613 ? 120
	    : orbit>= 60995674 && orbit<= 63463695 ? 140
	    : orbit>= 63631902 && orbit<= 66076490 ? 160
	    : orbit>= 66213020 && orbit<= 68722423 ? 180
	    : orbit>= 68890165 && orbit<= 71333543 ? 200
	    : orbit>= 71498800 && orbit<= 73941265 ? 240
	    : orbit>= 74129851 && orbit<= 76570264 ? 280
	    : orbit>= 76734342 && orbit<= 79189022 ? 320
	    : orbit>= 79329459 && orbit<= 81814529 ? 350
	    : orbit>= 82013635 && orbit<= 84419465 ? 400
	    : orbit>= 85001650 && orbit<= 87569257 ? 10
	    : orbit>= 87759543 && orbit<= 90188057 ? 30
	    : orbit>= 90323314 && orbit<= 92815992 ? 50
	    : orbit>= 92953354 && orbit<= 95441167 ? 70
	    : orbit>= 95791830 && orbit<= 95961670 ? 400
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 20
	    : orbit>= 9566810 && orbit<= 12075322 ? 40
	    : orbit>= 12213121 && orbit<= 14717975 ? 60
	    : orbit>= 14853577 && orbit<= 17316216 ? 80
	    : orbit>= 17503961 && orbit<= 19935530 ? 100
	    : orbit>= 20071439 && orbit<= 22554342 ? 120
	    : orbit>= 22715316 && orbit<= 25193763 ? 140
	    : orbit>= 25355311 && orbit<= 27817230 ? 160
	    : orbit>= 27926532 && orbit<= 30416278 ? 180
	    : orbit>= 30527882 && orbit<= 33049984 ? 200
	    : orbit>= 33212050 && orbit<= 35664191 ? 240
	    : orbit>= 35826282 && orbit<= 38287417 ? 280
	    : orbit>= 38504148 && orbit<= 40914406 ? 320
	    : orbit>= 41077682 && orbit<= 43524088 ? 350
	    : orbit>= 43659205 && orbit<= 46161085 ? 400
	    : orbit>= 46728740 && orbit<= 49298332 ? 10
	    : orbit>= 49493037 && orbit<= 51915397 ? 30
	    : orbit>= 52049768 && orbit<= 54561617 ? 50
	    : orbit>= 54723510 && orbit<= 57164897 ? 70
	    : orbit>= 57487275 && orbit<= 57702598 ? 400
	      : NOVAL_I;
  case 320500:
	  return
	    orbit>= 38982534 && orbit<= 41435000 ? 80
	    : orbit>= 41649491 && orbit<= 44097390 ? 120
	    : orbit>= 44286534 && orbit<= 46932167 ? 160
	    : orbit>= 47145590 && orbit<= 49569757 ? 200
	    : orbit>= 49783965 && orbit<= 52205093 ? 240
	    : orbit>= 52338511 && orbit<= 54814731 ? 280
	    : orbit>= 55030138 && orbit<= 57699575 ? 320
	    : orbit>= 57887403 && orbit<= 60333176 ? 350
	    : orbit>= 60520568 && orbit<= 62945798 ? 400
	    : orbit>= 63240246 && orbit<= 65820242 ? 300
	    : orbit>= 66063657 && orbit<= 68711384 ? 260
	    : orbit>= 68955890 && orbit<= 71622151 ? 220
	    : orbit>= 71809121 && orbit<= 74494756 ? 180
	    : orbit>= 74684169 && orbit<= 77128923 ? 140
	    : orbit>= 77263372 && orbit<= 79715401 ? 100
	    : orbit>= 79984054 && orbit<= 82591209 ? 60
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 20
	    : orbit>= 4370646 && orbit<= 6835331 ? 40
	    : orbit>= 6998249 && orbit<= 9443899 ? 60
	    : orbit>= 9603408 && orbit<= 12088965 ? 80
	    : orbit>= 12249948 && orbit<= 14691253 ? 100
	    : orbit>= 14824908 && orbit<= 17317702 ? 120
	    : orbit>= 17479610 && orbit<= 19929276 ? 140
	    : orbit>= 20117009 && orbit<= 22560727 ? 160
	    : orbit>= 22748255 && orbit<= 25191626 ? 180
	    : orbit>= 25299297 && orbit<= 27799610 ? 200
	    : orbit>= 27936056 && orbit<= 30437130 ? 240
	    : orbit>= 30629196 && orbit<= 33078612 ? 280
	    : orbit>= 33186971 && orbit<= 35673738 ? 320
	    : orbit>= 35860673 && orbit<= 38283804 ? 350
	    : orbit>= 38417265 && orbit<= 40915199 ? 400
	    : orbit>= 41076211 && orbit<= 43523705 ? 450
	    : orbit>= 43709569 && orbit<= 46158773 ? 500
	    : orbit>= 46346107 && orbit<= 48766767 ? 550
	    : orbit>= 48954620 && orbit<= 51396578 ? 600
	    : orbit>= 51746675 && orbit<= 51933237 ? 400
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 20
	    : orbit>= 63075867 && orbit<= 65549032 ? 40
	    : orbit>= 65683169 && orbit<= 68178385 ? 60
	    : orbit>= 68339788 && orbit<= 70786533 ? 80
	    : orbit>= 70945624 && orbit<= 73405782 ? 100
	    : orbit>= 73539162 && orbit<= 76031847 ? 120
	    : orbit>= 76194593 && orbit<= 78661829 ? 140
	    : orbit>= 78793861 && orbit<= 81294346 ? 160
	    : orbit>= 81402558 && orbit<= 83913027 ? 180
	    : orbit>= 84019032 && orbit<= 86545026 ? 200
	    : orbit>= 86678270 && orbit<= 89173927 ? 240
	    : orbit>= 89360682 && orbit<= 91778781 ? 280
	    : orbit>= 91965880 && orbit<= 94679839 ? 320
	    : orbit>= 94865315 && orbit<= 97286456 ? 350
	    : orbit>= 97472797 && orbit<= 99884436 ? 400
	    : orbit>= 100098900 && orbit<= 102523723 ? 450
	    : orbit>= 102708961 && orbit<= 105133240 ? 500
	    : orbit>= 105290722 && orbit<= 107757020 ? 550
	    : orbit>= 107888477 && orbit<= 110382854 ? 600
	    : orbit>= 110727354 && orbit<= 110914389 ? 400
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 20
	    : orbit>= 58114200 && orbit<= 60588212 ? 40
	    : orbit>= 60724340 && orbit<= 63202264 ? 60
	    : orbit>= 63340322 && orbit<= 65817097 ? 80
	    : orbit>= 65979355 && orbit<= 68425849 ? 100
	    : orbit>= 68561709 && orbit<= 71071128 ? 120
	    : orbit>= 71233215 && orbit<= 73688647 ? 140
	    : orbit>= 73852199 && orbit<= 76310213 ? 160
	    : orbit>= 76473584 && orbit<= 78927087 ? 180
	    : orbit>= 79093199 && orbit<= 81541766 ? 200
	    : orbit>= 81704609 && orbit<= 84163799 ? 240
	    : orbit>= 84355052 && orbit<= 86800517 ? 280
	    : orbit>= 86965497 && orbit<= 89409147 ? 320
	    : orbit>= 89572559 && orbit<= 92042263 ? 350
	    : orbit>= 92204778 && orbit<= 94675917 ? 400
	    : orbit>= 94838548 && orbit<= 97280347 ? 450
	    : orbit>= 97470307 && orbit<= 99890291 ? 500
	    : orbit>= 100079665 && orbit<= 102522741 ? 550
	    : orbit>= 102712865 && orbit<= 105177376 ? 600
	    : orbit>= 105524648 && orbit<= 105659424 ? 400
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 20
	    : orbit>= 43422348 && orbit<= 45881929 ? 40
	    : orbit>= 46018056 && orbit<= 48516945 ? 60
	    : orbit>= 48678223 && orbit<= 51169750 ? 80
	    : orbit>= 51304556 && orbit<= 53771512 ? 100
	    : orbit>= 53932342 && orbit<= 56381384 ? 120
	    : orbit>= 56516448 && orbit<= 59011528 ? 140
	    : orbit>= 59200521 && orbit<= 61617940 ? 160
	    : orbit>= 61753974 && orbit<= 64253057 ? 180
	    : orbit>= 64390607 && orbit<= 66854828 ? 200
	    : orbit>= 67018750 && orbit<= 69485929 ? 240
	    : orbit>= 69648708 && orbit<= 72118854 ? 280
	    : orbit>= 72306340 && orbit<= 74742683 ? 320
	    : orbit>= 74932909 && orbit<= 77350840 ? 350
	    : orbit>= 77510220 && orbit<= 79977923 ? 400
	    : orbit>= 80140120 && orbit<= 82583218 ? 450
	    : orbit>= 82772153 && orbit<= 85219004 ? 500
	    : orbit>= 85380942 && orbit<= 87843975 ? 550
	    : orbit>= 88036981 && orbit<= 90452859 ? 600
	    : orbit>= 90754006 && orbit<= 90996042 ? 450
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 20
	    : orbit>= 52868613 && orbit<= 55321785 ? 40
	    : orbit>= 55462104 && orbit<= 57973413 ? 60
	    : orbit>= 58087326 && orbit<= 60562624 ? 80
	    : orbit>= 60709545 && orbit<= 63210483 ? 100
	    : orbit>= 63359047 && orbit<= 65804852 ? 120
	    : orbit>= 65946954 && orbit<= 68434710 ? 140
	    : orbit>= 68605001 && orbit<= 71096881 ? 160
	    : orbit>= 71238107 && orbit<= 73690920 ? 180
	    : orbit>= 73860855 && orbit<= 76295804 ? 200
	    : orbit>= 76465735 && orbit<= 78930971 ? 240
	    : orbit>= 79102261 && orbit<= 81539075 ? 280
	    : orbit>= 81714638 && orbit<= 84171548 ? 320
	    : orbit>= 84349817 && orbit<= 86788381 ? 350
	    : orbit>= 86964660 && orbit<= 89396615 ? 400
	    : orbit>= 89567078 && orbit<= 92044434 ? 450
	    : orbit>= 92212873 && orbit<= 94683362 ? 500
	    : orbit>= 94878471 && orbit<= 97549671 ? 550
	    : orbit>= 97720736 && orbit<= 100166254 ? 600
	    : orbit>= 100483993 && orbit<= 100681077 ? 450
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
	case 352931:
	  return
	    orbit>= 1968481 && orbit<= 4736017 ? 5
	    : orbit>= 4784461 && orbit<= 7610810 ? 10
	    : orbit>= 7660060 && orbit<= 10511621 ? 15
	    : orbit>= 10562037 && orbit<= 13380721 ? 20
	    : orbit>= 13429646 && orbit<= 16268114 ? 25
	    : orbit>= 16390112 && orbit<= 19147855 ? 30
	    : orbit>= 19272670 && orbit<= 22032839 ? 35
	    : orbit>= 22082824 && orbit<= 24921952 ? 40
	    : orbit>= 25044824 && orbit<= 27805658 ? 50
	    : orbit>= 27855378 && orbit<= 30684689 ? 60
	    : orbit>= 30808993 && orbit<= 33579280 ? 70
	    : orbit>= 33629193 && orbit<= 36467115 ? 80
	    : orbit>= 36613893 && orbit<= 39337659 ? 90
	    : orbit>= 39386937 && orbit<= 42233511 ? 100
	    : orbit>= 42380958 && orbit<= 45108131 ? 110
	    : orbit>= 45157840 && orbit<= 47985532 ? 120
	    : orbit>= 48105844 && orbit<= 50885738 ? 130
	    : orbit>= 50934591 && orbit<= 53747920 ? 140
	    : orbit>= 53917558 && orbit<= 56637545 ? 150
	    : orbit>= 56686674 && orbit<= 59525018 ? 160
	    : orbit>= 59574993 && orbit<= 59797815 ? 150
	      : NOVAL_I;
	case 355135:
	  return
	    orbit>= 161294539 && orbit<= 164114396 ? 5
	    : orbit>= 164193923 && orbit<= 167010579 ? 10
	    : orbit>= 176587318 && orbit<= 179316204 ? 15
	    : orbit>= 179394468 && orbit<= 182198295 ? 20
	    : orbit>= 182305356 && orbit<= 185104214 ? 25
	    : orbit>= 185184016 && orbit<= 187975178 ? 30
	    : orbit>= 188028281 && orbit<= 190857437 ? 35
	    : orbit>= 190988882 && orbit<= 193748657 ? 40
	    : orbit>= 193801869 && orbit<= 196627631 ? 50
	    : orbit>= 196680023 && orbit<= 199506953 ? 60
	    : orbit>= 199559749 && orbit<= 202382412 ? 70
	    : orbit>= 202515994 && orbit<= 205265340 ? 80
	    : orbit>= 205318374 && orbit<= 208164981 ? 100
	    : orbit>= 208218450 && orbit<= 211041795 ? 125
	    : orbit>= 211096589 && orbit<= 213917326 ? 150
	      : NOVAL_I;
	case 357900:
	  return
	    orbit>= 12664081 && orbit<= 15486907 ? 5
	    : orbit>= 15566369 && orbit<= 18368115 ? 10
	    : orbit>= 18420230 && orbit<= 21247176 ? 15
	    : orbit>= 21378632 && orbit<= 24147295 ? 20
	    : orbit>= 24199731 && orbit<= 27025711 ? 25
	    : orbit>= 27077499 && orbit<= 29909218 ? 30
	    : orbit>= 29960548 && orbit<= 32790919 ? 35
	    : orbit>= 32843486 && orbit<= 35673003 ? 40
	    : orbit>= 35778744 && orbit<= 38555720 ? 50
	    : orbit>= 38608540 && orbit<= 41438736 ? 60
	    : orbit>= 41570546 && orbit<= 44324553 ? 70
	    : orbit>= 44455195 && orbit<= 47211734 ? 80
	    : orbit>= 47342579 && orbit<= 50093965 ? 90
	    : orbit>= 50251205 && orbit<= 52977181 ? 100
	    : orbit>= 53030010 && orbit<= 55863627 ? 110
	    : orbit>= 55916697 && orbit<= 58740975 ? 120
	    : orbit>= 58793298 && orbit<= 61624510 ? 130
	    : orbit>= 61784559 && orbit<= 64513818 ? 140
	    : orbit>= 64698513 && orbit<= 67393943 ? 150
	    : orbit>= 67551617 && orbit<= 70262612 ? 160
	    : orbit>= 70315602 && orbit<= 73150278 ? 150
	      : NOVAL_I;
	case 359343:
	  return
	    orbit>= 3418159 && orbit<= 8933237 ? 5
	    : orbit>= 15591758 && orbit<= 20987875 ? 25
	    : orbit>= 22032623 && orbit<= 27548399 ? 50
	    : orbit>= 27653790 && orbit<= 33051729 ? 75
	    : orbit>= 33105487 && orbit<= 38554847 ? 100
	    : orbit>= 38634789 && orbit<= 44052675 ? 125
	    : orbit>= 44107717 && orbit<= 49551604 ? 150
	    : orbit>= 49604972 && orbit<= 55059848 ? 175
	    : orbit>= 55112700 && orbit<= 60563286 ? 200
	    : orbit>= 60645023 && orbit<= 66072166 ? 225
	    : orbit>= 66125454 && orbit<= 71587252 ? 250
	    : orbit>= 71642104 && orbit<= 77088674 ? 275
	    : orbit>= 77141746 && orbit<= 82602958 ? 325
	    : orbit>= 82658147 && orbit<= 88109979 ? 350
	    : orbit>= 88162788 && orbit<= 93600981 ? 300
	      : NOVAL_I;
	case 359571:
	  return
	    orbit>= 1598793 && orbit<= 4462108 ? 10
	    : orbit>= 4511395 && orbit<= 7350069 ? 20
	    : orbit>= 7399774 && orbit<= 10241564 ? 30
	    : orbit>= 10365345 && orbit<= 13132585 ? 40
	    : orbit>= 13255825 && orbit<= 15995781 ? 50
	    : orbit>= 16121215 && orbit<= 18899097 ? 60
	    : orbit>= 19022211 && orbit<= 21775984 ? 70
	    : orbit>= 21826416 && orbit<= 24672183 ? 80
	    : orbit>= 24722328 && orbit<= 27552047 ? 100
	    : orbit>= 27601834 && orbit<= 30433146 ? 120
	    : orbit>= 30557652 && orbit<= 33309141 ? 140
	    : orbit>= 33432366 && orbit<= 36193558 ? 160
	    : orbit>= 36243029 && orbit<= 39068178 ? 180
	    : orbit>= 39118463 && orbit<= 41969704 ? 200
	      : NOVAL_I;
	case 359575:
	  return
	    orbit>= 629737 && orbit<= 3422063 ? 220
	    : orbit>= 3548475 && orbit<= 6312050 ? 240
	    : orbit>= 6461056 && orbit<= 9196810 ? 260
	    : orbit>= 9348596 && orbit<= 12066809 ? 280
	    : orbit>= 12216331 && orbit<= 14954951 ? 325
	    : orbit>= 15107686 && orbit<= 17849142 ? 350
	    : orbit>= 18099677 && orbit<= 20986877 ? 300
	      : NOVAL_I;
	case 359998:
	  return
	    orbit>= 104875561 && orbit<= 107755135 ? 10
	    : orbit>= 107913968 && orbit<= 110630494 ? 20
	    : orbit>= 110788251 && orbit<= 113524201 ? 30
	    : orbit>= 113682052 && orbit<= 116420968 ? 40
	    : orbit>= 116550343 && orbit<= 119293351 ? 50
	    : orbit>= 119426118 && orbit<= 122178850 ? 60
	    : orbit>= 122336636 && orbit<= 125069620 ? 70
	    : orbit>= 125226412 && orbit<= 127952275 ? 80
	    : orbit>= 128057808 && orbit<= 130827303 ? 100
	    : orbit>= 130983638 && orbit<= 133718918 ? 120
	    : orbit>= 133823634 && orbit<= 136599596 ? 140
	    : orbit>= 136731343 && orbit<= 139480531 ? 160
	    : orbit>= 139610170 && orbit<= 142361614 ? 180
	    : orbit>= 142518456 && orbit<= 145248303 ? 200
	    : orbit>= 146982775 && orbit<= 149705976 ? 220
	    : orbit>= 149812001 && orbit<= 152574204 ? 240
	    : orbit>= 152707668 && orbit<= 155473411 ? 260
	    : orbit>= 155579472 && orbit<= 158344060 ? 280
	    : orbit>= 158503782 && orbit<= 161231425 ? 325
	    : orbit>= 161392164 && orbit<= 164109895 ? 350
	    : orbit>= 164399038 && orbit<= 167263402 ? 300
	      : NOVAL_I;
	case 360295:
	  return
	    orbit>= 250123817 && orbit<= 252997151 ? 10
	    : orbit>= 253130344 && orbit<= 255876427 ? 20
	    : orbit>= 256037677 && orbit<= 258760820 ? 30
	    : orbit>= 258895922 && orbit<= 261640771 ? 40
	    : orbit>= 261775735 && orbit<= 264513826 ? 50
	    : orbit>= 264621139 && orbit<= 267397855 ? 60
	    : orbit>= 267530956 && orbit<= 270282609 ? 70
	    : orbit>= 270417033 && orbit<= 273166939 ? 80
	    : orbit>= 273326940 && orbit<= 276051811 ? 100
	    : orbit>= 276185803 && orbit<= 278938988 ? 120
	    : orbit>= 279075317 && orbit<= 281832159 ? 140
	    : orbit>= 281965899 && orbit<= 284714222 ? 160
	    : orbit>= 284848582 && orbit<= 287602289 ? 180
	    : orbit>= 287735524 && orbit<= 290484727 ? 200
	    : orbit>= 290620075 && orbit<= 293353433 ? 220
	    : orbit>= 293460265 && orbit<= 296246415 ? 240
	    : orbit>= 296379312 && orbit<= 299138425 ? 260
	    : orbit>= 299301164 && orbit<= 302001233 ? 280
	    : orbit>= 302137056 && orbit<= 304881966 ? 325
	    : orbit>= 305042514 && orbit<= 307762219 ? 350
	    : orbit>= 308029792 && orbit<= 310911240 ? 300
	      : NOVAL_I;
	case 360796:
	  return
	    orbit>= 75646765 && orbit<= 78396600 ? 10
	    : orbit>= 78507985 && orbit<= 81277003 ? 20
	    : orbit>= 81385464 && orbit<= 84160318 ? 30
	    : orbit>= 84297227 && orbit<= 87050646 ? 40
	    : orbit>= 87186625 && orbit<= 89935156 ? 50
	    : orbit>= 90098419 && orbit<= 92830631 ? 60
	    : orbit>= 92967681 && orbit<= 95710970 ? 70
	    : orbit>= 95821281 && orbit<= 98586494 ? 80
	    : orbit>= 98719921 && orbit<= 101456347 ? 100
	    : orbit>= 101593245 && orbit<= 104351070 ? 120
	    : orbit>= 104512707 && orbit<= 107226276 ? 140
	    : orbit>= 107333521 && orbit<= 110118658 ? 160
	    : orbit>= 110228652 && orbit<= 112993580 ? 180
	    : orbit>= 113104333 && orbit<= 115892159 ? 200
	    : orbit>= 116055955 && orbit<= 118776123 ? 220
	    : orbit>= 118912464 && orbit<= 121643055 ? 240
	    : orbit>= 121808435 && orbit<= 124535570 ? 260
	    : orbit>= 124698262 && orbit<= 127419378 ? 280
	    : orbit>= 127525948 && orbit<= 130294767 ? 325
	    : orbit>= 130432704 && orbit<= 133198582 ? 350
	    : orbit>= 133472480 && orbit<= 136338129 ? 300
	      : NOVAL_I;
	case 361223:
	  return
	    orbit>= 38087387 && orbit<= 40918583 ? 10
	    : orbit>= 41051543 && orbit<= 43792557 ? 20
	    : orbit>= 43899276 && orbit<= 46692751 ? 30
	    : orbit>= 46801557 && orbit<= 49551982 ? 40
	    : orbit>= 49712638 && orbit<= 52437174 ? 60
	    : orbit>= 52517765 && orbit<= 55318121 ? 80
	    : orbit>= 55451536 && orbit<= 58222205 ? 100
	    : orbit>= 58329114 && orbit<= 61107309 ? 120
	    : orbit>= 61241257 && orbit<= 63972397 ? 140
	    : orbit>= 64107430 && orbit<= 66869015 ? 160
	    : orbit>= 67003578 && orbit<= 69740800 ? 180
	    : orbit>= 69877021 && orbit<= 72642959 ? 200
	    : orbit>= 72778246 && orbit<= 75522331 ? 220
	    : orbit>= 75658158 && orbit<= 78396727 ? 240
	    : orbit>= 78533017 && orbit<= 81279217 ? 260
	    : orbit>= 81441635 && orbit<= 84154693 ? 280
	    : orbit>= 84317433 && orbit<= 87037091 ? 300
	    : orbit>= 87173373 && orbit<= 89928279 ? 325
	    : orbit>= 90038254 && orbit<= 92820920 ? 350
	    : orbit>= 92984498 && orbit<= 95713653 ? 400
	    : orbit>= 95988057 && orbit<= 98845309 ? 300
	      : NOVAL_I;
	case 361475:
	  return
	    orbit>= 222110333 && orbit<= 224939149 ? 10
	    : orbit>= 225072545 && orbit<= 227809699 ? 20
	    : orbit>= 227970409 && orbit<= 230699599 ? 30
	    : orbit>= 230779861 && orbit<= 233595778 ? 40
	    : orbit>= 233703427 && orbit<= 236465704 ? 60
	    : orbit>= 236598359 && orbit<= 239360686 ? 80
	    : orbit>= 239493494 && orbit<= 242245761 ? 100
	    : orbit>= 242405079 && orbit<= 245128059 ? 120
	    : orbit>= 245285736 && orbit<= 248003579 ? 140
	    : orbit>= 248163112 && orbit<= 250881259 ? 160
	    : orbit>= 250985797 && orbit<= 253786244 ? 180
	    : orbit>= 253891737 && orbit<= 256655416 ? 200
	    : orbit>= 256787880 && orbit<= 259547532 ? 220
	    : orbit>= 259680999 && orbit<= 262420314 ? 240
	    : orbit>= 262551948 && orbit<= 265298416 ? 260
	    : orbit>= 265428875 && orbit<= 268195013 ? 280
	    : orbit>= 268380359 && orbit<= 271084430 ? 300
	    : orbit>= 271243461 && orbit<= 273967363 ? 325
	    : orbit>= 274125527 && orbit<= 276846908 ? 350
	    : orbit>= 277001884 && orbit<= 279718446 ? 400
	    : orbit>= 279980916 && orbit<= 282880383 ? 300
	      : NOVAL_I;
	case 361890:
	  return
	    orbit>= 3963493 && orbit<= 9459187 ? 10
	    : orbit>= 9564419 && orbit<= 14968438 ? 20
	    : orbit>= 15099769 && orbit<= 20474451 ? 30
	    : orbit>= 20579259 && orbit<= 25958161 ? 40
	    : orbit>= 26114369 && orbit<= 31484064 ? 60
	    : orbit>= 31641788 && orbit<= 36981269 ? 80
	    : orbit>= 37111781 && orbit<= 42498466 ? 100
	    : orbit>= 42630885 && orbit<= 47984783 ? 120
	    : orbit>= 48115296 && orbit<= 53504821 ? 140
	    : orbit>= 53660650 && orbit<= 59011469 ? 160
	    : orbit>= 59143042 && orbit<= 64514429 ? 180
	    : orbit>= 64673894 && orbit<= 70005563 ? 200
	    : orbit>= 70138844 && orbit<= 75510829 ? 220
	    : orbit>= 75642832 && orbit<= 81009063 ? 240
	    : orbit>= 81141608 && orbit<= 86536110 ? 260
	    : orbit>= 86643866 && orbit<= 92044401 ? 280
	    : orbit>= 92180485 && orbit<= 97528310 ? 300
	    : orbit>= 97636672 && orbit<= 103045464 ? 325
	    : orbit>= 103180825 && orbit<= 108550068 ? 350
	    : orbit>= 108712296 && orbit<= 114044835 ? 400
	    : orbit>= 114313672 && orbit<= 119810887 ? 350
	      : NOVAL_I;
	case 362085:
	  return
	    orbit>= 19375442 && orbit<= 20735654 ? 10
	    : orbit>= 20893184 && orbit<= 22313799 ? 20
	    : orbit>= 22445874 && orbit<= 23865319 ? 30
	    : orbit>= 23997741 && orbit<= 25445058 ? 40
	    : orbit>= 25624876 && orbit<= 27008906 ? 60
	    : orbit>= 27184480 && orbit<= 28584727 ? 80
	    : orbit>= 28741931 && orbit<= 30154500 ? 100
	    : orbit>= 30307920 && orbit<= 31735121 ? 120
	    : orbit>= 31915692 && orbit<= 33313251 ? 140
	    : orbit>= 33417927 && orbit<= 34892440 ? 160
	    : orbit>= 35080903 && orbit<= 36449116 ? 180
	    : orbit>= 36630495 && orbit<= 38029014 ? 200
	    : orbit>= 38212706 && orbit<= 39613234 ? 220
	    : orbit>= 39774363 && orbit<= 41178572 ? 240
	    : orbit>= 41362007 && orbit<= 42737938 ? 260
	    : orbit>= 42923358 && orbit<= 44333645 ? 280
	    : orbit>= 44540364 && orbit<= 45900335 ? 300
	    : orbit>= 46057731 && orbit<= 47475853 ? 325
	    : orbit>= 47631896 && orbit<= 49052237 ? 375
	      : NOVAL_I;
	case 362087:
	  return
	    orbit>= 1977545 && orbit<= 3419811 ? 400
	    : orbit>= 3605604 && orbit<= 4989551 ? 350
	      : NOVAL_I;
	case 362617:
	  return
	    orbit>= 1675207 && orbit<= 4482307 ? 10
	    : orbit>= 4589516 && orbit<= 7345565 ? 25
	    : orbit>= 7503560 && orbit<= 10251143 ? 50
	    : orbit>= 10383641 && orbit<= 13118256 ? 75
	    : orbit>= 13251150 && orbit<= 16012285 ? 100
	    : orbit>= 16092002 && orbit<= 18904691 ? 125
	    : orbit>= 19064644 && orbit<= 21780375 ? 150
	    : orbit>= 21915491 && orbit<= 24647683 ? 175
	    : orbit>= 24781469 && orbit<= 27544216 ? 200
	    : orbit>= 27701105 && orbit<= 30425847 ? 225
	    : orbit>= 30531014 && orbit<= 33309354 ? 250
	    : orbit>= 33440550 && orbit<= 36205433 ? 275
	    : orbit>= 36311560 && orbit<= 39080353 ? 300
	    : orbit>= 39211611 && orbit<= 41966680 ? 320
	    : orbit>= 42123525 && orbit<= 44832214 ? 340
	    : orbit>= 44963600 && orbit<= 47738950 ? 360
	    : orbit>= 47870274 && orbit<= 50611790 ? 380
	    : orbit>= 50717573 && orbit<= 53483918 ? 415
	    : orbit>= 53643704 && orbit<= 56368187 ? 430
	    : orbit>= 56499465 && orbit<= 59266913 ? 450
	    : orbit>= 59529205 && orbit<= 62409575 ? 400
	      : NOVAL_I;
	case 362696:
	  return
	    orbit>= 291701081 && orbit<= 292564209 ? 300
	    : orbit>= 292724907 && orbit<= 293616024 ? 325
	    : orbit>= 293800922 && orbit<= 294661837 ? 350
	    : orbit>= 294820474 && orbit<= 295707924 ? 375
	    : orbit>= 295892686 && orbit<= 296775695 ? 425
	    : orbit>= 296933125 && orbit<= 297820921 ? 450
	    : orbit>= 297929165 && orbit<= 298870255 ? 475
	    : orbit>= 299056498 && orbit<= 299918764 ? 500
	    : orbit>= 300076528 && orbit<= 300956056 ? 525
	    : orbit>= 301114630 && orbit<= 302000022 ? 550
	    : orbit>= 302320347 && orbit<= 303312565 ? 400
	      : NOVAL_I;
	case 365775:
	  return
	    orbit>= 11674141 && orbit<= 14429083 ? 225
	    : orbit>= 14589392 && orbit<= 17324633 ? 250
	    : orbit>= 17510902 && orbit<= 20196585 ? 275
	    : orbit>= 20383796 && orbit<= 23092362 ? 300
	    : orbit>= 23253989 && orbit<= 25982133 ? 325
	    : orbit>= 26197706 && orbit<= 29103790 ? 350
	    : orbit>= 29319343 && orbit<= 32255384 ? 375
	    : orbit>= 32444673 && orbit<= 35145650 ? 425
	    : orbit>= 35334294 && orbit<= 38017264 ? 450
	    : orbit>= 38180097 && orbit<= 40924604 ? 475
	    : orbit>= 41087244 && orbit<= 43808026 ? 500
	    : orbit>= 44514502 && orbit<= 47198988 ? 10
	    : orbit>= 47361806 && orbit<= 50091213 ? 25
	    : orbit>= 50255317 && orbit<= 52961410 ? 50
	    : orbit>= 53152818 && orbit<= 55865611 ? 75
	    : orbit>= 56057509 && orbit<= 59001403 ? 100
	    : orbit>= 59192755 && orbit<= 61877774 ? 125
	    : orbit>= 62043689 && orbit<= 64774124 ? 150
	    : orbit>= 64884831 && orbit<= 67653732 ? 175
	    : orbit>= 67791500 && orbit<= 70538399 ? 200
	    : orbit>= 70818655 && orbit<= 73668482 ? 400
	      : NOVAL_I;
	case 366450:
	  return
	    orbit>= 3249843 && orbit<= 6054733 ? 10
	    : orbit>= 6249344 && orbit<= 9188144 ? 60
	    : orbit>= 9411787 && orbit<= 12352195 ? 110
	    : orbit>= 12578698 && orbit<= 15475579 ? 160
	    : orbit>= 15699624 && orbit<= 18641555 ? 210
	    : orbit>= 18838421 && orbit<= 21766746 ? 250
	    : orbit>= 21991073 && orbit<= 24923285 ? 290
	    : orbit>= 25147852 && orbit<= 28080078 ? 320
	    : orbit>= 28275810 && orbit<= 31228110 ? 350
	    : orbit>= 31397341 && orbit<= 34102130 ? 375
	    : orbit>= 34300328 && orbit<= 37257188 ? 425
	    : orbit>= 37398520 && orbit<= 40133300 ? 450
	    : orbit>= 40358690 && orbit<= 43279480 ? 480
	    : orbit>= 43499524 && orbit<= 46431814 ? 510
	    : orbit>= 46737562 && orbit<= 49564805 ? 400
	      : NOVAL_I;
	case 367262:
	  return
	    orbit>= 7099870 && orbit<= 9973319 ? 10
	    : orbit>= 10169046 && orbit<= 12852101 ? 25
	    : orbit>= 13040868 && orbit<= 15739671 ? 50
	    : orbit>= 15959748 && orbit<= 18892548 ? 75
	    : orbit>= 19083998 && orbit<= 21766757 ? 100
	    : orbit>= 21931959 && orbit<= 24652329 ? 125
	    : orbit>= 24817938 && orbit<= 27542550 ? 150
	    : orbit>= 27734239 && orbit<= 30417342 ? 175
	    : orbit>= 30608624 && orbit<= 33313703 ? 200
	    : orbit>= 33505478 && orbit<= 36453885 ? 225
	    : orbit>= 36587559 && orbit<= 39346964 ? 250
	    : orbit>= 39511702 && orbit<= 42230281 ? 275
	    : orbit>= 42366690 && orbit<= 45102527 ? 300
	    : orbit>= 45240256 && orbit<= 47984863 ? 325
	    : orbit>= 48176143 && orbit<= 50887425 ? 350
	    : orbit>= 51050647 && orbit<= 53762229 ? 375
	    : orbit>= 53954281 && orbit<= 56911774 ? 425
	    : orbit>= 57075795 && orbit<= 59793547 ? 450
	    : orbit>= 59929631 && orbit<= 62659588 ? 475
	    : orbit>= 62878057 && orbit<= 65827762 ? 500
	    : orbit>= 66128316 && orbit<= 68970973 ? 400
	      : NOVAL_I;
	case 367691:
	  return
	    orbit>= 38093805 && orbit<= 40915552 ? 10
	    : orbit>= 41110913 && orbit<= 44047646 ? 25
	    : orbit>= 44186753 && orbit<= 46929565 ? 50
	    : orbit>= 47125589 && orbit<= 49838059 ? 75
	    : orbit>= 50003212 && orbit<= 52705357 ? 100
	    : orbit>= 52896569 && orbit<= 55580803 ? 125
	      : NOVAL_I;
	case 367693:
	  return
	    orbit>= 1098110 && orbit<= 3945219 ? 125
	    : orbit>= 4135366 && orbit<= 6829305 ? 150
	      : NOVAL_I;
	case 367696:
	  return
	    orbit>= 3506414 && orbit<= 6308118 ? 175
	    : orbit>= 6506342 && orbit<= 9468137 ? 200
	    : orbit>= 9637017 && orbit<= 12338491 ? 225
	    : orbit>= 12533908 && orbit<= 15483844 ? 250
	    : orbit>= 15653641 && orbit<= 18355679 ? 275
	    : orbit>= 18555832 && orbit<= 21245305 ? 300
	    : orbit>= 21385589 && orbit<= 24127787 ? 325
	    : orbit>= 24298863 && orbit<= 27024565 ? 350
	    : orbit>= 27136462 && orbit<= 29892124 ? 375
	    : orbit>= 30062691 && orbit<= 32789318 ? 425
	    : orbit>= 32929346 && orbit<= 35656656 ? 450
	    : orbit>= 35826537 && orbit<= 38555859 ? 475
	    : orbit>= 38755411 && orbit<= 41712687 ? 500
	    : orbit>= 42025627 && orbit<= 44837160 ? 400
	      : NOVAL_I;
	case 368318:
	  return
	    orbit>= 38680055 && orbit<= 41436877 ? 10
	    : orbit>= 41571843 && orbit<= 44311348 ? 25
	    : orbit>= 44502309 && orbit<= 47205698 ? 50
	    : orbit>= 47421959 && orbit<= 50347521 ? 75
	    : orbit>= 50508280 && orbit<= 53224276 ? 100
	    : orbit>= 53385408 && orbit<= 56124453 ? 125
	    : orbit>= 56286132 && orbit<= 58997544 ? 150
	    : orbit>= 59161176 && orbit<= 61882440 ? 175
	    : orbit>= 62071686 && orbit<= 64759415 ? 200
	    : orbit>= 64977629 && orbit<= 67907945 ? 225
	    : orbit>= 68097540 && orbit<= 70786060 ? 250
	    : orbit>= 70948149 && orbit<= 73673465 ? 275
	    : orbit>= 73863541 && orbit<= 76551518 ? 300
	    : orbit>= 76713898 && orbit<= 79436967 ? 325
	    : orbit>= 79601241 && orbit<= 82331790 ? 350
	      : NOVAL_I;
	case 368320:
	  return
	    orbit>= 7296034 && orbit<= 10245784 ? 375
	    : orbit>= 10436831 && orbit<= 13120570 ? 425
	    : orbit>= 13256620 && orbit<= 16014083 ? 450
	    : orbit>= 16205744 && orbit<= 19147750 ? 475
	    : orbit>= 19340819 && orbit<= 22029462 ? 500
	    : orbit>= 22359114 && orbit<= 25197863 ? 400
	      : NOVAL_I;
	case 368636:
	  return
	    orbit>= 33385564 && orbit<= 36207914 ? 10
	    : orbit>= 36371515 && orbit<= 39085596 ? 25
	    : orbit>= 39249532 && orbit<= 41952787 ? 50
	    : orbit>= 42143811 && orbit<= 44832462 ? 75
	    : orbit>= 44995928 && orbit<= 47737091 ? 100
	    : orbit>= 47899342 && orbit<= 50615477 ? 125
	    : orbit>= 50751769 && orbit<= 53490218 ? 150
	    : orbit>= 53653665 && orbit<= 56365742 ? 175
	    : orbit>= 56528473 && orbit<= 59270226 ? 200
	    : orbit>= 59461047 && orbit<= 62411805 ? 225
	    : orbit>= 62548295 && orbit<= 65290140 ? 250
	    : orbit>= 65425227 && orbit<= 68169459 ? 275
	    : orbit>= 68331785 && orbit<= 71070912 ? 300
	    : orbit>= 71234301 && orbit<= 73930658 ? 325
	    : orbit>= 74121783 && orbit<= 76837685 ? 350
	    : orbit>= 76973011 && orbit<= 79706299 ? 375
	    : orbit>= 79868802 && orbit<= 82607141 ? 425
	    : orbit>= 82768510 && orbit<= 85484677 ? 450
	    : orbit>= 85646605 && orbit<= 88362620 ? 475
	    : orbit>= 88525784 && orbit<= 91244037 ? 500
	    : orbit>= 91540489 && orbit<= 94394769 ? 400
	      : NOVAL_I;
	case 370169:
	  return
	    orbit>= 40342105 && orbit<= 43280163 ? 10
	    : orbit>= 43446024 && orbit<= 46163964 ? 25
	    : orbit>= 46360986 && orbit<= 49310460 ? 50
	    : orbit>= 49475797 && orbit<= 52185788 ? 75
	    : orbit>= 52352339 && orbit<= 55071756 ? 100
	    : orbit>= 55239247 && orbit<= 57948217 ? 125
	    : orbit>= 58115174 && orbit<= 60824770 ? 150
	    : orbit>= 60992420 && orbit<= 63706944 ? 175
	    : orbit>= 63845307 && orbit<= 66614001 ? 200
	    : orbit>= 66782084 && orbit<= 69473855 ? 225
	    : orbit>= 69641850 && orbit<= 72375108 ? 250
	    : orbit>= 72571092 && orbit<= 75528087 ? 275
	    : orbit>= 75722880 && orbit<= 78653907 ? 300
	    : orbit>= 78849747 && orbit<= 81532531 ? 325
	    : orbit>= 81672588 && orbit<= 84442221 ? 350
	    : orbit>= 84637613 && orbit<= 87569623 ? 375
	    : orbit>= 87737354 && orbit<= 90457916 ? 425
	    : orbit>= 90623611 && orbit<= 93355955 ? 450
	    : orbit>= 93522339 && orbit<= 96229970 ? 475
	    : orbit>= 96368015 && orbit<= 99098219 ? 500
	    : orbit>= 99434925 && orbit<= 102250856 ? 450
	      : NOVAL_I;
	case 370772:
	  return
	    orbit>= 52470445 && orbit<= 55333639 ? 10
	    : orbit>= 55472333 && orbit<= 58213155 ? 25
	    : orbit>= 58377241 && orbit<= 61089932 ? 50
	    : orbit>= 61256076 && orbit<= 63986325 ? 75
	    : orbit>= 64151875 && orbit<= 66856984 ? 100
	    : orbit>= 67024241 && orbit<= 69745556 ? 125
	    : orbit>= 69882848 && orbit<= 72642643 ? 150
	    : orbit>= 72780104 && orbit<= 75513072 ? 175
	    : orbit>= 75705636 && orbit<= 78389735 ? 200
	    : orbit>= 78527331 && orbit<= 81287919 ? 225
	    : orbit>= 81481429 && orbit<= 84417782 ? 250
	    : orbit>= 84582153 && orbit<= 87299914 ? 275
	    : orbit>= 87493915 && orbit<= 90188367 ? 300
	    : orbit>= 90382679 && orbit<= 93075344 ? 325
	    : orbit>= 93240739 && orbit<= 95958111 ? 350
	    : orbit>= 96127506 && orbit<= 98855902 ? 375
	    : orbit>= 98995097 && orbit<= 101722000 ? 400
	    : orbit>= 101919990 && orbit<= 104619178 ? 425
	    : orbit>= 104813521 && orbit<= 107747043 ? 475
	    : orbit>= 107916236 && orbit<= 110656907 ? 500
	    : orbit>= 110966804 && orbit<= 113797510 ? 450
	      : NOVAL_I;
	case 372597:
	  return
	    orbit>= 7903752 && orbit<= 13394769 ? 10
	    : orbit>= 13557899 && orbit<= 18905971 ? 25
	    : orbit>= 19067942 && orbit<= 24398996 ? 50
	    : orbit>= 24559026 && orbit<= 29910640 ? 75
	    : orbit>= 30098947 && orbit<= 35673648 ? 100
	    : orbit>= 35834767 && orbit<= 41184922 ? 125
	    : orbit>= 41347438 && orbit<= 46668343 ? 150
	    : orbit>= 46855827 && orbit<= 52173231 ? 175
	      : NOVAL_I;
	case 372598:
	  return
	    orbit>= 2746350 && orbit<= 8139349 ? 200
	    : orbit>= 8273753 && orbit<= 13650923 ? 225
	    : orbit>= 15111512 && orbit<= 20472285 ? 250
	      : NOVAL_I;
	case 372601:
	  return
	    orbit>= 490474 && orbit<= 6042138 ? 275
	    : orbit>= 6176244 && orbit<= 11549929 ? 300
	      : NOVAL_I;
	case 372602:
	  return
	    orbit>= 361535 && orbit<= 5785597 ? 325
	    : orbit>= 5948983 && orbit<= 11296711 ? 350
	    : orbit>= 11459733 && orbit<= 16786650 ? 375
	    : orbit>= 16923122 && orbit<= 22312993 ? 400
	    : orbit>= 22477745 && orbit<= 27808336 ? 425
	    : orbit>= 28000123 && orbit<= 33564939 ? 475
	    : orbit>= 33759233 && orbit<= 39083698 ? 500
	    : orbit>= 39385415 && orbit<= 44853027 ? 450
	      : NOVAL_I;
	case 375697:
	  return
	    orbit>= 14181054 && orbit<= 17056109 ? 10
	    : orbit>= 17275876 && orbit<= 20193293 ? 50
	    : orbit>= 20388031 && orbit<= 23095530 ? 100
	    : orbit>= 23289806 && orbit<= 26236248 ? 150
	    : orbit>= 26403276 && orbit<= 29104372 ? 200
	    : orbit>= 29271858 && orbit<= 32013840 ? 250
	    : orbit>= 32126302 && orbit<= 34880439 ? 275
	    : orbit>= 35047818 && orbit<= 37760914 ? 300
	    : orbit>= 37929290 && orbit<= 40658642 ? 325
	    : orbit>= 40852199 && orbit<= 43809979 ? 350
	    : orbit>= 43977324 && orbit<= 46666746 ? 375
	    : orbit>= 46832244 && orbit<= 49562209 ? 400
	    : orbit>= 49759108 && orbit<= 52723019 ? 425
	    : orbit>= 52860920 && orbit<= 55597269 ? 475
	    : orbit>= 55790859 && orbit<= 58751634 ? 500
	    : orbit>= 59029356 && orbit<= 61896178 ? 450
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
    case 301086:
      return
      	ls  >= 44 && ls<= 72 ?  250
        : orbit>= 44709363 && orbit<= 46827299 ? 20
        : orbit>= 47071394 && orbit<= 49087949 ? 40
        : orbit>= 49394950 && orbit<= 51390927 ? 60
        : orbit>= 51679134 && orbit<= 53696916 ? 80
        : orbit>= 53938797 && orbit<= 55956366 ? 100
        : orbit>= 56199888 && orbit<= 58205548 ? 125
        : orbit>= 58450947 && orbit<= 60484847 ? 150
        : orbit>= 60841624 && orbit<= 62847234 ? 200
	  : NOVAL_I;
    case 303795:
      return
        orbit>= 64754455 && orbit<= 66710200 ? 50
        : orbit>= 66873391 && orbit<= 68611595 ? 100
        : orbit>= 68805047 && orbit<= 70485574 ? 150
        : orbit>= 70643566 && orbit<= 72331977 ? 200
        : orbit>= 51050070 && orbit<= 52540652 ? 250
        : orbit>= 85271381 && orbit<= 86949588 ? 300
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 250
        : orbit>= 43933973 && orbit<= 45279891 ? 150
        : orbit>= 45502221 && orbit<= 46856313 ? 200
        : orbit>= 47079116 && orbit<= 48431144 ? 300
        : orbit>= 48652014 && orbit<= 50012383 ? 350
        : orbit>= 50179764 && orbit<= 51532937 ? 400
        : orbit>= 67303535 && orbit<= 68633680 ? 250
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 49203187 && orbit<= 51690032 ? 10
	    : orbit>= 51856967 && orbit<= 54283208 ? 20
	    : orbit>= 54445915 && orbit<= 56892967 ? 30
	    : orbit>= 57051839 && orbit<= 59538529 ? 40
	    : orbit>= 59697915 && orbit<= 62135204 ? 50
	    : orbit>= 62297225 && orbit<= 64782381 ? 60
	    : orbit>= 64943299 && orbit<= 67376977 ? 70
	    : orbit>= 67538741 && orbit<= 69999871 ? 80
	    : orbit>= 70139184 && orbit<= 72643799 ? 90
	    : orbit>= 72835854 && orbit<= 75255306 ? 100
	    : orbit>= 75446590 && orbit<= 77886498 ? 150
	    : orbit>= 78101351 && orbit<= 80773664 ? 200
	    : orbit>= 80938519 && orbit<= 83389351 ? 250
	    : orbit>= 83580458 && orbit<= 86015149 ? 300
	    : orbit>= 86258748 && orbit<= 88893999 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 14541227 && orbit<= 17055893 ? 125
	    : orbit>= 17244195 && orbit<= 19668685 ? 175
	    : orbit>= 19856002 && orbit<= 22294753 ? 225
	    : orbit>= 22585205 && orbit<= 25181837 ? 350
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 10
	    : orbit>= 41825841 && orbit<= 44322177 ? 20
	    : orbit>= 44480767 && orbit<= 46948744 ? 30
	    : orbit>= 47135051 && orbit<= 49565502 ? 40
	    : orbit>= 49728746 && orbit<= 52187784 ? 50
	    : orbit>= 52322198 && orbit<= 54804994 ? 60
	    : orbit>= 54969957 && orbit<= 57440386 ? 70
	    : orbit>= 57553203 && orbit<= 60043347 ? 80
	    : orbit>= 60176652 && orbit<= 62671231 ? 90
	    : orbit>= 62830841 && orbit<= 65299490 ? 100
	    : orbit>= 65460761 && orbit<= 67931853 ? 125
	    : orbit>= 68119359 && orbit<= 70522726 ? 150
	    : orbit>= 70683404 && orbit<= 73153756 ? 175
	    : orbit>= 73311203 && orbit<= 75775055 ? 200
	    : orbit>= 75933126 && orbit<= 78397728 ? 225
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
  case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 10
	    : orbit>= 27391881 && orbit<= 29910318 ? 20
	    : orbit>= 30048261 && orbit<= 32528621 ? 30
	    : orbit>= 32692410 && orbit<= 35184550 ? 40
	    : orbit>= 35347550 && orbit<= 37766749 ? 50
	    : orbit>= 37964504 && orbit<= 40393240 ? 60
	    : orbit>= 40564372 && orbit<= 43001725 ? 70
	    : orbit>= 43111459 && orbit<= 45637231 ? 80
	    : orbit>= 45800722 && orbit<= 48263040 ? 90
	    : orbit>= 48454863 && orbit<= 50886070 ? 100
	    : orbit>= 51052187 && orbit<= 53510050 ? 125
	    : orbit>= 53672834 && orbit<= 56130806 ? 150
	    : orbit>= 56294595 && orbit<= 58752882 ? 175
	    : orbit>= 58889269 && orbit<= 61372970 ? 200
	    : orbit>= 61571382 && orbit<= 63995005 ? 225
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 250
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 10
	    : orbit>= 47613845 && orbit<= 50105260 ? 20
	    : orbit>= 50188211 && orbit<= 52709208 ? 30
	    : orbit>= 52895444 && orbit<= 55339608 ? 40
	    : orbit>= 55500867 && orbit<= 57952349 ? 50
	    : orbit>= 58141198 && orbit<= 60574900 ? 60
	    : orbit>= 60717816 && orbit<= 63221110 ? 70
	    : orbit>= 63329551 && orbit<= 65809487 ? 80
	    : orbit>= 65969746 && orbit<= 68435462 ? 90
	    : orbit>= 68575779 && orbit<= 71053332 ? 100
	    : orbit>= 71220080 && orbit<= 73688468 ? 125
	    : orbit>= 73877439 && orbit<= 76301206 ? 150
	    : orbit>= 76461185 && orbit<= 78925237 ? 175
	    : orbit>= 79058767 && orbit<= 81554007 ? 200
	    : orbit>= 81740951 && orbit<= 84170667 ? 225
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 250
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 10
	    : orbit>= 47854891 && orbit<= 50359955 ? 20
	    : orbit>= 50522239 && orbit<= 52977308 ? 30
	    : orbit>= 53113522 && orbit<= 55616572 ? 40
	    : orbit>= 55755315 && orbit<= 58228213 ? 50
	    : orbit>= 58372274 && orbit<= 60827613 ? 60
	    : orbit>= 60995674 && orbit<= 63463695 ? 70
	    : orbit>= 63631902 && orbit<= 66076490 ? 80
	    : orbit>= 66213020 && orbit<= 68722423 ? 90
	    : orbit>= 68890165 && orbit<= 71333543 ? 100
	    : orbit>= 71498800 && orbit<= 73941265 ? 125
	    : orbit>= 74129851 && orbit<= 76570264 ? 150
	    : orbit>= 76734342 && orbit<= 79189022 ? 175
	    : orbit>= 79329459 && orbit<= 81814529 ? 200
	    : orbit>= 82013635 && orbit<= 84419465 ? 225
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 250
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 10
	    : orbit>= 9566810 && orbit<= 12075322 ? 20
	    : orbit>= 12213121 && orbit<= 14717975 ? 30
	    : orbit>= 14853577 && orbit<= 17316216 ? 40
	    : orbit>= 17503961 && orbit<= 19935530 ? 50
	    : orbit>= 20071439 && orbit<= 22554342 ? 60
	    : orbit>= 22715316 && orbit<= 25193763 ? 70
	    : orbit>= 25355311 && orbit<= 27817230 ? 80
	    : orbit>= 27926532 && orbit<= 30416278 ? 90
	    : orbit>= 30527882 && orbit<= 33049984 ? 100
	    : orbit>= 33212050 && orbit<= 35664191 ? 125
	    : orbit>= 35826282 && orbit<= 38287417 ? 150
	    : orbit>= 38504148 && orbit<= 40914406 ? 175
	    : orbit>= 41077682 && orbit<= 43524088 ? 200
	    : orbit>= 43659205 && orbit<= 46161085 ? 225
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 300
	      : NOVAL_I;
	case 320500:
	  return
	    orbit>= 84029426 && orbit<= 86514704 ? 20
	    : orbit>= 86704248 && orbit<= 89148784 ? 60
	    : orbit>= 89309079 && orbit<= 91796643 ? 100
	    : orbit>= 91955453 && orbit<= 94408266 ? 150
	    : orbit>= 94595917 && orbit<= 97306966 ? 200
	    : orbit>= 97519296 && orbit<= 100166193 ? 250
	    : orbit>= 100404858 && orbit<= 103044431 ? 300
	    : orbit>= 103257788 && orbit<= 105688471 ? 350
	    : orbit>= 105928441 && orbit<= 108559000 ? 400
	    : orbit>= 108878023 && orbit<= 111439160 ? 275
	    : orbit>= 111680359 && orbit<= 114320642 ? 225
	    : orbit>= 114454314 && orbit<= 116944501 ? 175
	    : orbit>= 117182640 && orbit<= 119852547 ? 125
	    : orbit>= 120093836 && orbit<= 122737282 ? 80
	    : orbit>= 122977071 && ls<= 477 ? 40
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 10
	    : orbit>= 4370646 && orbit<= 6835331 ? 20
	    : orbit>= 6998249 && orbit<= 9443899 ? 30
	    : orbit>= 9603408 && orbit<= 12088965 ? 40
	    : orbit>= 12249948 && orbit<= 14691253 ? 50
	    : orbit>= 14824908 && orbit<= 17317702 ? 60
	    : orbit>= 17479610 && orbit<= 19929276 ? 70
	    : orbit>= 20117009 && orbit<= 22560727 ? 80
	    : orbit>= 22748255 && orbit<= 25191626 ? 90
	    : orbit>= 25299297 && orbit<= 27799610 ? 100
	    : orbit>= 27936056 && orbit<= 30437130 ? 125
	    : orbit>= 30629196 && orbit<= 33078612 ? 150
	    : orbit>= 33186971 && orbit<= 35673738 ? 175
	    : orbit>= 35860673 && orbit<= 38283804 ? 200
	    : orbit>= 38417265 && orbit<= 40915199 ? 225
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 300
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 10
	    : orbit>= 63075867 && orbit<= 65549032 ? 20
	    : orbit>= 65683169 && orbit<= 68178385 ? 30
	    : orbit>= 68339788 && orbit<= 70786533 ? 40
	    : orbit>= 70945624 && orbit<= 73405782 ? 50
	    : orbit>= 73539162 && orbit<= 76031847 ? 60
	    : orbit>= 76194593 && orbit<= 78661829 ? 70
	    : orbit>= 78793861 && orbit<= 81294346 ? 80
	    : orbit>= 81402558 && orbit<= 83913027 ? 90
	    : orbit>= 84019032 && orbit<= 86545026 ? 100
	    : orbit>= 86678270 && orbit<= 89173927 ? 125
	    : orbit>= 89360682 && orbit<= 91778781 ? 150
	    : orbit>= 91965880 && orbit<= 94679839 ? 175
	    : orbit>= 94865315 && orbit<= 97286456 ? 200
	    : orbit>= 97472797 && orbit<= 99884436 ? 225
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 300
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 10
	    : orbit>= 58114200 && orbit<= 60588212 ? 20
	    : orbit>= 60724340 && orbit<= 63202264 ? 30
	    : orbit>= 63340322 && orbit<= 65817097 ? 40
	    : orbit>= 65979355 && orbit<= 68425849 ? 50
	    : orbit>= 68561709 && orbit<= 71071128 ? 60
	    : orbit>= 71233215 && orbit<= 73688647 ? 70
	    : orbit>= 73852199 && orbit<= 76310213 ? 80
	    : orbit>= 76473584 && orbit<= 78927087 ? 90
	    : orbit>= 79093199 && orbit<= 81541766 ? 100
	    : orbit>= 81704609 && orbit<= 84163799 ? 125
	    : orbit>= 84355052 && orbit<= 86800517 ? 150
	    : orbit>= 86965497 && orbit<= 89409147 ? 175
	    : orbit>= 89572559 && orbit<= 92042263 ? 200
	    : orbit>= 92204778 && orbit<= 94675917 ? 225
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 300
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 10
	    : orbit>= 43422348 && orbit<= 45881929 ? 20
	    : orbit>= 46018056 && orbit<= 48516945 ? 30
	    : orbit>= 48678223 && orbit<= 51169750 ? 40
	    : orbit>= 51304556 && orbit<= 53771512 ? 50
	    : orbit>= 53932342 && orbit<= 56381384 ? 60
	    : orbit>= 56516448 && orbit<= 59011528 ? 70
	    : orbit>= 59200521 && orbit<= 61617940 ? 80
	    : orbit>= 61753974 && orbit<= 64253057 ? 90
	    : orbit>= 64390607 && orbit<= 66854828 ? 100
	    : orbit>= 67018750 && orbit<= 69485929 ? 125
	    : orbit>= 69648708 && orbit<= 72118854 ? 150
	    : orbit>= 72306340 && orbit<= 74742683 ? 175
	    : orbit>= 74932909 && orbit<= 77350840 ? 200
	    : orbit>= 77510220 && orbit<= 79977923 ? 225
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 300
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 10
	    : orbit>= 52868613 && orbit<= 55321785 ? 20
	    : orbit>= 55462104 && orbit<= 57973413 ? 30
	    : orbit>= 58087326 && orbit<= 60562624 ? 40
	    : orbit>= 60709545 && orbit<= 63210483 ? 50
	    : orbit>= 63359047 && orbit<= 65804852 ? 60
	    : orbit>= 65946954 && orbit<= 68434710 ? 70
	    : orbit>= 68605001 && orbit<= 71096881 ? 80
	    : orbit>= 71238107 && orbit<= 73690920 ? 90
	    : orbit>= 73860855 && orbit<= 76295804 ? 100
	    : orbit>= 76465735 && orbit<= 78930971 ? 125
	    : orbit>= 79102261 && orbit<= 81539075 ? 150
	    : orbit>= 81714638 && orbit<= 84171548 ? 175
	    : orbit>= 84349817 && orbit<= 86788381 ? 200
	    : orbit>= 86964660 && orbit<= 89396615 ? 225
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 300
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
	case 352931:
	  return
	    orbit>= 1968481 && orbit<= 4736017 ? 10
	    : orbit>= 4784461 && orbit<= 7610810 ? 20
	    : orbit>= 7660060 && orbit<= 10511621 ? 30
	    : orbit>= 10562037 && orbit<= 13380721 ? 40
	    : orbit>= 13429646 && orbit<= 16268114 ? 50
	    : orbit>= 16390112 && orbit<= 19147855 ? 60
	    : orbit>= 19272670 && orbit<= 22032839 ? 70
	    : orbit>= 22082824 && orbit<= 24921952 ? 80
	    : orbit>= 25044824 && orbit<= 27805658 ? 90
	    : orbit>= 27855378 && orbit<= 30684689 ? 100
	    : orbit>= 30808993 && orbit<= 33579280 ? 120
	    : orbit>= 33629193 && orbit<= 36467115 ? 140
	    : orbit>= 36613893 && orbit<= 39337659 ? 160
	    : orbit>= 39386937 && orbit<= 42233511 ? 180
	    : orbit>= 42380958 && orbit<= 45108131 ? 200
	    : orbit>= 45157840 && orbit<= 47985532 ? 220
	    : orbit>= 48105844 && orbit<= 50885738 ? 240
	    : orbit>= 50934591 && orbit<= 53747920 ? 260
	    : orbit>= 53917558 && orbit<= 56637545 ? 280
	    : orbit>= 56686674 && orbit<= 59525018 ? 300
	    : orbit>= 59574993 && orbit<= 59797815 ? 300
	      : NOVAL_I;
	case 355135:
	  return
	    orbit>= 15379995 && orbit<= 18102008 ? 10
	    : orbit>= 18228854 && orbit<= 20978020 ? 20
	    : orbit>= 21156328 && orbit<= 23873234 ? 30
	    : orbit>= 23998387 && orbit<= 26745416 ? 40
	    : orbit>= 26921049 && orbit<= 29646696 ? 50
	    : orbit>= 29773853 && orbit<= 32514925 ? 60
	    : orbit>= 32641005 && orbit<= 35405111 ? 70
	    : orbit>= 35580839 && orbit<= 38281038 ? 80
	    : orbit>= 38409008 && orbit<= 41173172 ? 90
	    : orbit>= 41299853 && orbit<= 44066676 ? 100
	    : orbit>= 44293480 && orbit<= 47197273 ? 125
	    : orbit>= 47349961 && orbit<= 50098721 ? 150
	    : orbit>= 50325504 && orbit<= 53223044 ? 200
	    : orbit>= 53425185 && orbit<= 56126777 ? 250
	    : orbit>= 56408419 && orbit<= 59264438 ? 300
	      : NOVAL_I;
	case 357900:
	  return
	    orbit>= 12664081 && orbit<= 15486907 ? 10
	    : orbit>= 15566369 && orbit<= 18368115 ? 20
	    : orbit>= 18420230 && orbit<= 21247176 ? 30
	    : orbit>= 21378632 && orbit<= 24147295 ? 40
	    : orbit>= 24199731 && orbit<= 27025711 ? 50
	    : orbit>= 27077499 && orbit<= 29909218 ? 60
	    : orbit>= 29960548 && orbit<= 32790919 ? 70
	    : orbit>= 32843486 && orbit<= 35673003 ? 80
	    : orbit>= 35778744 && orbit<= 38555720 ? 90
	    : orbit>= 38608540 && orbit<= 41438736 ? 100
	    : orbit>= 41570546 && orbit<= 44324553 ? 120
	    : orbit>= 44455195 && orbit<= 47211734 ? 140
	    : orbit>= 47342579 && orbit<= 50093965 ? 160
	    : orbit>= 50251205 && orbit<= 52977181 ? 180
	    : orbit>= 53030010 && orbit<= 55863627 ? 200
	    : orbit>= 55916697 && orbit<= 58740975 ? 220
	    : orbit>= 58793298 && orbit<= 61624510 ? 240
	    : orbit>= 61784559 && orbit<= 64513818 ? 260
	    : orbit>= 64698513 && orbit<= 67393943 ? 280
	    : orbit>= 67551617 && orbit<= 70262612 ? 300
	    : orbit>= 70315602 && orbit<= 73150278 ? 300
	      : NOVAL_I;
	case 359571:
	  return
	    orbit>= 1598793 && orbit<= 4462108 ? 10
	    : orbit>= 4511395 && orbit<= 7350069 ? 20
	    : orbit>= 7399774 && orbit<= 10241564 ? 30
	    : orbit>= 10365345 && orbit<= 13132585 ? 40
	    : orbit>= 13255825 && orbit<= 15995781 ? 50
	    : orbit>= 16121215 && orbit<= 18899097 ? 60
	    : orbit>= 19022211 && orbit<= 21775984 ? 70
	    : orbit>= 21826416 && orbit<= 24672183 ? 80
	    : orbit>= 24722328 && orbit<= 27552047 ? 100
	    : orbit>= 27601834 && orbit<= 30433146 ? 120
	    : orbit>= 30557652 && orbit<= 33309141 ? 140
	    : orbit>= 33432366 && orbit<= 36193558 ? 160
	    : orbit>= 36243029 && orbit<= 39068178 ? 180
	    : orbit>= 39118463 && orbit<= 41969704 ? 200
	      : NOVAL_I;
	case 359575:
	  return
	    orbit>= 629737 && orbit<= 3422063 ? 220
	    : orbit>= 3548475 && orbit<= 6312050 ? 240
	    : orbit>= 6461056 && orbit<= 9196810 ? 260
	    : orbit>= 9348596 && orbit<= 12066809 ? 280
	    : orbit>= 12216331 && orbit<= 14954951 ? 325
	    : orbit>= 15107686 && orbit<= 17849142 ? 350
	    : orbit>= 18099677 && orbit<= 20986877 ? 300
	      : NOVAL_I;
	case 359998:
	  return
	    orbit>= 104875561 && orbit<= 107755135 ? 10
	    : orbit>= 107913968 && orbit<= 110630494 ? 20
	    : orbit>= 110788251 && orbit<= 113524201 ? 30
	    : orbit>= 113682052 && orbit<= 116420968 ? 40
	    : orbit>= 116550343 && orbit<= 119293351 ? 50
	    : orbit>= 119426118 && orbit<= 122178850 ? 60
	    : orbit>= 122336636 && orbit<= 125069620 ? 70
	    : orbit>= 125226412 && orbit<= 127952275 ? 80
	    : orbit>= 128057808 && orbit<= 130827303 ? 100
	    : orbit>= 130983638 && orbit<= 133718918 ? 120
	    : orbit>= 133823634 && orbit<= 136599596 ? 140
	    : orbit>= 136731343 && orbit<= 139480531 ? 160
	    : orbit>= 139610170 && orbit<= 142361614 ? 180
	    : orbit>= 142518456 && orbit<= 145248303 ? 200
	    : orbit>= 146982775 && orbit<= 149705976 ? 220
	    : orbit>= 149812001 && orbit<= 152574204 ? 240
	    : orbit>= 152707668 && orbit<= 155473411 ? 260
	    : orbit>= 155579472 && orbit<= 158344060 ? 280
	    : orbit>= 158503782 && orbit<= 161231425 ? 325
	    : orbit>= 161392164 && orbit<= 164109895 ? 350
	    : orbit>= 164399038 && orbit<= 167263402 ? 300
	      : NOVAL_I;
	case 360295:
	  return
	    orbit>= 250123817 && orbit<= 252997151 ? 10
	    : orbit>= 253130344 && orbit<= 255876427 ? 20
	    : orbit>= 256037677 && orbit<= 258760820 ? 30
	    : orbit>= 258895922 && orbit<= 261640771 ? 40
	    : orbit>= 261775735 && orbit<= 264513826 ? 50
	    : orbit>= 264621139 && orbit<= 267397855 ? 60
	    : orbit>= 267530956 && orbit<= 270282609 ? 70
	    : orbit>= 270417033 && orbit<= 273166939 ? 80
	    : orbit>= 273326940 && orbit<= 276051811 ? 100
	    : orbit>= 276185803 && orbit<= 278938988 ? 120
	    : orbit>= 279075317 && orbit<= 281832159 ? 140
	    : orbit>= 281965899 && orbit<= 284714222 ? 160
	    : orbit>= 284848582 && orbit<= 287602289 ? 180
	    : orbit>= 287735524 && orbit<= 290484727 ? 200
	    : orbit>= 290620075 && orbit<= 293353433 ? 220
	    : orbit>= 293460265 && orbit<= 296246415 ? 240
	    : orbit>= 296379312 && orbit<= 299138425 ? 260
	    : orbit>= 299301164 && orbit<= 302001233 ? 280
	    : orbit>= 302137056 && orbit<= 304881966 ? 325
	    : orbit>= 305042514 && orbit<= 307762219 ? 350
	    : orbit>= 308029792 && orbit<= 310911240 ? 300
	      : NOVAL_I;
	case 360796:
	  return
	    orbit>= 75646765 && orbit<= 78396600 ? 10
	    : orbit>= 78507985 && orbit<= 81277003 ? 20
	    : orbit>= 81385464 && orbit<= 84160318 ? 30
	    : orbit>= 84297227 && orbit<= 87050646 ? 40
	    : orbit>= 87186625 && orbit<= 89935156 ? 50
	    : orbit>= 90098419 && orbit<= 92830631 ? 60
	    : orbit>= 92967681 && orbit<= 95710970 ? 70
	    : orbit>= 95821281 && orbit<= 98586494 ? 80
	    : orbit>= 98719921 && orbit<= 101456347 ? 100
	    : orbit>= 101593245 && orbit<= 104351070 ? 120
	    : orbit>= 104512707 && orbit<= 107226276 ? 140
	    : orbit>= 107333521 && orbit<= 110118658 ? 160
	    : orbit>= 110228652 && orbit<= 112993580 ? 180
	    : orbit>= 113104333 && orbit<= 115892159 ? 200
	    : orbit>= 116055955 && orbit<= 118776123 ? 220
	    : orbit>= 118912464 && orbit<= 121643055 ? 240
	    : orbit>= 121808435 && orbit<= 124535570 ? 260
	    : orbit>= 124698262 && orbit<= 127419378 ? 280
	    : orbit>= 127525948 && orbit<= 130294767 ? 325
	    : orbit>= 130432704 && orbit<= 133198582 ? 350
	    : orbit>= 133472480 && orbit<= 136338129 ? 300
	      : NOVAL_I;
	case 361223:
	  return
	    orbit>= 38087387 && orbit<= 40918583 ? 10
	    : orbit>= 41051543 && orbit<= 43792557 ? 20
	    : orbit>= 43899276 && orbit<= 46692751 ? 30
	    : orbit>= 46801557 && orbit<= 49551982 ? 40
	    : orbit>= 49712638 && orbit<= 52437174 ? 50
	    : orbit>= 52517765 && orbit<= 55318121 ? 60
	    : orbit>= 55451536 && orbit<= 58222205 ? 70
	    : orbit>= 58329114 && orbit<= 61107309 ? 80
	    : orbit>= 61241257 && orbit<= 63972397 ? 100
	    : orbit>= 64107430 && orbit<= 66869015 ? 120
	    : orbit>= 67003578 && orbit<= 69740800 ? 140
	    : orbit>= 69877021 && orbit<= 72642959 ? 160
	    : orbit>= 72778246 && orbit<= 75522331 ? 180
	    : orbit>= 75658158 && orbit<= 78396727 ? 200
	    : orbit>= 78533017 && orbit<= 81279217 ? 220
	    : orbit>= 81441635 && orbit<= 84154693 ? 240
	    : orbit>= 84317433 && orbit<= 87037091 ? 260
	    : orbit>= 87173373 && orbit<= 89928279 ? 280
	    : orbit>= 90038254 && orbit<= 92820920 ? 325
	    : orbit>= 92984498 && orbit<= 95713653 ? 350
	    : orbit>= 95988057 && orbit<= 98845309 ? 300
	      : NOVAL_I;
	case 361475:
	  return
	    orbit>= 222110333 && orbit<= 224939149 ? 10
	    : orbit>= 225072545 && orbit<= 227809699 ? 20
	    : orbit>= 227970409 && orbit<= 230699599 ? 30
	    : orbit>= 230779861 && orbit<= 233595778 ? 40
	    : orbit>= 233703427 && orbit<= 236465704 ? 50
	    : orbit>= 236598359 && orbit<= 239360686 ? 60
	    : orbit>= 239493494 && orbit<= 242245761 ? 70
	    : orbit>= 242405079 && orbit<= 245128059 ? 80
	    : orbit>= 245285736 && orbit<= 248003579 ? 100
	    : orbit>= 248163112 && orbit<= 250881259 ? 120
	    : orbit>= 250985797 && orbit<= 253786244 ? 140
	    : orbit>= 253891737 && orbit<= 256655416 ? 160
	    : orbit>= 256787880 && orbit<= 259547532 ? 180
	    : orbit>= 259680999 && orbit<= 262420314 ? 200
	    : orbit>= 262551948 && orbit<= 265298416 ? 220
	    : orbit>= 265428875 && orbit<= 268195013 ? 240
	    : orbit>= 268380359 && orbit<= 271084430 ? 260
	    : orbit>= 271243461 && orbit<= 273967363 ? 280
	    : orbit>= 274125527 && orbit<= 276846908 ? 325
	    : orbit>= 277001884 && orbit<= 279718446 ? 350
	    : orbit>= 279980916 && orbit<= 282880383 ? 300
	      : NOVAL_I;
	case 361890:
	  return
	    orbit>= 3963493 && orbit<= 9459187 ? 10
	    : orbit>= 9564419 && orbit<= 14968438 ? 20
	    : orbit>= 15099769 && orbit<= 20474451 ? 30
	    : orbit>= 20579259 && orbit<= 25958161 ? 40
	    : orbit>= 26114369 && orbit<= 31484064 ? 50
	    : orbit>= 31641788 && orbit<= 36981269 ? 60
	    : orbit>= 37111781 && orbit<= 42498466 ? 70
	    : orbit>= 42630885 && orbit<= 47984783 ? 80
	    : orbit>= 48115296 && orbit<= 53504821 ? 100
	    : orbit>= 53660650 && orbit<= 59011469 ? 120
	    : orbit>= 59143042 && orbit<= 64514429 ? 140
	    : orbit>= 64673894 && orbit<= 70005563 ? 160
	    : orbit>= 70138844 && orbit<= 75510829 ? 180
	    : orbit>= 75642832 && orbit<= 81009063 ? 200
	    : orbit>= 81141608 && orbit<= 86536110 ? 220
	    : orbit>= 86643866 && orbit<= 92044401 ? 240
	    : orbit>= 92180485 && orbit<= 97528310 ? 260
	    : orbit>= 97636672 && orbit<= 103045464 ? 280
	    : orbit>= 103180825 && orbit<= 108550068 ? 325
	    : orbit>= 108712296 && orbit<= 114044835 ? 350
	    : orbit>= 114313672 && orbit<= 119810887 ? 300
	      : NOVAL_I;
	case 362617:
	  return
	    orbit>= 1675207 && orbit<= 4482307 ? 10
	    : orbit>= 4589516 && orbit<= 7345565 ? 25
	    : orbit>= 7503560 && orbit<= 10251143 ? 50
	    : orbit>= 10383641 && orbit<= 13118256 ? 75
	    : orbit>= 13251150 && orbit<= 16012285 ? 100
	    : orbit>= 16092002 && orbit<= 18904691 ? 120
	    : orbit>= 19064644 && orbit<= 21780375 ? 140
	    : orbit>= 21915491 && orbit<= 24647683 ? 160
	    : orbit>= 24781469 && orbit<= 27544216 ? 180
	    : orbit>= 27701105 && orbit<= 30425847 ? 200
	    : orbit>= 30531014 && orbit<= 33309354 ? 220
	    : orbit>= 33440550 && orbit<= 36205433 ? 240
	    : orbit>= 36311560 && orbit<= 39080353 ? 260
	    : orbit>= 39211611 && orbit<= 41966680 ? 280
	    : orbit>= 42123525 && orbit<= 44832214 ? 320
	    : orbit>= 44963600 && orbit<= 47738950 ? 340
	    : orbit>= 47870274 && orbit<= 50611790 ? 360
	    : orbit>= 50717573 && orbit<= 53483918 ? 380
	    : orbit>= 53643704 && orbit<= 56368187 ? 400
	    : orbit>= 56499465 && orbit<= 59266913 ? 425
	    : orbit>= 59529205 && orbit<= 62409575 ? 300
	      : NOVAL_I;
	case 365775:
	  return
	    orbit>= 11674141 && orbit<= 14429083 ? 200
	    : orbit>= 14589392 && orbit<= 17324633 ? 220
	    : orbit>= 17510902 && orbit<= 20196585 ? 240
	    : orbit>= 20383796 && orbit<= 23092362 ? 260
	    : orbit>= 23253989 && orbit<= 25982133 ? 280
	    : orbit>= 26197706 && orbit<= 29103790 ? 320
	    : orbit>= 29319343 && orbit<= 32255384 ? 340
	    : orbit>= 32444673 && orbit<= 35145650 ? 360
	    : orbit>= 35334294 && orbit<= 38017264 ? 380
	    : orbit>= 38180097 && orbit<= 40924604 ? 400
	    : orbit>= 41087244 && orbit<= 43808026 ? 425
	    : orbit>= 44514502 && orbit<= 47198988 ? 10
	    : orbit>= 47361806 && orbit<= 50091213 ? 25
	    : orbit>= 50255317 && orbit<= 52961410 ? 50
	    : orbit>= 53152818 && orbit<= 55865611 ? 75
	    : orbit>= 56057509 && orbit<= 59001403 ? 100
	    : orbit>= 59192755 && orbit<= 61877774 ? 120
	    : orbit>= 62043689 && orbit<= 64774124 ? 140
	    : orbit>= 64884831 && orbit<= 67653732 ? 160
	    : orbit>= 67791500 && orbit<= 70538399 ? 180
	    : orbit>= 70818655 && orbit<= 73668482 ? 300
	      : NOVAL_I;
	case 366451:
	  return
	    orbit>= 11427179 && orbit<= 14160940 ? 10
	    : orbit>= 14382455 && orbit<= 17324839 ? 40
	    : orbit>= 17573565 && orbit<= 20460932 ? 80
	    : orbit>= 20710526 && orbit<= 23611692 ? 120
	    : orbit>= 23862063 && orbit<= 26749131 ? 160
	    : orbit>= 26969444 && orbit<= 29902584 ? 200
	    : orbit>= 30175576 && orbit<= 33058196 ? 230
	    : orbit>= 33332287 && orbit<= 36185466 ? 260
	    : orbit>= 36408444 && orbit<= 39337900 ? 280
	    : orbit>= 39558702 && orbit<= 42481928 ? 320
	    : orbit>= 42732455 && orbit<= 45642756 ? 340
	    : orbit>= 45914551 && orbit<= 48781132 ? 370
	    : orbit>= 49056415 && orbit<= 51921275 ? 400
	    : orbit>= 52194942 && orbit<= 55078899 ? 430
	    : orbit>= 55408643 && orbit<= 58210178 ? 300
	      : NOVAL_I;
	case 367262:
	  return
	    orbit>= 7099870 && orbit<= 9973319 ? 10
	    : orbit>= 10169046 && orbit<= 12852101 ? 25
	    : orbit>= 13040868 && orbit<= 15739671 ? 50
	    : orbit>= 15959748 && orbit<= 18892548 ? 75
	    : orbit>= 19083998 && orbit<= 21766757 ? 100
	    : orbit>= 21931959 && orbit<= 24652329 ? 120
	    : orbit>= 24817938 && orbit<= 27542550 ? 140
	    : orbit>= 27734239 && orbit<= 30417342 ? 160
	    : orbit>= 30608624 && orbit<= 33313703 ? 180
	    : orbit>= 33505478 && orbit<= 36453885 ? 200
	    : orbit>= 36587559 && orbit<= 39346964 ? 220
	    : orbit>= 39511702 && orbit<= 42230281 ? 240
	    : orbit>= 42366690 && orbit<= 45102527 ? 260
	    : orbit>= 45240256 && orbit<= 47984863 ? 280
	    : orbit>= 48176143 && orbit<= 50887425 ? 320
	    : orbit>= 51050647 && orbit<= 53762229 ? 340
	    : orbit>= 53954281 && orbit<= 56911774 ? 360
	    : orbit>= 57075795 && orbit<= 59793547 ? 380
	    : orbit>= 59929631 && orbit<= 62659588 ? 400
	    : orbit>= 62878057 && orbit<= 65827762 ? 425
	    : orbit>= 66128316 && orbit<= 68970973 ? 300
	      : NOVAL_I;
	case 367691:
	  return
	    orbit>= 38093805 && orbit<= 40915552 ? 10
	    : orbit>= 41110913 && orbit<= 44047646 ? 25
	    : orbit>= 44186753 && orbit<= 46929565 ? 50
	    : orbit>= 47125589 && orbit<= 49838059 ? 75
	    : orbit>= 50003212 && orbit<= 52705357 ? 100
	    : orbit>= 52896569 && orbit<= 55580803 ? 120
	      : NOVAL_I;
	case 367693:
	  return
	    orbit>= 1098110 && orbit<= 3945219 ? 120
	    : orbit>= 4135366 && orbit<= 6829305 ? 140
	      : NOVAL_I;
	case 367696:
	  return
	    orbit>= 3506414 && orbit<= 6308118 ? 160
	    : orbit>= 6506342 && orbit<= 9468137 ? 180
	    : orbit>= 9637017 && orbit<= 12338491 ? 200
	    : orbit>= 12533908 && orbit<= 15483844 ? 220
	    : orbit>= 15653641 && orbit<= 18355679 ? 240
	    : orbit>= 18555832 && orbit<= 21245305 ? 260
	    : orbit>= 21385589 && orbit<= 24127787 ? 280
	    : orbit>= 24298863 && orbit<= 27024565 ? 320
	    : orbit>= 27136462 && orbit<= 29892124 ? 340
	    : orbit>= 30062691 && orbit<= 32789318 ? 360
	    : orbit>= 32929346 && orbit<= 35656656 ? 380
	    : orbit>= 35826537 && orbit<= 38555859 ? 400
	    : orbit>= 38755411 && orbit<= 41712687 ? 425
	    : orbit>= 42025627 && orbit<= 44837160 ? 300
	      : NOVAL_I;
	case 368318:
	  return
	    orbit>= 38680055 && orbit<= 41436877 ? 10
	    : orbit>= 41571843 && orbit<= 44311348 ? 25
	    : orbit>= 44502309 && orbit<= 47205698 ? 50
	    : orbit>= 47421959 && orbit<= 50347521 ? 75
	    : orbit>= 50508280 && orbit<= 53224276 ? 100
	    : orbit>= 53385408 && orbit<= 56124453 ? 120
	    : orbit>= 56286132 && orbit<= 58997544 ? 140
	    : orbit>= 59161176 && orbit<= 61882440 ? 160
	    : orbit>= 62071686 && orbit<= 64759415 ? 180
	    : orbit>= 64977629 && orbit<= 67907945 ? 200
	    : orbit>= 68097540 && orbit<= 70786060 ? 220
	    : orbit>= 70948149 && orbit<= 73673465 ? 240
	    : orbit>= 73863541 && orbit<= 76551518 ? 260
	    : orbit>= 76713898 && orbit<= 79436967 ? 280
	    : orbit>= 79601241 && orbit<= 82331790 ? 320
	      : NOVAL_I;
	case 368320:
	  return
	    orbit>= 7296034 && orbit<= 10245784 ? 340
	    : orbit>= 10436831 && orbit<= 13120570 ? 360
	    : orbit>= 13256620 && orbit<= 16014083 ? 380
	    : orbit>= 16205744 && orbit<= 19147750 ? 400
	    : orbit>= 19340819 && orbit<= 22029462 ? 425
	    : orbit>= 22359114 && orbit<= 25197863 ? 300
	      : NOVAL_I;
	case 368636:
	  return
	    orbit>= 33385564 && orbit<= 36207914 ? 10
	    : orbit>= 36371515 && orbit<= 39085596 ? 25
	    : orbit>= 39249532 && orbit<= 41952787 ? 50
	    : orbit>= 42143811 && orbit<= 44832462 ? 75
	    : orbit>= 44995928 && orbit<= 47737091 ? 100
	    : orbit>= 47899342 && orbit<= 50615477 ? 120
	    : orbit>= 50751769 && orbit<= 53490218 ? 140
	    : orbit>= 53653665 && orbit<= 56365742 ? 160
	    : orbit>= 56528473 && orbit<= 59270226 ? 180
	    : orbit>= 59461047 && orbit<= 62411805 ? 200
	    : orbit>= 62548295 && orbit<= 65290140 ? 220
	    : orbit>= 65425227 && orbit<= 68169459 ? 240
	    : orbit>= 68331785 && orbit<= 71070912 ? 260
	    : orbit>= 71234301 && orbit<= 73930658 ? 280
	    : orbit>= 74121783 && orbit<= 76837685 ? 320
	    : orbit>= 76973011 && orbit<= 79706299 ? 340
	    : orbit>= 79868802 && orbit<= 82607141 ? 360
	    : orbit>= 82768510 && orbit<= 85484677 ? 380
	    : orbit>= 85646605 && orbit<= 88362620 ? 400
	    : orbit>= 88525784 && orbit<= 91244037 ? 425
	    : orbit>= 91540489 && orbit<= 94394769 ? 300
	      : NOVAL_I;
	case 370169:
	  return
	    orbit>= 40342105 && orbit<= 43280163 ? 10
	    : orbit>= 43446024 && orbit<= 46163964 ? 25
	    : orbit>= 46360986 && orbit<= 49310460 ? 50
	    : orbit>= 49475797 && orbit<= 52185788 ? 75
	    : orbit>= 52352339 && orbit<= 55071756 ? 100
	    : orbit>= 55239247 && orbit<= 57948217 ? 120
	    : orbit>= 58115174 && orbit<= 60824770 ? 140
	    : orbit>= 60992420 && orbit<= 63706944 ? 160
	    : orbit>= 63845307 && orbit<= 66614001 ? 180
	    : orbit>= 66782084 && orbit<= 69473855 ? 200
	    : orbit>= 69641850 && orbit<= 72375108 ? 220
	    : orbit>= 72571092 && orbit<= 75528087 ? 240
	    : orbit>= 75722880 && orbit<= 78653907 ? 260
	    : orbit>= 78849747 && orbit<= 81532531 ? 280
	    : orbit>= 81672588 && orbit<= 84442221 ? 320
	    : orbit>= 84637613 && orbit<= 87569623 ? 340
	    : orbit>= 87737354 && orbit<= 90457916 ? 360
	    : orbit>= 90623611 && orbit<= 93355955 ? 380
	    : orbit>= 93522339 && orbit<= 96229970 ? 400
	    : orbit>= 96368015 && orbit<= 99098219 ? 425
	    : orbit>= 99434925 && orbit<= 102250856 ? 350
	      : NOVAL_I;
	case 370772:
	  return
	    orbit>= 52470445 && orbit<= 55333639 ? 10
	    : orbit>= 55472333 && orbit<= 58213155 ? 25
	    : orbit>= 58377241 && orbit<= 61089932 ? 50
	    : orbit>= 61256076 && orbit<= 63986325 ? 75
	    : orbit>= 64151875 && orbit<= 66856984 ? 100
	    : orbit>= 67024241 && orbit<= 69745556 ? 120
	    : orbit>= 69882848 && orbit<= 72642643 ? 140
	    : orbit>= 72780104 && orbit<= 75513072 ? 160
	    : orbit>= 75705636 && orbit<= 78389735 ? 180
	    : orbit>= 78527331 && orbit<= 81287919 ? 200
	    : orbit>= 81481429 && orbit<= 84417782 ? 220
	    : orbit>= 84582153 && orbit<= 87299914 ? 240
	    : orbit>= 87493915 && orbit<= 90188367 ? 260
	    : orbit>= 90382679 && orbit<= 93075344 ? 280
	    : orbit>= 93240739 && orbit<= 95958111 ? 300
	    : orbit>= 96127506 && orbit<= 98855902 ? 325
	    : orbit>= 98995097 && orbit<= 101722000 ? 375
	    : orbit>= 101919990 && orbit<= 104619178 ? 400
	    : orbit>= 104813521 && orbit<= 107747043 ? 425
	    : orbit>= 107916236 && orbit<= 110656907 ? 450
	    : orbit>= 110966804 && orbit<= 113797510 ? 350
	      : NOVAL_I;
	case 372597:
	  return
	    orbit>= 7903752 && orbit<= 13394769 ? 10
	    : orbit>= 13557899 && orbit<= 18905971 ? 25
	    : orbit>= 19067942 && orbit<= 24398996 ? 50
	    : orbit>= 24559026 && orbit<= 29910640 ? 75
	    : orbit>= 30098947 && orbit<= 35673648 ? 100
	    : orbit>= 35834767 && orbit<= 41184922 ? 120
	    : orbit>= 41347438 && orbit<= 46668343 ? 140
	    : orbit>= 46855827 && orbit<= 52173231 ? 160
	      : NOVAL_I;
	case 372598:
	  return
	    orbit>= 2746350 && orbit<= 8139349 ? 180
	    : orbit>= 8273753 && orbit<= 13650923 ? 200
	    : orbit>= 15111512 && orbit<= 20472285 ? 220
	      : NOVAL_I;
	case 372601:
	  return
	    orbit>= 490474 && orbit<= 6042138 ? 240
	    : orbit>= 6176244 && orbit<= 11549929 ? 260
	      : NOVAL_I;
	case 372602:
	  return
	    orbit>= 361535 && orbit<= 5785597 ? 280
	    : orbit>= 5948983 && orbit<= 11296711 ? 300
	    : orbit>= 11459733 && orbit<= 16786650 ? 325
	    : orbit>= 16923122 && orbit<= 22312993 ? 375
	    : orbit>= 22477745 && orbit<= 27808336 ? 400
	    : orbit>= 28000123 && orbit<= 33564939 ? 425
	    : orbit>= 33759233 && orbit<= 39083698 ? 450
	    : orbit>= 39385415 && orbit<= 44853027 ? 350
	      : NOVAL_I;
	case 375697:
	  return
	    orbit>= 14181054 && orbit<= 17056109 ? 10
	    : orbit>= 17275876 && orbit<= 20193293 ? 50
	    : orbit>= 20388031 && orbit<= 23095530 ? 100
	    : orbit>= 23289806 && orbit<= 26236248 ? 140
	    : orbit>= 26403276 && orbit<= 29104372 ? 180
	    : orbit>= 29271858 && orbit<= 32013840 ? 220
	    : orbit>= 32126302 && orbit<= 34880439 ? 240
	    : orbit>= 35047818 && orbit<= 37760914 ? 260
	    : orbit>= 37929290 && orbit<= 40658642 ? 280
	    : orbit>= 40852199 && orbit<= 43809979 ? 300
	    : orbit>= 43977324 && orbit<= 46666746 ? 325
	    : orbit>= 46832244 && orbit<= 49562209 ? 375
	    : orbit>= 49759108 && orbit<= 52723019 ? 400
	    : orbit>= 52860920 && orbit<= 55597269 ? 425
	    : orbit>= 55790859 && orbit<= 58751634 ? 450
	    : orbit>= 59029356 && orbit<= 61896178 ? 350
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
    case 301086:
      return
      	ls  >= 44 && ls<= 72 ?  100
        : orbit>= 63271699 && orbit<= 65364783 ? 20
        : orbit>= 65661133 && orbit<= 67651616 ? 40
        : orbit>= 67895036 && orbit<= 69885566 ? 60
        : orbit>= 70132973 && orbit<= 72145405 ? 80
	  : NOVAL_I;
    case 301912:
      return
        orbit>= 22840887 && orbit<= 24889630 ? 200
	  : NOVAL_I;
    case 303795:
      return
        orbit>= 87484993 && orbit<= 89032277 ? 50
        : orbit>= 89218917 && orbit<= 90844165 ? 100
        : orbit>= 91034966 && orbit<= 92594483 ? 150
        : orbit>= 92784418 && orbit<= 94341300 ? 250
        : orbit>= 51050070 && orbit<= 52540652 ? 200
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 200
        : orbit>= 52140033 && orbit<= 53489015 ? 100
        : orbit>= 53655274 && orbit<= 55006273 ? 150
        : orbit>= 55172056 && orbit<= 56522975 ? 250
        : orbit>= 56690865 && orbit<= 58043147 ? 300
        : orbit>= 67303535 && orbit<= 68633680 ? 200
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 89689664 && orbit<= 92311119 ? 10
	    : orbit>= 92472812 && orbit<= 94927270 ? 20
	    : orbit>= 95120809 && orbit<= 97536875 ? 30
	    : orbit>= 97703946 && orbit<= 100168652 ? 40
	    : orbit>= 100334028 && orbit<= 102783139 ? 50
	    : orbit>= 102972115 && orbit<= 105406833 ? 60
	    : orbit>= 105594033 && orbit<= 108059073 ? 70
	    : orbit>= 108246648 && orbit<= 110908752 ? 80
	    : orbit>= 111095814 && orbit<= 113516127 ? 90
	    : orbit>= 113704728 && orbit<= 116158230 ? 100
	    : orbit>= 116345830 && orbit<= 118778641 ? 150
	    : orbit>= 118991865 && orbit<= 121399693 ? 200
	    : orbit>= 121481216 && orbit<= 124017418 ? 250
	    : orbit>= 124231352 && orbit<= 126620937 ? 300
	    : orbit>= 126840130 && orbit<= 129247729 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 25614942 && orbit<= 28068392 ? 125
	    : orbit>= 28261245 && orbit<= 30691838 ? 175
	    : orbit>= 30825898 && orbit<= 33304291 ? 225
	    : orbit>= 33569057 && orbit<= 36202926 ? 350
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 10
	    : orbit>= 41825841 && orbit<= 44322177 ? 20
	    : orbit>= 44480767 && orbit<= 46948744 ? 30
	    : orbit>= 47135051 && orbit<= 49565502 ? 40
	    : orbit>= 49728746 && orbit<= 52187784 ? 50
	    : orbit>= 52322198 && orbit<= 54804994 ? 60
	    : orbit>= 54969957 && orbit<= 57440386 ? 70
	    : orbit>= 57553203 && orbit<= 60043347 ? 80
	    : orbit>= 60176652 && orbit<= 62671231 ? 90
	    : orbit>= 62830841 && orbit<= 65299490 ? 100
	    : orbit>= 65460761 && orbit<= 67931853 ? 125
	    : orbit>= 68119359 && orbit<= 70522726 ? 150
	    : orbit>= 70683404 && orbit<= 73153756 ? 175
	    : orbit>= 73311203 && orbit<= 75775055 ? 200
	    : orbit>= 75933126 && orbit<= 78397728 ? 225
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
  case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 10
	    : orbit>= 27391881 && orbit<= 29910318 ? 20
	    : orbit>= 30048261 && orbit<= 32528621 ? 30
	    : orbit>= 32692410 && orbit<= 35184550 ? 40
	    : orbit>= 35347550 && orbit<= 37766749 ? 50
	    : orbit>= 37964504 && orbit<= 40393240 ? 60
	    : orbit>= 40564372 && orbit<= 43001725 ? 70
	    : orbit>= 43111459 && orbit<= 45637231 ? 80
	    : orbit>= 45800722 && orbit<= 48263040 ? 90
	    : orbit>= 48454863 && orbit<= 50886070 ? 100
	    : orbit>= 51052187 && orbit<= 53510050 ? 125
	    : orbit>= 53672834 && orbit<= 56130806 ? 150
	    : orbit>= 56294595 && orbit<= 58752882 ? 175
	    : orbit>= 58889269 && orbit<= 61372970 ? 200
	    : orbit>= 61571382 && orbit<= 63995005 ? 225
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 200
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 10
	    : orbit>= 47613845 && orbit<= 50105260 ? 20
	    : orbit>= 50188211 && orbit<= 52709208 ? 30
	    : orbit>= 52895444 && orbit<= 55339608 ? 40
	    : orbit>= 55500867 && orbit<= 57952349 ? 50
	    : orbit>= 58141198 && orbit<= 60574900 ? 60
	    : orbit>= 60717816 && orbit<= 63221110 ? 70
	    : orbit>= 63329551 && orbit<= 65809487 ? 80
	    : orbit>= 65969746 && orbit<= 68435462 ? 90
	    : orbit>= 68575779 && orbit<= 71053332 ? 100
	    : orbit>= 71220080 && orbit<= 73688468 ? 125
	    : orbit>= 73877439 && orbit<= 76301206 ? 150
	    : orbit>= 76461185 && orbit<= 78925237 ? 175
	    : orbit>= 79058767 && orbit<= 81554007 ? 200
	    : orbit>= 81740951 && orbit<= 84170667 ? 225
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 200
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 10
	    : orbit>= 47854891 && orbit<= 50359955 ? 20
	    : orbit>= 50522239 && orbit<= 52977308 ? 30
	    : orbit>= 53113522 && orbit<= 55616572 ? 40
	    : orbit>= 55755315 && orbit<= 58228213 ? 50
	    : orbit>= 58372274 && orbit<= 60827613 ? 60
	    : orbit>= 60995674 && orbit<= 63463695 ? 70
	    : orbit>= 63631902 && orbit<= 66076490 ? 80
	    : orbit>= 66213020 && orbit<= 68722423 ? 90
	    : orbit>= 68890165 && orbit<= 71333543 ? 100
	    : orbit>= 71498800 && orbit<= 73941265 ? 125
	    : orbit>= 74129851 && orbit<= 76570264 ? 150
	    : orbit>= 76734342 && orbit<= 79189022 ? 175
	    : orbit>= 79329459 && orbit<= 81814529 ? 200
	    : orbit>= 82013635 && orbit<= 84419465 ? 225
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 200
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 10
	    : orbit>= 9566810 && orbit<= 12075322 ? 20
	    : orbit>= 12213121 && orbit<= 14717975 ? 30
	    : orbit>= 14853577 && orbit<= 17316216 ? 40
	    : orbit>= 17503961 && orbit<= 19935530 ? 50
	    : orbit>= 20071439 && orbit<= 22554342 ? 60
	    : orbit>= 22715316 && orbit<= 25193763 ? 70
	    : orbit>= 25355311 && orbit<= 27817230 ? 80
	    : orbit>= 27926532 && orbit<= 30416278 ? 90
	    : orbit>= 30527882 && orbit<= 33049984 ? 100
	    : orbit>= 33212050 && orbit<= 35664191 ? 125
	    : orbit>= 35826282 && orbit<= 38287417 ? 150
	    : orbit>= 38504148 && orbit<= 40914406 ? 175
	    : orbit>= 41077682 && orbit<= 43524088 ? 200
	    : orbit>= 43659205 && orbit<= 46161085 ? 225
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 250
	      : NOVAL_I;
	case 320570:
	  return
	    orbit>= 3912124 && orbit<= 6576017 ? 10
	    : orbit>= 6739153 && orbit<= 9219039 ? 20
	    : orbit>= 9406451 && orbit<= 11820881 ? 30
	    : orbit>= 12008626 && orbit<= 14437338 ? 40
	    : orbit>= 14625889 && orbit<= 17098820 ? 50
	    : orbit>= 17260535 && orbit<= 19680876 ? 60
	    : orbit>= 19868619 && orbit<= 22292703 ? 70
	    : orbit>= 22481459 && orbit<= 24931178 ? 80
	    : orbit>= 25065836 && orbit<= 27546766 ? 90
	    : orbit>= 27706651 && orbit<= 30152915 ? 100
	    : orbit>= 30369098 && orbit<= 32798197 ? 125
	    : orbit>= 32986003 && orbit<= 35437784 ? 150
	    : orbit>= 35625697 && orbit<= 38024355 ? 175
	    : orbit>= 38213131 && orbit<= 40662809 ? 200
	    : orbit>= 40796989 && orbit<= 43264760 ? 250
	    : orbit>= 43425814 && orbit<= 45906240 ? 300
	    : orbit>= 46121187 && orbit<= 48813848 ? 400
	    : orbit>= 49136071 && orbit<= 49322439 ? 250
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 10
	    : orbit>= 4370646 && orbit<= 6835331 ? 20
	    : orbit>= 6998249 && orbit<= 9443899 ? 30
	    : orbit>= 9603408 && orbit<= 12088965 ? 40
	    : orbit>= 12249948 && orbit<= 14691253 ? 50
	    : orbit>= 14824908 && orbit<= 17317702 ? 60
	    : orbit>= 17479610 && orbit<= 19929276 ? 70
	    : orbit>= 20117009 && orbit<= 22560727 ? 80
	    : orbit>= 22748255 && orbit<= 25191626 ? 90
	    : orbit>= 25299297 && orbit<= 27799610 ? 100
	    : orbit>= 27936056 && orbit<= 30437130 ? 125
	    : orbit>= 30629196 && orbit<= 33078612 ? 150
	    : orbit>= 33186971 && orbit<= 35673738 ? 175
	    : orbit>= 35860673 && orbit<= 38283804 ? 200
	    : orbit>= 38417265 && orbit<= 40915199 ? 225
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 250
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 10
	    : orbit>= 63075867 && orbit<= 65549032 ? 20
	    : orbit>= 65683169 && orbit<= 68178385 ? 30
	    : orbit>= 68339788 && orbit<= 70786533 ? 40
	    : orbit>= 70945624 && orbit<= 73405782 ? 50
	    : orbit>= 73539162 && orbit<= 76031847 ? 60
	    : orbit>= 76194593 && orbit<= 78661829 ? 70
	    : orbit>= 78793861 && orbit<= 81294346 ? 80
	    : orbit>= 81402558 && orbit<= 83913027 ? 90
	    : orbit>= 84019032 && orbit<= 86545026 ? 100
	    : orbit>= 86678270 && orbit<= 89173927 ? 125
	    : orbit>= 89360682 && orbit<= 91778781 ? 150
	    : orbit>= 91965880 && orbit<= 94679839 ? 175
	    : orbit>= 94865315 && orbit<= 97286456 ? 200
	    : orbit>= 97472797 && orbit<= 99884436 ? 225
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 250
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 10
	    : orbit>= 58114200 && orbit<= 60588212 ? 20
	    : orbit>= 60724340 && orbit<= 63202264 ? 30
	    : orbit>= 63340322 && orbit<= 65817097 ? 40
	    : orbit>= 65979355 && orbit<= 68425849 ? 50
	    : orbit>= 68561709 && orbit<= 71071128 ? 60
	    : orbit>= 71233215 && orbit<= 73688647 ? 70
	    : orbit>= 73852199 && orbit<= 76310213 ? 80
	    : orbit>= 76473584 && orbit<= 78927087 ? 90
	    : orbit>= 79093199 && orbit<= 81541766 ? 100
	    : orbit>= 81704609 && orbit<= 84163799 ? 125
	    : orbit>= 84355052 && orbit<= 86800517 ? 150
	    : orbit>= 86965497 && orbit<= 89409147 ? 175
	    : orbit>= 89572559 && orbit<= 92042263 ? 200
	    : orbit>= 92204778 && orbit<= 94675917 ? 225
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 250
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 10
	    : orbit>= 43422348 && orbit<= 45881929 ? 20
	    : orbit>= 46018056 && orbit<= 48516945 ? 30
	    : orbit>= 48678223 && orbit<= 51169750 ? 40
	    : orbit>= 51304556 && orbit<= 53771512 ? 50
	    : orbit>= 53932342 && orbit<= 56381384 ? 60
	    : orbit>= 56516448 && orbit<= 59011528 ? 70
	    : orbit>= 59200521 && orbit<= 61617940 ? 80
	    : orbit>= 61753974 && orbit<= 64253057 ? 90
	    : orbit>= 64390607 && orbit<= 66854828 ? 100
	    : orbit>= 67018750 && orbit<= 69485929 ? 125
	    : orbit>= 69648708 && orbit<= 72118854 ? 150
	    : orbit>= 72306340 && orbit<= 74742683 ? 175
	    : orbit>= 74932909 && orbit<= 77350840 ? 200
	    : orbit>= 77510220 && orbit<= 79977923 ? 225
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 250
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 10
	    : orbit>= 52868613 && orbit<= 55321785 ? 20
	    : orbit>= 55462104 && orbit<= 57973413 ? 30
	    : orbit>= 58087326 && orbit<= 60562624 ? 40
	    : orbit>= 60709545 && orbit<= 63210483 ? 50
	    : orbit>= 63359047 && orbit<= 65804852 ? 60
	    : orbit>= 65946954 && orbit<= 68434710 ? 70
	    : orbit>= 68605001 && orbit<= 71096881 ? 80
	    : orbit>= 71238107 && orbit<= 73690920 ? 90
	    : orbit>= 73860855 && orbit<= 76295804 ? 100
	    : orbit>= 76465735 && orbit<= 78930971 ? 125
	    : orbit>= 79102261 && orbit<= 81539075 ? 150
	    : orbit>= 81714638 && orbit<= 84171548 ? 175
	    : orbit>= 84349817 && orbit<= 86788381 ? 200
	    : orbit>= 86964660 && orbit<= 89396615 ? 225
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 250
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
	case 352931:
	  return
	    orbit>= 1968481 && orbit<= 4736017 ? 10
	    : orbit>= 4784461 && orbit<= 7610810 ? 20
	    : orbit>= 7660060 && orbit<= 10511621 ? 30
	    : orbit>= 10562037 && orbit<= 13380721 ? 40
	    : orbit>= 13429646 && orbit<= 16268114 ? 50
	    : orbit>= 16390112 && orbit<= 19147855 ? 60
	    : orbit>= 19272670 && orbit<= 22032839 ? 70
	    : orbit>= 22082824 && orbit<= 24921952 ? 80
	    : orbit>= 25044824 && orbit<= 27805658 ? 90
	    : orbit>= 27855378 && orbit<= 30684689 ? 100
	    : orbit>= 30808993 && orbit<= 33579280 ? 125
	    : orbit>= 33629193 && orbit<= 36467115 ? 150
	    : orbit>= 36613893 && orbit<= 39337659 ? 175
	    : orbit>= 39386937 && orbit<= 42233511 ? 200
	    : orbit>= 42380958 && orbit<= 45108131 ? 225
	    : orbit>= 45157840 && orbit<= 47985532 ? 250
	    : orbit>= 48105844 && orbit<= 50885738 ? 275
	    : orbit>= 50934591 && orbit<= 53747920 ? 300
	    : orbit>= 53917558 && orbit<= 56637545 ? 350
	    : orbit>= 56686674 && orbit<= 59525018 ? 400
	    : orbit>= 59574993 && orbit<= 59797815 ? 250
	      : NOVAL_I;
	case 355135:
	  return
	    orbit>= 60256175 && orbit<= 62938846 ? 10
	    : orbit>= 63065350 && orbit<= 65812399 ? 20
	    : orbit>= 65991787 && orbit<= 68710676 ? 30
	    : orbit>= 68889646 && orbit<= 71580864 ? 40
	    : orbit>= 71734812 && orbit<= 74456364 ? 50
	    : orbit>= 74610439 && orbit<= 77351083 ? 60
	    : orbit>= 77529784 && orbit<= 80228062 ? 70
	    : orbit>= 80279887 && orbit<= 83122171 ? 80
	    : orbit>= 83302626 && orbit<= 86002915 ? 90
	    : orbit>= 86157586 && orbit<= 88876708 ? 100
	    : orbit>= 89084382 && orbit<= 91769094 ? 150
	    : orbit>= 91821345 && orbit<= 94662176 ? 200
	    : orbit>= 94894817 && orbit<= 97804936 ? 250
	    : orbit>= 97984695 && orbit<= 100679171 ? 300
	    : orbit>= 100731058 && orbit<= 103566025 ? 400
	      : NOVAL_I;
	case 357900:
	  return
	    orbit>= 12664081 && orbit<= 15486907 ? 10
	    : orbit>= 15566369 && orbit<= 18368115 ? 20
	    : orbit>= 18420230 && orbit<= 21247176 ? 30
	    : orbit>= 21378632 && orbit<= 24147295 ? 40
	    : orbit>= 24199731 && orbit<= 27025711 ? 50
	    : orbit>= 27077499 && orbit<= 29909218 ? 60
	    : orbit>= 29960548 && orbit<= 32790919 ? 70
	    : orbit>= 32843486 && orbit<= 35673003 ? 80
	    : orbit>= 35778744 && orbit<= 38555720 ? 90
	    : orbit>= 38608540 && orbit<= 41438736 ? 100
	    : orbit>= 41570546 && orbit<= 44324553 ? 125
	    : orbit>= 44455195 && orbit<= 47211734 ? 150
	    : orbit>= 47342579 && orbit<= 50093965 ? 175
	    : orbit>= 50251205 && orbit<= 52977181 ? 200
	    : orbit>= 53030010 && orbit<= 55863627 ? 225
	    : orbit>= 55916697 && orbit<= 58740975 ? 250
	    : orbit>= 58793298 && orbit<= 61624510 ? 275
	    : orbit>= 61784559 && orbit<= 64513818 ? 300
	    : orbit>= 64698513 && orbit<= 67393943 ? 350
	    : orbit>= 67551617 && orbit<= 70262612 ? 400
	    : orbit>= 70315602 && orbit<= 73150278 ? 250
	      : NOVAL_I;
	case 359571:
	  return
	    orbit>= 1598793 && orbit<= 4462108 ? 10
	    : orbit>= 4511395 && orbit<= 7350069 ? 20
	    : orbit>= 7399774 && orbit<= 10241564 ? 30
	    : orbit>= 10365345 && orbit<= 13132585 ? 40
	    : orbit>= 13255825 && orbit<= 15995781 ? 60
	    : orbit>= 16121215 && orbit<= 18899097 ? 80
	    : orbit>= 19022211 && orbit<= 21775984 ? 100
	    : orbit>= 21826416 && orbit<= 24672183 ? 120
	    : orbit>= 24722328 && orbit<= 27552047 ? 140
	    : orbit>= 27601834 && orbit<= 30433146 ? 160
	    : orbit>= 30557652 && orbit<= 33309141 ? 180
	    : orbit>= 33432366 && orbit<= 36193558 ? 200
	    : orbit>= 36243029 && orbit<= 39068178 ? 220
	    : orbit>= 39118463 && orbit<= 41969704 ? 240
	      : NOVAL_I;
	case 359575:
	  return
	    orbit>= 629737 && orbit<= 3422063 ? 260
	    : orbit>= 3548475 && orbit<= 6312050 ? 280
	    : orbit>= 6461056 && orbit<= 9196810 ? 300
	    : orbit>= 9348596 && orbit<= 12066809 ? 325
	    : orbit>= 12216331 && orbit<= 14954951 ? 350
	    : orbit>= 15107686 && orbit<= 17849142 ? 400
	    : orbit>= 18099677 && orbit<= 20986877 ? 250
	      : NOVAL_I;
	case 360295:
	  return
	    orbit>= 250123817 && orbit<= 252997151 ? 10
	    : orbit>= 253130344 && orbit<= 255876427 ? 20
	    : orbit>= 256037677 && orbit<= 258760820 ? 30
	    : orbit>= 258895922 && orbit<= 261640771 ? 40
	    : orbit>= 261775735 && orbit<= 264513826 ? 60
	    : orbit>= 264621139 && orbit<= 267397855 ? 80
	    : orbit>= 267530956 && orbit<= 270282609 ? 100
	    : orbit>= 270417033 && orbit<= 273166939 ? 120
	    : orbit>= 273326940 && orbit<= 276051811 ? 140
	    : orbit>= 276185803 && orbit<= 278938988 ? 160
	    : orbit>= 279075317 && orbit<= 281832159 ? 180
	    : orbit>= 281965899 && orbit<= 284714222 ? 200
	    : orbit>= 284848582 && orbit<= 287602289 ? 220
	    : orbit>= 287735524 && orbit<= 290484727 ? 240
	    : orbit>= 290620075 && orbit<= 293353433 ? 260
	    : orbit>= 293460265 && orbit<= 296246415 ? 280
	    : orbit>= 296379312 && orbit<= 299138425 ? 300
	    : orbit>= 299301164 && orbit<= 302001233 ? 325
	    : orbit>= 302137056 && orbit<= 304881966 ? 350
	    : orbit>= 305042514 && orbit<= 307762219 ? 400
	    : orbit>= 308029792 && orbit<= 310911240 ? 250
	      : NOVAL_I;
	case 360796:
	  return
	    orbit>= 75646765 && orbit<= 78396600 ? 10
	    : orbit>= 78507985 && orbit<= 81277003 ? 20
	    : orbit>= 81385464 && orbit<= 84160318 ? 30
	    : orbit>= 84297227 && orbit<= 87050646 ? 40
	    : orbit>= 87186625 && orbit<= 89935156 ? 60
	    : orbit>= 90098419 && orbit<= 92830631 ? 80
	    : orbit>= 92967681 && orbit<= 95710970 ? 100
	    : orbit>= 95821281 && orbit<= 98586494 ? 120
	    : orbit>= 98719921 && orbit<= 101456347 ? 140
	    : orbit>= 101593245 && orbit<= 104351070 ? 160
	    : orbit>= 104512707 && orbit<= 107226276 ? 180
	    : orbit>= 107333521 && orbit<= 110118658 ? 200
	    : orbit>= 110228652 && orbit<= 112993580 ? 220
	    : orbit>= 113104333 && orbit<= 115892159 ? 240
	    : orbit>= 116055955 && orbit<= 118776123 ? 260
	    : orbit>= 118912464 && orbit<= 121643055 ? 280
	    : orbit>= 121808435 && orbit<= 124535570 ? 300
	    : orbit>= 124698262 && orbit<= 127419378 ? 325
	    : orbit>= 127525948 && orbit<= 130294767 ? 350
	    : orbit>= 130432704 && orbit<= 133198582 ? 400
	    : orbit>= 133472480 && orbit<= 136338129 ? 250
	      : NOVAL_I;
	case 361223:
	  return
	    orbit>= 38087387 && orbit<= 40918583 ? 10
	    : orbit>= 41051543 && orbit<= 43792557 ? 20
	    : orbit>= 43899276 && orbit<= 46692751 ? 30
	    : orbit>= 46801557 && orbit<= 49551982 ? 40
	    : orbit>= 49712638 && orbit<= 52437174 ? 60
	    : orbit>= 52517765 && orbit<= 55318121 ? 80
	    : orbit>= 55451536 && orbit<= 58222205 ? 100
	    : orbit>= 58329114 && orbit<= 61107309 ? 120
	    : orbit>= 61241257 && orbit<= 63972397 ? 140
	    : orbit>= 64107430 && orbit<= 66869015 ? 160
	    : orbit>= 67003578 && orbit<= 69740800 ? 180
	    : orbit>= 69877021 && orbit<= 72642959 ? 200
	    : orbit>= 72778246 && orbit<= 75522331 ? 220
	    : orbit>= 75658158 && orbit<= 78396727 ? 240
	    : orbit>= 78533017 && orbit<= 81279217 ? 260
	    : orbit>= 81441635 && orbit<= 84154693 ? 280
	    : orbit>= 84317433 && orbit<= 87037091 ? 300
	    : orbit>= 87173373 && orbit<= 89928279 ? 325
	    : orbit>= 90038254 && orbit<= 92820920 ? 350
	    : orbit>= 92984498 && orbit<= 95713653 ? 400
	    : orbit>= 95988057 && orbit<= 98845309 ? 250
	      : NOVAL_I;
	case 361475:
	  return
	    orbit>= 222110333 && orbit<= 224939149 ? 10
	    : orbit>= 225072545 && orbit<= 227809699 ? 20
	    : orbit>= 227970409 && orbit<= 230699599 ? 30
	    : orbit>= 230779861 && orbit<= 233595778 ? 40
	    : orbit>= 233703427 && orbit<= 236465704 ? 60
	    : orbit>= 236598359 && orbit<= 239360686 ? 80
	    : orbit>= 239493494 && orbit<= 242245761 ? 100
	    : orbit>= 242405079 && orbit<= 245128059 ? 120
	    : orbit>= 245285736 && orbit<= 248003579 ? 140
	    : orbit>= 248163112 && orbit<= 250881259 ? 160
	    : orbit>= 250985797 && orbit<= 253786244 ? 180
	    : orbit>= 253891737 && orbit<= 256655416 ? 200
	    : orbit>= 256787880 && orbit<= 259547532 ? 220
	    : orbit>= 259680999 && orbit<= 262420314 ? 240
	    : orbit>= 262551948 && orbit<= 265298416 ? 260
	    : orbit>= 265428875 && orbit<= 268195013 ? 280
	    : orbit>= 268380359 && orbit<= 271084430 ? 300
	    : orbit>= 271243461 && orbit<= 273967363 ? 325
	    : orbit>= 274125527 && orbit<= 276846908 ? 350
	    : orbit>= 277001884 && orbit<= 279718446 ? 400
	    : orbit>= 279980916 && orbit<= 282880383 ? 250
	      : NOVAL_I;
	case 361890:
	  return
	    orbit>= 3963493 && orbit<= 9459187 ? 10
	    : orbit>= 9564419 && orbit<= 14968438 ? 20
	    : orbit>= 15099769 && orbit<= 20474451 ? 30
	    : orbit>= 20579259 && orbit<= 25958161 ? 40
	    : orbit>= 26114369 && orbit<= 31484064 ? 60
	    : orbit>= 31641788 && orbit<= 36981269 ? 80
	    : orbit>= 37111781 && orbit<= 42498466 ? 100
	    : orbit>= 42630885 && orbit<= 47984783 ? 120
	    : orbit>= 48115296 && orbit<= 53504821 ? 140
	    : orbit>= 53660650 && orbit<= 59011469 ? 160
	    : orbit>= 59143042 && orbit<= 64514429 ? 180
	    : orbit>= 64673894 && orbit<= 70005563 ? 200
	    : orbit>= 70138844 && orbit<= 75510829 ? 220
	    : orbit>= 75642832 && orbit<= 81009063 ? 240
	    : orbit>= 81141608 && orbit<= 86536110 ? 260
	    : orbit>= 86643866 && orbit<= 92044401 ? 280
	    : orbit>= 92180485 && orbit<= 97528310 ? 300
	    : orbit>= 97636672 && orbit<= 103045464 ? 325
	    : orbit>= 103180825 && orbit<= 108550068 ? 350
	    : orbit>= 108712296 && orbit<= 114044835 ? 400
	    : orbit>= 114313672 && orbit<= 119810887 ? 250
	      : NOVAL_I;
	case 362617:
	  return
	    orbit>= 1675207 && orbit<= 4482307 ? 10
	    : orbit>= 4589516 && orbit<= 7345565 ? 25
	    : orbit>= 7503560 && orbit<= 10251143 ? 50
	    : orbit>= 10383641 && orbit<= 13118256 ? 75
	    : orbit>= 13251150 && orbit<= 16012285 ? 100
	    : orbit>= 16092002 && orbit<= 18904691 ? 120
	    : orbit>= 19064644 && orbit<= 21780375 ? 140
	    : orbit>= 21915491 && orbit<= 24647683 ? 160
	    : orbit>= 24781469 && orbit<= 27544216 ? 180
	    : orbit>= 27701105 && orbit<= 30425847 ? 200
	    : orbit>= 30531014 && orbit<= 33309354 ? 220
	    : orbit>= 33440550 && orbit<= 36205433 ? 240
	    : orbit>= 36311560 && orbit<= 39080353 ? 260
	    : orbit>= 39211611 && orbit<= 41966680 ? 280
	    : orbit>= 42123525 && orbit<= 44832214 ? 300
	    : orbit>= 44963600 && orbit<= 47738950 ? 320
	    : orbit>= 47870274 && orbit<= 50611790 ? 340
	    : orbit>= 50717573 && orbit<= 53483918 ? 360
	    : orbit>= 53643704 && orbit<= 56368187 ? 380
	    : orbit>= 56499465 && orbit<= 59266913 ? 400
	    : orbit>= 59529205 && orbit<= 62409575 ? 250
	      : NOVAL_I;
	case 365775:
	  return
	    orbit>= 11674141 && orbit<= 14429083 ? 200
	    : orbit>= 14589392 && orbit<= 17324633 ? 220
	    : orbit>= 17510902 && orbit<= 20196585 ? 240
	    : orbit>= 20383796 && orbit<= 23092362 ? 260
	    : orbit>= 23253989 && orbit<= 25982133 ? 280
	    : orbit>= 26197706 && orbit<= 29103790 ? 300
	    : orbit>= 29319343 && orbit<= 32255384 ? 320
	    : orbit>= 32444673 && orbit<= 35145650 ? 340
	    : orbit>= 35334294 && orbit<= 38017264 ? 360
	    : orbit>= 38180097 && orbit<= 40924604 ? 380
	    : orbit>= 41087244 && orbit<= 43808026 ? 400
	    : orbit>= 44514502 && orbit<= 47198988 ? 10
	    : orbit>= 47361806 && orbit<= 50091213 ? 25
	    : orbit>= 50255317 && orbit<= 52961410 ? 50
	    : orbit>= 53152818 && orbit<= 55865611 ? 75
	    : orbit>= 56057509 && orbit<= 59001403 ? 100
	    : orbit>= 59192755 && orbit<= 61877774 ? 120
	    : orbit>= 62043689 && orbit<= 64774124 ? 140
	    : orbit>= 64884831 && orbit<= 67653732 ? 160
	    : orbit>= 67791500 && orbit<= 70538399 ? 180
	    : orbit>= 70818655 && orbit<= 73668482 ? 250
	      : NOVAL_I;
	case 366451:
	  return
	    orbit>= 58699848 && orbit<= 61609564 ? 10
	    : orbit>= 61855050 && orbit<= 64768771 ? 40
	    : orbit>= 65015489 && orbit<= 67906385 ? 80
	    : orbit>= 68180112 && orbit<= 71046519 ? 120
	    : orbit>= 71291153 && orbit<= 74213289 ? 160
	    : orbit>= 74483037 && orbit<= 77340829 ? 200
	    : orbit>= 77582257 && orbit<= 80500459 ? 220
	    : orbit>= 80768423 && orbit<= 83635242 ? 240
	    : orbit>= 83903748 && orbit<= 86778734 ? 260
	    : orbit>= 86994641 && orbit<= 89925879 ? 280
	    : orbit>= 90166981 && orbit<= 93066380 ? 300
	    : orbit>= 93280876 && orbit<= 95967751 ? 330
	    : orbit>= 96237367 && orbit<= 99108516 ? 360
	    : orbit>= 99379543 && orbit<= 102262964 ? 400
	    : orbit>= 102641354 && orbit<= 105413326 ? 250
	      : NOVAL_I;
	case 367262:
	  return
	    orbit>= 7099870 && orbit<= 9973319 ? 10
	    : orbit>= 10169046 && orbit<= 12852101 ? 25
	    : orbit>= 13040868 && orbit<= 15739671 ? 50
	    : orbit>= 15959748 && orbit<= 18892548 ? 75
	    : orbit>= 19083998 && orbit<= 21766757 ? 100
	    : orbit>= 21931959 && orbit<= 24652329 ? 120
	    : orbit>= 24817938 && orbit<= 27542550 ? 140
	    : orbit>= 27734239 && orbit<= 30417342 ? 160
	    : orbit>= 30608624 && orbit<= 33313703 ? 180
	    : orbit>= 33505478 && orbit<= 36453885 ? 200
	    : orbit>= 36587559 && orbit<= 39346964 ? 220
	    : orbit>= 39511702 && orbit<= 42230281 ? 240
	    : orbit>= 42366690 && orbit<= 45102527 ? 260
	    : orbit>= 45240256 && orbit<= 47984863 ? 280
	    : orbit>= 48176143 && orbit<= 50887425 ? 300
	    : orbit>= 51050647 && orbit<= 53762229 ? 320
	    : orbit>= 53954281 && orbit<= 56911774 ? 340
	    : orbit>= 57075795 && orbit<= 59793547 ? 360
	    : orbit>= 59929631 && orbit<= 62659588 ? 380
	    : orbit>= 62878057 && orbit<= 65827762 ? 400
	    : orbit>= 66128316 && orbit<= 68970973 ? 250
	      : NOVAL_I;
	case 367691:
	  return
	    orbit>= 38093805 && orbit<= 40915552 ? 10
	    : orbit>= 41110913 && orbit<= 44047646 ? 25
	    : orbit>= 44186753 && orbit<= 46929565 ? 50
	    : orbit>= 47125589 && orbit<= 49838059 ? 75
	    : orbit>= 50003212 && orbit<= 52705357 ? 100
	    : orbit>= 52896569 && orbit<= 55580803 ? 120
	      : NOVAL_I;
	case 367693:
	  return
	    orbit>= 1098110 && orbit<= 3945219 ? 120
	    : orbit>= 4135366 && orbit<= 6829305 ? 140
	      : NOVAL_I;
	case 367696:
	  return
	    orbit>= 3506414 && orbit<= 6308118 ? 160
	    : orbit>= 6506342 && orbit<= 9468137 ? 180
	    : orbit>= 9637017 && orbit<= 12338491 ? 200
	    : orbit>= 12533908 && orbit<= 15483844 ? 220
	    : orbit>= 15653641 && orbit<= 18355679 ? 240
	    : orbit>= 18555832 && orbit<= 21245305 ? 260
	    : orbit>= 21385589 && orbit<= 24127787 ? 280
	    : orbit>= 24298863 && orbit<= 27024565 ? 300
	    : orbit>= 27136462 && orbit<= 29892124 ? 320
	    : orbit>= 30062691 && orbit<= 32789318 ? 340
	    : orbit>= 32929346 && orbit<= 35656656 ? 360
	    : orbit>= 35826537 && orbit<= 38555859 ? 380
	    : orbit>= 38755411 && orbit<= 41712687 ? 400
	    : orbit>= 42025627 && orbit<= 44837160 ? 250
	      : NOVAL_I;
	case 368318:
	  return
	    orbit>= 38680055 && orbit<= 41436877 ? 10
	    : orbit>= 41571843 && orbit<= 44311348 ? 25
	    : orbit>= 44502309 && orbit<= 47205698 ? 50
	    : orbit>= 47421959 && orbit<= 50347521 ? 75
	    : orbit>= 50508280 && orbit<= 53224276 ? 100
	    : orbit>= 53385408 && orbit<= 56124453 ? 120
	    : orbit>= 56286132 && orbit<= 58997544 ? 140
	    : orbit>= 59161176 && orbit<= 61882440 ? 160
	    : orbit>= 62071686 && orbit<= 64759415 ? 180
	    : orbit>= 64977629 && orbit<= 67907945 ? 200
	    : orbit>= 68097540 && orbit<= 70786060 ? 220
	    : orbit>= 70948149 && orbit<= 73673465 ? 240
	    : orbit>= 73863541 && orbit<= 76551518 ? 260
	    : orbit>= 76713898 && orbit<= 79436967 ? 280
	    : orbit>= 79601241 && orbit<= 82331790 ? 300
	      : NOVAL_I;
	case 368320:
	  return
	    orbit>= 7296034 && orbit<= 10245784 ? 320
	    : orbit>= 10436831 && orbit<= 13120570 ? 340
	    : orbit>= 13256620 && orbit<= 16014083 ? 360
	    : orbit>= 16205744 && orbit<= 19147750 ? 380
	    : orbit>= 19340819 && orbit<= 22029462 ? 400
	    : orbit>= 22359114 && orbit<= 25197863 ? 250
	      : NOVAL_I;
	case 368636:
	  return
	    orbit>= 33385564 && orbit<= 36207914 ? 10
	    : orbit>= 36371515 && orbit<= 39085596 ? 25
	    : orbit>= 39249532 && orbit<= 41952787 ? 50
	    : orbit>= 42143811 && orbit<= 44832462 ? 75
	    : orbit>= 44995928 && orbit<= 47737091 ? 100
	    : orbit>= 47899342 && orbit<= 50615477 ? 120
	    : orbit>= 50751769 && orbit<= 53490218 ? 140
	    : orbit>= 53653665 && orbit<= 56365742 ? 160
	    : orbit>= 56528473 && orbit<= 59270226 ? 180
	    : orbit>= 59461047 && orbit<= 62411805 ? 200
	    : orbit>= 62548295 && orbit<= 65290140 ? 220
	    : orbit>= 65425227 && orbit<= 68169459 ? 240
	    : orbit>= 68331785 && orbit<= 71070912 ? 260
	    : orbit>= 71234301 && orbit<= 73930658 ? 280
	    : orbit>= 74121783 && orbit<= 76837685 ? 300
	    : orbit>= 76973011 && orbit<= 79706299 ? 320
	    : orbit>= 79868802 && orbit<= 82607141 ? 340
	    : orbit>= 82768510 && orbit<= 85484677 ? 360
	    : orbit>= 85646605 && orbit<= 88362620 ? 380
	    : orbit>= 88525784 && orbit<= 91244037 ? 400
	    : orbit>= 91540489 && orbit<= 94394769 ? 250
	      : NOVAL_I;
	case 370169:
	  return
	    orbit>= 40342105 && orbit<= 43280163 ? 10
	    : orbit>= 43446024 && orbit<= 46163964 ? 25
	    : orbit>= 46360986 && orbit<= 49310460 ? 50
	    : orbit>= 49475797 && orbit<= 52185788 ? 75
	    : orbit>= 52352339 && orbit<= 55071756 ? 100
	    : orbit>= 55239247 && orbit<= 57948217 ? 120
	    : orbit>= 58115174 && orbit<= 60824770 ? 140
	    : orbit>= 60992420 && orbit<= 63706944 ? 160
	    : orbit>= 63845307 && orbit<= 66614001 ? 180
	    : orbit>= 66782084 && orbit<= 69473855 ? 200
	    : orbit>= 69641850 && orbit<= 72375108 ? 220
	    : orbit>= 72571092 && orbit<= 75528087 ? 240
	    : orbit>= 75722880 && orbit<= 78653907 ? 260
	    : orbit>= 78849747 && orbit<= 81532531 ? 280
	    : orbit>= 81672588 && orbit<= 84442221 ? 300
	    : orbit>= 84637613 && orbit<= 87569623 ? 320
	    : orbit>= 87737354 && orbit<= 90457916 ? 340
	    : orbit>= 90623611 && orbit<= 93355955 ? 360
	    : orbit>= 93522339 && orbit<= 96229970 ? 380
	    : orbit>= 96368015 && orbit<= 99098219 ? 400
	    : orbit>= 99434925 && orbit<= 102250856 ? 250
	      : NOVAL_I;
	case 370772:
	  return
	    orbit>= 52470445 && orbit<= 55333639 ? 10
	    : orbit>= 55472333 && orbit<= 58213155 ? 25
	    : orbit>= 58377241 && orbit<= 61089932 ? 50
	    : orbit>= 61256076 && orbit<= 63986325 ? 75
	    : orbit>= 64151875 && orbit<= 66856984 ? 100
	    : orbit>= 67024241 && orbit<= 69745556 ? 120
	    : orbit>= 69882848 && orbit<= 72642643 ? 140
	    : orbit>= 72780104 && orbit<= 75513072 ? 160
	    : orbit>= 75705636 && orbit<= 78389735 ? 180
	    : orbit>= 78527331 && orbit<= 81287919 ? 200
	    : orbit>= 81481429 && orbit<= 84417782 ? 220
	    : orbit>= 84582153 && orbit<= 87299914 ? 240
	    : orbit>= 87493915 && orbit<= 90188367 ? 260
	    : orbit>= 90382679 && orbit<= 93075344 ? 280
	    : orbit>= 93240739 && orbit<= 95958111 ? 300
	    : orbit>= 96127506 && orbit<= 98855902 ? 320
	    : orbit>= 98995097 && orbit<= 101722000 ? 340
	    : orbit>= 101919990 && orbit<= 104619178 ? 360
	    : orbit>= 104813521 && orbit<= 107747043 ? 380
	    : orbit>= 107916236 && orbit<= 110656907 ? 400
	    : orbit>= 110966804 && orbit<= 113797510 ? 250
	      : NOVAL_I;
	case 372597:
	  return
	    orbit>= 7903752 && orbit<= 13394769 ? 10
	    : orbit>= 13557899 && orbit<= 18905971 ? 25
	    : orbit>= 19067942 && orbit<= 24398996 ? 50
	    : orbit>= 24559026 && orbit<= 29910640 ? 75
	    : orbit>= 30098947 && orbit<= 35673648 ? 100
	    : orbit>= 35834767 && orbit<= 41184922 ? 120
	    : orbit>= 41347438 && orbit<= 46668343 ? 140
	    : orbit>= 46855827 && orbit<= 52173231 ? 160
	      : NOVAL_I;
	case 372598:
	  return
	    orbit>= 2746350 && orbit<= 8139349 ? 180
	    : orbit>= 8273753 && orbit<= 13650923 ? 200
	    : orbit>= 15111512 && orbit<= 20472285 ? 220
	      : NOVAL_I;
	case 372601:
	  return
	    orbit>= 490474 && orbit<= 6042138 ? 240
	    : orbit>= 6176244 && orbit<= 11549929 ? 260
	      : NOVAL_I;
	case 372602:
	  return
	    orbit>= 361535 && orbit<= 5785597 ? 280
	    : orbit>= 5948983 && orbit<= 11296711 ? 300
	    : orbit>= 11459733 && orbit<= 16786650 ? 320
	    : orbit>= 16923122 && orbit<= 22312993 ? 340
	    : orbit>= 22477745 && orbit<= 27808336 ? 360
	    : orbit>= 28000123 && orbit<= 33564939 ? 380
	    : orbit>= 33759233 && orbit<= 39083698 ? 400
	    : orbit>= 39385415 && orbit<= 44853027 ? 250
	      : NOVAL_I;
	case 375697:
	  return
	    orbit>= 14181054 && orbit<= 17056109 ? 10
	    : orbit>= 17275876 && orbit<= 20193293 ? 50
	    : orbit>= 20388031 && orbit<= 23095530 ? 100
	    : orbit>= 23289806 && orbit<= 26236248 ? 140
	    : orbit>= 26403276 && orbit<= 29104372 ? 180
	    : orbit>= 29271858 && orbit<= 32013840 ? 220
	    : orbit>= 32126302 && orbit<= 34880439 ? 240
	    : orbit>= 35047818 && orbit<= 37760914 ? 260
	    : orbit>= 37929290 && orbit<= 40658642 ? 280
	    : orbit>= 40852199 && orbit<= 43809979 ? 300
	    : orbit>= 43977324 && orbit<= 46666746 ? 320
	    : orbit>= 46832244 && orbit<= 49562209 ? 340
	    : orbit>= 49759108 && orbit<= 52723019 ? 360
	    : orbit>= 52860920 && orbit<= 55597269 ? 380
	    : orbit>= 55790859 && orbit<= 58751634 ? 400
	    : orbit>= 59029356 && orbit<= 61896178 ? 250
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_l3
  
  // Define Layer 4 Scans below
  int hv_l4(int run, int ls, int orbit) {
    switch (run) {
    case 301086:
      return
      	ls  >= 44 && ls<= 72 ?  100
        : orbit>= 72564229 && orbit<= 74538859 ? 20
        : orbit>= 74806268 && orbit<= 76837010 ? 40
        : orbit>= 77124490 && orbit<= 79431314 ? 60
        : orbit>= 79633779 && orbit<= 81639444 ? 80
	  : NOVAL_I;
    case 301912:
      return
        orbit>= 22840887 && orbit<= 24889630 ? 200
	  : NOVAL_I;
    case 303795:
      return
        orbit>= 94873693 && orbit<= 96446818 ? 50
        : orbit>= 96607690 && orbit<= 98148974 ? 100
        : orbit>= 98359529 && orbit<= 99507810 ? 150
        : orbit>= 99719028 && orbit<= 101739533 ? 250
        : orbit>= 51050070 && orbit<= 52540652 ? 200
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 200
        : orbit>= 58596169 && orbit<= 59922216 ? 100
        : orbit>= 60115178 && orbit<= 61470624 ? 150
        : orbit>= 61691015 && orbit<= 63023819 ? 250
        : orbit>= 63217766 && orbit<= 64543879 ? 300
        : orbit>= 67303535 && orbit<= 68633680 ? 200
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 130381323 && orbit<= 132934980 ? 5
	    : orbit>= 133068722 && orbit<= 135540254 ? 10
	    : orbit>= 135674536 && orbit<= 138174246 ? 15
	    : orbit>= 138309330 && orbit<= 140800465 ? 20
	    : orbit>= 140971902 && orbit<= 143422950 ? 25
	    : orbit>= 143593020 && orbit<= 146031871 ? 30
	    : orbit>= 146174267 && orbit<= 148653151 ? 40
	    : orbit>= 148840032 && orbit<= 151285917 ? 50
	    : orbit>= 151418525 && orbit<= 153884225 ? 60
	    : orbit>= 154043043 && orbit<= 156531499 ? 80
	    : orbit>= 156743742 && orbit<= 159400350 ? 100
	    : orbit>= 159585302 && orbit<= 162013799 ? 150
	    : orbit>= 162225719 && orbit<= 164645494 ? 200
	    : orbit>= 164779000 && orbit<= 167279487 ? 250
	    : orbit>= 167492317 && orbit<= 170146283 ? 350
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 36637269 && orbit<= 39091295 ? 125
	    : orbit>= 39304209 && orbit<= 41964093 ? 175
	    : orbit>= 42177100 && orbit<= 44594783 ? 300
	    : orbit>= 44840392 && orbit<= 47458916 ? 400
	    : orbit>= 73868092 && orbit<= 76298442 ? 70
	    : orbit>= 76458346 && orbit<= 78926316 ? 90
	    : orbit>= 79194684 && orbit<= 81795818 ? 225
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 5
	    : orbit>= 41825841 && orbit<= 44322177 ? 10
	    : orbit>= 44480767 && orbit<= 46948744 ? 15
	    : orbit>= 47135051 && orbit<= 49565502 ? 20
	    : orbit>= 49728746 && orbit<= 52187784 ? 25
	    : orbit>= 52322198 && orbit<= 54804994 ? 30
	    : orbit>= 54969957 && orbit<= 57440386 ? 40
	    : orbit>= 57553203 && orbit<= 60043347 ? 50
	    : orbit>= 60176652 && orbit<= 62671231 ? 60
	    : orbit>= 62830841 && orbit<= 65299490 ? 80
	    : orbit>= 65460761 && orbit<= 67931853 ? 100
	    : orbit>= 68119359 && orbit<= 70522726 ? 125
	    : orbit>= 70683404 && orbit<= 73153756 ? 150
	    : orbit>= 73311203 && orbit<= 75775055 ? 175
	    : orbit>= 75933126 && orbit<= 78397728 ? 200
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
	case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 5
	    : orbit>= 27391881 && orbit<= 29910318 ? 10
	    : orbit>= 30048261 && orbit<= 32528621 ? 15
	    : orbit>= 32692410 && orbit<= 35184550 ? 20
	    : orbit>= 35347550 && orbit<= 37766749 ? 25
	    : orbit>= 37964504 && orbit<= 40393240 ? 30
	    : orbit>= 40564372 && orbit<= 43001725 ? 40
	    : orbit>= 43111459 && orbit<= 45637231 ? 50
	    : orbit>= 45800722 && orbit<= 48263040 ? 60
	    : orbit>= 48454863 && orbit<= 50886070 ? 80
	    : orbit>= 51052187 && orbit<= 53510050 ? 100
	    : orbit>= 53672834 && orbit<= 56130806 ? 125
	    : orbit>= 56294595 && orbit<= 58752882 ? 150
	    : orbit>= 58889269 && orbit<= 61372970 ? 175
	    : orbit>= 61571382 && orbit<= 63995005 ? 200
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 200
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 5
	    : orbit>= 47613845 && orbit<= 50105260 ? 10
	    : orbit>= 50188211 && orbit<= 52709208 ? 15
	    : orbit>= 52895444 && orbit<= 55339608 ? 20
	    : orbit>= 55500867 && orbit<= 57952349 ? 25
	    : orbit>= 58141198 && orbit<= 60574900 ? 30
	    : orbit>= 60717816 && orbit<= 63221110 ? 40
	    : orbit>= 63329551 && orbit<= 65809487 ? 50
	    : orbit>= 65969746 && orbit<= 68435462 ? 60
	    : orbit>= 68575779 && orbit<= 71053332 ? 80
	    : orbit>= 71220080 && orbit<= 73688468 ? 100
	    : orbit>= 73877439 && orbit<= 76301206 ? 125
	    : orbit>= 76461185 && orbit<= 78925237 ? 150
	    : orbit>= 79058767 && orbit<= 81554007 ? 175
	    : orbit>= 81740951 && orbit<= 84170667 ? 200
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 200
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 5
	    : orbit>= 47854891 && orbit<= 50359955 ? 10
	    : orbit>= 50522239 && orbit<= 52977308 ? 15
	    : orbit>= 53113522 && orbit<= 55616572 ? 20
	    : orbit>= 55755315 && orbit<= 58228213 ? 25
	    : orbit>= 58372274 && orbit<= 60827613 ? 30
	    : orbit>= 60995674 && orbit<= 63463695 ? 40
	    : orbit>= 63631902 && orbit<= 66076490 ? 50
	    : orbit>= 66213020 && orbit<= 68722423 ? 60
	    : orbit>= 68890165 && orbit<= 71333543 ? 80
	    : orbit>= 71498800 && orbit<= 73941265 ? 100
	    : orbit>= 74129851 && orbit<= 76570264 ? 125
	    : orbit>= 76734342 && orbit<= 79189022 ? 150
	    : orbit>= 79329459 && orbit<= 81814529 ? 175
	    : orbit>= 82013635 && orbit<= 84419465 ? 200
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 200
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 5
	    : orbit>= 9566810 && orbit<= 12075322 ? 10
	    : orbit>= 12213121 && orbit<= 14717975 ? 15
	    : orbit>= 14853577 && orbit<= 17316216 ? 20
	    : orbit>= 17503961 && orbit<= 19935530 ? 25
	    : orbit>= 20071439 && orbit<= 22554342 ? 30
	    : orbit>= 22715316 && orbit<= 25193763 ? 40
	    : orbit>= 25355311 && orbit<= 27817230 ? 50
	    : orbit>= 27926532 && orbit<= 30416278 ? 60
	    : orbit>= 30527882 && orbit<= 33049984 ? 80
	    : orbit>= 33212050 && orbit<= 35664191 ? 100
	    : orbit>= 35826282 && orbit<= 38287417 ? 125
	    : orbit>= 38504148 && orbit<= 40914406 ? 150
	    : orbit>= 41077682 && orbit<= 43524088 ? 175
	    : orbit>= 43659205 && orbit<= 46161085 ? 200
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 250
	      : NOVAL_I;
	case 320570:
	  return
	    orbit>= 49778311 && orbit<= 52174583 ? 10
	    : orbit>= 52363057 && orbit<= 54817129 ? 20
	    : orbit>= 55005385 && orbit<= 57427140 ? 30
	    : orbit>= 57562288 && orbit<= 60062002 ? 40
	    : orbit>= 60276000 && orbit<= 62942731 ? 50
	    : orbit>= 63157045 && orbit<= 65820976 ? 60
	    : orbit>= 65955103 && orbit<= 68433339 ? 70
	    : orbit>= 68594223 && orbit<= 71098367 ? 80
	    : orbit>= 71260096 && orbit<= 73691039 ? 90
	    : orbit>= 73852017 && orbit<= 76301806 ? 100
	    : orbit>= 76437069 && orbit<= 78933364 ? 125
	    : orbit>= 79067620 && orbit<= 81537619 ? 150
	    : orbit>= 81697616 && orbit<= 84172962 ? 175
	    : orbit>= 84361974 && orbit<= 86801621 ? 200
	    : orbit>= 86988379 && orbit<= 89411122 ? 250
	    : orbit>= 89598437 && orbit<= 92041736 ? 300
	    : orbit>= 92283598 && orbit<= 94922442 ? 400
	    : orbit>= 95243781 && orbit<= 95431232 ? 250
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 5
	    : orbit>= 4370646 && orbit<= 6835331 ? 10
	    : orbit>= 6998249 && orbit<= 9443899 ? 15
	    : orbit>= 9603408 && orbit<= 12088965 ? 20
	    : orbit>= 12249948 && orbit<= 14691253 ? 25
	    : orbit>= 14824908 && orbit<= 17317702 ? 30
	    : orbit>= 17479610 && orbit<= 19929276 ? 40
	    : orbit>= 20117009 && orbit<= 22560727 ? 50
	    : orbit>= 22748255 && orbit<= 25191626 ? 60
	    : orbit>= 25299297 && orbit<= 27799610 ? 80
	    : orbit>= 27936056 && orbit<= 30437130 ? 100
	    : orbit>= 30629196 && orbit<= 33078612 ? 125
	    : orbit>= 33186971 && orbit<= 35673738 ? 150
	    : orbit>= 35860673 && orbit<= 38283804 ? 175
	    : orbit>= 38417265 && orbit<= 40915199 ? 200
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 250
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 5
	    : orbit>= 63075867 && orbit<= 65549032 ? 10
	    : orbit>= 65683169 && orbit<= 68178385 ? 15
	    : orbit>= 68339788 && orbit<= 70786533 ? 20
	    : orbit>= 70945624 && orbit<= 73405782 ? 25
	    : orbit>= 73539162 && orbit<= 76031847 ? 30
	    : orbit>= 76194593 && orbit<= 78661829 ? 40
	    : orbit>= 78793861 && orbit<= 81294346 ? 50
	    : orbit>= 81402558 && orbit<= 83913027 ? 60
	    : orbit>= 84019032 && orbit<= 86545026 ? 80
	    : orbit>= 86678270 && orbit<= 89173927 ? 100
	    : orbit>= 89360682 && orbit<= 91778781 ? 125
	    : orbit>= 91965880 && orbit<= 94679839 ? 150
	    : orbit>= 94865315 && orbit<= 97286456 ? 175
	    : orbit>= 97472797 && orbit<= 99884436 ? 200
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 250
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 5
	    : orbit>= 58114200 && orbit<= 60588212 ? 10
	    : orbit>= 60724340 && orbit<= 63202264 ? 15
	    : orbit>= 63340322 && orbit<= 65817097 ? 20
	    : orbit>= 65979355 && orbit<= 68425849 ? 25
	    : orbit>= 68561709 && orbit<= 71071128 ? 30
	    : orbit>= 71233215 && orbit<= 73688647 ? 40
	    : orbit>= 73852199 && orbit<= 76310213 ? 50
	    : orbit>= 76473584 && orbit<= 78927087 ? 60
	    : orbit>= 79093199 && orbit<= 81541766 ? 80
	    : orbit>= 81704609 && orbit<= 84163799 ? 100
	    : orbit>= 84355052 && orbit<= 86800517 ? 125
	    : orbit>= 86965497 && orbit<= 89409147 ? 150
	    : orbit>= 89572559 && orbit<= 92042263 ? 175
	    : orbit>= 92204778 && orbit<= 94675917 ? 200
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 250
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 5
	    : orbit>= 43422348 && orbit<= 45881929 ? 10
	    : orbit>= 46018056 && orbit<= 48516945 ? 15
	    : orbit>= 48678223 && orbit<= 51169750 ? 20
	    : orbit>= 51304556 && orbit<= 53771512 ? 25
	    : orbit>= 53932342 && orbit<= 56381384 ? 30
	    : orbit>= 56516448 && orbit<= 59011528 ? 40
	    : orbit>= 59200521 && orbit<= 61617940 ? 50
	    : orbit>= 61753974 && orbit<= 64253057 ? 60
	    : orbit>= 64390607 && orbit<= 66854828 ? 80
	    : orbit>= 67018750 && orbit<= 69485929 ? 100
	    : orbit>= 69648708 && orbit<= 72118854 ? 125
	    : orbit>= 72306340 && orbit<= 74742683 ? 150
	    : orbit>= 74932909 && orbit<= 77350840 ? 175
	    : orbit>= 77510220 && orbit<= 79977923 ? 200
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 250
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 5
	    : orbit>= 52868613 && orbit<= 55321785 ? 10
	    : orbit>= 55462104 && orbit<= 57973413 ? 15
	    : orbit>= 58087326 && orbit<= 60562624 ? 20
	    : orbit>= 60709545 && orbit<= 63210483 ? 25
	    : orbit>= 63359047 && orbit<= 65804852 ? 30
	    : orbit>= 65946954 && orbit<= 68434710 ? 40
	    : orbit>= 68605001 && orbit<= 71096881 ? 50
	    : orbit>= 71238107 && orbit<= 73690920 ? 60
	    : orbit>= 73860855 && orbit<= 76295804 ? 80
	    : orbit>= 76465735 && orbit<= 78930971 ? 100
	    : orbit>= 79102261 && orbit<= 81539075 ? 125
	    : orbit>= 81714638 && orbit<= 84171548 ? 150
	    : orbit>= 84349817 && orbit<= 86788381 ? 175
	    : orbit>= 86964660 && orbit<= 89396615 ? 200
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 250
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
	case 352931:
	  return
	    orbit>= 1968481 && orbit<= 4736017 ? 5
	    : orbit>= 4784461 && orbit<= 7610810 ? 10
	    : orbit>= 7660060 && orbit<= 10511621 ? 15
	    : orbit>= 10562037 && orbit<= 13380721 ? 20
	    : orbit>= 13429646 && orbit<= 16268114 ? 25
	    : orbit>= 16390112 && orbit<= 19147855 ? 30
	    : orbit>= 19272670 && orbit<= 22032839 ? 40
	    : orbit>= 22082824 && orbit<= 24921952 ? 50
	    : orbit>= 25044824 && orbit<= 27805658 ? 60
	    : orbit>= 27855378 && orbit<= 30684689 ? 70
	    : orbit>= 30808993 && orbit<= 33579280 ? 80
	    : orbit>= 33629193 && orbit<= 36467115 ? 90
	    : orbit>= 36613893 && orbit<= 39337659 ? 100
	    : orbit>= 39386937 && orbit<= 42233511 ? 125
	    : orbit>= 42380958 && orbit<= 45108131 ? 150
	    : orbit>= 45157840 && orbit<= 47985532 ? 175
	    : orbit>= 48105844 && orbit<= 50885738 ? 200
	    : orbit>= 50934591 && orbit<= 53747920 ? 250
	    : orbit>= 53917558 && orbit<= 56637545 ? 300
	    : orbit>= 56686674 && orbit<= 59525018 ? 350
	    : orbit>= 59574993 && orbit<= 59797815 ? 250
	      : NOVAL_I;
	case 355135:
	  return
	    orbit>= 104755793 && orbit<= 107485110 ? 5
	    : orbit>= 107614366 && orbit<= 110391607 ? 10
	    : orbit>= 110573192 && orbit<= 113275272 ? 15
	    : orbit>= 113405153 && orbit<= 116158746 ? 20
	    : orbit>= 116287797 && orbit<= 119020007 ? 25
	    : orbit>= 119176310 && orbit<= 121918327 ? 30
	    : orbit>= 122046345 && orbit<= 124807657 ? 40
	    : orbit>= 124938870 && orbit<= 127676820 ? 50
	    : orbit>= 127808113 && orbit<= 130574447 ? 60
	    : orbit>= 130703959 && orbit<= 133445781 ? 80
	    : orbit>= 133575707 && orbit<= 136335379 ? 100
	    : orbit>= 136464965 && orbit<= 139229004 ? 150
	    : orbit>= 139255350 && orbit<= 142101766 ? 200
	    : orbit>= 142285520 && orbit<= 144981374 ? 250
	    : orbit>= 145163017 && orbit<= 147867049 ? 350
	      : NOVAL_I;
	case 357900:
	  return
	    orbit>= 12664081 && orbit<= 15486907 ? 5
	    : orbit>= 15566369 && orbit<= 18368115 ? 10
	    : orbit>= 18420230 && orbit<= 21247176 ? 15
	    : orbit>= 21378632 && orbit<= 24147295 ? 20
	    : orbit>= 24199731 && orbit<= 27025711 ? 25
	    : orbit>= 27077499 && orbit<= 29909218 ? 30
	    : orbit>= 29960548 && orbit<= 32790919 ? 40
	    : orbit>= 32843486 && orbit<= 35673003 ? 50
	    : orbit>= 35778744 && orbit<= 38555720 ? 60
	    : orbit>= 38608540 && orbit<= 41438736 ? 70
	    : orbit>= 41570546 && orbit<= 44324553 ? 80
	    : orbit>= 44455195 && orbit<= 47211734 ? 90
	    : orbit>= 47342579 && orbit<= 50093965 ? 100
	    : orbit>= 50251205 && orbit<= 52977181 ? 125
	    : orbit>= 53030010 && orbit<= 55863627 ? 150
	    : orbit>= 55916697 && orbit<= 58740975 ? 175
	    : orbit>= 58793298 && orbit<= 61624510 ? 200
	    : orbit>= 61784559 && orbit<= 64513818 ? 250
	    : orbit>= 64698513 && orbit<= 67393943 ? 300
	    : orbit>= 67551617 && orbit<= 70262612 ? 350
	    : orbit>= 70315602 && orbit<= 73150278 ? 250
	      : NOVAL_I;
	case 359571:
	  return
	    orbit>= 1598793 && orbit<= 4462108 ? 10
	    : orbit>= 4511395 && orbit<= 7350069 ? 20
	    : orbit>= 7399774 && orbit<= 10241564 ? 30
	    : orbit>= 10365345 && orbit<= 13132585 ? 40
	    : orbit>= 13255825 && orbit<= 15995781 ? 60
	    : orbit>= 16121215 && orbit<= 18899097 ? 80
	    : orbit>= 19022211 && orbit<= 21775984 ? 100
	    : orbit>= 21826416 && orbit<= 24672183 ? 120
	    : orbit>= 24722328 && orbit<= 27552047 ? 140
	    : orbit>= 27601834 && orbit<= 30433146 ? 160
	    : orbit>= 30557652 && orbit<= 33309141 ? 180
	    : orbit>= 33432366 && orbit<= 36193558 ? 200
	    : orbit>= 36243029 && orbit<= 39068178 ? 220
	    : orbit>= 39118463 && orbit<= 41969704 ? 240
	      : NOVAL_I;
	case 359575:
	  return
	    orbit>= 629737 && orbit<= 3422063 ? 260
	    : orbit>= 3548475 && orbit<= 6312050 ? 280
	    : orbit>= 6461056 && orbit<= 9196810 ? 300
	    : orbit>= 9348596 && orbit<= 12066809 ? 325
	    : orbit>= 12216331 && orbit<= 14954951 ? 350
	    : orbit>= 15107686 && orbit<= 17849142 ? 400
	    : orbit>= 18099677 && orbit<= 20986877 ? 250
	      : NOVAL_I;
	case 359998:
	  return
	    orbit>= 104875561 && orbit<= 107755135 ? 10
	    : orbit>= 107913968 && orbit<= 110630494 ? 20
	    : orbit>= 110788251 && orbit<= 113524201 ? 30
	    : orbit>= 113682052 && orbit<= 116420968 ? 40
	    : orbit>= 116550343 && orbit<= 119293351 ? 60
	    : orbit>= 119426118 && orbit<= 122178850 ? 80
	    : orbit>= 122336636 && orbit<= 125069620 ? 100
	    : orbit>= 125226412 && orbit<= 127952275 ? 120
	    : orbit>= 128057808 && orbit<= 130827303 ? 140
	    : orbit>= 130983638 && orbit<= 133718918 ? 160
	    : orbit>= 133823634 && orbit<= 136599596 ? 180
	    : orbit>= 136731343 && orbit<= 139480531 ? 200
	    : orbit>= 139610170 && orbit<= 142361614 ? 220
	    : orbit>= 142518456 && orbit<= 145248303 ? 240
	    : orbit>= 146982775 && orbit<= 149705976 ? 260
	    : orbit>= 149812001 && orbit<= 152574204 ? 280
	    : orbit>= 152707668 && orbit<= 155473411 ? 300
	    : orbit>= 155579472 && orbit<= 158344060 ? 325
	    : orbit>= 158503782 && orbit<= 161231425 ? 350
	    : orbit>= 161392164 && orbit<= 164109895 ? 400
	    : orbit>= 164399038 && orbit<= 167263402 ? 250
	      : NOVAL_I;
	case 360295:
	  return
	    orbit>= 250123817 && orbit<= 252997151 ? 10
	    : orbit>= 253130344 && orbit<= 255876427 ? 20
	    : orbit>= 256037677 && orbit<= 258760820 ? 30
	    : orbit>= 258895922 && orbit<= 261640771 ? 40
	    : orbit>= 261775735 && orbit<= 264513826 ? 60
	    : orbit>= 264621139 && orbit<= 267397855 ? 80
	    : orbit>= 267530956 && orbit<= 270282609 ? 100
	    : orbit>= 270417033 && orbit<= 273166939 ? 120
	    : orbit>= 273326940 && orbit<= 276051811 ? 140
	    : orbit>= 276185803 && orbit<= 278938988 ? 160
	    : orbit>= 279075317 && orbit<= 281832159 ? 180
	    : orbit>= 281965899 && orbit<= 284714222 ? 200
	    : orbit>= 284848582 && orbit<= 287602289 ? 220
	    : orbit>= 287735524 && orbit<= 290484727 ? 240
	    : orbit>= 290620075 && orbit<= 293353433 ? 260
	    : orbit>= 293460265 && orbit<= 296246415 ? 280
	    : orbit>= 296379312 && orbit<= 299138425 ? 300
	    : orbit>= 299301164 && orbit<= 302001233 ? 325
	    : orbit>= 302137056 && orbit<= 304881966 ? 350
	    : orbit>= 305042514 && orbit<= 307762219 ? 400
	    : orbit>= 308029792 && orbit<= 310911240 ? 250
	      : NOVAL_I;
	case 360796:
	  return
	    orbit>= 75646765 && orbit<= 78396600 ? 10
	    : orbit>= 78507985 && orbit<= 81277003 ? 20
	    : orbit>= 81385464 && orbit<= 84160318 ? 30
	    : orbit>= 84297227 && orbit<= 87050646 ? 40
	    : orbit>= 87186625 && orbit<= 89935156 ? 60
	    : orbit>= 90098419 && orbit<= 92830631 ? 80
	    : orbit>= 92967681 && orbit<= 95710970 ? 100
	    : orbit>= 95821281 && orbit<= 98586494 ? 120
	    : orbit>= 98719921 && orbit<= 101456347 ? 140
	    : orbit>= 101593245 && orbit<= 104351070 ? 160
	    : orbit>= 104512707 && orbit<= 107226276 ? 180
	    : orbit>= 107333521 && orbit<= 110118658 ? 200
	    : orbit>= 110228652 && orbit<= 112993580 ? 220
	    : orbit>= 113104333 && orbit<= 115892159 ? 240
	    : orbit>= 116055955 && orbit<= 118776123 ? 260
	    : orbit>= 118912464 && orbit<= 121643055 ? 280
	    : orbit>= 121808435 && orbit<= 124535570 ? 300
	    : orbit>= 124698262 && orbit<= 127419378 ? 325
	    : orbit>= 127525948 && orbit<= 130294767 ? 350
	    : orbit>= 130432704 && orbit<= 133198582 ? 400
	    : orbit>= 133472480 && orbit<= 136338129 ? 250
	      : NOVAL_I;
	case 361223:
	  return
	    orbit>= 38087387 && orbit<= 40918583 ? 10
	    : orbit>= 41051543 && orbit<= 43792557 ? 20
	    : orbit>= 43899276 && orbit<= 46692751 ? 30
	    : orbit>= 46801557 && orbit<= 49551982 ? 40
	    : orbit>= 49712638 && orbit<= 52437174 ? 60
	    : orbit>= 52517765 && orbit<= 55318121 ? 80
	    : orbit>= 55451536 && orbit<= 58222205 ? 100
	    : orbit>= 58329114 && orbit<= 61107309 ? 120
	    : orbit>= 61241257 && orbit<= 63972397 ? 140
	    : orbit>= 64107430 && orbit<= 66869015 ? 160
	    : orbit>= 67003578 && orbit<= 69740800 ? 180
	    : orbit>= 69877021 && orbit<= 72642959 ? 200
	    : orbit>= 72778246 && orbit<= 75522331 ? 220
	    : orbit>= 75658158 && orbit<= 78396727 ? 240
	    : orbit>= 78533017 && orbit<= 81279217 ? 260
	    : orbit>= 81441635 && orbit<= 84154693 ? 280
	    : orbit>= 84317433 && orbit<= 87037091 ? 300
	    : orbit>= 87173373 && orbit<= 89928279 ? 325
	    : orbit>= 90038254 && orbit<= 92820920 ? 350
	    : orbit>= 92984498 && orbit<= 95713653 ? 400
	    : orbit>= 95988057 && orbit<= 98845309 ? 250
	      : NOVAL_I;
	case 361475:
	  return
	    orbit>= 222110333 && orbit<= 224939149 ? 10
	    : orbit>= 225072545 && orbit<= 227809699 ? 20
	    : orbit>= 227970409 && orbit<= 230699599 ? 30
	    : orbit>= 230779861 && orbit<= 233595778 ? 40
	    : orbit>= 233703427 && orbit<= 236465704 ? 60
	    : orbit>= 236598359 && orbit<= 239360686 ? 80
	    : orbit>= 239493494 && orbit<= 242245761 ? 100
	    : orbit>= 242405079 && orbit<= 245128059 ? 120
	    : orbit>= 245285736 && orbit<= 248003579 ? 140
	    : orbit>= 248163112 && orbit<= 250881259 ? 160
	    : orbit>= 250985797 && orbit<= 253786244 ? 180
	    : orbit>= 253891737 && orbit<= 256655416 ? 200
	    : orbit>= 256787880 && orbit<= 259547532 ? 220
	    : orbit>= 259680999 && orbit<= 262420314 ? 240
	    : orbit>= 262551948 && orbit<= 265298416 ? 260
	    : orbit>= 265428875 && orbit<= 268195013 ? 280
	    : orbit>= 268380359 && orbit<= 271084430 ? 300
	    : orbit>= 271243461 && orbit<= 273967363 ? 325
	    : orbit>= 274125527 && orbit<= 276846908 ? 350
	    : orbit>= 277001884 && orbit<= 279718446 ? 400
	    : orbit>= 279980916 && orbit<= 282880383 ? 250
	      : NOVAL_I;
	case 361890:
	  return
	    orbit>= 3963493 && orbit<= 9459187 ? 10
	    : orbit>= 9564419 && orbit<= 14968438 ? 20
	    : orbit>= 15099769 && orbit<= 20474451 ? 30
	    : orbit>= 20579259 && orbit<= 25958161 ? 40
	    : orbit>= 26114369 && orbit<= 31484064 ? 60
	    : orbit>= 31641788 && orbit<= 36981269 ? 80
	    : orbit>= 37111781 && orbit<= 42498466 ? 100
	    : orbit>= 42630885 && orbit<= 47984783 ? 120
	    : orbit>= 48115296 && orbit<= 53504821 ? 140
	    : orbit>= 53660650 && orbit<= 59011469 ? 160
	    : orbit>= 59143042 && orbit<= 64514429 ? 180
	    : orbit>= 64673894 && orbit<= 70005563 ? 200
	    : orbit>= 70138844 && orbit<= 75510829 ? 220
	    : orbit>= 75642832 && orbit<= 81009063 ? 240
	    : orbit>= 81141608 && orbit<= 86536110 ? 260
	    : orbit>= 86643866 && orbit<= 92044401 ? 280
	    : orbit>= 92180485 && orbit<= 97528310 ? 300
	    : orbit>= 97636672 && orbit<= 103045464 ? 325
	    : orbit>= 103180825 && orbit<= 108550068 ? 350
	    : orbit>= 108712296 && orbit<= 114044835 ? 400
	    : orbit>= 114313672 && orbit<= 119810887 ? 250
	      : NOVAL_I;
	case 362617:
	  return
	    orbit>= 1675207 && orbit<= 4482307 ? 10
	    : orbit>= 4589516 && orbit<= 7345565 ? 25
	    : orbit>= 7503560 && orbit<= 10251143 ? 50
	    : orbit>= 10383641 && orbit<= 13118256 ? 75
	    : orbit>= 13251150 && orbit<= 16012285 ? 100
	    : orbit>= 16092002 && orbit<= 18904691 ? 120
	    : orbit>= 19064644 && orbit<= 21780375 ? 140
	    : orbit>= 21915491 && orbit<= 24647683 ? 160
	    : orbit>= 24781469 && orbit<= 27544216 ? 180
	    : orbit>= 27701105 && orbit<= 30425847 ? 200
	    : orbit>= 30531014 && orbit<= 33309354 ? 220
	    : orbit>= 33440550 && orbit<= 36205433 ? 240
	    : orbit>= 36311560 && orbit<= 39080353 ? 260
	    : orbit>= 39211611 && orbit<= 41966680 ? 280
	    : orbit>= 42123525 && orbit<= 44832214 ? 300
	    : orbit>= 44963600 && orbit<= 47738950 ? 320
	    : orbit>= 47870274 && orbit<= 50611790 ? 340
	    : orbit>= 50717573 && orbit<= 53483918 ? 360
	    : orbit>= 53643704 && orbit<= 56368187 ? 380
	    : orbit>= 56499465 && orbit<= 59266913 ? 400
	    : orbit>= 59529205 && orbit<= 62409575 ? 250
	      : NOVAL_I;
	case 365775:
	  return
	    orbit>= 11674141 && orbit<= 14429083 ? 200
	    : orbit>= 14589392 && orbit<= 17324633 ? 220
	    : orbit>= 17510902 && orbit<= 20196585 ? 240
	    : orbit>= 20383796 && orbit<= 23092362 ? 260
	    : orbit>= 23253989 && orbit<= 25982133 ? 280
	    : orbit>= 26197706 && orbit<= 29103790 ? 300
	    : orbit>= 29319343 && orbit<= 32255384 ? 320
	    : orbit>= 32444673 && orbit<= 35145650 ? 340
	    : orbit>= 35334294 && orbit<= 38017264 ? 360
	    : orbit>= 38180097 && orbit<= 40924604 ? 380
	    : orbit>= 41087244 && orbit<= 43808026 ? 400
	    : orbit>= 44514502 && orbit<= 47198988 ? 10
	    : orbit>= 47361806 && orbit<= 50091213 ? 25
	    : orbit>= 50255317 && orbit<= 52961410 ? 50
	    : orbit>= 53152818 && orbit<= 55865611 ? 75
	    : orbit>= 56057509 && orbit<= 59001403 ? 100
	    : orbit>= 59192755 && orbit<= 61877774 ? 120
	    : orbit>= 62043689 && orbit<= 64774124 ? 140
	    : orbit>= 64884831 && orbit<= 67653732 ? 160
	    : orbit>= 67791500 && orbit<= 70538399 ? 180
	    : orbit>= 70818655 && orbit<= 73668482 ? 250
	      : NOVAL_I;
	case 366451:
	  return
	    orbit>= 105899907 && orbit<= 108812288 ? 10
	    : orbit>= 109057182 && orbit<= 111946094 ? 40
	    : orbit>= 112217754 && orbit<= 115102167 ? 80
	    : orbit>= 115372336 && orbit<= 118244161 ? 120
	    : orbit>= 118544068 && orbit<= 121401866 ? 160
	    : orbit>= 121674019 && orbit<= 124537023 ? 200
	    : orbit>= 124837506 && orbit<= 127678870 ? 220
	    : orbit>= 127950483 && orbit<= 130824261 ? 240
	    : orbit>= 131066318 && orbit<= 133963750 ? 260
	    : orbit>= 134236191 && orbit<= 137114959 ? 280
	    : orbit>= 137360095 && orbit<= 140269143 ? 300
	    : orbit>= 140514680 && orbit<= 143425440 ? 330
	    : orbit>= 143668962 && orbit<= 146550293 ? 360
	    : orbit>= 146825766 && orbit<= 149705145 ? 400
	    : orbit>= 150058975 && orbit<= 152838797 ? 250
	      : NOVAL_I;
	case 367262:
	  return
	    orbit>= 7099870 && orbit<= 9973319 ? 10
	    : orbit>= 10169046 && orbit<= 12852101 ? 25
	    : orbit>= 13040868 && orbit<= 15739671 ? 50
	    : orbit>= 15959748 && orbit<= 18892548 ? 75
	    : orbit>= 19083998 && orbit<= 21766757 ? 100
	    : orbit>= 21931959 && orbit<= 24652329 ? 120
	    : orbit>= 24817938 && orbit<= 27542550 ? 140
	    : orbit>= 27734239 && orbit<= 30417342 ? 160
	    : orbit>= 30608624 && orbit<= 33313703 ? 180
	    : orbit>= 33505478 && orbit<= 36453885 ? 200
	    : orbit>= 36587559 && orbit<= 39346964 ? 220
	    : orbit>= 39511702 && orbit<= 42230281 ? 240
	    : orbit>= 42366690 && orbit<= 45102527 ? 260
	    : orbit>= 45240256 && orbit<= 47984863 ? 280
	    : orbit>= 48176143 && orbit<= 50887425 ? 300
	    : orbit>= 51050647 && orbit<= 53762229 ? 320
	    : orbit>= 53954281 && orbit<= 56911774 ? 340
	    : orbit>= 57075795 && orbit<= 59793547 ? 360
	    : orbit>= 59929631 && orbit<= 62659588 ? 380
	    : orbit>= 62878057 && orbit<= 65827762 ? 400
	    : orbit>= 66128316 && orbit<= 68970973 ? 250
	      : NOVAL_I;
	case 367691:
	  return
	    orbit>= 38093805 && orbit<= 40915552 ? 10
	    : orbit>= 41110913 && orbit<= 44047646 ? 25
	    : orbit>= 44186753 && orbit<= 46929565 ? 50
	    : orbit>= 47125589 && orbit<= 49838059 ? 75
	    : orbit>= 50003212 && orbit<= 52705357 ? 100
	    : orbit>= 52896569 && orbit<= 55580803 ? 120
	      : NOVAL_I;
	case 367693:
	  return
	    orbit>= 1098110 && orbit<= 3945219 ? 120
	    : orbit>= 4135366 && orbit<= 6829305 ? 140
	      : NOVAL_I;
	case 367696:
	  return
	    orbit>= 3506414 && orbit<= 6308118 ? 160
	    : orbit>= 6506342 && orbit<= 9468137 ? 180
	    : orbit>= 9637017 && orbit<= 12338491 ? 200
	    : orbit>= 12533908 && orbit<= 15483844 ? 220
	    : orbit>= 15653641 && orbit<= 18355679 ? 240
	    : orbit>= 18555832 && orbit<= 21245305 ? 260
	    : orbit>= 21385589 && orbit<= 24127787 ? 280
	    : orbit>= 24298863 && orbit<= 27024565 ? 300
	    : orbit>= 27136462 && orbit<= 29892124 ? 320
	    : orbit>= 30062691 && orbit<= 32789318 ? 340
	    : orbit>= 32929346 && orbit<= 35656656 ? 360
	    : orbit>= 35826537 && orbit<= 38555859 ? 380
	    : orbit>= 38755411 && orbit<= 41712687 ? 400
	    : orbit>= 42025627 && orbit<= 44837160 ? 250
	      : NOVAL_I;
	case 368318:
	  return
	    orbit>= 38680055 && orbit<= 41436877 ? 10
	    : orbit>= 41571843 && orbit<= 44311348 ? 25
	    : orbit>= 44502309 && orbit<= 47205698 ? 50
	    : orbit>= 47421959 && orbit<= 50347521 ? 75
	    : orbit>= 50508280 && orbit<= 53224276 ? 100
	    : orbit>= 53385408 && orbit<= 56124453 ? 120
	    : orbit>= 56286132 && orbit<= 58997544 ? 140
	    : orbit>= 59161176 && orbit<= 61882440 ? 160
	    : orbit>= 62071686 && orbit<= 64759415 ? 180
	    : orbit>= 64977629 && orbit<= 67907945 ? 200
	    : orbit>= 68097540 && orbit<= 70786060 ? 220
	    : orbit>= 70948149 && orbit<= 73673465 ? 240
	    : orbit>= 73863541 && orbit<= 76551518 ? 260
	    : orbit>= 76713898 && orbit<= 79436967 ? 280
	    : orbit>= 79601241 && orbit<= 82331790 ? 300
	      : NOVAL_I;
	case 368320:
	  return
	    orbit>= 7296034 && orbit<= 10245784 ? 320
	    : orbit>= 10436831 && orbit<= 13120570 ? 340
	    : orbit>= 13256620 && orbit<= 16014083 ? 360
	    : orbit>= 16205744 && orbit<= 19147750 ? 380
	    : orbit>= 19340819 && orbit<= 22029462 ? 400
	    : orbit>= 22359114 && orbit<= 25197863 ? 250
	      : NOVAL_I;
	case 368636:
	  return
	    orbit>= 33385564 && orbit<= 36207914 ? 10
	    : orbit>= 36371515 && orbit<= 39085596 ? 25
	    : orbit>= 39249532 && orbit<= 41952787 ? 50
	    : orbit>= 42143811 && orbit<= 44832462 ? 75
	    : orbit>= 44995928 && orbit<= 47737091 ? 100
	    : orbit>= 47899342 && orbit<= 50615477 ? 120
	    : orbit>= 50751769 && orbit<= 53490218 ? 140
	    : orbit>= 53653665 && orbit<= 56365742 ? 160
	    : orbit>= 56528473 && orbit<= 59270226 ? 180
	    : orbit>= 59461047 && orbit<= 62411805 ? 200
	    : orbit>= 62548295 && orbit<= 65290140 ? 220
	    : orbit>= 65425227 && orbit<= 68169459 ? 240
	    : orbit>= 68331785 && orbit<= 71070912 ? 260
	    : orbit>= 71234301 && orbit<= 73930658 ? 280
	    : orbit>= 74121783 && orbit<= 76837685 ? 300
	    : orbit>= 76973011 && orbit<= 79706299 ? 320
	    : orbit>= 79868802 && orbit<= 82607141 ? 340
	    : orbit>= 82768510 && orbit<= 85484677 ? 360
	    : orbit>= 85646605 && orbit<= 88362620 ? 380
	    : orbit>= 88525784 && orbit<= 91244037 ? 400
	    : orbit>= 91540489 && orbit<= 94394769 ? 250
	      : NOVAL_I;
	case 370169:
	  return
	    orbit>= 40342105 && orbit<= 43280163 ? 10
	    : orbit>= 43446024 && orbit<= 46163964 ? 25
	    : orbit>= 46360986 && orbit<= 49310460 ? 50
	    : orbit>= 49475797 && orbit<= 52185788 ? 75
	    : orbit>= 52352339 && orbit<= 55071756 ? 100
	    : orbit>= 55239247 && orbit<= 57948217 ? 120
	    : orbit>= 58115174 && orbit<= 60824770 ? 140
	    : orbit>= 60992420 && orbit<= 63706944 ? 160
	    : orbit>= 63845307 && orbit<= 66614001 ? 180
	    : orbit>= 66782084 && orbit<= 69473855 ? 200
	    : orbit>= 69641850 && orbit<= 72375108 ? 220
	    : orbit>= 72571092 && orbit<= 75528087 ? 240
	    : orbit>= 75722880 && orbit<= 78653907 ? 260
	    : orbit>= 78849747 && orbit<= 81532531 ? 280
	    : orbit>= 81672588 && orbit<= 84442221 ? 300
	    : orbit>= 84637613 && orbit<= 87569623 ? 320
	    : orbit>= 87737354 && orbit<= 90457916 ? 340
	    : orbit>= 90623611 && orbit<= 93355955 ? 360
	    : orbit>= 93522339 && orbit<= 96229970 ? 380
	    : orbit>= 96368015 && orbit<= 99098219 ? 400
	    : orbit>= 99434925 && orbit<= 102250856 ? 250
	      : NOVAL_I;
	case 370772:
	  return
	    orbit>= 52470445 && orbit<= 55333639 ? 10
	    : orbit>= 55472333 && orbit<= 58213155 ? 25
	    : orbit>= 58377241 && orbit<= 61089932 ? 50
	    : orbit>= 61256076 && orbit<= 63986325 ? 75
	    : orbit>= 64151875 && orbit<= 66856984 ? 100
	    : orbit>= 67024241 && orbit<= 69745556 ? 120
	    : orbit>= 69882848 && orbit<= 72642643 ? 140
	    : orbit>= 72780104 && orbit<= 75513072 ? 160
	    : orbit>= 75705636 && orbit<= 78389735 ? 180
	    : orbit>= 78527331 && orbit<= 81287919 ? 200
	    : orbit>= 81481429 && orbit<= 84417782 ? 220
	    : orbit>= 84582153 && orbit<= 87299914 ? 240
	    : orbit>= 87493915 && orbit<= 90188367 ? 260
	    : orbit>= 90382679 && orbit<= 93075344 ? 280
	    : orbit>= 93240739 && orbit<= 95958111 ? 300
	    : orbit>= 96127506 && orbit<= 98855902 ? 320
	    : orbit>= 98995097 && orbit<= 101722000 ? 340
	    : orbit>= 101919990 && orbit<= 104619178 ? 360
	    : orbit>= 104813521 && orbit<= 107747043 ? 380
	    : orbit>= 107916236 && orbit<= 110656907 ? 400
	    : orbit>= 110966804 && orbit<= 113797510 ? 250
	      : NOVAL_I;
	case 372597:
	  return
	    orbit>= 7903752 && orbit<= 13394769 ? 10
	    : orbit>= 13557899 && orbit<= 18905971 ? 25
	    : orbit>= 19067942 && orbit<= 24398996 ? 50
	    : orbit>= 24559026 && orbit<= 29910640 ? 75
	    : orbit>= 30098947 && orbit<= 35673648 ? 100
	    : orbit>= 35834767 && orbit<= 41184922 ? 120
	    : orbit>= 41347438 && orbit<= 46668343 ? 140
	    : orbit>= 46855827 && orbit<= 52173231 ? 160
	      : NOVAL_I;
	case 372598:
	  return
	    orbit>= 2746350 && orbit<= 8139349 ? 180
	    : orbit>= 8273753 && orbit<= 13650923 ? 200
	    : orbit>= 15111512 && orbit<= 20472285 ? 220
	      : NOVAL_I;
	case 372601:
	  return
	    orbit>= 490474 && orbit<= 6042138 ? 240
	    : orbit>= 6176244 && orbit<= 11549929 ? 260
	      : NOVAL_I;
	case 372602:
	  return
	    orbit>= 361535 && orbit<= 5785597 ? 280
	    : orbit>= 5948983 && orbit<= 11296711 ? 300
	    : orbit>= 11459733 && orbit<= 16786650 ? 320
	    : orbit>= 16923122 && orbit<= 22312993 ? 340
	    : orbit>= 22477745 && orbit<= 27808336 ? 360
	    : orbit>= 28000123 && orbit<= 33564939 ? 380
	    : orbit>= 33759233 && orbit<= 39083698 ? 400
	    : orbit>= 39385415 && orbit<= 44853027 ? 250
	      : NOVAL_I;
	case 375697:
	  return
	    orbit>= 14181054 && orbit<= 17056109 ? 10
	    : orbit>= 17275876 && orbit<= 20193293 ? 50
	    : orbit>= 20388031 && orbit<= 23095530 ? 100
	    : orbit>= 23289806 && orbit<= 26236248 ? 140
	    : orbit>= 26403276 && orbit<= 29104372 ? 180
	    : orbit>= 29271858 && orbit<= 32013840 ? 220
	    : orbit>= 32126302 && orbit<= 34880439 ? 240
	    : orbit>= 35047818 && orbit<= 37760914 ? 260
	    : orbit>= 37929290 && orbit<= 40658642 ? 280
	    : orbit>= 40852199 && orbit<= 43809979 ? 300
	    : orbit>= 43977324 && orbit<= 46666746 ? 320
	    : orbit>= 46832244 && orbit<= 49562209 ? 340
	    : orbit>= 49759108 && orbit<= 52723019 ? 360
	    : orbit>= 52860920 && orbit<= 55597269 ? 380
	    : orbit>= 55790859 && orbit<= 58751634 ? 400
	    : orbit>= 59029356 && orbit<= 61896178 ? 250
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_l4
  
  // Define Disk 1 Scans below
  int hv_d1(int run, int ls, int orbit, int ring) {
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
      //2017 May25 - FPix only
    case 295127:
      return
        orbit>= 2776807 && orbit<= 4835890 ? 10
        : orbit>= 6716073 && orbit<= 8715613 ? 20
	  : NOVAL_I;
    case 295128:
      return
        orbit>= 200333 && orbit<= 1961764 ? 30
        : orbit>= 3237710 && orbit<= 4971846 ? 40
        : orbit>= 7788614 && orbit<= 9517935 ? 50
        : orbit>= 10466037 && orbit<= 12197179 ? 60
        : orbit>= 13976185 && orbit<= 15773805 ? 80
        : orbit>= 17583931 && orbit<= 19359151 ? 100
        : orbit>= 21177001 && orbit<= 22918206 ? 125
        : orbit>= 88739037 && orbit<= 90548890 ? 70
        : orbit>= 91901665 && orbit<= 93666825 ? 90
	  : NOVAL_I;
    case 295132:
      return 150;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 300
        : orbit>= 4820837 && orbit<= 6140910 ? 100
        : orbit>= 6278715 && orbit<= 7625165 ? 150
        : orbit>= 7791082 && orbit<= 9123014 ? 200
        : orbit>= 9315440 && orbit<= 10661707 ? 250
        : orbit>= 10826802 && orbit<= 12175187 ? 350
        : orbit>= 12338552 && orbit<= 13683570 ? 400
        : orbit>= 67303535 && orbit<= 68633680 ? 300
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 130381323 && orbit<= 132934980 ? 10
	    : orbit>= 133068722 && orbit<= 135540254 ? 20
	    : orbit>= 135674536 && orbit<= 138174246 ? 30
	    : orbit>= 138309330 && orbit<= 140800465 ? 40
	    : orbit>= 140971902 && orbit<= 143422950 ? 50
	    : orbit>= 143593020 && orbit<= 146031871 ? 60
	    : orbit>= 146174267 && orbit<= 148653151 ? 70
	    : orbit>= 148840032 && orbit<= 151285917 ? 80
	    : orbit>= 151418525 && orbit<= 153884225 ? 90
	    : orbit>= 154043043 && orbit<= 156531499 ? 100
	    : orbit>= 156743742 && orbit<= 159400350 ? 150
	    : orbit>= 159585302 && orbit<= 162013799 ? 200
	    : orbit>= 162225719 && orbit<= 164645494 ? 250
	    : orbit>= 164779000 && orbit<= 167279487 ? 300
	    : orbit>= 167492317 && orbit<= 170146283 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 36637269 && orbit<= 39091295 ? 125
	    : orbit>= 39304209 && orbit<= 41964093 ? 175
	    : orbit>= 42177100 && orbit<= 44594783 ? 225
	    : orbit>= 44840392 && orbit<= 47458916 ? 350
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 10
	    : orbit>= 41825841 && orbit<= 44322177 ? 20
	    : orbit>= 44480767 && orbit<= 46948744 ? 30
	    : orbit>= 47135051 && orbit<= 49565502 ? 40
	    : orbit>= 49728746 && orbit<= 52187784 ? 50
	    : orbit>= 52322198 && orbit<= 54804994 ? 60
	    : orbit>= 54969957 && orbit<= 57440386 ? 70
	    : orbit>= 57553203 && orbit<= 60043347 ? 80
	    : orbit>= 60176652 && orbit<= 62671231 ? 90
	    : orbit>= 62830841 && orbit<= 65299490 ? 100
	    : orbit>= 65460761 && orbit<= 67931853 ? 125
	    : orbit>= 68119359 && orbit<= 70522726 ? 150
	    : orbit>= 70683404 && orbit<= 73153756 ? 175
	    : orbit>= 73311203 && orbit<= 75775055 ? 200
	    : orbit>= 75933126 && orbit<= 78397728 ? 225
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
	case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 10
	    : orbit>= 27391881 && orbit<= 29910318 ? 20
	    : orbit>= 30048261 && orbit<= 32528621 ? 30
	    : orbit>= 32692410 && orbit<= 35184550 ? 40
	    : orbit>= 35347550 && orbit<= 37766749 ? 50
	    : orbit>= 37964504 && orbit<= 40393240 ? 60
	    : orbit>= 40564372 && orbit<= 43001725 ? 70
	    : orbit>= 43111459 && orbit<= 45637231 ? 80
	    : orbit>= 45800722 && orbit<= 48263040 ? 90
	    : orbit>= 48454863 && orbit<= 50886070 ? 100
	    : orbit>= 51052187 && orbit<= 53510050 ? 125
	    : orbit>= 53672834 && orbit<= 56130806 ? 150
	    : orbit>= 56294595 && orbit<= 58752882 ? 175
	    : orbit>= 58889269 && orbit<= 61372970 ? 200
	    : orbit>= 61571382 && orbit<= 63995005 ? 225
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 300
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 10
	    : orbit>= 47613845 && orbit<= 50105260 ? 20
	    : orbit>= 50188211 && orbit<= 52709208 ? 30
	    : orbit>= 52895444 && orbit<= 55339608 ? 40
	    : orbit>= 55500867 && orbit<= 57952349 ? 50
	    : orbit>= 58141198 && orbit<= 60574900 ? 60
	    : orbit>= 60717816 && orbit<= 63221110 ? 70
	    : orbit>= 63329551 && orbit<= 65809487 ? 80
	    : orbit>= 65969746 && orbit<= 68435462 ? 90
	    : orbit>= 68575779 && orbit<= 71053332 ? 100
	    : orbit>= 71220080 && orbit<= 73688468 ? 125
	    : orbit>= 73877439 && orbit<= 76301206 ? 150
	    : orbit>= 76461185 && orbit<= 78925237 ? 175
	    : orbit>= 79058767 && orbit<= 81554007 ? 200
	    : orbit>= 81740951 && orbit<= 84170667 ? 225
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 300
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 10
	    : orbit>= 47854891 && orbit<= 50359955 ? 20
	    : orbit>= 50522239 && orbit<= 52977308 ? 30
	    : orbit>= 53113522 && orbit<= 55616572 ? 40
	    : orbit>= 55755315 && orbit<= 58228213 ? 50
	    : orbit>= 58372274 && orbit<= 60827613 ? 60
	    : orbit>= 60995674 && orbit<= 63463695 ? 70
	    : orbit>= 63631902 && orbit<= 66076490 ? 80
	    : orbit>= 66213020 && orbit<= 68722423 ? 90
	    : orbit>= 68890165 && orbit<= 71333543 ? 100
	    : orbit>= 71498800 && orbit<= 73941265 ? 125
	    : orbit>= 74129851 && orbit<= 76570264 ? 150
	    : orbit>= 76734342 && orbit<= 79189022 ? 175
	    : orbit>= 79329459 && orbit<= 81814529 ? 200
	    : orbit>= 82013635 && orbit<= 84419465 ? 225
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 300
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 10
	    : orbit>= 9566810 && orbit<= 12075322 ? 20
	    : orbit>= 12213121 && orbit<= 14717975 ? 30
	    : orbit>= 14853577 && orbit<= 17316216 ? 40
	    : orbit>= 17503961 && orbit<= 19935530 ? 50
	    : orbit>= 20071439 && orbit<= 22554342 ? 60
	    : orbit>= 22715316 && orbit<= 25193763 ? 70
	    : orbit>= 25355311 && orbit<= 27817230 ? 80
	    : orbit>= 27926532 && orbit<= 30416278 ? 90
	    : orbit>= 30527882 && orbit<= 33049984 ? 100
	    : orbit>= 33212050 && orbit<= 35664191 ? 125
	    : orbit>= 35826282 && orbit<= 38287417 ? 150
	    : orbit>= 38504148 && orbit<= 40914406 ? 175
	    : orbit>= 41077682 && orbit<= 43524088 ? 200
	    : orbit>= 43659205 && orbit<= 46161085 ? 225
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 300
	      : NOVAL_I;
	case 320570:
	  return
	    orbit>= 49778311 && orbit<= 52174583 ? 20
	    : orbit>= 52363057 && orbit<= 54817129 ? 40
	    : orbit>= 55005385 && orbit<= 57427140 ? 60
	    : orbit>= 57562288 && orbit<= 60062002 ? 80
	    : orbit>= 60276000 && orbit<= 62942731 ? 100
	    : orbit>= 63157045 && orbit<= 65820976 ? 125
	    : orbit>= 65955103 && orbit<= 68433339 ? 150
	    : orbit>= 68594223 && orbit<= 71098367 ? 175
	    : orbit>= 71260096 && orbit<= 73691039 ? 200
	    : orbit>= 73852017 && orbit<= 76301806 ? 225
	    : orbit>= 76437069 && orbit<= 78933364 ? 250
	    : orbit>= 79067620 && orbit<= 81537619 ? 275
	    : orbit>= 81697616 && orbit<= 84172962 ? 300
	    : orbit>= 84361974 && orbit<= 86801621 ? 325
	    : orbit>= 86988379 && orbit<= 89411122 ? 350
	    : orbit>= 89598437 && orbit<= 92041736 ? 375
	    : orbit>= 92283598 && orbit<= 94922442 ? 400
	    : orbit>= 95243781 && orbit<= 95431232 ? 300
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 10
	    : orbit>= 4370646 && orbit<= 6835331 ? 20
	    : orbit>= 6998249 && orbit<= 9443899 ? 30
	    : orbit>= 9603408 && orbit<= 12088965 ? 40
	    : orbit>= 12249948 && orbit<= 14691253 ? 50
	    : orbit>= 14824908 && orbit<= 17317702 ? 60
	    : orbit>= 17479610 && orbit<= 19929276 ? 70
	    : orbit>= 20117009 && orbit<= 22560727 ? 80
	    : orbit>= 22748255 && orbit<= 25191626 ? 90
	    : orbit>= 25299297 && orbit<= 27799610 ? 100
	    : orbit>= 27936056 && orbit<= 30437130 ? 125
	    : orbit>= 30629196 && orbit<= 33078612 ? 150
	    : orbit>= 33186971 && orbit<= 35673738 ? 175
	    : orbit>= 35860673 && orbit<= 38283804 ? 200
	    : orbit>= 38417265 && orbit<= 40915199 ? 225
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 300
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 10
	    : orbit>= 63075867 && orbit<= 65549032 ? 20
	    : orbit>= 65683169 && orbit<= 68178385 ? 30
	    : orbit>= 68339788 && orbit<= 70786533 ? 40
	    : orbit>= 70945624 && orbit<= 73405782 ? 50
	    : orbit>= 73539162 && orbit<= 76031847 ? 60
	    : orbit>= 76194593 && orbit<= 78661829 ? 70
	    : orbit>= 78793861 && orbit<= 81294346 ? 80
	    : orbit>= 81402558 && orbit<= 83913027 ? 90
	    : orbit>= 84019032 && orbit<= 86545026 ? 100
	    : orbit>= 86678270 && orbit<= 89173927 ? 125
	    : orbit>= 89360682 && orbit<= 91778781 ? 150
	    : orbit>= 91965880 && orbit<= 94679839 ? 175
	    : orbit>= 94865315 && orbit<= 97286456 ? 200
	    : orbit>= 97472797 && orbit<= 99884436 ? 225
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 300
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 10
	    : orbit>= 58114200 && orbit<= 60588212 ? 20
	    : orbit>= 60724340 && orbit<= 63202264 ? 30
	    : orbit>= 63340322 && orbit<= 65817097 ? 40
	    : orbit>= 65979355 && orbit<= 68425849 ? 50
	    : orbit>= 68561709 && orbit<= 71071128 ? 60
	    : orbit>= 71233215 && orbit<= 73688647 ? 70
	    : orbit>= 73852199 && orbit<= 76310213 ? 80
	    : orbit>= 76473584 && orbit<= 78927087 ? 90
	    : orbit>= 79093199 && orbit<= 81541766 ? 100
	    : orbit>= 81704609 && orbit<= 84163799 ? 125
	    : orbit>= 84355052 && orbit<= 86800517 ? 150
	    : orbit>= 86965497 && orbit<= 89409147 ? 175
	    : orbit>= 89572559 && orbit<= 92042263 ? 200
	    : orbit>= 92204778 && orbit<= 94675917 ? 225
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 300
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 10
	    : orbit>= 43422348 && orbit<= 45881929 ? 20
	    : orbit>= 46018056 && orbit<= 48516945 ? 30
	    : orbit>= 48678223 && orbit<= 51169750 ? 40
	    : orbit>= 51304556 && orbit<= 53771512 ? 50
	    : orbit>= 53932342 && orbit<= 56381384 ? 60
	    : orbit>= 56516448 && orbit<= 59011528 ? 70
	    : orbit>= 59200521 && orbit<= 61617940 ? 80
	    : orbit>= 61753974 && orbit<= 64253057 ? 90
	    : orbit>= 64390607 && orbit<= 66854828 ? 100
	    : orbit>= 67018750 && orbit<= 69485929 ? 125
	    : orbit>= 69648708 && orbit<= 72118854 ? 150
	    : orbit>= 72306340 && orbit<= 74742683 ? 175
	    : orbit>= 74932909 && orbit<= 77350840 ? 200
	    : orbit>= 77510220 && orbit<= 79977923 ? 225
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 350
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 10
	    : orbit>= 52868613 && orbit<= 55321785 ? 20
	    : orbit>= 55462104 && orbit<= 57973413 ? 30
	    : orbit>= 58087326 && orbit<= 60562624 ? 40
	    : orbit>= 60709545 && orbit<= 63210483 ? 50
	    : orbit>= 63359047 && orbit<= 65804852 ? 60
	    : orbit>= 65946954 && orbit<= 68434710 ? 70
	    : orbit>= 68605001 && orbit<= 71096881 ? 80
	    : orbit>= 71238107 && orbit<= 73690920 ? 90
	    : orbit>= 73860855 && orbit<= 76295804 ? 100
	    : orbit>= 76465735 && orbit<= 78930971 ? 125
	    : orbit>= 79102261 && orbit<= 81539075 ? 150
	    : orbit>= 81714638 && orbit<= 84171548 ? 175
	    : orbit>= 84349817 && orbit<= 86788381 ? 200
	    : orbit>= 86964660 && orbit<= 89396615 ? 225
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 350
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
	case 352931:
	  return
	    orbit>= 1968481 && orbit<= 4736017 ? 10
	    : orbit>= 4784461 && orbit<= 7610810 ? 20
	    : orbit>= 7660060 && orbit<= 10511621 ? 30
	    : orbit>= 10562037 && orbit<= 13380721 ? 40
	    : orbit>= 13429646 && orbit<= 16268114 ? 50
	    : orbit>= 16390112 && orbit<= 19147855 ? 60
	    : orbit>= 19272670 && orbit<= 22032839 ? 70
	    : orbit>= 22082824 && orbit<= 24921952 ? 80
	    : orbit>= 25044824 && orbit<= 27805658 ? 90
	    : orbit>= 27855378 && orbit<= 30684689 ? 100
	    : orbit>= 30808993 && orbit<= 33579280 ? 125
	    : orbit>= 33629193 && orbit<= 36467115 ? 150
	    : orbit>= 36613893 && orbit<= 39337659 ? 175
	    : orbit>= 39386937 && orbit<= 42233511 ? 200
	    : orbit>= 42380958 && orbit<= 45108131 ? 225
	    : orbit>= 45157840 && orbit<= 47985532 ? 250
	    : orbit>= 48105844 && orbit<= 50885738 ? 275
	    : orbit>= 50934591 && orbit<= 53747920 ? 300
	    : orbit>= 53917558 && orbit<= 56637545 ? 350
	    : orbit>= 56686674 && orbit<= 59525018 ? 400
	    : orbit>= 59574993 && orbit<= 59797815 ? 350
	      : NOVAL_I;
	case 355135:
	  return
	    orbit>= 104755793 && orbit<= 107485110 ? 10
	    : orbit>= 107614366 && orbit<= 110391607 ? 20
	    : orbit>= 110573192 && orbit<= 113275272 ? 30
	    : orbit>= 113405153 && orbit<= 116158746 ? 40
	    : orbit>= 116287797 && orbit<= 119020007 ? 50
	    : orbit>= 119176310 && orbit<= 121918327 ? 60
	    : orbit>= 122046345 && orbit<= 124807657 ? 70
	    : orbit>= 124938870 && orbit<= 127676820 ? 80
	    : orbit>= 127808113 && orbit<= 130574447 ? 90
	    : orbit>= 130703959 && orbit<= 133445781 ? 100
	    : orbit>= 133575707 && orbit<= 136335379 ? 150
	    : orbit>= 136464965 && orbit<= 139229004 ? 200
	    : orbit>= 139255350 && orbit<= 142101766 ? 250
	    : orbit>= 142285520 && orbit<= 144981374 ? 300
	    : orbit>= 145163017 && orbit<= 147867049 ? 400
	      : NOVAL_I;
	case 357900:
	  return
	    orbit>= 12664081 && orbit<= 15486907 ? 10
	    : orbit>= 15566369 && orbit<= 18368115 ? 20
	    : orbit>= 18420230 && orbit<= 21247176 ? 30
	    : orbit>= 21378632 && orbit<= 24147295 ? 40
	    : orbit>= 24199731 && orbit<= 27025711 ? 50
	    : orbit>= 27077499 && orbit<= 29909218 ? 60
	    : orbit>= 29960548 && orbit<= 32790919 ? 70
	    : orbit>= 32843486 && orbit<= 35673003 ? 80
	    : orbit>= 35778744 && orbit<= 38555720 ? 90
	    : orbit>= 38608540 && orbit<= 41438736 ? 100
	    : orbit>= 41570546 && orbit<= 44324553 ? 125
	    : orbit>= 44455195 && orbit<= 47211734 ? 150
	    : orbit>= 47342579 && orbit<= 50093965 ? 175
	    : orbit>= 50251205 && orbit<= 52977181 ? 200
	    : orbit>= 53030010 && orbit<= 55863627 ? 225
	    : orbit>= 55916697 && orbit<= 58740975 ? 250
	    : orbit>= 58793298 && orbit<= 61624510 ? 275
	    : orbit>= 61784559 && orbit<= 64513818 ? 300
	    : orbit>= 64698513 && orbit<= 67393943 ? 350
	    : orbit>= 67551617 && orbit<= 70262612 ? 400
	    : orbit>= 70315602 && orbit<= 73150278 ? 350
	      : NOVAL_I;
	case 359571:
	  return
	    orbit>= 1598793 && orbit<= 4462108 ? 10
	    : orbit>= 4511395 && orbit<= 7350069 ? 20
	    : orbit>= 7399774 && orbit<= 10241564 ? 30
	    : orbit>= 10365345 && orbit<= 13132585 ? 40
	    : orbit>= 13255825 && orbit<= 15995781 ? 50
	    : orbit>= 16121215 && orbit<= 18899097 ? 60
	    : orbit>= 19022211 && orbit<= 21775984 ? 80
	    : orbit>= 21826416 && orbit<= 24672183 ? 100
	    : orbit>= 24722328 && orbit<= 27552047 ? 120
	    : orbit>= 27601834 && orbit<= 30433146 ? 140
	    : orbit>= 30557652 && orbit<= 33309141 ? 160
	    : orbit>= 33432366 && orbit<= 36193558 ? 180
	    : orbit>= 36243029 && orbit<= 39068178 ? 200
	    : orbit>= 39118463 && orbit<= 41969704 ? 225
	      : NOVAL_I;
	case 359575:
	  return
	    orbit>= 629737 && orbit<= 3422063 ? 250
	    : orbit>= 3548475 && orbit<= 6312050 ? 275
	    : orbit>= 6461056 && orbit<= 9196810 ? 300
	    : orbit>= 9348596 && orbit<= 12066809 ? 325
	    : orbit>= 12216331 && orbit<= 14954951 ? 375
	    : orbit>= 15107686 && orbit<= 17849142 ? 400
	    : orbit>= 18099677 && orbit<= 20986877 ? 350
	      : NOVAL_I;
	case 359998:
	  return
	    orbit>= 104875561 && orbit<= 107755135 ? 10
	    : orbit>= 107913968 && orbit<= 110630494 ? 20
	    : orbit>= 110788251 && orbit<= 113524201 ? 30
	    : orbit>= 113682052 && orbit<= 116420968 ? 40
	    : orbit>= 116550343 && orbit<= 119293351 ? 50
	    : orbit>= 119426118 && orbit<= 122178850 ? 60
	    : orbit>= 122336636 && orbit<= 125069620 ? 80
	    : orbit>= 125226412 && orbit<= 127952275 ? 100
	    : orbit>= 128057808 && orbit<= 130827303 ? 120
	    : orbit>= 130983638 && orbit<= 133718918 ? 140
	    : orbit>= 133823634 && orbit<= 136599596 ? 160
	    : orbit>= 136731343 && orbit<= 139480531 ? 180
	    : orbit>= 139610170 && orbit<= 142361614 ? 200
	    : orbit>= 142518456 && orbit<= 145248303 ? 225
	    : orbit>= 146982775 && orbit<= 149705976 ? 250
	    : orbit>= 149812001 && orbit<= 152574204 ? 275
	    : orbit>= 152707668 && orbit<= 155473411 ? 300
	    : orbit>= 155579472 && orbit<= 158344060 ? 325
	    : orbit>= 158503782 && orbit<= 161231425 ? 375
	    : orbit>= 161392164 && orbit<= 164109895 ? 400
	    : orbit>= 164399038 && orbit<= 167263402 ? 350
	      : NOVAL_I;
	case 360295:
	  return
	    orbit>= 250123817 && orbit<= 252997151 ? 10
	    : orbit>= 253130344 && orbit<= 255876427 ? 20
	    : orbit>= 256037677 && orbit<= 258760820 ? 30
	    : orbit>= 258895922 && orbit<= 261640771 ? 40
	    : orbit>= 261775735 && orbit<= 264513826 ? 50
	    : orbit>= 264621139 && orbit<= 267397855 ? 60
	    : orbit>= 267530956 && orbit<= 270282609 ? 80
	    : orbit>= 270417033 && orbit<= 273166939 ? 100
	    : orbit>= 273326940 && orbit<= 276051811 ? 120
	    : orbit>= 276185803 && orbit<= 278938988 ? 140
	    : orbit>= 279075317 && orbit<= 281832159 ? 160
	    : orbit>= 281965899 && orbit<= 284714222 ? 180
	    : orbit>= 284848582 && orbit<= 287602289 ? 200
	    : orbit>= 287735524 && orbit<= 290484727 ? 225
	    : orbit>= 290620075 && orbit<= 293353433 ? 250
	    : orbit>= 293460265 && orbit<= 296246415 ? 275
	    : orbit>= 296379312 && orbit<= 299138425 ? 300
	    : orbit>= 299301164 && orbit<= 302001233 ? 325
	    : orbit>= 302137056 && orbit<= 304881966 ? 375
	    : orbit>= 305042514 && orbit<= 307762219 ? 400
	    : orbit>= 308029792 && orbit<= 310911240 ? 350
	      : NOVAL_I;
	case 360796:
	  return
	    orbit>= 75646765 && orbit<= 78396600 ? 10
	    : orbit>= 78507985 && orbit<= 81277003 ? 20
	    : orbit>= 81385464 && orbit<= 84160318 ? 30
	    : orbit>= 84297227 && orbit<= 87050646 ? 40
	    : orbit>= 87186625 && orbit<= 89935156 ? 50
	    : orbit>= 90098419 && orbit<= 92830631 ? 60
	    : orbit>= 92967681 && orbit<= 95710970 ? 80
	    : orbit>= 95821281 && orbit<= 98586494 ? 100
	    : orbit>= 98719921 && orbit<= 101456347 ? 120
	    : orbit>= 101593245 && orbit<= 104351070 ? 140
	    : orbit>= 104512707 && orbit<= 107226276 ? 160
	    : orbit>= 107333521 && orbit<= 110118658 ? 180
	    : orbit>= 110228652 && orbit<= 112993580 ? 200
	    : orbit>= 113104333 && orbit<= 115892159 ? 225
	    : orbit>= 116055955 && orbit<= 118776123 ? 250
	    : orbit>= 118912464 && orbit<= 121643055 ? 275
	    : orbit>= 121808435 && orbit<= 124535570 ? 300
	    : orbit>= 124698262 && orbit<= 127419378 ? 325
	    : orbit>= 127525948 && orbit<= 130294767 ? 375
	    : orbit>= 130432704 && orbit<= 133198582 ? 400
	    : orbit>= 133472480 && orbit<= 136338129 ? 350
	      : NOVAL_I;
	case 361223:
	  return
	    orbit>= 38087387 && orbit<= 40918583 ? 10
	    : orbit>= 41051543 && orbit<= 43792557 ? 20
	    : orbit>= 43899276 && orbit<= 46692751 ? 30
	    : orbit>= 46801557 && orbit<= 49551982 ? 40
	    : orbit>= 49712638 && orbit<= 52437174 ? 50
	    : orbit>= 52517765 && orbit<= 55318121 ? 60
	    : orbit>= 55451536 && orbit<= 58222205 ? 80
	    : orbit>= 58329114 && orbit<= 61107309 ? 100
	    : orbit>= 61241257 && orbit<= 63972397 ? 120
	    : orbit>= 64107430 && orbit<= 66869015 ? 140
	    : orbit>= 67003578 && orbit<= 69740800 ? 160
	    : orbit>= 69877021 && orbit<= 72642959 ? 180
	    : orbit>= 72778246 && orbit<= 75522331 ? 200
	    : orbit>= 75658158 && orbit<= 78396727 ? 225
	    : orbit>= 78533017 && orbit<= 81279217 ? 250
	    : orbit>= 81441635 && orbit<= 84154693 ? 275
	    : orbit>= 84317433 && orbit<= 87037091 ? 300
	    : orbit>= 87173373 && orbit<= 89928279 ? 325
	    : orbit>= 90038254 && orbit<= 92820920 ? 375
	    : orbit>= 92984498 && orbit<= 95713653 ? 400
	    : orbit>= 95988057 && orbit<= 98845309 ? 350
	      : NOVAL_I;
	case 361475:
	  return
	    orbit>= 222110333 && orbit<= 224939149 ? 10
	    : orbit>= 225072545 && orbit<= 227809699 ? 20
	    : orbit>= 227970409 && orbit<= 230699599 ? 30
	    : orbit>= 230779861 && orbit<= 233595778 ? 40
	    : orbit>= 233703427 && orbit<= 236465704 ? 50
	    : orbit>= 236598359 && orbit<= 239360686 ? 60
	    : orbit>= 239493494 && orbit<= 242245761 ? 80
	    : orbit>= 242405079 && orbit<= 245128059 ? 100
	    : orbit>= 245285736 && orbit<= 248003579 ? 120
	    : orbit>= 248163112 && orbit<= 250881259 ? 140
	    : orbit>= 250985797 && orbit<= 253786244 ? 160
	    : orbit>= 253891737 && orbit<= 256655416 ? 180
	    : orbit>= 256787880 && orbit<= 259547532 ? 200
	    : orbit>= 259680999 && orbit<= 262420314 ? 225
	    : orbit>= 262551948 && orbit<= 265298416 ? 250
	    : orbit>= 265428875 && orbit<= 268195013 ? 275
	    : orbit>= 268380359 && orbit<= 271084430 ? 300
	    : orbit>= 271243461 && orbit<= 273967363 ? 325
	    : orbit>= 274125527 && orbit<= 276846908 ? 375
	    : orbit>= 277001884 && orbit<= 279718446 ? 400
	    : orbit>= 279980916 && orbit<= 282880383 ? 350
	      : NOVAL_I;
	case 361890:
	  return
	    orbit>= 3963493 && orbit<= 9459187 ? 10
	    : orbit>= 9564419 && orbit<= 14968438 ? 20
	    : orbit>= 15099769 && orbit<= 20474451 ? 30
	    : orbit>= 20579259 && orbit<= 25958161 ? 40
	    : orbit>= 26114369 && orbit<= 31484064 ? 50
	    : orbit>= 31641788 && orbit<= 36981269 ? 60
	    : orbit>= 37111781 && orbit<= 42498466 ? 80
	    : orbit>= 42630885 && orbit<= 47984783 ? 100
	    : orbit>= 48115296 && orbit<= 53504821 ? 120
	    : orbit>= 53660650 && orbit<= 59011469 ? 140
	    : orbit>= 59143042 && orbit<= 64514429 ? 160
	    : orbit>= 64673894 && orbit<= 70005563 ? 180
	    : orbit>= 70138844 && orbit<= 75510829 ? 200
	    : orbit>= 75642832 && orbit<= 81009063 ? 225
	    : orbit>= 81141608 && orbit<= 86536110 ? 250
	    : orbit>= 86643866 && orbit<= 92044401 ? 275
	    : orbit>= 92180485 && orbit<= 97528310 ? 300
	    : orbit>= 97636672 && orbit<= 103045464 ? 325
	    : orbit>= 103180825 && orbit<= 108550068 ? 375
	    : orbit>= 108712296 && orbit<= 114044835 ? 400
	    : orbit>= 114313672 && orbit<= 119810887 ? 350
	      : NOVAL_I;
	case 362617:
	  return
	    orbit>= 1675207 && orbit<= 4482307 ? 10
	    : orbit>= 4589516 && orbit<= 7345565 ? 25
	    : orbit>= 7503560 && orbit<= 10251143 ? 50
	    : orbit>= 10383641 && orbit<= 13118256 ? 75
	    : orbit>= 13251150 && orbit<= 16012285 ? 100
	    : orbit>= 16092002 && orbit<= 18904691 ? 125
	    : orbit>= 19064644 && orbit<= 21780375 ? 150
	    : orbit>= 21915491 && orbit<= 24647683 ? 175
	    : orbit>= 24781469 && orbit<= 27544216 ? 200
	    : orbit>= 27701105 && orbit<= 30425847 ? 225
	    : orbit>= 30531014 && orbit<= 33309354 ? 250
	    : orbit>= 33440550 && orbit<= 36205433 ? 275
	    : orbit>= 36311560 && orbit<= 39080353 ? 300
	    : orbit>= 39211611 && orbit<= 41966680 ? 320
	    : orbit>= 42123525 && orbit<= 44832214 ? 340
	    : orbit>= 44963600 && orbit<= 47738950 ? 360
	    : orbit>= 47870274 && orbit<= 50611790 ? 380
	    : orbit>= 50717573 && orbit<= 53483918 ? 400
	    : orbit>= 53643704 && orbit<= 56368187 ? 425
	    : orbit>= 56499465 && orbit<= 59266913 ? 450
	    : orbit>= 59529205 && orbit<= 62409575 ? 350
	      : NOVAL_I;
	case 365775:
	  return
	    orbit>= 11674141 && orbit<= 14429083 ? 225
	    : orbit>= 14589392 && orbit<= 17324633 ? 250
	    : orbit>= 17510902 && orbit<= 20196585 ? 275
	    : orbit>= 20383796 && orbit<= 23092362 ? 300
	    : orbit>= 23253989 && orbit<= 25982133 ? 320
	    : orbit>= 26197706 && orbit<= 29103790 ? 340
	    : orbit>= 29319343 && orbit<= 32255384 ? 360
	    : orbit>= 32444673 && orbit<= 35145650 ? 380
	    : orbit>= 35334294 && orbit<= 38017264 ? 400
	    : orbit>= 38180097 && orbit<= 40924604 ? 425
	    : orbit>= 41087244 && orbit<= 43808026 ? 450
	    : orbit>= 44514502 && orbit<= 47198988 ? 10
	    : orbit>= 47361806 && orbit<= 50091213 ? 25
	    : orbit>= 50255317 && orbit<= 52961410 ? 50
	    : orbit>= 53152818 && orbit<= 55865611 ? 75
	    : orbit>= 56057509 && orbit<= 59001403 ? 100
	    : orbit>= 59192755 && orbit<= 61877774 ? 125
	    : orbit>= 62043689 && orbit<= 64774124 ? 150
	    : orbit>= 64884831 && orbit<= 67653732 ? 175
	    : orbit>= 67791500 && orbit<= 70538399 ? 200
	    : orbit>= 70818655 && orbit<= 73668482 ? 350
	      : NOVAL_I;
	case 366451:
    if (ring==1) {
	  return
	    orbit>= 105899907 && orbit<= 108812288 ? 10
	    : orbit>= 109057182 && orbit<= 111946094 ? 50
	    : orbit>= 112217754 && orbit<= 115102167 ? 90
	    : orbit>= 115372336 && orbit<= 118244161 ? 130
	    : orbit>= 118544068 && orbit<= 121401866 ? 170
	    : orbit>= 121674019 && orbit<= 124537023 ? 210
	    : orbit>= 124837506 && orbit<= 127678870 ? 250
	    : orbit>= 127950483 && orbit<= 130824261 ? 280
	    : orbit>= 131066318 && orbit<= 133963750 ? 310
	    : orbit>= 134236191 && orbit<= 137114959 ? 330
	    : orbit>= 137360095 && orbit<= 140269143 ? 370
	    : orbit>= 140514680 && orbit<= 143425440 ? 390
	    : orbit>= 143668962 && orbit<= 146550293 ? 420
	    : orbit>= 146825766 && orbit<= 149705145 ? 450
	    : orbit>= 150058975 && orbit<= 152838797 ? 350
	      : NOVAL_I;
    }
    else if (ring==2) {
	  return
	    orbit>= 105899907 && orbit<= 108812288 ? 10
	    : orbit>= 109057182 && orbit<= 111946094 ? 40
	    : orbit>= 112217754 && orbit<= 115102167 ? 80
	    : orbit>= 115372336 && orbit<= 118244161 ? 120
	    : orbit>= 118544068 && orbit<= 121401866 ? 160
	    : orbit>= 121674019 && orbit<= 124537023 ? 200
	    : orbit>= 124837506 && orbit<= 127678870 ? 230
	    : orbit>= 127950483 && orbit<= 130824261 ? 260
	    : orbit>= 131066318 && orbit<= 133963750 ? 280
	    : orbit>= 134236191 && orbit<= 137114959 ? 320
	    : orbit>= 137360095 && orbit<= 140269143 ? 340
	    : orbit>= 140514680 && orbit<= 143425440 ? 370
	    : orbit>= 143668962 && orbit<= 146550293 ? 400
	    : orbit>= 146825766 && orbit<= 149705145 ? 430
	    : orbit>= 150058975 && orbit<= 152838797 ? 300
	      : NOVAL_I;
    }
	case 367262:
	  return
	    orbit>= 7099870 && orbit<= 9973319 ? 10
	    : orbit>= 10169046 && orbit<= 12852101 ? 25
	    : orbit>= 13040868 && orbit<= 15739671 ? 50
	    : orbit>= 15959748 && orbit<= 18892548 ? 75
	    : orbit>= 19083998 && orbit<= 21766757 ? 100
	    : orbit>= 21931959 && orbit<= 24652329 ? 125
	    : orbit>= 24817938 && orbit<= 27542550 ? 150
	    : orbit>= 27734239 && orbit<= 30417342 ? 175
	    : orbit>= 30608624 && orbit<= 33313703 ? 200
	    : orbit>= 33505478 && orbit<= 36453885 ? 225
	    : orbit>= 36587559 && orbit<= 39346964 ? 250
	    : orbit>= 39511702 && orbit<= 42230281 ? 275
	    : orbit>= 42366690 && orbit<= 45102527 ? 300
	    : orbit>= 45240256 && orbit<= 47984863 ? 320
	    : orbit>= 48176143 && orbit<= 50887425 ? 340
	    : orbit>= 51050647 && orbit<= 53762229 ? 360
	    : orbit>= 53954281 && orbit<= 56911774 ? 380
	    : orbit>= 57075795 && orbit<= 59793547 ? 400
	    : orbit>= 59929631 && orbit<= 62659588 ? 425
	    : orbit>= 62878057 && orbit<= 65827762 ? 450
	    : orbit>= 66128316 && orbit<= 68970973 ? 350
	      : NOVAL_I;
	case 367691:
	  return
	    orbit>= 38093805 && orbit<= 40915552 ? 10
	    : orbit>= 41110913 && orbit<= 44047646 ? 25
	    : orbit>= 44186753 && orbit<= 46929565 ? 50
	    : orbit>= 47125589 && orbit<= 49838059 ? 75
	    : orbit>= 50003212 && orbit<= 52705357 ? 100
	    : orbit>= 52896569 && orbit<= 55580803 ? 125
	      : NOVAL_I;
	case 367693:
	  return
	    orbit>= 1098110 && orbit<= 3945219 ? 125
	    : orbit>= 4135366 && orbit<= 6829305 ? 150
	      : NOVAL_I;
	case 367696:
	  return
	    orbit>= 3506414 && orbit<= 6308118 ? 175
	    : orbit>= 6506342 && orbit<= 9468137 ? 200
	    : orbit>= 9637017 && orbit<= 12338491 ? 225
	    : orbit>= 12533908 && orbit<= 15483844 ? 250
	    : orbit>= 15653641 && orbit<= 18355679 ? 275
	    : orbit>= 18555832 && orbit<= 21245305 ? 300
	    : orbit>= 21385589 && orbit<= 24127787 ? 320
	    : orbit>= 24298863 && orbit<= 27024565 ? 340
	    : orbit>= 27136462 && orbit<= 29892124 ? 360
	    : orbit>= 30062691 && orbit<= 32789318 ? 380
	    : orbit>= 32929346 && orbit<= 35656656 ? 400
	    : orbit>= 35826537 && orbit<= 38555859 ? 425
	    : orbit>= 38755411 && orbit<= 41712687 ? 450
	    : orbit>= 42025627 && orbit<= 44837160 ? 350
	      : NOVAL_I;
	case 368318:
	  return
	    orbit>= 38680055 && orbit<= 41436877 ? 10
	    : orbit>= 41571843 && orbit<= 44311348 ? 25
	    : orbit>= 44502309 && orbit<= 47205698 ? 50
	    : orbit>= 47421959 && orbit<= 50347521 ? 75
	    : orbit>= 50508280 && orbit<= 53224276 ? 100
	    : orbit>= 53385408 && orbit<= 56124453 ? 125
	    : orbit>= 56286132 && orbit<= 58997544 ? 150
	    : orbit>= 59161176 && orbit<= 61882440 ? 175
	    : orbit>= 62071686 && orbit<= 64759415 ? 200
	    : orbit>= 64977629 && orbit<= 67907945 ? 225
	    : orbit>= 68097540 && orbit<= 70786060 ? 250
	    : orbit>= 70948149 && orbit<= 73673465 ? 275
	    : orbit>= 73863541 && orbit<= 76551518 ? 300
	    : orbit>= 76713898 && orbit<= 79436967 ? 320
	    : orbit>= 79601241 && orbit<= 82331790 ? 340
	      : NOVAL_I;
	case 368320:
	  return
	    orbit>= 7296034 && orbit<= 10245784 ? 360
	    : orbit>= 10436831 && orbit<= 13120570 ? 380
	    : orbit>= 13256620 && orbit<= 16014083 ? 400
	    : orbit>= 16205744 && orbit<= 19147750 ? 425
	    : orbit>= 19340819 && orbit<= 22029462 ? 450
	    : orbit>= 22359114 && orbit<= 25197863 ? 350
	      : NOVAL_I;
	case 368636:
	  return
	    orbit>= 33385564 && orbit<= 36207914 ? 10
	    : orbit>= 36371515 && orbit<= 39085596 ? 25
	    : orbit>= 39249532 && orbit<= 41952787 ? 50
	    : orbit>= 42143811 && orbit<= 44832462 ? 75
	    : orbit>= 44995928 && orbit<= 47737091 ? 100
	    : orbit>= 47899342 && orbit<= 50615477 ? 125
	    : orbit>= 50751769 && orbit<= 53490218 ? 150
	    : orbit>= 53653665 && orbit<= 56365742 ? 175
	    : orbit>= 56528473 && orbit<= 59270226 ? 200
	    : orbit>= 59461047 && orbit<= 62411805 ? 225
	    : orbit>= 62548295 && orbit<= 65290140 ? 250
	    : orbit>= 65425227 && orbit<= 68169459 ? 275
	    : orbit>= 68331785 && orbit<= 71070912 ? 300
	    : orbit>= 71234301 && orbit<= 73930658 ? 320
	    : orbit>= 74121783 && orbit<= 76837685 ? 340
	    : orbit>= 76973011 && orbit<= 79706299 ? 360
	    : orbit>= 79868802 && orbit<= 82607141 ? 380
	    : orbit>= 82768510 && orbit<= 85484677 ? 400
	    : orbit>= 85646605 && orbit<= 88362620 ? 425
	    : orbit>= 88525784 && orbit<= 91244037 ? 450
	    : orbit>= 91540489 && orbit<= 94394769 ? 350
	      : NOVAL_I;
	case 370169:
	  return
	    orbit>= 40342105 && orbit<= 43280163 ? 10
	    : orbit>= 43446024 && orbit<= 46163964 ? 25
	    : orbit>= 46360986 && orbit<= 49310460 ? 50
	    : orbit>= 49475797 && orbit<= 52185788 ? 75
	    : orbit>= 52352339 && orbit<= 55071756 ? 100
	    : orbit>= 55239247 && orbit<= 57948217 ? 125
	    : orbit>= 58115174 && orbit<= 60824770 ? 150
	    : orbit>= 60992420 && orbit<= 63706944 ? 175
	    : orbit>= 63845307 && orbit<= 66614001 ? 200
	    : orbit>= 66782084 && orbit<= 69473855 ? 225
	    : orbit>= 69641850 && orbit<= 72375108 ? 250
	    : orbit>= 72571092 && orbit<= 75528087 ? 275
	    : orbit>= 75722880 && orbit<= 78653907 ? 300
	    : orbit>= 78849747 && orbit<= 81532531 ? 320
	    : orbit>= 81672588 && orbit<= 84442221 ? 340
	    : orbit>= 84637613 && orbit<= 87569623 ? 360
	    : orbit>= 87737354 && orbit<= 90457916 ? 380
	    : orbit>= 90623611 && orbit<= 93355955 ? 400
	    : orbit>= 93522339 && orbit<= 96229970 ? 425
	    : orbit>= 96368015 && orbit<= 99098219 ? 450
	    : orbit>= 99434925 && orbit<= 102250856 ? 350
	      : NOVAL_I;
	case 370772:
	  return
	    orbit>= 52470445 && orbit<= 55333639 ? 10
	    : orbit>= 55472333 && orbit<= 58213155 ? 25
	    : orbit>= 58377241 && orbit<= 61089932 ? 50
	    : orbit>= 61256076 && orbit<= 63986325 ? 75
	    : orbit>= 64151875 && orbit<= 66856984 ? 100
	    : orbit>= 67024241 && orbit<= 69745556 ? 125
	    : orbit>= 69882848 && orbit<= 72642643 ? 150
	    : orbit>= 72780104 && orbit<= 75513072 ? 175
	    : orbit>= 75705636 && orbit<= 78389735 ? 200
	    : orbit>= 78527331 && orbit<= 81287919 ? 225
	    : orbit>= 81481429 && orbit<= 84417782 ? 250
	    : orbit>= 84582153 && orbit<= 87299914 ? 275
	    : orbit>= 87493915 && orbit<= 90188367 ? 300
	    : orbit>= 90382679 && orbit<= 93075344 ? 320
	    : orbit>= 93240739 && orbit<= 95958111 ? 340
	    : orbit>= 96127506 && orbit<= 98855902 ? 360
	    : orbit>= 98995097 && orbit<= 101722000 ? 380
	    : orbit>= 101919990 && orbit<= 104619178 ? 400
	    : orbit>= 104813521 && orbit<= 107747043 ? 425
	    : orbit>= 107916236 && orbit<= 110656907 ? 450
	    : orbit>= 110966804 && orbit<= 113797510 ? 350
	      : NOVAL_I;
	case 372597:
	  return
	    orbit>= 7903752 && orbit<= 13394769 ? 10
	    : orbit>= 13557899 && orbit<= 18905971 ? 25
	    : orbit>= 19067942 && orbit<= 24398996 ? 50
	    : orbit>= 24559026 && orbit<= 29910640 ? 75
	    : orbit>= 30098947 && orbit<= 35673648 ? 100
	    : orbit>= 35834767 && orbit<= 41184922 ? 125
	    : orbit>= 41347438 && orbit<= 46668343 ? 150
	    : orbit>= 46855827 && orbit<= 52173231 ? 175
	      : NOVAL_I;
	case 372598:
	  return
	    orbit>= 2746350 && orbit<= 8139349 ? 200
	    : orbit>= 8273753 && orbit<= 13650923 ? 225
	    : orbit>= 15111512 && orbit<= 20472285 ? 250
	      : NOVAL_I;
	case 372601:
	  return
	    orbit>= 490474 && orbit<= 6042138 ? 275
	    : orbit>= 6176244 && orbit<= 11549929 ? 300
	      : NOVAL_I;
	case 372602:
	  return
	    orbit>= 361535 && orbit<= 5785597 ? 320
	    : orbit>= 5948983 && orbit<= 11296711 ? 340
	    : orbit>= 11459733 && orbit<= 16786650 ? 360
	    : orbit>= 16923122 && orbit<= 22312993 ? 380
	    : orbit>= 22477745 && orbit<= 27808336 ? 400
	    : orbit>= 28000123 && orbit<= 33564939 ? 425
	    : orbit>= 33759233 && orbit<= 39083698 ? 450
	    : orbit>= 39385415 && orbit<= 44853027 ? 350
	      : NOVAL_I;
	case 375697:
	  return
	    orbit>= 14181054 && orbit<= 17056109 ? 10
	    : orbit>= 17275876 && orbit<= 20193293 ? 50
	    : orbit>= 20388031 && orbit<= 23095530 ? 100
	    : orbit>= 23289806 && orbit<= 26236248 ? 150
	    : orbit>= 26403276 && orbit<= 29104372 ? 200
	    : orbit>= 29271858 && orbit<= 32013840 ? 250
	    : orbit>= 32126302 && orbit<= 34880439 ? 275
	    : orbit>= 35047818 && orbit<= 37760914 ? 300
	    : orbit>= 37929290 && orbit<= 40658642 ? 320
	    : orbit>= 40852199 && orbit<= 43809979 ? 340
	    : orbit>= 43977324 && orbit<= 46666746 ? 360
	    : orbit>= 46832244 && orbit<= 49562209 ? 380
	    : orbit>= 49759108 && orbit<= 52723019 ? 400
	    : orbit>= 52860920 && orbit<= 55597269 ? 425
	    : orbit>= 55790859 && orbit<= 58751634 ? 450
	    : orbit>= 59029356 && orbit<= 61896178 ? 350
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_d1
  
  
  // Define Disk 2 Scans below
  int hv_d2(int run, int ls, int orbit, int ring) {
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
      //2017 May25 - FPix only
    case 295128:
      return
        orbit>= 28930462 && orbit<= 30717430 ? 20
        : orbit>= 32457066 && orbit<= 34197265 ? 40
        : orbit>= 35907256 && orbit<= 37678734 ? 60
        : orbit>= 39486371 && orbit<= 41250245 ? 80
        : orbit>= 42188777 && orbit<= 43924245 ? 100
        : orbit>= 45828839 && orbit<= 47579193 ? 125
        : orbit>= 96400768 && orbit<= 98255119 ? 10
	  : NOVAL_I;
    case 295130:
      return
        orbit>= 1504385 && orbit<= 3239211 ? 30
	  : NOVAL_I;
    case 295131:
      return
        orbit>= 1086058 && orbit<= 2849166 ? 50
        : orbit>= 4883221 && orbit<= 6660623 ? 70
        : orbit>= 8881952 && orbit<= 10668270 ? 90
	  : NOVAL_I;
    case 295132:
      return 150;
    case 303795:
      return
        orbit>= 74609916 && orbit<= 76349774 ? 100
        : orbit>= 76533019 && orbit<= 78187809 ? 150
        : orbit>= 78380432 && orbit<= 80038745 ? 200
        : orbit>= 80255784 && orbit<= 81885676 ? 250
        : orbit>= 82097207 && orbit<= 83743814 ? 350
        : orbit>= 51050070 && orbit<= 52540652 ? 300
	  : NOVAL_I;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 300
        : orbit>= 14315734 && orbit<= 15670544 ? 100
        : orbit>= 15863097 && orbit<= 17185585 ? 150
        : orbit>= 17378771 && orbit<= 18701788 ? 200
        : orbit>= 18894343 && orbit<= 20220649 ? 250
        : orbit>= 20412332 && orbit<= 21741408 ? 350
        : orbit>= 21907187 && orbit<= 23265703 ? 400
        : orbit>= 67303535 && orbit<= 68633680 ? 300
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 89689664 && orbit<= 92311119 ? 10
	    : orbit>= 92472812 && orbit<= 94927270 ? 20
	    : orbit>= 95120809 && orbit<= 97536875 ? 30
	    : orbit>= 97703946 && orbit<= 100168652 ? 40
	    : orbit>= 100334028 && orbit<= 102783139 ? 50
	    : orbit>= 102972115 && orbit<= 105406833 ? 60
	    : orbit>= 105594033 && orbit<= 108059073 ? 70
	    : orbit>= 108246648 && orbit<= 110908752 ? 80
	    : orbit>= 111095814 && orbit<= 113516127 ? 90
	    : orbit>= 113704728 && orbit<= 116158230 ? 100
	    : orbit>= 116345830 && orbit<= 118778641 ? 150
	    : orbit>= 118991865 && orbit<= 121399693 ? 200
	    : orbit>= 121481216 && orbit<= 124017418 ? 250
	    : orbit>= 124231352 && orbit<= 126620937 ? 300
	    : orbit>= 126840130 && orbit<= 129247729 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 25614942 && orbit<= 28068392 ? 125
	    : orbit>= 28261245 && orbit<= 30691838 ? 175
	    : orbit>= 30825898 && orbit<= 33304291 ? 225
	    : orbit>= 33569057 && orbit<= 36202926 ? 350
	      : NOVAL_I;
	case 320570:
	  return
	    orbit>= 3912124 && orbit<= 6576017 ? 20
	    : orbit>= 6739153 && orbit<= 9219039 ? 40
	    : orbit>= 9406451 && orbit<= 11820881 ? 60
	    : orbit>= 12008626 && orbit<= 14437338 ? 80
	    : orbit>= 14625889 && orbit<= 17098820 ? 100
	    : orbit>= 17260535 && orbit<= 19680876 ? 125
	    : orbit>= 19868619 && orbit<= 22292703 ? 150
	    : orbit>= 22481459 && orbit<= 24931178 ? 175
	    : orbit>= 25065836 && orbit<= 27546766 ? 200
	    : orbit>= 27706651 && orbit<= 30152915 ? 225
	    : orbit>= 30369098 && orbit<= 32798197 ? 250
	    : orbit>= 32986003 && orbit<= 35437784 ? 275
	    : orbit>= 35625697 && orbit<= 38024355 ? 300
	    : orbit>= 38213131 && orbit<= 40662809 ? 325
	    : orbit>= 40796989 && orbit<= 43264760 ? 350
	    : orbit>= 43425814 && orbit<= 45906240 ? 375
	    : orbit>= 46121187 && orbit<= 48813848 ? 400
	    : orbit>= 49136071 && orbit<= 49322439 ? 300
	      : NOVAL_I;
	case 355135:
	  return
	    orbit>= 60256175 && orbit<= 62938846 ? 10
	    : orbit>= 63065350 && orbit<= 65812399 ? 20
	    : orbit>= 65991787 && orbit<= 68710676 ? 30
	    : orbit>= 68889646 && orbit<= 71580864 ? 40
	    : orbit>= 71734812 && orbit<= 74456364 ? 50
	    : orbit>= 74610439 && orbit<= 77351083 ? 60
	    : orbit>= 77529784 && orbit<= 80228062 ? 70
	    : orbit>= 80279887 && orbit<= 83122171 ? 80
	    : orbit>= 83302626 && orbit<= 86002915 ? 90
	    : orbit>= 86157586 && orbit<= 88876708 ? 100
	    : orbit>= 89084382 && orbit<= 91769094 ? 150
	    : orbit>= 91821345 && orbit<= 94662176 ? 200
	    : orbit>= 94894817 && orbit<= 97804936 ? 250
	    : orbit>= 97984695 && orbit<= 100679171 ? 300
	    : orbit>= 100731058 && orbit<= 103566025 ? 400
	      : NOVAL_I;
	case 366451:
  if (ring==1) {
	  return
	    orbit>= 58699848 && orbit<= 61609564 ? 10
	    : orbit>= 61855050 && orbit<= 64768771 ? 50
	    : orbit>= 65015489 && orbit<= 67906385 ? 90
	    : orbit>= 68180112 && orbit<= 71046519 ? 130
	    : orbit>= 71291153 && orbit<= 74213289 ? 170
	    : orbit>= 74483037 && orbit<= 77340829 ? 210
	    : orbit>= 77582257 && orbit<= 80500459 ? 250
	    : orbit>= 80768423 && orbit<= 83635242 ? 280
	    : orbit>= 83903748 && orbit<= 86778734 ? 310
	    : orbit>= 86994641 && orbit<= 89925879 ? 330
	    : orbit>= 90166981 && orbit<= 93066380 ? 370
	    : orbit>= 93280876 && orbit<= 95967751 ? 390
	    : orbit>= 96237367 && orbit<= 99108516 ? 420
	    : orbit>= 99379543 && orbit<= 102262964 ? 450
	    : orbit>= 102641354 && orbit<= 105413326 ? 350
	      : NOVAL_I;
  }
  else if (ring==2) {
	  return
	    orbit>= 58699848 && orbit<= 61609564 ? 10
	    : orbit>= 61855050 && orbit<= 64768771 ? 40
	    : orbit>= 65015489 && orbit<= 67906385 ? 80
	    : orbit>= 68180112 && orbit<= 71046519 ? 120
	    : orbit>= 71291153 && orbit<= 74213289 ? 160
	    : orbit>= 74483037 && orbit<= 77340829 ? 200
	    : orbit>= 77582257 && orbit<= 80500459 ? 230
	    : orbit>= 80768423 && orbit<= 83635242 ? 260
	    : orbit>= 83903748 && orbit<= 86778734 ? 280
	    : orbit>= 86994641 && orbit<= 89925879 ? 320
	    : orbit>= 90166981 && orbit<= 93066380 ? 340
	    : orbit>= 93280876 && orbit<= 95967751 ? 370
	    : orbit>= 96237367 && orbit<= 99108516 ? 400
	    : orbit>= 99379543 && orbit<= 102262964 ? 430
	    : orbit>= 102641354 && orbit<= 105413326 ? 300
	      : NOVAL_I;
  }
    default:
      return NOVAL_I;
    }
  } // end hv_d2
  
  int hv_d3(int run, int ls, int orbit, int ring) {
    switch (run) {
      //2017 May25 - FPix only
    case 295128:
      return
        orbit>= 50124837 && orbit<= 51854658 ? 20
        : orbit>= 53841226 && orbit<= 55572281 ? 40
        : orbit>= 57359349 && orbit<= 59137883 ? 60
        : orbit>= 60956178 && orbit<= 62800951 ? 80
        : orbit>= 65028459 && orbit<= 66862336 ? 100
        : orbit>= 68514163 && orbit<= 70420790 ? 125
	  : NOVAL_I;
    case 295131:
      return
        orbit>= 13480958 && orbit<= 15224488 ? 10
        : orbit>= 17053698 && orbit<= 18825620 ? 30
        : orbit>= 20990373 && orbit<= 22749603 ? 50
        : orbit>= 25048580 && orbit<= 26859190 ? 70
        : orbit>= 29047979 && orbit<= 30785239 ? 90
	  : NOVAL_I;
    case 295132:
      return 150;
    case 306458:
      return
        orbit>= 3110498 && orbit<= 4434306 ? 300
        : orbit>= 23869216 && orbit<= 25219440 ? 100
        : orbit>= 25412179 && orbit<= 26740226 ? 150
        : orbit>= 26932231 && orbit<= 28276872 ? 200
        : orbit>= 28441837 && orbit<= 29804395 ? 250
        : orbit>= 29970783 && orbit<= 31324672 ? 350
        : orbit>= 31575328 && orbit<= 32923952 ? 400
        : orbit>= 67303535 && orbit<= 68633680 ? 300
	  : NOVAL_I;
	case 314650:
	  return
	    orbit>= 49203187 && orbit<= 51690032 ? 10
	    : orbit>= 51856967 && orbit<= 54283208 ? 20
	    : orbit>= 54445915 && orbit<= 56892967 ? 30
	    : orbit>= 57051839 && orbit<= 59538529 ? 40
	    : orbit>= 59697915 && orbit<= 62135204 ? 50
	    : orbit>= 62297225 && orbit<= 64782381 ? 60
	    : orbit>= 64943299 && orbit<= 67376977 ? 70
	    : orbit>= 67538741 && orbit<= 69999871 ? 80
	    : orbit>= 70139184 && orbit<= 72643799 ? 90
	    : orbit>= 72835854 && orbit<= 75255306 ? 100
	    : orbit>= 75446590 && orbit<= 77886498 ? 150
	    : orbit>= 78101351 && orbit<= 80773664 ? 200
	    : orbit>= 80938519 && orbit<= 83389351 ? 250
	    : orbit>= 83580458 && orbit<= 86015149 ? 300
	    : orbit>= 86258748 && orbit<= 88893999 ? 400
	      : NOVAL_I;
	case 314663:
	  return
	    orbit>= 14541227 && orbit<= 17055893 ? 125
	    : orbit>= 17244195 && orbit<= 19668685 ? 175
	    : orbit>= 19856002 && orbit<= 22294753 ? 225
	    : orbit>= 22585205 && orbit<= 25181837 ? 350
	      : NOVAL_I;
	case 315764:
	  return
	    orbit>= 39146638 && orbit<= 41719829 ? 10
	    : orbit>= 41825841 && orbit<= 44322177 ? 20
	    : orbit>= 44480767 && orbit<= 46948744 ? 30
	    : orbit>= 47135051 && orbit<= 49565502 ? 40
	    : orbit>= 49728746 && orbit<= 52187784 ? 50
	    : orbit>= 52322198 && orbit<= 54804994 ? 60
	    : orbit>= 54969957 && orbit<= 57440386 ? 70
	    : orbit>= 57553203 && orbit<= 60043347 ? 80
	    : orbit>= 60176652 && orbit<= 62671231 ? 90
	    : orbit>= 62830841 && orbit<= 65299490 ? 100
	    : orbit>= 65460761 && orbit<= 67931853 ? 125
	    : orbit>= 68119359 && orbit<= 70522726 ? 150
	    : orbit>= 70683404 && orbit<= 73153756 ? 175
	    : orbit>= 73311203 && orbit<= 75775055 ? 200
	    : orbit>= 75933126 && orbit<= 78397728 ? 225
	    : orbit>= 78988711 && orbit<= 81533957 ? 250
	      : NOVAL_I;
	case 316199:
	  return
	    orbit>= 24873392 && orbit<= 27280501 ? 10
	    : orbit>= 27391881 && orbit<= 29910318 ? 20
	    : orbit>= 30048261 && orbit<= 32528621 ? 30
	    : orbit>= 32692410 && orbit<= 35184550 ? 40
	    : orbit>= 35347550 && orbit<= 37766749 ? 50
	    : orbit>= 37964504 && orbit<= 40393240 ? 60
	    : orbit>= 40564372 && orbit<= 43001725 ? 70
	    : orbit>= 43111459 && orbit<= 45637231 ? 80
	    : orbit>= 45800722 && orbit<= 48263040 ? 90
	    : orbit>= 48454863 && orbit<= 50886070 ? 100
	    : orbit>= 51052187 && orbit<= 53510050 ? 125
	    : orbit>= 53672834 && orbit<= 56130806 ? 150
	    : orbit>= 56294595 && orbit<= 58752882 ? 175
	    : orbit>= 58889269 && orbit<= 61372970 ? 200
	    : orbit>= 61571382 && orbit<= 63995005 ? 225
	    : orbit>= 64601416 && orbit<= 67138847 ? 250
	    : orbit>= 67357410 && orbit<= 70015053 ? 300
	    : orbit>= 70179388 && orbit<= 72631784 ? 350
	    : orbit>= 72823108 && orbit<= 75250636 ? 400
	    : orbit>= 75639209 && orbit<= 75775182 ? 300
	      : NOVAL_I;
	case 316876:
	  return
	    orbit>= 44845878 && orbit<= 47472880 ? 10
	    : orbit>= 47613845 && orbit<= 50105260 ? 20
	    : orbit>= 50188211 && orbit<= 52709208 ? 30
	    : orbit>= 52895444 && orbit<= 55339608 ? 40
	    : orbit>= 55500867 && orbit<= 57952349 ? 50
	    : orbit>= 58141198 && orbit<= 60574900 ? 60
	    : orbit>= 60717816 && orbit<= 63221110 ? 70
	    : orbit>= 63329551 && orbit<= 65809487 ? 80
	    : orbit>= 65969746 && orbit<= 68435462 ? 90
	    : orbit>= 68575779 && orbit<= 71053332 ? 100
	    : orbit>= 71220080 && orbit<= 73688468 ? 125
	    : orbit>= 73877439 && orbit<= 76301206 ? 150
	    : orbit>= 76461185 && orbit<= 78925237 ? 175
	    : orbit>= 79058767 && orbit<= 81554007 ? 200
	    : orbit>= 81740951 && orbit<= 84170667 ? 225
	    : orbit>= 84770465 && orbit<= 87321138 ? 250
	    : orbit>= 87514391 && orbit<= 89930989 ? 300
	    : orbit>= 90122374 && orbit<= 92565760 ? 350
	    : orbit>= 92754465 && orbit<= 95185550 ? 400
	    : orbit>= 95563605 && orbit<= 95697795 ? 300
	      : NOVAL_I;
	case 317640:
	  return
	    orbit>= 45293973 && orbit<= 47719019 ? 10
	    : orbit>= 47854891 && orbit<= 50359955 ? 20
	    : orbit>= 50522239 && orbit<= 52977308 ? 30
	    : orbit>= 53113522 && orbit<= 55616572 ? 40
	    : orbit>= 55755315 && orbit<= 58228213 ? 50
	    : orbit>= 58372274 && orbit<= 60827613 ? 60
	    : orbit>= 60995674 && orbit<= 63463695 ? 70
	    : orbit>= 63631902 && orbit<= 66076490 ? 80
	    : orbit>= 66213020 && orbit<= 68722423 ? 90
	    : orbit>= 68890165 && orbit<= 71333543 ? 100
	    : orbit>= 71498800 && orbit<= 73941265 ? 125
	    : orbit>= 74129851 && orbit<= 76570264 ? 150
	    : orbit>= 76734342 && orbit<= 79189022 ? 175
	    : orbit>= 79329459 && orbit<= 81814529 ? 200
	    : orbit>= 82013635 && orbit<= 84419465 ? 225
	    : orbit>= 85001650 && orbit<= 87569257 ? 250
	    : orbit>= 87759543 && orbit<= 90188057 ? 300
	    : orbit>= 90323314 && orbit<= 92815992 ? 350
	    : orbit>= 92953354 && orbit<= 95441167 ? 400
	    : orbit>= 95791830 && orbit<= 95961670 ? 300
	      : NOVAL_I;
	case 319503:
	  return
	    orbit>= 7055894 && orbit<= 9459722 ? 10
	    : orbit>= 9566810 && orbit<= 12075322 ? 20
	    : orbit>= 12213121 && orbit<= 14717975 ? 30
	    : orbit>= 14853577 && orbit<= 17316216 ? 40
	    : orbit>= 17503961 && orbit<= 19935530 ? 50
	    : orbit>= 20071439 && orbit<= 22554342 ? 60
	    : orbit>= 22715316 && orbit<= 25193763 ? 70
	    : orbit>= 25355311 && orbit<= 27817230 ? 80
	    : orbit>= 27926532 && orbit<= 30416278 ? 90
	    : orbit>= 30527882 && orbit<= 33049984 ? 100
	    : orbit>= 33212050 && orbit<= 35664191 ? 125
	    : orbit>= 35826282 && orbit<= 38287417 ? 150
	    : orbit>= 38504148 && orbit<= 40914406 ? 175
	    : orbit>= 41077682 && orbit<= 43524088 ? 200
	    : orbit>= 43659205 && orbit<= 46161085 ? 225
	    : orbit>= 46728740 && orbit<= 49298332 ? 250
	    : orbit>= 49493037 && orbit<= 51915397 ? 300
	    : orbit>= 52049768 && orbit<= 54561617 ? 350
	    : orbit>= 54723510 && orbit<= 57164897 ? 400
	    : orbit>= 57487275 && orbit<= 57702598 ? 300
	      : NOVAL_I;
	case 321396:
	  return
	    orbit>= 1584551 && orbit<= 4205803 ? 10
	    : orbit>= 4370646 && orbit<= 6835331 ? 20
	    : orbit>= 6998249 && orbit<= 9443899 ? 30
	    : orbit>= 9603408 && orbit<= 12088965 ? 40
	    : orbit>= 12249948 && orbit<= 14691253 ? 50
	    : orbit>= 14824908 && orbit<= 17317702 ? 60
	    : orbit>= 17479610 && orbit<= 19929276 ? 70
	    : orbit>= 20117009 && orbit<= 22560727 ? 80
	    : orbit>= 22748255 && orbit<= 25191626 ? 90
	    : orbit>= 25299297 && orbit<= 27799610 ? 100
	    : orbit>= 27936056 && orbit<= 30437130 ? 125
	    : orbit>= 30629196 && orbit<= 33078612 ? 150
	    : orbit>= 33186971 && orbit<= 35673738 ? 175
	    : orbit>= 35860673 && orbit<= 38283804 ? 200
	    : orbit>= 38417265 && orbit<= 40915199 ? 225
	    : orbit>= 41076211 && orbit<= 43523705 ? 250
	    : orbit>= 43709569 && orbit<= 46158773 ? 300
	    : orbit>= 46346107 && orbit<= 48766767 ? 350
	    : orbit>= 48954620 && orbit<= 51396578 ? 400
	    : orbit>= 51746675 && orbit<= 51933237 ? 300
	      : NOVAL_I;
	case 322022:
	  return
	    orbit>= 60279961 && orbit<= 62943225 ? 10
	    : orbit>= 63075867 && orbit<= 65549032 ? 20
	    : orbit>= 65683169 && orbit<= 68178385 ? 30
	    : orbit>= 68339788 && orbit<= 70786533 ? 40
	    : orbit>= 70945624 && orbit<= 73405782 ? 50
	    : orbit>= 73539162 && orbit<= 76031847 ? 60
	    : orbit>= 76194593 && orbit<= 78661829 ? 70
	    : orbit>= 78793861 && orbit<= 81294346 ? 80
	    : orbit>= 81402558 && orbit<= 83913027 ? 90
	    : orbit>= 84019032 && orbit<= 86545026 ? 100
	    : orbit>= 86678270 && orbit<= 89173927 ? 125
	    : orbit>= 89360682 && orbit<= 91778781 ? 150
	    : orbit>= 91965880 && orbit<= 94679839 ? 175
	    : orbit>= 94865315 && orbit<= 97286456 ? 200
	    : orbit>= 97472797 && orbit<= 99884436 ? 225
	    : orbit>= 100098900 && orbit<= 102523723 ? 250
	    : orbit>= 102708961 && orbit<= 105133240 ? 300
	    : orbit>= 105290722 && orbit<= 107757020 ? 350
	    : orbit>= 107888477 && orbit<= 110382854 ? 400
	    : orbit>= 110727354 && orbit<= 110914389 ? 300
	      : NOVAL_I;
	case 322381:
	  return
	    orbit>= 55393118 && orbit<= 57952598 ? 10
	    : orbit>= 58114200 && orbit<= 60588212 ? 20
	    : orbit>= 60724340 && orbit<= 63202264 ? 30
	    : orbit>= 63340322 && orbit<= 65817097 ? 40
	    : orbit>= 65979355 && orbit<= 68425849 ? 50
	    : orbit>= 68561709 && orbit<= 71071128 ? 60
	    : orbit>= 71233215 && orbit<= 73688647 ? 70
	    : orbit>= 73852199 && orbit<= 76310213 ? 80
	    : orbit>= 76473584 && orbit<= 78927087 ? 90
	    : orbit>= 79093199 && orbit<= 81541766 ? 100
	    : orbit>= 81704609 && orbit<= 84163799 ? 125
	    : orbit>= 84355052 && orbit<= 86800517 ? 150
	    : orbit>= 86965497 && orbit<= 89409147 ? 175
	    : orbit>= 89572559 && orbit<= 92042263 ? 200
	    : orbit>= 92204778 && orbit<= 94675917 ? 225
	    : orbit>= 94838548 && orbit<= 97280347 ? 250
	    : orbit>= 97470307 && orbit<= 99890291 ? 300
	    : orbit>= 100079665 && orbit<= 102522741 ? 350
	    : orbit>= 102712865 && orbit<= 105177376 ? 400
	    : orbit>= 105524648 && orbit<= 105659424 ? 300
	      : NOVAL_I;
	case 323524:
	  return
	    orbit>= 40712834 && orbit<= 43310073 ? 10
	    : orbit>= 43422348 && orbit<= 45881929 ? 20
	    : orbit>= 46018056 && orbit<= 48516945 ? 30
	    : orbit>= 48678223 && orbit<= 51169750 ? 40
	    : orbit>= 51304556 && orbit<= 53771512 ? 50
	    : orbit>= 53932342 && orbit<= 56381384 ? 60
	    : orbit>= 56516448 && orbit<= 59011528 ? 70
	    : orbit>= 59200521 && orbit<= 61617940 ? 80
	    : orbit>= 61753974 && orbit<= 64253057 ? 90
	    : orbit>= 64390607 && orbit<= 66854828 ? 100
	    : orbit>= 67018750 && orbit<= 69485929 ? 125
	    : orbit>= 69648708 && orbit<= 72118854 ? 150
	    : orbit>= 72306340 && orbit<= 74742683 ? 175
	    : orbit>= 74932909 && orbit<= 77350840 ? 200
	    : orbit>= 77510220 && orbit<= 79977923 ? 225
	    : orbit>= 80140120 && orbit<= 82583218 ? 250
	    : orbit>= 82772153 && orbit<= 85219004 ? 300
	    : orbit>= 85380942 && orbit<= 87843975 ? 350
	    : orbit>= 88036981 && orbit<= 90452859 ? 400
	    : orbit>= 90754006 && orbit<= 90996042 ? 300
	      : NOVAL_I;
	case 324980:
	  return
	    orbit>= 50205057 && orbit<= 52700068 ? 10
	    : orbit>= 52868613 && orbit<= 55321785 ? 20
	    : orbit>= 55462104 && orbit<= 57973413 ? 30
	    : orbit>= 58087326 && orbit<= 60562624 ? 40
	    : orbit>= 60709545 && orbit<= 63210483 ? 50
	    : orbit>= 63359047 && orbit<= 65804852 ? 60
	    : orbit>= 65946954 && orbit<= 68434710 ? 70
	    : orbit>= 68605001 && orbit<= 71096881 ? 80
	    : orbit>= 71238107 && orbit<= 73690920 ? 90
	    : orbit>= 73860855 && orbit<= 76295804 ? 100
	    : orbit>= 76465735 && orbit<= 78930971 ? 125
	    : orbit>= 79102261 && orbit<= 81539075 ? 150
	    : orbit>= 81714638 && orbit<= 84171548 ? 175
	    : orbit>= 84349817 && orbit<= 86788381 ? 200
	    : orbit>= 86964660 && orbit<= 89396615 ? 225
	    : orbit>= 89567078 && orbit<= 92044434 ? 250
	    : orbit>= 92212873 && orbit<= 94683362 ? 300
	    : orbit>= 94878471 && orbit<= 97549671 ? 350
	    : orbit>= 97720736 && orbit<= 100166254 ? 400
	    : orbit>= 100483993 && orbit<= 100681077 ? 300
	      : NOVAL_I;
	case 326483:
	  return
	    ls>= 1 && ls<= 10 ? 10
	    : ls>= 20 && ls<=  40? 20
	    : ls>= 50 && ls<=  80? 30
	    : ls>= 100 && ls<= 110 ? 110
	    : ls>= 120 && ls<= 140 ? 120
	    : ls>= 150 && ls<= 180 ? 130
	      : NOVAL_I;
	case 352931:
	  return
	    orbit>= 1968481 && orbit<= 4736017 ? 10
	    : orbit>= 4784461 && orbit<= 7610810 ? 20
	    : orbit>= 7660060 && orbit<= 10511621 ? 30
	    : orbit>= 10562037 && orbit<= 13380721 ? 40
	    : orbit>= 13429646 && orbit<= 16268114 ? 50
	    : orbit>= 16390112 && orbit<= 19147855 ? 60
	    : orbit>= 19272670 && orbit<= 22032839 ? 70
	    : orbit>= 22082824 && orbit<= 24921952 ? 80
	    : orbit>= 25044824 && orbit<= 27805658 ? 90
	    : orbit>= 27855378 && orbit<= 30684689 ? 100
	    : orbit>= 30808993 && orbit<= 33579280 ? 125
	    : orbit>= 33629193 && orbit<= 36467115 ? 150
	    : orbit>= 36613893 && orbit<= 39337659 ? 175
	    : orbit>= 39386937 && orbit<= 42233511 ? 200
	    : orbit>= 42380958 && orbit<= 45108131 ? 225
	    : orbit>= 45157840 && orbit<= 47985532 ? 250
	    : orbit>= 48105844 && orbit<= 50885738 ? 275
	    : orbit>= 50934591 && orbit<= 53747920 ? 300
	    : orbit>= 53917558 && orbit<= 56637545 ? 350
	    : orbit>= 56686674 && orbit<= 59525018 ? 400
	    : orbit>= 59574993 && orbit<= 59797815 ? 300
	      : NOVAL_I;
	case 355135:
	  return
	    orbit>= 15379995 && orbit<= 18102008 ? 10
	    : orbit>= 18228854 && orbit<= 20978020 ? 20
	    : orbit>= 21156328 && orbit<= 23873234 ? 30
	    : orbit>= 23998387 && orbit<= 26745416 ? 40
	    : orbit>= 26921049 && orbit<= 29646696 ? 50
	    : orbit>= 29773853 && orbit<= 32514925 ? 60
	    : orbit>= 32641005 && orbit<= 35405111 ? 70
	    : orbit>= 35580839 && orbit<= 38281038 ? 80
	    : orbit>= 38409008 && orbit<= 41173172 ? 90
	    : orbit>= 41299853 && orbit<= 44066676 ? 100
	    : orbit>= 44293480 && orbit<= 47197273 ? 150
	    : orbit>= 47349961 && orbit<= 50098721 ? 200
	    : orbit>= 50325504 && orbit<= 53223044 ? 250
	    : orbit>= 53425185 && orbit<= 56126777 ? 300
	    : orbit>= 56408419 && orbit<= 59264438 ? 400
	      : NOVAL_I;
	case 357900:
	  return
	    orbit>= 12664081 && orbit<= 15486907 ? 10
	    : orbit>= 15566369 && orbit<= 18368115 ? 20
	    : orbit>= 18420230 && orbit<= 21247176 ? 30
	    : orbit>= 21378632 && orbit<= 24147295 ? 40
	    : orbit>= 24199731 && orbit<= 27025711 ? 50
	    : orbit>= 27077499 && orbit<= 29909218 ? 60
	    : orbit>= 29960548 && orbit<= 32790919 ? 70
	    : orbit>= 32843486 && orbit<= 35673003 ? 80
	    : orbit>= 35778744 && orbit<= 38555720 ? 90
	    : orbit>= 38608540 && orbit<= 41438736 ? 100
	    : orbit>= 41570546 && orbit<= 44324553 ? 125
	    : orbit>= 44455195 && orbit<= 47211734 ? 150
	    : orbit>= 47342579 && orbit<= 50093965 ? 175
	    : orbit>= 50251205 && orbit<= 52977181 ? 200
	    : orbit>= 53030010 && orbit<= 55863627 ? 225
	    : orbit>= 55916697 && orbit<= 58740975 ? 250
	    : orbit>= 58793298 && orbit<= 61624510 ? 275
	    : orbit>= 61784559 && orbit<= 64513818 ? 300
	    : orbit>= 64698513 && orbit<= 67393943 ? 350
	    : orbit>= 67551617 && orbit<= 70262612 ? 400
	    : orbit>= 70315602 && orbit<= 73150278 ? 300
	      : NOVAL_I;
	case 359571:
	  return
	    orbit>= 1598793 && orbit<= 4462108 ? 10
	    : orbit>= 4511395 && orbit<= 7350069 ? 20
	    : orbit>= 7399774 && orbit<= 10241564 ? 30
	    : orbit>= 10365345 && orbit<= 13132585 ? 40
	    : orbit>= 13255825 && orbit<= 15995781 ? 50
	    : orbit>= 16121215 && orbit<= 18899097 ? 60
	    : orbit>= 19022211 && orbit<= 21775984 ? 80
	    : orbit>= 21826416 && orbit<= 24672183 ? 100
	    : orbit>= 24722328 && orbit<= 27552047 ? 120
	    : orbit>= 27601834 && orbit<= 30433146 ? 140
	    : orbit>= 30557652 && orbit<= 33309141 ? 160
	    : orbit>= 33432366 && orbit<= 36193558 ? 180
	    : orbit>= 36243029 && orbit<= 39068178 ? 200
	    : orbit>= 39118463 && orbit<= 41969704 ? 225
	      : NOVAL_I;
	case 359575:
	  return
	    orbit>= 629737 && orbit<= 3422063 ? 250
	    : orbit>= 3548475 && orbit<= 6312050 ? 275
	    : orbit>= 6461056 && orbit<= 9196810 ? 325
	    : orbit>= 9348596 && orbit<= 12066809 ? 350
	    : orbit>= 12216331 && orbit<= 14954951 ? 375
	    : orbit>= 15107686 && orbit<= 17849142 ? 400
	    : orbit>= 18099677 && orbit<= 20986877 ? 300
	      : NOVAL_I;
	case 359998:
	  return
	    orbit>= 104875561 && orbit<= 107755135 ? 10
	    : orbit>= 107913968 && orbit<= 110630494 ? 20
	    : orbit>= 110788251 && orbit<= 113524201 ? 30
	    : orbit>= 113682052 && orbit<= 116420968 ? 40
	    : orbit>= 116550343 && orbit<= 119293351 ? 50
	    : orbit>= 119426118 && orbit<= 122178850 ? 60
	    : orbit>= 122336636 && orbit<= 125069620 ? 80
	    : orbit>= 125226412 && orbit<= 127952275 ? 100
	    : orbit>= 128057808 && orbit<= 130827303 ? 120
	    : orbit>= 130983638 && orbit<= 133718918 ? 140
	    : orbit>= 133823634 && orbit<= 136599596 ? 160
	    : orbit>= 136731343 && orbit<= 139480531 ? 180
	    : orbit>= 139610170 && orbit<= 142361614 ? 200
	    : orbit>= 142518456 && orbit<= 145248303 ? 225
	    : orbit>= 146982775 && orbit<= 149705976 ? 250
	    : orbit>= 149812001 && orbit<= 152574204 ? 275
	    : orbit>= 152707668 && orbit<= 155473411 ? 325
	    : orbit>= 155579472 && orbit<= 158344060 ? 350
	    : orbit>= 158503782 && orbit<= 161231425 ? 375
	    : orbit>= 161392164 && orbit<= 164109895 ? 400
	    : orbit>= 164399038 && orbit<= 167263402 ? 300
	      : NOVAL_I;
	case 360295:
	  return
	    orbit>= 250123817 && orbit<= 252997151 ? 10
	    : orbit>= 253130344 && orbit<= 255876427 ? 20
	    : orbit>= 256037677 && orbit<= 258760820 ? 30
	    : orbit>= 258895922 && orbit<= 261640771 ? 40
	    : orbit>= 261775735 && orbit<= 264513826 ? 50
	    : orbit>= 264621139 && orbit<= 267397855 ? 60
	    : orbit>= 267530956 && orbit<= 270282609 ? 80
	    : orbit>= 270417033 && orbit<= 273166939 ? 100
	    : orbit>= 273326940 && orbit<= 276051811 ? 120
	    : orbit>= 276185803 && orbit<= 278938988 ? 140
	    : orbit>= 279075317 && orbit<= 281832159 ? 160
	    : orbit>= 281965899 && orbit<= 284714222 ? 180
	    : orbit>= 284848582 && orbit<= 287602289 ? 200
	    : orbit>= 287735524 && orbit<= 290484727 ? 225
	    : orbit>= 290620075 && orbit<= 293353433 ? 250
	    : orbit>= 293460265 && orbit<= 296246415 ? 275
	    : orbit>= 296379312 && orbit<= 299138425 ? 325
	    : orbit>= 299301164 && orbit<= 302001233 ? 350
	    : orbit>= 302137056 && orbit<= 304881966 ? 375
	    : orbit>= 305042514 && orbit<= 307762219 ? 400
	    : orbit>= 308029792 && orbit<= 310911240 ? 300
	      : NOVAL_I;
	case 360796:
	  return
	    orbit>= 75646765 && orbit<= 78396600 ? 10
	    : orbit>= 78507985 && orbit<= 81277003 ? 20
	    : orbit>= 81385464 && orbit<= 84160318 ? 30
	    : orbit>= 84297227 && orbit<= 87050646 ? 40
	    : orbit>= 87186625 && orbit<= 89935156 ? 50
	    : orbit>= 90098419 && orbit<= 92830631 ? 60
	    : orbit>= 92967681 && orbit<= 95710970 ? 80
	    : orbit>= 95821281 && orbit<= 98586494 ? 100
	    : orbit>= 98719921 && orbit<= 101456347 ? 120
	    : orbit>= 101593245 && orbit<= 104351070 ? 140
	    : orbit>= 104512707 && orbit<= 107226276 ? 160
	    : orbit>= 107333521 && orbit<= 110118658 ? 180
	    : orbit>= 110228652 && orbit<= 112993580 ? 200
	    : orbit>= 113104333 && orbit<= 115892159 ? 225
	    : orbit>= 116055955 && orbit<= 118776123 ? 250
	    : orbit>= 118912464 && orbit<= 121643055 ? 275
	    : orbit>= 121808435 && orbit<= 124535570 ? 325
	    : orbit>= 124698262 && orbit<= 127419378 ? 350
	    : orbit>= 127525948 && orbit<= 130294767 ? 375
	    : orbit>= 130432704 && orbit<= 133198582 ? 400
	    : orbit>= 133472480 && orbit<= 136338129 ? 300
	      : NOVAL_I;
	case 361223:
	  return
	    orbit>= 38087387 && orbit<= 40918583 ? 10
	    : orbit>= 41051543 && orbit<= 43792557 ? 20
	    : orbit>= 43899276 && orbit<= 46692751 ? 30
	    : orbit>= 46801557 && orbit<= 49551982 ? 40
	    : orbit>= 49712638 && orbit<= 52437174 ? 50
	    : orbit>= 52517765 && orbit<= 55318121 ? 60
	    : orbit>= 55451536 && orbit<= 58222205 ? 80
	    : orbit>= 58329114 && orbit<= 61107309 ? 100
	    : orbit>= 61241257 && orbit<= 63972397 ? 120
	    : orbit>= 64107430 && orbit<= 66869015 ? 140
	    : orbit>= 67003578 && orbit<= 69740800 ? 160
	    : orbit>= 69877021 && orbit<= 72642959 ? 180
	    : orbit>= 72778246 && orbit<= 75522331 ? 200
	    : orbit>= 75658158 && orbit<= 78396727 ? 225
	    : orbit>= 78533017 && orbit<= 81279217 ? 250
	    : orbit>= 81441635 && orbit<= 84154693 ? 275
	    : orbit>= 84317433 && orbit<= 87037091 ? 325
	    : orbit>= 87173373 && orbit<= 89928279 ? 350
	    : orbit>= 90038254 && orbit<= 92820920 ? 375
	    : orbit>= 92984498 && orbit<= 95713653 ? 400
	    : orbit>= 95988057 && orbit<= 98845309 ? 300
	      : NOVAL_I;
	case 361475:
	  return
	    orbit>= 222110333 && orbit<= 224939149 ? 10
	    : orbit>= 225072545 && orbit<= 227809699 ? 20
	    : orbit>= 227970409 && orbit<= 230699599 ? 30
	    : orbit>= 230779861 && orbit<= 233595778 ? 40
	    : orbit>= 233703427 && orbit<= 236465704 ? 50
	    : orbit>= 236598359 && orbit<= 239360686 ? 60
	    : orbit>= 239493494 && orbit<= 242245761 ? 80
	    : orbit>= 242405079 && orbit<= 245128059 ? 100
	    : orbit>= 245285736 && orbit<= 248003579 ? 120
	    : orbit>= 248163112 && orbit<= 250881259 ? 140
	    : orbit>= 250985797 && orbit<= 253786244 ? 160
	    : orbit>= 253891737 && orbit<= 256655416 ? 180
	    : orbit>= 256787880 && orbit<= 259547532 ? 200
	    : orbit>= 259680999 && orbit<= 262420314 ? 225
	    : orbit>= 262551948 && orbit<= 265298416 ? 250
	    : orbit>= 265428875 && orbit<= 268195013 ? 275
	    : orbit>= 268380359 && orbit<= 271084430 ? 325
	    : orbit>= 271243461 && orbit<= 273967363 ? 350
	    : orbit>= 274125527 && orbit<= 276846908 ? 375
	    : orbit>= 277001884 && orbit<= 279718446 ? 400
	    : orbit>= 279980916 && orbit<= 282880383 ? 300
	      : NOVAL_I;
	case 361890:
	  return
	    orbit>= 3963493 && orbit<= 9459187 ? 10
	    : orbit>= 9564419 && orbit<= 14968438 ? 20
	    : orbit>= 15099769 && orbit<= 20474451 ? 30
	    : orbit>= 20579259 && orbit<= 25958161 ? 40
	    : orbit>= 26114369 && orbit<= 31484064 ? 50
	    : orbit>= 31641788 && orbit<= 36981269 ? 60
	    : orbit>= 37111781 && orbit<= 42498466 ? 80
	    : orbit>= 42630885 && orbit<= 47984783 ? 100
	    : orbit>= 48115296 && orbit<= 53504821 ? 120
	    : orbit>= 53660650 && orbit<= 59011469 ? 140
	    : orbit>= 59143042 && orbit<= 64514429 ? 160
	    : orbit>= 64673894 && orbit<= 70005563 ? 180
	    : orbit>= 70138844 && orbit<= 75510829 ? 200
	    : orbit>= 75642832 && orbit<= 81009063 ? 225
	    : orbit>= 81141608 && orbit<= 86536110 ? 250
	    : orbit>= 86643866 && orbit<= 92044401 ? 275
	    : orbit>= 92180485 && orbit<= 97528310 ? 325
	    : orbit>= 97636672 && orbit<= 103045464 ? 350
	    : orbit>= 103180825 && orbit<= 108550068 ? 375
	    : orbit>= 108712296 && orbit<= 114044835 ? 400
	    : orbit>= 114313672 && orbit<= 119810887 ? 300
	      : NOVAL_I;
	case 362617:
	  return
	    orbit>= 1675207 && orbit<= 4482307 ? 10
	    : orbit>= 4589516 && orbit<= 7345565 ? 25
	    : orbit>= 7503560 && orbit<= 10251143 ? 50
	    : orbit>= 10383641 && orbit<= 13118256 ? 75
	    : orbit>= 13251150 && orbit<= 16012285 ? 100
	    : orbit>= 16092002 && orbit<= 18904691 ? 120
	    : orbit>= 19064644 && orbit<= 21780375 ? 140
	    : orbit>= 21915491 && orbit<= 24647683 ? 160
	    : orbit>= 24781469 && orbit<= 27544216 ? 180
	    : orbit>= 27701105 && orbit<= 30425847 ? 200
	    : orbit>= 30531014 && orbit<= 33309354 ? 220
	    : orbit>= 33440550 && orbit<= 36205433 ? 240
	    : orbit>= 36311560 && orbit<= 39080353 ? 260
	    : orbit>= 39211611 && orbit<= 41966680 ? 280
	    : orbit>= 42123525 && orbit<= 44832214 ? 320
	    : orbit>= 44963600 && orbit<= 47738950 ? 340
	    : orbit>= 47870274 && orbit<= 50611790 ? 360
	    : orbit>= 50717573 && orbit<= 53483918 ? 380
	    : orbit>= 53643704 && orbit<= 56368187 ? 400
	    : orbit>= 56499465 && orbit<= 59266913 ? 425
	    : orbit>= 59529205 && orbit<= 62409575 ? 300
	      : NOVAL_I;
	case 365775:
	  return
	    orbit>= 11674141 && orbit<= 14429083 ? 200
	    : orbit>= 14589392 && orbit<= 17324633 ? 220
	    : orbit>= 17510902 && orbit<= 20196585 ? 240
	    : orbit>= 20383796 && orbit<= 23092362 ? 260
	    : orbit>= 23253989 && orbit<= 25982133 ? 280
	    : orbit>= 26197706 && orbit<= 29103790 ? 320
	    : orbit>= 29319343 && orbit<= 32255384 ? 340
	    : orbit>= 32444673 && orbit<= 35145650 ? 360
	    : orbit>= 35334294 && orbit<= 38017264 ? 380
	    : orbit>= 38180097 && orbit<= 40924604 ? 400
	    : orbit>= 41087244 && orbit<= 43808026 ? 425
	    : orbit>= 44514502 && orbit<= 47198988 ? 10
	    : orbit>= 47361806 && orbit<= 50091213 ? 25
	    : orbit>= 50255317 && orbit<= 52961410 ? 50
	    : orbit>= 53152818 && orbit<= 55865611 ? 75
	    : orbit>= 56057509 && orbit<= 59001403 ? 100
	    : orbit>= 59192755 && orbit<= 61877774 ? 120
	    : orbit>= 62043689 && orbit<= 64774124 ? 140
	    : orbit>= 64884831 && orbit<= 67653732 ? 160
	    : orbit>= 67791500 && orbit<= 70538399 ? 180
	    : orbit>= 70818655 && orbit<= 73668482 ? 300
	      : NOVAL_I;
	case 366451:
  if (ring==1) {
	  return
	    orbit>= 11427179 && orbit<= 14160940 ? 10
	    : orbit>= 14382455 && orbit<= 17324839 ? 50
	    : orbit>= 17573565 && orbit<= 20460932 ? 90
	    : orbit>= 20710526 && orbit<= 23611692 ? 130
	    : orbit>= 23862063 && orbit<= 26749131 ? 170
	    : orbit>= 26969444 && orbit<= 29902584 ? 210
	    : orbit>= 30175576 && orbit<= 33058196 ? 250
	    : orbit>= 33332287 && orbit<= 36185466 ? 280
	    : orbit>= 36408444 && orbit<= 39337900 ? 310
	    : orbit>= 39558702 && orbit<= 42481928 ? 330
	    : orbit>= 42732455 && orbit<= 45642756 ? 370
	    : orbit>= 45914551 && orbit<= 48781132 ? 390
	    : orbit>= 49056415 && orbit<= 51921275 ? 420
	    : orbit>= 52194942 && orbit<= 55078899 ? 450
	    : orbit>= 55408643 && orbit<= 58210178 ? 350
	      : NOVAL_I;
  }
  else if (ring==2) {
	  return
	    orbit>= 11427179 && orbit<= 14160940 ? 10
	    : orbit>= 14382455 && orbit<= 17324839 ? 40
	    : orbit>= 17573565 && orbit<= 20460932 ? 80
	    : orbit>= 20710526 && orbit<= 23611692 ? 120
	    : orbit>= 23862063 && orbit<= 26749131 ? 160
	    : orbit>= 26969444 && orbit<= 29902584 ? 200
	    : orbit>= 30175576 && orbit<= 33058196 ? 230
	    : orbit>= 33332287 && orbit<= 36185466 ? 260
	    : orbit>= 36408444 && orbit<= 39337900 ? 280
	    : orbit>= 39558702 && orbit<= 42481928 ? 320
	    : orbit>= 42732455 && orbit<= 45642756 ? 340
	    : orbit>= 45914551 && orbit<= 48781132 ? 370
	    : orbit>= 49056415 && orbit<= 51921275 ? 400
	    : orbit>= 52194942 && orbit<= 55078899 ? 430
	    : orbit>= 55408643 && orbit<= 58210178 ? 300
	      : NOVAL_I;
  }
	case 367262:
	  return
	    orbit>= 7099870 && orbit<= 9973319 ? 10
	    : orbit>= 10169046 && orbit<= 12852101 ? 25
	    : orbit>= 13040868 && orbit<= 15739671 ? 50
	    : orbit>= 15959748 && orbit<= 18892548 ? 75
	    : orbit>= 19083998 && orbit<= 21766757 ? 100
	    : orbit>= 21931959 && orbit<= 24652329 ? 120
	    : orbit>= 24817938 && orbit<= 27542550 ? 140
	    : orbit>= 27734239 && orbit<= 30417342 ? 160
	    : orbit>= 30608624 && orbit<= 33313703 ? 180
	    : orbit>= 33505478 && orbit<= 36453885 ? 200
	    : orbit>= 36587559 && orbit<= 39346964 ? 220
	    : orbit>= 39511702 && orbit<= 42230281 ? 240
	    : orbit>= 42366690 && orbit<= 45102527 ? 260
	    : orbit>= 45240256 && orbit<= 47984863 ? 280
	    : orbit>= 48176143 && orbit<= 50887425 ? 320
	    : orbit>= 51050647 && orbit<= 53762229 ? 340
	    : orbit>= 53954281 && orbit<= 56911774 ? 360
	    : orbit>= 57075795 && orbit<= 59793547 ? 380
	    : orbit>= 59929631 && orbit<= 62659588 ? 400
	    : orbit>= 62878057 && orbit<= 65827762 ? 425
	    : orbit>= 66128316 && orbit<= 68970973 ? 300
	      : NOVAL_I;
	case 367691:
	  return
	    orbit>= 38093805 && orbit<= 40915552 ? 10
	    : orbit>= 41110913 && orbit<= 44047646 ? 25
	    : orbit>= 44186753 && orbit<= 46929565 ? 50
	    : orbit>= 47125589 && orbit<= 49838059 ? 75
	    : orbit>= 50003212 && orbit<= 52705357 ? 100
	    : orbit>= 52896569 && orbit<= 55580803 ? 120
	      : NOVAL_I;
	case 367693:
	  return
	    orbit>= 1098110 && orbit<= 3945219 ? 120
	    : orbit>= 4135366 && orbit<= 6829305 ? 140
	      : NOVAL_I;
	case 367696:
	  return
	    orbit>= 3506414 && orbit<= 6308118 ? 160
	    : orbit>= 6506342 && orbit<= 9468137 ? 180
	    : orbit>= 9637017 && orbit<= 12338491 ? 200
	    : orbit>= 12533908 && orbit<= 15483844 ? 220
	    : orbit>= 15653641 && orbit<= 18355679 ? 240
	    : orbit>= 18555832 && orbit<= 21245305 ? 260
	    : orbit>= 21385589 && orbit<= 24127787 ? 280
	    : orbit>= 24298863 && orbit<= 27024565 ? 320
	    : orbit>= 27136462 && orbit<= 29892124 ? 340
	    : orbit>= 30062691 && orbit<= 32789318 ? 360
	    : orbit>= 32929346 && orbit<= 35656656 ? 380
	    : orbit>= 35826537 && orbit<= 38555859 ? 400
	    : orbit>= 38755411 && orbit<= 41712687 ? 425
	    : orbit>= 42025627 && orbit<= 44837160 ? 300
	      : NOVAL_I;
	case 368318:
	  return
	    orbit>= 38680055 && orbit<= 41436877 ? 10
	    : orbit>= 41571843 && orbit<= 44311348 ? 25
	    : orbit>= 44502309 && orbit<= 47205698 ? 50
	    : orbit>= 47421959 && orbit<= 50347521 ? 75
	    : orbit>= 50508280 && orbit<= 53224276 ? 100
	    : orbit>= 53385408 && orbit<= 56124453 ? 120
	    : orbit>= 56286132 && orbit<= 58997544 ? 140
	    : orbit>= 59161176 && orbit<= 61882440 ? 160
	    : orbit>= 62071686 && orbit<= 64759415 ? 180
	    : orbit>= 64977629 && orbit<= 67907945 ? 200
	    : orbit>= 68097540 && orbit<= 70786060 ? 220
	    : orbit>= 70948149 && orbit<= 73673465 ? 240
	    : orbit>= 73863541 && orbit<= 76551518 ? 260
	    : orbit>= 76713898 && orbit<= 79436967 ? 280
	    : orbit>= 79601241 && orbit<= 82331790 ? 320
	      : NOVAL_I;
	case 368320:
	  return
	    orbit>= 7296034 && orbit<= 10245784 ? 340
	    : orbit>= 10436831 && orbit<= 13120570 ? 360
	    : orbit>= 13256620 && orbit<= 16014083 ? 380
	    : orbit>= 16205744 && orbit<= 19147750 ? 400
	    : orbit>= 19340819 && orbit<= 22029462 ? 425
	    : orbit>= 22359114 && orbit<= 25197863 ? 300
	      : NOVAL_I;
	case 368636:
	  return
	    orbit>= 33385564 && orbit<= 36207914 ? 10
	    : orbit>= 36371515 && orbit<= 39085596 ? 25
	    : orbit>= 39249532 && orbit<= 41952787 ? 50
	    : orbit>= 42143811 && orbit<= 44832462 ? 75
	    : orbit>= 44995928 && orbit<= 47737091 ? 100
	    : orbit>= 47899342 && orbit<= 50615477 ? 120
	    : orbit>= 50751769 && orbit<= 53490218 ? 140
	    : orbit>= 53653665 && orbit<= 56365742 ? 160
	    : orbit>= 56528473 && orbit<= 59270226 ? 180
	    : orbit>= 59461047 && orbit<= 62411805 ? 200
	    : orbit>= 62548295 && orbit<= 65290140 ? 220
	    : orbit>= 65425227 && orbit<= 68169459 ? 240
	    : orbit>= 68331785 && orbit<= 71070912 ? 260
	    : orbit>= 71234301 && orbit<= 73930658 ? 280
	    : orbit>= 74121783 && orbit<= 76837685 ? 320
	    : orbit>= 76973011 && orbit<= 79706299 ? 340
	    : orbit>= 79868802 && orbit<= 82607141 ? 360
	    : orbit>= 82768510 && orbit<= 85484677 ? 380
	    : orbit>= 85646605 && orbit<= 88362620 ? 400
	    : orbit>= 88525784 && orbit<= 91244037 ? 425
	    : orbit>= 91540489 && orbit<= 94394769 ? 300
	      : NOVAL_I;
	case 370169:
	  return
	    orbit>= 40342105 && orbit<= 43280163 ? 10
	    : orbit>= 43446024 && orbit<= 46163964 ? 25
	    : orbit>= 46360986 && orbit<= 49310460 ? 50
	    : orbit>= 49475797 && orbit<= 52185788 ? 75
	    : orbit>= 52352339 && orbit<= 55071756 ? 100
	    : orbit>= 55239247 && orbit<= 57948217 ? 120
	    : orbit>= 58115174 && orbit<= 60824770 ? 140
	    : orbit>= 60992420 && orbit<= 63706944 ? 160
	    : orbit>= 63845307 && orbit<= 66614001 ? 180
	    : orbit>= 66782084 && orbit<= 69473855 ? 200
	    : orbit>= 69641850 && orbit<= 72375108 ? 220
	    : orbit>= 72571092 && orbit<= 75528087 ? 240
	    : orbit>= 75722880 && orbit<= 78653907 ? 260
	    : orbit>= 78849747 && orbit<= 81532531 ? 280
	    : orbit>= 81672588 && orbit<= 84442221 ? 320
	    : orbit>= 84637613 && orbit<= 87569623 ? 340
	    : orbit>= 87737354 && orbit<= 90457916 ? 360
	    : orbit>= 90623611 && orbit<= 93355955 ? 380
	    : orbit>= 93522339 && orbit<= 96229970 ? 400
	    : orbit>= 96368015 && orbit<= 99098219 ? 425
	    : orbit>= 99434925 && orbit<= 102250856 ? 300
	      : NOVAL_I;
	case 370772:
	  return
	    orbit>= 52470445 && orbit<= 55333639 ? 10
	    : orbit>= 55472333 && orbit<= 58213155 ? 25
	    : orbit>= 58377241 && orbit<= 61089932 ? 50
	    : orbit>= 61256076 && orbit<= 63986325 ? 75
	    : orbit>= 64151875 && orbit<= 66856984 ? 100
	    : orbit>= 67024241 && orbit<= 69745556 ? 120
	    : orbit>= 69882848 && orbit<= 72642643 ? 140
	    : orbit>= 72780104 && orbit<= 75513072 ? 160
	    : orbit>= 75705636 && orbit<= 78389735 ? 180
	    : orbit>= 78527331 && orbit<= 81287919 ? 200
	    : orbit>= 81481429 && orbit<= 84417782 ? 220
	    : orbit>= 84582153 && orbit<= 87299914 ? 240
	    : orbit>= 87493915 && orbit<= 90188367 ? 260
	    : orbit>= 90382679 && orbit<= 93075344 ? 280
	    : orbit>= 93240739 && orbit<= 95958111 ? 320
	    : orbit>= 96127506 && orbit<= 98855902 ? 340
	    : orbit>= 98995097 && orbit<= 101722000 ? 360
	    : orbit>= 101919990 && orbit<= 104619178 ? 380
	    : orbit>= 104813521 && orbit<= 107747043 ? 400
	    : orbit>= 107916236 && orbit<= 110656907 ? 425
	    : orbit>= 110966804 && orbit<= 113797510 ? 300
	      : NOVAL_I;
	case 372597:
	  return
	    orbit>= 7903752 && orbit<= 13394769 ? 10
	    : orbit>= 13557899 && orbit<= 18905971 ? 25
	    : orbit>= 19067942 && orbit<= 24398996 ? 50
	    : orbit>= 24559026 && orbit<= 29910640 ? 75
	    : orbit>= 30098947 && orbit<= 35673648 ? 100
	    : orbit>= 35834767 && orbit<= 41184922 ? 120
	    : orbit>= 41347438 && orbit<= 46668343 ? 140
	    : orbit>= 46855827 && orbit<= 52173231 ? 160
	      : NOVAL_I;
	case 372598:
	  return
	    orbit>= 2746350 && orbit<= 8139349 ? 180
	    : orbit>= 8273753 && orbit<= 13650923 ? 200
	    : orbit>= 15111512 && orbit<= 20472285 ? 220
	      : NOVAL_I;
	case 372601:
	  return
	    orbit>= 490474 && orbit<= 6042138 ? 240
	    : orbit>= 6176244 && orbit<= 11549929 ? 260
	      : NOVAL_I;
	case 372602:
	  return
	    orbit>= 361535 && orbit<= 5785597 ? 280
	    : orbit>= 5948983 && orbit<= 11296711 ? 320
	    : orbit>= 11459733 && orbit<= 16786650 ? 340
	    : orbit>= 16923122 && orbit<= 22312993 ? 360
	    : orbit>= 22477745 && orbit<= 27808336 ? 380
	    : orbit>= 28000123 && orbit<= 33564939 ? 400
	    : orbit>= 33759233 && orbit<= 39083698 ? 425
	    : orbit>= 39385415 && orbit<= 44853027 ? 300
	      : NOVAL_I;
	case 375697:
	  return
	    orbit>= 14181054 && orbit<= 17056109 ? 10
	    : orbit>= 17275876 && orbit<= 20193293 ? 50
	    : orbit>= 20388031 && orbit<= 23095530 ? 100
	    : orbit>= 23289806 && orbit<= 26236248 ? 140
	    : orbit>= 26403276 && orbit<= 29104372 ? 180
	    : orbit>= 29271858 && orbit<= 32013840 ? 220
	    : orbit>= 32126302 && orbit<= 34880439 ? 240
	    : orbit>= 35047818 && orbit<= 37760914 ? 260
	    : orbit>= 37929290 && orbit<= 40658642 ? 280
	    : orbit>= 40852199 && orbit<= 43809979 ? 320
	    : orbit>= 43977324 && orbit<= 46666746 ? 340
	    : orbit>= 46832244 && orbit<= 49562209 ? 360
	    : orbit>= 49759108 && orbit<= 52723019 ? 380
	    : orbit>= 52860920 && orbit<= 55597269 ? 400
	    : orbit>= 55790859 && orbit<= 58751634 ? 425
	    : orbit>= 59029356 && orbit<= 61896178 ? 300
	      : NOVAL_I;
    default:
      return NOVAL_I;
    }
  } // end hv_d3
  
  
  int bias_voltage(int hv_scan_no, int run, int ls, int orbit, int det, int lay, int disk, int ring, size_t l1_new_module) {
    if (hv_scan_no==-1) return det ? 300 : (run<238474 ? 150 : 200);
    return (det==1) ? ((disk==1) ? hv_d1(run, ls, orbit, ring) : (disk==2) ? hv_d2(run, ls, orbit, ring) : (disk==3) ? hv_d3(run, ls, orbit, ring) : NOVAL_I) :
      ((lay==1) ? hv_l1(run, ls, orbit, l1_new_module) : (lay==2) ? hv_l2(run, ls, orbit) : (lay==3) ? hv_l3(run, ls, orbit) : (lay==4) ? hv_l4(run, ls, orbit) : NOVAL_I);
  }
  
  bool is_full_hv_scan(int n, int layer, int sector, size_t shell) {
    
    //BPix_BpO Sec4 didn't participate in the following scan(s)
    if ((n==45||n==53||n==55||n==57) && !(layer==1 && sector==4 && shell==1)) return 1;
    return n==4||n==5||n==6||n==11||n==12||n==13||n==14||n==15||(n>=17&&n<=19)||n==22||n==23||n==24||n==25||n==26||n==27||n==28||n==29||n==35||n==43;

  }
  
  bool is_one_hv_group_scan(int hv_scan_no, int hv, bool det, int layer, int ladder, int module, int disk, int blade, int panel, int ring) {
    if (hv_scan_no==-1) return 0;
    if (hv==NOVAL_I) return 0;
    bool returnvalue=0;
    if (hv_scan_no==30 || hv_scan_no==31 || hv_scan_no==32 || hv_scan_no==33 || hv_scan_no==34) {
      if (det) {
        //FPix_BpO_D1_RNG1_ROG1
        if (disk==1 && ring==1 && blade<0 && blade>-4) returnvalue=1;
        //FPix_BmI_D3_RNG1_ROG3
        if (disk==-3 && ring==1) returnvalue= blade>5 && blade<9;
        if (disk==-3 && ring==2) returnvalue= blade>9 && blade<14;
      }
      else {
        //BPix_BmO_SEC2_LYR1 (3 modules; 1 is new (2018))
        if (layer==1) {
          if (ladder==-1 && module==-1) returnvalue= 1;
          if (ladder==-2 && module==-3) returnvalue= 1;
          if (ladder==-2 && module==-4) returnvalue= 1;
        }
        //BPix_BpI_SEC6_LYR2
        if (layer==2) returnvalue= module>0 && ladder==10;
        //BPix_BpO_SEC3_LYR3
        if (layer==3) returnvalue= module>0 && ladder<-5 && ladder>-9;
        //BPix_BmI_SEC3_LYR4
        if (layer==4) returnvalue= module<0 && ladder>8 && ladder<13;
      }
    }
    else if (hv_scan_no==29 || hv_scan_no==36 || hv_scan_no==37 || hv_scan_no==38 || hv_scan_no==39) {
      if (det) {
        //FPix_BpO_D1_RNG1_ROG1
        if (disk==1 && ring==1 && blade<0 && blade>-4) returnvalue=1;
        //FPix_BmI_D3_RNG1_ROG3
        if (disk==-3 && ring==1) returnvalue= blade>5 && blade<9;
        if (disk==-3 && ring==2) returnvalue= blade>9 && blade<14;
      }
      else {
        //BPix_BmO_SEC7_LYR1
        if (layer==1) {
          if (ladder==-5 && module==-1) returnvalue= 1;
          if (ladder==-5 && module==-2) returnvalue= 1;
          if (ladder==-6 && module==-4) returnvalue= 1;
        }
        //BPix_BpI_SEC6_LYR2
        if (layer==2) returnvalue= module>0 && ladder==10;
        //BPix_BpO_SEC3_LYR3
        if (layer==3) returnvalue= module>0 && ladder<-5 && ladder>-9;
        //BPix_BmI_SEC3_LYR4
        if (layer==4) returnvalue= module<0 && ladder>8 && ladder<13;
      }
    }
    else if (hv_scan_no==40 || hv_scan_no==41 || hv_scan_no==42|| hv_scan_no==44|| hv_scan_no==46|| hv_scan_no==47|| hv_scan_no==48|| hv_scan_no==49|| hv_scan_no==50|| hv_scan_no==51|| hv_scan_no==52|| hv_scan_no==54|| hv_scan_no==56|| hv_scan_no==58|| hv_scan_no==59|| hv_scan_no==60|| hv_scan_no==61|| hv_scan_no==62|| hv_scan_no==63|| hv_scan_no==64|| hv_scan_no==65) {
      if (det) {
        //FPix_BpO_D1_RNG1_ROG1
        if (disk==1 && ring==1 && blade<0 && blade>-4) returnvalue=1;
        //FPix_BmI_D3_RNG1_ROG3
        if (disk==-3 && ring==2) returnvalue= blade>9 && blade<14;
      }
      else {
        //BPix_BmO_SEC7_LYR1
        if (layer==1) {
          if (ladder==-5 && module==-1) returnvalue= 1;
          if (ladder==-5 && module==-2) returnvalue= 1;
          if (ladder==-6 && module==-4) returnvalue= 1;
        }
        //BPix_BpI_SEC6_LYR2
        if (layer==2) returnvalue= module>0 && ladder==10;
        //BPix_BpO_SEC3_LYR3
        if (layer==3) returnvalue= module>0 && ladder<-5 && ladder>-9;
        //BPix_BmI_SEC3_LYR4
        if (layer==4) returnvalue= module<0 && ladder>8 && ladder<13;
      }
    }
    return returnvalue;
  }
  
}// namespace scans
