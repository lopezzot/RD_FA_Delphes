#define tauStudies_cxx
#include "tauStudies.h"

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
#include <delphes/classes/SortableObject.h>


double f_deltaR (double const &Eta1, double const &Eta2, double const &Phi1, double const &Phi2)
{
  double deltaR = sqrt((Eta1 - Eta2)*(Eta1 - Eta2) + (Phi1 - Phi2)*(Phi1 - Phi2));
  return deltaR;
}


void tauStudies::Loop(const char* inputfile)
{
  TFile *outfile; 
  outfile = new TFile("ZH_tautaujets_30cm_dR3.root","RECREATE");
  //outfile = new TFile("Z_jets_30cm.root","RECREATE");

  if (fChain == 0) return;
  gSystem->Load("libDelphes");
  TChain *chain = new TChain("Delphes");
  chain->Add(inputfile);
  ExRootTreeReader *treeReader = new ExRootTreeReader(chain);
  //Long64_t numberOfEntries = 1000;                                                                                    
  Long64_t numberOfEntries = treeReader->GetEntries();
  std::cout << "Number of entries in Delphes Tree " << numberOfEntries << "\n";

  TClonesArray *branchParticle = treeReader -> UseBranch ("Particle"); 
  TClonesArray *branchTower    = treeReader -> UseBranch ("Tower");
  TClonesArray *branchJet      = treeReader -> UseBranch ("Jet");
  TClonesArray *branchMET      = treeReader -> UseBranch ("MissingET");

  GenParticle* p1;
  Jet* jet;

  //HISTO
  TH1D *h_nParticle  = new TH1D ("h_nParticle", "nParticle", 120, 0, 120);
  TH1D *h_p_PT       = new TH1D ("h_p_PT", "Particle PT", 80, 0, 40);
  TH1D *h_p_P        = new TH1D ("h_p_P", "Particle P", 80, 0, 40);
  TH1D *h_p_Energy   = new TH1D ("h_p_Energy", "Particle Energy", 80, 0, 40);
  TH1D *h_p_ETA      = new TH1D ("h_p_ETA", "Particle ETA", 10, -5, 5);

  TH1D *h_nEle       = new TH1D ("h_nEle", "nEle", 50, 0, 50);  // ELE + and ELE - and neutrino        
  TH1D *h_nMuon      = new TH1D ("h_nMuon", "Muon", 50, 0, 50); // MU + and MU - and neutrino          
  TH1D *h_nGamma     = new TH1D ("h_nGamma", "nGamma", 70, 0, 70);
  TH1D *h_nPion      = new TH1D ("h_nPion", "nPion", 70, 0, 70);
  TH1D *h_nKaon      = new TH1D ("h_nKaon", "nKaon", 25, 0, 25);
  TH1D *h_nProton    = new TH1D ("h_nProton", "nProton", 25, 0, 25);
  TH1D *h_nNeutron   = new TH1D ("h_nNeutron", "nNeutron", 25, 0, 25);

  TH1F* h_Njet          = new TH1F("h_Njet","nJet", 20, 0., 20.);
  TH1F* h_jet_PT        = new TH1F("h_jet_PT","Jet_PT", 100, 0., 100.);
  TH1F* h_jet_ETA       = new TH1F("h_jet_ETA","Jet_ETA", 10, -5., 5.);
  TH1F* h_jet_PHI       = new TH1F("h_jet_PHI","Jet_PHI", 10, -5., 5.);
  TH1F* h_deltaRjetjet  = new TH1F("h_deltaRjetjet","DeltaR_jetjet", 10, 0., 10.);
  TH1F* h_Ntaujet       = new TH1F("h_Ntaujet","nTaujet", 10, 0., 10.);
  TH1F* h_taujet_PT     = new TH1F("h_taujet_PT","Taujet_PT", 100, 0., 100.);
  TH1F* h_taujet_ETA    = new TH1F("h_taujet_ETA","Taujet_ETA", 10, -5., 5.);
  TH1F* h_taujet_PHI    = new TH1F("h_taujet_PHI","Taujet_PHI", 10, -5., 5.);
  TH1F* h_deltaRtautau  = new TH1F("h_deltaRtautau","DeltaR_tautau", 10, 0., 10.);
  TH1F* h_MET           = new TH1F("h_MET","MET", 50, 0., 200.);

  TH1F* h_taumass       = new TH1F("h_taumass","Tau Mass ", 120, 0., 30.);
  TH1F* h_ditaumass_vis = new TH1F("h_ditaumass_vis","Ditau visible Mass", 50, 0., 200.);
  TH1F* h_dijetmass     = new TH1F("h_dijetmass","Dijet Mass", 40, 0., 200.);

  TH1F* h_overlappingTowers = new TH1F("h_overlappingTowers","Number of tower with overlap", 10, 0., 10.);


  for (Long64_t jentry=0; jentry<numberOfEntries; jentry++) // Loop EVENTS 
    {
      treeReader -> ReadEntry(jentry);
      //Long64_t ientry = LoadTree(jentry);
      //if (ientry < 0) break;
      if (jentry%1000==0) std::cout << jentry << "\n";
      //std::cout << "############ EVENT " << jentry << "\n";                                                          
      Int_t N_particle = branchParticle -> GetEntriesFast();
      int N_jet        = branchJet      -> GetEntriesFast();
      int N_Tower      = branchTower    -> GetEntriesFast();

      Int_t n_particle = 0;
      Int_t n_ele      = 0; // ELE+ and ELE-                                                                                           
      Int_t n_muon     = 0;
      Int_t n_gamma    = 0;
      Int_t n_pion     = 0;
      Int_t n_kaon     = 0;
      Int_t n_proton   = 0;
      Int_t n_neutron  = 0;
      Int_t overlap    = 0;

      //////////////////////////////////////////////////////////////TOWER//////////////////////////////////////////////////////////
      for (int t=0; t < N_Tower; t++)
	{
	  Tower* tower = (Tower*)branchTower->At(t);
	  if (tower->Eem != 0. && tower->Ehad != 0.) overlap++; 
	  //std::cout << "Tower" << t << "\t\t Eem = " << tower->Eem << "\t\t Ehad = " << tower->Ehad << "\n";
	}
      h_overlappingTowers -> Fill(overlap);

      ///////////////////////////////////////////////////////////PARTICLE//////////////////////////////////////////////////////////
      for (int i = 0; i < N_particle; i++) // Loop PARTICLE                                                                          
        {
          p1 = (GenParticle*) branchParticle -> At(i); //p1 is a pointer to a GenParticle object at the positon i in the array         
	  //std::cout << "Particle " << i << "\t\t Status = " << p1->Status << "\t\t PID = " << p1->PID << '\n';

	  if (fabs(p1->Eta) < 3.0 && p1->Status == 1) 
	    {
	      n_particle++;
	      h_p_PT -> Fill(p1->PT);
	      h_p_P -> Fill(p1->P);
	      h_p_Energy -> Fill(p1->E);
	      h_p_ETA -> Fill(p1->Eta);

	      if (fabs(p1->PID) == 11 || fabs(p1->PID) == 12) n_ele++;
	      else if (fabs(p1->PID) == 13 || fabs(p1->PID) == 14) n_muon++;
	      else if (fabs(p1->PID) == 22) n_gamma++;
	      else if (fabs(p1->PID) == 111 || fabs(p1->PID) == 211) n_pion++;
	      else if (fabs(p1->PID) == 130 || fabs(p1->PID) == 321) n_kaon++;
	      else if (fabs(p1->PID) == 2212) n_proton++;
	      else if (fabs(p1->PID) == 2112) n_neutron++;
	    }	      
	} // End Loop PARTICLE
      
      h_nParticle->Fill(n_particle);
      h_nEle->Fill(n_ele); 
      h_nMuon->Fill(n_muon); 
      h_nGamma->Fill(n_gamma); 
      h_nPion->Fill(n_pion); 
      h_nKaon->Fill(n_kaon); 
      h_nProton->Fill(n_proton); 
      h_nNeutron->Fill(n_neutron); 

      ///////////////////////////////////////////////////////////////JET///////////////////////////////////////////////////////////
      h_Njet  -> Fill(N_jet);
      //if (N_jet != 2) continue;
      //if (! (N_jet == 2 || N_jet == 3)) continue;

      Int_t JetPair [2];
      TLorentzVector J1;
      TLorentzVector J2;
      TLorentzVector jetPair;
      Jet* jet1;
      Jet* jet2;
      Double_t jet_PT_min = 0;
      Int_t  Jets[20];
      Int_t  nlightjets = 0;

      Int_t TauPair [2];
      TLorentzVector T;
      TLorentzVector T1;
      TLorentzVector T2;
      TLorentzVector tauPair;
      Jet* tau1;
      Jet* tau2;
      Double_t tau_PT_min = 0;
      Int_t  TaggedJets [10];
      Bool_t tauVeto  = false;
      Int_t  ntaujets = 0;


      for (int j=0; j < N_jet; j++)
	{
          jet = static_cast<Jet*>(branchJet->At(j));
	  h_jet_PT -> Fill (jet->PT);
	  h_jet_ETA -> Fill (jet->Eta);
	  h_jet_PHI -> Fill (jet->Phi);
	  if (fabs(jet->Eta) > 3.0) continue;
	  if (jet->PT < 10.0) continue;

          if (jet->TauTag & (1 << 0))
            {
              TaggedJets[ntaujets] = j;
              ntaujets++;
	      h_Ntaujet    -> Fill (ntaujets);
	      h_taujet_PT  -> Fill (jet->PT);
	      h_taujet_ETA -> Fill (jet->Eta);
	      h_taujet_PHI -> Fill (jet->Phi);
            }
	  else
	    {
              Jets[nlightjets] = j;
	      nlightjets++;
	    }
	}

      //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°//
      if (nlightjets >= 2)
	{
	  for (int n=0; n < nlightjets; n++)
	    {
	      jet1 = static_cast<Jet*>(branchJet->At(Jets[n]));
	      //Int_t indexJ1 = Jets [n];
	      for (int j=n+1; j < nlightjets; j++)
		{
		  jet2 = static_cast<Jet*>(branchJet->At(Jets [j]));
		  //Int_t indexJ2 = Jets [j];

		  if ((jet1->Flavor != 3) || (jet1->Flavor != jet2->Flavor)) continue;
		  if ((jet1->Charge + jet2->Charge) != 0) continue;
		    		 
		  Double_t dRjj = f_deltaR (jet1->Eta, jet2->Eta, jet1->Phi, jet2->Phi);
		  h_deltaRjetjet -> Fill (dRjj);
		  std::cout << "Flavour = " << jet1->Flavor << "\t Charge = " << jet1->Charge << '\n';  
		  std::cout << "Flavour = " << jet2->Flavor << "\t Charge = " << jet2->Charge << '\n';  
		  std::cout << "DeltaR_jet = " << dRjj << '\n';  

		  J1.SetPtEtaPhiM (jet1 -> PT, jet1 -> Eta, jet1 -> Phi, jet1 -> Mass);
		  J2.SetPtEtaPhiM (jet2 -> PT, jet2 -> Eta, jet2 -> Phi, jet2 -> Mass);
		      
		  jetPair = J1 + J2;
		  for (int i = 0; i < N_particle; i++) // Loop PARTICLE                                                                          
		    {
		      p1 = (GenParticle*) branchParticle -> At(i); //p1 is a pointer to a GenParticle object at the positon i in the array         
		      if (p1->PID == 25 && fabs(p1->Eta) < 3.0)
			{

			  Double_t deltaHjetPair = f_deltaR(p1->Eta, jetPair.Eta(), p1->Phi, jetPair.Phi());
			  if ( deltaHjetPair < 0.4 ) 
			    {
			      h_dijetmass -> Fill (jetPair.M());
			      //std::cout << "Evento " << jentry << "\t\t Trovato H e riempito! \n";
			      break;
			    }	   
			}
		    }	      
		}
	    }
	}
	

      //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°//      
      if (ntaujets>=2) tauVeto = true;
      if(tauVeto==false) continue;
      
      for (int n=0; n < ntaujets; n++)
	{
	  tau1 = static_cast<Jet*>(branchJet->At(TaggedJets[n]));
	  T.SetPtEtaPhiM (tau1 -> PT, tau1 -> Eta, tau1 -> Phi, tau1 -> Mass);
	  h_taumass -> Fill(tau1->Mass);
	  Int_t indexT1 = TaggedJets [n];
	  for (int j=n+1; j < ntaujets; j++)
	    {
	      tau2 = static_cast<Jet*>(branchJet->At(TaggedJets [j]));
	      Int_t indexT2 = TaggedJets [j];
	      if (tau1 -> PT + tau2 -> PT > tau_PT_min)
		{
		  tau_PT_min = tau1 -> PT + tau2 -> PT;
		  TauPair [0] = indexT1;
		  TauPair [1] = indexT2;
		}
	    }
	}
      
      tau1 = (Jet*) branchJet -> At (TauPair [0]);
      tau2 = (Jet*) branchJet -> At (TauPair [1]);
      
      double dRtautau = f_deltaR (tau1->Eta, tau2->Eta, tau1->Phi, tau2->Phi);
      h_deltaRtautau -> Fill (dRtautau);
      if (dRtautau < 2.2 || dRtautau > 3.8) continue;
      
      if (! ((tau1->Charge + tau2->Charge) == 0)) continue;
      if ((tau1->Charge) > (tau2->Charge)) continue;
      T1.SetPtEtaPhiM (tau1 -> PT, tau1 -> Eta, tau1 -> Phi, tau1 -> Mass);
      T2.SetPtEtaPhiM (tau2 -> PT, tau2 -> Eta, tau2-> Phi, tau2 -> Mass);
      
      //h_taumass -> Fill(tau1->Mass);
      //h_taumass -> Fill(tau2->Mass);
      tauPair = T1 + T2;
      MissingET* met = static_cast<MissingET*>(branchMET->At(0));
      h_MET->Fill(met->MET);
      
      //if (Z.M() < 80 || Z.M() > 100) continue;
      h_ditaumass_vis -> Fill (tauPair.M());
      
    } // End Loop EVENTS
  outfile->cd();
  gDirectory -> pwd();
  outfile->Write();
}// End MACRO      










/*
  std::cout << "Number of particles   " << n_particle << '\n';
  std::cout << "Ele = " << n_ele << '\n';
  std::cout << "Muon = " << n_muon << '\n';
  std::cout << "Photon = " << n_gamma << '\n';
  std::cout << "Pion = " << n_pion << '\n';
  std::cout << "Kaon = " << n_kaon << '\n';
  std::cout << "Proton = " << n_proton << '\n';
  std::cout << "Neutron = " << n_neutron << '\n';
*/
