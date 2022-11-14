#include <stdio.h>

int main (void){

int broj;
short stotica, desetica, jedinica;

printf ("Unesite troznamenkasti broj: ");
scanf ("%d", &broj);
stotica =(broj-broj%100)/100;
desetica=(broj%100-broj%10)/10;
jedinica=broj%10;
printf ("Broj dobiven obrnutim poretkom znamenaka broja %d je %d%d%d.\n", broj, jedinica, desetica, stotica);

return 0;
}