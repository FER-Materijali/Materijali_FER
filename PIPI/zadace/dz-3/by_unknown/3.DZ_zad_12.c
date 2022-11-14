#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXRED 100
#define MAXSTUP 150

void funkcija (int *mat, int brRed, int brStup, int maxStup){
	int i, j;
	for(i=0;i<brRed;++i){
		for(j=0;j<brStup;++j){
			if(mat[i*maxStup+j]%2==0) continue;
			else mat[i*maxStup+j]=(int)((float)rand()/(RAND_MAX)*(mat[i*maxStup+j]+1));
		}
	}
}

int main(){
	int i, j, red, stup;
	int mat[MAXRED][MAXSTUP];

	printf("Unesi broj redaka: ");
	scanf("%d", &red);
	printf("Unesi broj stupaca: ");
	scanf("%d", &stup);
	printf("\n\n");

	srand((unsigned)time(NULL));
	

	for(i=0;i<red;++i){
		for(j=0;j<stup;++j){
			printf("Unesi element (%d,%d): ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	printf("\n\nIspis matrice prije zamjene neparnih elemenata:\n");
	for(i=0;i<red;++i){
		for(j=0;j<stup;++j){
			printf("%5d  ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	funkcija(&mat[0][0], red, stup, MAXSTUP);

	printf("Ispis matrice nakon zamjene neparnih elemenata:\n");
	for(i=0;i<red;++i){
		for(j=0;j<stup;++j){
			printf("%5d  ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	return 0;
}