#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXRED 100
#define MAXSTUP 150

void funkcija(int *mat, int brRed, int brStup, int maxStup){
	int i, j, broj;
	for(i=0;i<brRed;++i){
		for(j=0;j<brStup;++j){
			do{
				broj=(int)((float)rand()/(RAND_MAX+1)*('z'-'A'+1)+'A');
			}while(!((broj>='A' && broj<='Z') || (broj>='a' && broj<='z')));
			mat[i*maxStup+j]=broj;
		}
	}
}



int main(){
	int mat[MAXRED][MAXSTUP], i, j, red, stup;

	srand ((unsigned)time(NULL));

	printf("Unesi broj redaka: ");
	scanf("%d", &red);
	printf("Unesi broj stupaca: ");
	scanf("%d", &stup);
	printf("\n\n");

	funkcija(&mat[0][0], red, stup, MAXSTUP);

	printf("\n\nIspis matrice:\n");
	for(i=0;i<red;++i){
		for(j=0;j<stup;++j){
			printf("%c  ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	return 0;
}

