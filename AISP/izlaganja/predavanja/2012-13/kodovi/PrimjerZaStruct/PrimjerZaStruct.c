// PrimjerZaStruct.c - Prebaceno u PIPI
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAXBROJ 13
#define MAXNAZIV 40

typedef struct s_osoba {	// krace: typedef struct { ... } osoba;
  char jmbg [MAXBROJ + 1]; 	
  char prezime [MAXNAZIV + 1];
  char ime [MAXNAZIV + 1];
  int visina;
  float tezina;
} osoba;

typedef struct s_adresa {
	char ulica [MAXNAZIV + 1];
	int kbr;
	int post_broj;
	char mjesto [MAXNAZIV + 1];
} adresa;

typedef struct s_student {
	int maticni_broj;
	osoba osobni_podaci;
	adresa adresa_roditelja;
	adresa adresa_u_mjestu_studiranja;
	osoba otac;
	osoba majka;
} student;


int main (void) {
	student pero, *p;
	
	// referenciranje elemenata strukture
	strcpy (pero.osobni_podaci.ime, "Pero");
	pero.otac.visina = 182;
	pero.majka.tezina = 92.5;
	
	// referenciranje preko pokazivaca
	p = (student *) malloc (sizeof (student));
	strcpy (p->osobni_podaci.ime, "Ivo");
	p->otac.tezina = 82.8;		// p je pokazivac na strukturu
	p->majka.visina = 152;
	(*p).majka.tezina = 55.5;	// (*p) je struktura

	return 0;
}
