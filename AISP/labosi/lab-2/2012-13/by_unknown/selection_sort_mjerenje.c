#include <stdio.h>
#include "sortovi.h"
#include <time.h>
#define KRAJ 15000
#define AGREG 30
#define START 0
#define KORAK 250
#define SILAZNO 0
/*slo�enost O(n^2), eureka ka�e 4.62n^2*/
int main(){
	FILE *ulaz, *izlaz;
	int i=START, j, niz[KRAJ], broj_clanova, cuvaj[KRAJ];
	time_t vrijeme1, vrijeme2; 
	long trajanje, ukupno_trajanje;
	float prosijek;
	if((ulaz=fopen("ulaz_brojevi1.txt","r"))==NULL)
		return -1;
	if((izlaz=fopen("izlaz_selection_sort.txt","w"))==NULL)
		return -2;
	/*ucitavaj brojeve iz ulazne datoteke*/
	do{
		fscanf(ulaz,"%d",&niz[i]);
		cuvaj[i]=niz[i];
		i++;
	}while(i<KRAJ);
	printf("Ucitano!\n");
	/*po�ni izvr�avat glavnu petlju tj. za svaki korak po AGREG sortiranja*/
	for(broj_clanova=START; broj_clanova<=KRAJ; broj_clanova+=KORAK){
		ukupno_trajanje=0;
		for(i=0;i<AGREG;i++){
			/*pocni mjerit vrijeme*/
			vrijeme1=clock();
			selection_sort(niz,broj_clanova,SILAZNO);
			/*prestani mjerit vrijeme*/
			vrijeme2=clock();
			printf("Sortiran sa %d clanova po %2d-ti put", broj_clanova, i+1);
			/*izra�unaj vrijeme izvo�enja sortiranja za zadanu veli�inu niza*/
			trajanje=(vrijeme2-vrijeme1);
			printf(" - vrijeme sortiranja: %ld ms\n",trajanje);
			ukupno_trajanje+=trajanje;
			/*obnovi niz za sortiranje*/
			for(j=0;j<broj_clanova;j++)
				niz[j]=cuvaj[j];
		}
		/*izra�unaj prosije�no vrijeme sortiranja i upi�i u datoteku*/
		prosijek=(float)ukupno_trajanje/AGREG;
		fprintf(izlaz,"%d\t%f\n",broj_clanova,prosijek);
	}
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
