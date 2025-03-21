#include <string.h>
#include "syspara.h"

void eventloop(FILE *fp1,int *mode, int *P,double m[])
{
	int i;
		
	xhplot(KEYIN,0,0,WHITE);
	if (xddpret.key != -1){
		switch (xddpret.key){
			case 'e':
				if(*mode==1){
					xhplot(CLS, m[0],m[1],BLACK);
					xhplot(FRAME, m[0],m[1],WHITE);
				}
				if(*mode==2){
					xhplot(CLS, m[0],m[2],BLACK);
					xhplot(FRAME, m[0],m[2],WHITE);
				}
				if(!*mode){
					xhplot(CLS, m[0],m[1],BLACK);
					xhplot(FRAME, m[0],m[1],WHITE);
				}
				break;
			case 'A':
				rategk1 += dIstim;
				printf("GK1 = %lf\n",rategk1*Gk1);
				fflush(stdout);
				break;
			case 'a':
				rategk1 -= dIstim;
				printf("GK1 = %lf\n",rategk1*Gk1);
				fflush(stdout);
				break;
			case 'f':
				var.pflag = 1 - var.pflag;
				break;
			case 'g':
				switch(*P){
				case 2 : 
					*P = 8;
					fprintf(stderr,"fixed point is doted\n");
					printf("P=%d\n",*P);
					break;
				case 8 : 
					*P = 2;
					fprintf(stderr,"fixed point is not doted\n");
					printf("P=%d\n",*P);
					break;
				}
				break;
			case 'q':
				printf("quit\n");
				exit(0);
				break;
			case 's':
				printf("\nStatus\n");
				printf("%lf %lf %f %f %f\n", m[0],m[1],m[2],m[3],m[4]);
				printf("%lf %lf %f %f %f\n", m[5],m[6],m[7],m[8],m[9]);
				printf("%lf %lf %f %f %f\n", m[10],m[11],m[12],m[13],m[14]);
				printf("%lf %lf %f %f %f %f\n", m[15],m[16],m[17],m[18],m[19],m[20]);
				fflush(stdout);
				var.pswitch = 1 - var.pswitch;
				if(var.pswitch == 1){
					printf("Current data output\n");
				} else {
					printf("Current data output stop\n");
				}
				break;
			case '1':
				for(i=0;i<NN;i++){fprintf(fp1,"%10.8lf\n",m[i]);}
				fflush(fp1);
				printf("stored in para.out\n");
				break; 
			case ' ':
				//mode = 1 - mode;
				printf("\n");
				*mode+=1;
				if(*mode==1)
					printf("### Now plane is Vm, m ###\n");
				if(*mode==2)
					printf("### Now plane is Vm, h ###\n");
				if(*mode>2){
					*mode=1; 
					printf("### Now plane is Vm, m ###\n");
					printf("\n");
					printf(" a:   Istim\n");
					printf(" e:   clear\n");
					printf(" f:   change\n");
					printf(" g:   small <-> big\n");
					printf(" s:   state\n");
					printf("space: Vm,m <-> Vm,h \n");
					printf("\n");
					break;
				}
		}
	}
}
