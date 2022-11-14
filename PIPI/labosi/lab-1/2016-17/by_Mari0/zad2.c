#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj, jedinica, desetica, ispis;
	printf("Unesite cijeli dvoznamenkasti broj: \n");
	scanf("%d", &broj);
	jedinica=abs(broj)%10;
	desetica=abs(broj)/10;
	if(desetica != 5){
		ispis=desetica;
		printf("Prva znamenka broja %d je %d. \n", broj, ispis);
	}
	else{
		ispis=jedinica;
		printf("Zadnja znamenka broja %d je %d. \n", broj, jedinica);
	}
	return 0;
	
}
