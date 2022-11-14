#include <stdio.h>

int main (void){

float x1, x2, max;
printf ("Unesite 2 realna broja: ");
scanf ("%f%f", &x1, &x2);

max=x1*x1;
if (x2*x2>max) max=x2*x2;
if (x1>x2) {
	if (x1<0) x1*=-1;
	printf ("y = %.2f", x1);
	}
else printf ("y = %.2f", max);


return 0;
}