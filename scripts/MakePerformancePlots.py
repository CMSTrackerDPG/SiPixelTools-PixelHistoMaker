import argparse
import os
import ROOT
import re
from math import sqrt

ROOT.gStyle.SetOptStat(0)

metadata = {
    #"TimingScan_0s": {
    #    "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2023/histos/PerformancePlots_Apr2023/Histos_0007.root",
    #    "int_lumi": 42,
    #    "fill": [8550],
    #    "bias": 400,
    #    "marker_color": ROOT.kRed+1,
    #    "marker_style": 20,
    #    "marker_syze": .5,
    #    "outname": "PerformancePlots_Apr2023",
    #    "sqrts": 900,
    #    "year": 2023,
    #    "legend": "Stable beams Apr2023",
    #    "write": True,
    #},
    #"Run_367337": {
    #    #"file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixeltest/Muon0_Tight_Run2023C_160523/Histos_0036.root",
    #    "file": "/work/bevila_t/EPR/my_fork/CMSSW_10_2_16_UL/src/SiPixelTools/PixelHistoMaker/Performances_run367337.root",
    #    "int_lumi": 46.3,
    #    "fill": [8746],
    #    "bias": 400,
    #    "marker_color": ROOT.kRed+1,
    #    "marker_style": 20,
    #    "marker_syze": .5,
    #    "outname": "PerformancePlots_May2023",
    #    "sqrts": 13.6,
    #    "year": 2023,
    #    "legend": "Run 367337",
    #    "write": True,
    #},
    # "Run_367413": {
    #     #"file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixeltest/Muon0_Tight_Run2023C_160523/Histos_0036.root",
    #     "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2023/histos/Muon01_Tight_Run2023C_010623/Histos_0036.root",
    #     "int_lumi": 46.9,
    #     "fill": [8754],
    #     "bias": 400,
    #     "marker_color": ROOT.kRed+1,
    #     "marker_style": 20,
    #     "marker_syze": .5,
    #     "outname": "PerformancePlots_May2023_Run367413",
    #     "sqrts": 13.6,
    #     "year": 2023,
    #     "legend": "Run 367413",
    #     "write": True,
    # },
    # "Run_368423": {
    #     #"file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixeltest/Muon0_Tight_Run2023C_160523/Histos_0036.root",
    #     "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2023/histos/Express_Tight_Run368423_060623/Histos_0001.root",
    #     "int_lumi": 56.2,
    #     "fill": [8754],
    #     "bias": 400,
    #     "marker_color": ROOT.kRed+1,
    #     "marker_style": 20,
    #     "marker_syze": .5,
    #     "outname": "PerformancePlots_May2023_Run368423",
    #     "sqrts": 13.6,
    #     "year": 2023,
    #     "legend": "Run 368423",
    #     "write": True,
    # },
    # "2023_EraC": {
    #     "file": "merged_Run3_2023C_150623.root",
    #     "start_int_lumi": 43.3,
    #     "int_lumi": 54.0,
    #     "fill": [8754],
    #     "bias": 400,
    #     "marker_color": ROOT.kBlue+1,
    #     "marker_style": 20,
    #     "marker_syze": .5,
    #     "outname": "PerformancePlots_May2023_EraC",
    #     "sqrts": 13.6,
    #     "year": 2023,
    #     "legend": "2023 EraC",
    #     "write": True,
    # }
    #"2024_EraC_Run379661": {
    #    "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon0_Run2024C_Tight/Histos_0014.root",
    #    "start_int_lumi": 76.2,
    #    "int_lumi": 76.3,
    #    "fill": [],
    #    "bias": 450,
    #    "marker_color": ROOT.kRed+1,
    #    "marker_style": 20,
    #    "marker_syze": .5,
    #    "outname": "PerformancePlots_May2024_Run379661",
    #    "sqrts": 13.6,
    #    "year": 2024,
    #    "legend": "Run 379661",
    #    "write": True,
    #},
    #"2024_EraB": {
    #    "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon0_Run2024B_Tight/merged/merged_manual/mergerd_manual_step2/merged_all.root",
    #    "start_int_lumi": 73.5,
    #    "int_lumi": 74.5,
    #    "fill": [],
    #    "bias": 450,
    #    "marker_color": ROOT.kRed+1,
    #    "marker_style": 20,
    #    "marker_syze": .5,
    #    "outname": "PerformancePlots_May2024_EraB",
    #    "sqrts": 13.6,
    #    "year": 2024,
    #    "legend": "2024 EraB",
    #    "write": True,
    #},
    #"2024_EraC": {
    #    "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon0_Run2024C_Tight/merged_manual/mergerd_manual_step2/merged_manual_step3/merged_merged_merged_total.root",
    #    "start_int_lumi": 74.5,
    #    "int_lumi": 81.1,
    #    "fill": [],
    #    "bias": 450,
    #    "marker_color": ROOT.kBlue+1,
    #    "marker_style": 20,
    #    "marker_syze": .5,
    #    "outname": "PerformancePlots_May2024_EraC",
    #    "sqrts": 13.6,
    #    "year": 2024,
    #    "legend": "2024 EraC",
    #    "write": True,
    #},
    #"2024_EraD": {
    #     "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon0_Run2024D_Tight/merged/merged/merged_merged_all.root",
    #     "start_int_lumi": 81.1,
    #     "int_lumi": 92.0,
    #     "fill": [],
    #     "bias": 450,
    #     "marker_color": ROOT.kGreen+1,
    #     "marker_style": 20,
    #     "marker_syze": .5,
    #     "outname": "PerformancePlots_May2024_EraD",
    #     "sqrts": 13.6,
    #     "year": 2024,
    #     "legend": "2024 EraD",
    #    "write": True,
    # },
    # "2024_EraE": {
    #      "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon0_Run2024E_Tight/merged/merged/merged/merged_merged_histo_all.root",
    #      "start_int_lumi": 92.0,
    #      "int_lumi": 104.24,
    #      "fill": [],
    #      "bias": 450,
    #      "marker_color": ROOT.kGreen+1,
    #      "marker_style": 20,
    #      "marker_syze": .5,
    #      "outname": "PerformancePlots_Nov2024_EraE",
    #      "sqrts": 13.6,
    #      "year": 2024,
    #      "legend": "2024 EraE",
    #     "write": True,
    #  },
    # "2024_EraF": {
    #      "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon0_Run2024F_Tight/merged/merged/merged/merged/merged_merged_all.root",
    #      "start_int_lumi": 104.24,
    #      "int_lumi": 134.71,
    #      "fill": [],
    #      "bias": 450,
    #      "marker_color": ROOT.kGreen+1,
    #      "marker_style": 20,
    #      "marker_syze": .5,
    #      "outname": "PerformancePlots_Nov2024_EraF",
    #      "sqrts": 13.6,
    #      "year": 2024,
    #      "legend": "2024 EraF",
    #     "write": True,
    #  },
    # "2024_EraG": {
    #      "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon01_Run2024G_Tight/merged/merged/merged/merged/merged/merged_all.root",
    #      "start_int_lumi": 134.71,
    #      "int_lumi": 177.55,
    #      "fill": [],
    #      "bias": 500,
    #      "marker_color": ROOT.kGreen+1,
    #      "marker_style": 20,
    #      "marker_syze": .5,
    #      "outname": "PerformancePlots_Nov2024_EraG",
    #      "sqrts": 13.6,
    #      "year": 2024,
    #      "legend": "2024 EraG",
    #     "write": True,
    #  },
    # "2024_EraH": {
    #      "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon01_Run2024H_Tight/merged/merged/merged/merged/merged_all.root",
    #      "start_int_lumi": 177.55,
    #      "int_lumi": 184.36,
    #      "fill": [],
    #      "bias": 550,
    #      "marker_color": ROOT.kGreen+1,
    #      "marker_style": 20,
    #      "marker_syze": .5,
    #      "outname": "PerformancePlots_Nov2024_EraH",
    #      "sqrts": 13.6,
    #      "year": 2024,
    #      "legend": "2024 EraH",
    #     "write": True,
    #  },
    # "2024_EraI": {
    #      "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon01_Run2024I_Tight/merged/merged/merged/merged/merged/merged_2024eraI_all.root",
    #      "start_int_lumi": 184.36,
    #      "int_lumi": 197.21,
    #      "fill": [],
    #      "bias": 550,
    #      "marker_color": ROOT.kGreen+1,
    #      "marker_style": 20,
    #      "marker_syze": .5,
    #      "outname": ".",
    #      "sqrts": 13.6,
    #      "year": 2024,
    #      "legend": "2024 EraI",
    #     "write": True,
    #  },
    # "fill_9614": {
    #     "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon0_Run2024D_Tight_fill9614/Muon0_Run2024D_fill9614_all.root",
    #     "start_int_lumi": 89.28,
    #     "int_lumi": 90.05,
    #     "fill": [],
    #     "bias": 450,
    #     "marker_color": ROOT.kBlue+1,
    #     "marker_style": 20,
    #     "marker_syze": .5,
    #     "outname": "PerformancePlots_May2024_fill_9614",
    #     "sqrts": 13.6,
    #     "year": 2024,
    #     "legend": "2024 EraC",
    #     "write": True,
    # }
    #     "2025_eraB": {
    #     "file": "/pnfs/psi.ch/cms/trivcat/store/user/nvassaki/pixel2025/histomaker/Muon01_2025B_new/merged/merged/merged/merged/merged_histos_0001.root",
    #     "start_int_lumi": 197.48,
    #     "int_lumi": 197.81,
    #     "fill": [],
    #     "bias": 450,
    #     "marker_color": ROOT.kBlue+1,
    #     "marker_style": 20,
    #     "marker_syze": .5,
    #     "outname": "PerformancePlots_2025_eraB",
    #     "sqrts": 13.6,
    #     "year": 2025,
    #     "legend": "2025 EraB",
    #     "write": True,
    # }
    # "Fill_10701": {
    #     "file": "/pnfs/psi.ch/cms/trivcat/store/user/nvassaki/pixel2025/histomaker/main_branch/Fill_10701/merged/merged_histos_0001.root",
    #     "start_int_lumi": 214.22,
    #     "int_lumi": 223.24,
    #     "fill": [],
    #     "bias": 600,
    #     "marker_color": ROOT.kBlue+1,
    #     "marker_style": 20,
    #     "marker_syze": .5,
    #     "outname": "PerformancePlots_Fill_10701",
    #     "sqrts": 13.6,
    #     "year": 2025,
    #     "legend": "2025 EraC_v2",
    #     "write": True,
    # }
    "Fill_11239": {
        "file": "/pnfs/psi.ch/cms/trivcat/store/user/nvassaki/pixel2025/histomaker/Run_398860/merged/merged_histos_0001.root",
        "start_int_lumi": 197.48,
        "int_lumi":322.02,
        "fill": [],
        "bias": 650,
        "marker_color": ROOT.kBlue+1,
        "marker_style": 20,
        "marker_syze": .5,
        "outname": "PerformancePlots_Fill_11239",
        "sqrts": 13.6,
        "year": 2025,
        "legend": "2025 EraG",
        "write": True,
    }
}

