#include "stdio.h"
#include "stdlib.h"

#define MAXSTOG 10000 /* maksimalna velicina stoga */

typedef struct{
	char vrsta;
	int  velicina;
	char putanja[80];
}Datoteka;


typedef struct {
	int vrh;
	Datoteka polje[MAXSTOG];
} Stog;

void init_stog(Stog *stog);
int dodaj(Datoteka stavka, Stog *stog);
int skini(Datoteka *stavka, Stog *stog);

//typedef struct datoteka Datoteka;
int vratiDatoteke(char *mapa, Datoteka **datoteke);
void prepisiDatoteku(Datoteka *odrediste,Datoteka *izvor);
