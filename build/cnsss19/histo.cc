void histo(){


	auto file1 = new TFile("hist_117133_6cluster.root");
	auto file2 = new TFile("hist_117133_ringtype.root");
	auto file7 = new TFile("hist_LaCo_4cluster.root");

	auto file3 = new TFile("hist_662_6cluster.root");
	auto file4 = new TFile("hist_662_ringtype.root");



	auto hist1 = (TH1D *) file1 -> Get("hist_24eet");
	auto hist2 = (TH1D *) file1 -> Get("hist_onedet");
	auto hist3 = (TH1D *) file2 -> Get("hist_onedet");

	auto hist4 = (TH1D *) file3 -> Get("hist_24eet");
	auto hist5 = (TH1D *) file3 -> Get("hist_onedet");
	auto hist6 = (TH1D *) file4 -> Get("hist_onedet");

	auto hist9 = (TH1D *) file7 -> Get("hist_fourdet");
	auto hist10 = (TH1D *) file7 -> Get("hist_onedet_0");

	double a;
	/*
	for(int i=0;i<2500;i++)
	{

		a=hist9->GetBinContent(i);
		hist9->SetBinContent(i,a/3);
		a=hist10->GetBinContent(i);
		hist10->SetBinContent(i,a/3);

	}
	*/


 hist4->Add(hist9);
 hist5->Add(hist10);
 hist6->Add(hist10);


hist6->Draw();
hist4->Draw("same");
hist5->Draw("same");
hist6->SetLineColor(3);


 



}
