#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void funkcija(FILE *d, char *pivo, float *kol, float* cijena){
	char pivo1[30+1];
	float cijena1=0, kol1=0, pom=1000000;

	while(fscanf(d, "%30[^#]%*c%f%*c%f%*c", &pivo1, &kol1, &cijena1)==3){
		if((cijena1/kol1)<pom){
			*kol = kol1;
			*cijena=cijena1/kol1;
			strcpy(pivo, pivo1);
		}
		pom=cijena1/kol1;
	}
}



int main (){
	FILE *d;
	char pivo[30+1];
	float cijena, kol;

	if((d=fopen("pivo.txt", "r"))==NULL){
		printf("Greska kod otvaranja datoteke!\n\n");
		exit(1);
	}

	funkcija(d, pivo, &kol, &cijena);
	printf("Najisplatijevije pivo je %s, i to u pakiranju od %.2f l, \n  po cijeni od %.2f po litri.\n\n", pivo, kol, cijena);


	return 0;
}
