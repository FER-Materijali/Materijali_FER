#include <stdio.h>
#define MAX 10

int main(){
	int n, i, j, k;
	float mat[MAX][MAX], pom;

	do{
		printf("Unesi n iz intervala [1,10]: ");
		scanf("%d", &n);
	}while(n<1 || n>10);
	
	k=n;
	printf("\n\n");

	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("Unesi element (%d,%d): ",i+1,j+1);
			scanf("%f", &mat[i][j]);
		}
	}

	for(i=0;i<n;++i){
		pom = mat[i][i];
		mat[i][i]=mat[i][k-1];
		mat[i][k-1]=pom;
		k--;

	}

	printf("\n\nIspis matrice kojoj smo zamijenili elemente:\n\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%6.2f  ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	return 0;
}
