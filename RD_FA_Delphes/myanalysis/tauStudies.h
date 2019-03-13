//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Mar 12 10:54:40 2019 by ROOT version 5.34/38
// from TTree Delphes/Analysis tree
// found on file: rootfile/ZH_tautaujets_3cm.root
//////////////////////////////////////////////////////////

#ifndef tauStudies_h
#define tauStudies_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxEvent = 1;
   const Int_t kMaxParticle = 357;
   const Int_t kMaxElectron1 = 7;
   const Int_t kMaxElectron2 = 5;
   const Int_t kMaxElectron3 = 5;
   const Int_t kMaxElectron4 = 2;
   const Int_t kMaxMuon1 = 4;
   const Int_t kMaxMuon2 = 3;
   const Int_t kMaxMuon3 = 2;
   const Int_t kMaxTrack = 51;
   const Int_t kMaxTower = 113;
   const Int_t kMaxEFlowTrack = 51;
   const Int_t kMaxEFlowPhoton = 116;
   const Int_t kMaxEFlowNeutralHadron = 1;
   const Int_t kMaxGenJet = 18;
   const Int_t kMaxGenMissingET = 1;
   const Int_t kMaxJet = 19;
   const Int_t kMaxElectron = 2;
   const Int_t kMaxPhoton = 4;
   const Int_t kMaxMuon = 2;
   const Int_t kMaxAntiKtJet = 20;
   const Int_t kMaxMissingET = 1;
   const Int_t kMaxScalarHT = 1;

