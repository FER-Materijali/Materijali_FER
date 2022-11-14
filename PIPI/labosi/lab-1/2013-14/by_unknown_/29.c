#include <stdio.h>
#define PI 3.14159

int main (void){

float o1, o2;

printf ("Unesite opseg kruga i opseg kvadrata: ");
scanf ("%f%f", &o1, &o2);

printf ("Polumjer kruga    =   %.3f\n", o1/(2*PI));
printf ("Stranica kvadrata =   %.3f\n", o2/4);
if ((o1/(2*PI))>(o2/4)) printf ("Krug nije moguce smjestiti unutar kvadrata.");
else printf ("Krug je moguce smjestiti unutar kvadrata.");

return 0;
}