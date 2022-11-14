#include <stdio.h>
#include <math.h>
#define MAX 50
int main() {
	int broj, brojac[MAX]={0};
	int i, j=0;
	do{
		scanf("%d", &broj);
		j++;
		if(broj>=1 && broj<=50){
			brojac[broj]++;
			if(brojac[broj]==6){
				printf("Broj koji se procitao 6 puta: %d\n", broj);
				break;
			}
		}
		else {
			printf("Ucitali ste broj izvan zadanog intervala.\n"); break;
		}
	}while(1);
	printf("Ukupno je procitano %d brojeva.\n", j);
	return 0;
}