//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb 17 18:19:23 2016 by ROOT version 6.06/00
// from TTree ElectronTree/Electron data
// found on file: electron_ntuple_mini.root
//////////////////////////////////////////////////////////

#ifndef ElectronTree_h
#define ElectronTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class ElectronTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   Int_t           evtnum;
   Int_t           nEle;
   vector<float>   *pt;
   vector<float>   *eta;
   vector<float>   *phi;
   vector<float>   *mvaVal;
   vector<int>     *mvaCat;
   vector<int>     *passMediumId;
   vector<int>     *passTightId;
   vector<int>     *isTrue;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_evtnum;   //!
   TBranch        *b_nEle;   //!
   TBranch        *b_pt;   //!
   TBranch        *b_eta;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_mvaVal;   //!
   TBranch        *b_mvaCat;   //!
   TBranch        *b_passMediumId;   //!
   TBranch        *b_passTightId;   //!
   TBranch        *b_isTrue;   //!

   ElectronTree(TTree *tree=0);
   virtual ~ElectronTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ElectronTree_cxx
ElectronTree::ElectronTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("electron_ntuple_mini.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("electron_ntuple_mini.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("electron_ntuple_mini.root:/ntupler");
      dir->GetObject("ElectronTree",tree);

   }
   Init(tree);
}

ElectronTree::~ElectronTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ElectronTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ElectronTree::LoadTree(Long64_t entry)
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

void ElectronTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pt = 0;
   eta = 0;
   phi = 0;
   mvaVal = 0;
   mvaCat = 0;
   passMediumId = 0;
   passTightId = 0;
   isTrue = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("evtnum", &evtnum, &b_evtnum);
   fChain->SetBranchAddress("nEle", &nEle, &b_nEle);
   fChain->SetBranchAddress("pt", &pt, &b_pt);
   fChain->SetBranchAddress("eta", &eta, &b_eta);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("mvaVal", &mvaVal, &b_mvaVal);
   fChain->SetBranchAddress("mvaCat", &mvaCat, &b_mvaCat);
   fChain->SetBranchAddress("passMediumId", &passMediumId, &b_passMediumId);
   fChain->SetBranchAddress("passTightId", &passTightId, &b_passTightId);
   fChain->SetBranchAddress("isTrue", &isTrue, &b_isTrue);
   Notify();
}

Bool_t ElectronTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ElectronTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ElectronTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ElectronTree_cxx
