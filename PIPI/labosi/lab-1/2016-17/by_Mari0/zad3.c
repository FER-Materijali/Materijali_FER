#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj, srednjaZnamenka;
	printf("Unesite cijeli troznamenkasti broj: \n");
	scanf("%d", &broj);
	srednjaZnamenka=(abs(broj) / 10 ) % 10;
	printf("Srednja znamenka broja %d je %d. \n", broj, srednjaZnamenka);
	return 0;
	
}
