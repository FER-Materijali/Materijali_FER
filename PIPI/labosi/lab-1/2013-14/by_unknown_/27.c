#include <stdio.h>

int main (void){

int n,m;
int temp1, temp2;

printf ("Unesite dva prirodna broja: ");
scanf ("%d%d", &n, &m);

temp1=n*10+m;
temp2=m*10+n;

if (!(temp1%2) && !(temp2%2)) printf ("Parni brojevi kreirani od znamenaka %d i %d: %d %d", n,m,temp1,temp2);
else if (temp1%2 && temp2%2) printf ("Parni brojevi kreirani od znamenaka %d i %d: -", n,m);
else 
	if (!(temp1%2)) printf ("Parni brojevi kreirani od znamenaka %d i %d: %d", n,m,temp1);
	else printf ("Parni brojevi kreirani od znamenaka %d i %d: %d", n,m,temp2);

return 0;
}
