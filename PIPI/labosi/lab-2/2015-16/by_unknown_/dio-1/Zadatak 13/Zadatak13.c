#include <stdio.h>

int main(void){
	int niz[29] = { 0 }, Ulaz, i;
	do{
		scanf("%d", &Ulaz);
		if(Ulaz < 1 || Ulaz > 30){
			break;
		}else{
			niz[Ulaz - 1]++;
		}
	}while(1);
	for(i = 0; i < 29; i++){
		if(niz[i] > 1){
			printf("Broj %2d: %d\n", (i + 1), niz[i]);
		}
	}
	return 0;
}