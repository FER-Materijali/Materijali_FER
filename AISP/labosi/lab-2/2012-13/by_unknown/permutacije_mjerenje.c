#include <stdio.h>
#include "sortovi.h"
#include <time.h>
#define KRAJ 11
#define AGREG 50
#define START 2
#define KORAK 1
#define SILAZNO 0
/*složenost O(n!), eureka kaže 2.03e-5*n!*/
void rotiraj(char *niz, int n){
	char pom;
	int i;
	/*rotiraj cijeli niz za jedan clan u lijevo*/
	pom=niz[0];
	for(i=0;i<n-1;i++){
		niz[i]=niz[i+1];
	}
	niz[i]=pom;
}

void permutacije(char *niz, char *prvi, int n){
	int i,j;
	/*rotiraj sve vanjske podnizove; pod vanjski se podrazumijeva svi podnizovi duljine veæe od 2*/
	if(n>1){ 
		for(j=0;j<n && n>2;j++){
			permutacije(niz+1,prvi,n-1);
			rotiraj(niz,n);
		}
	}
		else
			return;
	/*rotira zadnja dva èlana i vraæa poèetni niz*/
	if(n==2)
	for(i=0;i<n;i++){
		rotiraj(niz,n);
	}
}

int main(){
	FILE *ulaz, *izlaz;
	int i=START, j, broj_clanova;
	char niz[KRAJ], cuvaj[KRAJ];
	time_t vrijeme1, vrijeme2; 
	long trajanje, ukupno_trajanje;
	float prosijek;
	if((ulaz=fopen("ulaz_string.txt","r"))==NULL)
		return -1;
	if((izlaz=fopen("izlaz_permutacije.txt","w"))==NULL)
		return -2;
	/*ucitavaj brojeve iz ulazne datoteke*/
	do{
		fscanf(ulaz,"%c",&niz[i]);
		cuvaj[i]=niz[i];
		i++;
	}while(i<KRAJ);
	printf("Ucitano!\n");
	/*poèni izvršavat glavnu petlju tj. za svaki korak po AGREG permutiranja*/
	for(broj_clanova=START; broj_clanova<=KRAJ; broj_clanova+=KORAK){
		ukupno_trajanje=0;
		for(i=0;i<AGREG;i++){
			/*pocni mjerit vrijeme*/
			vrijeme1=clock();
			permutacije(niz,niz,broj_clanova);
			/*prestani mjerit vrijeme*/
			vrijeme2=clock();
			printf("Permutacija sa %d clanova po %2d-ti put", broj_clanova, i+1);
			/*izraèunaj vrijeme permutiranja za zadanu velièinu niza*/
			trajanje=(vrijeme2-vrijeme1);
			printf(" - vrijeme permutiranja: %ld ms\n",trajanje);
			ukupno_trajanje+=trajanje;
			/*obnovi niz za permutiranje*/
			for(j=0;j<broj_clanova;j++)
				niz[j]=cuvaj[j];
		}
		/*izraèunaj prosijeèno vrijeme permutiranja i upiši u datoteku*/
		prosijek=(float)ukupno_trajanje/AGREG;
		fprintf(izlaz,"%d\t%f\n",broj_clanova,prosijek);
	}
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
