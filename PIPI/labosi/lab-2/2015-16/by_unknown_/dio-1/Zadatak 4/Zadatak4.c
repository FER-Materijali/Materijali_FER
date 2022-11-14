#include <stdio.h>

int main(void){
	int niz[20], i, Ulaz;
	do{
		scanf("%d", &Ulaz);
	}while((Ulaz < 1) && (Ulaz > 20));
	for(i = 0; i < Ulaz; i++){
		scanf("%d", &niz[i]);
	}
	for(i = 0; i < Ulaz; i++){
		if((niz[i] >= 10) && (niz[i] <= 20)){
			printf("%d", i);
			printf(". %d\n", niz[i]);
		}
	}
	return 0;
}