plotdict ={
    "dirs": {
        "NewHitEfficiency_vs_InstLumi":{
            "xtitle": "Instantaneous luminosity [x10^{33}cm^{-2}s^{-1}]",
            "ytitle": "Hit efficiency",
            "type": "hiteff",
            "ext": ["pdf", "root", "eps", "png"],
            "rebin": (False, 4),
        },
        "OnCluChargeNorm":{
            "xtitle": "Norm. on-trk clu. charge [ke]",
            "ytitle": "On-track clusters/0.5 ke",
            "type": "charge",
            "ext": ["pdf", "root", "eps", "png"],
            "rebin": (False, 2)
        },
        "OnCluSize":{
            "xtitle": "On-track cluster size [pixels]",
            "ytitle": "On-track clusters/1 pixel",
            "type": "size",
            "ext": ["pdf", "root", "eps", "png"],
            "rebin": (False, 2)
        },
        "OnCluSizeX":{
            "xtitle": "On-track cluster size x [pixels]",
            "ytitle": "On-track clusters/1 pixel",
            "ext": ["pdf", "root", "eps", "png"],
            "type": "size_x",
            "rebin": (False, 2)
        },
        "OnCluSizeY":{
            "xtitle": "On-track cluster size y [pixels]",
            "ytitle": "On-track clusters/1 pixel",
            "type": "size",
            "ext": ["pdf", "root", "eps", "png"],
            "rebin": (False, 2)
        },
        #"HitEfficiency_vs_Delay":{
        #    "xtitle": "Time Delay [ns]",
        #    "ytitle": "Hit Efficiency",
        #    "type": "eff",
        #    "rebin": (False, 2)
        #},
    },

    "plots":{
        "Layers_ALCARECOTight_allmuon": {
            "ranges_size_x": [0, 10, 0, 0.9],
            "ranges_size": [0, 20, 0, 0.6],
            "ranges_charge": [0, 60, 0, 0.08],
            "ranges_eff": [-10,10, 0.9, 1.05],
            "ranges_hiteff": [0,22, 0.9, 1.0],
            "leg_size": [0.5, 0.7, 0.7, 0.9],
            "leg_size_x": [0.5, 0.7, 0.7, 0.9],
            "leg_charge": [0.5, 0.7, 0.7, 0.9],
            "leg_hiteff": [0.5, 0.7, 0.3, 0.5],
            "legtitle": "BPIX",
        },
        #"Layers_ALCARECOTight_allmuon": {
        #    "ranges_size_x": [0, 10, 0, 0.8],
        #    "ranges_size": [0, 20, 0, 0.6],
        #    "ranges_charge": [0, 60, 0, 0.1],
        #    "ranges_eff": [-10,10, 0.9, 1.05],
        #    "ranges_hiteff": [0,20, 0.9, 1.05],
        #    "leg_size": [0.5, 0.7, 0.7, 0.9],
        #    "leg_size_x": [0.5, 0.7, 0.7, 0.9],
        #    "leg_charge": [0.5, 0.7, 0.7, 0.9],
        #    "leg_hiteff": [0.5, 0.7, 0.7, 0.9],
        #    "legtitle": "BPIX",
        #},
        "DisksRings_ALCARECOTight_allmuon": {
            "ranges_size_x": [0, 10, 0, 0.9],
            "ranges_size": [0, 10, 0, 0.8],
            "ranges_charge": [0, 60, 0, 0.08],
            "ranges_eff": [-10, 10, 0.9, 1.05],
            "ranges_hiteff": [0, 22, 0.9, 1.0],
            "leg_size": [0.5, 0.7, 0.6, 0.9],
            "leg_size_x": [0.5, 0.7, 0.6, 0.9],
            "leg_charge": [0.5, 0.7, 0.6, 0.9],
            "leg_hiteff": [0.5, 0.7, 0.3, 0.5],
            "legtitle": "FPIX",
        },
    },
}

# plots starting from canvas and fixing graphics
file = []
for j,filename in enumerate(metadata):
    file.append(ROOT.TFile.Open(metadata[filename]["file"]))
    for dir in plotdict["dirs"]:
        for plot in plotdict["plots"]:
            c = file[j].Get(dir+"/"+plot)
            c.SetCanvasSize(600,700)
            c.SetTitle("")
            leg = None
        
            for item in c.GetListOfPrimitives():
                if item.GetName()!="TPave":
                    item.SetTitle("")
                    if plotdict["dirs"][dir]["rebin"][0]:
                        item.Rebin(plotdict["dirs"][dir]["rebin"][1])
                    item.GetXaxis().SetRangeUser(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][0], plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][1])
                    item.GetXaxis().SetTitle(plotdict["dirs"][dir]["xtitle"])
                    item.GetYaxis().SetRangeUser(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][2], plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3])
                    item.GetYaxis().SetTitle(plotdict["dirs"][dir]["ytitle"])
                if item.GetName()=="TPave":
                    leg=item
                if leg != None:
                    leg.SetHeader(plotdict["plots"][plot]["legtitle"])
                    leg.SetX1(plotdict["plots"][plot]["leg_%s" % plotdict["dirs"][dir]["type"]][0])
                    leg.SetX2(plotdict["plots"][plot]["leg_%s" % plotdict["dirs"][dir]["type"]][1])
                    leg.SetY1(plotdict["plots"][plot]["leg_%s" % plotdict["dirs"][dir]["type"]][2])
                    leg.SetY2(plotdict["plots"][plot]["leg_%s" % plotdict["dirs"][dir]["type"]][3])


            CMS = ROOT.TLatex(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][0], plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]+(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]-plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][2])*0.03, "CMS#scale[0.75]{#font[52]{ Preliminary}}")
            CMS.SetLineWidth(2)
            CMS.Draw()
            era = ROOT.TLatex(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][1]*0.7, plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]+(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]-plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][2])*0.03, "#scale[0.7]{#font[40]{%s (%s TeV)}}" % (metadata[filename]["year"], metadata[filename]["sqrts"]) )
            era.SetLineWidth(1)
            era.Draw()
            if "Layers" in plot:
                bias = ROOT.TLatex(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][1]*0.55, plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]*0.4, "#scale[0.8]{Layer 1 HV = %d V}" % (metadata[filename]["bias"]))
                bias.SetLineWidth(1)
                bias.Draw()
            lumi = ROOT.TLatex(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][1]*0.6, plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]*0.5, "#scale[0.8]{#font[40]{#int Ldt = %s fb^{-1}}}" % metadata[filename]["int_lumi"])
            lumi.SetLineWidth(1)
            lumi.Draw()
            c.SetGridx()
            c.SetGridy()
            # c.Draw()
            if metadata[filename]["write"]:
                for ext in plotdict["dirs"][dir]["ext"]:
                    # print(ext, metadata[filename]["file"] )
                    c.SaveAs('plots/%s/%s_%s.%s' % (metadata[filename]["outname"], dir, plot.split("_")[0], ext))
            c.SaveAs('plots/%s/%s_%s.png' % (metadata[filename]["outname"], dir, plot.split("_")[0]))
            #c.SaveAs('plots/%s/%s_%s.png' % (metadata[filename]["outname"], dir, plot.split("_")[0]))

# plots starting from graphs and histos
key = "NewHitEfficiency_vs_LayersDisks/ALCARECOTight_allmuon"

c=ROOT.TCanvas()
c.SetCanvasSize(1500, 750)
hist = []
files = []
leg = ROOT.TLegend(0.47, 0.2, 0.6, 0.5)
for i,filename in enumerate(metadata):
    files.append(ROOT.TFile.Open(metadata[filename]["file"]))
    hist.append(files[i].Get(key))
    hist[i].SetTitle("")
    hist[i].Draw("P,SAME")
    hist[i].GetXaxis().SetLabelOffset(.005)
    hist[i].GetYaxis().SetLabelOffset(.005)
    hist[i].GetXaxis().SetLabelSize(.05)
    hist[i].GetYaxis().SetLabelSize(.035)
    hist[i].GetXaxis().SetTitleSize(.045)
    hist[i].GetYaxis().SetTitleSize(.045)
    hist[i].GetYaxis().SetTitleOffset(.9)
    hist[i].GetXaxis().SetRangeUser(0, 50)
    hist[i].GetYaxis().SetRangeUser(.95, 1.005)
    hist[i].SetMarkerColor(metadata[filename]["marker_color"])
    hist[i].SetLineColor(metadata[filename]["marker_color"])
    hist[i].SetMarkerStyle(metadata[filename]["marker_style"])
    leg.AddEntry(hist[i], '%s - %s /fb' % (metadata[filename]["legend"], metadata[filename]["int_lumi"]), 'p')
    leg.SetHeader("") 
    leg.SetFillColor(0)
    leg.SetFillStyle(0)
    leg.SetBorderSize(0)
    leg.SetTextSize(0.04)
    leg.Draw()
