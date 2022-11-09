// RedListom.c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct at {
	int element;
	struct at *sljed;
};
typedef struct at atom;

// dodaje element u red, vraca 1 ako uspije, inace 0 
int DodajURed (int element, atom *ulaz, atom *izlaz) {
	atom *novi;
	if (novi = malloc (sizeof (atom))) {
		novi->element = element;
		novi->sljed = NULL;
		if (izlaz == NULL) {
			izlaz = novi;		// ako je red bio prazan
		} else {
			(ulaz)->sljed = novi;	// inace, stavi na kraj
		}
		ulaz = novi;			// zapamti zadnjeg
		return 1;
	}
	return 0;
}
// uklanja element iz reda, vraca 1 ako uspije, inace 0 
int SkiniIzReda (int *element, atom *ulaz, atom *izlaz) {
	atom *stari;
	if (izlaz) {						// ako red nije prazan 
		*element = (izlaz)->element;	// element koji se skida
		stari = izlaz;					// zapamti trenutni izlaz
		izlaz = (izlaz)->sljed;		// novi izlaz
		free (stari);					// oslobodi memoriju skinutog
		if (izlaz == NULL) ulaz = NULL; // prazan red
		return 1;
  }
	return 0;
}
// vraca broj elemenata u redu
int Prebroji (atom *izlaz) {
	int n;
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
int main () {
  int broj;				// podatak/kontrola
	atom *ulaz = NULL;	// krajevi	
	atom *izlaz = NULL;
 	
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
			if (!DodajURed (broj, ulaz, izlaz)) 
				printf("Nema vise memorije\n");
		} else {
			// Parni broj simulira skidanje iz reda
			if (SkiniIzReda (&broj, ulaz, izlaz)) {
				printf ("Iz reda je skinut podatak %d\n", broj);
			} else {
				printf("Red je prazan\n");
			}
		}
		printf ("Broj elemenata u redu: %d\n", Prebroji (izlaz));
	}
}
