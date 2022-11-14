#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj, jedinica, desetica, stotica, noviBroj;
	printf("Unesite cijeli troznamenkasti broj: \n");
	scanf("%d", &broj);
	jedinica=broj%10;
	desetica=(broj/10) %10;
	stotica=broj/100;
	noviBroj=stotica + desetica*10 + jedinica*100;
	printf("Broj dobiven obrnutim poretkom znamenaka broja %d je %d. \n", broj, noviBroj);
	return 0;
	
}
