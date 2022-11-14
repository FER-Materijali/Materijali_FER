#include<stdio.h>

int main(void){

			float a, b, c, x, y;
			scanf("%f %f %f", &a, &b, &c);
			x=a;
			y=b;
			if(c<x) x=c;
			if(b<x) x=b;
			if(a>y) y=a;
			if(c>y) y=c;
			printf("\r\n Broj %.2f je najmanji, a %.2f najveci od ucitanih brojeva.", x, y);		
			return 0;
}