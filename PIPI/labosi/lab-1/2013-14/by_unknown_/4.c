#include <stdio.h>

int main (void){

int N;

do{
	printf ("Unesite prirodan broj N: ");
	scanf ("%d", &N);
} while (N<=0);

if (N%2) printf ("Broj %d je neparan.", N);
else printf ("Broj %d je paran.",N);

return 0;

}

/* Uvijet u programu ne kontrolira je li uneseni broj realan!
Ako se unese realan broj tada fca scanf cita taj broj do 
decimalne tocke*/