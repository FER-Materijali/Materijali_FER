#include <stdio.h>

int main (void){

int broj, znamenka;

	printf ("Unesite broj: ", &broj);
	scanf ("%d", &broj);
	znamenka=((broj-broj%10)/10);
	if (znamenka<0) znamenka*=-1;
	
	if (znamenka!=5) 
		printf ("Prva znamenka broja %d je %d.\n", broj, znamenka);
	else {
		znamenka=broj%10;
		if (znamenka<0) znamenka*=-1;
		printf ("Zadnja znamenka broja %d je %d.\n", broj, znamenka);
	}
	   
	return 0;
}