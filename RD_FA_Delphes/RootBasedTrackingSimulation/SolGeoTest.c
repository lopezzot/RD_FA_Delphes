#include <TMath.h>
#include <TGraph.h>
#include <TAxis.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <iostream>
#include "SolGeom.h"
#include "SolTrack.h"

//
void SolGeoTest()
{
	//
	//	Init geometry
	//
	SolGeom *G;		// Init geometry
	const Int_t nDet = 9;
	Bool_t OK[nDet] = {		// Enable selected parts of the detector 
		1,					// Beam pipe
		1,					// Inner VTX pixel layers
		1,					// Outer VTX layers
		1,					// Drift chamber
		1,					// Barrel Si wrapper
		1,					// Barrel pre-shower
		1,					// Forw. VTX pixel layers
		1,					// Forw. Si wrapper
		1 };					// Forw. pre-shower
	G = new SolGeom(OK);
	G->Draw();
	TCanvas *cc = G->cnv();
	//
	// Draw track on top of geometry display
	//
	Double_t x[3] = { 0.0, 0.0, 0.0 };		// Track starting point
	Double_t p[3] = { 5., 0.0, 10. };		// Track momentum
	SolTrack *trk = new 	SolTrack(x, p, G);	// Initialize track
	Double_t *zh = new Double_t[G->Nl()];	// z of hit array
	Double_t *rh = new Double_t[G->Nl()];	// R of hit array
	Int_t k = 0;
	for (Int_t i = 0; i < G->Nl(); i++)		// Loop on all layers
	{
		Double_t R; Double_t phi; Double_t z;
		if (trk->HitLayer(i,R,phi,z))		// if layer is hit return location
		{
			zh[k] = z; 
			rh[k] = R;
			k++;
		}
	}
	TGraph *gr = new TGraph(k, zh, rh);		// graph intersection with layers
	gr->SetMarkerStyle(kCircle);
	gr->SetMarkerColor(kMagenta);
	gr->SetMarkerSize(1);
	gr->SetLineColor(kMagenta);
	gr->Draw("PLSAME");						// plot track
	cout << "x = " << x[0] << " ,  " << x[1] << " ,  " << x[2] << endl;
	cout << "p = " << p[0] << " ,  " << p[1] << " ,  " << p[2] << endl;
	cout << "Calculated parameters:" << endl;
	Double_t D    = trk->D();
	Double_t phi0 = trk->phi0();
	Double_t C    = trk->C();
	Double_t z0   = trk->z0();
	Double_t ct   = trk->ct();
	cout << "D = " << D << " , phi0 =  " << phi0 << " , C =  " << C 
		 << " , z0 = " << z0 << " , ct =  " << ct << endl;
	cout << "Reverse now" << endl;
	SolTrack *krt = new SolTrack(D, phi0, C, z0, ct, G);
	x[0] = krt->x();
	x[1] = krt->y();
	x[2] = krt->z();
	p[0] = krt->px();
	p[1] = krt->py();
	p[2] = krt->pz();
	cout << "x = " << x[0] << " ,  " << x[1] << " ,  " << x[2] << endl;
	cout << "p = " << p[0] << " ,  " << p[1] << " ,  " << p[2] << endl;
	cout << endl;
	cout << "And again:" << endl;
	SolTrack *trk1 = new 	SolTrack(x, p, G);
	cout << "Calculated parameters:" << endl;
	Double_t D1    = trk1->D();
	Double_t phi01 = trk1->phi0();
	Double_t C1    = trk1->C();
	Double_t z01   = trk1->z0();
	Double_t ct1   = trk1->ct();
	cout << "D = " << D1 << " , phi0 =  " << phi01 << " , C =  " << C1
		<< " , z0 = " << z01 << " , ct =  " << ct1 << endl;
	//
	// resolution vs pt and theta
	//
	TCanvas *resol = new TCanvas("resol", "Resolutions", 100, 100, 500, 500);
	resol->Divide(2, 2);
	const Int_t Nth = 3;			// NUmber of angles
	TGraph *grpt[Nth];			// pt resolution graphs
	TGraph *grd0[Nth];			// D resolution graphs
	TGraph *grz0[Nth];			// z0 resolution graphs
	TGraph *grct[Nth];			// cot(theta) resolution
	Double_t theta[Nth] = {45., 60., 90.};	// angles
	Int_t cl[Nth] = { kGreen, kBlue, kRed };
	Double_t Npt = 100;			// Nr. of points per graph
	Double_t * pt = new Double_t[Npt];
	Double_t *spt = new Double_t[Npt];
	Double_t *sd0 = new Double_t[Npt];
	Double_t *sz0 = new Double_t[Npt];
	Double_t *sct = new Double_t[Npt];
	Double_t ptmin = 0;
	Double_t ptmax = 100;
	Double_t pts = (ptmax - ptmin) / (Double_t)Npt;
	for (Int_t i = 0; i < Nth; i++)	// Loop on angles
	{
		Double_t th = TMath::Pi()*theta[i] / 180.;
		cout << "Th = " << th << endl;
		for (Int_t k = 0; k < Npt; k++)	// Loop on pt
		{
			x[0] = 0; x[1] = 0; x[2] = 0;	// Set origin
			pt[k] = (k + 1)*pts;				// Set momentum
			p[0] = pt[k]; p[1] = 0;	p[2] = pt[k] / TMath::Tan(th);
			SolTrack *tr = new 	SolTrack(x, p, G); // Initialize track
			tr->CovCalc();			// Calculate covariance
			spt[k] = pt[k]*tr->s_C() / (0.2998*G->B()); // Store resolutions
			sd0[k] = tr->s_D();
			sz0[k] = tr->s_z0();
			sct[k] = tr->s_ct();
		}
		//
		//for (Int_t j = 0; j < Npt; j++)cout << "pt-sig: " << pt[j] << ", " << sd0[j] << endl;
		// pt
		resol->cd(1);
		grpt[i] = new TGraph(Npt, pt, spt);
		grpt[i]->SetMarkerStyle(kCircle);
		grpt[i]->SetMarkerColor(kBlue);
		grpt[i]->SetMarkerSize(1);
		grpt[i]->SetLineColor(cl[i]);
		if (i == 0)
		{
			grpt[i]->SetTitle("#sigma_{pt}/pt");
			grpt[i]->SetMinimum(0.0);
			grpt[i]->Draw("AL");
		}
		else grpt[i]->Draw("L SAME");
		// d0
		resol->cd(2);
		grd0[i] = new TGraph(Npt, pt, sd0);
		grd0[i]->SetMarkerStyle(kCircle);
		grd0[i]->SetMarkerColor(kBlue);
		grd0[i]->SetMarkerSize(1);
		grd0[i]->SetLineColor(cl[i]);
		if (i == 0)
		{
			grd0[i]->SetTitle("#sigma_{D_{0}}");
			grd0[i]->SetMinimum(1.0e-6);
			grd0[i]->Draw("AL");
		}
		else grd0[i]->Draw("L SAME");
		// z0
		resol->cd(3);
		grz0[i] = new TGraph(Npt, pt, sz0);
		grz0[i]->SetMarkerStyle(kCircle);
		grz0[i]->SetMarkerColor(kBlue);
		grz0[i]->SetMarkerSize(1);
		grz0[i]->SetLineColor(cl[i]);
		if (i == 0)
		{
			grz0[i]->SetTitle("#sigma_{z_{0}}");
			grz0[i]->SetMinimum(1.0e-6);
			grz0[i]->Draw("AL");
		}
		else grz0[i]->Draw("L SAME");
		// ct
		resol->cd(4);
		grct[i] = new TGraph(Npt, pt, sct);
		grct[i]->SetMarkerStyle(kCircle);
		grct[i]->SetMarkerColor(kBlue);
		grct[i]->SetMarkerSize(1);
		grct[i]->SetLineColor(cl[i]);
		if (i == 0)
		{
			grct[i]->SetTitle("#sigma_{cot(#theta)}");
			grct[i]->SetMinimum(0.0);
			//grct[i]->SetMaximum(1.0e-4);
			grct[i]->Draw("AL");
		}
		else grct[i]->Draw("L SAME");
	}
}