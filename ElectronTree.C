#define ElectronTree_cxx
#include "ElectronTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <iostream>
#include <TLorentzVector.h>

void ElectronTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L ElectronTree.C
//      root> ElectronTree t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

	TH1F* h1_m = new TH1F("h1_m","h1_m",200, 0,200);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

		int idx1=-1;
		int idx2=-1;
		for(unsigned int idx=0; idx<pt->size(); idx++) {
			if(passTightId->at(idx)) {
				if(idx1 == -1) idx1 = idx;
				else if(idx2 == -1) idx2 = idx;
			}
		}

		if(idx2 > 0) {
			TLorentzVector p1; p1.SetPtEtaPhiM(pt->at(idx1), eta->at(idx1), phi->at(idx1), 0.0);
			TLorentzVector p2; p2.SetPtEtaPhiM(pt->at(idx2), eta->at(idx2), phi->at(idx2), 0.0);
			TLorentzVector z = p1+ p2;
			std::cout << z.M() << std::endl;
			h1_m->Fill(z.M()) ;
		}

   }

	h1_m->Draw();
}
