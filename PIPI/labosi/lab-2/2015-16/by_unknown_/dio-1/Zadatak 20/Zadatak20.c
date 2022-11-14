#include <stdio.h>

int main(void){
	int Ulaz, Rezultat, PrvaZnamenka, ZadnjaZnamenka;
	do{
		scanf("%d", &Ulaz);
	}while(Ulaz < 1 || Ulaz > 99999);
	printf("Broj %d: ", Ulaz);
	ZadnjaZnamenka = Ulaz % 10;
	while(Ulaz){
		PrvaZnamenka = Ulaz;
		Ulaz /= 10;
	}
	Rezultat = PrvaZnamenka - ZadnjaZnamenka;
	if(Rezultat < 0){
		printf("prva znamenka je manja od zadnje.\n");
	}else if(Rezultat == 0){
		printf("prva i zadnja znamenka su jednake.\n");
	}else{
		printf("prva znamenka je veca od zadnje.\n");
	}
	return 0;
}