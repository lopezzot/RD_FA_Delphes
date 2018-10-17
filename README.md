# RD_FA_Delphes
Delphes IDEA simulation

Implementation of the IDEA Detector with Delphes. 
Working folders and files:
        cards -> delphes_card_IDEAdet.tcl
        (all) Pythia8 generation files -> Delphes-3.4.1/examples/Pythia8/mypythia
        (all) Pyroot analysis -> Delphes-3.4.1/examples/myanalysis

To generate events with DelphesPythia8 run in Delphes-3.4.1:
        ./DelphesPythia8 cards/delphes_card_IDEAdet.tcl examples/Pythia8/mypythia/MYCONFIG.cmnd MYNEWOUTPUT.root
        
To analyize data with Pyroot in Delphes-3.4.1:
        python examples/myanalysis/MYANALYSIS.py MYNEWOUTPUT.root MYANALYSYSOUTPUT.root
        
  
  
TO INSTALL DELPHES AND CONFIGURE WITH PYTHIA8:

(the following commands will install Delphes in $HOME/Delphes-3.4.1)
cd $HOME
wget http://cp3.irmp.ucl.ac.be/downloads/Delphes-3.4.1.tar.gz
tar -zxf Delphes-3.4.1.tar.gz
cd Delphes-3.4.1
make -j 4
(the following commands will install Pythia8 in $HOME/pythia8235 and configure Delphes to also run Pythia8)
cd $HOME
wget http://home.thep.lu.se/~torbjorn/pythia8/pythia8235.tgz
tar xzvf pythia8235.tgz
cd pythia8235
./configure --prefix=$HOME/Pythia8
make install
export PYTHIA8=$HOME/Pythia8
cd $HOME/Delphes-3.4.1
make HAS_PYTHIA8=true DelphesPythia8
(the following commands sets the environment variables that will be set at login)
cd $HOME
echo PYTHIA8=\”\$HOME/Pythia8\” >> $HOME/.bashrc
(the following commands check that the binaries are there)
cd $HOME/Delphes-3.4.1
./DelphesHepMC
./DelphesPythia8 cards/delphes_card_CMS.tcl \
examples/Pythia8/configNoLHE.cmnd delphes_nolhe.root
