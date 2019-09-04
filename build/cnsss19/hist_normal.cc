#include "TFile.h"
#include "TH1D.h"
#include "TTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;


void hist_normal(){

	TFile *file1 = new TFile("hist_Co_6cluster.root","read");
	TTree *tree1 = (TTree *)file1-> Get("tree1");
	//TFile *file1 = new TFile("hist_g4.root","recreate");
        //TTree *tree1 = new TTree("tree1","tree1");	

	int nent1= tree1->GetEntries();
cout << nent1 << endl;
	Double_t hist_g4;
	Double_t hist_ab_g4;


	tree1->SetBranchAddress("hist_g4",&hist_g4);

	TH1D *hist_edep = new TH1D("hist_edep","deposited energy;keV;count",2500,0,2500);
	TH1D *hist_edep1 = new TH1D("hist_edep","deposited energy;keV;count",2500,0,2500);
	
	
	
	
	
	for(int i =0; i< nent1; i++)
	{
		tree1->GetEntry(i);
		hist_edep1->Fill(hist_g4);
	}
	file1->Close();

	TFile *file2 = new TFile("hist_Co_6cluster_ab.root","read");
	TTree *tree2 = (TTree *)file2-> Get("tree2");
	int nent2 = tree2->GetEntries();
	tree2->SetBranchAddress("hist_ab_g4",&hist_ab_g4);
	for(int i =0; i< nent2; i++)
	{
		tree2->GetEntry(i);
		hist_edep1->Fill(hist_ab_g4);
	}
	
	/*TCanvas *cvs2=new TCanvas("cvs2","",800,600);
	TF1* ftn = new TF1("ftn","gaus(0)+gaus(3)+expo(6)+[8]*x+[9]",1100,1400);
        TF1* gaus1 = new TF1("gaus1","gaus(0)",1130, 1200);
        TF1* gaus2 = new TF1("gaus2","gaus(0)",1270, 1370);
        TF1* exp = new TF1("exp","expo(0)",1100, 1220);
        TF1* lin = new TF1("lin","[0]*x+[1]",1100,34000);

	ftn->SetParLimits(3,100,4000);
        ftn->SetParLimits(4,1300,1350);
        ftn->SetParLimits(0,100,4000);
        ftn->SetParLimits(1,1150,1200);

	hist_edep->Fit(ftn,"M","",1100,1400);
        gaus1->SetParameters(ftn->GetParameter(0), ftn->GetParameter(1), ftn->GetParameter(2));
        gaus2->SetParameters(ftn->GetParameter(3), ftn->GetParameter(4), ftn->GetParameter(5));
        exp->SetParameters(ftn->GetParameter(6), ftn->GetParameter(7));
        lin->SetParameters(ftn->GetParameter(8), ftn->GetParameter(9));
        gaus1->Draw("same");
        gaus2->Draw("same");
        exp->Draw("same");
        lin->Draw("same");
	
	gaus1->SetLineColor(4);
        gaus2->SetLineColor(1);
        exp->SetLineColor(3);
        lin->SetLineColor(5);
	*/
	
	

	//hist_edep1->Fill(TRandom::Gaus(662,1));
	//hist_edep1->Draw();
	hist_edep->Draw();        
	hist_edep1->Draw("same");        
	hist_edep1->SetLineColor(2);	
	//TF1* ftn = new TF1("ftn","gaus(0)",600,700);
	//ftn -> SetParLimits(1,650,670);
	//hist_edep->Fit(ftn,"M","",600,700);

	//tree1->Write();
        //file1->Close();		



}
