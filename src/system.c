#include "syspara.h"

void function(double x[],double f[],double t)
{

	int i;
	comp_reversal_potential(x);
	comp_ina(x);
	comp_ik1(x);
	comp_ito(x);
	comp_ikur(x);
	comp_ikr(x);
	comp_iks(x);
	comp_ical(x);
	comp_inak(x);
	comp_ikb(x);
	comp_icab(x);
	comp_inab(x);
	comp_inaca(x);
	comp_ipca(x);
	comp_jrel(x);
	comp_jup(x);
	comp_jtr(x);
	comp_concentration(x);
	
	var.Ina_total = ina.fast + inab.na + 3.0*inak.nak + 3.0*ncx.j;
	var.Ik_total = ito.ik + ikur.ik + ikr.ik + iks.ik + ik1.ik + ikb.k - 2.0*inak.nak + var.Istim;
	var.Ica_total = ipca.ca + ical.ica + icab.ca - 2.0*ncx.j;

	var.Itotal = ina.fast + ito.ik + ikur.ik + ikr.ik + iks.ik + ik1.ik + ical.ica
					+ ncx.j + inak.nak + inab.na + icab.ca + ikb.k + ipca.ca + var.Istim;

	f[0] = -var.Itotal;
	//Fast sodium current
	f[1] = (ina.mss - x[1])/ina.taum; // m
	f[2] = (ina.hss - x[2])/ina.tauh; // h_fast
	f[3] = (ina.jss - x[3])/ina.tauj; // j
	//Transient outward current
	f[4] = (ito.ass - x[4])/ito.taua;
	f[5] = (ito.iss - x[5])/ito.taui;
	//Transient outward current
	f[6] = (ikur.ass - x[6])/ikur.taua;
	f[7] = (ikur.iss - x[7])/ikur.taui;
	// Ikr
	f[8] = (ikr.xrss - x[8])/ikr.tauxr;
	// Iks
	f[9] = (iks.xsss - x[9])/iks.tauxs;
	// LTCC
	f[10] = (ical.dss - x[10])/ical.taud;
	f[11] = (ical.fss - x[11])/ical.tauf;
	f[12] = (ical.fcass - x[12])/ical.taufca;
	// Jrel
	f[13] = (jrel.uss - x[13])/jrel.tauu; 
	f[14] = (jrel.vss - x[14])/jrel.tauv; 
	f[15] = (jrel.wss - x[15])/jrel.tauw;
	// [Na]i
	f[16] = -var.Ina_total*var.vr1;
	// [K]i
	f[17] = -var.Ik_total*var.vr1;
	// [Ca]i
	f[18] = (-var.Ica_total*var.vr2 + (jup.leak-jup.ca)*var.vr3 + jrel.ca*var.vr4)/buf.b2;
	// [Ca]nsr
	f[19] = jup.ca - jup.leak - jtr.ca*var.vr5;
	// [Ca]jsr
	f[20] = (jtr.ca-jrel.ca)/buf.b3;

	//for(i=0;i<NN;i++){
	//	printf("f[%d]=%e\n",i,f[i]);
	//}
}
