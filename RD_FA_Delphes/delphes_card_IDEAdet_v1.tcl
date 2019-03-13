#####################################################################
# IDEAdet model
# 
# Authors: Elisa Fontanesi, Lorenzo Pezzotti, Massimiliano Antonello
# email: lorenzo.pezzotti01@universitadipavia.it, 
#        m.antonello@uninsubria.it,
#        efontane@bo.infn.it
#####################################################################
#
#######################################
# Order of execution of various modules
#######################################

set ExecutionPath {
    ParticlePropagator

    ChargedHadronTrackingEfficiency
    ElectronTrackingEfficiency
    MuonTrackingEfficiency

    ChargedHadronMomentumSmearing
    ElectronMomentumSmearing
    MuonMomentumSmearing
    
    TrackMerger

    ECal
    HCal
    
    EFlowTrackMerger

    Calorimeter
    EFlowMerger
    
    PhotonEfficiency
    PhotonIsolation

    ElectronFilter
    ElectronEfficiency
    ElectronIsolation

    ChargedHadronFilter

    MuonEfficiency
    MuonIsolation

    EFlowFilter
    NeutrinoFilter
    GenJetFinder
    FastJetFinderAntiKt
    
    MissingET
    GenMissingET

    JetEnergyScale

    JetFlavorAssociation
    
    BTagging
    CTagging	
    TauTagging
    
    ScalarHT

    TreeWriter
}

#################################
# Propagate particles in cylinder
#################################

module ParticlePropagator ParticlePropagator {
    set InputArray Delphes/stableParticles

    set OutputArray stableParticles
    set ChargedHadronOutputArray chargedHadrons
    set ElectronOutputArray electrons
    set MuonOutputArray muons

    # inner radius of the solenoid, in m
    set Radius 2.25

    # half-length: z of solenoid, in m
    set HalfLength 2.5

    # magnetic field, in T
    set Bz 2.0
}

####################################
# Charged hadron tracking efficiency
####################################

module Efficiency ChargedHadronTrackingEfficiency {
    set InputArray ParticlePropagator/chargedHadrons
    set OutputArray chargedHadrons
    # We use only one efficiency, we set only 0 effincency out of eta bounds:

    set EfficiencyFormula {
	(pt <= 0.1)                                            * (0.000) +
	(abs(eta) > 2.1)                                       * (0.000) +
	(energy >= 0.5) * (abs(eta) <= 2.1)                    * (0.995) +
	(energy < 0.5 && energy >= 0.3) * (abs(eta) <= 2.1)    * (0.65) +
	(energy < 0.3) * (abs(eta) <= 2.1)                     * (0.06) 
    }
}

##############################
# Electron tracking efficiency
##############################

module Efficiency ElectronTrackingEfficiency {
    set InputArray ParticlePropagator/electrons
    set OutputArray electrons


    # Current full simulation with CLICdet provides for electrons:
    set EfficiencyFormula {
	(pt <= 0.1)                                            * (0.000) +
	(abs(eta) > 2.1)                                       * (0.000) +
	(energy >= 0.5) * (abs(eta) <= 2.1)                    * (0.995) +
	(energy < 0.5 && energy >= 0.3) * (abs(eta) <= 2.1)    * (0.65) +
	(energy < 0.3) * (abs(eta) <= 2.1)                     * (0.06) 
    }
}

##########################
# Muon tracking efficiency
##########################

module Efficiency MuonTrackingEfficiency {
    set InputArray ParticlePropagator/muons
    set OutputArray muons

    # Current full simulation with CLICdet provides for muons:
    set EfficiencyFormula {
	(pt < 0.1)                                             * (0.000) +
	(abs(eta) > 2.1)                                       * (0.000) +
	(energy >= 0.5) * (abs(eta) <= 2.1)                    * (0.995) +
	(energy < 0.5 && energy >= 0.3) * (abs(eta) <= 2.1)    * (0.65) +
	(energy < 0.3) * (abs(eta) <= 2.1)                     * (0.06) 
    }
}

