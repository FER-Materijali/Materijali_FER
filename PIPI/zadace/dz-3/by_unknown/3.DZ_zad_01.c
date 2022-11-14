#include <stdio.h>
#include <math.h>
#define MAXRED 100
#define MAXSTUP 150

void funkcija(int *mat, int brRed, int brStup, int maxStup, int *ired, int *istup){
	float arit_sred=0, pom=0;
	int i, j;
	for(i=0;i<brRed;++i){
		for(j=0;j<brStup;++j){
			arit_sred+=mat[i*maxStup+j];
		}
	}
	arit_sred/=brRed*brStup;

	*ired=0;
	*istup=0;
	pom = fabs(arit_sred-mat[0]);
	for(i=0;i<brRed;++i){
		for(j=0;j<brStup;++j){
			if (fabs(arit_sred-mat[i*maxStup+j]) <= pom){
				pom=fabs(arit_sred-mat[i*maxStup+j]);
				*ired=i;
				*istup=j;
			}
		}
	}
}



int main(){
	int mat[MAXRED][MAXSTUP], i, j, red, stup;
	int ired, istup;


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

	funkcija(&mat[0][0], red, stup, MAXSTUP, &ired, &istup);

	printf("Element koji je najblizi aritmetickoj sredini matrice\n nalazi se u %d. stupcu i %d. retku, i to je broj %d.", ired+1, istup+1, mat[ired][istup]);

	printf("\n\n");

	return 0;
}

