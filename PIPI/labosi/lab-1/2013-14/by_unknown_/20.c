#include <stdio.h>

int main (void){

float a, b, c, min, max;
printf ("Unesite tri realna broja: ");
scanf ("%f%f%f", &a, &b, &c);

min=a;
max=c;

if (b<min) min=b;
if (c<min) min=c;
if (a>max) max=a;
if (b>max) max=b;

printf ("Broj %.1f je najmanji, a %.1f najveci od ucitanih brojeva.", min, max);

return 0;
} 