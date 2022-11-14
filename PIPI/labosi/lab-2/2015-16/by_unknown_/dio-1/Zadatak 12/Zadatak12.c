#include <stdio.h>

int main(void){
	int niz[60] = { 0 }, Ulaz, Brojac = 0;
	do{
		scanf("%d", &Ulaz);
		Brojac++;
		if(Ulaz < -30 || Ulaz > 30){
			break;
		}else{
			niz[Ulaz + 30]++;
		}
		if(niz[Ulaz + 30] == 3){
			break;
		}
	}while(1);
	printf("Ukupno je ucitano %d brojeva", Brojac);
	return 0;
}