#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;


void gamma1(){

	TFile *file = new TFile("data_La_double.root","read");
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
	TH1D *hist_edep1 = new TH1D("hist_edep1","deposited energy;keV;counts",3000,0,3000);
	TH2D *hist_coin = new TH2D("hist_coin","",3000,0,3000,3000,0,3000);
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
		cout << edep<< endl;
		if (i == 0)	a = eventID;

		
		
		 
	
		if(eventID==a)
		{
			//s1=d1*(exp(2.23296-0.00737*d1)-0.00144274*d1+4.35266)/234.582;
			//c1=gRandom -> Gaus(d1,s1);
			//hist_edep1->Fill(c1);
			if(volumeID==200)
			{
				b=b+edep;
			}
		}
		else
		{
			if(b>80)
			{
				s=b*(exp(3.61114-0.0715599*b)-0.0018171*b+5.28785)/234.582;
				c=gRandom -> Gaus(b,s);
				//cout << particleID <<" " << endl;
				hist_edep->Fill(c);
				b=edep;
			}
		}
	//	else continue;
		a=eventID;
	}


	//Int_t colors[] = {0, 1, 2, 3, 4, 5, 6};
	//gStyle->SetPalette((sizeof(colors)/sizeof(Int_t)), colors);
	//Double_t levels[] = {-1.79e308, 1.17e-38, 0.90, 0.95, 1.00, 1.05, 1.10, 1.79e308};
	//hist_coin->SetContour((sizeof(levels)/sizeof(Double_t)), levels);	
	
	hist_edep->Draw();        
	
	//TCanvas *cvs1=new TCanvas("cvs","",1000,600);
	//hist_coin->Draw("colz");
	//tree1->Write();
        //file1->Close();		
}