CMS = ROOT.TLatex(-0., 1.0075, "CMS#scale[0.8]{#font[52]{Preliminary}}")
CMS.SetLineWidth(2)
CMS.Draw()

era = ROOT.TLatex(9, 1.0075, "#scale[0.9]{#font[40]{Run 3 (13.6 TeV)} }")
era.SetLineWidth(1)
era.Draw()

c.SetGridx()
c.SetGridy()
# c.Draw()
c.SaveAs('plots/%s/%s_%s.png' % (metadata[filename]["outname"], filename, "HitEffvsLayersDisks"))

print('plots/%s/%s_%s.png' % (metadata[filename]["outname"], filename, "HitEffvsLayersDisks"))
        

key = "NewHitEfficiency_vs_BunchCrossing5/ALCARECOTight_allmuon_Lay1"

c=ROOT.TCanvas()
c.SetCanvasSize(2500, 750)
hist = []
files = []
leg = ROOT.TLegend(0.47, 0.2, 0.6, 0.5)
for i,filename in enumerate(metadata):
    files.append(ROOT.TFile.Open(metadata[filename]["file"]))
    hist.append(files[i].Get(key))
    hist[i].SetTitle("")
    hist[i].Draw("P,SAME")
    hist[i].GetXaxis().SetLabelOffset(.005)
    hist[i].GetYaxis().SetLabelOffset(.005)
    hist[i].GetXaxis().SetLabelSize(.05)
    hist[i].GetYaxis().SetLabelSize(.035)
    hist[i].GetXaxis().SetTitleSize(.045)
    hist[i].GetYaxis().SetTitleSize(.045)
    hist[i].GetYaxis().SetTitleOffset(.9)
    hist[i].GetXaxis().SetRangeUser(0, 50)
    hist[i].GetYaxis().SetRangeUser(.95, 1.005)
    hist[i].SetMarkerColor(metadata[filename]["marker_color"])
    hist[i].SetLineColor(metadata[filename]["marker_color"])
    hist[i].SetMarkerStyle(metadata[filename]["marker_style"])
CMS = ROOT.TLatex(-0., 1.0075, "CMS#scale[0.8]{#font[52]{Preliminary}}")
CMS.SetLineWidth(2)
CMS.Draw()

era = ROOT.TLatex(9, 1.0075, "#scale[0.9]{#font[40]{Run 3 (13.6 TeV)} }")
era.SetLineWidth(1)
era.Draw()
c.SetGridx()
c.SetGridy()
# c.Draw()
c.SaveAs('plots/%s/%s_%s.pdf' % (metadata[filename]["outname"], filename, "HitEffvsBunchCrossing"))

key = "NewHitEfficiency_vs_InstLumi/"

plots={
    "Lay1_ALCARECOTight_allmuon": {
            "marker_color": ROOT.kRed,
            "marker_style": 20,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Layer1"
        },
    "Disk1_ALCARECOTight_allmuon": {
            "marker_color": ROOT.kRed,
            "marker_style": 20,
            "marker_syze": .5,
            "legend": "Disk1"
        },
    "Lay2_ALCARECOTight_allmuon": {
            "marker_color": ROOT.kMagenta,
            "marker_style": 21,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Layer2"
        },
    "Disk2_ALCARECOTight_allmuon": {
            "marker_color": ROOT.kMagenta,
            "marker_style": 21,
            "marker_syze": .5,
            "legend": "Disk2"
        },
    "Lay3_ALCARECOTight_allmuon": {
            "marker_color": ROOT.kAzure,
            "marker_style": 22,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Layer3"
        },
    "Disk3_ALCARECOTight_allmuon": {
            "marker_color": ROOT.kAzure,
            "marker_style": 22,
            "marker_syze": .5,
            "legend": "Disk3"
        },
    "Lay4_ALCARECOTight_allmuon": {
            "marker_color": ROOT.kTeal-1,
            "marker_style": 23,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Layer4"
        }
}


#######################################
#             TREND PLOTS             #
#######################################

for filename in metadata:
    file = ROOT.TFile.Open(metadata[filename]["file"])
    c=ROOT.TCanvas('%s_LayersDisks_%s' % (key.split("/")[0], {key.split("/")[0]}), '%s_LayersDisks_%s' % (key.split("/")[0], {key.split("/")[0]}))
    c.SetCanvasSize(600,600)
    c.SetLeftMargin(0.15)
    c.SetBottomMargin(0.15)
    hist = []  
    leg = ROOT.TLegend(0.47, 0.15, 0.8, 0.45)
    leg.SetNColumns(2)
    for i,plot in enumerate(["Lay1_ALCARECOTight_allmuon", "Disk1_ALCARECOTight_allmuon", "Lay2_ALCARECOTight_allmuon", "Disk2_ALCARECOTight_allmuon", "Lay3_ALCARECOTight_allmuon", "Disk3_ALCARECOTight_allmuon", "Lay4_ALCARECOTight_allmuon"]):
        hist.append(file.Get(key+plot))
        print (plot)
        hist[i].SetTitle("")
        hist[i].Draw("P,SAME")
        hist[i].GetXaxis().SetLabelOffset(.005)
        hist[i].GetYaxis().SetLabelOffset(.005)
        hist[i].GetXaxis().SetLabelSize(.035)
        hist[i].GetYaxis().SetLabelSize(.03)
        hist[i].GetXaxis().SetTitleSize(.042)
        hist[i].GetYaxis().SetTitleSize(.042)
        hist[i].GetXaxis().SetTitleOffset(1.05)
        hist[i].GetYaxis().SetTitleOffset(1.35)
        hist[i].GetYaxis().SetTitle("Hit efficiency")
        hist[i].GetYaxis().SetRangeUser(.9, 1.005)
        hist[i].GetXaxis().SetRangeUser(0, 22)
        leg.AddEntry(hist[i], plots[plot]["legend"], 'pel')
    leg.SetHeader("")
    leg.SetFillColor(0)
    leg.SetFillStyle(0)
    leg.SetBorderSize(0)
    leg.SetTextSize(0.04)
    leg.Draw()
    CMS = ROOT.TLatex(-0., 1.01, "#scale[0.9]{CMS}#scale[0.7]{#font[52]{}}")
    CMS.SetLineWidth(2)
    CMS.Draw()
    era = ROOT.TLatex(15, 1.01, "#scale[0.75]{#font[40]{%s (13.6 TeV)}}" % (metadata[filename]["year"]))
    era.SetLineWidth(1)
    era.Draw()
    if "start_int_lumi" in metadata[filename]:
        lumi = ROOT.TLatex(8.5, 0.941, "#scale[0.8]{#font[40]{#int Ldt = %s - %s fb^{-1}}}" % (metadata[filename]["start_int_lumi"], metadata[filename]["int_lumi"]))
    else:
        lumi = ROOT.TLatex(8.5, 0.941, "#scale[0.8]{#font[40]{#int Ldt = %s fb^{-1}}}" % metadata[filename]["int_lumi"])
    lumi.SetLineWidth(1)
    lumi.Draw()
    c.SetGridx()
    c.SetGridy()
    # c.Draw()
    for ext in ["pdf", "root", "eps", "png"]:
        c.SaveAs('plots/%s/NewHitEfficiency_vs_InstLumi_LayersDisks.%s' % (metadata[filename]["outname"], ext))
    #file.Close()


#
key = "HitEfficiency_vs_IntLumiRunIII/"

plots={
    "2022Data_Lay1": {#"ALCARECOTight_allmuon_Lay1": {
            "marker_color": ROOT.kRed+1,
            "marker_style": 20,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Layer 1"
        },
    "2022Data_Lay2": {#"ALCARECOTight_allmuon_Lay2": {
            "marker_color": ROOT.kMagenta+2,
            "marker_style": 21,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Layer 2"
        },
    "2022Data_Lay3": {#"ALCARECOTight_allmuon_Lay3": {
            "marker_color": ROOT.kBlue+1,
            "marker_style": 22,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Layer 3"
        },
    "2022Data_Lay4": {#"ALCARECOTight_allmuon_Lay4": {
            "marker_color": ROOT.kCyan+2,
            "marker_style": 23,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Layer 4"
        }
}

