#include <stdio.h>
#define MAX 10

int main(){
	int n,i,j,pom, ind=0;
	int mat1[MAX][MAX], mat2[MAX][MAX], brojac[MAX]={0};

	do{
		printf("Unesi n iz intervala [1,10]: ");
		scanf("%d", &n);
	}while(n<1 || n>10);

	printf("\n\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("Unesi element (%d,%d) prve matrice: ", i+1, j+1);
			scanf("%d", &mat1[i][j]);
		}
	}

	printf("\n\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("Unesi element (%d,%d) druge matrice: ", i+1, j+1);
			scanf("%d", &mat2[i][j]);
			if(mat2[i][j] == mat1[i][j]) brojac[j]++;
		}
	}

	printf("\n\nIspis prve matrice:\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%6d ", mat1[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nIspis druge matrice:\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%6d ", mat2[i][j]);
		}
		printf("\n");
	}

	pom=brojac[0];
	for(i=0;i<n;++i){
		if(brojac[i]>pom){
			pom=brojac[i];
			ind=i;
		}
	}

	printf("\n\nMatrice su najslicije u %d. stupcu.\n\n", ind+1);

	return 0;
}



