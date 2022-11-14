#include <stdio.h>
#define MAX 5
int main(void){
	char niz[MAX + 1];
	int Ponavljanje = 0, ProvjeraZnamenki = 0, Brojac = 0;
	gets(niz);
	while(niz[Brojac] != '\0'){
		if(niz[Brojac] < 48 || niz[Brojac] > 55){
			ProvjeraZnamenki = 1;
			break;
		}else if(niz[Brojac] == '4'){
			Ponavljanje++;
		}
		Brojac++;
	}
	if(ProvjeraZnamenki == 1){
		printf("Ucitani niz nije ispravno zadan.");
	}else{
		printf("Znamenka 4 se u ucitanom broju pojavljuje %d puta.", Ponavljanje);
	}
	return 0;
}