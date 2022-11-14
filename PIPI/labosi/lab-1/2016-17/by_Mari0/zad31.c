#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj1, broj2, zbroj;
	float aritmetickaSredina, izracunataVrijednost;
	printf("Unesite 2 cijela broja razlicita od 0: \n");
	scanf("%d %d", &broj1, &broj2);
	zbroj=broj1+broj2;
	if(zbroj>0){
		aritmetickaSredina=(float)(broj1+broj2)/2;
		printf("Aritmeticka sredina brojeva %d i %d : %.4f \n", broj1, broj2, aritmetickaSredina);
	}
	else{
		izracunataVrijednost=fabs(1./broj1 + 1./broj2);
		printf("Izracunata vrijednost: %.4f", izracunataVrijednost);
	}
	return 0;
	
}
