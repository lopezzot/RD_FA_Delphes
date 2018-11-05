#define dieleZmass_cxx
#include "dieleZmass.h"

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



void dieleZmass::Loop(const char *inputFile)
{
  ////////////////////////////////////////////////////////////////////////////////////
  // 1. OUTPUT FILE                                                                 //
  // We also load Delphes libraries and say to TreeReader which Tree it has to read //
  ////////////////////////////////////////////////////////////////////////////////////
  TFile *File;
  File = new TFile ("ee_Z_Zee_1k_GenCuts_IDEAdet.histo","RECREATE");
  //File = new TFile ("Analysis/ee_Z_Zee_1k_IDEAdet.histo","RECREATE");
  //File = new TFile ("Analysis/ee_ZH_Zee_Hbb_1k_CLICdet.histo","RECREATE");
  //File = new TFile ("Analysis/ee_Z_Zee_1k_CLICdet.histo","RECREATE");

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
  TClonesArray *branchElectron = treeReader -> UseBranch ("Electron");
  
  GenParticle* p1;
  GenParticle* p2;  
  GenParticle* genEL1;  
  GenParticle* genEL2;
  GenParticle* genMotherEL;
  GenParticle* genMotherEL2;
  GenParticle* genMotherZ;
  Electron* recoEL1;
  Electron* recoEL2;
  TLorentzVector M1;
  TLorentzVector M2;
  TLorentzVector Z;
 
  // HISTOS
  TH1F* h_Ngenele_tot        = new TH1F("h_Ngenele_tot","h_Ngenele_tot", 5, 0., 5.);// All Generated Ele (Particles with PID=11)    
  TH1F* h_Ngenele            = new TH1F("h_Ngenele","h_Ngenele", 5, 0., 5.);        // All GenEle excluding when MotherParticle is an Ele
  TH1F* h_Ngenele_sig        = new TH1F("h_Ngenele_sig","h_Ngenele_sig", 5, 0., 5.);// GenEle with a Z boson as mother
  TH1F* h_Ngenele_oth        = new TH1F("h_Ngenele_oth","h_Ngenele_oth", 5, 0., 5.);// GenEle with other particles as mother, i.e.411,511,...
  TH1F* h_Ngenele_PT         = new TH1F("h_Ngenele_PT","h_Ngenele_PT", 100, 0., 100.);
  TH1F* h_Ngenele_ETA        = new TH1F("h_Ngenele_Eta","h_Ngenele_ETA", 10, -5., 5.);
  TH1F* h_Ngenele_PHI        = new TH1F("h_Ngenele_Phi","h_Ngenele_Phi", 10, -5., 5.);
  TH1F* h_Nrecoele_tot       = new TH1F("h_Nrecoele_tot","h_Nrecoele_tot", 5, 0., 5.);//All Reco Ele (how many events with 0/1/2/3 Ele?)
  TH1F* h_Nrecoele           = new TH1F("h_Nrecoele","h_Nrecoele", 5, 0., 5.);        //All RecoEle excluding when MotherParticle is an Ele
  TH1F* h_Nrecoele_sig       = new TH1F("h_Nrecoele_sig","h_Nrecoele_sig", 5, 0., 5.);//RecoEle with a Z boson as mother
  TH1F* h_Nrecoele_oth       = new TH1F("h_Nrecoele_oth","h_Nrecoele_oth", 5, 0., 5.);//RecoEle with other particles as mother

  TH1F* h_NgenZ_tot          = new TH1F("h_NgenZ_tot","h_NgenZ_tot", 5, 0., 5.); //All Particles with PID 23 
  TH1F* h_NgenZ              = new TH1F("h_NgenZ","h_NgenZ", 5, 0., 5.);         //Signal Z boson, generated from e+e-
  TH1F* h_Zmass_Particle     = new TH1F("h_Zmass_Particle","h_Zmass_Particle", 200, 0., 200.); //Z inv mass with signal GenEle 
  // Here we select only Z boson with Reco Ele linked to a signal GenParticle
  TH1F* h_Zmass_matchedElectrons = new TH1F("h_Zmass_matchedElectrons","h_Zmass_matchedElectrons", 200, 0., 200.);
  
  
  for (Long64_t jentry=0; jentry<numberOfEntries; jentry++) //Loop EVENTS
    {
      treeReader -> ReadEntry(jentry);
      if (jentry%100==0) std::cout << jentry << "\n";

      int N_particle = branchParticle  -> GetEntriesFast();
      int N_recoEL   = branchElectron  -> GetEntriesFast();

      h_Nrecoele_tot -> Fill(N_recoEL);
      
      for(int i = 0; i < N_particle; i++) // Loop PARTICLE
	{
      	  p1 = (GenParticle*) branchParticle -> At(i); //p1 is a pointer to a GenParticle object at the positon i in the array

	  // Including these cuts at gen level, we are looking to a sub-group of gen ele which is characterized by the same                   
          // requirements included in the reconstruction of electrons, so we can evaluate the proper efficiency of the detector.      
          // Exluding this line, we have the feeling of how many ele we loose only because of the geometry and size of our                 
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

	  else if (fabs (p1->PID) == 11) 
	    {
	      h_Ngenele_tot -> Fill(1);
	      if ((p1->M1 > branchParticle->GetEntriesFast()) || (p1->M1 < 0)) continue;	   
	      genMotherEL = (GenParticle*) branchParticle->At(p1->M1);	

	      if ((fabs(genMotherEL->PID) != 11)) 
		{
		  h_Ngenele -> Fill(1);
		  h_Ngenele_PT -> Fill(p1->PT);
		  h_Ngenele_ETA -> Fill(p1->Eta);
		  h_Ngenele_PHI -> Fill(p1->Phi);

		  if (fabs(genMotherEL->PID) == 23) 
		    {
		      h_Ngenele_sig -> Fill(1); 
		      
		      for(int j = 0; j < N_particle; j++) 
			{
			  p2 = (GenParticle*) branchParticle -> At(j);
			  if (i == j) continue;
			  if ((p2->M1 > branchParticle->GetEntriesFast()) || (p2->M1 < 0)) continue; 
			  genMotherEL2 = (GenParticle*) branchParticle->At(p2->M1);	
			  if (!(fabs(genMotherEL2->PID) == 23)) continue;
			  if (!((p1->PID + p2->PID) == 0)) continue; 
			  
			  M1.SetPtEtaPhiM (p1->PT, p1->Eta, p1->Phi, p1->Mass);        
			  M2.SetPtEtaPhiM (p2->PT, p2->Eta, p2->Phi, p2->Mass);                
			  Z = M1 + M2;          
			  h_Zmass_Particle -> Fill(Z.M());
			}             
		    }
		  else h_Ngenele_oth -> Fill(1);
		}
	    }

	} //End Loop PARTICLE
  

      for(int i = 0; i < N_recoEL; i++) // Loop RECOELE - Matching                                     
	{
	  recoEL1 = (Electron*) branchElectron -> At(i);
	  genEL1 = (GenParticle*) recoEL1 -> Particle.GetObject();
	  if ((genEL1->M1 > branchParticle->GetEntriesFast()) || (genEL1->M1 < 0)) continue;	      
	  genMotherEL = (GenParticle*) branchParticle->At(genEL1->M1);

	  if ((fabs(genMotherEL->PID) != 11)) 
	    {
	      h_Nrecoele -> Fill(1);
	      if ((genMotherEL->PID) != 23) h_Nrecoele_oth -> Fill(1);	   
	    }

	  if ((fabs(genMotherEL->PID) == 23))
	    {
	      h_Nrecoele_sig -> Fill(1); 
	    	      
	      for (int j = 0; j < N_recoEL; j++)
		{
		  recoEL2 = (Electron*) branchElectron -> At(j);
		  if (i <= j) continue;
		  genEL2 = (GenParticle*) recoEL2 -> Particle.GetObject();
		  
		  if ((genEL2->M1 > branchParticle->GetEntriesFast()) || (genEL2->M1 < 0)) continue;
		  genMotherEL2 = (GenParticle*) branchParticle->At(genEL2->M1);

		  if (!(fabs(genMotherEL2->PID) == 23)) continue;
		  if (!((genEL1->PID + genEL2->PID) == 0)) continue; 
		  
		  M1.SetPtEtaPhiM (genEL1->PT, genEL1->Eta, genEL1->Phi, genEL1->Mass);            
		  M2.SetPtEtaPhiM (genEL2->PT, genEL2->Eta, genEL2->Phi, genEL2->Mass);          
		  Z = M1 + M2;                                                                   
            
		  h_Zmass_matchedElectrons -> Fill(Z.M());  
		  //std::cout << "Mass matchedElectrons = " << Z.M() << '\n';
		}
	    }	  
	} //End Loop RECOELE - Matching

    } //End Loop EVENTS

File->cd();
gDirectory -> pwd();
File->Write();

} //End Loop MACRO