metadata_int = {
    "Data Run3": {
        # "file": "merged_2022ToRun2023C_060623.root",
        #"file": "merged_Run3_2022_2023C_150623.root",
        #"file": "merged_Run3_2022_2023C_210623_2.root",
        #"int_lumi": 54.0,
        #"file": "Performance_merged_2022-2024C_3.root",
        #"int_lumi": 83, # 82.4
        #"file": "Performance_merged_2022-2024D.root",
        #"file": "PHM_PHASE1_out/Muon0_all_2022-2024F.root",
        #"file": "PHM_PHASE1_out/Muon01_Run2022_2024I_2.root",
        #"file": "merged_2022-2024eraI_all.root",
        # "file": "/pnfs/psi.ch/cms/trivcat/store/user/bevila_t/test2/phys/xpluscharm/pixel2024/histos/Muon01_merged_all_2022_2024I_250121.root",
        # "file": "/pnfs/psi.ch/cms/trivcat/store/user/nvassaki/pixel2025/histomaker/main_branch/merged_all_2022_2025C_v2.root",
        "file": "/pnfs/psi.ch/cms/trivcat/store/user/nvassaki/pixel2025/histomaker/Muon01_merged_all_2022_2025G2_251209.root",
        "int_lumi": 325, #275, #255 ,#224,#187,#135,# 92, # 82.4
        "fill": 9579,
        "peak_inst_lumi": 5.4,
        "bias":450,
        "marker_color": ROOT.kViolet-7,
        "marker_style": 25,
        "marker_syze": .5,
        "outname": "trends",
        "sqrts": 13.6,
        "year": 2025,
        "legend": "2025 EraG",
        "write": True,
    },
}
file = []
for j,filename in enumerate(metadata_int):
    file.append(ROOT.TFile.Open(metadata_int[filename]["file"]))
    c=ROOT.TCanvas('%s_Layers_run3' % (key.split("/")[0]), '%s_Layers_run3' % (key.split("/")[0]))
    c.SetCanvasSize(900,600)
    hist = []  
    leg = ROOT.TLegend(0.31, 0.15, 0.70, 0.4)
    leg.SetNColumns(2)
    for i,plot in enumerate(["2022Data_Lay1", "2022Data_Lay2", "2022Data_Lay3", "2022Data_Lay4"]):
        if i == 1: 
            bias_increase_=[10.94, 32.36, 38.65, 62.8, 136.76, 171.98, 197.52, 212.29,  274.39]
            bias_increase_run=[359014,361514,362520,369698]
            l_sep = []
            for k,ls in enumerate(bias_increase_):
                l_sep.append(ROOT.TLine(ls,0.89,ls,1.005) if k not in [0] else ROOT.TLine(ls,0.9604,ls,1.005))
                l_sep[k].SetLineWidth(1)
                l_sep[k].SetLineStyle(9)
                l_sep[k].SetLineColor(ROOT.kAzure)
                l_sep[k].Draw("SAME")
            leg.AddEntry(l_sep[0], "HV change", 'l')
        if i == 2:         
            gain_calib_lumi=[10.94, 13.87, 41.8, 73.55, 107.47,  197.56 ]
            gain_calib_run=[359211,359946,365777,371402]
            l_cal = []
            for k,ls in enumerate(gain_calib_lumi):
                l_cal.append(ROOT.TLine(ls,0.89,ls,1.005) if k != 0 else ROOT.TLine(ls,0.9,ls,0.9302))
                l_cal[k].SetLineWidth(1)
                l_cal[k].SetLineStyle(6)
                l_cal[k].SetLineColor(ROOT.kBlack)
                l_cal[k].Draw("SAME")
            leg.AddEntry(l_cal[0], "Gain calibration", 'l')
        if i == 3:
            stops_lumi=[10.93, 32.97, 74.2, 104.04,197.48, 223.24]
            stops_run=[361580 ]
            l_stop = []
            for k,ls in enumerate(stops_lumi):
                l_stop.append(ROOT.TLine(ls,0.89,ls,1.005) if k != 0 else ROOT.TLine(ls,0.9302,ls,0.9604))
                l_stop[k].SetLineWidth(1)
                l_stop[k].SetLineStyle(5)
                l_stop[k].SetLineColor(ROOT.kOrange+10)
                l_stop[k].Draw("SAME")
            leg.AddEntry(l_stop[0], "Technical stop", 'l')
            
        hist.append(file[j].Get(key+plot))
        
        hist[i].SetTitle("")
        # the bin at 0 is wrong, either i rerun over all files (not feasible) or I change the bin content to not show up
        hist[i].SetBinContent(1, 100)
        hist[i].Draw("P,SAME")
        hist[i].GetXaxis().SetLabelOffset(.005)
        hist[i].GetYaxis().SetLabelOffset(.005)
        hist[i].GetXaxis().SetLabelSize(.035)
        hist[i].GetYaxis().SetLabelSize(.035)
        hist[i].GetXaxis().SetTitleSize(.045)
        hist[i].GetXaxis().SetTitle("Delivered integrated luminosity [fb^{-1}]")
        hist[i].GetYaxis().SetTitle("Hit efficiency")
        hist[i].GetYaxis().SetTitleSize(.045)
        hist[i].GetYaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetRangeUser(0, metadata_int[filename]["int_lumi"])
        hist[i].GetYaxis().SetRangeUser(.89, 1.005)
        hist[i].SetMarkerColor(plots[plot]["marker_color"])
        hist[i].SetLineColor(plots[plot]["marker_color"])
        hist[i].SetMarkerStyle(plots[plot]["marker_style"])
        hist[i].SetMarkerSize(1)
        leg.AddEntry(hist[i], plots[plot]["legend"], 'pl') 

        if i == 3:
            winter_lumi=[41., 73.55,197.48]
            stops_run=[361580 ]
            l_winter = []
            for k,ls in enumerate(winter_lumi):
                if k == 1:
                    l_winter.append(ROOT.TLine(ls,0.95,ls,1.005))
                else:
                    l_winter.append(ROOT.TLine(ls,0.89,ls,1.005))
                l_winter[k].SetLineWidth(1)
                l_winter[k].SetLineStyle(1)
                l_winter[k].SetLineColor(ROOT.kBlack)
                l_winter[k].Draw("SAME")
        #     leg.AddEntry(l_cal[0], " ", '')

    # lines for CPE calibration
    cpe_calib_lumi = [ 10.94,  16.62 , 41.47,  48.09,  74.20 ,  198.79,  226.13, 266.44,  266.60,  296.74 ,  312.43 ]
    l_cpe = []
    for k, ls in enumerate(cpe_calib_lumi):
        # mimic gain-calib verticals, including the shorter first tick
        l_cpe.append(
            ROOT.TLine(ls, 0.89, ls, 1.005) if k != 0 else ROOT.TLine(ls, 0.9, ls, 1.005)
        )
        l_cpe[k].SetLineWidth(1)
        l_cpe[k].SetLineStyle(2)      
        l_cpe[k].SetLineColor(ROOT.kOrange+4) 
        l_cpe[k].Draw("SAME")
    leg.AddEntry(l_cpe[0], "CPE calibration", 'l')
  
    f1=ROOT.TF1("f1","x",0,metadata_int[filename]["int_lumi"])
    A1 = ROOT.TGaxis(0,1.005,metadata_int[filename]["int_lumi"],1.005,"f1",810,"-")
    A1.SetLabelSize(0)
    A1.SetLineWidth(1)
    A1.Draw("SAME")
    f2=ROOT.TF1("f2","x",0.9,1.005)
    A2 = ROOT.TGaxis(metadata_int[filename]["int_lumi"],0.9,metadata_int[filename]["int_lumi"],1.005,"f2",510,"+")
    A2.SetLabelSize(0)
    A2.SetLineWidth(1)
    A2.Draw("SAME")    
    
    leg.SetHeader("BPIX") 
    leg.SetFillColor(ROOT.kWhite)
    # leg.SetFillStyle(1)
    leg.SetBorderSize(1)
    leg.SetTextSize(0.034)
    leg.Draw()
    CMS = ROOT.TLatex(-0., 1.0075, "CMS#scale[0.8]{#font[52]{ Preliminary}}")
    CMS.SetLineWidth(2)
    CMS.Draw()
    era = ROOT.TLatex(237, 1.0075, "#scale[0.9]{#font[40]{Run 3 (13.6 TeV)}}")
    era.SetLineWidth(1)
    era.Draw()
    year2022 = ROOT.TLatex(1.5, 0.955, "#scale[0.75]{#font[40]{2022}}")
    year2022.SetLineWidth(1)
    year2022.Draw()
    year2023 = ROOT.TLatex(42.4, 0.955, "#scale[0.75]{#font[40]{2023}}")
    year2023.SetLineWidth(1)
    year2023.Draw()
    year2024 = ROOT.TLatex(74.5, 0.955, "#scale[0.75]{#font[40]{2024}}")
    year2024.SetLineWidth(1)
    year2024.Draw()
    year2025 = ROOT.TLatex(198.5, 0.955, "#scale[0.75]{#font[40]{2025}}")
    year2025.SetLineWidth(1)
    year2025.Draw()
    
    # c.Draw()
    for ext in ["pdf", "root", "eps", "png"]:
        c.SaveAs('plots/%s/%s_Layers_run3.%s' % (metadata_int[filename]["outname"], key.split("/")[0], ext))
    #file.Close()


# CHarge 

key = "AvgOnCluChargeNorm_vs_IntLumiRunIII/"

plots={
    "Lay1_2021Data": {
            "marker_color": ROOT.kRed+1,
            "marker_style": 20,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Layer 1" 
        },
    "Lay2_2021Data": {
            "marker_color": ROOT.kMagenta+2,
            "marker_style": 21,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Layer 2"
        },
    "Lay3_2021Data": {
            "marker_color": ROOT.kBlue+1,
            "marker_style": 22,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Layer 3"
        },
    "Lay4_2021Data": {
            "marker_color": ROOT.kCyan+2,
            "marker_style": 23,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Layer 4"
        }
}


