#include <stdio.h>

int main (void){

int broj;
short stotica, jedinica;

printf ("Unesite troznamenkasti broj: ");
scanf ("%d", &broj);
stotica =(broj-broj%100)/100;
jedinica=broj%10;


if (jedinica==stotica) printf ("Broj %d je palindrom.", broj);
else printf ("Broj %d nije palindrom.", broj);

return 0;
}