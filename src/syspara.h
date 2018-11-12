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

//#define R 8314.472		// J/mmol/K
//#define F 96485.33771638995	// C/mol
//#define T 310.0		// K
#define R 8.3143	// J/mol/K
#define F 96.4867	// C/mmol
#define T 310.0		// K

#define dvm 5
#define Emax 200
#define Emin -200
#define VNMAX (Emax-Emin)*dvm+1

struct varstruct {

    int datas;
    int line_wid[NUM];
	
	int n;
    double Istim;
	double dIstim;

	// An invariant constant
	double RTonF,RTon2F;

	// Cell tupe
	int celltype;

	// Cell Geometry
	double length,a,vcell,ageo,acap;
	double vmyo,vmito,vsr,vnsr,vjsr,vcleft,vss;
	double vr1,vr2,vr3,vr4,vr5,vr6,vr7,vr8;

	// Ion Valences 
	double zna,zk,zca;

	// time ratio
	double ndis;

	// Q10
	double K_Q10;	

	// Reversal potential
	double Ena,Ek,Eks,Eca;
	double prnak;
			
	// Sodium-Calcium Exchanger V-S
	double hca,hna;
	double *Thca,*Thna;
	double kna1,kna2,kna3,kasym;
	double omega_na,omega_ca,omega_naca;
	double kca_on,kca_off,qna,qca;
	double km_ca_act;
	double inaca_i,inaca_ss,inaca;
	double Gnaca;

	// Total Ion currents 
	double Ina_total;
	double Ik_total;
	double Ica_total;
	double Itotal;

	// Ion concentration and Buffers
	double cmdnmax,kmcmdn;
	double trpnmax,kmtrpn;
	double csqnmax,kmcsqn;

	// Extracellular ion concentrations
	double nao,ko,cao;

	// Base Currnt Stimulus
	double Istim_base;

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

// Fast and Late sodium currnets
struct inastruct {

	double Gna_fast,fast;
	double *Tmss,*Ttaum,*Thss,*Ttauh,*Tjss,*Ttauj;
	double mss,taum,hss,tauh,jss,tauj;

} ina;

// Transient Outward Current (Ito)
struct itostruct {

	double ik,Gto;
	double ass,taua,iss,taui;
	double *Tass,*Ttaua,*Tiss,*Ttaui;

} ito;

// Transient Outward Current (Ito)
struct ikurstruct {

	double ik,gkur;
	double ass,taua,iss,taui;
	double *Tass,*Ttaua,*Tiss,*Ttaui;
	double *Tgkur;

} ikur;

// L-type Calcium channel current (IcaL)
struct icalstruct {

	double dss,taud,fss,tauf,fcass,taufca;
	double *Tdss,*Ttaud,*Tfss,*Ttauf;
	double ica,gca;

} ical;

// Rapid activating potassium current (Ikr)
struct ikrstruct {

	double ik,Gkr,rategkr;
	double xr,xrss,tauxr,rkr;
	double *Txrss,*Ttauxr,*Trkr;

} ikr;

// Slowlactivating potassium current (Iks)
struct iksstruct {

	double ik,Gks;
	double xsss,tauxs;
	double *Txsss,*Ttauxs;
		
} iks;

// Inward rectifier potassium current (Ik1)
struct ik1struct {

	double ik,Gk1,rategk1;
	double k1ss,tauk1,rk1;
	double *Tk1ss,*Ttauk1,*Trk1;

} ik1;

// Sodium-Potassium Pump
struct inakstruct {

	double km_nai,km_ko;
	double knai,knao,*Tknai,*Tknao;
	double sigma,fnak,max,nak;

} inak;

struct ncxstruct {

	double hca,hna;
	double *Thca,*Thna;
	double h1,h2,h3,h4;
	double ksat,gamma;
	double kmna,kmca;
	double j,max;

} ncx;

// Sarcolemmal Ca Pump
struct ipcastruct {

	double G,km,ca;

} ipca;

// Na Background Current
struct inabstruct {
	double G,na;
} inab;

// K Background Current
struct ikbstruct {
	double G,k;
} ikb;

// Ca Background Current
struct icabstruct {
	double G,ca;
} icab;

// SR calcium release flux, via RyR (Jrel)
struct jrelstruct {

	double uss,tauu,vss,tauv,wss,tauw;
	double *Twss,*Ttauw;
	double K,Fn;
	double CaMKss,tau_CaMK;
	double pCaMK,ca;
	double p;

} jrel;

// Calcium uptake via SERCA pump
struct jupstruct {

	double p,kup,caup_max;
	double ca,leak;

} jup;

// Ca buffer
struct bufstruct {

	double ca_cmdn,ca_trpn,ca_csqn;
	double b2,b3;

} buf;

// Translocation of Ca Ions from NSR to JSR
struct jtrstruct {

	double tau,ca;

} jtr;

void val_consts(FILE *);
void make_ExPTable();

void eular(int n,double h,double x[],double t);
void function(double x[],double f[],double t);
void input_para(FILE *);
//void initial_mem(int tMAX);
void initial_mem();
void closed_mem();

void eventloop(FILE *, int *mode, int *P, double m[]);
void orbit(int *mode, double m[], double x2);
void draw_p(int *mode, int P, double x[], double x2);
void mouse(int *mode, double x[], double x2);

void data_out(FILE *, double t, double u[]);
void out_ikr (FILE *, double time, double p[]);
void out_iks (FILE *, double time, double p[]);
void out_ical(FILE *, double time, double p[]);
void out_inaca (FILE *f, double time, double p[]);
void out_inak (FILE *f, double time, double p[]);
void out_cicr (FILE *f, double time, double p[]);

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

main(int argc,char **argv);
