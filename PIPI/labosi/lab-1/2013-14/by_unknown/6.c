#include<stdio.h>

int main(void){

			unsigned int x, y, a, b, c, d;
			scanf("%u %u", &x, &y);
			a=x%10;
			b=x/10;
			c=y%10;
			d=y/10;
			if((a+b)>(c+d)) printf("\r\n Broj %u ima vecu sumu znamenaka od broja %u", x, y);
			else if ((a+b)<(c+d)) printf("\r\n Broj %u ima vecu sumu znamenaka od broja %u", y, x);
			else if ((a+b)==(c+d)) printf ("\r\n Brojevi %u i %u imaju jednaku sumu znamenaka", x, y);
			return 0;
}
				