########################################
# Momentum resolution for charged tracks
########################################

module MomentumSmearing ChargedHadronMomentumSmearing {
    set InputArray ChargedHadronTrackingEfficiency/chargedHadrons
    set OutputArray chargedHadrons


    # Resolution given in dpT/pT.
    # IDEAdet
    set ResolutionFormula {
    (abs(eta) <= 0.87) * (pt > 0.1)                   * sqrt(0.000034^2 * pt^2 + 0.00133^2) +
    (abs(eta) > 0.87 && abs(eta) <= 2.1) * (pt > 0.1) * sqrt(0.00034^2 * pt^2 + 0.0133^2)
    }
}

###################################
# Momentum resolution for electrons
###################################

module MomentumSmearing ElectronMomentumSmearing {
    set InputArray ElectronTrackingEfficiency/electrons
    set OutputArray electrons

    # Resolution given in dpT/pT.
    # IDEAdet
    set ResolutionFormula {
    (abs(eta) <= 0.87) * (pt > 0.1)                   * sqrt( 0.000034^2 * pt^2 + 0.00133^2) +
    (abs(eta) > 0.87 && abs(eta) <= 2.1) * (pt > 0.1) * sqrt( 0.00034^2 * pt^2 + 0.0133^2)
    }
}

###############################
# Momentum resolution for muons
###############################

module MomentumSmearing MuonMomentumSmearing {
    set InputArray MuonTrackingEfficiency/muons
    set OutputArray muons

    # Resolution given in dpT/pT.
    # IDEAdet
    set ResolutionFormula {
    (abs(eta) <= 0.87) * (pt > 0.1)                   * sqrt( 0.000034^2 * pt^2 + 0.00133^2) +
    (abs(eta) > 0.87 && abs(eta) <= 2.1) * (pt > 0.1) * sqrt( 0.00034^2 * pt^2 + 0.0133^2)
    }
}

##############
# Track merger
##############

module Merger TrackMerger {
    # add InputArray InputArray
    add InputArray ElectronMomentumSmearing/electrons
    add InputArray MuonMomentumSmearing/muons
    set OutputArray tracks
}

#############
#   DRECAL
#############

module SimpleCalorimeter ECal {
    set ParticleInputArray ParticlePropagator/stableParticles
    # We change the input excluding chargedHadrons
    set TrackInputArray TrackMerger/tracks

    set TowerOutputArray ecalTowers
    set EFlowTrackOutputArray DREeflowTracks
    set EFlowTowerOutputArray eflowPhotons

    set IsEcal true 
    
    set EnergyMin 0.5
    set EnergySignificanceMin 1.0

    set SmearTowerCenter true

    set pi [expr {acos(-1)}]

    # Lists of the edges of each tower in eta and phi
    # each list starts with the lower edge of the first tower
    # the list ends with the higher edged of the last tower

    #ECAL barrel: deta=0.00195 towers up to |eta| <=0.87 (45°)
    #ECAL endcaps: deta=0.004 towers up to |eta| <=2.59 (8.6°)
    #ECAL cell sizes always 5.6x5.6 mm^2

    #barrel:                                                                    
    set PhiBins {}
    for {set i -1402} {$i <= 1402} {incr i} {
        add PhiBins [expr {$i * $pi/1402.0 }]
    }
    #deta=0.00195 units for |eta| <= 0.87                                      
    for {set i -446} {$i <=446} {incr i} {
        set eta [expr {$i * 0.00195}]
        add EtaPhiBins $eta $PhiBins
    }

