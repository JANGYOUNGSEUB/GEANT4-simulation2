#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;


void qdc_caen(){

TFile *file = new TFile("Co60_att_run01.root","read");
TTree *tree = (TTree *)file -> Get("wavedata");

Long64_t nent = tree->GetEntries();
UInt_t NHitCh;
tree->SetBranchAddress("NHitCh",&NHitCh);
float QDC[2];
UInt_t Channel[2];

tree->SetBranchAddress("QDC",&QDC);
tree->SetBranchAddress("Channel",&Channel);

TH1D *hist_QDC=new TH1D("","",5000,0,500000);

for(int i=0;i<nent;i++)
{
	tree->GetEntry(i);
	//cout <<Channel[NHitCh]<<endl;
	//cout <<Channel[0]<<" "<<QDC[0]<<endl;

	if(Channel[0]==0)
	{
		hist_QDC->Fill(QDC[0]);
	}
/*
	{
		if(NHitCh==2)
		{
			hist_QDC->Fill(QDC[0]);
			hist_QDC->Fill(QDC[1]);
		}
		else
		{
			hist_QDC->Fill(QDC[0]);

		}
	}
	*/
}

hist_QDC->Draw();


}

