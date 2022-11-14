#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj, jedinica, desetica, stotica, noviBroj;
	printf("Unesite troznamenkasti prirodni broj: \n");
	scanf("%d", &broj);
	jedinica=broj%10;
	desetica=(broj/10)%10;
	stotica=broj/100;
	noviBroj=stotica + desetica*10 + jedinica*100;
	if(noviBroj==broj){
		printf("Broj %d je palindrom. \n", broj);
	}
	else
		printf("Broj %d nije palindrom. \n", broj);
	return 0;
	
}
