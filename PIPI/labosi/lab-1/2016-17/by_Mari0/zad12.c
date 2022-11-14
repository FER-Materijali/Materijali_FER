//možda postoji neka jednostavnija forma za rješavanje ovog zadatka, probajte sami :) //
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj1, broj2, operacija, rezultat;
	printf("Unesite 2 cijela: \n");
	scanf("%d %d", &broj1, &broj2);
	printf("Unesite operaciju (1-zbrajanje, 2-oduzimanje manjeg br. od veceg): \n");
	scanf("%d", &operacija);
	if(operacija==1){
		rezultat=broj1+broj2;
		printf("%d + %d = %d", broj1, broj2, rezultat);
	}
	else{
		if(broj1>broj2){
			rezultat=broj1-broj2;
			printf("%d - %d = %d",broj1, broj2, rezultat);
		}
		else{
			rezultat=broj2-broj1;
			printf("%d - %d = %d", broj2, broj1, rezultat);
		}
	}
	return 0;
	
}
