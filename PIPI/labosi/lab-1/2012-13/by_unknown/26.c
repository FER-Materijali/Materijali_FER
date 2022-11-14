#include <stdio.h>
#include <math.h>
#define MAX 61
int main() {
	int broj, brojac[MAX]={0};
	int i;
	do{
		scanf("%d", &broj);
		if(broj>=-30 && broj<=30){
			brojac[broj+30]++;
			if(brojac[broj+30]==3){
				printf("Broj koji se procitao 3 puta: %d\n", broj);
				break;
			}
		}
		else {
			printf("Ucitali ste broj izvan zadanog intervala.\n"); break;
		}
	}while(1);
	return 0;
}