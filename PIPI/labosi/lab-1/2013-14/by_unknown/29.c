#include<stdio.h>
#define PI 3.14159

int main(void){

			float x, y, a, b;
			scanf("%f %f", &x, &y);
			a=x/(2*PI);
			b=y/4;
			if((a*2)>b) printf("\r\n Polumjer kruga = %.3f\r\n Stranica kvadrata = %.3f\r\n Krug nije moguce smjestiti unutar kvadrata.", a, b);
			else printf("\r\n Polumjer kruga = %.3f\r\n Stranica kvadrata = %.3f\r\n Krug je moguce smjestiti unutar kvadrata.", a, b);
			return 0;
}