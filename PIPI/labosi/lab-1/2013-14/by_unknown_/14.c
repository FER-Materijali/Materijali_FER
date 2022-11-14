#include <stdio.h>

int main (void){

int m,n, jedinica;

printf ("Unesite dva prirodna broja: ");
scanf ("%d%d", &m, &n);
jedinica=n%10;

if (!jedinica){
	printf ("Dijeljenje nije moguce!");
	return;
	}
printf ("%d / %d = %3.2f", m, jedinica, 1.*m/jedinica);

return 0;
}