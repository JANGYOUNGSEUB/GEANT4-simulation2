void read()
{
	          gStyle->SetOptStat(0);

	auto file1 = new TFile("hist_Co_6cluster.root");
	auto file2 = new TFile("hist_Co_ringtype.root");
	auto file3 = new TFile("hist_Eu_6cluster.root");
	auto file4 = new TFile("hist_Eu_ringtype.root");
	auto file5 = new TFile("hist_Eu_exp.root");
	auto file6 = new TFile("hist_Co_exp.root");
	auto file7 = new TFile("hist_LaCo_4cluster.root");
	
	auto hist1 = (TH1D *) file1 -> Get("hist_24eet");
	auto hist2 = (TH1D *) file1 -> Get("hist_onedet");
	auto hist3 = (TH1D *) file2 -> Get("hist_onedet");
	auto hist4 = (TH1D *) file3 -> Get("hist_24eet");
	auto hist5 = (TH1D *) file3 -> Get("hist_onedet");
	auto hist6 = (TH1D *) file4 -> Get("hist_onedet");
	auto hist7 = (TH1D *) file5 -> Get("QDC");
	auto hist8 = (TH1D *) file6 -> Get("QDC");

	auto hist9 = (TH1D *) file7 -> Get("hist_fourdet");
	auto hist10 = (TH1D *) file7 -> Get("hist_onedet_0");
//	TCanvas *cvs= new TCanvas("CVS","",1200,1200);
//	cvs->Divide(2,2);
//	cvs->cd(1);
/*
	hist1->Rebin(10);
	hist2->Rebin(10);
	hist3->Rebin(10);
	hist4->Rebin(10);
	hist5->Rebin(10);
	hist6->Rebin(10);
*/	


//for(int i=0;i<6;i++)
{
	hist1->Add(hist9);
}
//for(int i=0;i<6;i++)
{
	hist2->Add(hist10);
	hist3->Add(hist10);
}
	hist3 -> Draw();
	hist1 -> Draw("same");
	hist2 -> Draw("same");
	cout <<hist2->GetBinContent(1174)/ (hist3->GetBinContent(1174))<<" " <<(hist2->GetBinContent(1174))<<endl;
	//hist8 -> Draw("same");
	//hist8 -> SetLineColor(3);
	//hist8 -> Draw("same");
	hist3 -> SetLineColor(3);
	TCanvas *cvs= new TCanvas("CVS","",700,500);
	cvs->cd(2);
	hist4->Add(hist9);
	hist5->Add(hist10);
	hist6->Add(hist10);
	hist6 -> Draw();
	hist5 -> Draw("same");
	hist4 -> Draw("same");
	//hist7 -> Draw("same");
	//hist7 -> SetLineColor(3);
	//hist7 -> Draw("same");
	hist6 -> SetLineColor(3);
	//hist10->Draw();
	//hist9->Draw("same");
}

