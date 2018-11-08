#ifndef EleEfficiency_h
#define EleEfficiency_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"

class EleEfficiency {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxEvent = 1;
   static constexpr Int_t kMaxParticle = 347;
   static constexpr Int_t kMaxGenJet = 5;
   static constexpr Int_t kMaxKTjet = 5;
   static constexpr Int_t kMaxVLCjetR05N2 = 2;
   static constexpr Int_t kMaxGenMissingET = 1;
   static constexpr Int_t kMaxTower = 75;
   static constexpr Int_t kMaxEFlowTrack = 47;
   static constexpr Int_t kMaxEFlowPhoton = 38;
   static constexpr Int_t kMaxEFlowNeutralHadron = 18;
   static constexpr Int_t kMaxPhoton = 2;
   static constexpr Int_t kMaxElectron = 1;
   static constexpr Int_t kMaxMuon = 3;
   static constexpr Int_t kMaxMissingET = 1;
   static constexpr Int_t kMaxScalarHT = 1;

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
   Int_t           KTjet_;
   UInt_t          KTjet_fUniqueID[kMaxKTjet];   //[KTjet_]
   UInt_t          KTjet_fBits[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_PT[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_Eta[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_Phi[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_T[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_Mass[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_DeltaEta[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_DeltaPhi[kMaxKTjet];   //[KTjet_]
   UInt_t          KTjet_Flavor[kMaxKTjet];   //[KTjet_]
   UInt_t          KTjet_FlavorAlgo[kMaxKTjet];   //[KTjet_]
   UInt_t          KTjet_FlavorPhys[kMaxKTjet];   //[KTjet_]
   UInt_t          KTjet_BTag[kMaxKTjet];   //[KTjet_]
   UInt_t          KTjet_BTagAlgo[kMaxKTjet];   //[KTjet_]
   UInt_t          KTjet_BTagPhys[kMaxKTjet];   //[KTjet_]
   UInt_t          KTjet_TauTag[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_TauWeight[kMaxKTjet];   //[KTjet_]
   Int_t           KTjet_Charge[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_EhadOverEem[kMaxKTjet];   //[KTjet_]
   Int_t           KTjet_NCharged[kMaxKTjet];   //[KTjet_]
   Int_t           KTjet_NNeutrals[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_Beta[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_BetaStar[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_MeanSqDeltaR[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_PTD[kMaxKTjet];   //[KTjet_]
   Float_t         KTjet_FracPt[kMaxKTjet][5];   //[KTjet_]
   Float_t         KTjet_Tau[kMaxKTjet][5];   //[KTjet_]
   TLorentzVector  KTjet_SoftDroppedJet[kMaxKTjet];
   TLorentzVector  KTjet_SoftDroppedSubJet1[kMaxKTjet];
   TLorentzVector  KTjet_SoftDroppedSubJet2[kMaxKTjet];
   TLorentzVector  KTjet_TrimmedP4[5][kMaxKTjet];
   TLorentzVector  KTjet_PrunedP4[5][kMaxKTjet];
   TLorentzVector  KTjet_SoftDroppedP4[5][kMaxKTjet];
   Int_t           KTjet_NSubJetsTrimmed[kMaxKTjet];   //[KTjet_]
   Int_t           KTjet_NSubJetsPruned[kMaxKTjet];   //[KTjet_]
   Int_t           KTjet_NSubJetsSoftDropped[kMaxKTjet];   //[KTjet_]
   Double_t        KTjet_ExclYmerge23[kMaxKTjet];   //[KTjet_]
   Double_t        KTjet_ExclYmerge34[kMaxKTjet];   //[KTjet_]
   Double_t        KTjet_ExclYmerge45[kMaxKTjet];   //[KTjet_]
   Double_t        KTjet_ExclYmerge56[kMaxKTjet];   //[KTjet_]
   TRefArray       KTjet_Constituents[kMaxKTjet];
   TRefArray       KTjet_Particles[kMaxKTjet];
   TLorentzVector  KTjet_Area[kMaxKTjet];
   Int_t           KTjet_size;
   Int_t           VLCjetR05N2_;
   UInt_t          VLCjetR05N2_fUniqueID[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   UInt_t          VLCjetR05N2_fBits[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_PT[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_Eta[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_Phi[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_T[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_Mass[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_DeltaEta[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_DeltaPhi[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   UInt_t          VLCjetR05N2_Flavor[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   UInt_t          VLCjetR05N2_FlavorAlgo[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   UInt_t          VLCjetR05N2_FlavorPhys[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   UInt_t          VLCjetR05N2_BTag[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   UInt_t          VLCjetR05N2_BTagAlgo[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   UInt_t          VLCjetR05N2_BTagPhys[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   UInt_t          VLCjetR05N2_TauTag[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_TauWeight[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Int_t           VLCjetR05N2_Charge[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_EhadOverEem[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Int_t           VLCjetR05N2_NCharged[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Int_t           VLCjetR05N2_NNeutrals[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_Beta[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_BetaStar[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_MeanSqDeltaR[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_PTD[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_FracPt[kMaxVLCjetR05N2][5];   //[VLCjetR05N2_]
   Float_t         VLCjetR05N2_Tau[kMaxVLCjetR05N2][5];   //[VLCjetR05N2_]
   TLorentzVector  VLCjetR05N2_SoftDroppedJet[kMaxVLCjetR05N2];
   TLorentzVector  VLCjetR05N2_SoftDroppedSubJet1[kMaxVLCjetR05N2];
   TLorentzVector  VLCjetR05N2_SoftDroppedSubJet2[kMaxVLCjetR05N2];
   TLorentzVector  VLCjetR05N2_TrimmedP4[5][kMaxVLCjetR05N2];
   TLorentzVector  VLCjetR05N2_PrunedP4[5][kMaxVLCjetR05N2];
   TLorentzVector  VLCjetR05N2_SoftDroppedP4[5][kMaxVLCjetR05N2];
   Int_t           VLCjetR05N2_NSubJetsTrimmed[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Int_t           VLCjetR05N2_NSubJetsPruned[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Int_t           VLCjetR05N2_NSubJetsSoftDropped[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Double_t        VLCjetR05N2_ExclYmerge23[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Double_t        VLCjetR05N2_ExclYmerge34[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Double_t        VLCjetR05N2_ExclYmerge45[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   Double_t        VLCjetR05N2_ExclYmerge56[kMaxVLCjetR05N2];   //[VLCjetR05N2_]
   TRefArray       VLCjetR05N2_Constituents[kMaxVLCjetR05N2];
   TRefArray       VLCjetR05N2_Particles[kMaxVLCjetR05N2];
   TLorentzVector  VLCjetR05N2_Area[kMaxVLCjetR05N2];
   Int_t           VLCjetR05N2_size;
   Int_t           GenMissingET_;
   UInt_t          GenMissingET_fUniqueID[kMaxGenMissingET];   //[GenMissingET_]
   UInt_t          GenMissingET_fBits[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_MET[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_Eta[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_Phi[kMaxGenMissingET];   //[GenMissingET_]
   Int_t           GenMissingET_size;
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
   TBranch        *b_KTjet_;   //!
   TBranch        *b_KTjet_fUniqueID;   //!
   TBranch        *b_KTjet_fBits;   //!
   TBranch        *b_KTjet_PT;   //!
   TBranch        *b_KTjet_Eta;   //!
   TBranch        *b_KTjet_Phi;   //!
   TBranch        *b_KTjet_T;   //!
   TBranch        *b_KTjet_Mass;   //!
   TBranch        *b_KTjet_DeltaEta;   //!
   TBranch        *b_KTjet_DeltaPhi;   //!
   TBranch        *b_KTjet_Flavor;   //!
   TBranch        *b_KTjet_FlavorAlgo;   //!
   TBranch        *b_KTjet_FlavorPhys;   //!
   TBranch        *b_KTjet_BTag;   //!
   TBranch        *b_KTjet_BTagAlgo;   //!
   TBranch        *b_KTjet_BTagPhys;   //!
   TBranch        *b_KTjet_TauTag;   //!
   TBranch        *b_KTjet_TauWeight;   //!
   TBranch        *b_KTjet_Charge;   //!
   TBranch        *b_KTjet_EhadOverEem;   //!
   TBranch        *b_KTjet_NCharged;   //!
   TBranch        *b_KTjet_NNeutrals;   //!
   TBranch        *b_KTjet_Beta;   //!
   TBranch        *b_KTjet_BetaStar;   //!
   TBranch        *b_KTjet_MeanSqDeltaR;   //!
   TBranch        *b_KTjet_PTD;   //!
   TBranch        *b_KTjet_FracPt;   //!
   TBranch        *b_KTjet_Tau;   //!
   TBranch        *b_KTjet_SoftDroppedJet;   //!
   TBranch        *b_KTjet_SoftDroppedSubJet1;   //!
   TBranch        *b_KTjet_SoftDroppedSubJet2;   //!
   TBranch        *b_KTjet_TrimmedP4;   //!
   TBranch        *b_KTjet_PrunedP4;   //!
   TBranch        *b_KTjet_SoftDroppedP4;   //!
   TBranch        *b_KTjet_NSubJetsTrimmed;   //!
   TBranch        *b_KTjet_NSubJetsPruned;   //!
   TBranch        *b_KTjet_NSubJetsSoftDropped;   //!
   TBranch        *b_KTjet_ExclYmerge23;   //!
   TBranch        *b_KTjet_ExclYmerge34;   //!
   TBranch        *b_KTjet_ExclYmerge45;   //!
   TBranch        *b_KTjet_ExclYmerge56;   //!
   TBranch        *b_KTjet_Constituents;   //!
   TBranch        *b_KTjet_Particles;   //!
   TBranch        *b_KTjet_Area;   //!
   TBranch        *b_KTjet_size;   //!
   TBranch        *b_VLCjetR05N2_;   //!
   TBranch        *b_VLCjetR05N2_fUniqueID;   //!
   TBranch        *b_VLCjetR05N2_fBits;   //!
   TBranch        *b_VLCjetR05N2_PT;   //!
   TBranch        *b_VLCjetR05N2_Eta;   //!
   TBranch        *b_VLCjetR05N2_Phi;   //!
   TBranch        *b_VLCjetR05N2_T;   //!
   TBranch        *b_VLCjetR05N2_Mass;   //!
   TBranch        *b_VLCjetR05N2_DeltaEta;   //!
   TBranch        *b_VLCjetR05N2_DeltaPhi;   //!
   TBranch        *b_VLCjetR05N2_Flavor;   //!
   TBranch        *b_VLCjetR05N2_FlavorAlgo;   //!
   TBranch        *b_VLCjetR05N2_FlavorPhys;   //!
   TBranch        *b_VLCjetR05N2_BTag;   //!
   TBranch        *b_VLCjetR05N2_BTagAlgo;   //!
   TBranch        *b_VLCjetR05N2_BTagPhys;   //!
   TBranch        *b_VLCjetR05N2_TauTag;   //!
   TBranch        *b_VLCjetR05N2_TauWeight;   //!
   TBranch        *b_VLCjetR05N2_Charge;   //!
   TBranch        *b_VLCjetR05N2_EhadOverEem;   //!
   TBranch        *b_VLCjetR05N2_NCharged;   //!
   TBranch        *b_VLCjetR05N2_NNeutrals;   //!
   TBranch        *b_VLCjetR05N2_Beta;   //!
   TBranch        *b_VLCjetR05N2_BetaStar;   //!
   TBranch        *b_VLCjetR05N2_MeanSqDeltaR;   //!
   TBranch        *b_VLCjetR05N2_PTD;   //!
   TBranch        *b_VLCjetR05N2_FracPt;   //!
   TBranch        *b_VLCjetR05N2_Tau;   //!
   TBranch        *b_VLCjetR05N2_SoftDroppedJet;   //!
   TBranch        *b_VLCjetR05N2_SoftDroppedSubJet1;   //!
   TBranch        *b_VLCjetR05N2_SoftDroppedSubJet2;   //!
   TBranch        *b_VLCjetR05N2_TrimmedP4;   //!
   TBranch        *b_VLCjetR05N2_PrunedP4;   //!
   TBranch        *b_VLCjetR05N2_SoftDroppedP4;   //!
   TBranch        *b_VLCjetR05N2_NSubJetsTrimmed;   //!
   TBranch        *b_VLCjetR05N2_NSubJetsPruned;   //!
   TBranch        *b_VLCjetR05N2_NSubJetsSoftDropped;   //!
   TBranch        *b_VLCjetR05N2_ExclYmerge23;   //!
   TBranch        *b_VLCjetR05N2_ExclYmerge34;   //!
   TBranch        *b_VLCjetR05N2_ExclYmerge45;   //!
   TBranch        *b_VLCjetR05N2_ExclYmerge56;   //!
   TBranch        *b_VLCjetR05N2_Constituents;   //!
   TBranch        *b_VLCjetR05N2_Particles;   //!
   TBranch        *b_VLCjetR05N2_Area;   //!
   TBranch        *b_VLCjetR05N2_size;   //!
   TBranch        *b_GenMissingET_;   //!
   TBranch        *b_GenMissingET_fUniqueID;   //!
   TBranch        *b_GenMissingET_fBits;   //!
   TBranch        *b_GenMissingET_MET;   //!
   TBranch        *b_GenMissingET_Eta;   //!
   TBranch        *b_GenMissingET_Phi;   //!
   TBranch        *b_GenMissingET_size;   //!
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

   EleEfficiency(TTree *tree=0);
   virtual ~EleEfficiency();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(const char*);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef EleEfficiency_cxx
EleEfficiency::EleEfficiency(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DelphesRoot/ee_ZH_Zmumu_Hbb_1k_IDEA.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("DelphesRoot/ee_ZH_Zmumu_Hbb_1k_IDEA.root");
      }
      f->GetObject("Delphes",tree);

   }
   Init(tree);
}

EleEfficiency::~EleEfficiency()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t EleEfficiency::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t EleEfficiency::LoadTree(Long64_t entry)
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

void EleEfficiency::Init(TTree *tree)
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
   fChain->SetBranchAddress("KTjet", &KTjet_, &b_KTjet_);
   fChain->SetBranchAddress("KTjet.fUniqueID", KTjet_fUniqueID, &b_KTjet_fUniqueID);
   fChain->SetBranchAddress("KTjet.fBits", KTjet_fBits, &b_KTjet_fBits);
   fChain->SetBranchAddress("KTjet.PT", KTjet_PT, &b_KTjet_PT);
   fChain->SetBranchAddress("KTjet.Eta", KTjet_Eta, &b_KTjet_Eta);
   fChain->SetBranchAddress("KTjet.Phi", KTjet_Phi, &b_KTjet_Phi);
   fChain->SetBranchAddress("KTjet.T", KTjet_T, &b_KTjet_T);
   fChain->SetBranchAddress("KTjet.Mass", KTjet_Mass, &b_KTjet_Mass);
   fChain->SetBranchAddress("KTjet.DeltaEta", KTjet_DeltaEta, &b_KTjet_DeltaEta);
   fChain->SetBranchAddress("KTjet.DeltaPhi", KTjet_DeltaPhi, &b_KTjet_DeltaPhi);
   fChain->SetBranchAddress("KTjet.Flavor", KTjet_Flavor, &b_KTjet_Flavor);
   fChain->SetBranchAddress("KTjet.FlavorAlgo", KTjet_FlavorAlgo, &b_KTjet_FlavorAlgo);
   fChain->SetBranchAddress("KTjet.FlavorPhys", KTjet_FlavorPhys, &b_KTjet_FlavorPhys);
   fChain->SetBranchAddress("KTjet.BTag", KTjet_BTag, &b_KTjet_BTag);
   fChain->SetBranchAddress("KTjet.BTagAlgo", KTjet_BTagAlgo, &b_KTjet_BTagAlgo);
   fChain->SetBranchAddress("KTjet.BTagPhys", KTjet_BTagPhys, &b_KTjet_BTagPhys);
   fChain->SetBranchAddress("KTjet.TauTag", KTjet_TauTag, &b_KTjet_TauTag);
   fChain->SetBranchAddress("KTjet.TauWeight", KTjet_TauWeight, &b_KTjet_TauWeight);
   fChain->SetBranchAddress("KTjet.Charge", KTjet_Charge, &b_KTjet_Charge);
   fChain->SetBranchAddress("KTjet.EhadOverEem", KTjet_EhadOverEem, &b_KTjet_EhadOverEem);
   fChain->SetBranchAddress("KTjet.NCharged", KTjet_NCharged, &b_KTjet_NCharged);
   fChain->SetBranchAddress("KTjet.NNeutrals", KTjet_NNeutrals, &b_KTjet_NNeutrals);
   fChain->SetBranchAddress("KTjet.Beta", KTjet_Beta, &b_KTjet_Beta);
   fChain->SetBranchAddress("KTjet.BetaStar", KTjet_BetaStar, &b_KTjet_BetaStar);
   fChain->SetBranchAddress("KTjet.MeanSqDeltaR", KTjet_MeanSqDeltaR, &b_KTjet_MeanSqDeltaR);
   fChain->SetBranchAddress("KTjet.PTD", KTjet_PTD, &b_KTjet_PTD);
   fChain->SetBranchAddress("KTjet.FracPt[5]", KTjet_FracPt, &b_KTjet_FracPt);
   fChain->SetBranchAddress("KTjet.Tau[5]", KTjet_Tau, &b_KTjet_Tau);
   fChain->SetBranchAddress("KTjet.SoftDroppedJet", KTjet_SoftDroppedJet, &b_KTjet_SoftDroppedJet);
   fChain->SetBranchAddress("KTjet.SoftDroppedSubJet1", KTjet_SoftDroppedSubJet1, &b_KTjet_SoftDroppedSubJet1);
   fChain->SetBranchAddress("KTjet.SoftDroppedSubJet2", KTjet_SoftDroppedSubJet2, &b_KTjet_SoftDroppedSubJet2);
   fChain->SetBranchAddress("KTjet.TrimmedP4[5]", KTjet_TrimmedP4, &b_KTjet_TrimmedP4);
   fChain->SetBranchAddress("KTjet.PrunedP4[5]", KTjet_PrunedP4, &b_KTjet_PrunedP4);
   fChain->SetBranchAddress("KTjet.SoftDroppedP4[5]", KTjet_SoftDroppedP4, &b_KTjet_SoftDroppedP4);
   fChain->SetBranchAddress("KTjet.NSubJetsTrimmed", KTjet_NSubJetsTrimmed, &b_KTjet_NSubJetsTrimmed);
   fChain->SetBranchAddress("KTjet.NSubJetsPruned", KTjet_NSubJetsPruned, &b_KTjet_NSubJetsPruned);
   fChain->SetBranchAddress("KTjet.NSubJetsSoftDropped", KTjet_NSubJetsSoftDropped, &b_KTjet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("KTjet.ExclYmerge23", KTjet_ExclYmerge23, &b_KTjet_ExclYmerge23);
   fChain->SetBranchAddress("KTjet.ExclYmerge34", KTjet_ExclYmerge34, &b_KTjet_ExclYmerge34);
   fChain->SetBranchAddress("KTjet.ExclYmerge45", KTjet_ExclYmerge45, &b_KTjet_ExclYmerge45);
   fChain->SetBranchAddress("KTjet.ExclYmerge56", KTjet_ExclYmerge56, &b_KTjet_ExclYmerge56);
   fChain->SetBranchAddress("KTjet.Constituents", KTjet_Constituents, &b_KTjet_Constituents);
   fChain->SetBranchAddress("KTjet.Particles", KTjet_Particles, &b_KTjet_Particles);
   fChain->SetBranchAddress("KTjet.Area", KTjet_Area, &b_KTjet_Area);
   fChain->SetBranchAddress("KTjet_size", &KTjet_size, &b_KTjet_size);
   fChain->SetBranchAddress("VLCjetR05N2", &VLCjetR05N2_, &b_VLCjetR05N2_);
   fChain->SetBranchAddress("VLCjetR05N2.fUniqueID", VLCjetR05N2_fUniqueID, &b_VLCjetR05N2_fUniqueID);
   fChain->SetBranchAddress("VLCjetR05N2.fBits", VLCjetR05N2_fBits, &b_VLCjetR05N2_fBits);
   fChain->SetBranchAddress("VLCjetR05N2.PT", VLCjetR05N2_PT, &b_VLCjetR05N2_PT);
   fChain->SetBranchAddress("VLCjetR05N2.Eta", VLCjetR05N2_Eta, &b_VLCjetR05N2_Eta);
   fChain->SetBranchAddress("VLCjetR05N2.Phi", VLCjetR05N2_Phi, &b_VLCjetR05N2_Phi);
   fChain->SetBranchAddress("VLCjetR05N2.T", VLCjetR05N2_T, &b_VLCjetR05N2_T);
   fChain->SetBranchAddress("VLCjetR05N2.Mass", VLCjetR05N2_Mass, &b_VLCjetR05N2_Mass);
   fChain->SetBranchAddress("VLCjetR05N2.DeltaEta", VLCjetR05N2_DeltaEta, &b_VLCjetR05N2_DeltaEta);
   fChain->SetBranchAddress("VLCjetR05N2.DeltaPhi", VLCjetR05N2_DeltaPhi, &b_VLCjetR05N2_DeltaPhi);
   fChain->SetBranchAddress("VLCjetR05N2.Flavor", VLCjetR05N2_Flavor, &b_VLCjetR05N2_Flavor);
   fChain->SetBranchAddress("VLCjetR05N2.FlavorAlgo", VLCjetR05N2_FlavorAlgo, &b_VLCjetR05N2_FlavorAlgo);
   fChain->SetBranchAddress("VLCjetR05N2.FlavorPhys", VLCjetR05N2_FlavorPhys, &b_VLCjetR05N2_FlavorPhys);
   fChain->SetBranchAddress("VLCjetR05N2.BTag", VLCjetR05N2_BTag, &b_VLCjetR05N2_BTag);
   fChain->SetBranchAddress("VLCjetR05N2.BTagAlgo", VLCjetR05N2_BTagAlgo, &b_VLCjetR05N2_BTagAlgo);
   fChain->SetBranchAddress("VLCjetR05N2.BTagPhys", VLCjetR05N2_BTagPhys, &b_VLCjetR05N2_BTagPhys);
   fChain->SetBranchAddress("VLCjetR05N2.TauTag", VLCjetR05N2_TauTag, &b_VLCjetR05N2_TauTag);
   fChain->SetBranchAddress("VLCjetR05N2.TauWeight", VLCjetR05N2_TauWeight, &b_VLCjetR05N2_TauWeight);
   fChain->SetBranchAddress("VLCjetR05N2.Charge", VLCjetR05N2_Charge, &b_VLCjetR05N2_Charge);
   fChain->SetBranchAddress("VLCjetR05N2.EhadOverEem", VLCjetR05N2_EhadOverEem, &b_VLCjetR05N2_EhadOverEem);
   fChain->SetBranchAddress("VLCjetR05N2.NCharged", VLCjetR05N2_NCharged, &b_VLCjetR05N2_NCharged);
   fChain->SetBranchAddress("VLCjetR05N2.NNeutrals", VLCjetR05N2_NNeutrals, &b_VLCjetR05N2_NNeutrals);
   fChain->SetBranchAddress("VLCjetR05N2.Beta", VLCjetR05N2_Beta, &b_VLCjetR05N2_Beta);
   fChain->SetBranchAddress("VLCjetR05N2.BetaStar", VLCjetR05N2_BetaStar, &b_VLCjetR05N2_BetaStar);
   fChain->SetBranchAddress("VLCjetR05N2.MeanSqDeltaR", VLCjetR05N2_MeanSqDeltaR, &b_VLCjetR05N2_MeanSqDeltaR);
   fChain->SetBranchAddress("VLCjetR05N2.PTD", VLCjetR05N2_PTD, &b_VLCjetR05N2_PTD);
   fChain->SetBranchAddress("VLCjetR05N2.FracPt[5]", VLCjetR05N2_FracPt, &b_VLCjetR05N2_FracPt);
   fChain->SetBranchAddress("VLCjetR05N2.Tau[5]", VLCjetR05N2_Tau, &b_VLCjetR05N2_Tau);
   fChain->SetBranchAddress("VLCjetR05N2.SoftDroppedJet", VLCjetR05N2_SoftDroppedJet, &b_VLCjetR05N2_SoftDroppedJet);
   fChain->SetBranchAddress("VLCjetR05N2.SoftDroppedSubJet1", VLCjetR05N2_SoftDroppedSubJet1, &b_VLCjetR05N2_SoftDroppedSubJet1);
   fChain->SetBranchAddress("VLCjetR05N2.SoftDroppedSubJet2", VLCjetR05N2_SoftDroppedSubJet2, &b_VLCjetR05N2_SoftDroppedSubJet2);
   fChain->SetBranchAddress("VLCjetR05N2.TrimmedP4[5]", VLCjetR05N2_TrimmedP4, &b_VLCjetR05N2_TrimmedP4);
   fChain->SetBranchAddress("VLCjetR05N2.PrunedP4[5]", VLCjetR05N2_PrunedP4, &b_VLCjetR05N2_PrunedP4);
   fChain->SetBranchAddress("VLCjetR05N2.SoftDroppedP4[5]", VLCjetR05N2_SoftDroppedP4, &b_VLCjetR05N2_SoftDroppedP4);
   fChain->SetBranchAddress("VLCjetR05N2.NSubJetsTrimmed", VLCjetR05N2_NSubJetsTrimmed, &b_VLCjetR05N2_NSubJetsTrimmed);
   fChain->SetBranchAddress("VLCjetR05N2.NSubJetsPruned", VLCjetR05N2_NSubJetsPruned, &b_VLCjetR05N2_NSubJetsPruned);
   fChain->SetBranchAddress("VLCjetR05N2.NSubJetsSoftDropped", VLCjetR05N2_NSubJetsSoftDropped, &b_VLCjetR05N2_NSubJetsSoftDropped);
   fChain->SetBranchAddress("VLCjetR05N2.ExclYmerge23", VLCjetR05N2_ExclYmerge23, &b_VLCjetR05N2_ExclYmerge23);
   fChain->SetBranchAddress("VLCjetR05N2.ExclYmerge34", VLCjetR05N2_ExclYmerge34, &b_VLCjetR05N2_ExclYmerge34);
   fChain->SetBranchAddress("VLCjetR05N2.ExclYmerge45", VLCjetR05N2_ExclYmerge45, &b_VLCjetR05N2_ExclYmerge45);
   fChain->SetBranchAddress("VLCjetR05N2.ExclYmerge56", VLCjetR05N2_ExclYmerge56, &b_VLCjetR05N2_ExclYmerge56);
   fChain->SetBranchAddress("VLCjetR05N2.Constituents", VLCjetR05N2_Constituents, &b_VLCjetR05N2_Constituents);
   fChain->SetBranchAddress("VLCjetR05N2.Particles", VLCjetR05N2_Particles, &b_VLCjetR05N2_Particles);
   fChain->SetBranchAddress("VLCjetR05N2.Area", VLCjetR05N2_Area, &b_VLCjetR05N2_Area);
   fChain->SetBranchAddress("VLCjetR05N2_size", &VLCjetR05N2_size, &b_VLCjetR05N2_size);
   fChain->SetBranchAddress("GenMissingET", &GenMissingET_, &b_GenMissingET_);
   fChain->SetBranchAddress("GenMissingET.fUniqueID", GenMissingET_fUniqueID, &b_GenMissingET_fUniqueID);
   fChain->SetBranchAddress("GenMissingET.fBits", GenMissingET_fBits, &b_GenMissingET_fBits);
   fChain->SetBranchAddress("GenMissingET.MET", GenMissingET_MET, &b_GenMissingET_MET);
   fChain->SetBranchAddress("GenMissingET.Eta", GenMissingET_Eta, &b_GenMissingET_Eta);
   fChain->SetBranchAddress("GenMissingET.Phi", GenMissingET_Phi, &b_GenMissingET_Phi);
   fChain->SetBranchAddress("GenMissingET_size", &GenMissingET_size, &b_GenMissingET_size);
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
   fChain->SetBranchAddress("EFlowNeutralHadron.fUniqueID", EFlowNeutralHadron_fUniqueID, &b_EFlowNeutralHadron_fUniqueID);
   fChain->SetBranchAddress("EFlowNeutralHadron.fBits", EFlowNeutralHadron_fBits, &b_EFlowNeutralHadron_fBits);
   fChain->SetBranchAddress("EFlowNeutralHadron.ET", EFlowNeutralHadron_ET, &b_EFlowNeutralHadron_ET);
   fChain->SetBranchAddress("EFlowNeutralHadron.Eta", EFlowNeutralHadron_Eta, &b_EFlowNeutralHadron_Eta);
   fChain->SetBranchAddress("EFlowNeutralHadron.Phi", EFlowNeutralHadron_Phi, &b_EFlowNeutralHadron_Phi);
   fChain->SetBranchAddress("EFlowNeutralHadron.E", EFlowNeutralHadron_E, &b_EFlowNeutralHadron_E);
   fChain->SetBranchAddress("EFlowNeutralHadron.T", EFlowNeutralHadron_T, &b_EFlowNeutralHadron_T);
   fChain->SetBranchAddress("EFlowNeutralHadron.NTimeHits", EFlowNeutralHadron_NTimeHits, &b_EFlowNeutralHadron_NTimeHits);
   fChain->SetBranchAddress("EFlowNeutralHadron.Eem", EFlowNeutralHadron_Eem, &b_EFlowNeutralHadron_Eem);
   fChain->SetBranchAddress("EFlowNeutralHadron.Ehad", EFlowNeutralHadron_Ehad, &b_EFlowNeutralHadron_Ehad);
   fChain->SetBranchAddress("EFlowNeutralHadron.Edges[4]", EFlowNeutralHadron_Edges, &b_EFlowNeutralHadron_Edges);
   fChain->SetBranchAddress("EFlowNeutralHadron.Particles", EFlowNeutralHadron_Particles, &b_EFlowNeutralHadron_Particles);
   fChain->SetBranchAddress("EFlowNeutralHadron_size", &EFlowNeutralHadron_size, &b_EFlowNeutralHadron_size);
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
   fChain->SetBranchAddress("Electron", &Electron_, &b_Electron_);
   fChain->SetBranchAddress("Electron.fUniqueID", &Electron_fUniqueID, &b_Electron_fUniqueID);
   fChain->SetBranchAddress("Electron.fBits", &Electron_fBits, &b_Electron_fBits);
   fChain->SetBranchAddress("Electron.PT", &Electron_PT, &b_Electron_PT);
   fChain->SetBranchAddress("Electron.Eta", &Electron_Eta, &b_Electron_Eta);
   fChain->SetBranchAddress("Electron.Phi", &Electron_Phi, &b_Electron_Phi);
   fChain->SetBranchAddress("Electron.T", &Electron_T, &b_Electron_T);
   fChain->SetBranchAddress("Electron.Charge", &Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron.EhadOverEem", &Electron_EhadOverEem, &b_Electron_EhadOverEem);
   fChain->SetBranchAddress("Electron.Particle", &Electron_Particle, &b_Electron_Particle);
   fChain->SetBranchAddress("Electron.IsolationVar", &Electron_IsolationVar, &b_Electron_IsolationVar);
   fChain->SetBranchAddress("Electron.IsolationVarRhoCorr", &Electron_IsolationVarRhoCorr, &b_Electron_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Electron.SumPtCharged", &Electron_SumPtCharged, &b_Electron_SumPtCharged);
   fChain->SetBranchAddress("Electron.SumPtNeutral", &Electron_SumPtNeutral, &b_Electron_SumPtNeutral);
   fChain->SetBranchAddress("Electron.SumPtChargedPU", &Electron_SumPtChargedPU, &b_Electron_SumPtChargedPU);
   fChain->SetBranchAddress("Electron.SumPt", &Electron_SumPt, &b_Electron_SumPt);
   fChain->SetBranchAddress("Electron_size", &Electron_size, &b_Electron_size);
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

Bool_t EleEfficiency::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void EleEfficiency::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t EleEfficiency::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef EleEfficiency_cxx
