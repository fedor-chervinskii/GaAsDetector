{
TFile *_file0 = TFile::Open("/home/fedor/GaAsDetector/build/file.root");
TTree* t;
t = (TTree*) _file0->Get("myTree");
Float_t p[3];
Float_t x[3];
Int_t parentid;
Float_t me, E, p1;
TH1F *hm1 = new TH1F("histogramm of E, primaries, el","electron",1000,0,1);
TCanvas *canvas = new TCanvas();
t->SetBranchAddress("E0",&E);
t->SetBranchAddress("parentid",&parentid);

Int_t nentries = (Int_t)t->GetEntries();

for (Int_t i=0; i<nentries; i++) 
{
  t->GetEntry(i);
  if(parentid==1) hm1->Fill(E);
}

 hm1->Draw();

 printf("N = %i \n", nentries);

}
