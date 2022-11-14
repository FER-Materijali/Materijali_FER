#include <stdio.h>

int main (void){

int broj, Abroj;
short stotica, desetica, jedinica;

printf ("Unesite troznamenkasti broj: ");
scanf ("%d", &broj);
stotica =(broj-broj%100)/100;
desetica=(broj%100-broj%10)/10;
jedinica=broj%10;

Abroj=stotica*stotica*stotica+jedinica*jedinica*jedinica+desetica*desetica*desetica;

if (broj==Abroj) printf ("Broj %d je Armstrongov broj.", broj);
else printf ("Broj %d nije Armstrongov broj.", broj);

return 0;
}