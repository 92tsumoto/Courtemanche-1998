#include "syspara.h"

// Fast sodium channel current
void comp_ina(double x[])
{
	int iV=0;
	double V1,V2,d1,d2;
	
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	mss  = Tmss[iV]*d2  + Tmss[iV+1]*d1;
	taum = Ttaum[iV]*d2 + Ttaum[iV+1]*d1;
	hss  = Thss[iV]*d2  + Thss[iV+1]*d1;
	tauh = Ttauh[iV]*d2 + Ttauh[iV+1]*d1;
	jss  = Tjss[iV]*d2  + Tjss[iV+1]*d1;
	tauj = Ttauj[iV]*d2 + Ttauj[iV+1]*d1;

	INaf = Gnaf*(x[0] - ENa)*x[1]*x[1]*x[1]*x[2]*x[3];
}

// Inward rectifier potassium current (Ik1)
void comp_ik1 (double x[])
{
        
	MKL_INT iV=0;   
	double V1,V2,d1,d2;
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	k1ss = Tk1ss[iV]*d2 + Tk1ss[iV+1]*d1;

	Ik1 = rategk1*Gk1*k1ss*(x[0] - EK);

}

// Ito Transient Outward Current
void comp_ito (double x[])
{

	MKL_INT iV=0;
	double V1,V2,d1,d2;
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	ass  = Tass[iV]*d2  + Tass[iV+1]*d1;
	taua = Ttaua[iV]*d2 + Ttaua[iV+1]*d1;

	iss  = Tiss[iV]*d2  + Tiss[iV+1]*d1;
	taui = Ttaui[iV]*d2 + Ttaui[iV+1]*d1;

	Ito = Gto*(x[0] - EK)*x[4]*x[4]*x[4]*x[5];

}

// Ikur Ultra-rapid delayed rectifier K Current
void comp_ikur (double x[])
{

	MKL_INT iV=0;
	double V1,V2,d1,d2;
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	ua_ss  = Tua_ss[iV]*d2  + Tua_ss[iV+1]*d1;
	tau_ua = Ttau_ua[iV]*d2 + Ttau_ua[iV+1]*d1;

	ui_ss  = Tui_ss[iV]*d2  + Tui_ss[iV+1]*d1;
	tau_ui = Ttau_ui[iV]*d2 + Ttau_ui[iV+1]*d1;
	
	Gkur   = Tgkur[iV]*d2 + Tgkur[iV+1]*d1;

	Ikur = Gkur*(x[0] - EK)*x[6]*x[6]*x[6]*x[7];

}

// Rapidly Activating Potassium Current 
void comp_ikr (double x[])
{
	MKL_INT iV=0;	
	double V1,V2,d1,d2;
	
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	xrss  = Txrss[iV]*d2  + Txrss[iV+1]*d1;
	tauxr = Ttau_xr[iV]*d2 + Ttau_xr[iV+1]*d1;
	rkr   = Trkr[iV]*d2   + Trkr[iV+1]*d1;

	Ikr = Gkr*rkr*(x[0] - EK)*x[8];

}

// Slowly Activating Potassium Current 
void comp_iks (double x[])
{
	
	MKL_INT iV=0;
	double V1,V2,d1,d2;
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	xsss  = Txsss[iV]*d2  + Txsss[iV+1]*d1;
	tauxs = Ttauxs[iV]*d2 + Ttauxs[iV+1]*d1;

	Iks = Gks*x[9]*x[9]*(x[0] - EK);

}

// L-type calcium current
void comp_ical(double x[])
{

	MKL_INT iV=0;
	double V1,V2,d1,d2;
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	// VDA
	dss  = Tdss[iV]*d2  + Tdss[iV+1]*d1;
	taud = Ttaud[iV]*d2 + Ttaud[iV+1]*d1;
	// VDI 
	fss  = Tfss[iV]*d2  + Tfss[iV+1]*d1;
	tauf = Ttauf[iV]*d2 + Ttauf[iV+1]*d1;
	// CDI 
	fcass = 1.0/(1.0+x[18]/0.00035);
	//ical.taufca = 2.0;

	Ical = GCaL*x[10]*x[11]*x[12]*(x[0] - ECaL);

}

