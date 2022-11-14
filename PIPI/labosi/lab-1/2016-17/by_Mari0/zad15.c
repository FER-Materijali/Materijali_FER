#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	
	int broj, sati, minute, sekunde;
	printf("Unesite jedan prirodan broj koji predstavlja broj sekundi: \n");
	scanf("%d", &broj);
	sati=broj/3600;
	minute=(broj/60)%60;
	sekunde=broj%60;
	printf("sekunde %d = sati-minute-sekunde: %d-%d-%d", broj, sati, minute, sekunde);
	return 0;
	
}
