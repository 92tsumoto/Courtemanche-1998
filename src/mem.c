
#include "syspara.h"

typedef double Number;

void initial_mem()
{

	// ina_fast
	Tmss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttaum = (Number *)calloc(VNMAX,sizeof(Number));
	Thss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttauh = (Number *)calloc(VNMAX,sizeof(Number));
	Tjss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttauj = (Number *)calloc(VNMAX,sizeof(Number));
	if( Tmss==NULL || Ttaum==NULL || Thss==NULL || Ttauh==NULL || Tjss==NULL || Ttauj==NULL) exit(1);
	
	// ik1
	Tk1ss = (Number *)calloc(VNMAX,sizeof(Number));
	if( Tk1ss == NULL ) exit(1);
	
	// ito
	Tass  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttaua = (Number *)calloc(VNMAX,sizeof(Number));
	Tiss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttaui = (Number *)calloc(VNMAX,sizeof(Number));
	if( Tass==NULL || Ttaua==NULL || Tiss==NULL || Ttaui==NULL) exit(1);
	
	// ikur
	Tua_ss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttau_ua = (Number *)calloc(VNMAX,sizeof(Number));
	Tui_ss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttau_ui = (Number *)calloc(VNMAX,sizeof(Number));
	Tgkur   = (Number *)calloc(VNMAX,sizeof(Number));
	if( Tua_ss==NULL || Ttau_ua==NULL || Tui_ss==NULL || Ttau_ui==NULL || Tgkur==NULL) exit(1);
	
	// ikr
	Txrss   = (Number *)calloc(VNMAX,sizeof(Number));
	Ttau_xr = (Number *)calloc(VNMAX,sizeof(Number));
	Trkr    = (Number *)calloc(VNMAX,sizeof(Number));
	if( Txrss==NULL || Ttau_xr==NULL  || Trkr==NULL ) exit(1);

	// iks
	Txsss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttauxs = (Number *)calloc(VNMAX,sizeof(Number));
	if( Txsss==NULL || Ttauxs==NULL ) exit(1);

	// ical
	Tdss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttaud = (Number *)calloc(VNMAX,sizeof(Number));
	Tfss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttauf = (Number *)calloc(VNMAX,sizeof(Number));
	if( Tdss==NULL || Ttaud==NULL || Tfss==NULL || Ttauf==NULL ) exit(1);

	// inak
	Tknai = (Number *)calloc(VNMAX,sizeof(Number));
	Tknao = (Number *)calloc(VNMAX,sizeof(Number));
	if( Tknai==NULL || Tknao==NULL ) exit(1);
	
	// inaca
	Thca = (Number *)calloc(VNMAX,sizeof(Number));
	Thna = (Number *)calloc(VNMAX,sizeof(Number));
	if( Thca==NULL || Thna==NULL ) exit(1);
	
	// jrel
	Twss  = (Number *)calloc(VNMAX,sizeof(Number));
	Ttauw = (Number *)calloc(VNMAX,sizeof(Number));
	if( Twss==NULL || Ttauw==NULL ) exit(1);
}


void closed_mem()
{

	free(Tmss); free(Ttaum); free(Thss); free(Ttauh); free(Tjss); free(Ttauj);
	free(Tk1ss);
	free(Tass); free(Ttaua); free(Tiss); free(Ttaui);
	free(Tua_ss); free(Ttau_ua); free(Tui_ss); free(Ttau_ui); free(Tgkur);
	free(Txrss); free(Ttau_xr); free(Trkr);
	free(Txsss); free(Ttauxs);
	free(Tdss); free(Ttaud); free(Tfss); free(Ttauf);
	free(Tknai); free(Tknao);
	free(Twss); free(Ttauw);

}

