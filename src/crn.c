/* produced by Tsumoto. K 2008.10.27 */

#include <string.h>
#include <stdlib.h>
#include "syspara.h"

FILE *fopen(), *fpin, *fp0, *fp1, *fp2, *fp3;
FILE *fp4, *fp5, *fp6, *fp7, *fp8, *fp9;
int mode = 1;
int P = 2;
int beats = 30;

typedef double Number;

main(argc,argv)
int argc;
char **argv;
{
	int i,w;
	int ii=0;
	double x[NN];
	double t = 0.0;
	double tt,ttt;
	double time=0.0;
	double ttime=0.0;
	double h;
	double v_old,dvdt,dvdt_new;
	char *tmpname;
	char cmd[BUFSIZ];
	double tend;
	double apd,rmbp,vmax,toneapd,ttwoapd,dvdtmax;

/* Action Potential Duration and Max. Info */
/*	double *vmax ; // Max. Voltage (mV)
	double *dvdtmax ; // Max. dv/dt (mV/ms)
	double *apd; // Action Potential Duration
	double *toneapd; // Time of dv/dt Max.
	double *ttwoapd; // Time of 90% Repolarization
	double *rmbp; // Resting Membrane Potential
	double *nair; // Intracellular Na At Rest
	double *cair; // Intracellular Ca At Rest
	double *kir ; // Intracellular K At Rest
	double caimax [beats] ; // Peak Intracellular Ca

	vmax=(Number *)calloc(beats,sizeof(Number));
	dvdtmax=(Number *)calloc(beats,sizeof(Number));
	apd=(Number *)calloc(beats,sizeof(Number));
	toneapd=(Number *)calloc(beats,sizeof(Number));
	ttwoapd=(Number *)calloc(beats,sizeof(Number));
	rmbp=(Number *)calloc(beats,sizeof(Number));
	nair=(Number *)calloc(beats,sizeof(Number));
	cair=(Number *)calloc(beats,sizeof(Number));
	kir=(Number *)calloc(beats,sizeof(Number));
	if(vmax==NULL || dvdtmax==NULL || apd==NULL || toneapd==NULL || ttwoapd==NULL 
		|| rmbp==NULL || nair==NULL || cair==NULL || kir==NULL
		) exit(1);
*/

	tmpname = "temp";

	sprintf(cmd, "/usr/bin/cpp -P %s > %s", argv[1],tmpname);
	if(system(cmd) == -1){
		fprintf(stderr,"cannot open %s\n",argv[1]);
		exit(1);
	}
	if((fpin=fopen(tmpname,"r"))==NULL){
		fprintf(stderr,"cannot open %s\n",argv[1]);
		exit(1);
	}
	if ((fp1 = fopen("para.out","w")) == NULL){
		printf("Can't open File\n");
		exit(1);
	}
	if ((fp2 = fopen("data.out","w")) == NULL){
		printf("Can't open File\n");
		exit(1);
	}
	if ((fp3 = fopen("ndata.out","w")) == NULL){
		printf("Can't open File\n");
		exit(1);
	}

	// parameter inputs
	input_para(fpin);

	if (var.write){
		if ((fp0 = fopen(argv[2],"w"))==NULL){
			fprintf(stderr, "%s cannot open.\n",argv[2]);
			exit(-1);
		}
	}
	if (var.out_data){
		if ((fp4 = fopen("ikr.out","w")) == NULL){
			printf("Can't open File\n");
			exit(1);
		}
		if ((fp5 = fopen("iks.out","w")) == NULL){
			printf("Can't open File\n");
			exit(1);
		}
		if ((fp6 = fopen("ical.out","w")) == NULL){
			printf("Can't open File\n");
			exit(1);
		}
		if ((fp7 = fopen("incx.out","w")) == NULL){
			printf("Can't open File\n");
			exit(1);
		}
		if ((fp8 = fopen("inak.out","w")) == NULL){
			printf("Can't open File\n");
			exit(1);
		}
		if ((fp9 = fopen("jrel.out","w")) == NULL){
			printf("Can't open File\n");
			exit(1);
		}
	}

	xhplot(WINDOW, 700.0, 700.0, WHITE);
	xhplot(DIRECT, 0.0, 0.0, WHITE);

	for (ii = 0; ii < var.datas; ii++){
		long j;
		time = 0.0;
		tend = var.tend[ii];
		for (i = 0; i < NN; i++){ 
			x[i] = var.x0[ii][i];
		}
		h = 1.0 / var.m;
		h *= var.tsign[ii];

		xddp.line_wid = var.line_wid[ii];
		xhplot(LINEATT,0,0,WHITE);
		
		// initial values input.
		val_consts(fp1);
		printf("exit consts\n");
		printf("cell volume=%e\n",M_PI*var.a*var.a*var.length);
		printf("Vcell=%e\n",var.vcell);
		printf("Cm=%e\n",var.acap);
		printf("Istim=%lf\n",var.Istim_base);
				
		// initial values input.
		initial_mem();
		printf("exit memory initialization\n");

		// Tablize exp functions.	
		printf("start tablization\n");
		make_ExpTable();
		printf("finished tablization\n");

		// Initialization time
		var.beat = 0;
		tt = var.ndis*(double)var.m*var.BCL;
		ttt = (1.0-var.ndis)*(double)var.m*var.BCL;
		printf("tt=%lf,ttt=%lf\n",tt,ttt);

		while (1){
			eventloop(fp1,&mode,&P,x);
			time = var.beat*var.BCL;
			
			apd = 0.0; toneapd = 0.0; ttwoapd = 0.0; rmbp = x[0]; vmax = -90.0; dvdtmax = 0.0, v_old = x[0];
			for (j = 0; j< (int)tt; j++){
				t = h*(double)j;
				v_old=x[0];
				var.Istim = var.Istim_base;

				if (var.deb==1){
					printf("%d %lf %lf %lf %lf\n",var.beat,apd,toneapd,ttwoapd,rmbp);
					printf("%lf %lf %f %f %e ", x[0],x[1],x[2],x[3],x[4]);
					printf("%lf %lf %f %f %e ", x[5],x[6],x[7],x[8],x[9]);
					printf("%lf %e %lf %lf %lf ", x[10],x[11],x[12],x[13],x[14]);
					printf("%lf %e %lf %lf %lf %lf\n", x[15],x[16],x[17],x[18],x[19],x[20]);
					printf("time=%lf,Istim=%lf\n",time,var.Istim);
					printf("dvdtmax[%d]=%lf\n",var.beat,dvdt);
					printf("ENa=%lf, EK=%lf ECa=%lf\n", var.Ena,var.Ek,var.Eca);
				}

				eular(NN,h,x,t);
				
				dvdt_new = (x[0]-v_old)/h;
				if (x[0] > vmax) vmax = x[0];
				if (dvdt_new > dvdtmax ){
						dvdtmax = dvdt_new;
						toneapd = time;
				}
				if (dvdt_new < 0.0 && x[0] >= (vmax -0.9*(vmax-rmbp))) ttwoapd = time;
				
				if (var.pflag) orbit(&mode,x,dvdt_new);
				if(var.pswitch == 1){
					if (j%10==0){
						data_out(fp2,time,x);
						if(var.out_data){
							current(fp4,fp5,fp6,fp7,fp8,fp9,ttime,x);
						}
					}
				}
			
				time += h;
				ttime = time;
			} // end 1st loop

			for (j = 0; j< (int)ttt; j++){
				t = h*(double)j;
				v_old=x[0];
				var.Istim = 0.0;

				if (var.deb==1){
					printf("%d %lf %lf %lf %lf\n",var.beat,apd,toneapd,ttwoapd,rmbp);
					printf("%lf %lf %f %f %e ", x[0],x[1],x[2],x[3],x[4]);
					printf("%lf %lf %f %f %e ", x[5],x[6],x[7],x[8],x[9]);
					printf("%lf %e %lf %lf %lf ", x[10],x[11],x[12],x[13],x[14]);
					printf("%lf %e %lf %lf %lf %lf\n", x[15],x[16],x[17],x[18],x[19],x[20]);
					printf("time=%lf,Istim=%lf\n",time,var.Istim);
					printf("dvdtmax[%d]=%lf\n",var.beat,dvdt);
					printf("ENa=%lf, EK=%lf ECa=%lf\n", var.Ena,var.Ek,var.Eca);
				}

				eular(NN,h,x,t);
				
				dvdt_new = (x[0]-v_old)/h;
				if (x[0] > vmax) vmax = x[0];
				if (dvdt_new > dvdtmax ){
						dvdtmax = dvdt_new;
						toneapd = time;
				}
				if (dvdt_new < 0.0 && x[0] >= (vmax -0.9*(vmax-rmbp))) ttwoapd = time;
				
				if (var.pflag) orbit(&mode,x,dvdt_new);
				if(var.pswitch == 1){
					if (j%10==0){
						data_out(fp2,time,x);
						if(var.out_data){
							current(fp4,fp5,fp6,fp7,fp8,fp9,ttime,x);
						}
					}
				}
			
				time += h;
				ttime = time;
			} // end 2nd loop

			fprintf(fp3,"#beats=%d\n",var.beat);
			for(w=0;w<NN;w++){
				fprintf(fp3,"%16.15e\n",x[w]);
			}
			
			if(var.sswitch==1){
				printf("%d %lf ",var.beat,time);
				for(w=0;w<NN+1;w++){
					if(w!=NN){
						printf("%10.9lf ",x[w]);
					} else {
						printf("/ %10.9lf\n",ttwoapd - toneapd);
						fprintf(fp1,"APD90=%lf\n",ttwoapd-toneapd);
					}
				}
			}

			draw_p(&mode,P,x,dvdt);
			mouse(&mode,x,dvdt);
			if (fabs(time) > tend &&  tend != 0.0) break;
			var.beat++;

		} // end while loop

	} // end for ii-loop

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	if(var.out_data){
		fclose(fp4);fclose(fp5);fclose(fp6);fclose(fp7);fclose(fp8);fclose(fp9);
	}
	closed_mem();

} // end main

