void qdch(){

        TFile *file = new TFile("Cs137_pmt1_1400_pmt2_1310_th50_0001.root","read");
        TTree *tree = (TTree *)file -> Get("tree");
	TFile *file1 = new TFile("hist_Cs_exp.root","recreate");
	gStyle->SetOptStat(0);
        int waveform_length=240;
        int waveform[waveform_length];
        int waveformtime[waveform_length];
	int cid;
        ULong64_t event_number;
        ULong64_t trig_num;
        Long64_t entrynum =tree ->GetEntries();
        Long64_t eventmax =tree ->GetMaximum("event_number");
	Double_t count_qdc;
	//tree1 -> Branch("count_qdc",&count_qdc);


        tree ->SetBranchAddress("waveform",&waveform);
        tree ->SetBranchAddress("waveformtime",&waveformtime);
        tree ->SetBranchAddress("event_number",&event_number);
        tree ->SetBranchAddress("trig_num",&trig_num);
        tree ->SetBranchAddress("waveform_length",&waveform_length);
	tree ->SetBranchAddress("cid",&cid);	

        TH1D *hist_QDC = new TH1D("QDC","QDC;QDC;Counts",2500,0,2500);
	TH1D *hist_pedestal = new TH1D("pedestal","pedestal_C1",4096,0,4095);
	TH1D *hist_pulseh = new TH1D("pulseh","pulse_height_C1",4096,0,4095);        
	TH1D *hist_pedestal_dif = new TH1D("pedestal_dif","pedestal_dif",200,0,15);	
        TH1D *hist_QDC2 = new TH1D("QDC2","QDC_C2",10000,0,50000);
	TH1D *hist_pedestal2 = new TH1D("pedestal2","pedestal_C2",4096,0,4095);
	TH1D *hist_pulseh2 = new TH1D("pulseh2","pulse_height_C2",4096,0,4095);        
	TH1D *hist_pedestal_dif2 = new TH1D("pedestal_dif2","pedestal_dif2",200,0,15);	
	


	int a,b,c,d,e,f,g,h;
	int min=waveform[0];
	int min2=waveform[0];

		for(int i = 0; i < entrynum; i++)
                {

                        tree->GetEntry(i);
        //                cout <<i<<" "<< trig_num<<" "<<cid<<endl;
			e=0;
                        f=0;
                        g=0;
                        h=0;
                        min2=waveform[0];
                        for(int j = 0; j < 20; j++)
                        {
                                e=e+waveform[j];
                        }
                        for(int j = 220; j <240; j++)
                        {
                                g=g+waveform[j];
                        }

                        for(int k = 0; k < waveform_length ; k++)
                        {
                                f=f+e/20-waveform[k];

                        }
                        for(int k = 20; k <150; k++)
                        {
                                if( waveform[k] < min2)
                                {
                                        min2=waveform[k];
                                }
                        }
                 	if(cid==2){

				hist_QDC2 -> Fill(f/20);
				hist_pedestal2 -> Fill(e/20);
				hist_pulseh2 -> Fill(e/20-min2);
				hist_pedestal_dif2 -> Fill(e/20-g/20);
			}
                	else{
				hist_QDC -> Fill(0.0420074*f+5.1222);
                                //count_qdc=f;
				//tree1->Fill();
				
				hist_pedestal -> Fill(e/20);
                                hist_pulseh -> Fill(e/20-min2);
                                hist_pedestal_dif -> Fill(e/20-g/20);	

			}
		}
//	cout << waveform[1] << endl;
//	TCanvas* cvs1 = new TCanvas("cvs1","",2000,1000);
//	cvs1->Divide(4,2);
//	cvs1->cd(1);	
//	hist_pedestal->Draw();
//	cvs1->cd(2);
//	hist_pulseh->Draw();
//	cvs1->cd(3);
//	hist_QDC->Draw();
//	cvs1->cd(4);
//	hist_pedestal_dif->Draw();
//      cvs1->cd(5);
//      hist_pedestal2->Draw();
//      cvs1->cd(6);
//      hist_pulseh2->Draw();
//      cvs1->cd(7);
//      hist_QDC2->Draw();
//      cvs1->cd(8);
//      hist_pedestal_dif2->Draw();

//	tree1->Write();
//	file1->Close();

//	여기부터 fitting


/*

	TCanvas *cvs2=new TCanvas("cvs2","",800,600);
	//cvs2->Divide(2,1);
	TF1* ftn = new TF1("ftn","gaus(0)+gaus(3)+expo(6)+[8]*x+[9]",27000,34000);
	TF1* gaus1 = new TF1("gaus1","gaus(0)",27000, 34000);
	TF1* gaus2 = new TF1("gaus2","gaus(0)",27000, 34000);
	TF1* exp = new TF1("exp","expo(0)",27000, 34000);
	TF1* lin = new TF1("lin","[0]*x+[1]",27000,34000);
	//ftn->SetParameters(600,28300,100,500,32000,100,15,0);
	ftn->SetParLimits(3,100,1000);
	ftn->SetParLimits(4,30000,33000);
	ftn->SetParLimits(0,100,1000);	
	ftn->SetParLimits(1,28000,29000);	

	//cvs2->cd(1);
	//cvs2->cd(2);
	hist_QDC->Fit(ftn,"M","",27000,36000);
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

hist_QDC->Draw();
//file1->cd();
//hist_QDC->Write();
//file1->Close();

}