class tauStudies {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           Event_;
   UInt_t          Event_fUniqueID[kMaxEvent];   //[Event_]
   UInt_t          Event_fBits[kMaxEvent];   //[Event_]
   Long64_t        Event_Number[kMaxEvent];   //[Event_]
   Float_t         Event_ReadTime[kMaxEvent];   //[Event_]
   Float_t         Event_ProcTime[kMaxEvent];   //[Event_]
   Int_t           Event_ProcessID[kMaxEvent];   //[Event_]
   Int_t           Event_MPI[kMaxEvent];   //[Event_]
   Float_t         Event_Weight[kMaxEvent];   //[Event_]
   Float_t         Event_CrossSection[kMaxEvent];   //[Event_]
   Float_t         Event_CrossSectionError[kMaxEvent];   //[Event_]
   Float_t         Event_Scale[kMaxEvent];   //[Event_]
   Float_t         Event_AlphaQED[kMaxEvent];   //[Event_]
   Float_t         Event_AlphaQCD[kMaxEvent];   //[Event_]
   Int_t           Event_ID1[kMaxEvent];   //[Event_]
   Int_t           Event_ID2[kMaxEvent];   //[Event_]
   Float_t         Event_X1[kMaxEvent];   //[Event_]
   Float_t         Event_X2[kMaxEvent];   //[Event_]
   Float_t         Event_ScalePDF[kMaxEvent];   //[Event_]
   Float_t         Event_PDF1[kMaxEvent];   //[Event_]
   Float_t         Event_PDF2[kMaxEvent];   //[Event_]
   Int_t           Event_size;
   Int_t           Particle_;
   UInt_t          Particle_fUniqueID[kMaxParticle];   //[Particle_]
   UInt_t          Particle_fBits[kMaxParticle];   //[Particle_]
   Int_t           Particle_PID[kMaxParticle];   //[Particle_]
   Int_t           Particle_Status[kMaxParticle];   //[Particle_]
   Int_t           Particle_IsPU[kMaxParticle];   //[Particle_]
   Int_t           Particle_M1[kMaxParticle];   //[Particle_]
   Int_t           Particle_M2[kMaxParticle];   //[Particle_]
   Int_t           Particle_D1[kMaxParticle];   //[Particle_]
   Int_t           Particle_D2[kMaxParticle];   //[Particle_]
   Int_t           Particle_Charge[kMaxParticle];   //[Particle_]
   Float_t         Particle_Mass[kMaxParticle];   //[Particle_]
   Float_t         Particle_E[kMaxParticle];   //[Particle_]
   Float_t         Particle_Px[kMaxParticle];   //[Particle_]
   Float_t         Particle_Py[kMaxParticle];   //[Particle_]
   Float_t         Particle_Pz[kMaxParticle];   //[Particle_]
   Float_t         Particle_P[kMaxParticle];   //[Particle_]
   Float_t         Particle_PT[kMaxParticle];   //[Particle_]
   Float_t         Particle_Eta[kMaxParticle];   //[Particle_]
   Float_t         Particle_Phi[kMaxParticle];   //[Particle_]
   Float_t         Particle_Rapidity[kMaxParticle];   //[Particle_]
   Float_t         Particle_CtgTheta[kMaxParticle];   //[Particle_]
   Float_t         Particle_D0[kMaxParticle];   //[Particle_]
   Float_t         Particle_DZ[kMaxParticle];   //[Particle_]
   Float_t         Particle_T[kMaxParticle];   //[Particle_]
   Float_t         Particle_X[kMaxParticle];   //[Particle_]
   Float_t         Particle_Y[kMaxParticle];   //[Particle_]
   Float_t         Particle_Z[kMaxParticle];   //[Particle_]
   Int_t           Particle_size;
   Int_t           Electron1_;
   UInt_t          Electron1_fUniqueID[kMaxElectron1];   //[Electron1_]
   UInt_t          Electron1_fBits[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_PT[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_Eta[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_Phi[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_T[kMaxElectron1];   //[Electron1_]
   Int_t           Electron1_Charge[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_EhadOverEem[kMaxElectron1];   //[Electron1_]
   TRef            Electron1_Particle[kMaxElectron1];
   Float_t         Electron1_IsolationVar[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_IsolationVarRhoCorr[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_SumPtCharged[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_SumPtNeutral[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_SumPtChargedPU[kMaxElectron1];   //[Electron1_]
   Float_t         Electron1_SumPt[kMaxElectron1];   //[Electron1_]
   Int_t           Electron1_size;
   Int_t           Electron2_;
   UInt_t          Electron2_fUniqueID[kMaxElectron2];   //[Electron2_]
   UInt_t          Electron2_fBits[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_PT[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_Eta[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_Phi[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_T[kMaxElectron2];   //[Electron2_]
   Int_t           Electron2_Charge[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_EhadOverEem[kMaxElectron2];   //[Electron2_]
   TRef            Electron2_Particle[kMaxElectron2];
   Float_t         Electron2_IsolationVar[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_IsolationVarRhoCorr[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_SumPtCharged[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_SumPtNeutral[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_SumPtChargedPU[kMaxElectron2];   //[Electron2_]
   Float_t         Electron2_SumPt[kMaxElectron2];   //[Electron2_]
   Int_t           Electron2_size;
   Int_t           Electron3_;
   UInt_t          Electron3_fUniqueID[kMaxElectron3];   //[Electron3_]
   UInt_t          Electron3_fBits[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_PT[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_Eta[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_Phi[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_T[kMaxElectron3];   //[Electron3_]
   Int_t           Electron3_Charge[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_EhadOverEem[kMaxElectron3];   //[Electron3_]
   TRef            Electron3_Particle[kMaxElectron3];
   Float_t         Electron3_IsolationVar[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_IsolationVarRhoCorr[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_SumPtCharged[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_SumPtNeutral[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_SumPtChargedPU[kMaxElectron3];   //[Electron3_]
   Float_t         Electron3_SumPt[kMaxElectron3];   //[Electron3_]
   Int_t           Electron3_size;
   Int_t           Electron4_;
   UInt_t          Electron4_fUniqueID[kMaxElectron4];   //[Electron4_]
   UInt_t          Electron4_fBits[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_PT[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_Eta[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_Phi[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_T[kMaxElectron4];   //[Electron4_]
   Int_t           Electron4_Charge[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_EhadOverEem[kMaxElectron4];   //[Electron4_]
   TRef            Electron4_Particle[kMaxElectron4];
   Float_t         Electron4_IsolationVar[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_IsolationVarRhoCorr[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_SumPtCharged[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_SumPtNeutral[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_SumPtChargedPU[kMaxElectron4];   //[Electron4_]
   Float_t         Electron4_SumPt[kMaxElectron4];   //[Electron4_]
   Int_t           Electron4_size;
   Int_t           Muon1_;
   UInt_t          Muon1_fUniqueID[kMaxMuon1];   //[Muon1_]
   UInt_t          Muon1_fBits[kMaxMuon1];   //[Muon1_]
   Float_t         Muon1_PT[kMaxMuon1];   //[Muon1_]
   Float_t         Muon1_Eta[kMaxMuon1];   //[Muon1_]
   Float_t         Muon1_Phi[kMaxMuon1];   //[Muon1_]
   Float_t         Muon1_T[kMaxMuon1];   //[Muon1_]
   Int_t           Muon1_Charge[kMaxMuon1];   //[Muon1_]
   TRef            Muon1_Particle[kMaxMuon1];
   Float_t         Muon1_IsolationVar[kMaxMuon1];   //[Muon1_]
   Float_t         Muon1_IsolationVarRhoCorr[kMaxMuon1];   //[Muon1_]
   Float_t         Muon1_SumPtCharged[kMaxMuon1];   //[Muon1_]
   Float_t         Muon1_SumPtNeutral[kMaxMuon1];   //[Muon1_]
   Float_t         Muon1_SumPtChargedPU[kMaxMuon1];   //[Muon1_]
   Float_t         Muon1_SumPt[kMaxMuon1];   //[Muon1_]
   Int_t           Muon1_size;
   Int_t           Muon2_;
   UInt_t          Muon2_fUniqueID[kMaxMuon2];   //[Muon2_]
   UInt_t          Muon2_fBits[kMaxMuon2];   //[Muon2_]
   Float_t         Muon2_PT[kMaxMuon2];   //[Muon2_]
   Float_t         Muon2_Eta[kMaxMuon2];   //[Muon2_]
   Float_t         Muon2_Phi[kMaxMuon2];   //[Muon2_]
   Float_t         Muon2_T[kMaxMuon2];   //[Muon2_]
   Int_t           Muon2_Charge[kMaxMuon2];   //[Muon2_]
   TRef            Muon2_Particle[kMaxMuon2];
   Float_t         Muon2_IsolationVar[kMaxMuon2];   //[Muon2_]
   Float_t         Muon2_IsolationVarRhoCorr[kMaxMuon2];   //[Muon2_]
   Float_t         Muon2_SumPtCharged[kMaxMuon2];   //[Muon2_]
   Float_t         Muon2_SumPtNeutral[kMaxMuon2];   //[Muon2_]
   Float_t         Muon2_SumPtChargedPU[kMaxMuon2];   //[Muon2_]
   Float_t         Muon2_SumPt[kMaxMuon2];   //[Muon2_]
   Int_t           Muon2_size;
   Int_t           Muon3_;
   UInt_t          Muon3_fUniqueID[kMaxMuon3];   //[Muon3_]
   UInt_t          Muon3_fBits[kMaxMuon3];   //[Muon3_]
   Float_t         Muon3_PT[kMaxMuon3];   //[Muon3_]
   Float_t         Muon3_Eta[kMaxMuon3];   //[Muon3_]
   Float_t         Muon3_Phi[kMaxMuon3];   //[Muon3_]
   Float_t         Muon3_T[kMaxMuon3];   //[Muon3_]
   Int_t           Muon3_Charge[kMaxMuon3];   //[Muon3_]
   TRef            Muon3_Particle[kMaxMuon3];
   Float_t         Muon3_IsolationVar[kMaxMuon3];   //[Muon3_]
   Float_t         Muon3_IsolationVarRhoCorr[kMaxMuon3];   //[Muon3_]
   Float_t         Muon3_SumPtCharged[kMaxMuon3];   //[Muon3_]
   Float_t         Muon3_SumPtNeutral[kMaxMuon3];   //[Muon3_]
   Float_t         Muon3_SumPtChargedPU[kMaxMuon3];   //[Muon3_]
   Float_t         Muon3_SumPt[kMaxMuon3];   //[Muon3_]
   Int_t           Muon3_size;
   Int_t           Track_;
   UInt_t          Track_fUniqueID[kMaxTrack];   //[Track_]
   UInt_t          Track_fBits[kMaxTrack];   //[Track_]
   Int_t           Track_PID[kMaxTrack];   //[Track_]
   Int_t           Track_Charge[kMaxTrack];   //[Track_]
   Float_t         Track_P[kMaxTrack];   //[Track_]
   Float_t         Track_PT[kMaxTrack];   //[Track_]
   Float_t         Track_Eta[kMaxTrack];   //[Track_]
   Float_t         Track_Phi[kMaxTrack];   //[Track_]
   Float_t         Track_CtgTheta[kMaxTrack];   //[Track_]
   Float_t         Track_EtaOuter[kMaxTrack];   //[Track_]
   Float_t         Track_PhiOuter[kMaxTrack];   //[Track_]
   Float_t         Track_T[kMaxTrack];   //[Track_]
   Float_t         Track_X[kMaxTrack];   //[Track_]
   Float_t         Track_Y[kMaxTrack];   //[Track_]
   Float_t         Track_Z[kMaxTrack];   //[Track_]
   Float_t         Track_TOuter[kMaxTrack];   //[Track_]
   Float_t         Track_XOuter[kMaxTrack];   //[Track_]
   Float_t         Track_YOuter[kMaxTrack];   //[Track_]
   Float_t         Track_ZOuter[kMaxTrack];   //[Track_]
   Float_t         Track_Xd[kMaxTrack];   //[Track_]
   Float_t         Track_Yd[kMaxTrack];   //[Track_]
   Float_t         Track_Zd[kMaxTrack];   //[Track_]
   Float_t         Track_L[kMaxTrack];   //[Track_]
   Float_t         Track_D0[kMaxTrack];   //[Track_]
   Float_t         Track_DZ[kMaxTrack];   //[Track_]
   Float_t         Track_ErrorP[kMaxTrack];   //[Track_]
   Float_t         Track_ErrorPT[kMaxTrack];   //[Track_]
   Float_t         Track_ErrorPhi[kMaxTrack];   //[Track_]
   Float_t         Track_ErrorCtgTheta[kMaxTrack];   //[Track_]
   Float_t         Track_ErrorT[kMaxTrack];   //[Track_]
   Float_t         Track_ErrorD0[kMaxTrack];   //[Track_]
   Float_t         Track_ErrorDZ[kMaxTrack];   //[Track_]
   TRef            Track_Particle[kMaxTrack];
   Int_t           Track_VertexIndex[kMaxTrack];   //[Track_]
   Int_t           Track_size;
   Int_t           Tower_;
   UInt_t          Tower_fUniqueID[kMaxTower];   //[Tower_]
   UInt_t          Tower_fBits[kMaxTower];   //[Tower_]
   Float_t         Tower_ET[kMaxTower];   //[Tower_]
   Float_t         Tower_Eta[kMaxTower];   //[Tower_]
   Float_t         Tower_Phi[kMaxTower];   //[Tower_]
   Float_t         Tower_E[kMaxTower];   //[Tower_]
   Float_t         Tower_T[kMaxTower];   //[Tower_]
   Int_t           Tower_NTimeHits[kMaxTower];   //[Tower_]
   Float_t         Tower_Eem[kMaxTower];   //[Tower_]
   Float_t         Tower_Ehad[kMaxTower];   //[Tower_]
   Float_t         Tower_Edges[kMaxTower][4];   //[Tower_]
   TRefArray       Tower_Particles[kMaxTower];
   Int_t           Tower_size;
   Int_t           EFlowTrack_;
   UInt_t          EFlowTrack_fUniqueID[kMaxEFlowTrack];   //[EFlowTrack_]
   UInt_t          EFlowTrack_fBits[kMaxEFlowTrack];   //[EFlowTrack_]
   Int_t           EFlowTrack_PID[kMaxEFlowTrack];   //[EFlowTrack_]
   Int_t           EFlowTrack_Charge[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_P[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_PT[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Eta[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Phi[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_CtgTheta[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_EtaOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_PhiOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_T[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_X[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Y[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Z[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_TOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_XOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_YOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_ZOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Xd[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Yd[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Zd[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_L[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_D0[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_DZ[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_ErrorP[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_ErrorPT[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_ErrorPhi[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_ErrorCtgTheta[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_ErrorT[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_ErrorD0[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_ErrorDZ[kMaxEFlowTrack];   //[EFlowTrack_]
   TRef            EFlowTrack_Particle[kMaxEFlowTrack];
   Int_t           EFlowTrack_VertexIndex[kMaxEFlowTrack];   //[EFlowTrack_]
   Int_t           EFlowTrack_size;
   Int_t           EFlowPhoton_;
   UInt_t          EFlowPhoton_fUniqueID[kMaxEFlowPhoton];   //[EFlowPhoton_]
   UInt_t          EFlowPhoton_fBits[kMaxEFlowPhoton];   //[EFlowPhoton_]
   Float_t         EFlowPhoton_ET[kMaxEFlowPhoton];   //[EFlowPhoton_]
   Float_t         EFlowPhoton_Eta[kMaxEFlowPhoton];   //[EFlowPhoton_]
   Float_t         EFlowPhoton_Phi[kMaxEFlowPhoton];   //[EFlowPhoton_]
   Float_t         EFlowPhoton_E[kMaxEFlowPhoton];   //[EFlowPhoton_]
   Float_t         EFlowPhoton_T[kMaxEFlowPhoton];   //[EFlowPhoton_]
   Int_t           EFlowPhoton_NTimeHits[kMaxEFlowPhoton];   //[EFlowPhoton_]
   Float_t         EFlowPhoton_Eem[kMaxEFlowPhoton];   //[EFlowPhoton_]
   Float_t         EFlowPhoton_Ehad[kMaxEFlowPhoton];   //[EFlowPhoton_]
   Float_t         EFlowPhoton_Edges[kMaxEFlowPhoton][4];   //[EFlowPhoton_]
   TRefArray       EFlowPhoton_Particles[kMaxEFlowPhoton];
   Int_t           EFlowPhoton_size;
   Int_t           EFlowNeutralHadron_;
   UInt_t          EFlowNeutralHadron_fUniqueID[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   UInt_t          EFlowNeutralHadron_fBits[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   Float_t         EFlowNeutralHadron_ET[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   Float_t         EFlowNeutralHadron_Eta[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   Float_t         EFlowNeutralHadron_Phi[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   Float_t         EFlowNeutralHadron_E[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   Float_t         EFlowNeutralHadron_T[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   Int_t           EFlowNeutralHadron_NTimeHits[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   Float_t         EFlowNeutralHadron_Eem[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   Float_t         EFlowNeutralHadron_Ehad[kMaxEFlowNeutralHadron];   //[EFlowNeutralHadron_]
   Float_t         EFlowNeutralHadron_Edges[kMaxEFlowNeutralHadron][4];   //[EFlowNeutralHadron_]
   TRefArray       EFlowNeutralHadron_Particles[kMaxEFlowNeutralHadron];
   Int_t           EFlowNeutralHadron_size;
   Int_t           GenJet_;
   UInt_t          GenJet_fUniqueID[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_fBits[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PT[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Eta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Phi[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_T[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Mass[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaEta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaPhi[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_Flavor[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_FlavorAlgo[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_FlavorPhys[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTag[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTagAlgo[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTagPhys[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_TauTag[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_TauWeight[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_Charge[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_EhadOverEem[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NCharged[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NNeutrals[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Beta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_BetaStar[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_MeanSqDeltaR[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PTD[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_FracPt[kMaxGenJet][5];   //[GenJet_]
   Float_t         GenJet_Tau[kMaxGenJet][5];   //[GenJet_]
   TLorentzVector  GenJet_SoftDroppedJet[kMaxGenJet];
   TLorentzVector  GenJet_SoftDroppedSubJet1[kMaxGenJet];
   TLorentzVector  GenJet_SoftDroppedSubJet2[kMaxGenJet];
   TLorentzVector  GenJet_TrimmedP4[5][kMaxGenJet];
   TLorentzVector  GenJet_PrunedP4[5][kMaxGenJet];
   TLorentzVector  GenJet_SoftDroppedP4[5][kMaxGenJet];
   Int_t           GenJet_NSubJetsTrimmed[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NSubJetsPruned[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NSubJetsSoftDropped[kMaxGenJet];   //[GenJet_]
   Double_t        GenJet_ExclYmerge23[kMaxGenJet];   //[GenJet_]
   Double_t        GenJet_ExclYmerge34[kMaxGenJet];   //[GenJet_]
   Double_t        GenJet_ExclYmerge45[kMaxGenJet];   //[GenJet_]
   Double_t        GenJet_ExclYmerge56[kMaxGenJet];   //[GenJet_]
   TRefArray       GenJet_Constituents[kMaxGenJet];
   TRefArray       GenJet_Particles[kMaxGenJet];
   TLorentzVector  GenJet_Area[kMaxGenJet];
   Int_t           GenJet_size;
   Int_t           GenMissingET_;
   UInt_t          GenMissingET_fUniqueID[kMaxGenMissingET];   //[GenMissingET_]
   UInt_t          GenMissingET_fBits[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_MET[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_Eta[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_Phi[kMaxGenMissingET];   //[GenMissingET_]
   Int_t           GenMissingET_size;
   Int_t           Jet_;
   UInt_t          Jet_fUniqueID[kMaxJet];   //[Jet_]
   UInt_t          Jet_fBits[kMaxJet];   //[Jet_]
   Float_t         Jet_PT[kMaxJet];   //[Jet_]
   Float_t         Jet_Eta[kMaxJet];   //[Jet_]
   Float_t         Jet_Phi[kMaxJet];   //[Jet_]
   Float_t         Jet_T[kMaxJet];   //[Jet_]
   Float_t         Jet_Mass[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaEta[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaPhi[kMaxJet];   //[Jet_]
   UInt_t          Jet_Flavor[kMaxJet];   //[Jet_]
   UInt_t          Jet_FlavorAlgo[kMaxJet];   //[Jet_]
   UInt_t          Jet_FlavorPhys[kMaxJet];   //[Jet_]
   UInt_t          Jet_BTag[kMaxJet];   //[Jet_]
   UInt_t          Jet_BTagAlgo[kMaxJet];   //[Jet_]
   UInt_t          Jet_BTagPhys[kMaxJet];   //[Jet_]
   UInt_t          Jet_TauTag[kMaxJet];   //[Jet_]
   Float_t         Jet_TauWeight[kMaxJet];   //[Jet_]
   Int_t           Jet_Charge[kMaxJet];   //[Jet_]
   Float_t         Jet_EhadOverEem[kMaxJet];   //[Jet_]
   Int_t           Jet_NCharged[kMaxJet];   //[Jet_]
   Int_t           Jet_NNeutrals[kMaxJet];   //[Jet_]
   Float_t         Jet_Beta[kMaxJet];   //[Jet_]
   Float_t         Jet_BetaStar[kMaxJet];   //[Jet_]
   Float_t         Jet_MeanSqDeltaR[kMaxJet];   //[Jet_]
   Float_t         Jet_PTD[kMaxJet];   //[Jet_]
   Float_t         Jet_FracPt[kMaxJet][5];   //[Jet_]
   Float_t         Jet_Tau[kMaxJet][5];   //[Jet_]
   TLorentzVector  Jet_SoftDroppedJet[kMaxJet];
   TLorentzVector  Jet_SoftDroppedSubJet1[kMaxJet];
   TLorentzVector  Jet_SoftDroppedSubJet2[kMaxJet];
   TLorentzVector  Jet_TrimmedP4[5][kMaxJet];
   TLorentzVector  Jet_PrunedP4[5][kMaxJet];
   TLorentzVector  Jet_SoftDroppedP4[5][kMaxJet];
   Int_t           Jet_NSubJetsTrimmed[kMaxJet];   //[Jet_]
   Int_t           Jet_NSubJetsPruned[kMaxJet];   //[Jet_]
   Int_t           Jet_NSubJetsSoftDropped[kMaxJet];   //[Jet_]
   Double_t        Jet_ExclYmerge23[kMaxJet];   //[Jet_]
   Double_t        Jet_ExclYmerge34[kMaxJet];   //[Jet_]
   Double_t        Jet_ExclYmerge45[kMaxJet];   //[Jet_]
   Double_t        Jet_ExclYmerge56[kMaxJet];   //[Jet_]
   TRefArray       Jet_Constituents[kMaxJet];
   TRefArray       Jet_Particles[kMaxJet];
   TLorentzVector  Jet_Area[kMaxJet];
   Int_t           Jet_size;
   Int_t           Electron_;
   UInt_t          Electron_fUniqueID[kMaxElectron];   //[Electron_]
   UInt_t          Electron_fBits[kMaxElectron];   //[Electron_]
   Float_t         Electron_PT[kMaxElectron];   //[Electron_]
   Float_t         Electron_Eta[kMaxElectron];   //[Electron_]
   Float_t         Electron_Phi[kMaxElectron];   //[Electron_]
   Float_t         Electron_T[kMaxElectron];   //[Electron_]
   Int_t           Electron_Charge[kMaxElectron];   //[Electron_]
   Float_t         Electron_EhadOverEem[kMaxElectron];   //[Electron_]
   TRef            Electron_Particle[kMaxElectron];
   Float_t         Electron_IsolationVar[kMaxElectron];   //[Electron_]
   Float_t         Electron_IsolationVarRhoCorr[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPtCharged[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPtNeutral[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPtChargedPU[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPt[kMaxElectron];   //[Electron_]
   Int_t           Electron_size;
   Int_t           Photon_;
   UInt_t          Photon_fUniqueID[kMaxPhoton];   //[Photon_]
   UInt_t          Photon_fBits[kMaxPhoton];   //[Photon_]
   Float_t         Photon_PT[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Eta[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Phi[kMaxPhoton];   //[Photon_]
   Float_t         Photon_E[kMaxPhoton];   //[Photon_]
   Float_t         Photon_T[kMaxPhoton];   //[Photon_]
   Float_t         Photon_EhadOverEem[kMaxPhoton];   //[Photon_]
   TRefArray       Photon_Particles[kMaxPhoton];
   Float_t         Photon_IsolationVar[kMaxPhoton];   //[Photon_]
   Float_t         Photon_IsolationVarRhoCorr[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPtCharged[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPtNeutral[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPtChargedPU[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPt[kMaxPhoton];   //[Photon_]
   Int_t           Photon_Status[kMaxPhoton];   //[Photon_]
   Int_t           Photon_size;
   Int_t           Muon_;
   UInt_t          Muon_fUniqueID[kMaxMuon];   //[Muon_]
   UInt_t          Muon_fBits[kMaxMuon];   //[Muon_]
   Float_t         Muon_PT[kMaxMuon];   //[Muon_]
   Float_t         Muon_Eta[kMaxMuon];   //[Muon_]
   Float_t         Muon_Phi[kMaxMuon];   //[Muon_]
   Float_t         Muon_T[kMaxMuon];   //[Muon_]
   Int_t           Muon_Charge[kMaxMuon];   //[Muon_]
   TRef            Muon_Particle[kMaxMuon];
   Float_t         Muon_IsolationVar[kMaxMuon];   //[Muon_]
   Float_t         Muon_IsolationVarRhoCorr[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPtCharged[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPtNeutral[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPtChargedPU[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPt[kMaxMuon];   //[Muon_]
   Int_t           Muon_size;
   Int_t           AntiKtJet_;
   UInt_t          AntiKtJet_fUniqueID[kMaxAntiKtJet];   //[AntiKtJet_]
   UInt_t          AntiKtJet_fBits[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_PT[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_Eta[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_Phi[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_T[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_Mass[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_DeltaEta[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_DeltaPhi[kMaxAntiKtJet];   //[AntiKtJet_]
   UInt_t          AntiKtJet_Flavor[kMaxAntiKtJet];   //[AntiKtJet_]
   UInt_t          AntiKtJet_FlavorAlgo[kMaxAntiKtJet];   //[AntiKtJet_]
   UInt_t          AntiKtJet_FlavorPhys[kMaxAntiKtJet];   //[AntiKtJet_]
   UInt_t          AntiKtJet_BTag[kMaxAntiKtJet];   //[AntiKtJet_]
   UInt_t          AntiKtJet_BTagAlgo[kMaxAntiKtJet];   //[AntiKtJet_]
   UInt_t          AntiKtJet_BTagPhys[kMaxAntiKtJet];   //[AntiKtJet_]
   UInt_t          AntiKtJet_TauTag[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_TauWeight[kMaxAntiKtJet];   //[AntiKtJet_]
   Int_t           AntiKtJet_Charge[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_EhadOverEem[kMaxAntiKtJet];   //[AntiKtJet_]
   Int_t           AntiKtJet_NCharged[kMaxAntiKtJet];   //[AntiKtJet_]
   Int_t           AntiKtJet_NNeutrals[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_Beta[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_BetaStar[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_MeanSqDeltaR[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_PTD[kMaxAntiKtJet];   //[AntiKtJet_]
   Float_t         AntiKtJet_FracPt[kMaxAntiKtJet][5];   //[AntiKtJet_]
   Float_t         AntiKtJet_Tau[kMaxAntiKtJet][5];   //[AntiKtJet_]
   TLorentzVector  AntiKtJet_SoftDroppedJet[kMaxAntiKtJet];
   TLorentzVector  AntiKtJet_SoftDroppedSubJet1[kMaxAntiKtJet];
   TLorentzVector  AntiKtJet_SoftDroppedSubJet2[kMaxAntiKtJet];
   TLorentzVector  AntiKtJet_TrimmedP4[5][kMaxAntiKtJet];
   TLorentzVector  AntiKtJet_PrunedP4[5][kMaxAntiKtJet];
   TLorentzVector  AntiKtJet_SoftDroppedP4[5][kMaxAntiKtJet];
   Int_t           AntiKtJet_NSubJetsTrimmed[kMaxAntiKtJet];   //[AntiKtJet_]
   Int_t           AntiKtJet_NSubJetsPruned[kMaxAntiKtJet];   //[AntiKtJet_]
   Int_t           AntiKtJet_NSubJetsSoftDropped[kMaxAntiKtJet];   //[AntiKtJet_]
   Double_t        AntiKtJet_ExclYmerge23[kMaxAntiKtJet];   //[AntiKtJet_]
   Double_t        AntiKtJet_ExclYmerge34[kMaxAntiKtJet];   //[AntiKtJet_]
   Double_t        AntiKtJet_ExclYmerge45[kMaxAntiKtJet];   //[AntiKtJet_]
   Double_t        AntiKtJet_ExclYmerge56[kMaxAntiKtJet];   //[AntiKtJet_]
   TRefArray       AntiKtJet_Constituents[kMaxAntiKtJet];
   TRefArray       AntiKtJet_Particles[kMaxAntiKtJet];
   TLorentzVector  AntiKtJet_Area[kMaxAntiKtJet];
   Int_t           AntiKtJet_size;
   Int_t           MissingET_;
   UInt_t          MissingET_fUniqueID[kMaxMissingET];   //[MissingET_]
   UInt_t          MissingET_fBits[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_MET[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_Eta[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_Phi[kMaxMissingET];   //[MissingET_]
   Int_t           MissingET_size;
   Int_t           ScalarHT_;
   UInt_t          ScalarHT_fUniqueID[kMaxScalarHT];   //[ScalarHT_]
   UInt_t          ScalarHT_fBits[kMaxScalarHT];   //[ScalarHT_]
   Float_t         ScalarHT_HT[kMaxScalarHT];   //[ScalarHT_]
   Int_t           ScalarHT_size;

   // List of branches
   TBranch        *b_Event_;   //!
   TBranch        *b_Event_fUniqueID;   //!
   TBranch        *b_Event_fBits;   //!
   TBranch        *b_Event_Number;   //!
   TBranch        *b_Event_ReadTime;   //!
   TBranch        *b_Event_ProcTime;   //!
   TBranch        *b_Event_ProcessID;   //!
   TBranch        *b_Event_MPI;   //!
   TBranch        *b_Event_Weight;   //!
   TBranch        *b_Event_CrossSection;   //!
   TBranch        *b_Event_CrossSectionError;   //!
   TBranch        *b_Event_Scale;   //!
   TBranch        *b_Event_AlphaQED;   //!
   TBranch        *b_Event_AlphaQCD;   //!
   TBranch        *b_Event_ID1;   //!
   TBranch        *b_Event_ID2;   //!
   TBranch        *b_Event_X1;   //!
   TBranch        *b_Event_X2;   //!
   TBranch        *b_Event_ScalePDF;   //!
   TBranch        *b_Event_PDF1;   //!
   TBranch        *b_Event_PDF2;   //!
   TBranch        *b_Event_size;   //!
   TBranch        *b_Particle_;   //!
   TBranch        *b_Particle_fUniqueID;   //!
   TBranch        *b_Particle_fBits;   //!
   TBranch        *b_Particle_PID;   //!
   TBranch        *b_Particle_Status;   //!
   TBranch        *b_Particle_IsPU;   //!
   TBranch        *b_Particle_M1;   //!
   TBranch        *b_Particle_M2;   //!
   TBranch        *b_Particle_D1;   //!
   TBranch        *b_Particle_D2;   //!
   TBranch        *b_Particle_Charge;   //!
   TBranch        *b_Particle_Mass;   //!
   TBranch        *b_Particle_E;   //!
   TBranch        *b_Particle_Px;   //!
   TBranch        *b_Particle_Py;   //!
   TBranch        *b_Particle_Pz;   //!
   TBranch        *b_Particle_P;   //!
   TBranch        *b_Particle_PT;   //!
   TBranch        *b_Particle_Eta;   //!
   TBranch        *b_Particle_Phi;   //!
   TBranch        *b_Particle_Rapidity;   //!
   TBranch        *b_Particle_CtgTheta;   //!
   TBranch        *b_Particle_D0;   //!
   TBranch        *b_Particle_DZ;   //!
   TBranch        *b_Particle_T;   //!
   TBranch        *b_Particle_X;   //!
   TBranch        *b_Particle_Y;   //!
   TBranch        *b_Particle_Z;   //!
   TBranch        *b_Particle_size;   //!
   TBranch        *b_Electron1_;   //!
   TBranch        *b_Electron1_fUniqueID;   //!
   TBranch        *b_Electron1_fBits;   //!
   TBranch        *b_Electron1_PT;   //!
   TBranch        *b_Electron1_Eta;   //!
   TBranch        *b_Electron1_Phi;   //!
   TBranch        *b_Electron1_T;   //!
   TBranch        *b_Electron1_Charge;   //!
   TBranch        *b_Electron1_EhadOverEem;   //!
   TBranch        *b_Electron1_Particle;   //!
   TBranch        *b_Electron1_IsolationVar;   //!
   TBranch        *b_Electron1_IsolationVarRhoCorr;   //!
   TBranch        *b_Electron1_SumPtCharged;   //!
   TBranch        *b_Electron1_SumPtNeutral;   //!
   TBranch        *b_Electron1_SumPtChargedPU;   //!
   TBranch        *b_Electron1_SumPt;   //!
   TBranch        *b_Electron1_size;   //!
   TBranch        *b_Electron2_;   //!
   TBranch        *b_Electron2_fUniqueID;   //!
   TBranch        *b_Electron2_fBits;   //!
   TBranch        *b_Electron2_PT;   //!
   TBranch        *b_Electron2_Eta;   //!
   TBranch        *b_Electron2_Phi;   //!
   TBranch        *b_Electron2_T;   //!
   TBranch        *b_Electron2_Charge;   //!
   TBranch        *b_Electron2_EhadOverEem;   //!
   TBranch        *b_Electron2_Particle;   //!
   TBranch        *b_Electron2_IsolationVar;   //!
   TBranch        *b_Electron2_IsolationVarRhoCorr;   //!
   TBranch        *b_Electron2_SumPtCharged;   //!
   TBranch        *b_Electron2_SumPtNeutral;   //!
   TBranch        *b_Electron2_SumPtChargedPU;   //!
   TBranch        *b_Electron2_SumPt;   //!
   TBranch        *b_Electron2_size;   //!
   TBranch        *b_Electron3_;   //!
   TBranch        *b_Electron3_fUniqueID;   //!
   TBranch        *b_Electron3_fBits;   //!
   TBranch        *b_Electron3_PT;   //!
   TBranch        *b_Electron3_Eta;   //!
   TBranch        *b_Electron3_Phi;   //!
   TBranch        *b_Electron3_T;   //!
   TBranch        *b_Electron3_Charge;   //!
   TBranch        *b_Electron3_EhadOverEem;   //!
   TBranch        *b_Electron3_Particle;   //!
   TBranch        *b_Electron3_IsolationVar;   //!
   TBranch        *b_Electron3_IsolationVarRhoCorr;   //!
   TBranch        *b_Electron3_SumPtCharged;   //!
   TBranch        *b_Electron3_SumPtNeutral;   //!
   TBranch        *b_Electron3_SumPtChargedPU;   //!
   TBranch        *b_Electron3_SumPt;   //!
   TBranch        *b_Electron3_size;   //!
   TBranch        *b_Electron4_;   //!
   TBranch        *b_Electron4_fUniqueID;   //!
   TBranch        *b_Electron4_fBits;   //!
   TBranch        *b_Electron4_PT;   //!
   TBranch        *b_Electron4_Eta;   //!
   TBranch        *b_Electron4_Phi;   //!
   TBranch        *b_Electron4_T;   //!
   TBranch        *b_Electron4_Charge;   //!
   TBranch        *b_Electron4_EhadOverEem;   //!
   TBranch        *b_Electron4_Particle;   //!
   TBranch        *b_Electron4_IsolationVar;   //!
   TBranch        *b_Electron4_IsolationVarRhoCorr;   //!
   TBranch        *b_Electron4_SumPtCharged;   //!
   TBranch        *b_Electron4_SumPtNeutral;   //!
   TBranch        *b_Electron4_SumPtChargedPU;   //!
   TBranch        *b_Electron4_SumPt;   //!
   TBranch        *b_Electron4_size;   //!
   TBranch        *b_Muon1_;   //!
   TBranch        *b_Muon1_fUniqueID;   //!
   TBranch        *b_Muon1_fBits;   //!
   TBranch        *b_Muon1_PT;   //!
   TBranch        *b_Muon1_Eta;   //!
   TBranch        *b_Muon1_Phi;   //!
   TBranch        *b_Muon1_T;   //!
   TBranch        *b_Muon1_Charge;   //!
   TBranch        *b_Muon1_Particle;   //!
   TBranch        *b_Muon1_IsolationVar;   //!
   TBranch        *b_Muon1_IsolationVarRhoCorr;   //!
   TBranch        *b_Muon1_SumPtCharged;   //!
   TBranch        *b_Muon1_SumPtNeutral;   //!
   TBranch        *b_Muon1_SumPtChargedPU;   //!
   TBranch        *b_Muon1_SumPt;   //!
   TBranch        *b_Muon1_size;   //!
   TBranch        *b_Muon2_;   //!
   TBranch        *b_Muon2_fUniqueID;   //!
   TBranch        *b_Muon2_fBits;   //!
   TBranch        *b_Muon2_PT;   //!
   TBranch        *b_Muon2_Eta;   //!
   TBranch        *b_Muon2_Phi;   //!
   TBranch        *b_Muon2_T;   //!
   TBranch        *b_Muon2_Charge;   //!
   TBranch        *b_Muon2_Particle;   //!
   TBranch        *b_Muon2_IsolationVar;   //!
   TBranch        *b_Muon2_IsolationVarRhoCorr;   //!
   TBranch        *b_Muon2_SumPtCharged;   //!
   TBranch        *b_Muon2_SumPtNeutral;   //!
   TBranch        *b_Muon2_SumPtChargedPU;   //!
   TBranch        *b_Muon2_SumPt;   //!
   TBranch        *b_Muon2_size;   //!
   TBranch        *b_Muon3_;   //!
   TBranch        *b_Muon3_fUniqueID;   //!
   TBranch        *b_Muon3_fBits;   //!
   TBranch        *b_Muon3_PT;   //!
   TBranch        *b_Muon3_Eta;   //!
   TBranch        *b_Muon3_Phi;   //!
   TBranch        *b_Muon3_T;   //!
   TBranch        *b_Muon3_Charge;   //!
   TBranch        *b_Muon3_Particle;   //!
   TBranch        *b_Muon3_IsolationVar;   //!
   TBranch        *b_Muon3_IsolationVarRhoCorr;   //!
   TBranch        *b_Muon3_SumPtCharged;   //!
   TBranch        *b_Muon3_SumPtNeutral;   //!
   TBranch        *b_Muon3_SumPtChargedPU;   //!
   TBranch        *b_Muon3_SumPt;   //!
   TBranch        *b_Muon3_size;   //!
   TBranch        *b_Track_;   //!
   TBranch        *b_Track_fUniqueID;   //!
   TBranch        *b_Track_fBits;   //!
   TBranch        *b_Track_PID;   //!
   TBranch        *b_Track_Charge;   //!
   TBranch        *b_Track_P;   //!
   TBranch        *b_Track_PT;   //!
   TBranch        *b_Track_Eta;   //!
   TBranch        *b_Track_Phi;   //!
   TBranch        *b_Track_CtgTheta;   //!
   TBranch        *b_Track_EtaOuter;   //!
   TBranch        *b_Track_PhiOuter;   //!
   TBranch        *b_Track_T;   //!
   TBranch        *b_Track_X;   //!
   TBranch        *b_Track_Y;   //!
   TBranch        *b_Track_Z;   //!
   TBranch        *b_Track_TOuter;   //!
   TBranch        *b_Track_XOuter;   //!
   TBranch        *b_Track_YOuter;   //!
   TBranch        *b_Track_ZOuter;   //!
   TBranch        *b_Track_Xd;   //!
   TBranch        *b_Track_Yd;   //!
   TBranch        *b_Track_Zd;   //!
   TBranch        *b_Track_L;   //!
   TBranch        *b_Track_D0;   //!
   TBranch        *b_Track_DZ;   //!
   TBranch        *b_Track_ErrorP;   //!
   TBranch        *b_Track_ErrorPT;   //!
   TBranch        *b_Track_ErrorPhi;   //!
   TBranch        *b_Track_ErrorCtgTheta;   //!
   TBranch        *b_Track_ErrorT;   //!
   TBranch        *b_Track_ErrorD0;   //!
   TBranch        *b_Track_ErrorDZ;   //!
   TBranch        *b_Track_Particle;   //!
   TBranch        *b_Track_VertexIndex;   //!
   TBranch        *b_Track_size;   //!
   TBranch        *b_Tower_;   //!
   TBranch        *b_Tower_fUniqueID;   //!
   TBranch        *b_Tower_fBits;   //!
   TBranch        *b_Tower_ET;   //!
   TBranch        *b_Tower_Eta;   //!
   TBranch        *b_Tower_Phi;   //!
   TBranch        *b_Tower_E;   //!
   TBranch        *b_Tower_T;   //!
   TBranch        *b_Tower_NTimeHits;   //!
   TBranch        *b_Tower_Eem;   //!
   TBranch        *b_Tower_Ehad;   //!
   TBranch        *b_Tower_Edges;   //!
   TBranch        *b_Tower_Particles;   //!
   TBranch        *b_Tower_size;   //!
   TBranch        *b_EFlowTrack_;   //!
   TBranch        *b_EFlowTrack_fUniqueID;   //!
   TBranch        *b_EFlowTrack_fBits;   //!
   TBranch        *b_EFlowTrack_PID;   //!
   TBranch        *b_EFlowTrack_Charge;   //!
   TBranch        *b_EFlowTrack_P;   //!
   TBranch        *b_EFlowTrack_PT;   //!
   TBranch        *b_EFlowTrack_Eta;   //!
   TBranch        *b_EFlowTrack_Phi;   //!
   TBranch        *b_EFlowTrack_CtgTheta;   //!
   TBranch        *b_EFlowTrack_EtaOuter;   //!
   TBranch        *b_EFlowTrack_PhiOuter;   //!
   TBranch        *b_EFlowTrack_T;   //!
   TBranch        *b_EFlowTrack_X;   //!
   TBranch        *b_EFlowTrack_Y;   //!
   TBranch        *b_EFlowTrack_Z;   //!
   TBranch        *b_EFlowTrack_TOuter;   //!
   TBranch        *b_EFlowTrack_XOuter;   //!
   TBranch        *b_EFlowTrack_YOuter;   //!
   TBranch        *b_EFlowTrack_ZOuter;   //!
   TBranch        *b_EFlowTrack_Xd;   //!
   TBranch        *b_EFlowTrack_Yd;   //!
   TBranch        *b_EFlowTrack_Zd;   //!
   TBranch        *b_EFlowTrack_L;   //!
   TBranch        *b_EFlowTrack_D0;   //!
   TBranch        *b_EFlowTrack_DZ;   //!
   TBranch        *b_EFlowTrack_ErrorP;   //!
   TBranch        *b_EFlowTrack_ErrorPT;   //!
   TBranch        *b_EFlowTrack_ErrorPhi;   //!
   TBranch        *b_EFlowTrack_ErrorCtgTheta;   //!
   TBranch        *b_EFlowTrack_ErrorT;   //!
   TBranch        *b_EFlowTrack_ErrorD0;   //!
   TBranch        *b_EFlowTrack_ErrorDZ;   //!
   TBranch        *b_EFlowTrack_Particle;   //!
   TBranch        *b_EFlowTrack_VertexIndex;   //!
   TBranch        *b_EFlowTrack_size;   //!
   TBranch        *b_EFlowPhoton_;   //!
   TBranch        *b_EFlowPhoton_fUniqueID;   //!
   TBranch        *b_EFlowPhoton_fBits;   //!
   TBranch        *b_EFlowPhoton_ET;   //!
   TBranch        *b_EFlowPhoton_Eta;   //!
   TBranch        *b_EFlowPhoton_Phi;   //!
   TBranch        *b_EFlowPhoton_E;   //!
   TBranch        *b_EFlowPhoton_T;   //!
   TBranch        *b_EFlowPhoton_NTimeHits;   //!
   TBranch        *b_EFlowPhoton_Eem;   //!
   TBranch        *b_EFlowPhoton_Ehad;   //!
   TBranch        *b_EFlowPhoton_Edges;   //!
   TBranch        *b_EFlowPhoton_Particles;   //!
   TBranch        *b_EFlowPhoton_size;   //!
   TBranch        *b_EFlowNeutralHadron_;   //!
   TBranch        *b_EFlowNeutralHadron_fUniqueID;   //!
   TBranch        *b_EFlowNeutralHadron_fBits;   //!
   TBranch        *b_EFlowNeutralHadron_ET;   //!
   TBranch        *b_EFlowNeutralHadron_Eta;   //!
   TBranch        *b_EFlowNeutralHadron_Phi;   //!
   TBranch        *b_EFlowNeutralHadron_E;   //!
   TBranch        *b_EFlowNeutralHadron_T;   //!
   TBranch        *b_EFlowNeutralHadron_NTimeHits;   //!
   TBranch        *b_EFlowNeutralHadron_Eem;   //!
   TBranch        *b_EFlowNeutralHadron_Ehad;   //!
   TBranch        *b_EFlowNeutralHadron_Edges;   //!
   TBranch        *b_EFlowNeutralHadron_Particles;   //!
   TBranch        *b_EFlowNeutralHadron_size;   //!
   TBranch        *b_GenJet_;   //!
   TBranch        *b_GenJet_fUniqueID;   //!
   TBranch        *b_GenJet_fBits;   //!
   TBranch        *b_GenJet_PT;   //!
   TBranch        *b_GenJet_Eta;   //!
   TBranch        *b_GenJet_Phi;   //!
   TBranch        *b_GenJet_T;   //!
   TBranch        *b_GenJet_Mass;   //!
   TBranch        *b_GenJet_DeltaEta;   //!
   TBranch        *b_GenJet_DeltaPhi;   //!
   TBranch        *b_GenJet_Flavor;   //!
   TBranch        *b_GenJet_FlavorAlgo;   //!
   TBranch        *b_GenJet_FlavorPhys;   //!
   TBranch        *b_GenJet_BTag;   //!
   TBranch        *b_GenJet_BTagAlgo;   //!
   TBranch        *b_GenJet_BTagPhys;   //!
   TBranch        *b_GenJet_TauTag;   //!
   TBranch        *b_GenJet_TauWeight;   //!
   TBranch        *b_GenJet_Charge;   //!
   TBranch        *b_GenJet_EhadOverEem;   //!
   TBranch        *b_GenJet_NCharged;   //!
   TBranch        *b_GenJet_NNeutrals;   //!
   TBranch        *b_GenJet_Beta;   //!
   TBranch        *b_GenJet_BetaStar;   //!
   TBranch        *b_GenJet_MeanSqDeltaR;   //!
   TBranch        *b_GenJet_PTD;   //!
   TBranch        *b_GenJet_FracPt;   //!
   TBranch        *b_GenJet_Tau;   //!
   TBranch        *b_GenJet_SoftDroppedJet;   //!
   TBranch        *b_GenJet_SoftDroppedSubJet1;   //!
   TBranch        *b_GenJet_SoftDroppedSubJet2;   //!
   TBranch        *b_GenJet_TrimmedP4;   //!
   TBranch        *b_GenJet_PrunedP4;   //!
   TBranch        *b_GenJet_SoftDroppedP4;   //!
   TBranch        *b_GenJet_NSubJetsTrimmed;   //!
   TBranch        *b_GenJet_NSubJetsPruned;   //!
   TBranch        *b_GenJet_NSubJetsSoftDropped;   //!
   TBranch        *b_GenJet_ExclYmerge23;   //!
   TBranch        *b_GenJet_ExclYmerge34;   //!
   TBranch        *b_GenJet_ExclYmerge45;   //!
   TBranch        *b_GenJet_ExclYmerge56;   //!
   TBranch        *b_GenJet_Constituents;   //!
   TBranch        *b_GenJet_Particles;   //!
   TBranch        *b_GenJet_Area;   //!
   TBranch        *b_GenJet_size;   //!
   TBranch        *b_GenMissingET_;   //!
   TBranch        *b_GenMissingET_fUniqueID;   //!
   TBranch        *b_GenMissingET_fBits;   //!
   TBranch        *b_GenMissingET_MET;   //!
   TBranch        *b_GenMissingET_Eta;   //!
   TBranch        *b_GenMissingET_Phi;   //!
   TBranch        *b_GenMissingET_size;   //!
   TBranch        *b_Jet_;   //!
   TBranch        *b_Jet_fUniqueID;   //!
   TBranch        *b_Jet_fBits;   //!
   TBranch        *b_Jet_PT;   //!
   TBranch        *b_Jet_Eta;   //!
   TBranch        *b_Jet_Phi;   //!
   TBranch        *b_Jet_T;   //!
   TBranch        *b_Jet_Mass;   //!
   TBranch        *b_Jet_DeltaEta;   //!
   TBranch        *b_Jet_DeltaPhi;   //!
   TBranch        *b_Jet_Flavor;   //!
   TBranch        *b_Jet_FlavorAlgo;   //!
   TBranch        *b_Jet_FlavorPhys;   //!
   TBranch        *b_Jet_BTag;   //!
   TBranch        *b_Jet_BTagAlgo;   //!
   TBranch        *b_Jet_BTagPhys;   //!
   TBranch        *b_Jet_TauTag;   //!
   TBranch        *b_Jet_TauWeight;   //!
   TBranch        *b_Jet_Charge;   //!
   TBranch        *b_Jet_EhadOverEem;   //!
   TBranch        *b_Jet_NCharged;   //!
   TBranch        *b_Jet_NNeutrals;   //!
   TBranch        *b_Jet_Beta;   //!
   TBranch        *b_Jet_BetaStar;   //!
   TBranch        *b_Jet_MeanSqDeltaR;   //!
   TBranch        *b_Jet_PTD;   //!
   TBranch        *b_Jet_FracPt;   //!
   TBranch        *b_Jet_Tau;   //!
   TBranch        *b_Jet_SoftDroppedJet;   //!
   TBranch        *b_Jet_SoftDroppedSubJet1;   //!
   TBranch        *b_Jet_SoftDroppedSubJet2;   //!
   TBranch        *b_Jet_TrimmedP4;   //!
   TBranch        *b_Jet_PrunedP4;   //!
   TBranch        *b_Jet_SoftDroppedP4;   //!
   TBranch        *b_Jet_NSubJetsTrimmed;   //!
   TBranch        *b_Jet_NSubJetsPruned;   //!
   TBranch        *b_Jet_NSubJetsSoftDropped;   //!
   TBranch        *b_Jet_ExclYmerge23;   //!
   TBranch        *b_Jet_ExclYmerge34;   //!
   TBranch        *b_Jet_ExclYmerge45;   //!
   TBranch        *b_Jet_ExclYmerge56;   //!
   TBranch        *b_Jet_Constituents;   //!
   TBranch        *b_Jet_Particles;   //!
   TBranch        *b_Jet_Area;   //!
   TBranch        *b_Jet_size;   //!
   TBranch        *b_Electron_;   //!
   TBranch        *b_Electron_fUniqueID;   //!
   TBranch        *b_Electron_fBits;   //!
   TBranch        *b_Electron_PT;   //!
   TBranch        *b_Electron_Eta;   //!
   TBranch        *b_Electron_Phi;   //!
   TBranch        *b_Electron_T;   //!
   TBranch        *b_Electron_Charge;   //!
   TBranch        *b_Electron_EhadOverEem;   //!
   TBranch        *b_Electron_Particle;   //!
   TBranch        *b_Electron_IsolationVar;   //!
   TBranch        *b_Electron_IsolationVarRhoCorr;   //!
   TBranch        *b_Electron_SumPtCharged;   //!
   TBranch        *b_Electron_SumPtNeutral;   //!
   TBranch        *b_Electron_SumPtChargedPU;   //!
   TBranch        *b_Electron_SumPt;   //!
   TBranch        *b_Electron_size;   //!
   TBranch        *b_Photon_;   //!
   TBranch        *b_Photon_fUniqueID;   //!
   TBranch        *b_Photon_fBits;   //!
   TBranch        *b_Photon_PT;   //!
   TBranch        *b_Photon_Eta;   //!
   TBranch        *b_Photon_Phi;   //!
   TBranch        *b_Photon_E;   //!
   TBranch        *b_Photon_T;   //!
   TBranch        *b_Photon_EhadOverEem;   //!
   TBranch        *b_Photon_Particles;   //!
   TBranch        *b_Photon_IsolationVar;   //!
   TBranch        *b_Photon_IsolationVarRhoCorr;   //!
   TBranch        *b_Photon_SumPtCharged;   //!
   TBranch        *b_Photon_SumPtNeutral;   //!
   TBranch        *b_Photon_SumPtChargedPU;   //!
   TBranch        *b_Photon_SumPt;   //!
   TBranch        *b_Photon_Status;   //!
   TBranch        *b_Photon_size;   //!
   TBranch        *b_Muon_;   //!
   TBranch        *b_Muon_fUniqueID;   //!
   TBranch        *b_Muon_fBits;   //!
   TBranch        *b_Muon_PT;   //!
   TBranch        *b_Muon_Eta;   //!
   TBranch        *b_Muon_Phi;   //!
   TBranch        *b_Muon_T;   //!
   TBranch        *b_Muon_Charge;   //!
   TBranch        *b_Muon_Particle;   //!
   TBranch        *b_Muon_IsolationVar;   //!
   TBranch        *b_Muon_IsolationVarRhoCorr;   //!
   TBranch        *b_Muon_SumPtCharged;   //!
   TBranch        *b_Muon_SumPtNeutral;   //!
   TBranch        *b_Muon_SumPtChargedPU;   //!
   TBranch        *b_Muon_SumPt;   //!
   TBranch        *b_Muon_size;   //!
   TBranch        *b_AntiKtJet_;   //!
   TBranch        *b_AntiKtJet_fUniqueID;   //!
   TBranch        *b_AntiKtJet_fBits;   //!
   TBranch        *b_AntiKtJet_PT;   //!
   TBranch        *b_AntiKtJet_Eta;   //!
   TBranch        *b_AntiKtJet_Phi;   //!
   TBranch        *b_AntiKtJet_T;   //!
   TBranch        *b_AntiKtJet_Mass;   //!
   TBranch        *b_AntiKtJet_DeltaEta;   //!
   TBranch        *b_AntiKtJet_DeltaPhi;   //!
   TBranch        *b_AntiKtJet_Flavor;   //!
   TBranch        *b_AntiKtJet_FlavorAlgo;   //!
   TBranch        *b_AntiKtJet_FlavorPhys;   //!
   TBranch        *b_AntiKtJet_BTag;   //!
   TBranch        *b_AntiKtJet_BTagAlgo;   //!
   TBranch        *b_AntiKtJet_BTagPhys;   //!
   TBranch        *b_AntiKtJet_TauTag;   //!
   TBranch        *b_AntiKtJet_TauWeight;   //!
   TBranch        *b_AntiKtJet_Charge;   //!
   TBranch        *b_AntiKtJet_EhadOverEem;   //!
   TBranch        *b_AntiKtJet_NCharged;   //!
   TBranch        *b_AntiKtJet_NNeutrals;   //!
   TBranch        *b_AntiKtJet_Beta;   //!
   TBranch        *b_AntiKtJet_BetaStar;   //!
   TBranch        *b_AntiKtJet_MeanSqDeltaR;   //!
   TBranch        *b_AntiKtJet_PTD;   //!
   TBranch        *b_AntiKtJet_FracPt;   //!
   TBranch        *b_AntiKtJet_Tau;   //!
   TBranch        *b_AntiKtJet_SoftDroppedJet;   //!
   TBranch        *b_AntiKtJet_SoftDroppedSubJet1;   //!
   TBranch        *b_AntiKtJet_SoftDroppedSubJet2;   //!
   TBranch        *b_AntiKtJet_TrimmedP4;   //!
   TBranch        *b_AntiKtJet_PrunedP4;   //!
   TBranch        *b_AntiKtJet_SoftDroppedP4;   //!
   TBranch        *b_AntiKtJet_NSubJetsTrimmed;   //!
   TBranch        *b_AntiKtJet_NSubJetsPruned;   //!
   TBranch        *b_AntiKtJet_NSubJetsSoftDropped;   //!
   TBranch        *b_AntiKtJet_ExclYmerge23;   //!
   TBranch        *b_AntiKtJet_ExclYmerge34;   //!
   TBranch        *b_AntiKtJet_ExclYmerge45;   //!
   TBranch        *b_AntiKtJet_ExclYmerge56;   //!
   TBranch        *b_AntiKtJet_Constituents;   //!
   TBranch        *b_AntiKtJet_Particles;   //!
   TBranch        *b_AntiKtJet_Area;   //!
   TBranch        *b_AntiKtJet_size;   //!
   TBranch        *b_MissingET_;   //!
   TBranch        *b_MissingET_fUniqueID;   //!
   TBranch        *b_MissingET_fBits;   //!
   TBranch        *b_MissingET_MET;   //!
   TBranch        *b_MissingET_Eta;   //!
   TBranch        *b_MissingET_Phi;   //!
   TBranch        *b_MissingET_size;   //!
   TBranch        *b_ScalarHT_;   //!
   TBranch        *b_ScalarHT_fUniqueID;   //!
   TBranch        *b_ScalarHT_fBits;   //!
   TBranch        *b_ScalarHT_HT;   //!
   TBranch        *b_ScalarHT_size;   //!

   tauStudies(TTree *tree=0);
   virtual ~tauStudies();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(const char*);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef tauStudies_cxx
tauStudies::tauStudies(TTree *tree): fChain(0) 
{
  if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("rootfile/ZH_tautaujets_30cm.root");
    if (!f || !f->IsOpen()) {
      f = new TFile("rootfile/ZH_tautaujets_30cm.root");
    }
    f->GetObject("Delphes",tree);

  }
  Init(tree);
}

tauStudies::~tauStudies()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tauStudies::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tauStudies::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void tauStudies::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_, &b_Event_);
   fChain->SetBranchAddress("Event.fUniqueID", Event_fUniqueID, &b_Event_fUniqueID);
   fChain->SetBranchAddress("Event.fBits", Event_fBits, &b_Event_fBits);
   fChain->SetBranchAddress("Event.Number", Event_Number, &b_Event_Number);
   fChain->SetBranchAddress("Event.ReadTime", Event_ReadTime, &b_Event_ReadTime);
   fChain->SetBranchAddress("Event.ProcTime", Event_ProcTime, &b_Event_ProcTime);
   fChain->SetBranchAddress("Event.ProcessID", Event_ProcessID, &b_Event_ProcessID);
   fChain->SetBranchAddress("Event.MPI", Event_MPI, &b_Event_MPI);
   fChain->SetBranchAddress("Event.Weight", Event_Weight, &b_Event_Weight);
   fChain->SetBranchAddress("Event.CrossSection", Event_CrossSection, &b_Event_CrossSection);
   fChain->SetBranchAddress("Event.CrossSectionError", Event_CrossSectionError, &b_Event_CrossSectionError);
   fChain->SetBranchAddress("Event.Scale", Event_Scale, &b_Event_Scale);
   fChain->SetBranchAddress("Event.AlphaQED", Event_AlphaQED, &b_Event_AlphaQED);
   fChain->SetBranchAddress("Event.AlphaQCD", Event_AlphaQCD, &b_Event_AlphaQCD);
   fChain->SetBranchAddress("Event.ID1", Event_ID1, &b_Event_ID1);
   fChain->SetBranchAddress("Event.ID2", Event_ID2, &b_Event_ID2);
   fChain->SetBranchAddress("Event.X1", Event_X1, &b_Event_X1);
   fChain->SetBranchAddress("Event.X2", Event_X2, &b_Event_X2);
   fChain->SetBranchAddress("Event.ScalePDF", Event_ScalePDF, &b_Event_ScalePDF);
   fChain->SetBranchAddress("Event.PDF1", Event_PDF1, &b_Event_PDF1);
   fChain->SetBranchAddress("Event.PDF2", Event_PDF2, &b_Event_PDF2);
   fChain->SetBranchAddress("Event_size", &Event_size, &b_Event_size);
   fChain->SetBranchAddress("Particle", &Particle_, &b_Particle_);
   fChain->SetBranchAddress("Particle.fUniqueID", Particle_fUniqueID, &b_Particle_fUniqueID);
   fChain->SetBranchAddress("Particle.fBits", Particle_fBits, &b_Particle_fBits);
   fChain->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
   fChain->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
   fChain->SetBranchAddress("Particle.IsPU", Particle_IsPU, &b_Particle_IsPU);
   fChain->SetBranchAddress("Particle.M1", Particle_M1, &b_Particle_M1);
   fChain->SetBranchAddress("Particle.M2", Particle_M2, &b_Particle_M2);
   fChain->SetBranchAddress("Particle.D1", Particle_D1, &b_Particle_D1);
   fChain->SetBranchAddress("Particle.D2", Particle_D2, &b_Particle_D2);
   fChain->SetBranchAddress("Particle.Charge", Particle_Charge, &b_Particle_Charge);
   fChain->SetBranchAddress("Particle.Mass", Particle_Mass, &b_Particle_Mass);
   fChain->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
   fChain->SetBranchAddress("Particle.Px", Particle_Px, &b_Particle_Px);
   fChain->SetBranchAddress("Particle.Py", Particle_Py, &b_Particle_Py);
   fChain->SetBranchAddress("Particle.Pz", Particle_Pz, &b_Particle_Pz);
   fChain->SetBranchAddress("Particle.P", Particle_P, &b_Particle_P);
   fChain->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
   fChain->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
   fChain->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
   fChain->SetBranchAddress("Particle.Rapidity", Particle_Rapidity, &b_Particle_Rapidity);
   fChain->SetBranchAddress("Particle.CtgTheta", Particle_CtgTheta, &b_Particle_CtgTheta);
   fChain->SetBranchAddress("Particle.D0", Particle_D0, &b_Particle_D0);
   fChain->SetBranchAddress("Particle.DZ", Particle_DZ, &b_Particle_DZ);
   fChain->SetBranchAddress("Particle.T", Particle_T, &b_Particle_T);
   fChain->SetBranchAddress("Particle.X", Particle_X, &b_Particle_X);
   fChain->SetBranchAddress("Particle.Y", Particle_Y, &b_Particle_Y);
   fChain->SetBranchAddress("Particle.Z", Particle_Z, &b_Particle_Z);
   fChain->SetBranchAddress("Particle_size", &Particle_size, &b_Particle_size);
   fChain->SetBranchAddress("Electron1", &Electron1_, &b_Electron1_);
   fChain->SetBranchAddress("Electron1.fUniqueID", Electron1_fUniqueID, &b_Electron1_fUniqueID);
   fChain->SetBranchAddress("Electron1.fBits", Electron1_fBits, &b_Electron1_fBits);
   fChain->SetBranchAddress("Electron1.PT", Electron1_PT, &b_Electron1_PT);
   fChain->SetBranchAddress("Electron1.Eta", Electron1_Eta, &b_Electron1_Eta);
   fChain->SetBranchAddress("Electron1.Phi", Electron1_Phi, &b_Electron1_Phi);
   fChain->SetBranchAddress("Electron1.T", Electron1_T, &b_Electron1_T);
   fChain->SetBranchAddress("Electron1.Charge", Electron1_Charge, &b_Electron1_Charge);
   fChain->SetBranchAddress("Electron1.EhadOverEem", Electron1_EhadOverEem, &b_Electron1_EhadOverEem);
   fChain->SetBranchAddress("Electron1.Particle", Electron1_Particle, &b_Electron1_Particle);
   fChain->SetBranchAddress("Electron1.IsolationVar", Electron1_IsolationVar, &b_Electron1_IsolationVar);
   fChain->SetBranchAddress("Electron1.IsolationVarRhoCorr", Electron1_IsolationVarRhoCorr, &b_Electron1_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Electron1.SumPtCharged", Electron1_SumPtCharged, &b_Electron1_SumPtCharged);
   fChain->SetBranchAddress("Electron1.SumPtNeutral", Electron1_SumPtNeutral, &b_Electron1_SumPtNeutral);
   fChain->SetBranchAddress("Electron1.SumPtChargedPU", Electron1_SumPtChargedPU, &b_Electron1_SumPtChargedPU);
   fChain->SetBranchAddress("Electron1.SumPt", Electron1_SumPt, &b_Electron1_SumPt);
   fChain->SetBranchAddress("Electron1_size", &Electron1_size, &b_Electron1_size);
   fChain->SetBranchAddress("Electron2", &Electron2_, &b_Electron2_);
   fChain->SetBranchAddress("Electron2.fUniqueID", Electron2_fUniqueID, &b_Electron2_fUniqueID);
   fChain->SetBranchAddress("Electron2.fBits", Electron2_fBits, &b_Electron2_fBits);
   fChain->SetBranchAddress("Electron2.PT", Electron2_PT, &b_Electron2_PT);
   fChain->SetBranchAddress("Electron2.Eta", Electron2_Eta, &b_Electron2_Eta);
   fChain->SetBranchAddress("Electron2.Phi", Electron2_Phi, &b_Electron2_Phi);
   fChain->SetBranchAddress("Electron2.T", Electron2_T, &b_Electron2_T);
   fChain->SetBranchAddress("Electron2.Charge", Electron2_Charge, &b_Electron2_Charge);
   fChain->SetBranchAddress("Electron2.EhadOverEem", Electron2_EhadOverEem, &b_Electron2_EhadOverEem);
   fChain->SetBranchAddress("Electron2.Particle", Electron2_Particle, &b_Electron2_Particle);
   fChain->SetBranchAddress("Electron2.IsolationVar", Electron2_IsolationVar, &b_Electron2_IsolationVar);
   fChain->SetBranchAddress("Electron2.IsolationVarRhoCorr", Electron2_IsolationVarRhoCorr, &b_Electron2_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Electron2.SumPtCharged", Electron2_SumPtCharged, &b_Electron2_SumPtCharged);
   fChain->SetBranchAddress("Electron2.SumPtNeutral", Electron2_SumPtNeutral, &b_Electron2_SumPtNeutral);
   fChain->SetBranchAddress("Electron2.SumPtChargedPU", Electron2_SumPtChargedPU, &b_Electron2_SumPtChargedPU);
   fChain->SetBranchAddress("Electron2.SumPt", Electron2_SumPt, &b_Electron2_SumPt);
   fChain->SetBranchAddress("Electron2_size", &Electron2_size, &b_Electron2_size);
   fChain->SetBranchAddress("Electron3", &Electron3_, &b_Electron3_);
   fChain->SetBranchAddress("Electron3.fUniqueID", Electron3_fUniqueID, &b_Electron3_fUniqueID);
   fChain->SetBranchAddress("Electron3.fBits", Electron3_fBits, &b_Electron3_fBits);
   fChain->SetBranchAddress("Electron3.PT", Electron3_PT, &b_Electron3_PT);
   fChain->SetBranchAddress("Electron3.Eta", Electron3_Eta, &b_Electron3_Eta);
   fChain->SetBranchAddress("Electron3.Phi", Electron3_Phi, &b_Electron3_Phi);
   fChain->SetBranchAddress("Electron3.T", Electron3_T, &b_Electron3_T);
   fChain->SetBranchAddress("Electron3.Charge", Electron3_Charge, &b_Electron3_Charge);
   fChain->SetBranchAddress("Electron3.EhadOverEem", Electron3_EhadOverEem, &b_Electron3_EhadOverEem);
   fChain->SetBranchAddress("Electron3.Particle", Electron3_Particle, &b_Electron3_Particle);
   fChain->SetBranchAddress("Electron3.IsolationVar", Electron3_IsolationVar, &b_Electron3_IsolationVar);
   fChain->SetBranchAddress("Electron3.IsolationVarRhoCorr", Electron3_IsolationVarRhoCorr, &b_Electron3_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Electron3.SumPtCharged", Electron3_SumPtCharged, &b_Electron3_SumPtCharged);
   fChain->SetBranchAddress("Electron3.SumPtNeutral", Electron3_SumPtNeutral, &b_Electron3_SumPtNeutral);
   fChain->SetBranchAddress("Electron3.SumPtChargedPU", Electron3_SumPtChargedPU, &b_Electron3_SumPtChargedPU);
   fChain->SetBranchAddress("Electron3.SumPt", Electron3_SumPt, &b_Electron3_SumPt);
   fChain->SetBranchAddress("Electron3_size", &Electron3_size, &b_Electron3_size);
   fChain->SetBranchAddress("Electron4", &Electron4_, &b_Electron4_);
   fChain->SetBranchAddress("Electron4.fUniqueID", Electron4_fUniqueID, &b_Electron4_fUniqueID);
   fChain->SetBranchAddress("Electron4.fBits", Electron4_fBits, &b_Electron4_fBits);
   fChain->SetBranchAddress("Electron4.PT", Electron4_PT, &b_Electron4_PT);
   fChain->SetBranchAddress("Electron4.Eta", Electron4_Eta, &b_Electron4_Eta);
   fChain->SetBranchAddress("Electron4.Phi", Electron4_Phi, &b_Electron4_Phi);
   fChain->SetBranchAddress("Electron4.T", Electron4_T, &b_Electron4_T);
   fChain->SetBranchAddress("Electron4.Charge", Electron4_Charge, &b_Electron4_Charge);
   fChain->SetBranchAddress("Electron4.EhadOverEem", Electron4_EhadOverEem, &b_Electron4_EhadOverEem);
   fChain->SetBranchAddress("Electron4.Particle", Electron4_Particle, &b_Electron4_Particle);
   fChain->SetBranchAddress("Electron4.IsolationVar", Electron4_IsolationVar, &b_Electron4_IsolationVar);
   fChain->SetBranchAddress("Electron4.IsolationVarRhoCorr", Electron4_IsolationVarRhoCorr, &b_Electron4_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Electron4.SumPtCharged", Electron4_SumPtCharged, &b_Electron4_SumPtCharged);
   fChain->SetBranchAddress("Electron4.SumPtNeutral", Electron4_SumPtNeutral, &b_Electron4_SumPtNeutral);
   fChain->SetBranchAddress("Electron4.SumPtChargedPU", Electron4_SumPtChargedPU, &b_Electron4_SumPtChargedPU);
   fChain->SetBranchAddress("Electron4.SumPt", Electron4_SumPt, &b_Electron4_SumPt);
   fChain->SetBranchAddress("Electron4_size", &Electron4_size, &b_Electron4_size);
   fChain->SetBranchAddress("Muon1", &Muon1_, &b_Muon1_);
   fChain->SetBranchAddress("Muon1.fUniqueID", Muon1_fUniqueID, &b_Muon1_fUniqueID);
   fChain->SetBranchAddress("Muon1.fBits", Muon1_fBits, &b_Muon1_fBits);
   fChain->SetBranchAddress("Muon1.PT", Muon1_PT, &b_Muon1_PT);
   fChain->SetBranchAddress("Muon1.Eta", Muon1_Eta, &b_Muon1_Eta);
   fChain->SetBranchAddress("Muon1.Phi", Muon1_Phi, &b_Muon1_Phi);
   fChain->SetBranchAddress("Muon1.T", Muon1_T, &b_Muon1_T);
   fChain->SetBranchAddress("Muon1.Charge", Muon1_Charge, &b_Muon1_Charge);
   fChain->SetBranchAddress("Muon1.Particle", Muon1_Particle, &b_Muon1_Particle);
   fChain->SetBranchAddress("Muon1.IsolationVar", Muon1_IsolationVar, &b_Muon1_IsolationVar);
   fChain->SetBranchAddress("Muon1.IsolationVarRhoCorr", Muon1_IsolationVarRhoCorr, &b_Muon1_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Muon1.SumPtCharged", Muon1_SumPtCharged, &b_Muon1_SumPtCharged);
   fChain->SetBranchAddress("Muon1.SumPtNeutral", Muon1_SumPtNeutral, &b_Muon1_SumPtNeutral);
   fChain->SetBranchAddress("Muon1.SumPtChargedPU", Muon1_SumPtChargedPU, &b_Muon1_SumPtChargedPU);
   fChain->SetBranchAddress("Muon1.SumPt", Muon1_SumPt, &b_Muon1_SumPt);
   fChain->SetBranchAddress("Muon1_size", &Muon1_size, &b_Muon1_size);
   fChain->SetBranchAddress("Muon2", &Muon2_, &b_Muon2_);
   fChain->SetBranchAddress("Muon2.fUniqueID", Muon2_fUniqueID, &b_Muon2_fUniqueID);
   fChain->SetBranchAddress("Muon2.fBits", Muon2_fBits, &b_Muon2_fBits);
   fChain->SetBranchAddress("Muon2.PT", Muon2_PT, &b_Muon2_PT);
   fChain->SetBranchAddress("Muon2.Eta", Muon2_Eta, &b_Muon2_Eta);
   fChain->SetBranchAddress("Muon2.Phi", Muon2_Phi, &b_Muon2_Phi);
   fChain->SetBranchAddress("Muon2.T", Muon2_T, &b_Muon2_T);
   fChain->SetBranchAddress("Muon2.Charge", Muon2_Charge, &b_Muon2_Charge);
   fChain->SetBranchAddress("Muon2.Particle", Muon2_Particle, &b_Muon2_Particle);
   fChain->SetBranchAddress("Muon2.IsolationVar", Muon2_IsolationVar, &b_Muon2_IsolationVar);
   fChain->SetBranchAddress("Muon2.IsolationVarRhoCorr", Muon2_IsolationVarRhoCorr, &b_Muon2_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Muon2.SumPtCharged", Muon2_SumPtCharged, &b_Muon2_SumPtCharged);
   fChain->SetBranchAddress("Muon2.SumPtNeutral", Muon2_SumPtNeutral, &b_Muon2_SumPtNeutral);
   fChain->SetBranchAddress("Muon2.SumPtChargedPU", Muon2_SumPtChargedPU, &b_Muon2_SumPtChargedPU);
   fChain->SetBranchAddress("Muon2.SumPt", Muon2_SumPt, &b_Muon2_SumPt);
   fChain->SetBranchAddress("Muon2_size", &Muon2_size, &b_Muon2_size);
   fChain->SetBranchAddress("Muon3", &Muon3_, &b_Muon3_);
   fChain->SetBranchAddress("Muon3.fUniqueID", Muon3_fUniqueID, &b_Muon3_fUniqueID);
   fChain->SetBranchAddress("Muon3.fBits", Muon3_fBits, &b_Muon3_fBits);
   fChain->SetBranchAddress("Muon3.PT", Muon3_PT, &b_Muon3_PT);
   fChain->SetBranchAddress("Muon3.Eta", Muon3_Eta, &b_Muon3_Eta);
   fChain->SetBranchAddress("Muon3.Phi", Muon3_Phi, &b_Muon3_Phi);
   fChain->SetBranchAddress("Muon3.T", Muon3_T, &b_Muon3_T);
   fChain->SetBranchAddress("Muon3.Charge", Muon3_Charge, &b_Muon3_Charge);
   fChain->SetBranchAddress("Muon3.Particle", Muon3_Particle, &b_Muon3_Particle);
   fChain->SetBranchAddress("Muon3.IsolationVar", Muon3_IsolationVar, &b_Muon3_IsolationVar);
   fChain->SetBranchAddress("Muon3.IsolationVarRhoCorr", Muon3_IsolationVarRhoCorr, &b_Muon3_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Muon3.SumPtCharged", Muon3_SumPtCharged, &b_Muon3_SumPtCharged);
   fChain->SetBranchAddress("Muon3.SumPtNeutral", Muon3_SumPtNeutral, &b_Muon3_SumPtNeutral);
   fChain->SetBranchAddress("Muon3.SumPtChargedPU", Muon3_SumPtChargedPU, &b_Muon3_SumPtChargedPU);
   fChain->SetBranchAddress("Muon3.SumPt", Muon3_SumPt, &b_Muon3_SumPt);
   fChain->SetBranchAddress("Muon3_size", &Muon3_size, &b_Muon3_size);
   fChain->SetBranchAddress("Track", &Track_, &b_Track_);
   fChain->SetBranchAddress("Track.fUniqueID", Track_fUniqueID, &b_Track_fUniqueID);
   fChain->SetBranchAddress("Track.fBits", Track_fBits, &b_Track_fBits);
   fChain->SetBranchAddress("Track.PID", Track_PID, &b_Track_PID);
   fChain->SetBranchAddress("Track.Charge", Track_Charge, &b_Track_Charge);
   fChain->SetBranchAddress("Track.P", Track_P, &b_Track_P);
   fChain->SetBranchAddress("Track.PT", Track_PT, &b_Track_PT);
   fChain->SetBranchAddress("Track.Eta", Track_Eta, &b_Track_Eta);
   fChain->SetBranchAddress("Track.Phi", Track_Phi, &b_Track_Phi);
   fChain->SetBranchAddress("Track.CtgTheta", Track_CtgTheta, &b_Track_CtgTheta);
   fChain->SetBranchAddress("Track.EtaOuter", Track_EtaOuter, &b_Track_EtaOuter);
   fChain->SetBranchAddress("Track.PhiOuter", Track_PhiOuter, &b_Track_PhiOuter);
   fChain->SetBranchAddress("Track.T", Track_T, &b_Track_T);
   fChain->SetBranchAddress("Track.X", Track_X, &b_Track_X);
   fChain->SetBranchAddress("Track.Y", Track_Y, &b_Track_Y);
   fChain->SetBranchAddress("Track.Z", Track_Z, &b_Track_Z);
   fChain->SetBranchAddress("Track.TOuter", Track_TOuter, &b_Track_TOuter);
   fChain->SetBranchAddress("Track.XOuter", Track_XOuter, &b_Track_XOuter);
   fChain->SetBranchAddress("Track.YOuter", Track_YOuter, &b_Track_YOuter);
   fChain->SetBranchAddress("Track.ZOuter", Track_ZOuter, &b_Track_ZOuter);
   fChain->SetBranchAddress("Track.Xd", Track_Xd, &b_Track_Xd);
   fChain->SetBranchAddress("Track.Yd", Track_Yd, &b_Track_Yd);
   fChain->SetBranchAddress("Track.Zd", Track_Zd, &b_Track_Zd);
   fChain->SetBranchAddress("Track.L", Track_L, &b_Track_L);
   fChain->SetBranchAddress("Track.D0", Track_D0, &b_Track_D0);
   fChain->SetBranchAddress("Track.DZ", Track_DZ, &b_Track_DZ);
   fChain->SetBranchAddress("Track.ErrorP", Track_ErrorP, &b_Track_ErrorP);
   fChain->SetBranchAddress("Track.ErrorPT", Track_ErrorPT, &b_Track_ErrorPT);
   fChain->SetBranchAddress("Track.ErrorPhi", Track_ErrorPhi, &b_Track_ErrorPhi);
   fChain->SetBranchAddress("Track.ErrorCtgTheta", Track_ErrorCtgTheta, &b_Track_ErrorCtgTheta);
   fChain->SetBranchAddress("Track.ErrorT", Track_ErrorT, &b_Track_ErrorT);
   fChain->SetBranchAddress("Track.ErrorD0", Track_ErrorD0, &b_Track_ErrorD0);
   fChain->SetBranchAddress("Track.ErrorDZ", Track_ErrorDZ, &b_Track_ErrorDZ);
   fChain->SetBranchAddress("Track.Particle", Track_Particle, &b_Track_Particle);
   fChain->SetBranchAddress("Track.VertexIndex", Track_VertexIndex, &b_Track_VertexIndex);
   fChain->SetBranchAddress("Track_size", &Track_size, &b_Track_size);
   fChain->SetBranchAddress("Tower", &Tower_, &b_Tower_);
   fChain->SetBranchAddress("Tower.fUniqueID", Tower_fUniqueID, &b_Tower_fUniqueID);
   fChain->SetBranchAddress("Tower.fBits", Tower_fBits, &b_Tower_fBits);
   fChain->SetBranchAddress("Tower.ET", Tower_ET, &b_Tower_ET);
   fChain->SetBranchAddress("Tower.Eta", Tower_Eta, &b_Tower_Eta);
   fChain->SetBranchAddress("Tower.Phi", Tower_Phi, &b_Tower_Phi);
   fChain->SetBranchAddress("Tower.E", Tower_E, &b_Tower_E);
   fChain->SetBranchAddress("Tower.T", Tower_T, &b_Tower_T);
   fChain->SetBranchAddress("Tower.NTimeHits", Tower_NTimeHits, &b_Tower_NTimeHits);
   fChain->SetBranchAddress("Tower.Eem", Tower_Eem, &b_Tower_Eem);
   fChain->SetBranchAddress("Tower.Ehad", Tower_Ehad, &b_Tower_Ehad);
   fChain->SetBranchAddress("Tower.Edges[4]", Tower_Edges, &b_Tower_Edges);
   fChain->SetBranchAddress("Tower.Particles", Tower_Particles, &b_Tower_Particles);
   fChain->SetBranchAddress("Tower_size", &Tower_size, &b_Tower_size);
   fChain->SetBranchAddress("EFlowTrack", &EFlowTrack_, &b_EFlowTrack_);
   fChain->SetBranchAddress("EFlowTrack.fUniqueID", EFlowTrack_fUniqueID, &b_EFlowTrack_fUniqueID);
   fChain->SetBranchAddress("EFlowTrack.fBits", EFlowTrack_fBits, &b_EFlowTrack_fBits);
   fChain->SetBranchAddress("EFlowTrack.PID", EFlowTrack_PID, &b_EFlowTrack_PID);
   fChain->SetBranchAddress("EFlowTrack.Charge", EFlowTrack_Charge, &b_EFlowTrack_Charge);
   fChain->SetBranchAddress("EFlowTrack.P", EFlowTrack_P, &b_EFlowTrack_P);
   fChain->SetBranchAddress("EFlowTrack.PT", EFlowTrack_PT, &b_EFlowTrack_PT);
   fChain->SetBranchAddress("EFlowTrack.Eta", EFlowTrack_Eta, &b_EFlowTrack_Eta);
   fChain->SetBranchAddress("EFlowTrack.Phi", EFlowTrack_Phi, &b_EFlowTrack_Phi);
   fChain->SetBranchAddress("EFlowTrack.CtgTheta", EFlowTrack_CtgTheta, &b_EFlowTrack_CtgTheta);
   fChain->SetBranchAddress("EFlowTrack.EtaOuter", EFlowTrack_EtaOuter, &b_EFlowTrack_EtaOuter);
   fChain->SetBranchAddress("EFlowTrack.PhiOuter", EFlowTrack_PhiOuter, &b_EFlowTrack_PhiOuter);
   fChain->SetBranchAddress("EFlowTrack.T", EFlowTrack_T, &b_EFlowTrack_T);
   fChain->SetBranchAddress("EFlowTrack.X", EFlowTrack_X, &b_EFlowTrack_X);
   fChain->SetBranchAddress("EFlowTrack.Y", EFlowTrack_Y, &b_EFlowTrack_Y);
   fChain->SetBranchAddress("EFlowTrack.Z", EFlowTrack_Z, &b_EFlowTrack_Z);
   fChain->SetBranchAddress("EFlowTrack.TOuter", EFlowTrack_TOuter, &b_EFlowTrack_TOuter);
   fChain->SetBranchAddress("EFlowTrack.XOuter", EFlowTrack_XOuter, &b_EFlowTrack_XOuter);
   fChain->SetBranchAddress("EFlowTrack.YOuter", EFlowTrack_YOuter, &b_EFlowTrack_YOuter);
   fChain->SetBranchAddress("EFlowTrack.ZOuter", EFlowTrack_ZOuter, &b_EFlowTrack_ZOuter);
   fChain->SetBranchAddress("EFlowTrack.Xd", EFlowTrack_Xd, &b_EFlowTrack_Xd);
   fChain->SetBranchAddress("EFlowTrack.Yd", EFlowTrack_Yd, &b_EFlowTrack_Yd);
   fChain->SetBranchAddress("EFlowTrack.Zd", EFlowTrack_Zd, &b_EFlowTrack_Zd);
   fChain->SetBranchAddress("EFlowTrack.L", EFlowTrack_L, &b_EFlowTrack_L);
   fChain->SetBranchAddress("EFlowTrack.D0", EFlowTrack_D0, &b_EFlowTrack_D0);
   fChain->SetBranchAddress("EFlowTrack.DZ", EFlowTrack_DZ, &b_EFlowTrack_DZ);
   fChain->SetBranchAddress("EFlowTrack.ErrorP", EFlowTrack_ErrorP, &b_EFlowTrack_ErrorP);
   fChain->SetBranchAddress("EFlowTrack.ErrorPT", EFlowTrack_ErrorPT, &b_EFlowTrack_ErrorPT);
   fChain->SetBranchAddress("EFlowTrack.ErrorPhi", EFlowTrack_ErrorPhi, &b_EFlowTrack_ErrorPhi);
   fChain->SetBranchAddress("EFlowTrack.ErrorCtgTheta", EFlowTrack_ErrorCtgTheta, &b_EFlowTrack_ErrorCtgTheta);
   fChain->SetBranchAddress("EFlowTrack.ErrorT", EFlowTrack_ErrorT, &b_EFlowTrack_ErrorT);
   fChain->SetBranchAddress("EFlowTrack.ErrorD0", EFlowTrack_ErrorD0, &b_EFlowTrack_ErrorD0);
   fChain->SetBranchAddress("EFlowTrack.ErrorDZ", EFlowTrack_ErrorDZ, &b_EFlowTrack_ErrorDZ);
   fChain->SetBranchAddress("EFlowTrack.Particle", EFlowTrack_Particle, &b_EFlowTrack_Particle);
   fChain->SetBranchAddress("EFlowTrack.VertexIndex", EFlowTrack_VertexIndex, &b_EFlowTrack_VertexIndex);
   fChain->SetBranchAddress("EFlowTrack_size", &EFlowTrack_size, &b_EFlowTrack_size);
   fChain->SetBranchAddress("EFlowPhoton", &EFlowPhoton_, &b_EFlowPhoton_);
   fChain->SetBranchAddress("EFlowPhoton.fUniqueID", EFlowPhoton_fUniqueID, &b_EFlowPhoton_fUniqueID);
   fChain->SetBranchAddress("EFlowPhoton.fBits", EFlowPhoton_fBits, &b_EFlowPhoton_fBits);
   fChain->SetBranchAddress("EFlowPhoton.ET", EFlowPhoton_ET, &b_EFlowPhoton_ET);
   fChain->SetBranchAddress("EFlowPhoton.Eta", EFlowPhoton_Eta, &b_EFlowPhoton_Eta);
   fChain->SetBranchAddress("EFlowPhoton.Phi", EFlowPhoton_Phi, &b_EFlowPhoton_Phi);
   fChain->SetBranchAddress("EFlowPhoton.E", EFlowPhoton_E, &b_EFlowPhoton_E);
   fChain->SetBranchAddress("EFlowPhoton.T", EFlowPhoton_T, &b_EFlowPhoton_T);
   fChain->SetBranchAddress("EFlowPhoton.NTimeHits", EFlowPhoton_NTimeHits, &b_EFlowPhoton_NTimeHits);
   fChain->SetBranchAddress("EFlowPhoton.Eem", EFlowPhoton_Eem, &b_EFlowPhoton_Eem);
   fChain->SetBranchAddress("EFlowPhoton.Ehad", EFlowPhoton_Ehad, &b_EFlowPhoton_Ehad);
   fChain->SetBranchAddress("EFlowPhoton.Edges[4]", EFlowPhoton_Edges, &b_EFlowPhoton_Edges);
   fChain->SetBranchAddress("EFlowPhoton.Particles", EFlowPhoton_Particles, &b_EFlowPhoton_Particles);
   fChain->SetBranchAddress("EFlowPhoton_size", &EFlowPhoton_size, &b_EFlowPhoton_size);
   fChain->SetBranchAddress("EFlowNeutralHadron", &EFlowNeutralHadron_, &b_EFlowNeutralHadron_);
   fChain->SetBranchAddress("EFlowNeutralHadron.fUniqueID", &EFlowNeutralHadron_fUniqueID, &b_EFlowNeutralHadron_fUniqueID);
   fChain->SetBranchAddress("EFlowNeutralHadron.fBits", &EFlowNeutralHadron_fBits, &b_EFlowNeutralHadron_fBits);
   fChain->SetBranchAddress("EFlowNeutralHadron.ET", &EFlowNeutralHadron_ET, &b_EFlowNeutralHadron_ET);
   fChain->SetBranchAddress("EFlowNeutralHadron.Eta", &EFlowNeutralHadron_Eta, &b_EFlowNeutralHadron_Eta);
   fChain->SetBranchAddress("EFlowNeutralHadron.Phi", &EFlowNeutralHadron_Phi, &b_EFlowNeutralHadron_Phi);
   fChain->SetBranchAddress("EFlowNeutralHadron.E", &EFlowNeutralHadron_E, &b_EFlowNeutralHadron_E);
   fChain->SetBranchAddress("EFlowNeutralHadron.T", &EFlowNeutralHadron_T, &b_EFlowNeutralHadron_T);
   fChain->SetBranchAddress("EFlowNeutralHadron.NTimeHits", &EFlowNeutralHadron_NTimeHits, &b_EFlowNeutralHadron_NTimeHits);
   fChain->SetBranchAddress("EFlowNeutralHadron.Eem", &EFlowNeutralHadron_Eem, &b_EFlowNeutralHadron_Eem);
   fChain->SetBranchAddress("EFlowNeutralHadron.Ehad", &EFlowNeutralHadron_Ehad, &b_EFlowNeutralHadron_Ehad);
   fChain->SetBranchAddress("EFlowNeutralHadron.Edges[4]", &EFlowNeutralHadron_Edges, &b_EFlowNeutralHadron_Edges);
   fChain->SetBranchAddress("EFlowNeutralHadron.Particles", &EFlowNeutralHadron_Particles, &b_EFlowNeutralHadron_Particles);
   fChain->SetBranchAddress("EFlowNeutralHadron_size", &EFlowNeutralHadron_size, &b_EFlowNeutralHadron_size);
   fChain->SetBranchAddress("GenJet", &GenJet_, &b_GenJet_);
   fChain->SetBranchAddress("GenJet.fUniqueID", GenJet_fUniqueID, &b_GenJet_fUniqueID);
   fChain->SetBranchAddress("GenJet.fBits", GenJet_fBits, &b_GenJet_fBits);
   fChain->SetBranchAddress("GenJet.PT", GenJet_PT, &b_GenJet_PT);
   fChain->SetBranchAddress("GenJet.Eta", GenJet_Eta, &b_GenJet_Eta);
   fChain->SetBranchAddress("GenJet.Phi", GenJet_Phi, &b_GenJet_Phi);
   fChain->SetBranchAddress("GenJet.T", GenJet_T, &b_GenJet_T);
   fChain->SetBranchAddress("GenJet.Mass", GenJet_Mass, &b_GenJet_Mass);
   fChain->SetBranchAddress("GenJet.DeltaEta", GenJet_DeltaEta, &b_GenJet_DeltaEta);
   fChain->SetBranchAddress("GenJet.DeltaPhi", GenJet_DeltaPhi, &b_GenJet_DeltaPhi);
   fChain->SetBranchAddress("GenJet.Flavor", GenJet_Flavor, &b_GenJet_Flavor);
   fChain->SetBranchAddress("GenJet.FlavorAlgo", GenJet_FlavorAlgo, &b_GenJet_FlavorAlgo);
   fChain->SetBranchAddress("GenJet.FlavorPhys", GenJet_FlavorPhys, &b_GenJet_FlavorPhys);
   fChain->SetBranchAddress("GenJet.BTag", GenJet_BTag, &b_GenJet_BTag);
   fChain->SetBranchAddress("GenJet.BTagAlgo", GenJet_BTagAlgo, &b_GenJet_BTagAlgo);
   fChain->SetBranchAddress("GenJet.BTagPhys", GenJet_BTagPhys, &b_GenJet_BTagPhys);
   fChain->SetBranchAddress("GenJet.TauTag", GenJet_TauTag, &b_GenJet_TauTag);
   fChain->SetBranchAddress("GenJet.TauWeight", GenJet_TauWeight, &b_GenJet_TauWeight);
   fChain->SetBranchAddress("GenJet.Charge", GenJet_Charge, &b_GenJet_Charge);
   fChain->SetBranchAddress("GenJet.EhadOverEem", GenJet_EhadOverEem, &b_GenJet_EhadOverEem);
   fChain->SetBranchAddress("GenJet.NCharged", GenJet_NCharged, &b_GenJet_NCharged);
   fChain->SetBranchAddress("GenJet.NNeutrals", GenJet_NNeutrals, &b_GenJet_NNeutrals);
   fChain->SetBranchAddress("GenJet.Beta", GenJet_Beta, &b_GenJet_Beta);
   fChain->SetBranchAddress("GenJet.BetaStar", GenJet_BetaStar, &b_GenJet_BetaStar);
   fChain->SetBranchAddress("GenJet.MeanSqDeltaR", GenJet_MeanSqDeltaR, &b_GenJet_MeanSqDeltaR);
   fChain->SetBranchAddress("GenJet.PTD", GenJet_PTD, &b_GenJet_PTD);
   fChain->SetBranchAddress("GenJet.FracPt[5]", GenJet_FracPt, &b_GenJet_FracPt);
   fChain->SetBranchAddress("GenJet.Tau[5]", GenJet_Tau, &b_GenJet_Tau);
   fChain->SetBranchAddress("GenJet.SoftDroppedJet", GenJet_SoftDroppedJet, &b_GenJet_SoftDroppedJet);
   fChain->SetBranchAddress("GenJet.SoftDroppedSubJet1", GenJet_SoftDroppedSubJet1, &b_GenJet_SoftDroppedSubJet1);
   fChain->SetBranchAddress("GenJet.SoftDroppedSubJet2", GenJet_SoftDroppedSubJet2, &b_GenJet_SoftDroppedSubJet2);
   fChain->SetBranchAddress("GenJet.TrimmedP4[5]", GenJet_TrimmedP4, &b_GenJet_TrimmedP4);
   fChain->SetBranchAddress("GenJet.PrunedP4[5]", GenJet_PrunedP4, &b_GenJet_PrunedP4);
   fChain->SetBranchAddress("GenJet.SoftDroppedP4[5]", GenJet_SoftDroppedP4, &b_GenJet_SoftDroppedP4);
   fChain->SetBranchAddress("GenJet.NSubJetsTrimmed", GenJet_NSubJetsTrimmed, &b_GenJet_NSubJetsTrimmed);
   fChain->SetBranchAddress("GenJet.NSubJetsPruned", GenJet_NSubJetsPruned, &b_GenJet_NSubJetsPruned);
   fChain->SetBranchAddress("GenJet.NSubJetsSoftDropped", GenJet_NSubJetsSoftDropped, &b_GenJet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("GenJet.ExclYmerge23", GenJet_ExclYmerge23, &b_GenJet_ExclYmerge23);
   fChain->SetBranchAddress("GenJet.ExclYmerge34", GenJet_ExclYmerge34, &b_GenJet_ExclYmerge34);
   fChain->SetBranchAddress("GenJet.ExclYmerge45", GenJet_ExclYmerge45, &b_GenJet_ExclYmerge45);
   fChain->SetBranchAddress("GenJet.ExclYmerge56", GenJet_ExclYmerge56, &b_GenJet_ExclYmerge56);
   fChain->SetBranchAddress("GenJet.Constituents", GenJet_Constituents, &b_GenJet_Constituents);
   fChain->SetBranchAddress("GenJet.Particles", GenJet_Particles, &b_GenJet_Particles);
   fChain->SetBranchAddress("GenJet.Area", GenJet_Area, &b_GenJet_Area);
   fChain->SetBranchAddress("GenJet_size", &GenJet_size, &b_GenJet_size);
   fChain->SetBranchAddress("GenMissingET", &GenMissingET_, &b_GenMissingET_);
   fChain->SetBranchAddress("GenMissingET.fUniqueID", GenMissingET_fUniqueID, &b_GenMissingET_fUniqueID);
   fChain->SetBranchAddress("GenMissingET.fBits", GenMissingET_fBits, &b_GenMissingET_fBits);
   fChain->SetBranchAddress("GenMissingET.MET", GenMissingET_MET, &b_GenMissingET_MET);
   fChain->SetBranchAddress("GenMissingET.Eta", GenMissingET_Eta, &b_GenMissingET_Eta);
   fChain->SetBranchAddress("GenMissingET.Phi", GenMissingET_Phi, &b_GenMissingET_Phi);
   fChain->SetBranchAddress("GenMissingET_size", &GenMissingET_size, &b_GenMissingET_size);
   fChain->SetBranchAddress("Jet", &Jet_, &b_Jet_);
   fChain->SetBranchAddress("Jet.fUniqueID", Jet_fUniqueID, &b_Jet_fUniqueID);
   fChain->SetBranchAddress("Jet.fBits", Jet_fBits, &b_Jet_fBits);
   fChain->SetBranchAddress("Jet.PT", Jet_PT, &b_Jet_PT);
   fChain->SetBranchAddress("Jet.Eta", Jet_Eta, &b_Jet_Eta);
   fChain->SetBranchAddress("Jet.Phi", Jet_Phi, &b_Jet_Phi);
   fChain->SetBranchAddress("Jet.T", Jet_T, &b_Jet_T);
   fChain->SetBranchAddress("Jet.Mass", Jet_Mass, &b_Jet_Mass);
   fChain->SetBranchAddress("Jet.DeltaEta", Jet_DeltaEta, &b_Jet_DeltaEta);
   fChain->SetBranchAddress("Jet.DeltaPhi", Jet_DeltaPhi, &b_Jet_DeltaPhi);
   fChain->SetBranchAddress("Jet.Flavor", Jet_Flavor, &b_Jet_Flavor);
   fChain->SetBranchAddress("Jet.FlavorAlgo", Jet_FlavorAlgo, &b_Jet_FlavorAlgo);
   fChain->SetBranchAddress("Jet.FlavorPhys", Jet_FlavorPhys, &b_Jet_FlavorPhys);
   fChain->SetBranchAddress("Jet.BTag", Jet_BTag, &b_Jet_BTag);
   fChain->SetBranchAddress("Jet.BTagAlgo", Jet_BTagAlgo, &b_Jet_BTagAlgo);
   fChain->SetBranchAddress("Jet.BTagPhys", Jet_BTagPhys, &b_Jet_BTagPhys);
   fChain->SetBranchAddress("Jet.TauTag", Jet_TauTag, &b_Jet_TauTag);
   fChain->SetBranchAddress("Jet.TauWeight", Jet_TauWeight, &b_Jet_TauWeight);
   fChain->SetBranchAddress("Jet.Charge", Jet_Charge, &b_Jet_Charge);
   fChain->SetBranchAddress("Jet.EhadOverEem", Jet_EhadOverEem, &b_Jet_EhadOverEem);
   fChain->SetBranchAddress("Jet.NCharged", Jet_NCharged, &b_Jet_NCharged);
   fChain->SetBranchAddress("Jet.NNeutrals", Jet_NNeutrals, &b_Jet_NNeutrals);
   fChain->SetBranchAddress("Jet.Beta", Jet_Beta, &b_Jet_Beta);
   fChain->SetBranchAddress("Jet.BetaStar", Jet_BetaStar, &b_Jet_BetaStar);
   fChain->SetBranchAddress("Jet.MeanSqDeltaR", Jet_MeanSqDeltaR, &b_Jet_MeanSqDeltaR);
   fChain->SetBranchAddress("Jet.PTD", Jet_PTD, &b_Jet_PTD);
   fChain->SetBranchAddress("Jet.FracPt[5]", Jet_FracPt, &b_Jet_FracPt);
   fChain->SetBranchAddress("Jet.Tau[5]", Jet_Tau, &b_Jet_Tau);
   fChain->SetBranchAddress("Jet.SoftDroppedJet", Jet_SoftDroppedJet, &b_Jet_SoftDroppedJet);
   fChain->SetBranchAddress("Jet.SoftDroppedSubJet1", Jet_SoftDroppedSubJet1, &b_Jet_SoftDroppedSubJet1);
   fChain->SetBranchAddress("Jet.SoftDroppedSubJet2", Jet_SoftDroppedSubJet2, &b_Jet_SoftDroppedSubJet2);
   fChain->SetBranchAddress("Jet.TrimmedP4[5]", Jet_TrimmedP4, &b_Jet_TrimmedP4);
   fChain->SetBranchAddress("Jet.PrunedP4[5]", Jet_PrunedP4, &b_Jet_PrunedP4);
   fChain->SetBranchAddress("Jet.SoftDroppedP4[5]", Jet_SoftDroppedP4, &b_Jet_SoftDroppedP4);
   fChain->SetBranchAddress("Jet.NSubJetsTrimmed", Jet_NSubJetsTrimmed, &b_Jet_NSubJetsTrimmed);
   fChain->SetBranchAddress("Jet.NSubJetsPruned", Jet_NSubJetsPruned, &b_Jet_NSubJetsPruned);
   fChain->SetBranchAddress("Jet.NSubJetsSoftDropped", Jet_NSubJetsSoftDropped, &b_Jet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("Jet.ExclYmerge23", Jet_ExclYmerge23, &b_Jet_ExclYmerge23);
   fChain->SetBranchAddress("Jet.ExclYmerge34", Jet_ExclYmerge34, &b_Jet_ExclYmerge34);
   fChain->SetBranchAddress("Jet.ExclYmerge45", Jet_ExclYmerge45, &b_Jet_ExclYmerge45);
   fChain->SetBranchAddress("Jet.ExclYmerge56", Jet_ExclYmerge56, &b_Jet_ExclYmerge56);
   fChain->SetBranchAddress("Jet.Constituents", Jet_Constituents, &b_Jet_Constituents);
   fChain->SetBranchAddress("Jet.Particles", Jet_Particles, &b_Jet_Particles);
   fChain->SetBranchAddress("Jet.Area", Jet_Area, &b_Jet_Area);
   fChain->SetBranchAddress("Jet_size", &Jet_size, &b_Jet_size);
   fChain->SetBranchAddress("Electron", &Electron_, &b_Electron_);
   fChain->SetBranchAddress("Electron.fUniqueID", Electron_fUniqueID, &b_Electron_fUniqueID);
   fChain->SetBranchAddress("Electron.fBits", Electron_fBits, &b_Electron_fBits);
   fChain->SetBranchAddress("Electron.PT", Electron_PT, &b_Electron_PT);
   fChain->SetBranchAddress("Electron.Eta", Electron_Eta, &b_Electron_Eta);
   fChain->SetBranchAddress("Electron.Phi", Electron_Phi, &b_Electron_Phi);
   fChain->SetBranchAddress("Electron.T", Electron_T, &b_Electron_T);
   fChain->SetBranchAddress("Electron.Charge", Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron.EhadOverEem", Electron_EhadOverEem, &b_Electron_EhadOverEem);
   fChain->SetBranchAddress("Electron.Particle", Electron_Particle, &b_Electron_Particle);
   fChain->SetBranchAddress("Electron.IsolationVar", Electron_IsolationVar, &b_Electron_IsolationVar);
   fChain->SetBranchAddress("Electron.IsolationVarRhoCorr", Electron_IsolationVarRhoCorr, &b_Electron_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Electron.SumPtCharged", Electron_SumPtCharged, &b_Electron_SumPtCharged);
   fChain->SetBranchAddress("Electron.SumPtNeutral", Electron_SumPtNeutral, &b_Electron_SumPtNeutral);
   fChain->SetBranchAddress("Electron.SumPtChargedPU", Electron_SumPtChargedPU, &b_Electron_SumPtChargedPU);
   fChain->SetBranchAddress("Electron.SumPt", Electron_SumPt, &b_Electron_SumPt);
   fChain->SetBranchAddress("Electron_size", &Electron_size, &b_Electron_size);
   fChain->SetBranchAddress("Photon", &Photon_, &b_Photon_);
   fChain->SetBranchAddress("Photon.fUniqueID", Photon_fUniqueID, &b_Photon_fUniqueID);
   fChain->SetBranchAddress("Photon.fBits", Photon_fBits, &b_Photon_fBits);
   fChain->SetBranchAddress("Photon.PT", Photon_PT, &b_Photon_PT);
   fChain->SetBranchAddress("Photon.Eta", Photon_Eta, &b_Photon_Eta);
   fChain->SetBranchAddress("Photon.Phi", Photon_Phi, &b_Photon_Phi);
   fChain->SetBranchAddress("Photon.E", Photon_E, &b_Photon_E);
   fChain->SetBranchAddress("Photon.T", Photon_T, &b_Photon_T);
   fChain->SetBranchAddress("Photon.EhadOverEem", Photon_EhadOverEem, &b_Photon_EhadOverEem);
   fChain->SetBranchAddress("Photon.Particles", Photon_Particles, &b_Photon_Particles);
   fChain->SetBranchAddress("Photon.IsolationVar", Photon_IsolationVar, &b_Photon_IsolationVar);
   fChain->SetBranchAddress("Photon.IsolationVarRhoCorr", Photon_IsolationVarRhoCorr, &b_Photon_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Photon.SumPtCharged", Photon_SumPtCharged, &b_Photon_SumPtCharged);
   fChain->SetBranchAddress("Photon.SumPtNeutral", Photon_SumPtNeutral, &b_Photon_SumPtNeutral);
   fChain->SetBranchAddress("Photon.SumPtChargedPU", Photon_SumPtChargedPU, &b_Photon_SumPtChargedPU);
   fChain->SetBranchAddress("Photon.SumPt", Photon_SumPt, &b_Photon_SumPt);
   fChain->SetBranchAddress("Photon.Status", Photon_Status, &b_Photon_Status);
   fChain->SetBranchAddress("Photon_size", &Photon_size, &b_Photon_size);
   fChain->SetBranchAddress("Muon", &Muon_, &b_Muon_);
   fChain->SetBranchAddress("Muon.fUniqueID", Muon_fUniqueID, &b_Muon_fUniqueID);
   fChain->SetBranchAddress("Muon.fBits", Muon_fBits, &b_Muon_fBits);
   fChain->SetBranchAddress("Muon.PT", Muon_PT, &b_Muon_PT);
   fChain->SetBranchAddress("Muon.Eta", Muon_Eta, &b_Muon_Eta);
   fChain->SetBranchAddress("Muon.Phi", Muon_Phi, &b_Muon_Phi);
   fChain->SetBranchAddress("Muon.T", Muon_T, &b_Muon_T);
   fChain->SetBranchAddress("Muon.Charge", Muon_Charge, &b_Muon_Charge);
   fChain->SetBranchAddress("Muon.Particle", Muon_Particle, &b_Muon_Particle);
   fChain->SetBranchAddress("Muon.IsolationVar", Muon_IsolationVar, &b_Muon_IsolationVar);
   fChain->SetBranchAddress("Muon.IsolationVarRhoCorr", Muon_IsolationVarRhoCorr, &b_Muon_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Muon.SumPtCharged", Muon_SumPtCharged, &b_Muon_SumPtCharged);
   fChain->SetBranchAddress("Muon.SumPtNeutral", Muon_SumPtNeutral, &b_Muon_SumPtNeutral);
   fChain->SetBranchAddress("Muon.SumPtChargedPU", Muon_SumPtChargedPU, &b_Muon_SumPtChargedPU);
   fChain->SetBranchAddress("Muon.SumPt", Muon_SumPt, &b_Muon_SumPt);
   fChain->SetBranchAddress("Muon_size", &Muon_size, &b_Muon_size);
   fChain->SetBranchAddress("AntiKtJet", &AntiKtJet_, &b_AntiKtJet_);
   fChain->SetBranchAddress("AntiKtJet.fUniqueID", AntiKtJet_fUniqueID, &b_AntiKtJet_fUniqueID);
   fChain->SetBranchAddress("AntiKtJet.fBits", AntiKtJet_fBits, &b_AntiKtJet_fBits);
   fChain->SetBranchAddress("AntiKtJet.PT", AntiKtJet_PT, &b_AntiKtJet_PT);
   fChain->SetBranchAddress("AntiKtJet.Eta", AntiKtJet_Eta, &b_AntiKtJet_Eta);
   fChain->SetBranchAddress("AntiKtJet.Phi", AntiKtJet_Phi, &b_AntiKtJet_Phi);
   fChain->SetBranchAddress("AntiKtJet.T", AntiKtJet_T, &b_AntiKtJet_T);
   fChain->SetBranchAddress("AntiKtJet.Mass", AntiKtJet_Mass, &b_AntiKtJet_Mass);
   fChain->SetBranchAddress("AntiKtJet.DeltaEta", AntiKtJet_DeltaEta, &b_AntiKtJet_DeltaEta);
   fChain->SetBranchAddress("AntiKtJet.DeltaPhi", AntiKtJet_DeltaPhi, &b_AntiKtJet_DeltaPhi);
   fChain->SetBranchAddress("AntiKtJet.Flavor", AntiKtJet_Flavor, &b_AntiKtJet_Flavor);
   fChain->SetBranchAddress("AntiKtJet.FlavorAlgo", AntiKtJet_FlavorAlgo, &b_AntiKtJet_FlavorAlgo);
   fChain->SetBranchAddress("AntiKtJet.FlavorPhys", AntiKtJet_FlavorPhys, &b_AntiKtJet_FlavorPhys);
   fChain->SetBranchAddress("AntiKtJet.BTag", AntiKtJet_BTag, &b_AntiKtJet_BTag);
   fChain->SetBranchAddress("AntiKtJet.BTagAlgo", AntiKtJet_BTagAlgo, &b_AntiKtJet_BTagAlgo);
   fChain->SetBranchAddress("AntiKtJet.BTagPhys", AntiKtJet_BTagPhys, &b_AntiKtJet_BTagPhys);
   fChain->SetBranchAddress("AntiKtJet.TauTag", AntiKtJet_TauTag, &b_AntiKtJet_TauTag);
   fChain->SetBranchAddress("AntiKtJet.TauWeight", AntiKtJet_TauWeight, &b_AntiKtJet_TauWeight);
   fChain->SetBranchAddress("AntiKtJet.Charge", AntiKtJet_Charge, &b_AntiKtJet_Charge);
   fChain->SetBranchAddress("AntiKtJet.EhadOverEem", AntiKtJet_EhadOverEem, &b_AntiKtJet_EhadOverEem);
   fChain->SetBranchAddress("AntiKtJet.NCharged", AntiKtJet_NCharged, &b_AntiKtJet_NCharged);
   fChain->SetBranchAddress("AntiKtJet.NNeutrals", AntiKtJet_NNeutrals, &b_AntiKtJet_NNeutrals);
   fChain->SetBranchAddress("AntiKtJet.Beta", AntiKtJet_Beta, &b_AntiKtJet_Beta);
   fChain->SetBranchAddress("AntiKtJet.BetaStar", AntiKtJet_BetaStar, &b_AntiKtJet_BetaStar);
   fChain->SetBranchAddress("AntiKtJet.MeanSqDeltaR", AntiKtJet_MeanSqDeltaR, &b_AntiKtJet_MeanSqDeltaR);
   fChain->SetBranchAddress("AntiKtJet.PTD", AntiKtJet_PTD, &b_AntiKtJet_PTD);
   fChain->SetBranchAddress("AntiKtJet.FracPt[5]", AntiKtJet_FracPt, &b_AntiKtJet_FracPt);
   fChain->SetBranchAddress("AntiKtJet.Tau[5]", AntiKtJet_Tau, &b_AntiKtJet_Tau);
   fChain->SetBranchAddress("AntiKtJet.SoftDroppedJet", AntiKtJet_SoftDroppedJet, &b_AntiKtJet_SoftDroppedJet);
   fChain->SetBranchAddress("AntiKtJet.SoftDroppedSubJet1", AntiKtJet_SoftDroppedSubJet1, &b_AntiKtJet_SoftDroppedSubJet1);
   fChain->SetBranchAddress("AntiKtJet.SoftDroppedSubJet2", AntiKtJet_SoftDroppedSubJet2, &b_AntiKtJet_SoftDroppedSubJet2);
   fChain->SetBranchAddress("AntiKtJet.TrimmedP4[5]", AntiKtJet_TrimmedP4, &b_AntiKtJet_TrimmedP4);
   fChain->SetBranchAddress("AntiKtJet.PrunedP4[5]", AntiKtJet_PrunedP4, &b_AntiKtJet_PrunedP4);
   fChain->SetBranchAddress("AntiKtJet.SoftDroppedP4[5]", AntiKtJet_SoftDroppedP4, &b_AntiKtJet_SoftDroppedP4);
   fChain->SetBranchAddress("AntiKtJet.NSubJetsTrimmed", AntiKtJet_NSubJetsTrimmed, &b_AntiKtJet_NSubJetsTrimmed);
   fChain->SetBranchAddress("AntiKtJet.NSubJetsPruned", AntiKtJet_NSubJetsPruned, &b_AntiKtJet_NSubJetsPruned);
   fChain->SetBranchAddress("AntiKtJet.NSubJetsSoftDropped", AntiKtJet_NSubJetsSoftDropped, &b_AntiKtJet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("AntiKtJet.ExclYmerge23", AntiKtJet_ExclYmerge23, &b_AntiKtJet_ExclYmerge23);
   fChain->SetBranchAddress("AntiKtJet.ExclYmerge34", AntiKtJet_ExclYmerge34, &b_AntiKtJet_ExclYmerge34);
   fChain->SetBranchAddress("AntiKtJet.ExclYmerge45", AntiKtJet_ExclYmerge45, &b_AntiKtJet_ExclYmerge45);
   fChain->SetBranchAddress("AntiKtJet.ExclYmerge56", AntiKtJet_ExclYmerge56, &b_AntiKtJet_ExclYmerge56);
   fChain->SetBranchAddress("AntiKtJet.Constituents", AntiKtJet_Constituents, &b_AntiKtJet_Constituents);
   fChain->SetBranchAddress("AntiKtJet.Particles", AntiKtJet_Particles, &b_AntiKtJet_Particles);
   fChain->SetBranchAddress("AntiKtJet.Area", AntiKtJet_Area, &b_AntiKtJet_Area);
   fChain->SetBranchAddress("AntiKtJet_size", &AntiKtJet_size, &b_AntiKtJet_size);
   fChain->SetBranchAddress("MissingET", &MissingET_, &b_MissingET_);
   fChain->SetBranchAddress("MissingET.fUniqueID", MissingET_fUniqueID, &b_MissingET_fUniqueID);
   fChain->SetBranchAddress("MissingET.fBits", MissingET_fBits, &b_MissingET_fBits);
   fChain->SetBranchAddress("MissingET.MET", MissingET_MET, &b_MissingET_MET);
   fChain->SetBranchAddress("MissingET.Eta", MissingET_Eta, &b_MissingET_Eta);
   fChain->SetBranchAddress("MissingET.Phi", MissingET_Phi, &b_MissingET_Phi);
   fChain->SetBranchAddress("MissingET_size", &MissingET_size, &b_MissingET_size);
   fChain->SetBranchAddress("ScalarHT", &ScalarHT_, &b_ScalarHT_);
   fChain->SetBranchAddress("ScalarHT.fUniqueID", ScalarHT_fUniqueID, &b_ScalarHT_fUniqueID);
   fChain->SetBranchAddress("ScalarHT.fBits", ScalarHT_fBits, &b_ScalarHT_fBits);
   fChain->SetBranchAddress("ScalarHT.HT", ScalarHT_HT, &b_ScalarHT_HT);
   fChain->SetBranchAddress("ScalarHT_size", &ScalarHT_size, &b_ScalarHT_size);
   Notify();
}

Bool_t tauStudies::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tauStudies::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tauStudies::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tauStudies_cxx
