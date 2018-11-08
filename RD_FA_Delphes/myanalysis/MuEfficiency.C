#define MuEfficiency_cxx
#include "MuEfficiency.h"

#include "TH1.h"
#include "TH2.h"
#include <TStyle.h>
#include <TCanvas.h>
#include "TSystem.h"
#include <TClonesArray.h>
#include <TObject.h>
#include <vector>
#include <fstream>

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "delphes/classes/DelphesClasses.h"
#include "delphes/external/ExRootAnalysis/ExRootTreeReader.h"
#include "delphes/external/ExRootAnalysis/ExRootResult.h"
#endif


void MuEfficiency::Loop(const char *inputFile)
{
   TFile* File;
   //File = new TFile ("Analysis/EFFICIENCY_muons_Z_5k_IDEA.histo", "RECREATE");
   File = new TFile ("Analysis/EFFICIENCY_muons_Z_5k_CLIC.histo", "RECREATE");

   // Tracker acceptance IDEA
   //Double_t etacut = 2.1;
   // Tracker acceptance CLIC
   Double_t etacut = 2.54;
    
   TChain *chain = new TChain("Delphes");
   chain->Add(inputFile);
   ExRootTreeReader *treeReader = new ExRootTreeReader(chain); 
   Long64_t numberOfEntries = treeReader->GetEntries();
   std::cout << "Number of entries in Delphes Tree " << numberOfEntries << '\n';
  
   // Set number of events you want to use
   Long64_t maxNumberOfEvents = numberOfEntries;
   //Long64_t maxNumberOfEvents = 1000;
   std::cout << "Analysing " << maxNumberOfEvents << " events" << '\n';
  
   // Initialize pointers
   TClonesArray *branchParticle = treeReader->UseBranch("Particle");
   TClonesArray *branchMuon     = treeReader->UseBranch("Muon");
   //TClonesArray *branchEvent    = treeReader->UseBranch("Event");
   
   GenParticle *particle;
   GenParticle *genMU;
   Muon *muon;
   Double_t pt_res;
   
   // gStyle options
   gStyle->SetTitleFont(22,"X_mod");
   gStyle->SetTitleFont(22,"Y");
   //gStyle->SetOptStat(0);
   
   // Histograms
   TH1F *nEta_num      = new TH1F ("nEta_num", "# of events vs Eta", 20., -5., 5.);
   TH1F *nEta_den      = new TH1F ("nEta_den", "# of generated events vs eta", 20., -5., 5.);
   TH1F *effEta        = new TH1F ("effEta", "Efficiency vs Eta", 20., -5., 5.);
   
   TH1F *nPT_num       = new TH1F ("nPT_num", "# of events vs PT", 50., 0., 100.);
   TH1F *nPT_den       = new TH1F ("nPT_den", "# of generated events vs PT", 50., 0., 100.);
   TH1F *effPT         = new TH1F ("effPT", "Efficiency vs PT", 50., 0., 100.);
   
   TH1F *PTres         = new TH1F ("PTres", "PT Resolution", 200., -.15, .15);
   TH2F *PTres_over_PT = new TH2F ("PTres_over_PT", "PT Resolution VS PT", 5., 0., 100., 15., -.15, .15);
   TH1F *Isolation     = new TH1F ("Isolation", "Isolation", 200., -0.5, 3.);

  
   // Loop on all the events in the tree (entry -> event)
   for (Int_t entry = 0; entry < numberOfEntries; entry++) // Loop ENTRIES
     {
       // Load branches for event
       treeReader->ReadEntry(entry);
       if (entry%100==0) std::cout << " processing event " << entry << '\n';
       
       int Nmuons     = branchMuon -> GetEntriesFast();     // Number of muons in the event
       int Nparticles = branchParticle -> GetEntriesFast(); // Number of particles in the event
       

       for (int i=0; i<Nmuons; i++) // Loop MUONS
	 {
	   muon = (Muon*) branchMuon->At(i);
	   if ((fabs(muon->Eta)) > etacut) continue;   
	   Isolation -> Fill (muon->IsolationVar);
	 } // End Loop MUONS
       
       
       for (int i=0; i<Nparticles; i++)
	 {
	   particle = (GenParticle*) branchParticle->At(i);

	   // We look only for stable particles (Status=1)
	   if (fabs(particle->PID) != 13 || particle->Status != 1) continue;
	   if (particle->PT < 0.5 || ((fabs(particle->Eta)) > etacut)) continue; 	

	   nEta_den -> Fill (particle->Eta); //eff_Eta denominator histo
	   nPT_den  -> Fill (particle->PT);  //eff_PT denominator histo
	   

	   for (int k=0; k < Nmuons; k++) //Loop MUONS
	     {
	       muon = (Muon*) branchMuon->At(k);
	       
	       // Loop on good muons in acceptance
	       if (muon->PT < 0.5 || ((fabs(muon->Eta)) > etacut)) continue; 

	       genMU = (GenParticle*) muon->Particle.GetObject();
	       if (genMU != particle) continue; // We have found the recoMU associated to that GenParticle!
	   
	       nEta_num -> Fill (particle->Eta);//eff_PT numerator histo
	       nPT_num  -> Fill (particle->PT); //eff_Eta numerator histo

	       pt_res = ((muon->PT)-(particle->PT)) / (particle->PT);
	       PTres -> Fill (pt_res); //Resolution histo
	       PTres_over_PT -> Fill (particle->PT, pt_res);
       
	     } // End Loop MUONS
	 } // End Loop PARTICLES

     } // End Loop ENTRIES
   
   effEta -> Divide (nEta_num, nEta_den); //eff_Eta histo
   effPT  -> Divide (nPT_num, nPT_den); //eff_PT histo
   
   File->Write();
 
} // MACRO 

