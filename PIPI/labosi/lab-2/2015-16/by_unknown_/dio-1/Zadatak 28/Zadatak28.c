#include <stdio.h>

int main(void){
	int Ulaz, Suma = 0, Brojac = 0, PrviKrivi = 0;
	do{
		scanf("%d", &Ulaz);
		if((Ulaz < 0 || Ulaz > 100) && (Brojac == 0)){
			PrviKrivi = 1;
			break;
		}else if((Ulaz < 0 || Ulaz > 100)){
			break;
		}else if(Ulaz < 50){
			Suma += Ulaz;
		}
		Brojac = 1;
	}while(Ulaz >= 0 || Ulaz <= 100);
	if(PrviKrivi == 1){
		printf("Nije unesen niti jedan broj iz trazenog intervala.");
	}else{
		printf("Zbroj svih unesenih brojeva manjih od 50 je %d.", Suma);
	}
	return 0;
}