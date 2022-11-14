#include <stdio.h>

int main (void){

int broj1, broj2, temp1, temp2;

printf ("Unesite dva prirodna broj: ");
scanf ("%d%d", &broj1, &broj2);
temp1=((broj1%100-broj1%10)/10)*(broj1%10);
temp2=((broj2%100-broj2%10)/10)*(broj2%10);

if (temp1>temp2) printf ("Broj %d ima vecu sumu znamenaka od broja %d", broj1, broj2);
else if (temp1<temp2) printf ("Broj %d ima vecu sumu znamenaka od broja %d", broj2, broj1);
else printf ("Brojevi %d i %d imaju jednaku sumu znamenaka", broj1, broj2);

return 0;
}