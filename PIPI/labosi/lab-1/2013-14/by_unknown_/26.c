#include <stdio.h>

int main (void){

int n,m, min;

printf ("Unesite 2 prirodna broja: ");
scanf ("%d%d", &n, &m);
if (n<m) min=n;

if (!(n%2) && !(m%2)) printf ("Manji parni broj je: %d.", min);
else if ((n%2) && (m%2)) printf ("Niti jedan broj nije paran.");
else {
		if (!(n%2)) printf ("Manji parni broj je: %d.", n);
		else printf ("Manji parni broj je: %d.", m);
	}
return 0;
}
