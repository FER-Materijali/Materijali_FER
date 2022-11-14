#include <stdio.h>

int main (void){

float x1, x2;
printf ("Unesite 2 realna broja: ");
scanf ("%f%f", &x1, &x2);

if (x1<x2) printf ("y = %.3f", x1/x2);
else if (x1==x2) printf ("y = %.3f", x1*x1-3);
else  printf ("y = %.3f", 4*x1 + 3*x2);

return 0;
}