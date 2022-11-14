#include<stdio.h>

int main(void){

			float x1, x2, y;
			scanf("%f %f", &x1, &x2);
			if((x1<=x2) && (x1*x1)>(x2*x2)) y=x1*x1;
			else if((x1<=x2) && (x1*x1)<(x2*x2))y=x2*x2;
			else if(x1<0) y=-x1;
			else y=x1;
			printf("\r\n y = %.2f", y);
			return 0;
}