#include <stdio.h>

int main (void){

int broj;

printf ("Unesite prirodni broj: ");
scanf ("%d", &broj);

if (!(broj%3) && (broj%10)!=8) printf ("Broj %d je dijeljiv s 3 i zadnja znamenka mu nije 8.", broj);
else if (!(broj%3) && (broj%10)==8) printf ("Broj %d je dijeljiv s 3 i zadnja znamenka mu je 8.", broj);
else if ((broj%3) && (broj%10)!=8) printf ("Broj %d nije dijeljiv s 3 i zadnja znamenka mu nije 8.", broj);
else if ((broj%3) && (broj%10)==8) printf ("Broj %d nije dijeljiv s 3 i zadnja znamenka mu je 8.", broj);

return 0;
}