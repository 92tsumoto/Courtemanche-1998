#include "syspara.h"

void data_out(FILE *fp2, double t, double u[])
{

	fprintf(fp2,"%e %e %e %e %10.9e %e %e %e\n",
		t,u[0],u[16],u[17],u[18],u[19],u[20],Itotal);

}

void current(FILE *fp4, FILE *fp5, FILE *fp6, FILE *fp7, FILE *fp8, FILE *fp9, double t, double u[])
{

	out_ikr(fp4,t,u);
	out_iks(fp5,t,u);
	out_ical(fp6,t,u);
	out_inaca(fp7,t,u);
	out_inak(fp8,t,u);
	out_cicr(fp9,t,u);

}

// L-type calcium current
void out_ical(FILE *fp6, double time, double p[])
{
	fprintf(fp6,"%e %e %e %e %e\n",time,Ical,p[10],p[11],p[12]);
}

// Rapidly Activating Potassium Current 
void out_ikr (FILE *fp4, double time, double p[])
{
	fprintf(fp4,"%lf %lf\n",time,Ikr);
}

// Slowly Activating Potassium Current 
void out_iks (FILE *fp5, double time, double p[])
{
	fprintf(fp5,"%lf %lf\n",time,Iks);
}

// Sodium-Calcium Exchanger
void out_inaca (FILE *fp7, double time, double p[])
{
	fprintf(fp7,"%lf %lf\n",time,INCX);
}

// Sodium-Potassium Pump
void out_inak (FILE *fp8, double time, double p[])
{
	fprintf(fp8,"%lf %lf\n",time,INaK);
}

// Ca release from junctional SR
void out_cicr (FILE *fp9, double time, double p[])
{
	fprintf(fp9,"%e %e %e %e %e %e %e %e\n",time,Jrel,Fn,p[13],p[14],p[15],vss,uss);
}

