#include <stdio.h>
#define MAX 10

int main(){
	int n, i, j, a, b;
	float mat1[MAX][MAX], mat2[MAX][MAX], pom;

	do{
		printf("Unesi n u intervalu [1,10]: ");
		scanf("%d", &n);
	}while (n<1 || n>10);

	printf("Unesi a i b: ");
	scanf("%d %d", &a, &b);

	for(i=0;i<n;++i){
		for(j=0;j<n;++j) {
			printf("Unesi element (%d,%d) prve matrice: ", i+1, j+1);
			scanf("%f", &mat1[i][j]);
		}
	}
	printf("\n\n");

	for(i=0;i<n;++i){
		for(j=0;j<n;++j) {
			printf("Unesi element (%d,%d) druge matrice: ", i+1, j+1);
			scanf("%f", &mat2[i][j]);
		}
	}


	for(i=0;i<n;++i){
		pom = mat1[a-1][i];
		mat1[a-1][i]= mat2[i][b-1];
		mat2[i][b-1]= pom;
	}

	printf("\n\nIspis prve matrice nakon zamjene: \n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j) {
			printf("%6.2f   ", mat1[i][j]);
		}
		printf("\n");
	}

	printf("\n\nIspis druge matrice nakon zamjene: \n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j) printf("%6.2f   ", mat2[i][j]);
		printf("\n");
	}

	printf("\n\n");
	
	return 0;
}







