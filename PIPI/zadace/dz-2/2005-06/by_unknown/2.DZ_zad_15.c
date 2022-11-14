#include <stdio.h>
#define MAX 10


int main(){
	int n,i,j,k;
	float mat1[MAX][MAX], mat2[MAX][MAX], prod[MAX][MAX]={0};

	do{
		printf("Unesi n u intervalu [1,10]: ");
		scanf("%d",&n);
	}while(n<1 || n>MAX);

	printf("\n\nUnesi elemente prve matrice:\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("  Unesi element (%d,%d): ", i+1, j+1);
			scanf("%f", &mat1[i][j]);
		}
	}

	printf("\n\nUnesi elemente druge matrice:\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("  Unesi element (%d,%d): ", i+1, j+1);
			scanf("%f", &mat2[i][j]);
		}
	}

	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			for(k=0;k<n;++k) prod[i][j] += mat1[i][k]*mat2[k][j];
	printf("\n\nRezultat mnozenja matrica:\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("  %6.2f   ", prod[i][j]);
		}
		printf("\n");
	}
	return 0;
}

