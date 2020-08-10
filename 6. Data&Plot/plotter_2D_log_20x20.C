//May,22,2020 cut

{
  std::cout<<"starting"<<std::endl;

  double bin_x[21];
  double bin_y[21];
  
  //for(int i=50;i>=0;i--){bin_x[50-i]=TMath::Power(10.,(-3.*i*2/100.));}//50-ds original
  for(int i=20;i>=0;i--){bin_x[20-i]=TMath::Power(10.,(-2.3982*i*5/100.));}

  //for(int i=0;i<51;i++){bin_y[i]=TMath::Power(10,(-2 + 3.*i*2/100.));}//dm
  for(int i=0;i<21;i++){bin_y[i]=TMath::Power(10,(-2 + 3.302*i*5/100.));}//20dm
  //for(int i=0;i<51;i++){bin_y[i]=TMath::Power(10,(-2 + 4*i*2/100.));}//100dm
  //for(int i=0;i<51;i++){bin_y[i]=TMath::Power(10,(-1.097 + 1.8755*i*2/100.));}

  //for(int i=0;i<51;i++){bin_x[i]=i*0.02; bin_y[i]=i*0.4; }//linear

  double aa,bb,cc,dd,ee,ff;
  TH2D* p1_CL = new TH2D("p1_CL","p1_CL",20,bin_x,20,bin_y);
  TH2D* p2_CL = new TH2D("p2_CL","p2_CL",20,bin_x,20,bin_y);
  TH2D* p3_CL = new TH2D("p3_CL","p3_CL",20,bin_x,20,bin_y);

  TH2D* hContour = new TH2D("","",20,bin_x,20,bin_y);

  ifstream inContour;
  inContour.open("./N_0.1binwidth_3.1_20x20.txt");

  ifstream inContourv;
  inContourv.open("./N_0.1binwidth_3.1_20x20.txt");

  double minv = 1e10;
  double mina, minb;
  while(! inContourv.eof())
  {
      inContourv>>aa>>bb>>cc;//>>dd>>ee>>ff;//aa=dm, bb=ds, cc=chi2
      if(cc<350) {cc=999;}//May,22,2020
      std::cout<<"aa bb cc"<<aa<<" "<<bb<<" "<<cc<<endl;
      if(cc< minv) {minv = cc; mina = aa; minb = bb;}
  }

  std::cout<<"minimum value is "<<mina<<" "<<minb<<" "<<minv<<std::endl;

  while(! inContour.eof())
  {
      inContour>>aa>>bb>>cc;
      //double dS = TMath::Power(10.,(-3.*aa*2/100.));
      //double dM = TMath::Power(10,(-2 + 3.*bb*2/100.));
      /*
      p1_CL->SetBinContent(bb,aa,cc-minv);//50-ds,dm,chi2
      p2_CL->SetBinContent(bb,aa,cc-minv);
      p3_CL->SetBinContent(bb,aa,cc-minv);
      hContour->SetBinContent(bb,aa, cc-minv);
      */
       
      p1_CL->SetBinContent(20-bb,aa,cc-minv);//50-ds,dm,chi2
      p2_CL->SetBinContent(20-bb,aa,cc-minv);
      p3_CL->SetBinContent(20-bb,aa,cc-minv);
      hContour->SetBinContent(20-bb,aa, cc-minv);
      
  }

  double conto[1];
  conto[0] = 74.39;//39.087*2; // 40.256;
  p1_CL->SetContour(1,conto);
  p1_CL->SetLineWidth(3);
  p1_CL->SetLineColor(1);
   
  double conto2[1];
  conto2[0] = 79.08;//42.557*2; // 43.773;
  p2_CL->SetContour(1,conto2);
  p2_CL->SetLineWidth(3);
  p2_CL->SetLineColor(2);

  double conto3[1];
  conto3[0] = 88.40;//49.588*2; //50.892;
  p3_CL->SetContour(1,conto3);
  p3_CL->SetLineWidth(3);
  p3_CL->SetLineColor(4);
  
  TCanvas* c1 = new TCanvas();
  p1_CL->GetXaxis()->SetTitle("sin^{2}(2#theta_{s})");
  p1_CL->GetYaxis()->SetTitle("#Delta m^{2}_{s} eV^{2}");
  p1_CL->Draw("cont3");
  p2_CL->Draw("cont3 same");
  p3_CL->Draw("cont3 same");
  c1->SetLogy();
  c1->SetLogx();

  TCanvas* c2 = new TCanvas();
  hContour->GetXaxis()->SetTitle("sin^{2}(2#theta_{s})");
  hContour->GetYaxis()->SetTitle("#Delta m^{2}_{s} eV^{2}");
  hContour->Draw("colz");
  c2->SetLogy();
  c2->SetLogx();

  c1->SaveAs("test_plot1.png");
  c2->SaveAs("test_plot2.png");

}

