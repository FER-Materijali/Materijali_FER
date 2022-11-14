#include <stdio.h>

int main(void){
	int Ulaz, MaxZnamenka = 0;
	do{
		scanf("%d", &Ulaz);
	}while(Ulaz < 100 || Ulaz > 99999);
	printf("U broju %d najveca znamenka je: ", Ulaz);
	while(Ulaz){
		if((Ulaz % 10) > MaxZnamenka){
			MaxZnamenka = Ulaz % 10;
		}
		Ulaz /= 10;
	}
	printf("%d\n", MaxZnamenka);
	return 0;
}