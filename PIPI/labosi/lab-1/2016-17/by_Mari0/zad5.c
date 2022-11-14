#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj, jedinica, desetica, stotica, ispis;
	printf("Unesite cijeli troznamenkasti broj: \n");
	scanf("%d", &broj);
	stotica=broj/100;
	desetica=(broj/10)%10;
	jedinica=broj%10;
	ispis=jedinica * stotica * desetica;
	printf("Umnozak znamenaka broja %d je %d. \n", broj, ispis);
	return 0;
	
}