// Na-K Pump
void comp_inak (double x[])
{
	MKL_INT iV=0;
	double V1,V2,d1,d2;
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	knai = Tknai[iV]*d2 + Tknai[iV+1]*d1;
	knao = Tknao[iV]*d2 + Tknao[iV+1]*d1;

	fnak = 1.0/(1.0 + knai + sigma*knao);

	INaK = GNaK*fnak*(1.0/(1.0 + pow((km_nai/x[16]),1.5)))*(Ko/(Ko + km_ko));

}

// Sodium-Calcium Exchanger NCX
void comp_inaca (double x[])
{
	MKL_INT iV=0;
	double V1,V2,d1,d2;
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	hca = Thca[iV]*d2 + Thca[iV+1]*d1;
	hna = Thna[iV]*d2 + Thna[iV+1]*d1;

	ncxh1 = x[16]*x[16]*x[16]*Cao;
	ncxh2 = Nao*Nao*Nao*x[18];
	ncxh3 = kmna*kmna*kmna + Nao*Nao*Nao;
	ncxh4 = kmca + Cao;

	INCX = GNCX*(hca*ncxh1 - hna*ncxh2)/(ncxh3*ncxh4*(1.0 + ksat*hna));
	
}

// K Background Current
void comp_ikb (double x[])
{
//	ikb.k = ikb.G*(x[0] - EK);
}

// Ca Background Current 
void comp_icab (double x[])
{
	IbCa = Gcab*(x[0] - ECa);
}

// Na Background Current 
void comp_inab (double x[])
{
	IbNa = Gnab*(x[0] - ENa);
}

// Sarcolemmal Ca Pump 
void comp_ipca (double x[])
{
	IpCa = GpCa*x[18]/(Kmpca + x[18]);
}

void comp_jrel (double x[])
{
	
	MKL_INT iV=0;
	double V1,V2,d1,d2;
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;

	wss  = Twss[iV]*d2  + Twss[iV+1]*d1;
	tauw = Ttauw[iV]*d2 + Ttauw[iV+1]*d1;
	
	Fn = 1000.0*(Vjsr*Jrel - 0.5*(0.5*Ical-0.2*INCX)*Acap/F)*1.0E+12;

	uss = 1.0/(1.0 + exp(-(Fn - 0.34175)/0.001367));
	//tauu = 8.0;

	vss = 1.0 - 1.0/(1.0 + exp(-(Fn - 0.06835)/0.001367));
	tauv = 1.91+2.09/(1.0+exp(-(Fn - 0.34175)/0.001367));

	Jrel = Krel*x[13]*x[13]*x[14]*x[15]*(x[20]-x[18]);

}

void comp_jtr (double x[])
{
//  Jtr = ([Ca]nsr - [Ca]jsr)/tautr;
	Jtr = (x[19] - x[20])/tau_tr;
}

void comp_jup (double x[])
{
	// Ca2+ uptake current by the NSR
	Jup = Jup_max*x[18]/(x[18] + Km_up);
	
	// Ca2+ leak current by the NSR
	// CRN original formulation
	// jup.leak = jup.p*x[19]/jup.caup_max;
	// Jleak = 0.005*x[19]/15.0;
	
	// my modification
	Jleak = Jleak_max*(x[19] - x[18]);
}

void comp_concentration (double x[])
{
	buf_cmdn = cmdnmax*kmcmdn/(kmcmdn+x[18])/(kmcmdn+x[18]);
	buf_trpn = trpnmax*kmtrpn/(kmtrpn+x[18])/(kmtrpn+x[18]);
	buf_csqn = csqnmax*kmcsqn/(kmcsqn+x[20])/(kmcsqn+x[20]);

	B2 = 1.0 + buf_cmdn + buf_trpn;
	B3 = 1.0 + buf_csqn;
}


// Reversal potentials */

void comp_reversal_potential(double x[])
{
	ENa = RTF*log(Nao/x[16]);
	EK  = RTF*log(Ko/x[17]);
	ECa = RTF*log(Cao/x[18])/zca;
}

