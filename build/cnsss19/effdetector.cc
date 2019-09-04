#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include <stdio.h>
#include <iostream>

#include "TStyle.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TRandom.h"

using namespace std;


void effdetector(){

	gStyle->SetOptStat(0);

	TH1D *hist_24det = new TH1D("hist_24eet",";keV;Counts",2500,0,2500);
	TH1D *hist_onedet = new TH1D("hist_onedet",";keV;Counts",2500,0,2500);
	TH2D *hist_effab = new TH2D("hist_effab",";keV;Efficiency(%)",2500,0,2500,100000,0,100);
	TH2D *hist_eff = new TH2D("hist_eff",";keV;Efficiency(%)",100,0,2500,100,0,30);


	TFile *file = new TFile("data_Eu152_6cluster.root","read");
	TTree *data = (TTree *)file -> Get("data");
	TFile *file1 = new TFile("hist_Eu_6cluster.root","recreate");
	auto *hist = (TGraph *)file2 ->Get("graph");


	int nent = data->GetEntries();
	int eventID;
	int volumeID;
	int particleID;
	Double_t edep;
	Double_t KineticEnergy;
	Double_t ergeff_ab[12];
	Double_t ergeff[12];

	Int_t nevt = 1200000;

	data->SetBranchAddress("eventID",&eventID);
	data->SetBranchAddress("volumeID",&volumeID);
	data->SetBranchAddress("edep",&edep);
	data->SetBranchAddress("particleID",&particleID);
	data->SetBranchAddress("KineticEnergy",&KineticEnergy);

	int a=0;
	int inf_vol;
	int inf;
	float b=0;
	Double_t c;
	Double_t s;

//--------------add back-------------------

	for(int i =0; i< nent; i++)
	{
		data->GetEntry(i);
		if(i==0) a=eventID;

		if(eventID==a)
		{
			if(volumeID==inf_vol)
			{
				b=b+edep;
				inf=inf+volumeID;
			}

			else if(volumeID>0&&inf_vol>0)
			{
				if((volumeID/10)%5==0&&(inf_vol/10)%5==0)
				{
					b=b+edep;
				inf=inf+volumeID;

				}
				else if((volumeID/10)%6==0&&(inf_vol/10)%6==0)
				{
					b=b+edep;
				inf=inf+volumeID;
				}
				else if((volumeID/10)%7==0&&(inf_vol/10)%7==0)
				{
					b=b+edep;
				inf=inf+volumeID;
				}
			}
			else if(volumeID<0&&inf_vol<0)
			{
				if((volumeID/10)%5==0&&(inf_vol/10)%5==0)
				{
					b=b+edep;
				inf=inf+volumeID;
				}       
				else if((volumeID/10)%6==0&&(inf_vol/10)%6==0)
				{
					b=b+edep;
				inf=inf+volumeID;
				}       
				else if((volumeID/10)%7==0&&(inf_vol/10)%7==0)
				{
					b=b+edep;
				inf=inf+volumeID;
				}       
			}       
		}	
		else
		{ 
			if(b>80)
			{
				s=b*(exp(3.61114-0.0715599*b)-0.0018171*b+5.28785)/235.5;
				c=gRandom -> Gaus(b,s);
				hist_24det->Fill(c);

			}
			b=edep;
			//inf_vol=volumeID;
			inf=volumeID;
		}
			inf_vol=volumeID;
		a=eventID;
	}
//-------------------------------------------	




	
//-------------------------------------------	
	for(int l=0;l<nent;l++)
	{
		data->GetEntry(l);
		//cout << volumeID<< endl;
		if(l==0) a=eventID;

		if(eventID==a)
		{   
			//for(int i=1;i<5;i++)
			{
				//	for(int j=5;j<8;j++)
				{
					//		for(int k=0;k<2;k++)
					{

						//if(volumeID==10*i*j*(2*k-1))
						if(volumeID==inf_vol)
						{
							b=b+edep;
							//cout<< volumeID << " " <<b<<endl;
						}
						else
						{
							if(b>80)
							{
								s=b*(exp(3.61114-0.0715599*b)-0.0018171*b+5.28785)/235.5;
								c=gRandom -> Gaus(b,s);
								hist_onedet->Fill(c);

							}
							b=edep;
						}

					}
				}
			}
		}
		else
		{
			if(b>80)
			{
				s=b*(exp(3.61114-0.0715599*b)-0.0018171*b+5.28785)/235.5;
				c=gRandom -> Gaus(b,s);
				hist_onedet->Fill(c);

			}
			b=edep;
		}
		a=eventID; 
		inf_vol=volumeID;
	}

//--------------------------------------------------------
	hist_onedet->Draw();
//	hist_24det->Draw("same");
	hist_24det->SetLineColor(2);        

	TGraph *graph_ab = new TGraph();
	TGraph *graph = new TGraph();

	for (Int_t i = 0; i < 10; i++)
	{
		ergeff_ab[i] = 100*(hist_24det->GetBinContent(i*100+100)+hist_24det->GetBinContent(i*100+101))/(nevt/12);
		graph_ab->SetPoint(i, 100*i+100, ergeff_ab[i]);
	}
	for (Int_t i = 3; i < 5; i++)
	{
		ergeff_ab[i+7] = 100*(hist_24det->GetBinContent(i*500)+hist_24det->GetBinContent(i*500+1))/(nevt/12);
		graph_ab->SetPoint(i+7, 500*i, ergeff_ab[i+7]);
	}


	for (Int_t i = 0; i < 10; i++)
	{       
		ergeff[i] = 100*(hist_onedet->GetBinContent(i*100+100)+hist_onedet->GetBinContent(i*100+101))/(nevt/12);
		graph->SetPoint(i, 100*i+100, ergeff[i]);
	}
	for (Int_t i = 3; i < 5; i++)
	{       
		ergeff[i+7] = 100*(hist_onedet->GetBinContent(i*500)+hist_onedet->GetBinContent(i*500+1))/(nevt/12);
		graph->SetPoint(i+7, 500*i, ergeff[i+7]);
	}


	TCanvas* cvs = new TCanvas("cvs", "", 700, 500);
	hist_eff->Draw();
	graph_ab->Draw("P");
	graph->Draw("P");
	graph_ab->SetMarkerStyle(20);
	graph_ab->SetMarkerColor(2);
	graph->SetMarkerColor();
	graph->SetMarkerStyle(20);

	file1->cd();
	hist_24det->Write(); 
	hist_onedet->Write(); 
	file1->Close();	

}