    #endcaps:                                                                   
    set PhiBins {}
    for {set i -1402} {$i <= 1402} {incr i} {
        add PhiBins [expr {$i * $pi/1402.}]
    }
    #deta=0.004 units for 0.87 < |eta| <= 2.59                                      
    #first, from -2.59 to -0.87             
    for {set i 1} {$i <=410} {incr i} {
        set eta [expr {-2.59 + $i * 0.004}]
        add EtaPhiBins $eta $PhiBins
    }
    #same for 0.87 to 2.59                                                        
    for  {set i 1} {$i <=410} {incr i} {
        set eta [expr {0.87 + $i*0.004}]
        add EtaPhiBins $eta $PhiBins
    }

    # default energy fractions {abs(PDG code)} {fraction of energy deposited in ECAL}
    add EnergyFraction {0} {0.0}
    # energy fractions for e, gamma and pi0
    add EnergyFraction {11} {1.0}
    add EnergyFraction {22} {1.0}
    add EnergyFraction {111} {1.0}
    # energy fractions for muon, neutrinos and neutralinos
    add EnergyFraction {12} {0.0}
    add EnergyFraction {13} {0.0}
    add EnergyFraction {14} {0.0}
    add EnergyFraction {16} {0.0}
    add EnergyFraction {1000022} {0.0}
    add EnergyFraction {1000023} {0.0}
    add EnergyFraction {1000025} {0.0}
    add EnergyFraction {1000035} {0.0}
    add EnergyFraction {1000045} {0.0}
    # energy fractions for K0short and Lambda
    add EnergyFraction {310} {0.3}
    add EnergyFraction {3122} {0.3}

    # set ECalResolutionFormula {resolution formula as a function of eta and energy}
    set ResolutionFormula {
    (abs(eta) <= 0.87 )                     * sqrt(energy^2*0.07^2 + energy*0.55^2)+
    (abs(eta) > 0.87 && abs(eta) <=2.59)    * sqrt(energy^2*0.07^2 + energy*0.55^2)}
}    

#############
#   DRHCAL
#############

module SimpleCalorimeter HCal {
    set ParticleInputArray ParticlePropagator/stableParticles
    set TrackInputArray ChargedHadronMomentumSmearing/chargedHadrons

    set TowerOutputArray hcalTowers
    set EFlowTrackOutputArray DRHeflowTracks
    set EFlowTowerOutputArray eflowNeutralHadrons

    set IsEcal false 
    
    set EnergyMin 0.5
    set EnergySignificanceMin 1.0
    
    set SmearTowerCenter true

    set pi [expr {acos(-1)}]

    # Lists of the edges of each tower in eta and phi
    # each list starts with the lower edge of the first tower
    # the list ends with the higher edged of the last tower

    #HCAL barrel: deta=0.00195 towers up to |eta| <=0.87 (45°)
    #HCAL endcaps: deta=0.004 towers up to |eta| <=2.59 (8.6°)
    #HCAL cell sizes always 5.6x5.6 mm^2

    #barrel:                                                                    
     set PhiBins {}
    for {set i -1402} {$i <= 1402} {incr i} {
        add PhiBins [expr {$i * $pi/1402.0 }]
    }
    #deta=0.00195 units for |eta| <= 0.87                                       
    for {set i -446} {$i <=446} {incr i} {
        set eta [expr {$i * 0.00195}]
        add EtaPhiBins $eta $PhiBins
    }

    #endcaps:                                                                   
    set PhiBins {}
    for {set i -1402} {$i <= 1402} {incr i} {
        add PhiBins [expr {$i * $pi/1402.}]
    }
    #deta=0.004 units for 0.87 < |eta| <= 2.59                                      
    #first, from -2.59 to -0.87             
    for {set i 1} {$i <=410} {incr i} {
        set eta [expr {-2.59 + $i * 0.004}]
        add EtaPhiBins $eta $PhiBins
    }
    #same for 0.87 to 2.59                                                        
    for  {set i 1} {$i <=410} {incr i} {
        set eta [expr {0.87 + $i*0.004}]
        add EtaPhiBins $eta $PhiBins
    }

