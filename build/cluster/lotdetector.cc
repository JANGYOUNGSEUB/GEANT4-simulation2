#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;


void lotdetector(){

	TFile *file = new TFile("data.root","read");
	TTree *data = (TTree *)file -> Get("data");
	//TFile *file1 = new TFile("hist_g4.root","recreate");
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
	TH1D *hist_fourdet = new TH1D("hist_edep1","deposited energy;keV;counts",3000,0,3000);
	TH1D *hist_onedet[4] ;
	for (Int_t i = 0; i < 4; i++)
	{
		hist_onedet[i] = new TH1D(Form("hist_waveform_%d", i), "",2000, 0, 2000);
	}
	TH1D *hist_onedet1 = new TH1D("hist_coin","",5,0,5);
	TH1D *hist_onedet2 = new TH1D("hist_coin","",3000,0,3000);
	TH1D *hist_onedet3 = new TH1D("hist_coin","",3000,0,3000);
	TH1D *hist_onedet4 = new TH1D("hist_coin","",3000,0,3000);
	int a=0;
	float b=0;
	float b1=0;
	Double_t c;
	Double_t d=0;
	Double_t s;
	Double_t c1=1;
	Double_t d1;
	Double_t s1;
	

	for(int i =0; i< nent; i++)
        {
                data->GetEntry(i);
	//	cout << eventID <<" " << volumeID<< endl;
		if(i==0) {a=eventID;c=volumeID;}
		
		if(eventID==a)
		{
			if(volumeID!=c)
			{
				c1=c1+1;
		//		cout <<c1<< endl;
			}
			//cout <<eventID<< " " << volumeID <<endl;
				
		
		}	
		else
		{ 
		
			hist_onedet1->Fill(c1);
			c1=1;		
		}
		a=eventID;c=volumeID;
	}







	for(int j=1;j<5;j++)
	{   
	for(int i=0; i<nent;i++)
	{
		data->GetEntry(i);
		if(i==0) a=eventID;

		if(eventID==a)
		{   
			if(volumeID==200*j)
			{   
				b=b+edep;
			}    

		}   
		else
		{   

			if(b>30)
			{   
				s=b*(exp(2.28852-0.00800046*b)-0.00171403*b+4.7685)/234.582;
				c=gRandom -> Gaus(b,s);
				hist_onedet[0] ->Fill(c);    
				//cout << c<< " " <<volumeID<<endl;
				b=edep;
			}   
		}   
		a=eventID;
	}
	
	}


	//Int_t colors[] = {0, 1, 2, 3, 4, 5, 6};
	//gStyle->SetPalette((sizeof(colors)/sizeof(Int_t)), colors);
	//Double_t levels[] = {-1.79e308, 1.17e-38, 0.90, 0.95, 1.00, 1.05, 1.10, 1.79e308};
	//hist_coin->SetContour((sizeof(levels)/sizeof(Double_t)), levels);	
	
	hist_onedet1->Draw();        
	//hist_fourdet->SetLineColor(2);        
	//hist_onedet[0]->SetLineColor(4);        
//	h//ist_onedet[1]->SetLineColor(5);        
//	hist_onedet[2]->SetLineColor(6);        
//	hist_onedet[3]->SetLineColor(7);        
//	
//	hist_onedet[0]->Draw("same");        
//	hist_onedet[1]->Draw("same");        
//	hist_onedet[2]->Draw("same");        
//	hist_onedet[3]->Draw("same");        
	
	//TCanvas *cvs1=new TCanvas("cvs","",1000,600);
	//hist_coin->Draw("colz");
	//tree1->Write();
        //file1->Close();		
}
