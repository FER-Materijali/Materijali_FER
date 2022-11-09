// VisestrukaLista.c
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct tip {
  int mbr;
  char prezime[14+1];
};
struct at {
  struct tip element;
  struct at *smbr;
  struct at *sprez; 
};
typedef struct at atom;

// Dodavanje u listu 
// sortiranu po rastucoj vrijednosti maticnog broja
void DodajMBR (atom **glavap, atom *novi) {
#if 1
	// nadji pokazivac na atom s elementom vecim od elementa novog
	for (; *glavap && (*glavap)->element.mbr < novi->element.mbr;
								glavap = &((*glavap)->smbr));
	// glavap sadrzi adresu trazenog pokazivaca
	// *glavap sadrzi vrijednost tog pokazivaca
	novi->smbr = *glavap; // novi gleda na veceg po kljucu
	*glavap = novi;				// pokazivac smbr u cvoru koji prethodi novome
#else
	// Alternativno rješenje, s pomoænim pokazivaèem i while petljom:
	atom **pom;			// pom sadrzi adresu pokazivaca cvora
	pom = glavap;		// adresa pokazivaca na 1.clan
	while (*pom) {	// adresa pokazivaca na trenutni clan
		if ((*pom)->element.mbr < novi->element.mbr) {
			// Adresa pokazivaca na sljedeci atom
			pom = &((*pom)->smbr);
		}	else {
			break; // Skok iz petlje kad treba ubaciti novog
		}
	}
	// Izmjena pokazivaca smbr u cvoru koji prethodi novome
	novi->smbr = *pom;
	*pom = novi;
#endif
}

// Dodavanje u listu sortiranu po prezimenu
// analogno dodavanju po maticnom broju
void DodajPrezime (atom **glavap, atom *novi) {
#if 1
	for (;*glavap && strcmp((*glavap)->element.prezime,
				novi->element.prezime) < 0; glavap = &((*glavap)->sprez))
		;
  novi->sprez = *glavap;
	*glavap = novi;
#else
  // Alternativno rješenje, s pomoænim pokazivaèem i while petljom:
  atom **pom;
  pom = glavap;
  while (*pom) {
    if (strcmp((*pom)->element.prezime, novi->element.prezime) < 0) {
      pom = &((*pom)->sprez);
		} else {
      break;
    }
  }
  novi->sprez = *pom;
  *pom = novi;
#endif
}

// Trazenje clana za zadani maticni broj
int TraziMBR (atom *glava, int mbr, atom *trazeni) { // a) i b)
                       // c) ... atom **trazeni

  int nasao = 0;       // Podrazumijeva se da nije nasao
 
  while (glava) {       // Dok ima clanova liste  
    if (glava->element.mbr < mbr) {
      // maticni broj clana u listi manji od trazenoga => trazi dalje
       glava = glava->smbr;

    } else if (glava->element.mbr == mbr) {
      // maticni broj clana u listi jednak trazenom => nasao
      *trazeni = *glava;	 // a) i b) vrati atom na koji pokazuje glava
			// *trazeni = glava; // c) vrati pokazivac na nadjenog
      nasao = 1;      
			break;

    } else {
      // maticni broj clana u listi vecu id trazenog => nema ga
      break;
    }
  }
  return nasao;
}


void main (void) {
  FILE *fi;							// ulazna datoteka
  int j, mbr;						// brojac elemenata, maticni broj za pretragu
  struct tip element;		// element koji se dodaje u listu
  atom *glavambr,				// glava liste uredjene po mbr
		   *glavaprez;			// glava liste uredjene po prezimenu
	atom *p, *novi;				// pomocne varijable

	// inicijalizacija
	fi = fopen ("UlazZaVisestrukuListu.txt", "r");
  if (!fi) exit (1);
  glavambr = NULL;
  j = 0;

	// citanje ulaznih podataka 
	// i dodavanje u listu uredjenu po mbr
  while (fscanf (fi, "%d %s", &element.mbr,
                     &element.prezime) != EOF) {
    printf ("%d. ulazni podatak je %d %s\n",
       		  ++j, element.mbr, element.prezime);
    if ((novi = (atom *) malloc(sizeof(atom))) != NULL) {
      novi->element = element;
      novi->smbr = NULL;
      novi->sprez = NULL;
      DodajMBR (&glavambr, novi);
    } else {
      printf("Nema vise mjesta\n");
      break;
    }
  }
  fclose (fi);

	// ispis po mbr
  p = glavambr;
  printf  ("\nIspis po maticnom broju \n");
  while (p) {
    printf  ("Na adresi %p je %d %s\n", p, p->element.mbr, p->element.prezime);
    p = p->smbr;
  }

  // prolazak kroz listu uredjenu po mbr
	// i povezivanje u listu uredjenu po prezimenu
  glavaprez = NULL;
  novi = glavambr;
  while (novi) {
    DodajPrezime (&glavaprez, novi);
    novi = novi->smbr;
  }

	// ispis po prezimenu
  p = glavaprez;
  printf  (    "\nIspis po prezimenu \n");
  while (p) {
    printf  ("Na adresi %p je %d %s\n",p, p->element.mbr, p->element.prezime);
    p = p->sprez;
  }

  // trazenje clana visestruke liste po MBR
	// varijante:
	// a) vraca se atom, za koji treba rezervirati memoriju
  p = (atom *) malloc (sizeof(atom));
	
	// b) vraca se atom u deklariranu strukturu, npr. atom c;
	// bez prethodne naredbe malloc
	
	// c) vraca se adresa cvora, koja se smijesta u p
	// bez prethodne naredbe malloc

  do {          // ciniti...
    printf ("Upisite maticni broj >");
    scanf ("%d", &mbr);
    if (TraziMBR (glavambr, mbr, p)) {
      // b) : TraziMBR (glavambr, mbr, &c)
			// c) : TraziMBR (glavambr, mbr, &p)
      printf  ("Za maticni broj %d prezime je %s\n", mbr, p->element.prezime);
    } else {
      printf  ("Za maticni broj %d prezime nije nadjeno\n", mbr);
      break;    // Skok iz petlje i kraj
    }
  } while (1);  //... zauvijek 
  
	exit (0);
}
