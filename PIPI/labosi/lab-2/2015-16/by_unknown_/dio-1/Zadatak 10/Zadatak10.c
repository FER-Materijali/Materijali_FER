#include <stdio.h>

int main(void){
	int niz[20], n, i, Zbroj = 0;
	do{
		scanf("%d", &n);
	}while(n < 1 || n > 20);
	for(i = 0; i < n; i++){
		scanf("%d", &niz[i]);
		if(niz[i] >= -10 && niz[i] <= 10){
			Zbroj += niz[i];
			niz[i] = 0;
		}
	}
	printf("Zbroj vrijednosti promjenjenih elemenata: %d", Zbroj);
	return 0;
}