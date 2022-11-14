#include <stdio.h>
#include <math.h>
#define MAX 100
int main() {
	int broj, brojac[MAX]={0};
	int i;
	do{
		scanf("%d", &broj);
		if(broj>=1 && broj<=100){
			brojac[broj]++;
			if(brojac[broj]==5){
				printf("Broj koji se procitao 5 puta: %d\n", broj);
				break;
			}
		}
		else {
			printf("Ucitali ste broj izvan zadanog intervala.\n"); break;
		}
	}while(1);
	return 0;
}