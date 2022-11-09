#include "asp_massh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define VELJMBG 13
#define VELIME 14

struct zapis{
	char JMBG[VELJMBG+1];
	char prezime[VELIME+1];
};

#define BLOK 512L // Blok na disku
#define N 350 // Ocekivani broj zapisa:    
#define C ((int) (BLOK / sizeof (struct zapis))) // Broj zapisa u pretincu
#define M ((int) ((N/C) *1.3)) // Broj pretinaca

struct zapis ulaz, pretinac [C];

void Isprazni (FILE *ft) {
	int i;
	noviDio("Praznjenje");
	
	for (i = 0; i < C; i++) pretinac[i].JMBG[0] = '\0';
	
	for (i = 0; i < M; i++) {
		fseek (ft, i*BLOK, SEEK_SET);
		fwrite (pretinac, sizeof(pretinac), 1, ft);
	}
	
	printf("Tablica ispraznjena!\n");
	printf("Ocekujemo max zapisa: %d\n", N);
	printf("U jedan blok stane: %d\n", C);
	printf("Ukupno imamo blokova: %d\n", M);
	printf("Velicina bloka: %d bajtova\n", sizeof(pretinac));
}

int OdrediPrim (int m) {
	int i, prim, kraj;
	prim = m+1;
	
	do {
		prim--;
		kraj = (int) pow ((double) prim, (double) 0.5);
		for (i = kraj; i > 0; i--) {
			if (prim % i == 0) break;
		}
	} while (i != 1);
	
	return prim;
}

int Adresa (char JMBG[], int prim) {
	int i, a, b, c, adr;
	char pom [4+1];
	pom [4] = '\0';
	// Preklapanje
	for (i = 0; i < 4; i++) pom[i] = JMBG[i+4];
	a = atoi (pom);
	for (i = 0; i < 4; i++) pom[i] = JMBG[3-i];
	b = atoi (pom);
	for (i = 0; i < 4; i++) pom[i] = JMBG[11-i];
	c = atoi (pom);
	// Dijeljenje
	adr = (a + b + c) % prim;
	printf ("Izracunata adresa (%d) = %d\n", (a + b + c), adr);
	return adr;
}

int Upis (struct zapis ulaz, FILE *ft, int prim) {
	int i, j, poc;
	
	noviDio("Upis");
	
	i = Adresa (ulaz.JMBG, prim);
	poc = i;
	
	printf("     Zelimo upisati sto blize bloku %d\n", i);
	
	do {
		printf("          Isprobavamo blok %d\n", i);
		fseek (ft, i*BLOK, SEEK_SET);
		fread (pretinac, sizeof (pretinac), 1, ft);
		
		for (j = 0; j < C; j++) {
			printf ("            U bloku %d isprobavamo mjesto %d\n", i, j);
			if (pretinac[j].JMBG[0] != '\0') {
				printf ("               Za blok %d u dio %d vec upisan JMBG\n", i, j);
				if (strncmp (pretinac[j].JMBG, ulaz.JMBG, VELJMBG) == 0) {
					printf ("                    Upisujemo postojeci - skip\n");
					return 1;
				}
			} else {
				printf ("               UPIS U BLOK %d MJESTO %d!!!\n", i, j);
				
				pretinac[j] = ulaz;
				fseek (ft, i*BLOK, SEEK_SET);
				fwrite (pretinac, sizeof (pretinac), 1, ft);
				
				return 1;
			}
		}
		
		i = (i + 1) % M;
		printf ("Blok pun, idemo dalje\n");
	} while (i != poc);
	
	printf("I'm sorry Dave, I'm afraid I can't do that\n");
	return 0;
}  

void Ispis (FILE *ft) {
	int i, j;
	
	noviDio("Hash tablica po blokovima");
	
	for (i = 0; i < M; i++) {
		fseek (ft, i*BLOK, SEEK_SET);
		fread (pretinac, sizeof (pretinac), 1, ft);
		
		printf("### BLOK %d ###\n", i);
		
		for (j = 0; j < C; j++) {
			if (pretinac[j].JMBG[0] != '\0') {
				printf ("%d: %s %s \n", j, pretinac[j].JMBG, pretinac[j].prezime);
			}
		}
		printf("### KRAJ BLOKA ###\n\n");
	}
}

int Trazi (char mbr[], FILE *ft, int prim, struct zapis *ulaz) {
	noviDio("Trazenje");
	int i, j, poc;
	
	i = Adresa (mbr, prim);
	poc = i;
	do {
		printf("Trenutno gledam u bloku %d\n", i);
		
		fseek (ft, i*BLOK, SEEK_SET);
		fread (pretinac, sizeof (pretinac), 1, ft);
		
		for (j = 0; j < C; j++) {  
			printf("     Gledam u bloku %d na mjesto %d\n", i, j);
			if (pretinac[j].JMBG[0] != '\0') {
				printf("          Mjesto %d nije prazno!\n", j);
				if (strcmp (pretinac[j].JMBG, mbr) == 0) {
					printf("               Nije ono sto trazimo\n");
					*ulaz = pretinac[j];
					return 1;
				}
			} else {
				return 0; //pitat ih - zašto ovdje ubijamo funkciju?
			}
		}
		
		printf("Kraj pretrage u bloku, idemo dalje\n");
		i = (i + 1) % M;
	} while (i != poc);
	printf("Pretraga gotova, element nije nadjen");
	return 0;
}

int main() {
	FILE *fi, *ft;
	
	char mbr [VELJMBG+1];
	int prim;
	
	if ((fi = fopen ("input2.txt", "r")) == NULL) {
		printf("Err: Problem s input.txt\n");		
		return -1;
	}
		
	if ((ft = fopen ("tablica","wb+")) == NULL) {
		printf("Err: Problem s hash tablicom");
		return -1;
	}
		
	printf ("Velicina ulaza: %d\n", sizeof (ulaz));
	
	Isprazni (ft);
	Ispis (ft);
	
	prim = OdrediPrim (M);
	printf ("Prost broj: %d\n", prim);
	
	while (fscanf (fi, "%13s%s", ulaz.JMBG, ulaz.prezime) != EOF) {
		printf ("\nProcitan zapis %s %s", ulaz.JMBG, ulaz.prezime);
		
		if (!Upis (ulaz, ft, prim))
			printf("Err: Tablica je puna\n");

		printf ("\n");
	}

	fclose (fi); //gotovi smo s ulazom
	
	Ispis (ft);
	while (1) {
		printf ("Upisite JMBG >");
		scanf ("%s", mbr);
		if (Trazi (mbr, ft, prim, &ulaz)) {
			printf ("%s %s\n", ulaz.JMBG, ulaz.prezime);
		} else {
			printf ("JMBG %s nije u tablici\n", mbr);
			break;
		}
	}
	fclose (ft);
	return 0;
}
