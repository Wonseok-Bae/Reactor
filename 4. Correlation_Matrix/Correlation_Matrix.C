void Correlation_Matrix()
{
	double bin_x[25];
	double bin_y[25];
	bin_x[0]=1.;   bin_y[0]=1.; 
	bin_x[1]=1.25; bin_y[1]=1.25;
	bin_x[2]=1.5;  bin_y[2]=1.5;
	bin_x[3]=1.75; bin_y[3]=1.75;
	bin_x[4]=2.;   bin_y[4]=2.;
        bin_x[5]=2.25; bin_y[5]=2.25;
        bin_x[6]=2.5;  bin_y[6]=2.5;
        bin_x[7]=2.75; bin_y[7]=2.75;
	bin_x[8]=3.;   bin_y[8]=3.;
        bin_x[9]=3.25; bin_y[9]=3.25;
        bin_x[10]=3.5; bin_y[10]=3.5;
        bin_x[11]=3.75;bin_y[11]=3.75;
	bin_x[12]=4.;  bin_y[12]=4.;
        bin_x[13]=4.25;bin_y[13]=4.25;
        bin_x[14]=4.5; bin_y[14]=4.5;
        bin_x[15]=4.75;bin_y[15]=4.75;
	bin_x[16]=5.;  bin_y[16]=5.;
        bin_x[17]=5.25;bin_y[17]=5.25;
        bin_x[18]=5.5; bin_y[18]=5.5;
        bin_x[19]=5.75;bin_y[19]=5.75;
	bin_x[20]=6.;  bin_y[20]=6.;
        bin_x[21]=6.25;bin_y[21]=6.25;
        bin_x[22]=6.5; bin_y[22]=6.5;
        bin_x[23]=6.75;bin_y[23]=6.75;
	bin_x[24]=7.;  bin_y[24]=7.;
	bin_x[25]=10.; bin_y[25]=10.;
       
	//TFile* outputFile = new TFile("newCorreltionMatrix.root","RECREATE");
	TFile* outputFile = new TFile("NEOSCorrelationMatrix.root","RECREATE");
	//TH2D * nCM = new TH2D("filename","title",25,1,10,25,1,10);
	TH2D * nCM = new TH2D("hCorrelation_0.25MeV","title",25,bin_x,25,bin_y);

	for(int i = 1; i<26; i++)
	{
		for(int j = 1; j<26; j++)
		{
			if(i==j)
			{
				//nCM->Fill(i/2.5,j/2.5,1);
				nCM->SetBinContent(i,j,1);
			}
			else
			{
				//nCM->Fill(i/2.5,j/2.5,0);
				nCM->SetBinContent(i,j,0);
			}

			//cout<<" i: "<<i<<" "<<" j: "<<j<<" x: " << i*0.1 <<" y: "<< j*0.1 <<" vlaue: "<<nCM->GetBinContent(i,j)<<endl;
			cout<<" i: "<<i<<" "<<" j: "<<j<<" "<<" vlaue: "<<nCM->GetBinContent(i,j)<<endl;
		}
	}

	nCM->Write();
	outputFile->Close();
}
	
