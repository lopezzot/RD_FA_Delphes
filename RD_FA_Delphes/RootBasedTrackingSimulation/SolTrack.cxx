
#include "SolGeom.h"
#include "SolTrack.h"
#include <TMath.h>
#include <TMatrixD.h>
#include <TMatrixDSym.h>
#include  <iostream>
//
// Constructors
SolTrack::SolTrack(Double_t *x, Double_t *p, SolGeom *G)
{
	fG = G;
	// Store momentum
	fp[0] = p[0]; fp[1] = p[1]; fp[2] = p[2];
	Double_t px = p[0]; Double_t py = p[1]; Double_t pz = p[2];
	fx[0] = x[0]; fx[1] = x[1]; fx[2] = x[2];
	Double_t xx = x[0]; Double_t yy = x[1]; Double_t zz = x[2];
	// Store parameters
	Double_t pt = TMath::Sqrt(px*px + py*py);
	Double_t Charge = 1.0;						// Don't worry about charge for now
	Double_t a = -Charge*G->B()*0.2998;			// Normalized speed of light	
	Double_t C = a / (2 * pt);					// pt in GeV, B in Tesla, C in meters
	Double_t r2 = xx*xx + yy*yy;
	Double_t cross = xx*py - yy*px;
	Double_t T = TMath::Sqrt(pt*pt - 2 * a*cross + a*a*r2);
	Double_t phi0 = TMath::ATan2((py - a*xx) / T, (px + a*yy) / T);
	Double_t D;
	if (pt < 10.0) D = (T - pt) / a;
	else D = (-2 * cross + a*r2) / (T + pt);
	Double_t B = C*TMath::Sqrt((r2 - D*D) / (1 + 2 * C*D));
	Double_t st = TMath::ASin(B) / C;
	Double_t ct = pz / pt;
	Double_t z0 = zz - ct*st;
	fpar[0] = D;
	fpar[1] = phi0;
	fpar[2] = C;
	fpar[3] = z0;
	fpar[4] = ct;
	//cout<<"SolTrack: Done setting parameters"<<endl;
	//
	// Init covariances
	//
	fCov.ResizeTo(5, 5);
}
//
SolTrack::SolTrack(Double_t D, Double_t phi0, Double_t C, Double_t z0, Double_t ct, SolGeom *G)
{
	fG = G;
	// Store parameters
	fpar[0] = D;
	fpar[1] = phi0;
	fpar[2] = C;
	fpar[3] = z0;
	fpar[4] = ct;
	// Store momentum
	Double_t pt = G->B()*0.2998 / TMath::Abs(2 * C);
	Double_t px = pt*TMath::Cos(phi0);
	Double_t py = pt*TMath::Sin(phi0);
	Double_t pz = pt*ct;
	//
	fp[0] = px; fp[1] = py; fp[2] = pz;
	fx[0] = -D*TMath::Sin(phi0); fx[1] = D*TMath::Cos(phi0);  fx[2] = z0;
	//
	// Init covariances
	//
	fCov.ResizeTo(5, 5);
}
// Destructor
SolTrack::~SolTrack()
{
	delete[] & fp;
	delete[] & fpar;
	fCov.Clear();
}
//
Bool_t SolTrack::HitLayer(Int_t il, Double_t &R, Double_t &phi, Double_t &zz)
{
	Double_t Di = D();
	Double_t phi0i = phi0();
	Double_t Ci = C();
	Double_t z0i = z0();
	Double_t cti = ct();
	//
	R = 0; phi = 0; zz = 0;
	//
	Bool_t val = kFALSE;
	if (fG->lTyp(il) == 1)			// Cylinder: layer at constant R
	{
		R = fG->lPos(il);
		Double_t arg = (Ci*R + (1 + Ci*Di)*Di / R) / (1. + 2.*Ci*Di);
		if (TMath::Abs(arg) < 1.0)
		{
			zz = z0i + cti*TMath::ASin(Ci*TMath::Sqrt((R*R - Di*Di) / (1. + 2.*Ci*Di))) / Ci;
			if (zz > fG->lxMin(il) && zz < fG->lxMax(il))
			{
				phi = phi0i + TMath::ASin(arg);
				val = kTRUE;
			}
		}
	}
	else if (fG->lTyp(il) == 2)		// disk: layer at constant z
	{
		zz = fG->lPos(il);
		Double_t arg = Ci*(zz - z0i) / cti;
		if (TMath::Abs(arg) < 1.0 && (zz - z()) / cti > 0)
			R = TMath::Sqrt(Di*Di + (1. + 2.*Ci*Di)*pow(TMath::ASin(arg), 2) / (Ci*Ci));
		if (R > fG->lxMin(il) && R < fG->lxMax(il))
		{
			Double_t arg1 = (Ci*R + (1 + Ci*Di)*Di / R) / (1. + 2.*Ci*Di);
			if (TMath::Abs(arg1) < 1.0)
			{
				phi = phi0i + TMath::ASin(arg1);
				val = kTRUE;
			}
		}
	}
	//
	return val;
}
//
void SolTrack::CovCalc()
{
	//
	// Fill list of layers hit
	//
	Int_t Nlay = fG->Nl();				// Use only barrel layers for now
	Double_t *zhh = new Double_t[2*Nlay];	// z of hit
	Double_t *rhh = new Double_t[2*Nlay];	// r of hit
	Double_t *dhh = new Double_t[2*Nlay];	// distance of hit from origin
	Int_t    *ihh = new Int_t[2*Nlay];		// true index of layer
	Int_t    *mhh = new Int_t[2*Nlay];		// measurement layer side (0: inert, 1: upper, 2: lower)
	Int_t kh = 0;		// Number of layers hit (double measurements count twice)
	Int_t kmh = 0;		// Number of measurement layers hit (double measurements count twice)
	for (Int_t i = 0; i < Nlay; i++)
	{
		Double_t R; Double_t phi; Double_t zz;
		if (HitLayer(i, R, phi, zz)) // Only barrel type layers
		{
			zhh[kh] = zz;
			rhh[kh] = R;
			dhh[kh] = TMath::Sqrt(R*R + zz*zz);
			ihh[kh] = i;
			mhh[kh] = 0;
			kh++;
			if (fG->isMeasure(i))
			{
				mhh[kh - 1] = 1;
				kmh++;
				if (fG->lND(i) == 2)	// Treat as additional layer
				{
					zhh[kh] = zz;
					rhh[kh] = R;
					dhh[kh] = TMath::Sqrt(R*R + zz*zz);
					ihh[kh] = i;
					mhh[kh] = 2;
					kh++;
					kmh++;
				}
				//cout << "lay: " << kh << ", mlay: " << kmh
				//	<< ", R: " << R << ", z: " << zz << ", d: " << dh[kh-1] << endl;
			}
		}
	}
	// Repack
	Int_t    *hord = new Int_t[kh];	// hit order by distance from origin
	Double_t *zh = new Double_t[kh];	// z of hit
	Double_t *rh = new Double_t[kh];	// r of hit
	Double_t *dh = new Double_t[kh];	// distance of hit from origin
	Int_t    *ih = new Int_t[kh];	// true index of layer
	Int_t    *mh = new Int_t[kh];	// measurement layer side (0: inert, 1: upper, 2: lower)
	for (Int_t h = 0; h < kh; h++)
	{
		zh[h] = zhh[h]; rh[h] = rhh[h]; dh[h] = dhh[h]; ih[h] = ihh[h]; mh[h] = mhh[h];
	}
	TMath::Sort(kh, dh, hord, kFALSE); // Order by increasing distance from origin
	//for (Int_t ip = 0; ip < 10; ip++) cout << "hord[" << ip << "] =" << hord[ip] << endl;
	//
	// Fill measurement covariance S
	//
	//cout<<"Nlay = "<<Nlay<<", Nr. measurements: "<<Nm<<endl;
	TMatrixDSym Sm(kmh);	// Measurement covariance
	TMatrixD Rm(kmh, 5);	// Derivative matrix
	Int_t im = 0;
	for (Int_t ii = 0; ii < kh; ii++)
	{
		Int_t il = hord[ii];					// Hit layer numbering
		Int_t i = ih[il];					// True layer number
		if (fG->isMeasure(i))
		{
			Double_t str = 0;
			Double_t sig = 0;
			Int_t    typ = fG->lTyp(i);		// Barrel or Z
			if (mh[il] == 1)
			{
				str = fG->lStU(i);			// Stereo upper layer
				sig = fG->lSgU(i);			// Layer resolution
			}
			else if (mh[il] == 2)
			{
				str = fG->lStL(i);			// Stereo lower layer
				sig = fG->lSgL(i);			// Layer resolution
			}
			if (typ == 1)		// Barrel type layer
			{
				Rm(im, 0) = TMath::Cos(str);			// D derivative
				Rm(im, 1) = TMath::Cos(str)*rh[il];	// phi0 derivative
				Rm(im, 2) = TMath::Cos(str)*rh[il] * TMath::Cos(str)*rh[il];	// C derivative
				Rm(im, 3) = -TMath::Sin(str);		// z0 derivative
				Rm(im, 4) = -TMath::Sin(str)*rh[il];	// cot(theta) derivative
			}
			else if (typ == 2)	// Z type layer
			{
				if (mh[il] == 1)		// Upper layer is R-phi
				{
					Rm(im, 0) = 1.0;					// D derivative
					Rm(im, 1) = rh[il];				// phi0 derivative
					Rm(im, 2) = rh[il] * rh[il];		// C derivative
					Rm(im, 3) = -(phi0() + 2 * rh[il] * C()) / ct();		// z0 derivative
					Rm(im, 4) = -(phi0() + 2 * rh[il] * C())*(zh[il]-z0())/(ct()*ct());	// cot(theta) derivative
				}
				else if (mh[il] == 2) // Lower layer is R
				{
					Rm(im, 0) = D() / rh[il];				// D derivative
					Rm(im, 1) = 0;							// phi0 derivative
					Rm(im, 2) = 0;							// C derivative
					Rm(im, 3) = -1.0 / ct();					// z0 derivative
					Rm(im, 4) = -(zh[il]-z0()) / (ct()*ct());		// cot(theta) derivative
				}
			}
			//cout << "i: " << i << ", str: " << str << ", sig: " << sig << ", r: " << rh[i] << endl;
			//
			Int_t km = 0;
			for (Int_t kk = 0; kk <= ii; kk++)
			{
				Int_t kl = hord[kk];
				Int_t k = ih[kl];
				//cout << "Start of loop k = " << k << endl;
				if (fG->isMeasure(k))
				{
					Double_t strz = 0;
					if      (mh[kl] == 1) strz = fG->lStU(k);			// Stereo upper layer
					else if (mh[kl] == 2) strz = fG->lStL(k);			// Stereo lower layer
					//
					Sm(im, km) = 0;
					if (im == km) Sm(im, km) += sig*sig;	// Detector resolution on diagonal
					//
					if (TMath::Abs(str - strz) > 1.0) Sm(im, km) = 0;	// No correlation for orthogonal measurements
					else
					{
						for (Int_t jj = 0; jj < kk; jj++)					// Loop on all layers below for MS contribution
						{
							Int_t jl = hord[jj];
							Int_t j = ih[jl];
							if (mh[jl] < 2)							// avoid double counting
							{
								Double_t sn2t = 1.0 / (1 + ct()*ct());			//sin^2 theta of track
								Double_t cs2t = 1.0 - sn2t;						//cos^2 theta
								Double_t snt = TMath::Sqrt(sn2t);				// sin theta
								Double_t cst = TMath::Sqrt(cs2t);				// cos theta
								Double_t corr = snt;								// default is barrel
								if (fG->lTyp(j) == 2) corr = cst;				// this is Z layer
								Double_t p = TMath::Sqrt(px()*px() + py()*py() + pz()*pz());	// momentum
								Double_t Rlf = fG->lTh(j) / (corr*fG->lX0(j));	// Rad. length fraction
								Double_t tmsp = 0.0136*TMath::Sqrt(Rlf) / p;		// MS angle R-phi
								Double_t tmsz = tmsp / snt;						// MS angle R-z
								Double_t tms = tmsp;								// Select which angle to use
								if (TMath::Abs(str) > 1.0) tms = tmsz;
								Double_t Rj = rh[jl]; Double_t Ri = rh[il]; Double_t Rk = rh[kl];
								Sm(im, km) += (Ri - Rj)*(Rk - Rj)*tms*tms / sn2t;	// Ms contribution R-phi
							}
						}
					}
					//
					Sm(km, im) = Sm(im, km);
					km++;
					//cout << "km increased to " << km << endl;
				}
			}
			im++;
			//cout << "im increased to " << im << endl;
		}
	}
	//
	// Calculate transverse covariance
	//cout << "Sm = " << endl; Sm.Print();
	/*
	for (Int_t l1 = 0; l1 < 8; l1++)
	{
	for (Int_t l2 = 0; l2 < 8; l2++)
	cout << Sm(l1, l2) << ", ";
	cout << endl;
	}
	*/
	TMatrixDSym DSm(kmh); DSm.Zero();
	for (Int_t id = 0; id < kmh; id++) DSm(id, id) = TMath::Sqrt(Sm(id, id));
	TMatrixDSym DSmInv = DSm;
	DSmInv.Invert();
	TMatrixDSym SmN = Sm.Similarity(DSmInv);
	// Calculate transverse covariance
	//cout << "SmN = " << endl; SmN.Print();
	/*
	for (Int_t l1 = 0; l1 < 8; l1++)
	{
		for (Int_t l2 = 0; l2 < 8; l2++)
			cout << SmN(l1, l2) << ", ";
		cout << endl;
	}
	*/
	SmN.Invert();
	Sm = SmN.Similarity(DSmInv);
	TMatrixDSym H = Sm.SimilarityT(Rm);
	//cout << "H = " << endl; H.Print();
	fCov = H.Invert();
}