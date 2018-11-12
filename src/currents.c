#include "syspara.h"

void comp_ina(double x[])
{
	//MKL_INT iV=0;
	int iV=0;
	double V1,V2,d1,d2;
	
	V1 = (x[0]+Emax)*dvm;
	V2 = (int)V1;
	d1 = V1-V2;
	d2 = 1.0-d1;
	iV = (int)V2;
	//printf("iV=%d,V1=%f,V2=%f,d1=%f,d2=%f\n",iV,V1,V2,d1,d2);

	ina.mss = ina.Tmss[iV]*d2 + ina.Tmss[iV+1]*d1;
	ina.taum = ina.Ttaum[iV]*d2 + ina.Ttaum[iV+1]*d1;
	ina.hss = ina.Thss[iV]*d2 + ina.Thss[iV+1]*d1;
	ina.tauh = ina.Ttauh[iV]*d2 + ina.Ttauh[iV+1]*d1;
	ina.jss = ina.Tjss[iV]*d2 + ina.Tjss[iV+1]*d1;
	ina.tauj = ina.Ttauj[iV]*d2 + ina.Ttauj[iV+1]*d1;

	ina.fast = ina.Gna_fast*(x[0]-var.Ena)*x[1]*x[1]*x[1]*x[2]*x[3];
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

	ik1.k1ss = ik1.Tk1ss[iV]*d2 + ik1.Tk1ss[iV+1]*d1;

	ik1.ik = ik1.Gk1*ik1.k1ss*(x[0]-var.Ek);

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

	ito.ass = ito.Tass[iV]*d2 + ito.Tass[iV+1]*d1;
	ito.taua = ito.Ttaua[iV]*d2 + ito.Ttaua[iV+1]*d1;

	ito.iss = ito.Tiss[iV]*d2 + ito.Tiss[iV+1]*d1;
	ito.taui = ito.Ttaui[iV]*d2 + ito.Ttaui[iV+1]*d1;

	ito.ik = ito.Gto*(x[0]-var.Ek)*x[4]*x[4]*x[4]*x[5];

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

	ikur.ass = ikur.Tass[iV]*d2 + ikur.Tass[iV+1]*d1;
	ikur.taua = ikur.Ttaua[iV]*d2 + ikur.Ttaua[iV+1]*d1;

	ikur.iss = ikur.Tiss[iV]*d2 + ikur.Tiss[iV+1]*d1;
	ikur.taui = ikur.Ttaui[iV]*d2 + ikur.Ttaui[iV+1]*d1;
	
	ikur.gkur = ikur.Tgkur[iV]*d2 + ikur.Tgkur[iV+1]*d1;

	ikur.ik = ikur.gkur*(x[0]-var.Ek)*x[6]*x[6]*x[6]*x[7];

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

	ikr.xrss = ikr.Txrss[iV]*d2 + ikr.Txrss[iV+1]*d1;
	ikr.tauxr = ikr.Ttauxr[iV]*d2 + ikr.Ttauxr[iV+1]*d1;
	ikr.rkr = ikr.Trkr[iV]*d2 + ikr.Trkr[iV+1]*d1;

	ikr.ik = ikr.Gkr*ikr.rkr*(x[0]-var.Ek)*x[8];

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

	iks.xsss = iks.Txsss[iV]*d2 + iks.Txsss[iV+1]*d1;
	iks.tauxs = iks.Ttauxs[iV]*d2 + iks.Ttauxs[iV+1]*d1;
	iks.ik = iks.Gks*x[9]*x[9]*(x[0]-var.Ek);

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
	ical.dss = ical.Tdss[iV]*d2 + ical.Tdss[iV+1]*d1;
	ical.taud = ical.Ttaud[iV]*d2 + ical.Ttaud[iV+1]*d1;
	// VDI 
	ical.fss = ical.Tfss[iV]*d2 + ical.Tfss[iV+1]*d1;
	ical.tauf = ical.Ttauf[iV]*d2 + ical.Ttauf[iV+1]*d1;
	// CDI 
	ical.fcass = 1.0/(1.0+x[18]/0.00035);
	//ical.taufca = 2.0;

	ical.ica =ical.gca*x[10]*x[11]*x[12]*(x[0]-65.0);

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

	inak.knai = inak.Tknai[iV]*d2 + inak.Tknai[iV+1]*d1;
	inak.knao = inak.Tknao[iV]*d2 + inak.Tknao[iV+1]*d1;

	inak.fnak = 1.0/(1.0 + inak.knai + inak.sigma*inak.knao);

	//inak.nak = inak.max*inak.fnak*(1.0/(1.0 + pow(inak.km_nai/x[16],1.5))*(var.ko/(var.ko+inak.km_ko);
	inak.nak = inak.max*inak.fnak*(1.0/(1.0 + pow(10.0/x[16],1.5)))*(var.ko/(var.ko+1.5));

}

