#!/usr/bin/env python

import sys
import ROOT

if len(sys.argv) < 2:
	print " Usage: python examples/MissingMass.py delphes_ee_zh_zmumu.root hist_mrec.root"
	sys.exit(1)

ROOT.gSystem.Load("libDelphes")

try:
	ROOT.gInterpreter.Declare('#include "classes/SortableObject.h"')
	ROOT.gInterpreter.Declare('#include "classes/DelphesClasses.h"')
	ROOT.gInterpreter.Declare('#include "external/ExRootAnalysis/ExRootTreeReader.h"')
except:
	pass

inputFile = sys.argv[1]
outputFile = sys.argv[2]

# Create chain of root trees
chain = ROOT.TChain("Delphes")
chain.Add(inputFile)

# Create object of class ExRootTreeReader
treeReader = ROOT.ExRootTreeReader(chain)
numberOfEntries = treeReader.GetEntries()

# Get pointers to branches used in this analysis
branchMuon = treeReader.UseBranch("Muon")

# Book histograms
histZMass = ROOT.TH1F("Zmass", "M_{Z} [GeV]", 200, 0.0, 200.0)
histHMass = ROOT.TH1F("Hmass", "M_{recoil} [GeV]", 60, 100.0, 160.0)

ptot = ROOT.TLorentzVector(0.,0.,0.,240.)
# Loop over all events
for entry in range(0, numberOfEntries):
	# Load selected branches with data from specified event
	treeReader.ReadEntry(entry)

	# If event contains at least 2 muons
	if branchMuon.GetEntries() > 1:

		mu1 = branchMuon.At(0)
		mu2 = branchMuon.At(1)

		# If event contains at least 2 muons of opposite charge
		if ((mu1.Charge + mu2.Charge) == 0):
			pll = mu1.P4() + mu2.P4()
			ph = ptot - pll

			histHMass.Fill(ph.M())
			histZMass.Fill(pll.M())

out_root = ROOT.TFile(outputFile,"RECREATE")	
histZMass.Write()
histHMass.Write()
