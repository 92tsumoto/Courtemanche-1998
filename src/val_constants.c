
#include "syspara.h"

void val_consts(FILE *fp1)
{
	//double v_old,dvdt,dvdt_new;

	// Cell Geometry */
	// Based on Luo and Rudy ventricular myocyte model (1994)
		//length = 0.01;       // Length of the cell (cm)
		//radius = 0.0004;     // Radius of the cell (cm)
		//Vcell = 0.50265E-6;  // M_PI*radius*radius*length (cm3); 
		//Vcell = 502.655E-12; // (L) Cell Volume:3.801e-5 (uL)
		Vcell = 20100.0E-15; // Cell Volume: (um**3) --> 20100.0E-12 (cm3) --> 20100E-15(L) --> 20.1 (pL)
		Acap = 100.0;          // Capacitance: (pF)
		Vmyo = 13668E-15;      // Myoplasm volume (um**3) = 68% for Cell volume --> Vcell*0.68;
		Vnsr = 1109.52E-15;    // NSR volume (um**3)
		Vjsr = 96.48E-15;    // JSR volume (um**3)
		//Vmyo = Vcell*0.68;      // Myoplasm volume (um**3) = 68% for Cell volume
		//Vnsr = Vcell*0.0552;    // NSR volume (um**3)
		//Vjsr = Vcell*0.0048;    // JSR volume (um**3)
		//vss  = Vcell*0.02;    	// Subspace compartment (representing submembrane space near t-tubles)
		//vcleft = Vcell*0.12/0.88;  // Cleft volume (uL)
		//vmito = Vcell*0.26;     // Mitochondria volume (uL) = 26% for cell volume
		//vsr = Vnsr + Vjsr;       // SR volume (uL)

	// Q10
		K_Q10 = 3.0;

	// Ion Valences
		zna = 1.0;  // Na valence
		zk = 1.0;   // K valence
		zca = 2.0;  // Ca valence

	// invariant constant
		RTF = R*T/F;
		FRT = F/R/T;

	// Extracellular Concentrations
		Nao = 140.0;     // Initial Bulk Medium Na (mM)
		Ko = 5.4;      // Initial Bulk Medium K (mM)
		Cao = 1.8;     // Initial Bulk Medium Ca (mM)

	// Fast sodium current
		Gnaf = 7.8;	// (nS/pF).
		
	// Inward rectifier K current: Ik1
		Gk1 = 0.09; // (nS/pF)

	// Transient outward current
		Gto = 0.1652;	// (nS/pF).

	// Ultra rapid outward current
	//	Gkur = voltage-dependence function.	// (nS/pF).

	// Rapid delayed rectifier potassium current (Ikr)
		Gkr = 0.029411765;  //(nS/pF)
		//ikr.rategkr = sqrt(var.ko/5.4);

	// Slow delayed rectifier potassium current (Iks)
		Gks = 0.12941176;  //(nS/pF)
	
	// L-type calcium current
		GCaL = 0.12375;		// (nS/pF)
		taufca = 2.0;		// (ms)
		ECaL = 65.0;
		
	// Sodium-Potassium Pump
		km_nai = 10;		// (mM)
		km_ko = 1.5;		// (mM)
		sigma= (exp(Nao/67.3)-1.0)/7.0;
		GNaK = 0.59933874;	// (pA/pF)

	// Sodium-Calcium Exchanger V-S
		GNCX = 1600.0;	// (pA/pF)
		kmna = 87.5;	// (mM)
		kmca = 1.38;	// (mM)
		ksat = 0.1;
		gm = 0.35;

	// K Background Current 
	//	ikb.G = 0.0;		// Max. conductance of K background (nS/pF)
	// Ca Background Current 
		Gcab = 0.001131; // (nS/pF)
	// Na Background Current 
		Gnab = 0.0006744375; //(nS/pF)

	// Sarcolemmal Ca Pump
		GpCa  = 0.275;		// Max. Ca current through sarcolemmal Ca pump (pA/pF)
		Kmpca = 0.0005;		// Half-saturation concentration of sarcolemmal Ca pump (mM)

	// SR calcium release flux, via RyR (Jrel)
		tauu = 8.0;			// (ms)
		Krel = 30.0; 		// saturation factor (ms-1)

	// Translocation of Ca Ions from NSR to JSR
		tau_tr = 180.0;      // Time constant of Ca transfer from NSR to JSR (ms)

	// calcium uptake via SERCA pump (Jup)
		Km_up    = 0.00092;	// (mM)
		Jup_max  = 0.005;	// maximal Iup (mM/ms)
		Caup_max = 15.0;	// Maximal Ca2+ concentration in uptake comapartment (mM)
		Jleak_max = Jup_max/Caup_max;	

	// Myoplasmic Ca Ion Concentration Changes 
		cmdnmax = 0.05;   // Max. [Ca] buffered in CMDN (mM)
		trpnmax = 0.07;   // Max. [Ca] buffered in TRPN (mM)
		csqnmax = 10.0;     // Max. [Ca] buffered in CSQN (mM)

		kmcmdn = 0.00238;  // Equalibrium constant of buffering for CMDN (mM)
		kmtrpn = 0.0005;   // Equalibrium constant of buffering for TRPN (mM)
		kmcsqn = 0.8;     // Equalibrium constant of buffering for CSQN (mM)

}

