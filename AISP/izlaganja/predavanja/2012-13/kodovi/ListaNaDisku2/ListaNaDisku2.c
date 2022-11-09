#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
  int kljuc;
} tip;

typedef struct {
  tip element;
  long smbr;
} cvor;

int dodaj (tip element, FILE *fl) {
  // Dodavanje u listu sortiranu po rastucoj
  // vrijednosti maticnog broja
  long noviadr, prethodni, sljedeci;
  cvor c, novi;

  // Ima li u listi brisanih?
  fseek(fl, 4L, SEEK_SET);
  fread (&sljedeci, sizeof(sljedeci), 1, fl);
  if (sljedeci > 0) {
	// Ima, zapisat cemo na mjesto prvog iz liste brisanih
	noviadr = sljedeci;
	// Prespajanje glave brisanih
    fseek (fl, sljedeci, SEEK_SET);
    fread (&c, sizeof (c), 1, fl);
  	fseek(fl, 4L, SEEK_SET);
    fwrite (&(c.smbr), sizeof(sljedeci), 1, fl);
  } else {
    // Nema, dodavanje na kraj datoteke
    fseek(fl, 0L, SEEK_END);
    noviadr = ftell (fl);
  }
  // Fizièki upis i dodavanje po maticnom broju, jednako kao ListaNaDisku1
  novi.smbr = 0;
  novi.element = element;
  prethodni = 0;
  fseek (fl, 0L, SEEK_SET);
  fread (&sljedeci, sizeof(sljedeci), 1, fl);
  while (sljedeci) {
    fseek (fl, sljedeci, SEEK_SET);
    fread (&c, sizeof (c), 1, fl);
    if (c.element.kljuc > element.kljuc) {
      // novi se ubacuje ispred
      novi.smbr = sljedeci;
      break;
    }
    prethodni = sljedeci + sizeof (c.element);
    sljedeci = c.smbr;
  }
	// Povezivanje prethodnog
  fseek (fl, prethodni, SEEK_SET);
  if (fwrite (&noviadr, sizeof (noviadr), 1, fl) != 1) return 0;
  fseek (fl, noviadr, SEEK_SET);
  if (fwrite (&novi, sizeof(novi), 1, fl) != 1) return 0;
  return 1;
}
int brisi (tip element, FILE *fl) {
  // Brisanje iz uzlazno sortirane liste
  long prethodni, sljedeci;
  cvor c;
  prethodni = 0;
  fseek (fl, 0L, SEEK_SET);
  fread (&sljedeci, sizeof(sljedeci), 1, fl);
  while (sljedeci) {
    fseek (fl, sljedeci, SEEK_SET);
    fread (&c, sizeof (c), 1, fl);
    if (c.element.kljuc == element.kljuc) {
		// Povezivanje prethodnog sa sljedecim 
		fseek (fl, prethodni, SEEK_SET);
		fwrite (&(c.smbr), sizeof(c.smbr), 1, fl);
		// Postavljanje na vrh liste brisanih
		fseek (fl, 4L, SEEK_SET);
		fread (&(c.smbr), sizeof(c.smbr), 1, fl);
		fseek (fl, 4L, SEEK_SET);
		fwrite (&sljedeci, sizeof(sljedeci), 1, fl);
		fseek (fl, sljedeci, SEEK_SET);
		fwrite (&c, sizeof(c), 1, fl);
		return 1;
    } else if (c.element.kljuc > element.kljuc) {
		// Nema smisla tražiti dalje, nije nasao
		return 0;
		}
    prethodni = sljedeci + sizeof (c.element);
    sljedeci = c.smbr;
  }
  return 0;
}

void lista (FILE *fl, long pozicijaglave, char *nazivliste) {
	// Ispisuje listu zadanu pozicijom glave: 0L lista, 4L lista brisanih
  long sljedeci;
  cvor c;
  printf ("%s\n", nazivliste);
  fseek (fl, pozicijaglave, SEEK_SET);
  fread (&sljedeci, sizeof (sljedeci), 1, fl);
  while (sljedeci) {
    fseek (fl, sljedeci, SEEK_SET);
    fread(&c, sizeof (c), 1, fl);
    printf ("Na adresi %ld je %d\n", sljedeci, c.element.kljuc);
    sljedeci = c.smbr;
  }
}
int main () {
  FILE *fi, *fl;
  int j;
  tip element;
  long glava, glavabrisanih;
  char op[80];
  fi = fopen ("UlazZaListu2.txt", "r");
  fl = fopen ("Lista2", "w+b");
  if (!fi || !fl) exit (0);
  glava = 0; glavabrisanih = 0;
  fwrite (&glava, sizeof (glava), 1, fl);
  fwrite (&glavabrisanih, sizeof (glavabrisanih), 1, fl);
  j = 0;
  while (fscanf (fi, "%d", &element.kljuc) != EOF) {
    printf ("\n%d. ulazni podatak je %d\n", ++j, element.kljuc);
    if (!dodaj (element, fl)) {
      printf("Nema vise mjesta\n");
      break;
    }
  }
  fclose (fi);
	lista (fl, 0L, "Lista: ");
	while (1) {
		printf ("Unesite oznaku operacije (Dodaj,Brisi,Kraj)>");
		scanf ("%s", op);
		switch (tolower(op[0])) {
		case 'd':
  		printf ("Unesite kljuc elementa kojeg zelite dodati>");
		  scanf ("%d", &element.kljuc);
	    dodaj (element, fl);
			break;
		case 'b':
  		printf ("Unesite kljuc elementa kojeg zelite brisati>");
			scanf ("%d", &element.kljuc);
	    brisi (element, fl);
			break;
		case 'k':
			exit(0);
		}
		lista (fl, 0L, "Lista: ");
		lista (fl, 4L, "Lista brisanih: ");
	}
	return 0;
}