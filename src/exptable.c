#include "syspara.h"

void make_ExpTable()
{

	int vindex,kiindex;
	double v,ki;
	double am,bm,ah,bh,aj,bj;
	double ao,bo,ai,bi;
	double ua,ub,ia,ib;
	double axr,bxr;
	double axs,bxs;
    
	for(vindex=0;vindex<VNMAX;vindex++){

        v = (double)vindex/dvm-200.0;
		
		/** m-gate for ina **/
		if(v == -47.13){
			am=3.2;
		} else {
			am=0.32*(v+47.13)/(1.0-(exp(-0.1*(v+47.13))));
		}
		bm=0.08*exp(-v/11.0);
		ina.Tmss[vindex] = am/(am+bm);
		ina.Ttaum[vindex] = 1.0/(am+bm);

		/** h-gate for ina **/
		if(v<-40.0){
			ah = 0.135*exp(-(v+80.0)/6.8);
			bh = 3.56*exp(0.079*v)+3.1E+5*exp(0.35*v);
		} else {
			ah = 0.0;
			bh = 1.0/(0.13*(1.0+exp(-(v+10.66)/11.1)));
		}
		ina.Thss[vindex] = ah/(ah+bh);
		ina.Ttauh[vindex] = 1.0/(ah+bh);

		/** j-gate for ina **/
		if(v<-40.0){
			aj = (v+37.78)*(-1.2714E+5*exp(0.2444*v)-3.474E-5*exp(-0.04391*v))/(1.0+exp(0.311*(v+79.23)));
			bj = 0.1212*exp(-0.01052*v)/(1.0+exp(-0.1378*(v+40.14)));
		} else {
			aj = 0.0;
			bj = 0.3*exp(-2.535E-7*v)/(1.0+exp(-0.1*(v+32.0)));
		}
		ina.Tjss[vindex] = aj/(aj+bj);
		ina.Ttauj[vindex] = 1.0/(aj+bj);

		// ik1 
		ik1.Tk1ss[vindex] = 1.0/(1.0+exp(0.07*(v+80.0)));

		// ito
		ao=0.65/(exp(-(v+10.0)/8.5)+exp(-(v-30.0)/59.0));
		bo=0.65/(2.5+exp((v+82.0)/17.0));
		ito.Tass[vindex] = 1.0/(1.0+exp(-(v+20.47)/17.54));
		ito.Ttaua[vindex] = 1.0/(var.K_Q10*(ao+bo));

		ai=1.0/(18.53+exp((v+113.7)/10.95));
		bi=1.0/(35.56+exp(-(v+1.26)/7.44));
		ito.Tiss[vindex] = 1.0/(1.0+exp((v+43.1)/5.3));
		ito.Ttaui[vindex] = 1.0/(var.K_Q10*(ai+bi));

		// ikur
		ua=0.65/(exp(-(v+10)/8.5)+exp(-(v-30)/59.0));
		ub=0.65/(2.5+exp((v+82.0)/17.0));
		ikur.Tass[vindex] = 1.0/(1.0+exp(-(v+30.3)/9.6));
		ikur.Ttaua[vindex] = 1.0/(var.K_Q10*(ua+ub));

		ia=1.0/(21.0+exp(-(v-185.0)/28.0));
		ib=exp((v-158.0)/16.0);
		ikur.Tiss[vindex] = 1.0/(1.0+exp((v-99.45)/27.48));
		ikur.Ttaui[vindex] = 1.0/(var.K_Q10*(ia+ib));
		ikur.Tgkur[vindex] = 0.005+0.05/(1.0+exp(-(v-15.0)/13.0));

		// for ikr 
		ikr.Txrss[vindex] = 1.0/(1.0+exp(-(v+14.1)/6.5));
		if(fabs(v+14.1)<1E-10){
			axr=0.0015;
		} else {
			axr=0.0003*(v+14.1)/(1.0-exp(-(v+14.1)/5.0));
		}
		if(fabs(v-3.3328)<1E-10){
			bxr=3.7836118E-4;
		} else {
			bxr=7.3898E-5*(v-3.3328)/(exp((v-3.3328)/5.1237)-1.0);
		}
		ikr.Ttauxr[vindex] = 1.0/(axr+bxr);
		ikr.Trkr[vindex] = 1.0/(1.0+exp((v+15.0)/22.4));

		// for iks 
		iks.Txsss[vindex] = 1.0/sqrt(1.0+exp(-(v-19.9)/12.7));
		if(fabs(v-19.9)<1E-10){
			axs=0.00068;
		} else {
			axs=4E-5*(v-19.9)/(1.0-exp(-(v-19.9)/17.0));
		}
		if(fabs(v-19.9)<1E-10){
			bxs=0.000315;
		} else {
			bxs=3.5E-5*(v-19.9)/(exp((v-19.9)/9.0)-1.0);
		}
		iks.Ttauxs[vindex] = 0.5/(axs+bxs);

		// for ical
		ical.Tdss[vindex] = 1.0/(1.0+exp(-(v+10.0)/8.0));
		if(fabs(v+10)<1E-10){
			ical.Ttaud[vindex] = 4.579/(1.0+exp(-(v+10.0)/6.24));
		} else {
			ical.Ttaud[vindex] = (1.0-exp(-(v+10)/6.24))/(0.035*(v+10)*(1.0+exp(-(v+10)/6.24)));
		}

		ical.Tfss[vindex] = (exp(-(v+28.0)/6.9))/(1.0+exp(-(v+28.0)/6.9));	// from CellML model
		//ical.Tfss[vindex] = 1.0/(1.0+exp(-(v+28.0)/6.9));	// AJP original
		ical.Ttauf[vindex] = 9.0/(0.0197*exp(-(0.0337)*(0.0337)*(v+10.0)*(v+10.0))+0.02);

		// inak 
		inak.Tknai[vindex] = 0.1245*exp((-0.1*v*F)/(R*T));
		inak.Tknao[vindex] = 0.0365*exp((-1.0*v*F)/(R*T));

		// incx
		ncx.Thca[vindex] = exp(ncx.gamma*v/var.RTonF);
		ncx.Thna[vindex] = exp((ncx.gamma-1.0)*v/var.RTonF);

		// for jrel
		jrel.Twss[vindex] = 1.0-1.0/(1.0+exp(-(v-40.0)/17.0));
		if(fabs(v-7.9)<1E-10){
			jrel.Ttauw[vindex] = 60.2/1.3;
		} else {
			jrel.Ttauw[vindex] = 6.0*(1.0-exp(-(v-7.9)/5.0))/(v-7.9+0.3*(v-7.9)*exp(-(v-7.9)/5.0));
		}

	} //for i loop end

}
