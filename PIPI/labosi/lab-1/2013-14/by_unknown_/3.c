#include <stdio.h>

int main (void){

int broj, znamenka;

	printf ("Unesite broj: ", &broj);
	scanf ("%d", &broj);
	znamenka=(broj%100-broj%10)/10;
	if (znamenka<0) znamenka*=-1;
	
		if (znamenka<0) znamenka*=-1;
		printf ("Zadnja znamenka broja %d je %d.\n", broj, znamenka);
	
	   
	return 0;
}