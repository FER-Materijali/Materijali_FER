#include <stdio.h>

int main (void){

int broj;

printf ("Unesite troznamenkasti broj: ");
scanf ("%d", &broj);

printf ("Umnozak znamenaka broja %d je %d.\n", broj, (((broj-broj%100)/100)*((broj%100-broj%10)/10)*(broj%10)));

return 0;
}

/*
Stotica: (broj-broj%100)/100)
Desetica: ((broj%100-broj%10)/10)
Jedinica: (broj%10)
*/