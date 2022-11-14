#include <stdio.h>
#define MAX 100


int zbroj(int *mat, int n, int maxstup){
	int i, j, suma=0;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(i==j) continue;
			else suma+=mat[i*maxstup+j];
		}
	}
	return suma;
}


int main(){
	int i, j, n, x;
	int mat[MAX][MAX];

	printf("Unesi rang matrice: ");
	scanf("%d", &n);
	printf("\n\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("Unesi element (%d,%d): ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}

	printf("\n\nIspis matrice:\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%4d  ", mat[i][j]);
		}
		printf("\n");
	}

	x=zbroj(mat, n, MAX);
	
	printf("\n\n");
	printf("Zbroj elemenata matrice (bez dijagonale) iznosi: %d", x);
	printf("\n\n");

	return 0;
}