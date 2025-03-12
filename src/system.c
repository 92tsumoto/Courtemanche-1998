#include "syspara.h"

void function(double x[],double f[],double t)
{

	comp_reversal_potential(x);
	comp_ina(x);
	comp_ik1(x);
	comp_ito(x);
	comp_ikur(x);
	comp_ikr(x);
	comp_iks(x);
	comp_ical(x);
	comp_inak(x);
	comp_inaca(x);
	comp_icab(x);
	comp_inab(x);
	comp_ipca(x);
	comp_jrel(x);
	comp_jup(x);
	comp_jtr(x);
	comp_concentration(x);
	
	JNanet = INaf + IbNa + 3.0*INaK + 3.0*INCX;
	JKnet  = Ito + Ikur + Ikr + Iks + Ik1 - 2.0*INaK + Istim;
	JCanet = IpCa + Ical + IbCa - 2.0*INCX;

	Itotal = INaf + Ito + Ikur + Ikr + Iks + Ik1 + Ical + INaK + + INCX + IbNa + IbCa + IpCa;
	
	// Vm
	f[0] = -(Itotal+Istim);
	// INa
	f[1] = (mss - x[1])/taum; // m
	f[2] = (hss - x[2])/tauh; // h_fast
	f[3] = (jss - x[3])/tauj; // j
	// Ito
	f[4] = (ass - x[4])/taua;
	f[5] = (iss - x[5])/taui;
	// IKur
	f[6] = (ua_ss - x[6])/tau_ua;
	f[7] = (ui_ss - x[7])/tau_ui;
	// IKr
	f[8] = (xrss - x[8])/tauxr;
	// IKs
	f[9] = (xsss - x[9])/tauxs;
	// LTCC
	f[10] = (dss   - x[10])/taud;
	f[11] = (fss   - x[11])/tauf;
	f[12] = (fcass - x[12])/taufca;
	// Jrel
	f[13] = (uss - x[13])/tauu; 
	f[14] = (vss - x[14])/tauv; 
	f[15] = (wss - x[15])/tauw;
	// [Na]i
	f[16] = -JNanet*Acap/F/Vmyo;
	// [K]i
	f[17] = -JKnet*Acap/F/Vmyo;
	// [Ca]i
	f[18] = (-JCanet*Acap/2.0/F + (Jleak - Jup)*Vnsr + Jrel*Vjsr)/Vmyo/B2;
	// [Ca]nsr
	f[19] = Jup - Jleak - Jtr*Vjsr/Vnsr;
	// [Ca]jsr
	f[20] = (Jtr - Jrel)/B3;

	//for(i=0;i<NN;i++){
	//	printf("f[%d]=%e\n",i,f[i]);
	//}
}
