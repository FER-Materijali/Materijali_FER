#include <stdio.h>
#define MAX 5
int main(void){
	char niz[MAX + 1], PrvaZnamenka, ZadnjaZnamenka;
	int ProvjeraZnamenki = 0, Brojac = 0;
	gets(niz);
	while(niz[Brojac] != '\0'){
		if(niz[Brojac] < 48 || niz[Brojac] > 55){
			ProvjeraZnamenki = 1;
			break;
		}
		Brojac++;
	}
	if(ProvjeraZnamenki == 1){
		printf("Ucitani niz nije ispravno zadan.");
	}else{
		PrvaZnamenka = niz[0];
		ZadnjaZnamenka = niz[Brojac - 1];
		printf("Prva znamenka ucitanog broja je %c\n", PrvaZnamenka);
		printf("Posljednja znamenka ucitanog broja je %c\n", ZadnjaZnamenka);
	}
	return 0;
}