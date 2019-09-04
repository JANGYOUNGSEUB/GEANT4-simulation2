#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;


void lotdetector(){

	TFile *file = new TFile("data_LaCo_4cluster.root","read");
	TTree *data = (TTree *)file -> Get("data");
	TFile *file1 = new TFile("hist_LaCo_4cluster.root","recreate");
        //TTree *tree1 = new TTree("tree1","tree1");	

	int nent = data->GetEntries();
	int eventID;
	int volumeID;
	int particleID;
	Double_t edep;

	Double_t count_g4;
        //tree1 -> Branch("count_g4",&count_g4);


	data->SetBranchAddress("eventID",&eventID);
	data->SetBranchAddress("volumeID",&volumeID);
	data->SetBranchAddress("edep",&edep);
	data->SetBranchAddress("particleID",&particleID);

	TH1D *hist_edep = new TH1D("hist_edep","deposited energy;keV;counts",3000,0,3000);
	TH1D *hist_fourdet = new TH1D("hist_fourdet","deposited energy;keV;counts",2500,0,2500);
	TH1D *hist_onedet[4] ;
	for (Int_t i = 0; i < 4; i++)
	{
		hist_onedet[i] = new TH1D(Form("hist_onedet_%d", i), "",2500, 0, 2500);
	}
	TH1D *hist_onedet1 = new TH1D("hist_coin","",3000,0,3000);
	TH1D *hist_onedet2 = new TH1D("hist_coin","",3000,0,3000);
	TH1D *hist_onedet3 = new TH1D("hist_coin","",3000,0,3000);
	TH1D *hist_onedet4 = new TH1D("hist_coin","",3000,0,3000);
	int a=0;
	float b=0;
	float b1=0;
	Double_t c;
	Double_t d=0;
	Double_t s;
	Double_t c1;
	Double_t d1;
	Double_t s1;
	

	for(int i =0; i< nent; i++)
        {
                data->GetEntry(i);
		if(i==0) a=eventID;
		
		if(eventID==a)
			{b=b+edep;}	





		else{ 
			if(b>80)
			{
				s=b*(exp(3.61114-0.0715599*b)-0.0018171*b+5.28785)/234.582;
				c=gRandom -> Gaus(b,s);
				hist_fourdet->Fill(c);
			}
				b=edep;
		}
		a=eventID;
	}






	double_t infovol;
		for(int i=0; i<nent;i++)
		{
			data->GetEntry(i);
			if(i==0) a=eventID;

			if(eventID==a)
			{   
				if(volumeID==infovol)
				{   
					b=b+edep;
				}    
				else
				{
					if(b>80)
					{
						//cout << volumeID<<endl;
						//cout << b<<endl;
						s=b*(exp(3.61114-0.0715599*b)-0.0018171*b+5.28785)/235.5;
						c=gRandom -> Gaus(b,s);
						hist_onedet[0]->Fill(c);
					}
					b=edep;


				}   
			}
			else
			{   

				if(b>80)
				{   
					s=b*(exp(3.61114-0.0715599*b)-0.0018171*b+5.28785)/234.582;
					c=gRandom -> Gaus(b,s);
					hist_onedet[0] ->Fill(c);    
				}   
				b=edep;
			}   
			infovol=volumeID;
			a=eventID;
		}


	//Int_t colors[] = {0, 1, 2, 3, 4, 5, 6};
	//gStyle->SetPalette((sizeof(colors)/sizeof(Int_t)), colors);
	//Double_t levels[] = {-1.79e308, 1.17e-38, 0.90, 0.95, 1.00, 1.05, 1.10, 1.79e308};
	//hist_coin->SetContour((sizeof(levels)/sizeof(Double_t)), levels);	
	
	hist_onedet[0]->Draw();
	hist_fourdet->Draw("same");        
	hist_fourdet->SetLineColor(2);        
	hist_onedet[0]->SetLineColor(4);        
	hist_onedet[1]->SetLineColor(5);        
	hist_onedet[2]->SetLineColor(6);        
	hist_onedet[3]->SetLineColor(7);        
	
	//hist_onedet[1]->Draw("same");        
	//hist_onedet[2]->Draw("same");        
	//hist_onedet[3]->Draw("same");        
	
	//TCanvas *cvs1=new TCanvas("cvs","",1000,600);
	//hist_coin->Draw("colz");
	//tree1->Write();
	
	file1->cd();
	hist_onedet[0]->Write();
	hist_fourdet->Write();
        file1->Close();		

}
