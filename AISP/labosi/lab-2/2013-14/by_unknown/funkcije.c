#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "datoteka.h"

/*
 * pronalazi sve datoteke koje se nalaze u folderu ciji je naziv dan u varijabli mapa.
 * Funkcija vraca polje datoteke tipa Datoteka te broj datoteka u folderu (varijabla brojDatoteka),
 * a kroz naziv vraca broj elemenata polja, odnosno -1, ako je došlo do greske u otvaranju datoteke.
 */
int vratiDatoteke(char *mapa, Datoteka **datoteke) {

	FILE *dat;
	char tip;
	int broj, i;
	char naziv[80+1],pom[255+1];
	Datoteka *tmp;

	dat=fopen("podaciDatoteke.txt","r");
	if (dat==NULL){ /* ako datoteka s podacima nije uspjesno otvorena */
		datoteke=NULL;
		return -1;
	}

	fscanf(dat,"%c %d %s",&tip, &broj, naziv); fgets(pom,255,dat);
	while(!feof(dat)){
		if (strcmp(naziv,mapa)==0){ /* ako sam nasao pravi folder ... */
			tmp=(Datoteka*) malloc(sizeof(Datoteka)*broj); /* stvori prostor za spremanje podataka */
			for(i=0;i<broj;i++){
				fscanf(dat,"%c %d %s",&(tmp[i].vrsta), &(tmp[i].velicina), tmp[i].putanja); fgets(pom,255,dat);
			}
			fclose(dat);
			*datoteke=tmp;
			return broj;
		}
		else{
			for(i=0;i<broj;i++)
				fgets(pom,255,dat);
		}
		fscanf(dat,"%c %d %s",&tip, &broj, naziv); fgets(pom,255,dat);
	}
	datoteke=NULL;
	return 0;
}

void prepisiDatoteku(Datoteka *odrediste, Datoteka *izvor) {
	strcpy(odrediste->putanja,izvor->putanja);
	odrediste->velicina=izvor->velicina;
	odrediste->vrsta=izvor->vrsta;
}

void init_stog(Stog *stog) {
	stog->vrh = -1;
}

int dodaj(Datoteka stavka, Stog *stog) {
	if (stog->vrh >= MAXSTOG-1) return 0;   /* dosegnut kapacitet stoga */
	stog->vrh++;
	prepisiDatoteku( &(stog->polje[stog->vrh]), &stavka);
	return 1;
}

int skini(Datoteka *stavka, Stog *stog) {
	if (stog->vrh < 0) return 0;
	prepisiDatoteku(stavka,&(stog->polje[stog->vrh]));
	stog->vrh--;
	return 1;
}
