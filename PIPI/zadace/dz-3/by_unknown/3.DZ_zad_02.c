#include <stdio.h>
#include <math.h>
#define MAXRED 100
#define MAXSTUP 150

int funkcija(int *mat, int brRed, int brStup, int maxStup){
	int i, j, brojac_g=0, brojac_d=0, razlika;
	for(i=0;i<brRed;++i){
		for(j=0;j<brStup;++j){
			if(i<j){
				if(mat[i*maxStup+j]!=0) brojac_g++;
			}
			if(i>j){
				if(mat[i*maxStup+j]!=0) brojac_d++;
			}
		}
	}
	razlika = brojac_g-brojac_d;
	return razlika;
}




int main(){
	int mat[MAXRED][MAXSTUP], i, j, red, stup, razlika;

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
	printf("\n\nIspis matrice:\n");
	for(i=0;i<red;++i){
		for(j=0;j<stup;++j){
			printf("%5d  ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	razlika = funkcija(&mat[0][0], red, stup, MAXSTUP);

	printf("Razlika popunjenosti gornje i donje trokutaste matrice iznosi: %d", razlika);
	if(razlika>0) printf("\nGornja trokutasta matrica je popunjenija od donje!");
	if(razlika<0) printf("\nDonja trokutasta matrica je popunjenija od gornje!");
	if(razlika==0) printf("\nGornja i donja trokutasta matrica imaju jednak broj elemenata razlicit od nule!");

	printf("\n\n");

	return 0;
}

