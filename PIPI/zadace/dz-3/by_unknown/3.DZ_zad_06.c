#include <stdio.h>
#include <math.h>
#define MAXRED 100
#define MAXSTUP 150

void funkcija(int *mat, int brRed, int brStup, int maxStup, int *pom){
	int i, j;
	for(i=0;i<brRed;++i){
		for(j=0;j<brStup;++j){
            pom[i]+=mat[i*maxStup+j];
		}
		pom[i]/=brStup;
	}
}



int main(){
	int mat[MAXRED][MAXSTUP], i, j, red, stup;
	int pom[MAXRED]={0};

	printf("Unesi broj redaka: ");
	scanf("%d", &red);
	printf("Unesi broj stupaca: ");
	scanf("%d", &stup);
	printf("\n\n");

	for(i=0;i<red;++i){
		for(j=0;j<stup;++j){
			printf("Unesi element (%d,%d): ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	printf("\n\nIspis ulazne matrice:\n");
	for(i=0;i<red;++i){
		for(j=0;j<stup;++j){
			printf("%5d  ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	funkcija(&mat[0][0], red, stup, MAXSTUP, &pom[0]);

	printf("\n\nIspis matrice sa aritmetickim sredinama redaka ulazne matrice:\n");
	for(i=0;i<red;++i){
			printf("%5d  ", pom[i]);
		}

	printf("\n\n");

	return 0;
}

