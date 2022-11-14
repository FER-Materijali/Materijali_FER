#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159

int main(void){
	
	float duljinaKraka, povrsinaTrokuta, povrsinaKruga;
	printf("Unesite duljinu kraka pravokutnog jednakokracnog trokuta: \n");
	scanf("%f", &duljinaKraka);
	if(duljinaKraka<=0){
		printf("Duljina stranice mora biti pozitivan broj. \n");
	}
	else{
		povrsinaKruga=PI*pow(duljinaKraka,2);
		povrsinaTrokuta=pow(duljinaKraka,2)/2;
		printf("Povrsina trokuta: %.2f \nPovrsina kruga: %.2f \n", povrsinaTrokuta, povrsinaKruga);
	}
	return 0;
	
}
