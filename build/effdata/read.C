void read()
{
	          gStyle->SetOptStat(0);

	auto file1 = new TFile("hist_eff100_6cluster.root");
	auto file2 = new TFile("hist_eff200_6cluster.root");
	auto file3 = new TFile("hist_eff300_6cluster.root");
	auto file4 = new TFile("hist_eff400_6cluster.root");
	auto file5 = new TFile("hist_eff500_6cluster.root");
	auto file6 = new TFile("hist_eff600_6cluster.root");
	auto file7 = new TFile("hist_eff700_6cluster.root");
	auto file8 = new TFile("hist_eff800_6cluster.root");
	auto file9 = new TFile("hist_eff900_6cluster.root");
	auto file10 = new TFile("hist_eff1000_6cluster.root");
	auto file11 = new TFile("hist_eff1500_6cluster.root");
	auto file12 = new TFile("hist_eff2000_6cluster.root");
	
	auto file13 = new TFile("hist_eff100_ringtype.root");
	auto file14 = new TFile("hist_eff200_ringtype.root");
	auto file15 = new TFile("hist_eff300_ringtype.root");
	auto file16 = new TFile("hist_eff400_ringtype.root");
	auto file17 = new TFile("hist_eff500_ringtype.root");
	auto file18 = new TFile("hist_eff600_ringtype.root");
	auto file19 = new TFile("hist_eff700_ringtype.root");
	auto file20 = new TFile("hist_eff800_ringtype.root");
	auto file21 = new TFile("hist_eff900_ringtype.root");
	auto file22 = new TFile("hist_eff1000_ringtype.root");
	auto file23 = new TFile("hist_eff1500_ringtype.root");
	auto file24 = new TFile("hist_eff2000_ringtype.root");
	
	auto hist1 = (TGraph *) file1 -> Get("graph_ab");
	auto hist2 = (TGraph *) file1 -> Get("graph");
	auto hist3 = (TGraph *) file2 -> Get("graph_ab");
	auto hist4 = (TGraph *) file2 -> Get("graph");
	auto hist5 = (TGraph *) file3 -> Get("graph_ab");
	auto hist6 = (TGraph *) file3 -> Get("graph");
	auto hist7 = (TGraph *) file4 -> Get("graph_ab");
	auto hist8 = (TGraph *) file4 -> Get("graph");
	auto hist9 = (TGraph *) file5 -> Get("graph_ab");
	auto hist10 = (TGraph *) file5 -> Get("graph");
	auto hist11 = (TGraph *) file6 -> Get("graph_ab");
	auto hist12 = (TGraph *) file6 -> Get("graph");
	auto hist13 = (TGraph *) file7 -> Get("graph_ab");
	auto hist14 = (TGraph *) file7 -> Get("graph");
	auto hist15 = (TGraph *) file8 -> Get("graph_ab");
	auto hist16 = (TGraph *) file8 -> Get("graph");
	auto hist17 = (TGraph *) file9 -> Get("graph_ab");
	auto hist18 = (TGraph *) file9 -> Get("graph");
	auto hist19 = (TGraph *) file10 -> Get("graph_ab");
	auto hist20 = (TGraph *) file10 -> Get("graph");
	auto hist21 = (TGraph *) file11 -> Get("graph_ab");
	auto hist22 = (TGraph *) file11 -> Get("graph");
	auto hist23 = (TGraph *) file12 -> Get("graph_ab");
	auto hist24 = (TGraph *) file12 -> Get("graph");

	auto hist25 = (TGraph *) file13 -> Get("graph");
	auto hist26 = (TGraph *) file14 -> Get("graph");
	auto hist27 = (TGraph *) file15 -> Get("graph");
	auto hist28 = (TGraph *) file16 -> Get("graph");
	auto hist29 = (TGraph *) file17 -> Get("graph");
	auto hist30 = (TGraph *) file18 -> Get("graph");
	auto hist31 = (TGraph *) file19 -> Get("graph");
	auto hist32 = (TGraph *) file20 -> Get("graph");
	auto hist33 = (TGraph *) file21 -> Get("graph");
	auto hist34 = (TGraph *) file22 -> Get("graph");
	auto hist35 = (TGraph *) file23 -> Get("graph");
	auto hist36 = (TGraph *) file24 -> Get("graph");

	
	TH2D *back = new TH2D("hist_effab",";keV;Efficiency(%)",100,0,2200,100,0.4,24);










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
	TCanvas *cvs= new TCanvas("CVS","",700,500);
	back->Draw();
	hist25->Draw("P");
	hist1->Draw("P");

	hist2->Draw("P");
	hist3->Draw("P");
	hist4->Draw("P");
	hist5->Draw("P");
	hist6->Draw("P");
	hist7->Draw("P");
	hist8->Draw("P");
	hist9->Draw("P");
	hist10->Draw("P");
	hist11->Draw("P");
	hist12->Draw("P");
	hist13->Draw("P");
	hist14->Draw("P");
	hist15->Draw("P");
	hist16->Draw("P");
	hist17->Draw("P");
	hist18->Draw("P");
	hist19->Draw("P");
	hist20->Draw("P");
	hist21->Draw("P");
	hist22->Draw("P");
	hist23->Draw("P");
	hist24->Draw("P");

	hist26->Draw("P");
	hist27->Draw("P");
	hist28->Draw("P");
	hist29->Draw("P");
	hist30->Draw("P");
	hist31->Draw("P");
	hist32->Draw("P");
	hist33->Draw("P");
	hist34->Draw("P");
	hist35->Draw("P");
	hist36->Draw("P");


	hist25->SetMarkerColor(3);
	hist26->SetMarkerColor(3);
	hist26->SetMarkerColor(3);
	hist27->SetMarkerColor(3);
	hist28->SetMarkerColor(3);
	hist29->SetMarkerColor(3);
	hist30->SetMarkerColor(3);
	hist31->SetMarkerColor(3);
	hist32->SetMarkerColor(3);
	hist33->SetMarkerColor(3);
	hist34->SetMarkerColor(3);
	hist35->SetMarkerColor(3);
	hist36->SetMarkerColor(3);
	//TCanvas *cvs= new TCanvas("CVS","",700,500);
	//cvs->cd(2);
//	hist6 -> SetLineColor(3);
}