file = []
for j,filename in enumerate(metadata_int):
    file.append(ROOT.TFile.Open(metadata_int[filename]["file"]))
    c=ROOT.TCanvas('%s_Layers_run3' % (key.split("/")[0]), '%s_Layers_run3' % (key.split("/")[0]))
    c.SetCanvasSize(900,600)
    hist = []  
    leg = ROOT.TLegend(0.15, 0.12, 0.525, 0.32)
    leg.SetNColumns(2)
    for i,plot in enumerate(["Lay1_2021Data", "Lay2_2021Data", "Lay3_2021Data", "Lay4_2021Data"]):
        if i == 1: 
            bias_increase_=[10.94, 32.36, 38.65, 62.8, 136.76, 171.98, 197.52, 212.29,  274.39 ]
            bias_increase_run=[359014, 361514, 362520, 369698]
            l_sep = []
            for k,ls in enumerate(bias_increase_):
                l_sep.append(ROOT.TLine(ls,23.5,ls,35) if k == 0 else ROOT.TLine(ls,0.,ls,35))
                l_sep[k].SetLineWidth(1)
                l_sep[k].SetLineStyle(9)
                l_sep[k].SetLineColor(ROOT.kAzure)
                l_sep[k].Draw("SAME")
            leg.AddEntry(l_sep[0], "HV change", 'l')
        if i == 2:         
            gain_calib_lumi=[10.94, 13.87, 41.8, 73.55, 107.47,  197.56 ]
            gain_calib_run=[359211,359946,365777,371402]
            l_cal = []
            for k,ls in enumerate(gain_calib_lumi):
                l_cal.append(ROOT.TLine(ls,0.,ls,11.6) if k == 0 else ROOT.TLine(ls,0.,ls,35))
                l_cal[k].SetLineWidth(1)
                l_cal[k].SetLineStyle(6)
                l_cal[k].SetLineColor(ROOT.kBlack)
                l_cal[k].Draw("SAME")
            leg.AddEntry(l_cal[0], "Gain calibration", 'l')
        if i == 3:
            stops_lumi=[10.93, 32.97, 74.2, 104.04, 223.24]
            stops_run=[361580 ]
            l_stop = []
            for k,ls in enumerate(stops_lumi):
                l_stop.append(ROOT.TLine(ls,11.6,ls,23.5) if k == 0 else ROOT.TLine(ls,0.,ls,35))
                l_stop[k].SetLineWidth(1)
                l_stop[k].SetLineStyle(5)
                l_stop[k].SetLineColor(ROOT.kOrange+10)
                l_stop[k].Draw("SAME")
            leg.AddEntry(l_stop[0], "Technical stop", 'l')
            
        hist.append(file[j].Get(key+plot))
        hist[i].SetTitle("")
        # the bin at 0 is wrong, either i rerun over all files (not feasible) or I change the bin content to not show up
        hist[i].SetBinContent(1, 100)
        hist[i].Draw("P,SAME")
        hist[i].GetXaxis().SetLabelOffset(.005)
        hist[i].GetYaxis().SetLabelOffset(.005)
        hist[i].GetXaxis().SetLabelSize(.035)
        hist[i].GetYaxis().SetLabelSize(.035)
        hist[i].GetXaxis().SetTitleSize(.045)
        hist[i].GetXaxis().SetTitle("Delivered integrated luminosity [fb^{-1}]")
        hist[i].GetYaxis().SetTitleSize(.045)
        hist[i].GetYaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetRangeUser(0, metadata_int[filename]["int_lumi"])
        hist[i].GetYaxis().SetRangeUser(0, 35)
        hist[i].SetMarkerColor(plots[plot]["marker_color"])
        hist[i].SetLineColor(plots[plot]["marker_color"])
        hist[i].SetMarkerStyle(plots[plot]["marker_style"])
        hist[i].SetMarkerSize(1)
        leg.AddEntry(hist[i], plots[plot]["legend"], 'pl')

        if i == 3:
            winter_lumi=[41., 73.55,197.48]
            stops_run=[361580 ]
            l_winter = []
            for k,ls in enumerate(winter_lumi):
                if k == 1:
                    l_winter.append(ROOT.TLine(ls,17.5,ls,35))
                else:
                    l_winter.append(ROOT.TLine(ls,0.0,ls,35))
                l_winter[k].SetLineWidth(1)
                l_winter[k].SetLineStyle(1)
                l_winter[k].SetLineColor(ROOT.kBlack)
                l_winter[k].Draw("SAME")
        #     leg.AddEntry(l_cal[0], " ", '')


    # lines for CPE calibration
    cpe_calib_lumi = [ 10.94,  16.62 , 41.47,  48.09,  74.20 ,  198.79 ,  226.13 , 266.44,  266.60, 296.74, 312.43 ]
    l_cpe = []
    for k, ls in enumerate(cpe_calib_lumi):
        # mimic gain-calib verticals, including the shorter first tick
        l_cpe.append(
            ROOT.TLine(ls,0, ls, 35.) if k != 0 else ROOT.TLine(ls, 0, ls, 35.)
        )
        l_cpe[k].SetLineWidth(1)
        l_cpe[k].SetLineStyle(2)      
        l_cpe[k].SetLineColor(ROOT.kOrange+4) 
        l_cpe[k].Draw("SAME")
    leg.AddEntry(l_cpe[0], "CPE calibration", 'l')
   
    f1=ROOT.TF1("f1","x",0,metadata_int[filename]["int_lumi"])
    A1 = ROOT.TGaxis(0,35,metadata_int[filename]["int_lumi"],35,"f1",810,"-")
    A1.SetLabelSize(0)
    A1.SetLineWidth(1)
    A1.Draw("SAME")
    f2=ROOT.TF1("f2","x",0,35)
    A2 = ROOT.TGaxis(metadata_int[filename]["int_lumi"],0,metadata_int[filename]["int_lumi"],35,"f2",610,"+")
    A2.SetLabelSize(0)
    A2.SetLineWidth(1)
    A2.Draw("SAME")    
    
    leg.SetHeader("BPIX") 
    leg.SetFillColor(ROOT.kWhite)
    # leg.SetFillStyle(1)
    leg.SetBorderSize(1)
    leg.SetTextSize(0.034)
    leg.Draw()
    CMS = ROOT.TLatex(-0., 35.95, "CMS#scale[0.8]{#font[52]{ Preliminary}}")
    CMS.SetLineWidth(2)
    CMS.Draw()
    era = ROOT.TLatex(237, 35.95, "#scale[0.9]{#font[40]{Run 3 (13.6 TeV)}}")
    era.SetLineWidth(1)
    era.Draw()
    year2022 = ROOT.TLatex(1.2, 31, "#scale[0.75]{#font[40]{2022}}")
    year2022.SetLineWidth(1)
    year2022.Draw()
    year2023 = ROOT.TLatex(42.3, 31, "#scale[0.75]{#font[40]{2023}}")
    year2023.SetLineWidth(1)
    year2023.Draw()
    year2024 = ROOT.TLatex(74.4, 31, "#scale[0.75]{#font[40]{2024}}")
    year2024.SetLineWidth(1)
    year2024.Draw()
    year2025 = ROOT.TLatex(198.5, 31, "#scale[0.75]{#font[40]{2025}}")
    year2025.SetLineWidth(1)
    year2025.Draw()   
    # c.Draw()
    for ext in ["pdf", "root", "eps", "png"]:
        c.SaveAs('plots/%s/%s_Layers_run3.%s' % (metadata_int[filename]["outname"], key.split("/")[0], ext))
    #file.Close()


# CLUSTER SIZE

key = "AvgOnCluSize_vs_IntLumiRunIII/"

plots={
    "Lay1_2021Data": {
            "marker_color": ROOT.kRed+1,
            "marker_style": 20,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": " Layer 1"
        },
    "Lay2_2021Data": {
            "marker_color": ROOT.kMagenta+2,
            "marker_style": 21,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": " Layer 2"
        },
    "Lay3_2021Data": {
            "marker_color": ROOT.kBlue+1,
            "marker_style": 22,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": " Layer 3"
        },
    "Lay4_2021Data": {
            "marker_color": ROOT.kCyan+2,
            "marker_style": 23,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": " Layer 4"
        }
}


