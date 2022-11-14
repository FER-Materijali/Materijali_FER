#include <stdio.h>

int main (void){

int broj1, broj2, op;
printf ("Unesite dva cijela broja: ");
scanf ("%d%d", &broj1, &broj2);
printf ("Unesite \"1\" za zbrajanja ili \"2\" za oduzimanje: ");
scanf ("%d", &op);

if (op==1) printf ("%d + %d = %d", broj1, broj2, broj1+broj2);
else printf ("%d - %d = %d", broj1, broj2, broj1-broj2);

return 0;
}