// RedListom2.c
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

struct at2 {
	int element;
	struct at2 *sljed;
	struct at2 *preth;
};
typedef struct at2 atom2;

// dodavanje u red realiziran dvostruko povezanom listom
// funkcija vraca 1 ako uspije, inace 0
int DodajURed (int element, atom2 **glavap, atom2 **repp) {
	atom2 *novi;

	if (novi = malloc (sizeof (atom2))) {
		novi->element = element;
		novi->sljed = NULL;
		novi->preth = NULL;

		if (*glavap == NULL) {					// Ako je red bio prazan
			*glavap = novi; *repp = novi;	
		} else {								// inace, stavi na kraj
			(*repp)->sljed = novi;
			novi->preth = *repp;
			*repp = novi;	
		}
		return 1;
	}
	return 0;
}

// skidanje iz reda
// funkcija vraca 1 ako uspije, inace 0
int SkiniIzReda (int *element, atom2 **glavap, atom2 **repp) {
	atom2 *stari;

	if (*repp) {	// neprazan red ?
		*element = (*glavap)->element; // vrati element

		if (*glavap == *repp) {	// Ako je samo jedan clan
			stari = *glavap;
			*glavap = NULL; *repp = NULL;
		} else {								// inace, povezi ih
			(*glavap)->sljed->preth = NULL;
			stari = *glavap;
			*glavap = stari->sljed;
		}
		free (stari);
		return 1;
  }
	return 0;
}

// ispis reda
void IspisiRed (atom2 *glava) {
	for (; glava; glava = glava->sljed)
		printf ("%d ", glava->element);
	printf ("\n");
}

// brisanje iz reda clana sa zadanim kljucem
int BrisiIzReda (atom2 **glavap, atom2 **repp, int element) {
	atom2 *pom;
	if (*glavap) { // neprazan red
		// trazi clan
		for (pom = *glavap; pom && (pom->element != element); pom = pom->sljed)
			;
		if (pom) {	// Ako je nadjen,
			if (pom == *glavap) {	// ako je prvi
				*glavap = pom->sljed;
				if (pom->sljed)	{		// ako nije jedini
					pom->sljed->preth = NULL;
				} else {						// ako jest jedini
					*glavap = NULL; *repp = NULL;
				}
			} else if (pom == *repp) {	// ako je zadnji, ali ne i jedini
				(*repp)->preth->sljed = NULL;
				*repp = (*repp)->preth;
			} else {	// nije ni prvi ni zadnji
				pom->preth->sljed = pom->sljed;
				pom->sljed->preth = pom->preth;
			}
			free (pom);
			return 1;
		}
	}
	return 0;		// Nije nadjen ili lista prazna
}


// Red realiziran dvostruko povezanom listom
// omogucuje uklanjanje bilo kojeg clana iz reda
int main () {
	atom2 *glava = NULL;	// glava reda
	atom2 *rep = NULL;		// rep reda
	int broj;							// pseudoslucajni broj

 	printf ("Slucajno se generiraju nenegativni cijeli brojevi.\n");
	printf ("Neparni brojevi upisuju se u red, a parni broj simulira skidanje iz reda\n");
	printf ("Za obavljanje jednog koraka pritisnuti ENTER, za kraj K\n");
	
	// inicijalizacija generatora slucajnih brojeva
	srand ((unsigned) time (NULL));

	while (toupper(getch ()) != 'K') {
		broj = rand ();
		if (broj%2) { // Neparne upisujemo u red
			printf ("U red se upisuje broj %d\n", broj);
			if (!DodajURed (broj, &glava, &rep)) 
				printf("Nema vise memorije\n");
		} else {			// Parni broj simulira skidanje iz reda
			if (SkiniIzReda (&broj, &glava, &rep)) {
				printf ("Iz reda je skinut podatak %d\n", broj);
			} else {
				printf("Red je prazan\n");
			}
		}
		IspisiRed (glava);
	}
	// brisanje iz reda
	while (1) {
		IspisiRed (glava);
		printf ("Upisite podatak koji se brise iz reda >");
		scanf ("%d", &broj);
		if (!BrisiIzReda (&glava, &rep, broj)) 
			return 0;
	}
}