file = []
for j,filename in enumerate(metadata_int):
    file.append(ROOT.TFile.Open(metadata_int[filename]["file"]))
    c=ROOT.TCanvas('%s_Layers_run3' % (key.split("/")[0]), '%s_Layers_run3' % (key.split("/")[0]))
    c.SetCanvasSize(900,600)
    hist = []  
    leg = ROOT.TLegend(0.19, 0.15, 0.58, 0.4)
    leg.SetNColumns(2)
    for i,plot in enumerate(["Lay1_2021Data", "Lay2_2021Data", "Lay3_2021Data", "Lay4_2021Data"]):
        if i == 1: 
            bias_increase_=[10.94, 32.36, 38.65, 62.8, 136.76, 171.98, 197.52, 212.29,  274.39]
            bias_increase_run=[359014,361514,362520,369698]
            l_sep = []
            for k,ls in enumerate(bias_increase_):
                l_sep.append(ROOT.TLine(ls,0.,ls,7) if k != 0 else ROOT.TLine(ls,4.66,ls,7.))
                l_sep[k].SetLineWidth(1)
                l_sep[k].SetLineStyle(9)
                l_sep[k].SetLineColor(ROOT.kAzure)
                l_sep[k].Draw("SAME")
            leg.AddEntry(l_sep[0], "HV change", 'l')
        if i == 2:         
            gain_calib_lumi=[10.94, 13.87, 41.8, 73.55, 107.47,  197.56 ]
            gain_calib_run=[359211,359946,365777,371402]
            l_cal = []
            for k,ls in enumerate(gain_calib_lumi):
                l_cal.append(ROOT.TLine(ls,0.,ls,7) if k != 0 else ROOT.TLine(ls,0.,ls,2.33))
                l_cal[k].SetLineWidth(1)
                l_cal[k].SetLineStyle(6)
                l_cal[k].SetLineColor(ROOT.kBlack)
                l_cal[k].Draw("SAME")
            leg.AddEntry(l_cal[0], "Gain calibration", 'l')
        if i == 3:
            stops_lumi=[10.93, 32.97, 74.2, 104.04, 223.24]
            stops_run=[361580 ]
            l_stop = []
            for k,ls in enumerate(stops_lumi):
                l_stop.append(ROOT.TLine(ls,0.,ls,7.) if k != 0 else ROOT.TLine(ls,2.33,ls,4.66))
                l_stop[k].SetLineWidth(1)
                l_stop[k].SetLineStyle(5)
                l_stop[k].SetLineColor(ROOT.kOrange+10)
                l_stop[k].Draw("SAME")
            leg.AddEntry(l_stop[0], "Technical stop", 'l')
            
        hist.append(file[j].Get(key+plot))
        hist[i].SetTitle("")
        # the bin at 0 is wrong, either i rerun over all files (not feasible) or I change the bin content to not show up
        hist[i].SetBinContent(1, 100)
        hist[i].Draw("P,SAME")
        hist[i].GetXaxis().SetLabelOffset(.005)
        hist[i].GetYaxis().SetLabelOffset(.005)
        hist[i].GetXaxis().SetLabelSize(.035)
        hist[i].GetYaxis().SetLabelSize(.035)
        hist[i].GetXaxis().SetTitleSize(.045)
        hist[i].GetXaxis().SetTitle("Delivered integrated luminosity [fb^{-1}]")
        hist[i].GetYaxis().SetTitleSize(.045)
        hist[i].GetYaxis().SetTitle("Avg. on-track clu. size [pixel]")
        hist[i].GetYaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetRangeUser(0, metadata_int[filename]["int_lumi"])
        hist[i].GetYaxis().SetRangeUser(0, 7)
        hist[i].SetMarkerColor(plots[plot]["marker_color"])
        hist[i].SetLineColor(plots[plot]["marker_color"])
        hist[i].SetMarkerStyle(plots[plot]["marker_style"])
        hist[i].SetMarkerSize(1)
        leg.AddEntry(hist[i], plots[plot]["legend"], 'pl')        
    
        if i == 3:
            winter_lumi=[41., 73.55,197.48]
            stops_run=[361580 ]
            l_winter = []
            for k,ls in enumerate(winter_lumi):
                if k == 1:
                    l_winter.append(ROOT.TLine(ls,3.5,ls,7))
                else:
                    l_winter.append(ROOT.TLine(ls,0.0,ls,7))
                l_winter[k].SetLineWidth(1)
                l_winter[k].SetLineStyle(1)
                l_winter[k].SetLineColor(ROOT.kBlack)
                l_winter[k].Draw("SAME")
        #     leg.AddEntry(l_cal[0], " ", '')


    # lines for CPE calibration
    cpe_calib_lumi = [ 10.94,  16.62 , 41.47,  48.09,  74.20 ,  198.79 ,  226.13  , 266.44,  266.60, 296.74 , 312.43 ]
    l_cpe = []
    for k, ls in enumerate(cpe_calib_lumi):
        # mimic gain-calib verticals, including the shorter first tick
        l_cpe.append(
            ROOT.TLine(ls, 0., ls, 7.) if k != 0 else ROOT.TLine(ls, 0., ls, 7.)
        )
        l_cpe[k].SetLineWidth(1)
        l_cpe[k].SetLineStyle(2)      
        l_cpe[k].SetLineColor(ROOT.kOrange+4) 
        l_cpe[k].Draw("SAME")
    leg.AddEntry(l_cpe[0], "CPE calibration", 'l')
  

    f1=ROOT.TF1("f1","x",0,metadata_int[filename]["int_lumi"])
    A1 = ROOT.TGaxis(0,7,metadata_int[filename]["int_lumi"],7,"f1",810,"-")
    A1.SetLabelSize(0)
    A1.SetLineWidth(1)
    A1.Draw("SAME")
    f2=ROOT.TF1("f2","x",0,7)
    A2 = ROOT.TGaxis(metadata_int[filename]["int_lumi"],0,metadata_int[filename]["int_lumi"],7,"f2",710,"+")
    A2.SetLabelSize(0)
    A2.SetLineWidth(1)
    A2.Draw("SAME")       
    
    leg.SetHeader("BPIX") 
    leg.SetFillColor(ROOT.kWhite)
    # leg.SetFillStyle(1)
    leg.SetBorderSize(1)
    leg.SetTextSize(0.034)
    leg.Draw()
    CMS = ROOT.TLatex(-0., 7.2, "CMS#scale[0.8]{#font[52]{ Preliminary}}")
    CMS.SetLineWidth(2)
    CMS.Draw()
    era = ROOT.TLatex(237, 7.2, "#scale[0.9]{#font[40]{Run 3 (13.6 TeV)}}")
    era.SetLineWidth(1)
    era.Draw()
    year2022 = ROOT.TLatex(1.2, 6.1, "#scale[0.75]{#font[40]{2022}}")
    year2022.SetLineWidth(1)
    year2022.Draw()
    year2023 = ROOT.TLatex(42.3, 6.1, "#scale[0.75]{#font[40]{2023}}")
    year2023.SetLineWidth(1)
    year2023.Draw()
    year2024 = ROOT.TLatex(74.4, 6.1, "#scale[0.75]{#font[40]{2024}}")
    year2024.SetLineWidth(1)
    year2024.Draw()
    year2025 = ROOT.TLatex(198.5,  6.1, "#scale[0.75]{#font[40]{2025}}")
    year2025.SetLineWidth(1)
    year2025.Draw()
    for ext in ["pdf", "root", "eps", "png"]:
        c.SaveAs('plots/%s/%s_Layers_run3.%s' % (metadata_int[filename]["outname"], key.split("/")[0], ext))
    #file.Close()




############################
#       Forward Pixel       #
############################

key = "AvgOnCluChargeNorm_vs_IntLumiRunIII/"

plots={
    "Disk1_2021Data": {
            "marker_color": 633,
            "marker_style": 20,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk 1"
        },
    "Disk2_2021Data": {
            "marker_color": 618,
            "marker_style": 21,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk 2"
        },
    "Disk3_2021Data": {
            "marker_color": 601,
            "marker_style": 22,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk 3"
        },
    "Diskm1_2021Data": {
            "marker_color": 799,
            "marker_style": 29,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk -1"
        },
    "Diskm2_2021Data": {
            "marker_color": 402,
            "marker_style": 24,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk -2"
        },
    "Diskm3_2021Data": {
            "marker_color": 417,
            "marker_style": 25,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk -3"
        }
}

for file_ in file: file_.Close()
file = []
for j,filename in enumerate(metadata_int):
    file.append(ROOT.TFile.Open(metadata_int[filename]["file"]))
    c=ROOT.TCanvas('%s_Disks_run3' % (key.split("/")[0]), '%s_Disks_run3' % (key.split("/")[0]))
    c.SetCanvasSize(900,600)
    hist = []  
    leg = ROOT.TLegend(0.11, 0.12, 0.41, 0.42)
    leg.SetNColumns(2)
    for i, plot in enumerate(["Disk1_2021Data", "Disk2_2021Data", "Disk3_2021Data", "Diskm1_2021Data", "Diskm2_2021Data", "Diskm3_2021Data",]):
        if i == 1:         
            gain_calib_lumi=[10.94, 13.87, 41.8, 73.55, 107.47,  197.56 ]
            gain_calib_run=[359211,359946,365777,371402]
            l_cal = []
            for k,ls in enumerate(gain_calib_lumi):
                l_cal.append(ROOT.TLine(ls,13.,ls,25) if k != 0 else ROOT.TLine(ls,19,ls,25))
                l_cal[k].SetLineWidth(1)
                l_cal[k].SetLineStyle(6)
                l_cal[k].SetLineColor(ROOT.kBlack)
                l_cal[k].Draw("SAME")
            leg.AddEntry(l_cal[0], "Gain calibration", 'l')
        elif i == 2:
            stops_lumi=[10.93, 32.97, 74.2, 104.04,197.48, 223.24]
            stops_run=[361580 ]
            l_stop = []
            for k,ls in enumerate(stops_lumi):
                l_stop.append(ROOT.TLine(ls,13,ls,25) if k != 0 else ROOT.TLine(ls,13.,ls,19))
                l_stop[k].SetLineWidth(1)
                l_stop[k].SetLineStyle(5)
                l_stop[k].SetLineColor(ROOT.kOrange+10)
                l_stop[k].Draw("SAME")
            leg.AddEntry(l_stop[0], "Technical stop", 'l')
        elif i == 5:
            winter_lumi=[41., 73.55,197.48]
            stops_run=[361580 ]
            l_winter = []
            for k,ls in enumerate(winter_lumi):
                if k == 1:
                    l_winter.append(ROOT.TLine(ls,19.,ls,25))
                else:
                    l_winter.append(ROOT.TLine(ls,13,ls,25))
                l_winter[k].SetLineWidth(1)
                l_winter[k].SetLineStyle(1)
                l_winter[k].SetLineColor(ROOT.kBlack)
                l_winter[k].Draw("SAME")
            leg.AddEntry(l_winter[0], " ", '')
        elif i == 4:
            # lines for CPE calibration
            cpe_calib_lumi = [ 10.94,  16.62 , 41.47,  48.09,  74.20 ,  198.79,  226.13 , 266.44,  266.60, 296.74, 312.43 ]
            l_cpe = []
            for k, ls in enumerate(cpe_calib_lumi):
                # mimic gain-calib verticals, including the shorter first tick
                l_cpe.append(
                    ROOT.TLine(ls, 13., ls, 25.)
                )
                l_cpe[k].SetLineWidth(1)
                l_cpe[k].SetLineStyle(2)      
                l_cpe[k].SetLineColor(ROOT.kOrange+4) 
                l_cpe[k].Draw("SAME")
            leg.AddEntry(l_cpe[0], "CPE calibration", 'l')
        elif i == 3: 
            bias_increase_=[93.78, 212.29, 274.39]
            bias_increase_run=[]
            l_sep = []
            for k,ls in enumerate(bias_increase_):
                l_sep.append(ROOT.TLine(ls,13,ls,25))
                l_sep[k].SetLineWidth(1)
                l_sep[k].SetLineStyle(9)
                l_sep[k].SetLineColor(ROOT.kAzure)
                l_sep[k].Draw("SAME")
            leg.AddEntry(l_sep[0], "HV change", 'l')
        elif i > 5:
            leg.AddEntry(l_sep[0], "  ", '')

        hist.append(file[j].Get(key+plot))
        hist[i].SetTitle("")
        # the bin at 0 is wrong, either i rerun over all files (not feasible) or I change the bin content to not show up
        hist[i].SetBinContent(1, 100)
        hist[i].Draw("P,SAME")
        hist[i].GetXaxis().SetLabelOffset(.005)
        hist[i].GetYaxis().SetLabelOffset(.005)
        hist[i].GetXaxis().SetLabelSize(.035)
        hist[i].GetYaxis().SetLabelSize(.035)
        hist[i].GetXaxis().SetTitleSize(.045)
        hist[i].GetXaxis().SetTitle("Delivered integrated luminosity [fb^{-1}]")
        hist[i].GetYaxis().SetTitleSize(.045)
        hist[i].GetYaxis().SetTitle("Avg. norm. on-track clu. charge [ke]")
        hist[i].GetYaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetRangeUser(0, metadata_int[filename]["int_lumi"])
        hist[i].GetYaxis().SetRangeUser(13, 25)
        hist[i].SetMarkerColor(plots[plot]["marker_color"])
        hist[i].SetLineColor(plots[plot]["marker_color"])
        hist[i].SetMarkerStyle(plots[plot]["marker_style"])
        hist[i].SetMarkerSize(1)
        leg.AddEntry(hist[i], plots[plot]["legend"], 'pl') 


    f1=ROOT.TF1("f1","x",0,metadata_int[filename]["int_lumi"])
    A1 = ROOT.TGaxis(0,25,metadata_int[filename]["int_lumi"],25,"f1",810,"-")
    A1.SetLabelSize(0)
    A1.SetLineWidth(1)
    A1.Draw("SAME")
    f2=ROOT.TF1("f2","x",13,25)
    A2 = ROOT.TGaxis(metadata_int[filename]["int_lumi"],13,metadata_int[filename]["int_lumi"],25,"f2",610,"+")
    A2.SetLabelSize(0)
    A2.SetLineWidth(1)
    A2.Draw("SAME")
    
    leg.SetHeader("FPIX") 
    leg.SetFillColor(ROOT.kWhite)
    # leg.SetFillStyle(1)
    leg.SetBorderSize(1)
    leg.SetTextSize(0.034)
    leg.Draw()
    CMS = ROOT.TLatex(-0., 25.2, "CMS#scale[0.8]{#font[52]{ Preliminary}}")
    CMS.SetLineWidth(2)
    CMS.Draw()
    era = ROOT.TLatex(237, 25.2, "#scale[0.9]{#font[40]{Run 3 (13.6 TeV)}}")
    era.SetLineWidth(1)
    era.Draw()
    year2022 = ROOT.TLatex(1.2, 24.2, "#scale[0.75]{#font[40]{2022}}")
    year2022.SetLineWidth(1)
    year2022.Draw()
    year2023 = ROOT.TLatex(42.3, 24.2, "#scale[0.75]{#font[40]{2023}}")
    year2023.SetLineWidth(1)
    year2023.Draw()
    year2024 = ROOT.TLatex(74.4, 24.2, "#scale[0.75]{#font[40]{2024}}")
    year2024.SetLineWidth(1)
    year2024.Draw()
    year2025 = ROOT.TLatex(198.5,  24.2, "#scale[0.75]{#font[40]{2025}}")
    year2025.SetLineWidth(1)
    year2025.Draw()
    for ext in ["pdf", "root", "eps", "png"]:
        c.SaveAs('plots/%s/%s_Disks_run3.%s' % (metadata_int[filename]["outname"], key.split("/")[0], ext))
    #file.Close()

