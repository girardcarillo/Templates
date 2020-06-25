// Author Cloé Girard-Carillo girardcarillo@lal.in2p3.fr

#include <limits>
#include <string>
#include <iostream>
#include <map>

#include <TTree.h>
#include <TFile.h>
#include <TObject.h>
#include <TH1.h>
#include <TH2.h>

#include "/home/girardcarillo/Workdir/SNPlot/RootDisplay.h"
#include "/home/girardcarillo/Workdir/SNPlot/EventTree.h"

using namespace std ;

void MacroExample(){

  TCanvas *c1 = new TCanvas("c1","c1",10,10,2000,1000);

  ///Loop on all .root files
  for ( int i = 0 ; i < 10 ; ++i ) {

    TH1F *hDeltaT = new TH1F(Form("title %d",i),"name",100,-10,10);

    string filename = "path" ;

    stringstream ss ;
    ss << i ;
    string str = ss.str() ;

    filename = filename+str+".root" ;
    TFile *theInFile = TFile::Open(filename.c_str(),"READ") ;

    if ( theInFile->IsOpen() ) {
      cout << "File " << filename << " opened sucessfully" << endl ;
    }

    TTree *theTree = (TTree*)theInFile->Get("") ;
    theTree->SetBranchAddress("variable",&variable) ;
    cout << theTree->GetEntries() << " entries"<< endl ;


    for (Long64_t i=0;i<theTree->GetEntries();i++) {
      theTree->GetEntry(i);



    }


    theInFile->Close() ;
    theInFile->Delete() ;

    if ( !theInFile->IsOpen() ) {
      cout << "File " << filename << " closed sucessfully" << endl ;
    }

  }

}
