#include <stdio.h>

int main(void){
	int niz1[15], niz2[15] = { 0 }, Brojac = 0, n, i;
	do{
		scanf("%d", &n);
	}while(n < 1 || n > 15);
	for(i = 0; i < n; i++){
		scanf("%d", &niz1[i]);
		if(niz1[i] >= -10 && niz1[i] <= 15){
			niz2[Brojac] = niz1[i];
			Brojac += 1;
		}
	}
	printf("Novo polje: ");
	for(i = 0; i < Brojac; i++){
		printf("%d ", niz2[i]);
	}
	return 0;
}