################
# Cluster size #
################

key = "AvgOnCluSize_vs_IntLumiRunIII/"

plots={
    "Disk1_2021Data": {
            "marker_color": 633,
            "marker_style": 20,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk 1"
        },
    "Disk2_2021Data": {
            "marker_color": 618,
            "marker_style": 21,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk 2"
        },
    "Disk3_2021Data": {
            "marker_color": 601,
            "marker_style": 22,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk 3"
        },
    "Diskm1_2021Data": {
            "marker_color": 799,
            "marker_style": 29,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk -1"
        },
    "Diskm2_2021Data": {
            "marker_color": 402,
            "marker_style": 24,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk -2"
        },
    "Diskm3_2021Data": {
            "marker_color": 417,
            "marker_style": 25,
            "marker_syze": .5,
            "type": "charge_norm_1",
            "legend": "Disk -3"
        }
}

for file_ in file: file_.Close()
file = []
for j,filename in enumerate(metadata_int):
    file.append(ROOT.TFile.Open(metadata_int[filename]["file"]))
    c=ROOT.TCanvas('%s_Disks_run3' % (key.split("/")[0]), '%s_Disks_run3' % (key.split("/")[0]))
    c.SetCanvasSize(900,600)
    hist = []  
    leg = ROOT.TLegend(0.45, 0.12, 0.85, 0.42)
    leg.SetNColumns(2)
    for i,plot in enumerate(["Disk1_2021Data", "Disk2_2021Data", "Disk3_2021Data", "Diskm1_2021Data", "Diskm2_2021Data", "Diskm3_2021Data",]):
        if i == 1:         
            gain_calib_lumi=[10.94, 13.87, 41.8, 73.55, 107.47,  197.56 ]
            gain_calib_run=[359211,359946,365777,371402]
            l_cal = []
            for k,ls in enumerate(gain_calib_lumi):
                l_cal.append(ROOT.TLine(ls,1.,ls,3) if k != 0 else ROOT.TLine(ls,2.,ls,3))
                l_cal[k].SetLineWidth(1)
                l_cal[k].SetLineStyle(6)
                l_cal[k].SetLineColor(ROOT.kBlack)
                l_cal[k].Draw("SAME")
            leg.AddEntry(l_cal[0], "Gain calibration", 'l')
        if i == 2:
            stops_lumi=[10.93, 32.97, 74.2, 104.04, 197.48, 223.24]
            stops_run=[361580 ]
            l_stop = []
            for k,ls in enumerate(stops_lumi):
                l_stop.append(ROOT.TLine(ls,1,ls,3.) if k != 0 else ROOT.TLine(ls,1.,ls,2))
                l_stop[k].SetLineWidth(1)
                l_stop[k].SetLineStyle(5)
                l_stop[k].SetLineColor(ROOT.kOrange+10)
                l_stop[k].Draw("SAME")
            leg.AddEntry(l_stop[0], "Technical stop", 'l')
        if i == 4:
            # lines for CPE calibration
            cpe_calib_lumi = [ 10.94,  16.62 , 41.47,  48.09,  74.20 ,  198.79,  226.13 , 266.44,  266.60, 296.74, 312.43 ]
            l_cpe = []
            for k, ls in enumerate(cpe_calib_lumi):
                # mimic gain-calib verticals, including the shorter first tick
                l_cpe.append(
                    ROOT.TLine(ls, 1., ls, 3.)
                )
                l_cpe[k].SetLineWidth(1)
                l_cpe[k].SetLineStyle(2)      
                l_cpe[k].SetLineColor(ROOT.kOrange+4) 
                l_cpe[k].Draw("SAME")
            leg.AddEntry(l_cpe[0], "CPE calibration", 'l')
        if i == 5:
            winter_lumi=[41., 73.55,197.48]
            stops_run=[361580 ]
            l_winter = []
            for k,ls in enumerate(winter_lumi):
                if k == 1:
                    l_winter.append(ROOT.TLine(ls,2,ls,3))
                else:
                    l_winter.append(ROOT.TLine(ls,1,ls,3))
                l_winter[k].SetLineWidth(1)
                l_winter[k].SetLineStyle(1)
                l_winter[k].SetLineColor(ROOT.kBlack)
                l_winter[k].Draw("SAME")
            leg.AddEntry(l_cal[0], " ", '')
        if i == 3: 
            bias_increase_=[93.78,212.29, 274.39]
            bias_increase_run=[]
            l_sep = []
            for k,ls in enumerate(bias_increase_):
                l_sep.append(ROOT.TLine(ls,1,ls,3))
                l_sep[k].SetLineWidth(1)
                l_sep[k].SetLineStyle(9)
                l_sep[k].SetLineColor(ROOT.kAzure)
                l_sep[k].Draw("SAME")
            leg.AddEntry(l_sep[0], "HV change", 'l')
        if i > 5:
            leg.AddEntry(l_cal[0], " ", '')
            
        hist.append(file[j].Get(key+plot))
        hist[i].SetTitle("")
        # the bin at 0 is wrong, either i rerun over all files (not feasible) or I change the bin content to not show up
        hist[i].SetBinContent(1, 100)
        hist[i].Draw("P,SAME")

        hist[i].GetXaxis().SetLabelOffset(.005)
        hist[i].GetYaxis().SetLabelOffset(.005)
        hist[i].GetXaxis().SetLabelSize(.035)
        hist[i].GetYaxis().SetLabelSize(.035)
        hist[i].GetXaxis().SetTitleSize(.045)
        hist[i].GetXaxis().SetTitle("Delivered integrated luminosity [fb^{-1}]")
        hist[i].GetYaxis().SetTitleSize(.045)
        hist[i].GetYaxis().SetTitle("Avg. on-track clu. size [pixel]")
        hist[i].GetYaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetRangeUser(0, metadata_int[filename]["int_lumi"])
        hist[i].GetYaxis().SetRangeUser(1, 3.)
        hist[i].SetMarkerColor(plots[plot]["marker_color"])
        hist[i].SetLineColor(plots[plot]["marker_color"])
        hist[i].SetMarkerStyle(plots[plot]["marker_style"])
        hist[i].SetMarkerSize(1)
        leg.AddEntry(hist[i], plots[plot]["legend"], 'pl')
 
    
    f1=ROOT.TF1("f1","x",0,metadata_int[filename]["int_lumi"])
    A1 = ROOT.TGaxis(0,3,metadata_int[filename]["int_lumi"],3,"f1",810,"-")
    A1.SetLabelSize(0)
    A1.SetLineWidth(1)
    A1.Draw("SAME")
    f2=ROOT.TF1("f2","x",1,3)
    A2 = ROOT.TGaxis(metadata_int[filename]["int_lumi"],1,metadata_int[filename]["int_lumi"],3,"f2",710,"+")
    A2.SetLabelSize(0)
    A2.SetLineWidth(1)
    A2.Draw("SAME")
    
    leg.SetHeader("FPIX") 
    leg.SetFillColor(ROOT.kWhite)
    # leg.SetFillStyle(1)
    leg.SetBorderSize(1)
    leg.SetTextSize(0.034)
    leg.Draw()
    CMS = ROOT.TLatex(-0., 3.065, "CMS#scale[0.8]{#font[52]{ Preliminary}}")
    CMS.SetLineWidth(2)
    CMS.Draw()
    era = ROOT.TLatex(237, 3.065, "#scale[0.9]{#font[40]{Run 3 (13.6 TeV)}}")
    era.SetLineWidth(1)
    era.Draw()
    year2022 = ROOT.TLatex(1.2, 2.82, "#scale[0.75]{#font[40]{2022}}")
    year2022.SetLineWidth(1)
    year2022.Draw()
    year2023 = ROOT.TLatex(42.3, 2.82, "#scale[0.75]{#font[40]{2023}}")
    year2023.SetLineWidth(1)
    year2023.Draw()
    year2024 = ROOT.TLatex(74.4, 2.82, "#scale[0.75]{#font[40]{2024}}")
    year2024.SetLineWidth(1)
    year2024.Draw()
    year2025 = ROOT.TLatex(198.5, 2.82, "#scale[0.75]{#font[40]{2025}}")
    year2025.SetLineWidth(1)
    year2025.Draw()
    for ext in ["pdf", "root", "eps", "png"]:
        c.SaveAs('plots/%s/%s_Disks_run3.%s' % (metadata_int[filename]["outname"], key.split("/")[0], ext))
    #file.Close()

