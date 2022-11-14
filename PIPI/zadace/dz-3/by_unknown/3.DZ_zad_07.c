#include <stdio.h>
#include <math.h>
#define MAX 100

void funkcija(int *mat, int n, int maxStup, int x){
	int i, j;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(i==x)mat[i*maxStup+j]=1;
			else mat[i*maxStup+j]=0;
		}
	}
}

int main(){
	int mat[MAX][MAX], i, j, rang, x;

	printf("Unesi rang matrice: ");
	scanf("%d", &rang);

	printf("\n\n");

	printf("Unesite u koji redak zelite upisati jedinice: ");
	scanf("%d", &x);

	funkcija(&mat[0][0], rang, MAX, (x-1));
	
	printf("\n\nIspis matrice nakon upisa jedinica u %d. redak i nula u preostale retke:\n", x);
	for(i=0;i<rang;++i){
		for(j=0;j<rang;++j){
			printf("%d  ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	return 0;
}

