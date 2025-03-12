#include <string.h>
#include "syspara.h"

void orbit(int *mode, double m[])
{
	if(*mode==1)   xhplot(PSET,m[9],m[0],CYAN);
	if(*mode==2)   xhplot(PSET,m[9],m[0],MAGENTA);
} 

void draw_p(int *mode, int P, double x[])
{
	switch(*mode){
		case 1:
			xhplot(P, x[9],x[0],YELLOW);
			xhplot(POINT,x[9],x[0],WHITE);
			break;
		case 2:	
			xhplot(P, x[9],x[0],RED);
			xhplot(POINT,x[9],x[0],WHITE);
			break;
	}
}

void mouse(int *mode, double x[])
{
	if (!xddpret.key){
		switch(*mode){
			case 1:	x[9] = xddpret.x; x[0] = xddpret.y; break;
			case 2:	x[9] = xddpret.x; x[0] = xddpret.y; break;
		}
	}
}