##################
# Hit Efficiency #
##################

key = "HitEfficiency_vs_IntLumiRunIII/"

plots={
    "2022Data_Disk1": {#"ALCARECOTight_allmuon_Disk1": {
            "marker_color": 633,
            "marker_style": 20,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Disk 1"
        },
    "2022Data_Disk2": {#"ALCARECOTight_allmuon_Disk2": {
            "marker_color": 618,
            "marker_style": 21,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Disk 2"
        },
    "2022Data_Disk3": {#"ALCARECOTight_allmuon_Disk3": {
            "marker_color": 601,
            "marker_style": 22,
            "marker_syze": .5,
            "type": "HE_vs_Eta",
            "legend": "Disk 3"
        }
}

file = []
for j,filename in enumerate(metadata_int):
    file.append(ROOT.TFile.Open(metadata_int[filename]["file"]))
    c=ROOT.TCanvas('%s_Disks_run3' % (key.split("/")[0]), '%s_Disks_run3' % (key.split("/")[0]))
    c.SetCanvasSize(900,600)
    hist = []  
    leg = ROOT.TLegend(0.58, 0.15, 0.88, 0.44)

    legend_cal = None
    legend_stop = None
    legend_sep = None
    legend_cpe = None
    
    for i,plot in enumerate(plots):
        if i == 1:         
            gain_calib_lumi=[10.94, 13.87, 41.8, 73.55, 107.47,  197.56 ]
            gain_calib_run=[359211,359946,365777,371402]
            l_cal = []
            for k,ls in enumerate(gain_calib_lumi):
                l_cal.append(ROOT.TLine(ls,0.9,ls,1.005) if k != 0 else ROOT.TLine(ls,0.9525,ls,1.005))
                l_cal[k].SetLineWidth(1)
                l_cal[k].SetLineStyle(6)
                l_cal[k].SetLineColor(ROOT.kBlack)
                l_cal[k].Draw("SAME")
            legend_cal = l_cal[0]
        elif i == 2:
            stops_lumi=[10.93, 32.97, 74.2, 104.04,197.48, 223.24]
            stops_run=[361580 ]
            l_stop = []
            for k,ls in enumerate(stops_lumi):
                l_stop.append(ROOT.TLine(ls,0.9,ls,1.005) if k != 0 else ROOT.TLine(ls,0.9,ls,0.9525))
                l_stop[k].SetLineWidth(1)
                l_stop[k].SetLineStyle(5)
                l_stop[k].SetLineColor(ROOT.kOrange+10)
                l_stop[k].Draw("SAME")
            legend_stop = l_stop[0]

            # lines for CPE calibration
            cpe_calib_lumi = [ 10.94,  16.62 , 41.47,  48.09,  74.20 ,  198.79 ,  226.13 , 266.44,  266.60, 296.74 , 312.43]
            l_cpe = []
            for k, ls in enumerate(cpe_calib_lumi):
                # mimic gain-calib verticals, including the shorter first tick
                l_cpe.append(
                    ROOT.TLine(ls, 0.9, ls, 1.005)
                )
                l_cpe[k].SetLineWidth(1)
                l_cpe[k].SetLineStyle(2)      
                l_cpe[k].SetLineColor(ROOT.kOrange+4) 
                l_cpe[k].Draw("SAME")
            legend_cpe = l_cpe[0]
        if i > 3:
            leg.AddEntry(l_cal[0], " ", '')
            
        hist.append(file[j].Get(key+plot))
        print(key+plot)
        
        hist[i].SetTitle("")
        # the bin at 0 is wrong, either i rerun over all files (not feasible) or I change the bin content to not show up
        hist[i].SetBinContent(1, 100)
        hist[i].Draw("P,SAME")
        hist[i].GetXaxis().SetLabelOffset(.005)
        hist[i].GetYaxis().SetLabelOffset(.005)
        hist[i].GetXaxis().SetLabelSize(.035)
        hist[i].GetYaxis().SetLabelSize(.035)
        hist[i].GetXaxis().SetTitleSize(.045)
        hist[i].GetXaxis().SetTitle("Delivered integrated luminosity [fb^{-1}]")
        hist[i].GetYaxis().SetTitle("Hit efficiency")
        hist[i].GetYaxis().SetTitleSize(.045)
        hist[i].GetYaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetTitleOffset(.9)
        hist[i].GetXaxis().SetRangeUser(0, metadata_int[filename]["int_lumi"])
        hist[i].GetYaxis().SetRangeUser(.9, 1.005)
        hist[i].SetMarkerColor(plots[plot]["marker_color"])
        hist[i].SetLineColor(plots[plot]["marker_color"])
        hist[i].SetMarkerStyle(plots[plot]["marker_style"])
        hist[i].SetMarkerSize(1)
        leg.AddEntry(hist[i], plots[plot]["legend"], 'pl') 

        if i == 2:
            winter_lumi=[41., 73.55,197.48]
            stops_run=[361580 ]
            l_winter = []
            for k,ls in enumerate(winter_lumi):
                if k == 1:
                    l_winter.append(ROOT.TLine(ls,0.95,ls,1.005))
                else:
                    l_winter.append(ROOT.TLine(ls,0.9,ls,1.005))
                l_winter[k].SetLineWidth(1)
                l_winter[k].SetLineStyle(1)
                l_winter[k].SetLineColor(ROOT.kBlack)
                l_winter[k].Draw("SAME")
            bias_increase_=[93.78, 212.29, 274.39]
            bias_increase_run=[]
            l_sep = []
            for k,ls in enumerate(bias_increase_):
                l_sep.append(ROOT.TLine(ls,0.9,ls,1.005))
                l_sep[k].SetLineWidth(1)
                l_sep[k].SetLineStyle(9)
                l_sep[k].SetLineColor(ROOT.kAzure)
                l_sep[k].Draw("SAME")
            legend_sep = l_sep[0]

    if legend_cal:
        leg.AddEntry(legend_cal, "Gain calibration", 'l')
    if legend_stop:
        leg.AddEntry(legend_stop, "Technical stop", 'l')
    if legend_sep:
        leg.AddEntry(legend_sep, "HV change", 'l')
    if legend_cpe:
        leg.AddEntry(legend_cpe, "CPE calibration", 'l')

    f1=ROOT.TF1("f1","x",0,metadata_int[filename]["int_lumi"])
    A1 = ROOT.TGaxis(0,1.005,metadata_int[filename]["int_lumi"],1.005,"f1",810,"-")
    A1.SetLabelSize(0)
    A1.SetLineWidth(1)
    A1.Draw("SAME")
    f2=ROOT.TF1("f2","x",.9,1.005)
    A2 = ROOT.TGaxis(metadata_int[filename]["int_lumi"],.9,metadata_int[filename]["int_lumi"],1.005,"f2",510,"+")
    A2.SetLabelSize(0)
    A2.SetLineWidth(1)
    A2.Draw("SAME")    
    
    leg.SetHeader("FPIX") 
    leg.SetFillColor(ROOT.kWhite)
    # leg.SetFillStyle(1)
    leg.SetBorderSize(1)
    leg.SetTextSize(0.034)
    leg.Draw()
    CMS = ROOT.TLatex(-0., 1.0075, "CMS#scale[0.8]{#font[52]{ Preliminary}}")
    CMS.SetLineWidth(2)
    CMS.Draw()
    era = ROOT.TLatex(237, 1.0075, "#scale[0.9]{#font[40]{Run 3 (13.6 TeV)}}")
    era.SetLineWidth(1)
    era.Draw()
    year2022 = ROOT.TLatex(1.2, 0.975, "#scale[0.75]{#font[40]{2022}}")
    year2022.SetLineWidth(1)
    year2022.Draw()
    year2023 = ROOT.TLatex(42.3, 0.975, "#scale[0.75]{#font[40]{2023}}")
    year2023.SetLineWidth(1)
    year2023.Draw()
    year2024 = ROOT.TLatex(74.4, 0.975, "#scale[0.75]{#font[40]{2024}}")
    year2024.SetLineWidth(1)
    year2024.Draw()
    year2025 = ROOT.TLatex(198.5, 0.975, "#scale[0.75]{#font[40]{2025}}")
    year2025.SetLineWidth(1)
    year2025.Draw()
    for ext in ["pdf", "root", "eps", "png"]:
        c.SaveAs('plots/%s/%s_Disks_run3.%s' % (metadata_int[filename]["outname"], key.split("/")[0], ext))   
    #file.Close()
