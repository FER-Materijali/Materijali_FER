#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAXRED 100
#define MAXSTUP 150

int funkcija(int *mat, int brRed, int brStup, int maxStup){
	int i, j, pom, redak;
	redak=(int)((float)rand()/(RAND_MAX+1)*(brStup+1));
	pom=mat[0];
	for(i=redak,j=1;j<brStup;++j){
		if(pom+mat[i*maxStup+j]==0) return 1;
		else return 0;
	}
}

int main(){
	int mat[MAXRED][MAXSTUP], i, j, red, stup, x;

	printf("Unesi broj redaka: ");
	scanf("%d", &red);
	printf("Unesi broj stupaca: ");
	scanf("%d", &stup);
	printf("\n\n");

	srand ((unsigned)time(NULL));

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

	x=funkcija(&mat[0][0], red, stup, MAXSTUP);

	if(x==1)printf("U matrici POSTOJE elementi ciji je zbroj jednak nuli!");
	if(x==0)printf("U matrici NE POSTOJE elementi ciji bi zbroj bio jednak nuli!");

	printf("\n\n");

	return 0;
}

