#define dimuonZmass_cxx
#include "dimuonZmass.h"

#include "TH1.h"
#include <TH2.h>
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



void dimuonZmass::Loop(const char *inputFile)
{
  ////////////////////////////////////////////////////////////////////////////////////
  // 1. OUTPUT FILE                                                                 //
  // We also load Delphes libraries and say to TreeReader which Tree it has to read //
  ////////////////////////////////////////////////////////////////////////////////////
  TFile *File;
  File = new TFile ("PROVA_ee_Z_Zmumu_1k_IDEAdet.histo","RECREATE");
  //File = new TFile ("Analysis/ee_Z_Zmumu_1k_IDEAdet.histo","RECREATE");
  //File = new TFile ("Analysis/ee_ZH_Zmumu_Hbb_1k_CLICdet.histo","RECREATE");
  //File = new TFile ("Analysis/ee_Z_Zmumu_1k_CLICdet.histo","RECREATE");

  if (fChain == 0) return;
  gSystem->Load("libDelphes");
  TChain *chain = new TChain("Delphes");
  chain->Add(inputFile);
  ExRootTreeReader *treeReader = new ExRootTreeReader(chain);
  //Long64_t numberOfEntries = 50;
  Long64_t numberOfEntries = treeReader->GetEntries();
  std::cout << "Number of entries in Delphes Tree " << numberOfEntries << "\n";


  ////////////////////////////////////////////////////////////////////////////////////
  // 2. BRANCHES used for the analysis and declaration of objects and histos        //
  // The TreeReader reads branches with names used to save each branch in the       //
  // TreeWriter module in the card (BranchName):                                    //
  // # add Branch InputArray BranchName BranchClass                                 //
  // # add Branch Delphes/allParticles Particle GenParticle                         //
  // (BranchClass is the name used to access to the object, i.e. GenParticle*)      //
  ////////////////////////////////////////////////////////////////////////////////////
  
  TClonesArray *branchParticle = treeReader -> UseBranch ("Particle");
  TClonesArray *branchMuon     = treeReader -> UseBranch ("Muon");
  
  GenParticle* p1;
  GenParticle* p2;  
  GenParticle* genMU1;
  GenParticle* genMU2;
  GenParticle* genMotherMU;
  GenParticle* genMotherMU2;
  GenParticle* genMotherZ;
  Muon* recoMU1;
  Muon* recoMU2;
  TLorentzVector M1;
  TLorentzVector M2;
  TLorentzVector Z;
 
  // HISTOS
  TH1F* h_Ngenmu_tot         = new TH1F("h_Ngenmu_tot","h_Ngenmu_tot", 5, 0., 5.); // All Generated Muons (Particles with PID=13)
  TH1F* h_Ngenmu             = new TH1F("h_Ngenmu","h_Ngenmu", 5, 0., 5.);         // All GenMu excluding when MotherParticle is a Muon 
  TH1F* h_Ngenmu_sig         = new TH1F("h_Ngenmu_sig","h_Ngenmu_sig", 5, 0., 5.); // GenMu with a Z boson as mother 
  TH1F* h_Ngenmu_oth         = new TH1F("h_Ngenmu_oth","h_Ngenmu_oth", 5, 0., 5.); // GenMu with other particles as mother, i.e. 411, 511, ...
  TH1F* h_Ngenmu_PT          = new TH1F("h_Ngenmu_PT","h_Ngenmu_PT", 100, 0., 100.);
  TH1F* h_Ngenmu_ETA         = new TH1F("h_Ngenmu_Eta","h_Ngenmu_ETA", 10, -5., 5.);
  TH1F* h_Ngenmu_PHI         = new TH1F("h_Ngenmu_Phi","h_Ngenmu_Phi", 10, -5., 5.);
  TH1F* h_Nrecomu_tot        = new TH1F("h_Nrecomu_tot","h_Nrecomu_tot", 5, 0., 5.); //All Reco Muons (how many events with 0/1/2/3 Mu?)
  TH1F* h_Nrecomu            = new TH1F("h_Nrecomu","h_Nrecomu", 5, 0., 5.);         //All RecoMu excluding when MotherParticle is a Muon
  TH1F* h_Nrecomu_sig        = new TH1F("h_Nrecomu_sig","h_Nrecomu_sig", 5, 0., 5.); //RecoMu with a Z boson as mother
  TH1F* h_Nrecomu_oth        = new TH1F("h_Nrecomu_oth","h_Nrecomu_oth", 5, 0., 5.); //RecoMu with other particles as mother

  TH1F* h_NgenZ_tot          = new TH1F("h_NgenZ_tot","h_NgenZ_tot", 5, 0., 5.); //All Particles with PID 23 
  TH1F* h_NgenZ              = new TH1F("h_NgenZ","h_NgenZ", 5, 0., 5.);         //Signal Z boson, generated from e+e-
  TH1F* h_Zmass_Particle     = new TH1F("h_Zmass_Particle","h_Zmass_Particle", 200, 0., 200.); //Z inv mass with signal GenMu 
  // Here we select only Z boson with Reco Muons linked to a signal GenParticle
  TH1F* h_Zmass_matchedMuons = new TH1F("h_Zmass_matchedMuons","h_Zmass_matchedMuons", 200, 0., 200.);
  
  
  for (Long64_t jentry=0; jentry<numberOfEntries; jentry++) //Loop EVENTS
    {
      treeReader -> ReadEntry(jentry);
      if (jentry%100==0) std::cout << jentry << "\n";

      int N_particle = branchParticle  -> GetEntriesFast();
      int N_recoMU   = branchMuon      -> GetEntriesFast();

      h_Nrecomu_tot  -> Fill(N_recoMU);
      
      for(int i = 0; i < N_particle; i++) // Loop PARTICLE
	{
      	  p1 = (GenParticle*) branchParticle -> At(i); //p1 is a pointer to a GenParticle object at the positon i in the array

	  // Including these cuts at gen level, we are looking to a sub-group of gen mu which is characterized by the same 
	  // requirements included in the reconstruction of muons, so we can evaluate the proper efficiency of the detector.
	  // Exluding this line, we have the feeling of how many muons we loose only because of the geometry and size of our 
	  // detector. It could be an interesting comparison.
	  if (p1->Eta > 2.1 || p1->PT < 0.5) continue;

	  if (p1->PID == 23) 
	    {
	      h_NgenZ_tot -> Fill(1);
	      // M1 finds the mother of p1:
	      // we check that the mother is not out of array's bounds  
	      if ((p1->M1 > branchParticle->GetEntriesFast()) || (p1->M1 < 0)) continue; 
	      genMotherZ = (GenParticle*) branchParticle->At(p1->M1);
	      if (fabs(genMotherZ->PID) == 11) h_NgenZ -> Fill(1); 
	    }

	  else if (fabs (p1->PID) == 13) 
	    {
	      h_Ngenmu_tot -> Fill(1);
	      genMotherMU = (GenParticle*) branchParticle->At(p1->M1);	
	      if ((fabs(genMotherMU->PID) != 13)) 
		{
		  h_Ngenmu -> Fill(1);
		  h_Ngenmu_PT -> Fill(p1->PT);
		  h_Ngenmu_ETA -> Fill(p1->Eta);
		  h_Ngenmu_PHI -> Fill(p1->Phi);

		  if (fabs(genMotherMU->PID) == 23) 
		    {
		      h_Ngenmu_sig -> Fill(1); 
		      
		      for(int j = 0; j < N_particle; j++) 
			{
			  p2 = (GenParticle*) branchParticle -> At(j);
			  // We look for a pair of same particles with opposite sign 
			  if (i == j) continue;
			  if ((p2->M1 > branchParticle->GetEntriesFast()) || (p2->M1 < 0)) continue; 
			  genMotherMU2 = (GenParticle*) branchParticle->At(p2->M1);	
			  if (!(fabs(genMotherMU2->PID) == 23)) continue;
			  if (!((p1->PID + p2->PID) == 0)) continue; 
			  
			  // Then we associate to p1, p2 a TLorenzVector M1, M2
			  M1.SetPtEtaPhiM (p1->PT, p1->Eta, p1->Phi, p1->Mass);        
			  M2.SetPtEtaPhiM (p2->PT, p2->Eta, p2->Phi, p2->Mass);
			  // We build a new TLorentzVector Z with M1, M2 and fill the histo with Z invariant mass                
			  // 
			  Z = M1 + M2;          
			  h_Zmass_Particle -> Fill(Z.M());
			}             
		    }
		  else h_Ngenmu_oth -> Fill(1);
		}
	    }
	} //End Loop PARTICLE
  

        for(int i = 0; i < N_recoMU; i++) // Loop RECOMU - Matching                                     
	{
	  recoMU1 = (Muon*) branchMuon -> At(i);
	  genMU1 = (GenParticle*) recoMU1 -> Particle.GetObject();
	  if ((genMU1->M1 > branchParticle->GetEntriesFast()) || (genMU1->M1 < 0)) continue;	      
	  genMotherMU = (GenParticle*) branchParticle->At(genMU1->M1);

	  if ((fabs(genMotherMU->PID) != 13)) 
	    {
	      h_Nrecomu -> Fill(1);
	      if ((genMotherMU->PID) != 23) h_Nrecomu_oth -> Fill(1);	   
	    }

	  if ((fabs(genMotherMU->PID) == 23))
	    {
	      h_Nrecomu_sig -> Fill(1); 
	      
	      for (int j = 0; j < N_recoMU; j++)
		{
		  recoMU2 = (Muon*) branchMuon -> At(j);
		  if (i <= j) continue;
		  genMU2 = (GenParticle*) recoMU2 -> Particle.GetObject();
		  
		  if ((genMU2->M1 > branchParticle->GetEntriesFast()) || (genMU2->M1 < 0)) continue;
		  genMotherMU2 = (GenParticle*) branchParticle->At(genMU2->M1);
		  if (!(fabs(genMotherMU2->PID) == 23)) continue;
		  if (!((genMU1->PID + genMU2->PID) == 0)) continue; 
		  
		  M1.SetPtEtaPhiM (genMU1->PT, genMU1->Eta, genMU1->Phi, genMU1->Mass);            
		  M2.SetPtEtaPhiM (genMU2->PT, genMU2->Eta, genMU2->Phi, genMU2->Mass);          
		  Z = M1 + M2;                                                                               
		  h_Zmass_matchedMuons -> Fill(Z.M());  
		  //std::cout << "Mass matchedMuons = " << Z.M() << '\n';
		}
	    }	  
	} //End Loop RECOMU - Matching

    } //End Loop EVENTS

File->cd();
gDirectory -> pwd();
File->Write();

} //End Loop MACRO
