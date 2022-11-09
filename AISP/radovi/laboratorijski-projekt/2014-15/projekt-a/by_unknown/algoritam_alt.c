#define _CRT_SECURE_NO_DEPRECATE //treba ako radite u visual studiju (prigovara da funkcija strcpy nije sigurna i ne zeli kompajlirati)
#include <stdio.h>  //treba za rad s datotekama
#include <string.h>  //treba za funkcije strcmp i strcpy
#include <malloc.h>  //treba za funkciju malloc
#include <math.h>  //treba za funkciju sqrt
#include "dodatno.h"  //treba za NSTAVKI i struct stanovnik
#include "algoritam_alt.h"  //treba za deklaracije funkcija

struct {
	struct at *glava, *rep;
	char medijan[51];
} indeks;


int DodajURed(char *ime_prezime_dodaj, long pocetak_bloka_dodaj, Atom **glavap, Atom **repp) {
	Atom *novi;

	if (novi = (Atom*) malloc(sizeof(Atom))) {		//stvori novi atom
		strcpy(novi->ime_prezime, ime_prezime_dodaj);
		novi->pocetak_bloka = pocetak_bloka_dodaj;  //napuni ga zeljenim vrijednostima
		novi->sljed = NULL;
		novi->preth = NULL;

		if (*glavap == NULL) {					//ako je red bio prazan, namjesti glavu i rep na novi
			*glavap = novi; 
			*repp = novi;
		}
		else {								//ako nije bio prazan, umetni novi na kraj
			(*repp)->sljed = novi;
			novi->preth = *repp; 
			*repp = novi;
		}
		return 1;
	}
	fprintf(stderr, "Nema dovoljno memorije");
	return 0;  //ako nema memorije za novi atom, vrati 0
}


void inicijaliziraj(FILE *ulaz){
	Atom *glava = NULL;
	Atom *rep = NULL;
	char ime_prezime_dodaj[51];
	long pozicija_u_datoteci = 0;
	long br_blokova = NSTAVKI / (sqrt(NSTAVKI));
	long srednji_blok =  br_blokova / 2;
	long vel_bloka = sqrt(NSTAVKI)*sizeof(struct stanovnik);
	int i = 0;

	while (i < br_blokova){  //radi listu po blokovima
		fseek(ulaz, pozicija_u_datoteci, SEEK_SET);  //pozicioniranje unutar datoteke
		fread(ime_prezime_dodaj, sizeof(ime_prezime_dodaj), 1, ulaz); //izvadi ime i prezime prvog zapisa u bloku
		if (DodajURed(ime_prezime_dodaj, pozicija_u_datoteci, &glava, &rep) == 0) 
			exit(-2);  //dodaj ga u listu, ako nema memorije za novi atom, izadji iz programa s kodom -2
		if (i == srednji_blok) 
			strcpy(indeks.medijan, ime_prezime_dodaj); //dodaj zapis na sredini liste u indeks.medijan
		pozicija_u_datoteci += vel_bloka;  //pomakni se na sljedeci blok
		i++; //povecaj brojac blokova
	}
	indeks.glava = glava;
	indeks.rep = rep;
	return;
}

long nadji_blok(char *ime_prezime, FILE *ulaz){
	Atom *p;
	for (p = indeks.glava; p != NULL; p = p->sljed){  //pretrazuj od glave prema kraju
		if (strcmp(p->ime_prezime, ime_prezime) == 0) return p->pocetak_bloka;  //ako nadje podatak na pocetku bloka, vrati adresu tog bloka
		if (strcmp(p->ime_prezime, ime_prezime) > 0) return p->preth->pocetak_bloka;  //kada nadje blok u kojem su zapisi veci od trazenog, vrati adresu prethodnog bloka
	}
	return indeks.rep->pocetak_bloka; //ako se zapis nalazi u zadnjem bloku, ne postoji zapis u sljedecem bloku veci od njega, pa treba vratiti adresu zadnjeg bloka (na njega pokazuje rep)
}


char *izl_naziv(){
	return ("indeksna_pretraga.rez");
}