#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;


void coin(){

        TFile *file = new TFile("data.root","read");
        TTree *data = (TTree *)file -> Get("data");

	int nent = data->GetEntries();
        int eventID;
        int volumeID;
        Double_t edep;

	data->SetBranchAddress("eventID",&eventID);
        data->SetBranchAddress("volumeID",&volumeID);
        data->SetBranchAddress("edep",&edep);

        TH1D *hist_edep = new TH1D("hist_edep","deposited energy;keV;counts",1000,0,3000);
        TH1D *hist_edep1 = new TH1D("hist_edep1","deposited energy;keV;counts",1000,0,3000);
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
			if(volumeID==100)
			{
				b=b+edep;
				v=volumeID;
			}	
			else if(volumeID==200)
			{
				b1=b1+edep;
				v1=volumeID;
			}
		}
		else
		{
				if(b>80&&b1>80&&v>0&&v1>0)
					{
						s=b*(exp(2.28852-0.00800046*b)-0.00171403*b+4.7685)/234.582;
                                                c=gRandom -> Gaus(b,s);
                                                hist_edep ->Fill(c);	
						s1=b1*(exp(2.23296-0.00737*b1)-0.00144274*b1+4.35266)/234.582;
                                                c1=gRandom -> Gaus(b1,s1);
                                                //hist_edep1 ->Fill(c1);
						//hist_coin->Fill(c,c1);
					
					}
				if(volumeID==200)
                                        {b1=edep;b=0;v1=volumeID;v=0;}
				else if(volumeID==100)
                                        {b=edep;b1=0;v=volumeID;v1=0;}
				else
					{b=0;b1=0;v=0;v1=0;}
		}
		//else continue;
		a=eventID;
	}

	TFile *file1 = new TFile("dataLa.root","read");
	TTree *data1 = (TTree *)file1 ->Get("data");

	int nent1 = data1->GetEntries();
        int eventID1;
        int volumeID1;
        Double_t edep1;

	data1->SetBranchAddress("eventID",&eventID1);
        data1->SetBranchAddress("volumeID",&volumeID1);
        data1->SetBranchAddress("edep",&edep1);

	
	for(int i=0; i<nent1;i++)
	{
                data1->GetEntry(i);
                if(i==0) a=eventID1;

                if(eventID1==a)
                {
                        if(volumeID1==100)
                        {
                                b=b+edep1;
                                v=volumeID1;
                        }
                        else if(volumeID1==200)
                        {
                                b1=b1+edep1;
                                v1=volumeID1;
                        }
                }
                else
                {
                                if(b>80&&b1>80&&v>0&&v1>0)
                                        {
                                                s=b*(exp(2.28852-0.00800046*b)-0.00171403*b+4.7685)/234.582;
                                                c=gRandom -> Gaus(b,s);
                                                hist_edep1 ->Fill(c);
                                                s1=b1*(exp(2.23296-0.00737*b1)-0.00144274*b1+4.35266)/234.582;
                                                c1=gRandom -> Gaus(b1,s1);
						//cout << edep1<< " "<<b << endl;
					}
				if(volumeID1==200)
                                        {b1=edep;b=0;v1=volumeID1;v=0;}
                                else if(volumeID1==100)
                                        {b=edep;b1=0;v=volumeID1;v1=0;}
                                else
                                        {b=0;b1=0;v=0;v1=0;}
                }
	
		a=eventID1;
	}



	
	/*Int_t colors[] = {0, 1, 2, 3, 4, 5, 6};
	gStyle->SetPalette((sizeof(colors)/sizeof(Int_t)), colors);
	Double_t levels[] = {-1.79e38, 1.17e-38, 0.90, 0.95, 1.00, 1.05, 1.10, 1.79e38};
	hist_coin->SetContour((sizeof(levels)/sizeof(Double_t)), levels);  
*/
	
        TH1D *hist_edeptot = new TH1D("hist_edeptot","deposited energy;keV;counts",1000,0,3000);
	*hist_edeptot = *hist_edep+*hist_edep1;
	TCanvas *cvs=new TCanvas("cvs","",900,900);
	cvs->Divide(2,2);
	cvs->cd(1);
	hist_edep->Draw();
	//cvs->cd(2);
	hist_edep1->SetLineColor(2);
	hist_edep1->Draw("same");
	cvs->cd(2);
	hist_edeptot->Draw();
	//cvs->cd(3);
	//hist_coin->Draw("colz");
}
