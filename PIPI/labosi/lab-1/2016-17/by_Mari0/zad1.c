#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj, jedinica, desetica, stotica, ispis;
	printf("Unesite jedan troznamenkasti broj: \n");
	scanf("%d", &broj);
	jedinica=broj%10;
	desetica=(broj/10)%10;
	stotica=broj/100;
	if(jedinica<5){
		ispis=jedinica;
		printf("Zadnja znamenka broja %d je %d. \n", broj, jedinica);	
	}
	else{
		ispis=desetica * 10 + jedinica;
		printf("Zadnje dvije znamenke broja %d su %d. \n", broj, ispis);
	}
	return 0;
	
}
