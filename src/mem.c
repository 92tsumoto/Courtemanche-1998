
#include "syspara.h"

typedef double Number;

void initial_mem()
{

	// ina_fast
	ina.Tmss=(Number *)calloc(VNMAX,sizeof(Number));
	ina.Ttaum=(Number *)calloc(VNMAX,sizeof(Number));
	ina.Thss=(Number *)calloc(VNMAX,sizeof(Number));
	ina.Ttauh=(Number *)calloc(VNMAX,sizeof(Number));
	ina.Tjss=(Number *)calloc(VNMAX,sizeof(Number));
	ina.Ttauj=(Number *)calloc(VNMAX,sizeof(Number));
	if( ina.Tmss==NULL || ina.Ttaum==NULL || ina.Thss==NULL || ina.Ttauh==NULL || ina.Tjss==NULL || ina.Ttauj==NULL) exit(1);
	
	// ik1
	ik1.Tk1ss=(Number *)calloc(VNMAX,sizeof(Number));
	if( ik1.Tk1ss == NULL ) exit(1);
	
	// ito
	ito.Tass=(Number *)calloc(VNMAX,sizeof(Number));
	ito.Ttaua=(Number *)calloc(VNMAX,sizeof(Number));
	ito.Tiss=(Number *)calloc(VNMAX,sizeof(Number));
	ito.Ttaui=(Number *)calloc(VNMAX,sizeof(Number));
	if( ito.Tass==NULL || ito.Ttaua==NULL || ito.Tiss==NULL || ito.Ttaui==NULL) exit(1);
	
	// ikur
	ikur.Tass=(Number *)calloc(VNMAX,sizeof(Number));
	ikur.Ttaua=(Number *)calloc(VNMAX,sizeof(Number));
	ikur.Tiss=(Number *)calloc(VNMAX,sizeof(Number));
	ikur.Ttaui=(Number *)calloc(VNMAX,sizeof(Number));
	ikur.Tgkur=(Number *)calloc(VNMAX,sizeof(Number));
	if( ikur.Tass==NULL || ikur.Ttaua==NULL || ikur.Tiss==NULL || ikur.Ttaui==NULL || ikur.Tgkur==NULL) exit(1);
	
	// ikr
	ikr.Txrss=(Number *)calloc(VNMAX,sizeof(Number));
	ikr.Ttauxr=(Number *)calloc(VNMAX,sizeof(Number));
	ikr.Trkr=(Number *)calloc(VNMAX,sizeof(Number));
	if( ikr.Txrss==NULL || ikr.Ttauxr==NULL  || ikr.Trkr==NULL ) exit(1);

	// iks
	iks.Txsss=(Number *)calloc(VNMAX,sizeof(Number));
	iks.Ttauxs=(Number *)calloc(VNMAX,sizeof(Number));
	if( iks.Txsss==NULL || iks.Ttauxs==NULL ) exit(1);

	// ical
	ical.Tdss=(Number *)calloc(VNMAX,sizeof(Number));
	ical.Ttaud=(Number *)calloc(VNMAX,sizeof(Number));
	ical.Tfss=(Number *)calloc(VNMAX,sizeof(Number));
	ical.Ttauf=(Number *)calloc(VNMAX,sizeof(Number));
	if( ical.Tdss==NULL || ical.Ttaud==NULL || ical.Tfss==NULL || ical.Ttauf==NULL ) exit(1);

	// inak
	inak.Tknai=(Number *)calloc(VNMAX,sizeof(Number));
	inak.Tknao=(Number *)calloc(VNMAX,sizeof(Number));
	if( inak.Tknai==NULL || inak.Tknao==NULL ) exit(1);
	
	// inaca
	ncx.Thca=(Number *)calloc(VNMAX,sizeof(Number));
	ncx.Thna=(Number *)calloc(VNMAX,sizeof(Number));
	if( ncx.Thca==NULL || ncx.Thna==NULL ) exit(1);
	
	// jrel
	jrel.Twss=(Number *)calloc(VNMAX,sizeof(Number));
	jrel.Ttauw=(Number *)calloc(VNMAX,sizeof(Number));
	if( jrel.Twss==NULL || jrel.Ttauw==NULL ) exit(1);
}


void closed_mem()
{

	free(ina.Tmss); free(ina.Ttaum); free(ina.Thss); free(ina.Ttauh); free(ina.Tjss); free(ina.Ttauj);
	free(ik1.Tk1ss);
	free(ito.Tass); free(ito.Ttaua); free(ito.Tiss); free(ito.Ttaui);
	free(ikur.Tass); free(ikur.Ttaua); free(ikur.Tiss); free(ikur.Ttaui); free(ikur.Tgkur);
	free(ikr.Txrss); free(ikr.Ttauxr); free(ikr.Trkr);
	free(iks.Txsss); free(iks.Ttauxs);
	free(iks.Txsss); free(iks.Ttauxs);
	free(ical.Tdss); free(ical.Ttaud); free(ical.Tfss); free(ical.Ttauf);
	free(inak.Tknai); free(inak.Tknao);
	free(jrel.Twss); free(jrel.Ttauw);

}

