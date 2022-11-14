#include <stdio.h>

int main(void){
	int Ulaz, Najveci = 0, Najmanji = 100, Suma = 0, Brojac = 0, PrviKrivi = 0;
	do{
		scanf("%d", &Ulaz);
		if((Ulaz < 0 || Ulaz > 100) && (Brojac == 0)){
			PrviKrivi = 1;
			break;
		}else if((Ulaz < 0 || Ulaz > 100)){
			break;
		}else if((Ulaz % 4 == 0) && (Ulaz > Najveci)){
			Najveci = Ulaz;
		}else if((Ulaz % 4 == 0) && (Ulaz < Najmanji)){
			Najmanji = Ulaz;
		}
		Brojac = 1;
	}while((Ulaz >= 0) && (Ulaz <= 100));
	if(PrviKrivi == 1){
		printf("Nije unesen niti jedan broj iz trazenog intervala.");
	}else{
		Suma = Najveci + Najmanji;
		printf("Zbroj najveceg (%d) i najmanjeg (%d) unesenog broja djeljivog s 4 je %d.", Najveci, Najmanji, Suma);
	}
	return 0;
}