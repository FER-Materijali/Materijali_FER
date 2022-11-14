#include <stdio.h>
#define MAX 10
int main(void){
	char niz[MAX + 1];
	int BrojZnamenki = 0, Brojac = 0, ProvjeraZnamenki = 0;
	gets(niz);
	while(niz[Brojac] != '\0'){
		if((niz[Brojac] < 48) || (niz[Brojac] > 56 && niz[Brojac] < 65) || (niz[Brojac] > 70 && niz[Brojac] < 97) || (niz[Brojac] > 102)){
			ProvjeraZnamenki = 1;
			break;
		}else if(niz[Brojac] >= 48 && niz[Brojac] <= 56){
			BrojZnamenki++;
		}
		Brojac++;
	}
	if(ProvjeraZnamenki == 1){
		printf("Ucitani niz nije ispravno zadan.");
	}else{
		printf("Broj unesenih oktalnih znamenki: %d", BrojZnamenki);
	}
	return 0;
}