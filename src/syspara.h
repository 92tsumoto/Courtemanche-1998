//#ifndef __SYSPARA_H_INCLUDE 
//#define __SYSPARA_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "mkl.h"
#include "/home/tsumoto/lib/xhplot.h"

#define NN 21
#define BUF 100
#define NUM 60

//#define R 8.314462			// J/mol/K
//#define F 96485.33771638995	// C/mol
//#define T 310.0				// K
#define R 8314300000000000	// 8.3143E+15 (aJ/mM/K)
#define F 96486700000000000	// 96.4867E+15 (fC/mM)
#define T 310.0		// K

#define dvm 50
#define Emax 2000
#define Emin -2000
#define VNMAX (Emax-Emin)*dvm+1

	// An invariant constant
	double RTF,FRT;
	
	// Cell tupe
	int celltype;

	// Ion Valences 
	double zna,zk,zca;

	// Reversal potential
	double ENa,EK,EKs,ECa;
	double prnak;
			
	// Q10
	double K_Q10;	

	// Extracellular ion concentrations
	double Nao,Ko,Cao;

	// Cell Geometry
	double length,radius,Vcell,Ageo,Acap;
	double Vmyo,Vsr,Vnsr,Vjsr,Vcleft,Vss;
	double Vr1,Vr2,Vr3,Vr4,Vr5,vr6,vr7,vr8;

	// Base Currnt Stimulus
	double Istim_base;
    double Istim;
	double dIstim;

struct varstruct {

    int datas;
    int line_wid[NUM];
	
	int n;

	// time ratio
	double ndis;

	// test variable
	double dt,dvdt;
	// Sttimulus parameters
	double BCL;  // Base cycle length = stimulus period
	int beat; // Number of stimulus

    int m;
    int l;

    double x0[NUM][NN];
    double tsign[NUM];
    double tend[NUM];

    int pflag;
    int write, graph;
    int write0;
    int half;
	int pswitch,sswitch,out_data,deb;

} var;

// Total Ion currents 
	double JNanet,JKnet,JCanet;
	double Itotal;

// Fast and Late sodium currnets
	double Gnaf,INaf,ENa;
	double *Tmss,*Ttaum,*Thss,*Ttauh,*Tjss,*Ttauj;
	double mss,taum,hss,tauh,jss,tauj;

// Inward rectifier potassium current (Ik1)
// time-indipendent K+ current

	double Ik1,Gk1,rategk1;
	double k1ss,tauk1,rk1;
	double *Tk1ss,*Ttauk1,*Trk1;

// Transient Outward Current (Ito)
	double Ito,Gto;
	double ass,taua,iss,taui;
	double *Tass,*Ttaua,*Tiss,*Ttaui;

// Ultrarapid delayed rectifier K+ Current (Ito)
	double Ikur,Gkur;
	double ua_ss,tau_ua,ui_ss,tau_ui;
	double *Tua_ss,*Ttau_ua,*Tui_ss,*Ttau_ui;
	double *Tgkur;

// Rapid activating potassium current (Ikr)
	double Ikr,Gkr,rategkr;
	double xrss,tauxr,rkr;
	double *Txrss,*Ttau_xr,*Trkr;

// Slowlactivating potassium current (Iks)
	double Iks,Gks,rategks;
	double xsss,tauxs;
	double *Txsss,*Ttauxs;

// L-type Calcium channel current (IcaL)
	double Ical,GCaL,ECaL;
	double dss,taud,fss,tauf,fcass,taufca;
	double *Tdss,*Ttaud,*Tfss,*Ttauf;

// Sodium-Potassium (NaK) Pump
	double km_nai,km_ko;
	double knai,knao,*Tknai,*Tknao;
	double sigma,fnak,GNaK,INaK;

// Sodium-Calcium exchanger (NCX)
	double hca,hna;
	double *Thca,*Thna;
	double ncxh1,ncxh2,ncxh3,ncxh4;
	double ksat,gm;
	double kmna,kmca;
	double GNCX,INCX;

// Na Background Current
	double IbNa,Gnab;

// Ca Background Current
	double IbCa,Gcab;

// Sarcolemmal Ca Pump
	double GpCa,Kmpca,IpCa;

// SR calcium release flux, via RyR (Jrel)
	double uss,tauu,vss,tauv,wss,tauw;
	double *Twss,*Ttauw;
	double Krel,Fn,Jrel;
	double CaMKss,tau_CaMK;
	double pCaMK,relca;
	double relp;

// Calcium uptake via SERCA pump
	double Jup,Km_up,Jup_max;
	double Jleak,Jleak_max,Caup_max;
// Translocation of Ca Ions from NSR to JSR
	double Jtr,tau_tr;

// Ion concentration and Buffers
	double cmdnmax,kmcmdn;
	double trpnmax,kmtrpn;
	double csqnmax,kmcsqn;
	double buf_cmdn;
	double buf_trpn;
	double buf_csqn;
	double B2,B3;

void val_consts(FILE *);
void make_ExpTable(void);

//void eular(int n,double h,double x[],double t);
void runge(int n,double h,double x[],double t);
void function(double x[],double f[],double t);
void input_para(FILE *);
//void initial_mem(int tMAX);
void initial_mem(void);
void closed_mem(void);

void eventloop(FILE *, int *mode, int *P, double m[]);
void orbit(int *mode, double m[]);
void draw_p(int *mode, int P, double x[]);
void mouse(int *mode, double x[]);

void data_out(FILE *, double t, double u[]);
void out_ikr (FILE *, double time, double p[]);
void out_iks (FILE *, double time, double p[]);
void out_ical(FILE *, double time, double p[]);
void out_inaca (FILE *f, double time, double p[]);
void out_inak (FILE *f, double time, double p[]);
void out_cicr (FILE *f, double time, double p[]);
void current(FILE *,FILE *,FILE *,FILE *,FILE *,FILE *, double ttime, double x[]);

void comp_reversal_potential(double x[]);
void comp_ina(double x[]);
void comp_ito(double x[]);
void comp_ikur(double x[]);
void comp_ical(double x[]);
void comp_ikr(double x[]);
void comp_iks(double x[]);
void comp_ik1(double x[]);
void comp_inaca(double x[]);
void comp_inak(double x[]);
void comp_ipca(double x[]);
void comp_ikb(double x[]);
void comp_icab(double x[]);
void comp_inab(double x[]);
void comp_jrel(double x[]);
void comp_jup(double x[]);
void comp_jtr (double x[]);
void comp_concentration (double x[]);

//int main(int argc,char **argv);
