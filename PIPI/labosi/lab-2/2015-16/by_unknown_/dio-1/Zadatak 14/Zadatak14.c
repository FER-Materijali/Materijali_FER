#include <stdio.h>

int main(void){
	int niz[30] = { 0 }, Ulaz, Brojac = 1;
	do{
		scanf("%d", &Ulaz);
		if(Ulaz >= 1 && Ulaz <= 30){
			if(niz[Ulaz - 1] != 0){
				break;
			}
			niz[Ulaz - 1] = Brojac;
			Brojac++;
		}
	}while(1);
	printf("Broj %d bio je %d. ucitani broj.\nUkupno ucitano brojeva %d", Ulaz, niz[Ulaz - 1], Brojac);
	return 0;
}