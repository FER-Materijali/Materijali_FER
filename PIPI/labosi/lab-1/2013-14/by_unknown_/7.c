#include <stdio.h>

int main (void){

int x;

printf ("Unesite cijeli broj x: ", &x);
scanf ("%d", &x);

if (!(x%6)) printf ("Broj %d je dijeljiv sa 6.\n", x);
else if (x%2 && x%3) printf ("Broj %d nije dijeljiv sa 6 jer nije djeljiv ni sa 2 ni s 3", x);
else if (x%2) printf ("Broj %d nije dijeljiv sa 6 jer nije djeljiv s 2", x);
else printf ("Broj %d nije dijeljiv sa 6 jer nije djeljiv s 3", x);
return 0;
}