    # default energy fractions {abs(PDG code)} {Fecal Fhcal}
    add EnergyFraction {0} {1.0}
    # energy fractions for e, gamma and pi0
    add EnergyFraction {11} {0.0}
    add EnergyFraction {22} {0.0}
    add EnergyFraction {111} {0.0}
    # energy fractions for muon, neutrinos and neutralinos
    add EnergyFraction {12} {0.0}
    add EnergyFraction {13} {0.0}
    add EnergyFraction {14} {0.0}
    add EnergyFraction {16} {0.0}
    add EnergyFraction {1000022} {0.0}
    add EnergyFraction {1000023} {0.0}
    add EnergyFraction {1000025} {0.0}
    add EnergyFraction {1000035} {0.0}
    add EnergyFraction {1000045} {0.0}
    # energy fractions for K0short and Lambda
    add EnergyFraction {310} {0.7}
    add EnergyFraction {3122} {0.7}

    # set HCalResolutionFormula {resolution formula as a function of eta and energy}
    set ResolutionFormula {
    (abs(eta) <= 0.87 )                     * sqrt(energy^2*0.01^2 + energy*0.30^2)+
    (abs(eta) > 0.87 && abs(eta) <=2.59)    * sqrt(energy^2*0.01^2 + energy*0.30^2)}
}

###################
# EFlowTrack merger
###################

module Merger EFlowTrackMerger {
    # add InputArray InputArray
    add InputArray ECal/DREeflowTracks
    add InputArray HCal/DRHeflowTracks
    set OutputArray eflowTracks
}

#################
# Electron filter
#################

module PdgCodeFilter ElectronFilter {
    set InputArray EFlowTrackMerger/eflowTracks
    set OutputArray electrons
    set Invert true
    add PdgCode {11}
    add PdgCode {-11}
}

######################
# ChargedHadronFilter
######################

module PdgCodeFilter ChargedHadronFilter {
    set InputArray EFlowTrackMerger/eflowTracks
    set OutputArray chargedHadrons
    
    add PdgCode {11}
    add PdgCode {-11}
    add PdgCode {13}
    add PdgCode {-13}
}

###################################################
# Tower Merger (in case not using e-flow algorithm)
###################################################

module Merger Calorimeter {
    # add InputArray InputArray
    add InputArray ECal/ecalTowers
    add InputArray HCal/hcalTowers
    set OutputArray towers
}

####################
# Energy flow merger
####################

module Merger EFlowMerger {
    # add InputArray InputArray
    add InputArray EFlowTrackMerger/eflowTracks
    add InputArray ECal/eflowPhotons
    add InputArray HCal/eflowNeutralHadrons
    set OutputArray eflow
}

###################
# Photon efficiency
###################

module Efficiency PhotonEfficiency {
    set InputArray ECal/eflowPhotons
    set OutputArray photons

    # set EfficiencyFormula {efficiency formula as a function of eta and pt}

    # efficiency formula for photons
    set EfficiencyFormula {
	(energy < 2.0)                                         * (0.000)+
	(energy >= 2.0) * (abs(eta) <= 0.87)                   * (0.99) +
	(energy >= 2.0) * (abs(eta) >0.87 && abs(eta) <= 2.59) * (0.99)	+
        (abs(eta) > 2.59)                                      * (0.000)}
}

##################
# Photon isolation
##################

module Isolation PhotonIsolation {
    set CandidateInputArray PhotonEfficiency/photons
    set IsolationInputArray EFlowMerger/eflow

    set OutputArray photons

    set DeltaRMax 0.5

    set PTMin 0.5

    set PTRatioMax 0.12
}

#####################
# Electron efficiency
#####################

module Efficiency ElectronEfficiency {
    set InputArray ElectronFilter/electrons
    set OutputArray electrons

    # set EfficiencyFormula {efficiency formula as a function of eta and pt}

