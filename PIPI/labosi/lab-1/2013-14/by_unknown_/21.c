#include <stdio.h>

int main (void){

float x;
printf ("Unesite realni broj x: ");
scanf ("%f", &x);

if (x<0) printf ("x= %.2f y= %.2f", x, -1*x);
else if (!x) printf ("x= %.2f y= %.2f", x, x);
else  printf ("x= %.2f y= %.2f", x, 2.0/3*x +3);

return 0;
}