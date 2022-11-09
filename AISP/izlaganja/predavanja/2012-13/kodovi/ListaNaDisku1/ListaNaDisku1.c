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
  // Fizièki upis i dodavanje po maticnom broju
  fseek(fl, 0L, SEEK_END);
  noviadr = ftell (fl);
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
int main () {
  FILE *fi, *fl;
  int j;
  tip element;
  cvor c;
  long glava, sljedeci;

  fi = fopen ("UlazZaListu1.txt", "r");
  fl = fopen ("Lista1", "w+b");
  if (!fi || !fl) exit (0);
  
  glava = 0;
  fwrite (&glava, sizeof (glava), 1, fl);
  
  j = 0;
  while (fscanf (fi, "%d", &element.kljuc) != EOF) {
    printf ("\n%d. ulazni podatak je %d\n", ++j, element.kljuc);
    if (!dodaj (element, fl)) {
      printf("Nema vise mjesta\n");
      break;
    }
  }
  fclose (fi);
  fseek (fl, 0L, SEEK_SET);
  fread (&sljedeci, sizeof (sljedeci), 1, fl);
  while (sljedeci) {
    fseek (fl, sljedeci, SEEK_SET);
    fread(&c, sizeof (c), 1, fl);
    printf ("Na adresi %ld je %d\n",sljedeci, c.element.kljuc);
    sljedeci = c.smbr;
  }
  return 0;
}