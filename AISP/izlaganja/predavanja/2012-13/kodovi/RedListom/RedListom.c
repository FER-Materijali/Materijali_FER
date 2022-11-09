/* RedListom.c */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/***** IMPLEMENTACIJA REDA LISTOM **************/

struct at {
	int element;
	struct at *sljed;
};
typedef struct at atom;
typedef struct {
	atom *ulaz, *izlaz;
} Red;

void init_red(Red *red){
	red->ulaz = NULL;
	red->izlaz = NULL;
}

// dodaje element u red, vraca 1 ako uspije, inace 0 
int DodajURed (int element, Red *red) {
	atom *novi;
	if (novi = malloc (sizeof (atom))) {
		novi->element = element;
		novi->sljed = NULL;
		if (red->izlaz == NULL) {
			red->izlaz = novi;		// ako je red bio prazan
		} else {
			(red->ulaz)->sljed = novi;	// inace, stavi na kraj
		}
		red->ulaz = novi;			// zapamti zadnjeg
		return 1;
	}
	return 0;
}
// uklanja element iz reda, vraca 1 ako uspije, inace 0 
int SkiniIzReda (int *element, Red *red) {
	atom *stari;
	if (red->izlaz) {						// ako red nije prazan 
		*element = (red->izlaz)->element;	// element koji se skida
		stari = red->izlaz;					// zapamti trenutni izlaz
		red->izlaz = (red->izlaz)->sljed;		// novi izlaz
		free (stari);					// oslobodi memoriju skinutog
		if (red->izlaz == NULL) red->ulaz = NULL; // prazan red
		return 1;
  }
	return 0;
}
// vraca broj elemenata u redu
int Prebroji (Red *red) {
	int n;
	atom *izlaz;
	izlaz = red->izlaz;
#if 1
	for (n = 0; izlaz; izlaz = izlaz->sljed) {
		printf ("%d -> ", izlaz->element);
		n++ ;
	}
	printf ("NULL\n");
#else 
	// krace
	for (n = 0; izlaz; n++, izlaz = izlaz->sljed);
#endif
	return n;
}

/************* KRAJ IMPLEMENTACIJE REDA ******************/

int main () {
  int broj;				// podatak/kontrola
	Red red;
	init_red(&red);
 	
	printf ("Slucajno se generiraju nenegativni cijeli brojevi.\n");
	printf ("Neparni brojevi upisuju se u red, a parni broj simulira skidanje iz reda\n");
	printf ("Za obavljanje jednog koraka pritisnuti ENTER, za kraj CTRL-C\n");
	
	// inicijalizacija generatora slucajnih brojeva
	srand ((unsigned) time (NULL));

	while (1) {
		getchar ();			// ENTER, Ctrl-C
		broj = rand ();
		if (broj%2) {
			// Neparne upisujemo u red
			printf ("U red se upisuje broj %d\n", broj);
			if (!DodajURed (broj, &red)) 
				printf("Nema vise memorije\n");
		} else {
			// Parni broj simulira skidanje iz reda
			if (SkiniIzReda (&broj, &red)) {
				printf ("Iz reda je skinut podatak %d\n", broj);
			} else {
				printf("Red je prazan\n");
			}
		}
		printf ("Broj elemenata u redu: %d\n", Prebroji (&red));
	}
}
