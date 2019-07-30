#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;


void aldecay(){

        TFile *file = new TFile("data.root","read");
        TTree *data = (TTree *)file -> Get("data");

	int nent = data->GetEntries();
        int eventID;
        int volumeID;
        int particleID;
        Double_t edep;

	Double_t count_g4;
	data->SetBranchAddress("eventID",&eventID);
        data->SetBranchAddress("volumeID",&volumeID);
        data->SetBranchAddress("edep",&edep);
        data->SetBranchAddress("particleID",&particleID);

        TH1D *hist_edep = new TH1D("hist_edep","deposited energy;keV;counts",500,0,3000);
        TH1D *hist_edep1 = new TH1D("hist_edep1","deposited energy;keV;counts",500,0,3000);
        TH2D *hist_coin = new TH2D("hist_coin",";keV;keV",3000,0,3000,3000,0,3000);
        int a=0;
        float b=0;
        float b1=0;
        Double_t c;
        Double_t d=0;
        Double_t s;
        Double_t c1;
        Double_t d1;
        Double_t s1;
        Double_t v;
        Double_t v1;

	for(int i=0; i<nent;i++)
	{
		data->GetEntry(i);
		if(i==0) a=eventID;
			
		if(eventID==a)
		{
			if(volumeID==333)
			{
				b=b+edep;
				//cout << edep <<" "<< volumeID << endl;
			}	
		}
		else
		{

			if(b>30)
			{
				s=b*(exp(2.28852-0.00800046*b)-0.00171403*b+4.7685)/234.582;
				c=gRandom -> Gaus(b,s);
				hist_edep ->Fill(b);	
				b=edep;
			}
		}
		a=eventID;
	}
	
	Int_t colors[] = {0, 1, 2, 3, 4, 5, 6};
	gStyle->SetPalette((sizeof(colors)/sizeof(Int_t)), colors);
	Double_t levels[] = {-1.79e38, 1.17e-38, 0.90, 0.95, 1.00, 1.05, 1.10, 1.79e38};
	hist_coin->SetContour((sizeof(levels)/sizeof(Double_t)), levels);  



	hist_edep->Draw();
}