    set EfficiencyFormula {
	(energy < 2.0)                                         * (0.000)+
	(energy >= 2.0) * (abs(eta) <= 0.87)                   * (0.99) +
	(energy >= 2.0) * (abs(eta) >0.87 && abs(eta) <= 2.59) * (0.99)	+
        (abs(eta) > 2.59)                                      * (0.000)}
}

####################
# Electron isolation
####################

module Isolation ElectronIsolation {
    set CandidateInputArray ElectronEfficiency/electrons
    set IsolationInputArray EFlowMerger/eflow

    set OutputArray electrons

    set DeltaRMax 0.5

    set PTMin 0.5

    set PTRatioMax 0.12
}

#################
# Muon efficiency
#################

module Efficiency MuonEfficiency {
    set InputArray MuonMomentumSmearing/muons
    set OutputArray muons

    # set EfficiencyFormula {efficiency as a function of eta and pt}

    # efficiency formula for muons
    # current full simulation of CLICdet yields:

    set EfficiencyFormula {
	(energy < 2.0)                                         * (0.000)+
	(energy >= 2.0) * (abs(eta) <= 0.87)                   * (0.99) +
	(energy >= 2.0) * (abs(eta) >0.87 && abs(eta) <= 2.59) * (0.99)	+
        (abs(eta) > 2.59)                                      * (0.000)}
}

################
# Muon isolation
################

module Isolation MuonIsolation {
    set CandidateInputArray MuonEfficiency/muons
    set IsolationInputArray EFlowMerger/eflow

    set OutputArray muons

    set DeltaRMax 0.5

    set PTMin 0.5

    set PTRatioMax 0.25
}

###################
# Missing ET merger
###################

module Merger MissingET {
    # add InputArray InputArray
    add InputArray EFlowMerger/eflow
    set MomentumOutputArray momentum
}

##################
# Scalar HT merger
##################

module Merger ScalarHT {
    # add InputArray InputArray
    add InputArray EFlowMerger/eflow
    set EnergyOutputArray energy

}

##################################
# EFlowFilter (UniqueObjectFinder)
##################################

module UniqueObjectFinder EFlowFilter {
    add InputArray PhotonIsolation/photons photons
    add InputArray ElectronIsolation/electrons electrons
    add InputArray MuonIsolation/muons muons
    add InputArray EFlowMerger/eflow eflow
}

#################
# Neutrino Filter
#################

module PdgCodeFilter NeutrinoFilter {

    set InputArray Delphes/stableParticles
    set OutputArray filteredParticles

    set PTMin 0.0

    add PdgCode {12}
    add PdgCode {14}
    add PdgCode {16}
    add PdgCode {-12}
    add PdgCode {-14}
    add PdgCode {-16}
}

#####################
# MC truth jet finder
#####################

module FastJetFinder GenJetFinder {
    set InputArray NeutrinoFilter/filteredParticles

    set OutputArray jets

    # algorithm: 1 CDFJetClu, 2 MidPoint, 3 SIScone, 4 kt, 5 Cambridge/Aachen, 6 antikt, 7 anti-kt with winner-take-all axis (for N-subjettiness), 8 N-jettiness, 9 Valencia
    set JetAlgorithm 6
    set ParameterR 0.5
    set JetPTMin 20.0
}

#########################
# Gen Missing ET merger
########################

module Merger GenMissingET {
    # add InputArray InputArray
    add InputArray NeutrinoFilter/filteredParticles
    set MomentumOutputArray momentum
}

############
# Jet finder
############

module FastJetFinder FastJetFinderAntiKt {
    #  set InputArray Calorimeter/towers
    set InputArray EFlowMerger/eflow

    set OutputArray jets

    # algorithm: 1 CDFJetClu, 2 MidPoint, 3 SIScone, 4 kt, 5 Cambridge/Aachen, 6 antikt, 7 anti-kt with winner-take-all axis (for N-subjettiness), 8 N-jettiness, 9 Valencia
    set JetAlgorithm 6
    set ParameterR 0.5
    set JetPTMin 20.0
}

