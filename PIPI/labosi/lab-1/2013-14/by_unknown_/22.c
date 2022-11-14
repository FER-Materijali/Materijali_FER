#include <stdio.h>

int main (void){

float x;
printf ("Unesite realni broj x: ");
scanf ("%f", &x);

if (x<0) printf ("x= %.3f y= %.3f", x, 3*x);
else if (x>=1) printf ("x= %.3f y= %.3f", x, x*x+3);
else  printf ("x= %.3f y= %.3f", x, 3.0/4*x +1);

return 0;
}