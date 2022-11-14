#include <stdio.h>

int main (void){

int a,b;

printf ("Unesite dva prirodna broja: ");
scanf ("%d%d", &a, &b);

if (a==b) {
	printf ("Brojevi moraju biti razliciti!");
	return;
	}
	
if (!(a%b) && a>b) printf ("Broj %d je visekratnik broja %d.", b,a);
else if (!(b%a) && b>a) printf ("Broj %d je visekratnik broja %d.", a,b);
else printf ("Niti jedan broj nije visekratnik drugog ucitanog broja");

return 0;
}