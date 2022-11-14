#include <stdio.h>

int main(void){
	int niz[30], n, i;
	do{
		scanf("%d", &n);
	}while(n < 1 || n > 30);
	for(i = 0; i < n; i++){
		scanf("%d", &niz[i]);
		if(niz[i] >= -1 && niz[i] <= 22){
			niz[i] = 0;
		}
	}
	printf("Promijenjeno polje: ");
	for(i = 0; i < n; i++){
		printf("%d ", niz[i]);
	}
	return 0;
}