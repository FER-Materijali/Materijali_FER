#include <stdio.h>

int main(void){
	int niz[39] = {0}, Ulaz, i, Brojac = 0;
	do{
		scanf("%d", &Ulaz);
		if(Ulaz < 1 || Ulaz > 40){
			break;
		}else if(niz[Ulaz - 1] == 0){
			niz[Ulaz - 1] = ++Brojac;

		}
	}while(1);
	for(i = 0; i < 39; i++){
		if(niz[i] != 0){
			printf("Broj %d: %d\n", (i + 1), niz[i]);
		}
	}
	return 0;
}