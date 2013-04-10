{
TFile *_file0 = TFile::Open("/home/fedor/GaAsDetector/build/file2.root");
TTree* t;
t = (TTree*) _file0->Get("myTree2");
Float_t p[3];
Float_t x[3];
Int_t q;
Float_t me, E, p1;
TH1F *hm1 = new TH1F("histogramm of angles, el","electron",1000,0.97,0.001);
TCanvas *canvas = new TCanvas();
t->SetBranchAddress("px",&p[0]);
t->SetBranchAddress("py",&p[1]);
t->SetBranchAddress("pz",&p[2]);
t->SetBranchAddress("x",&x[0]);
t->SetBranchAddress("y",&x[1]);
t->SetBranchAddress("z",&x[2]);

Int_t nentries = (Int_t)t->GetEntries();

for (Int_t i=0; i<nentries; i++) 
{
  t->GetEntry(i);
  p1 = sqrt(p[1]*p[1]+p[0]*p[0]+p[2]*p[2]);
  hm1->Fill(p1);
}

 hm1->Draw();

 printf("N = %i \n", nentries);

}
