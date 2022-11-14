#include<stdio.h>
int main(void){
	int broj, broj2;
	printf("Upisi troznamenkasti prirodni broj:");
	scanf("%d", &broj);
	broj2 = broj - broj%10 - broj/100*100 + broj%10*100 + broj/100;
	printf("Broj dobiven obrnutim poretkom znamenaka broja %d je %d", broj, broj2);
	return 0;
}