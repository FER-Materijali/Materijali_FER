// Lista.c
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int tip;

struct at {
  tip element;
  struct at *sljed; 
};
typedef struct at atom;
// Dodavanje u listu 
// sortiranu po rastucoj vrijednosti elementa
// vraca 1 ako uspije, inace 0
int dodaj (atom **glavap, tip element) {
  atom *novi, *p;
  if ((novi = (atom *) malloc(sizeof(atom))) == NULL) 
		return 0;
  novi->element = element;
  if (*glavap == NULL || (*glavap)->element >= element) {
    // Dodavanje na pocetak liste
    novi->sljed = *glavap;
    *glavap = novi;
  } else {
	// Dodavanje iza postojeceg elementa kad:
	// a) postojeæi atom nema sljedeæeg
	// b) element u sljedeæem cvoru je veæi ili jednak novome
	for (p = *glavap; p->sljed && (p->sljed)->element < element; p = p->sljed);
		novi->sljed = p->sljed;
		p->sljed = novi;
  }
  return 1;
}
// ispis elemenata liste
void ispisi (atom *glava) {
  atom *p;
  for (p = glava; p != NULL; p = p->sljed) {
    printf ("Na adresi %p je %d koji gleda na %p\n", 
			p, p->element, p->sljed);
  }
}
// trazenje elementa liste
// vraca pokazivac na trazeni element ili NULL ako ga ne nadje
atom *trazi1 (atom *glava, tip element) {
  atom *p;
  for (p = glava; p != NULL; p = p->sljed) {
	if (p ->element == element) return p;
  }
	return NULL;
}

// trazenje elementa liste - inacica 2
atom *trazi2 (atom *glava, tip element) {
  atom* p;
  for (p = glava; p && p->element != element; p = p->sljed);
  return p;
}

// trazenje elementa liste - inacica 3
atom *trazi3 (atom *glava, tip element) {
  for (; glava && glava->element != element; glava = glava->sljed);
  return glava;
}

// brisanje elementa liste po kljucu
// koristenjem funkcije trazi
int brisi (atom **glavap, tip element) {
  atom *p, *pp;
  if ((p = trazi1 (*glavap, element)) == NULL) //ili trazi2 ili trazi3
	return 0; 
	if (p == *glavap) {	// Brisanje s pocetka liste
		pp = (*glavap)->sljed;
		free (*glavap);
		*glavap = pp;
	} else {		    // Brisanje iza clana liste
		// pronadji prethodni atom
		for (pp = *glavap; pp->sljed != p; pp = pp->sljed);
		// Povezi prethodni atom sa sljedbenikom izbrisanog cvora
		pp->sljed = p->sljed;
		// oslobodi memoriju zauzetu elementom koji se brise
		free (p);
	}
	return 1;
}

// Brisanje elementa liste po kljucu
// Objedinjuje traženje i brisanje
int brisi1 (atom **glavap, tip element) {
	atom *p;
  for (; *glavap && (*glavap)->element != element; glavap = &((*glavap)->sljed));
  if (*glavap) {
	p = *glavap;
	*glavap = (*glavap)->sljed;
	free (p);
	return 1;
  } else {
	return 0;
  }
}
int main (void) {
  int element, j; // element i brojac elemenata
  atom *glava;		// glava liste
  FILE *fi;				// ulazna datoteka
  // inicijalizacija
  fi = fopen ("UlazZaListu.txt", "r");
  if (!fi) exit (1);
  glava = NULL;
  j = 0;
  // citanje i dodavanje elemenata
  while (fscanf (fi, "%d", &element) != EOF) {
    printf  ("%d. ulazni podatak je %d \n", ++j, element);
    if ((dodaj (&glava, element))) {
      ispisi (glava);
		} else {
      printf ("Nema vise mjesta\n");
	    break;
    }
  }
  fclose (fi);
  printf ("\n");
	// trazenje i brisanje elemenata
  do {
	ispisi (glava);
    printf ("Upisite element koji se brise >");
    scanf ("%d", &element);
  } while (brisi (&glava, element));
  //} while (brisi1 (&glava, element));
  printf  ("Nema trazenog elementa!\n");
  return 0;
}
