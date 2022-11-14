#include <stdio.h>
#define MAX 5
int main(void){
	char niz[MAX + 1];
	int ProvjeraZnamenki = 0, NajvecaZnamenka = 0, Brojac = 0;
	gets(niz);
	while( niz[Brojac] != '\0'){
		if((niz[Brojac] < 48) || (niz[Brojac] > 58 && niz[Brojac] < 65) || (niz[Brojac] > 70 && niz[Brojac] < 97) || (niz[Brojac] > 102)){
			ProvjeraZnamenki = 1;
			break;
		}if(niz[Brojac] > NajvecaZnamenka){
			NajvecaZnamenka = niz[Brojac];
		}
		Brojac++;
	}
	if(ProvjeraZnamenki == 1){
		printf("Ucitani niz nije ispravno zadan.");
	}else{
		printf("Najveca heksadekadska znaenka u ucitanom broju je %c", NajvecaZnamenka);
	}
	return 0;
}