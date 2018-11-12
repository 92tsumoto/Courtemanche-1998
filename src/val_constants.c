
#include "syspara.h"

void val_consts(FILE *fp1)
{
	int i,w;
	double v_old,dvdt,dvdt_new;

	// Cell Geometry */
	// Forbes M, Sperelakis N. Ultrastructure of mammalian cardiac muscle. 
	// In: Sperelakis N, ed. Physiology and pathophysiology of the heart.
	// 2nd edition. Boston, MA: Kluwer Academic; 1989:3-41.
		var.length = 0.01;       // Length of the cell (cm)
		var.a = 0.0008;     // Radius of the cell (cm)
		//var.vcell = 1000*M_PI*var.a*var.a*var.length; // Cell Volume:3.801e-5 (uL)
		var.vcell = 20100; // Cell Volume: (um**3)
		//var.ageo = 2*M_PI*var.a*var.a+2.0*M_PI*var.a*var.length;  // eometric membrane area: 7.671e-5 (cm^2)
		//var.acap = var.ageo*2;     // Capacitive membrane area = Capacitance: 108.57e-6 (uF) --> 108.57 (pF)
		var.acap = 100;          // Capacitance: (pF)
		var.vmyo = var.vcell*0.68;      // Myoplasm volume (um**3) = 68% for Cell volume
		var.vnsr = var.vcell*0.0552;    // NSR volume (um**3)
		var.vjsr = var.vcell*0.0048;    // JSR volume (um**3)
		//var.vss  = var.vcell*0.02;    	// Subspace compartment (representing submembrane space near t-tubles)
		//var.vcleft = var.vcell*0.12/0.88;  // Cleft volume (uL)
		//var.vmito = var.vcell*0.26;     // Mitochondria volume (uL) = 26% for cell volume
		//var.vsr = var.vcell*0.06;       // SR volume (uL)
		var.vr1 = var.acap/(F*var.vmyo);
		var.vr2 = var.acap/(2.0*F*var.vmyo);
		var.vr3 = var.vnsr/var.vmyo;
		var.vr4 = var.vjsr/var.vmyo;
		var.vr5 = var.vjsr/var.vnsr;

	// Q10
		var.K_Q10 = 3.0;

	// Ion Valences
		var.zna = 1.0;  // Na valence
		var.zk = 1.0;   // K valence
		var.zca = 2.0;  // Ca valence

	// invariant constant
		var.RTonF = R*T/F;
		var.RTon2F = R*T/(var.zca*F);

	// Extracellular Concentrations
		var.nao = 140.0;     // Initial Bulk Medium Na (mM)
		var.ko = 5.4;      // Initial Bulk Medium K (mM)
		var.cao = 1.8;     // Initial Bulk Medium Ca (mM)

	// Fast sodium current
		ina.Gna_fast = 7.8;	// (nS/pF).
		
	// Inward rectifier K current: Ik1
		ik1.Gk1 = 0.09; // (nS/pF)

	// Transient outward current
		ito.Gto = 0.1652;	// (nS/pF).

	// Ultra rapid outward current
	//	ikur.Gkur = voltage-dependence function.	// (nS/pF).

	// Rapid delayed rectifier potassium current (Ikr)
		ikr.Gkr = 0.029411765;  //(nS/pF)
		//ikr.rategkr = sqrt(var.ko/5.4);

	// Slow delayed rectifier potassium current (Iks)
		iks.Gks = 0.12941176;  //(nS/pF)
	
	// L-type calcium current
		ical.gca = 0.12375;		// (nS/pF)
		ical.taufca = 2.0;		// (ms)

	// Sodium-Potassium Pump
		inak.km_nai = 10;		// (mM)
		inak.km_ko = 1.5;		// (mM)
		inak.sigma= (exp(var.nao/67.3)-1.0)/7.0;
		inak.max = 0.59933874;	// (pA/pF)

	// Sodium-Calcium Exchanger V-S
		ncx.max = 1600.0;	// (pA/pF)
		ncx.kmna = 87.5;	// (mM)
		ncx.kmca = 1.38;	// (mM)
		ncx.ksat = 0.1;
		ncx.gamma = 0.35;

	// Sarcolemmal Ca Pump
		ipca.G = 0.275;		// Max. Ca current through sarcolemmal Ca pump (pA/pF)
		ipca.km = 0.0005;		// Half-saturation concentration of sarcolemmal Ca pump (mM)

	// K Background Current 
		ikb.G = 0.0;		// Max. conductance of K background (nS/pF)
	// Ca Background Current 
		icab.G = 0.001131; // (nS/pF)
	// Na Background Current 
		inab.G = 0.0006744375; //(nS/pF)

	// SR calcium release flux, via RyR (Jrel)
		jrel.tauu = 8.0;	// (ms)
		jrel.K = 30.0; 		// saturation factor (ms-1)

	// Translocation of Ca Ions from NSR to JSR
		jtr.tau = 180.0;      // Time constant of Ca transfer from NSR to JSR (ms)

	// calcium uptake via SERCA pump (Jup)
		jup.kup = 0.00092;	// (mM)
		jup.p = 0.005;	// maximal Iup (mM/ms)
		jup.caup_max = 15.0;	// Maximal Ca2+ concentration in uptake comapartment (mM)

	// Myoplasmic Ca Ion Concentration Changes 
		var.cmdnmax = 0.05;   // Max. [Ca] buffered in CMDN (mM)
		var.trpnmax = 0.07;   // Max. [Ca] buffered in TRPN (mM)
		var.csqnmax = 10.0;     // Max. [Ca] buffered in CSQN (mM)

		var.kmcmdn = 0.00238;  // Equalibrium constant of buffering for CMDN (mM)
		var.kmtrpn = 0.0005;   // Equalibrium constant of buffering for TRPN (mM)
		var.kmcsqn = 0.8;     // Equalibrium constant of buffering for CSQN (mM)

}

