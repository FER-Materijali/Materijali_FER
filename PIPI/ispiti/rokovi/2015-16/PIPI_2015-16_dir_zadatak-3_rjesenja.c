#include <stdio.h>
#define MAX 10

int kopiraj(int *niz, int *polje, int m, int n, int maxstup, int broj){
	int i, j, k=0, brojac=0;
	for(i=0; i<m; ++i){
		for(j=0; j<n; ++j, ++k, --broj){
			if(broj==0)
				break;
			else
				*(polje+i*maxstup+j)=niz[k];
		}
	}
	if(broj==0){
		for(i; i<m; ++i){
			for(j; j<n; ++j){
				*(polje+i*maxstup+j)=0;
				++brojac;
			}
		}
		return brojac;
	}
	else
		return 0;
}

int main (void){
	int brel, polje[MAX][MAX], broj, i, j, niz[30];
	scanf("%d", &brel);
	for(i=0; i<brel; ++i)
		scanf("%d", &niz[i]);
	broj=kopiraj(niz, polje, 4, 5, MAX, brel);
	for(i=0; i<4; ++i){
		for(j=0; j<5; ++j)
			printf("%d ", polje[i][j]);
		printf("\n");
	}
	printf("\n%d", broj);
	return 0;
}