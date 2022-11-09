// ProsjekUStablu.c
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct {
  char artikl[15+1];
  float cijena;
} el;
typedef struct cv {
  el element;
  struct cv *lijevo;
  struct cv *desno;
} cvor;
typedef struct {
  float suma;
  int broj;
} pros;
// upisuje u stablo podatke: lijevo manji, desno veci
cvor *upis (cvor *korijen, el element) { 
  int smjer;
  if (korijen == NULL) {
    korijen = (cvor *) malloc (sizeof (cvor));
	if (korijen) {
		korijen->element = element;
		//strcpy (korijen->element.artikl, element.artikl);
		//korijen->element.cijena = element.cijena;
		korijen->lijevo = korijen->desno = NULL;
	} else {
		printf ("Nema dovoljno memorije!\n");
	}
  } else if ((smjer = strcmp (element.artikl, korijen->element.artikl)) < 0) {
    korijen->lijevo = upis (korijen->lijevo, element);
  } else if (smjer > 0) {
    korijen->desno  = upis (korijen->desno, element);
  } else {
    printf ("Podatak '%s' vec postoji!\n", element.artikl);
  }
  return korijen;
}
// ispis inorder
void ispisin (cvor *korijen) {
  if (korijen != NULL) {
    ispisin (korijen->lijevo);
    printf ("%-15s %6.2f\n", korijen->element.artikl, korijen->element.cijena);
    ispisin (korijen->desno);
  }        
}
// sumiranje cijena i brojanje elemenata element po element
void prosjek (cvor *korijen, pros *prs) {
  if (korijen != NULL) {
		prs->suma += korijen->element.cijena;
		prs->broj++;
    prosjek (korijen->lijevo, prs);
    prosjek (korijen->desno, prs);
  }
}
// brojanje elemenata stabla
int prebroji (cvor *korijen) {
  if (korijen != NULL) {
    return prebroji (korijen->lijevo) + 1 + prebroji (korijen->desno);
  } else {
    return 0;
  }
}
// sumiranje cijena i brojanje elemenata po podstablima
pros prosjek1 (cvor *korijen) {
  pros prs, prslijevo, prsdesno;
  if (korijen != NULL) {
    prslijevo = prosjek1 (korijen->lijevo);
    prsdesno = prosjek1 (korijen->desno);
    prs.broj = prslijevo.broj + 1 + prsdesno.broj; 
    prs.suma = prslijevo.suma + korijen->element.cijena + prsdesno.suma;
  } else {
    prs.broj = 0; prs.suma = 0;
  }
  return prs;
}
int main(void) {
  FILE *fi;			// ulazna datoteka
  int j;			// brojac elemenata
  cvor *korijen;		// pokazivac na korijen
  el element;		// sadrzaj cvora
  pros prs, prs1;	// broj elemenata i suma cijena
  // inicijalizacija
  prs.suma = 0.; prs.broj = 0;
  fi = fopen ("UlazZaProsjekUStablu.txt", "r");
  if (!fi) {
    printf ("Nema ulaznih podataka\n");
	return 1;
  }
  // citanje i upis
  j = 1;
  korijen = NULL;
  while (fscanf (fi, "%s %f", element.artikl, &element.cijena) != EOF) {
    printf ("%2d. ulazni podatak je %-15s %6.2f\n", j++, element.artikl, element.cijena);
    korijen = upis (korijen, element);
  }
  fclose (fi);

  // ispis, racun sume cijena i broja elemenata
  getchar ();
  ispisin (korijen);
  getchar ();
  prosjek (korijen, &prs);
  if (prs.broj) {
    printf ("Suma=%f, Broj cvorova=%d, Prosjek=%f\n",
			prs.suma, prs.broj, prs.suma / prs.broj);
	printf ("Broj cvorova (bez argumenta funkcije) = %d\n", prebroji (korijen));
	printf ("Izracunato na drugi nacin:\n");
	prs1 = prosjek1(korijen);
	printf ("Suma=%f, Broj cvorova=%d, Prosjek=%f\n",
			prs1.suma, prs1.broj, prs1.suma / prs1.broj);
	// varijante:
	printf ("Prosjek varijanta a) = %f\n",
			prs1.suma / prebroji (korijen));
	printf ("Prosjek varijanta b) = %f\n",
			(prosjek1 (korijen)).suma / (prosjek1 (korijen)).broj);
	getchar ();
  }
	return 0;
}