##################                                                                                                                        
# Jet Energy Scale                                                                                                                            
##################                                                                                                              

module EnergyScale JetEnergyScale {
    set InputArray FastJetFinderAntiKt/jets
    set OutputArray jets
    
    # scale formula for jets                                                                                                    
    set ScaleFormula {1.08}
}

########################
# Jet Flavor Association
########################

module JetFlavorAssociation JetFlavorAssociation {

  set PartonInputArray Delphes/partons
  set ParticleInputArray Delphes/allParticles
  set ParticleLHEFInputArray Delphes/allParticlesLHEF
  set JetInputArray JetEnergyScale/jets

  set DeltaR 0.5
  set PartonPTMin 1.0
  set PartonEtaMax 3.0
}

###########
# b-tagging
###########

module BTagging BTagging {
    set JetInputArray JetEnergyScale/jets
    set BitNumber 0
 
    # default efficiency formula (misidentification rate)
    add EfficiencyFormula {0} {0.001}
    
    # efficiency formula for c-jets (misidentification rate)
    add EfficiencyFormula {4} {0.10}
    
    # efficiency formula for b-jets
    add EfficiencyFormula {5} {0.80}
}

###########                                                                                                                                
# c-tagging                                                                                                                                        
###########                                                                                                                         

module BTagging CTagging {
    set JetInputArray JetEnergyScale/jets
    set BitNumber 1

    # default efficiency formula (misidentification rate)                                                                       
    add EfficiencyFormula {0} {0.12}
    
    # efficiency formula for c-jets (misidentification rate)                                                                                 
    add EfficiencyFormula {4} {0.70}

    # efficiency formula for b-jets                                                                                               
    add EfficiencyFormula {5} {0.20}
}

#############
# tau-tagging
#############

module TauTagging TauTagging {
  set ParticleInputArray Delphes/allParticles
  set PartonInputArray Delphes/partons
  set JetInputArray JetEnergyScale/jets

  set DeltaR 0.5
  set TauPTMin 1.0
  set TauEtaMax 3.0

  # default efficiency formula (misidentification rate)
  add EfficiencyFormula {0} {0.001}
  # efficiency formula for tau-jets
  add EfficiencyFormula {15} {0.6}
}


##################
# ROOT tree writer
##################

module TreeWriter TreeWriter {
    # add Branch InputArray BranchName BranchClass

    add Branch Delphes/allParticles Particle GenParticle
    
    ##### We save electrons and muons collection at various livels of the card flow
    add Branch ParticlePropagator/electrons Electron1 Electron
    add Branch ElectronMomentumSmearing/electrons Electron2 Electron
    add Branch ElectronFilter/electrons Electron3 Electron
    add Branch ElectronIsolation/electrons Electron4 Electron

    add Branch ParticlePropagator/muons Muon1 Muon
    add Branch MuonMomentumSmearing/muons Muon2 Muon
    add Branch MuonIsolation/muons Muon3 Muon

    ##### Final Collections 
    add Branch EFlowFilter/photons Photon Photon
    add Branch EFlowFilter/electrons Electron Electron
    add Branch EFlowFilter/muons Muon Muon
    
    add Branch GenMissingET/momentum GenMissingET MissingET
    add Branch Calorimeter/towers Tower Tower

    add Branch EFlowTrackMerger/eflowTracks EFlowTrack Track
    add Branch ECal/eflowPhotons EFlowPhoton Tower
    add Branch HCal/eflowNeutralHadrons EFlowNeutralHadron Tower

    add Branch GenJetFinder/jets GenJet Jet
    add Branch JetEnergyScale/jets AntiKtJet Jet
    
    add Branch MissingET/momentum MissingET MissingET
    add Branch ScalarHT/energy ScalarHT ScalarHT
}

