#include <stdio.h>

int main(void){
	int niz[10] = { 0 }, Ulaz, Suma = 0, i;
	do{
		scanf("%d", &Ulaz);
	}while(Ulaz < 1 || Ulaz > 99999);
	printf("Broj %d -suma znamenaka koje se jednom pojavljuju: ", Ulaz);
	while(Ulaz){
		niz[Ulaz % 10]++;
		Ulaz /= 10;
	}
	for(i = 0; i < 10; i++){
		if(niz[i] == 1){
			Suma += i;
		}
	}
	printf("%d\n", Suma);
	return 0;
}