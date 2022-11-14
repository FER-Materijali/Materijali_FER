#include <stdio.h>

int main(void){
	int Ulaz, i, j;
	do{
		scanf("%d", &Ulaz);
	}while((Ulaz >= 20) && (Ulaz <= 5));
	for(i = 0; i < (Ulaz + 1); i++){
		for(j = 0; j < (i + 1); j++){
			printf("%.1f ", 0.1*j);
		}
		printf("\n");
	}
	return 0;
}