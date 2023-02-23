import argparse
import os
import ROOT
import re
from math import sqrt

ROOT.gStyle.SetOptStat(True)

metadata = {
    "TimingScan": {
        "file": "../PHM_PHASE1_out/Histo_TimingScan_Sep2022_merged.root",
        "int_lumi": 10.9,
        "fill": [8210],
        "bias": 300,
        "marker_color": ROOT.kRed+1,
        "marker_style": 20,
        "marker_syze": .5,
        "outname": "TimingScan_Sep2022",
        "sqrts": 13.6,
        "year": 2022,
        "legend": "Timing Scan Sep2022",
        "write": True,
    }
}

plotdict ={
    "dirs": {
         "AvgNormOnTrkCluCharge_vs_Delay":{
            "xtitle": "Time Delay [ns]",
            "ytitle": "Avg. Norm. On-Trk Clu. Charge [ke]",
            "type": "charge"
        },
        "AvgOnTrkCluSize_vs_Delay":{
            "xtitle": "Time Delay [ns]",
            "ytitle": "Avg. On-Trk Clu. Size [pixel]",
            "type": "size"
        },
    },

    "plots":{
        "Layers_2022SepMiniScan": {
            "ranges_size": [-10,10, 0, 9],
            "ranges_charge": [-10,10, 10, 30],
            "legtitle": "BPIX",
        },
        "Disks_2022SepMiniScan": {
            "ranges_size": [-10,10, 0, 4],
            "ranges_charge": [-10,10, 10, 30],
            "legtitle": "FPIX",
        },
    },
}

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
                    item.GetXaxis().SetRangeUser(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][0], plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][1])
                    item.GetXaxis().SetTitle(plotdict["dirs"][dir]["xtitle"])
                    item.GetYaxis().SetRangeUser(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][2], plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3])
                    item.GetYaxis().SetTitle(plotdict["dirs"][dir]["ytitle"])
                if item.GetName()=="TPave":
                    leg=item
                if leg != None:
                    leg.SetHeader(plotdict["plots"][plot]["legtitle"])
                    leg.SetX1(0.2)
                    leg.SetX2(0.4)
                    leg.SetY1(0.7)
                    leg.SetY2(0.9)

            CMS = ROOT.TLatex(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][0], plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]+(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]-plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][2])*0.03, "CMS#scale[0.75]{#font[52]{Work in progress}}")
            CMS.SetLineWidth(2)
            CMS.Draw()
            era = ROOT.TLatex(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][1]*0.45, plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]+(plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][3]-plotdict["plots"][plot]["ranges_"+plotdict["dirs"][dir]["type"]][2])*0.03, "#scale[0.7]{#font[40]{(%s) %s TeV}}" % (metadata[filename]["year"], metadata[filename]["sqrts"]) )
            era.SetLineWidth(1)
            era.Draw()
            c.SetGridx()
            c.SetGridy()
            c.Draw()
            if metadata[filename]["write"]:
                c.SaveAs('%s_%s_%s.png' % (metadata[filename]["outname"], dir, plot.split("_")[0]))
        
