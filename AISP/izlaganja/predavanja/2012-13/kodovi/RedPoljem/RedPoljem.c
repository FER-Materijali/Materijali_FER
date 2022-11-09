/* RedPoljem.c */
#include <stdlib.h>
#include <stdio.h>

/***** IMPLEMENTACIJA REDA POLJEM **************/

#define MAXRED 10
typedef int tip;

typedef struct {
	tip polje[MAXRED]; 
	int ulaz, izlaz;
} Red;

void init_red(Red *red){
	red->ulaz = 0; red->izlaz = 0;
}

// dodaje element u red
// vraca 1 ako ima mjesta u redu, inace 0
// mijenja ulaz, tj straznji kraj
int DodajURed (tip element, Red *red) {
	if (((red->ulaz+1) % MAXRED) == red->izlaz) return 0;
	red->ulaz++; 
	red->ulaz %= MAXRED;
	red->polje[red->ulaz] = element;
	return 1;
}
// logicki uklanja element iz polja red od max n clanova
// vraca 1 ako ima clanova u redu, inace 0
// mijenja izlaz, tj prednji kraj
int SkiniIzReda (tip *element, Red *red) {
	if (red->ulaz == red->izlaz) return 0;
	red->izlaz++; 
	red->izlaz %= MAXRED;
	*element = red->polje[red->izlaz];
	return 1;
}
// vraca broj elemenata u redu
int prebroji (Red *red) {
	if (red->ulaz >= red->izlaz) {		
		return (red->ulaz - red->izlaz);		// standardno
	} else {
		return (red->ulaz - red->izlaz + MAXRED);// cirkularnost
	}
}


/************* KRAJ IMPLEMENTACIJE REDA ******************/

int main () {
	Red red;				
	int element;	// element, krajevi reda
	int skini;
	FILE *fi;							// ulazna datoteka

	init_red(&red);
	fi = fopen ("UlazZaRed.txt", "r");
	if (fi) {
		while (fscanf (fi, "%d", &element) != EOF) {
  			// stavljanje u red
			if ((DodajURed (element, &red))) {
				printf ("U red dodan element %d\n", element);
				printf ("\tBroj elemenata u redu je %d\n", 
										prebroji (&red));
			} else {	
				printf ("Nema vise mjesta u redu. Koliko skinuti?\n");
				scanf ("%d", &skini);

				// uklanjanje iz reda
				while (--skini >= 0 && SkiniIzReda (&element, &red)) {
					printf ("Iz reda skinut element %d\n", element);
					printf ("\tBroj elemenata u redu je %d\n", 
							prebroji (&red));
				}
				//break;
			}
		}
		fclose (fi);
		return 0;
	} else {
		printf ("Nema ulazne datoteke\n");
		return 1;
	}
}