// K Background Current
void comp_ikb (double x[])
{
	ikb.k = ikb.G*(x[0] - var.Ek);
}

// Ca Background Current 
void comp_icab (double x[])
{
	icab.ca = icab.G*(x[0] - var.Eca);
}

// Na Background Current 
void comp_inab (double x[])
{
	inab.na = inab.G*(x[0] - var.Ena);
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

	ncx.hca=ncx.Thca[iV]*d2 + ncx.Thca[iV+1]*d1;
	ncx.hna=ncx.Thna[iV]*d2 + ncx.Thna[iV+1]*d1;

	ncx.h1 = x[16]*x[16]*x[16]*var.cao;
	ncx.h2 = var.nao*var.nao*var.nao*x[18];
	ncx.h3 = ncx.kmna*ncx.kmna*ncx.kmna+var.nao*var.nao*var.nao;
	ncx.h4 = ncx.kmca+var.cao;

	ncx.j = ncx.max*(ncx.hca*ncx.h1-ncx.hna*ncx.h2)/(ncx.h3*ncx.h4*(1.0+ncx.ksat*ncx.hna));
	
}


// Sarcolemmal Ca Pump 

void comp_ipca (double x[])
{
	ipca.ca = ipca.G*x[18]/(ipca.km + x[18]);
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

	//jrel.Fn = 1E-12*var.vjsr*jrel.ca - (5E-13/F)*(0.5*ical.ica-0.2*ncx.j);
	jrel.Fn = 1E-12*var.vjsr*jrel.ca - (5E-13/F)*(0.5*var.acap*ical.ica-0.2*var.acap*ncx.j);

	jrel.uss = 1.0/(1.0+exp(-(jrel.Fn-3.4175E-13)/13.67E-16));
	//jrel.tauu = 8.0;

	jrel.tauv = 1.91+2.09/(1.0+exp(-(jrel.Fn-3.4175E-13)/13.67E-16));
	jrel.vss = 1.0-1.0/(1.0+exp(-(jrel.Fn-6.835E-14)/13.67E-16));

	jrel.wss=jrel.Twss[iV]*d2 + jrel.Twss[iV+1]*d1;
	jrel.tauw=jrel.Ttauw[iV]*d2 + jrel.Ttauw[iV+1]*d1;

	jrel.ca = jrel.K*x[13]*x[13]*x[14]*x[15]*(x[20]-x[18]);

}

void comp_jtr (double x[])
{
	jtr.ca = (x[19]-x[20])/jtr.tau;
}

void comp_jup (double x[])
{
	// Ca2+ uptake current by the NSR
	jup.ca = jup.p*x[18]/(x[18]+jup.kup);
	
	// Ca2+ leak current by the NSR
	jup.leak = jup.p*x[19]/jup.caup_max;

}

void comp_concentration (double x[])
{
	buf.ca_cmdn = var.cmdnmax*var.kmcmdn/(var.kmcmdn+x[18])/(var.kmcmdn+x[18]);
	buf.ca_trpn = var.trpnmax*var.kmtrpn/(var.kmtrpn+x[18])/(var.kmtrpn+x[18]);
	buf.ca_csqn = var.csqnmax*var.kmcsqn/(var.kmcsqn+x[20])/(var.kmcsqn+x[20]);

	buf.b2 = 1.0+buf.ca_cmdn+buf.ca_trpn;
	buf.b3 = 1.0+buf.ca_csqn;

}


// Reversal potentials */

void comp_reversal_potential(double x[])
{
	var.Ena = var.RTonF*log(var.nao/x[16]);
	var.Ek = var.RTonF*log(var.ko/x[17]);
	var.Eca = var.RTon2F*log(var.cao/x[18]);
	
	//printf("Ena=%lf, Ek=%lf, Eks=%lf\n",var.Ena,var.Ek,var.Eks);
}

