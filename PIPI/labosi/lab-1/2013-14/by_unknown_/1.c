#include <stdio.h>

int main (void){

int broj, znamenka;

	printf ("Unesite troznamenkasti broj: ");

	scanf ("%d", &broj);
	znamenka=broj%10;
	if (znamenka<0) znamenka*=-1;
	
	if (znamenka<5) printf("Zadnja znamenka broja %d je %d.\n", broj, znamenka);
	
	else{
	znamenka=broj%100;
	if (znamenka<0) znamenka*=-1;
	printf("Zadnja dvije znamenke broja %d su %d", broj, znamenka);
	}
	return 0;
}