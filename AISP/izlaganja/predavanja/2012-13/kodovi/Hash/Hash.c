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

#define BLOK 512L		// Blok na disku
#define N 350				// Ocekivani broj zapisa:    
#define C ((int) (BLOK / sizeof (struct zapis)))	// Broj zapisa u pretincu
#define M ((int) (N / C *1.3))	// Broj pretinaca, kapacitet 30% veci od minimalnog:
/*
#define C 1
#define M 5 
*/

struct zapis ulaz, pretinac [C];

void Pogreska (char *poruka) {
  fputs (poruka, stderr); fputs ("\n", stderr);
  exit (1);
}

void Isprazni (FILE *ft) {
  int i;
  for (i = 0; i < C; i++) pretinac [i].JMBG[0] = '\0';
  for (i = 0; i < M; i++) {
    fseek (ft, i*BLOK, SEEK_SET);
    fwrite (pretinac, sizeof (pretinac), 1, ft);
  }
  printf ("Tablica ispraznjena N=%d, C=%d, M=%d\n", N, C, M);
  printf ("Velicina pretinca = %d\n", sizeof (pretinac));
}

int OdrediPrim (int m) {
  int i, prim, kraj;
	printf ("Trazenje najveceg prim broja <= %d\n", m);
  prim = m+1;
  do {
    prim--;
    kraj = (int) pow ((double) prim, (double) 0.5);
    for (i = kraj; i > 0; i--) {
      printf ("%d/%d ", prim, i);
      if (prim % i == 0) break;
    }
  } while (i != 1);
  return prim;
}

int Kontrola (char JMBG[]) {
  int i, kz;
  long suma;
  char tez [12+1] = "765432765432";
  suma = 0; 
  for (i = 0; i < 12; i++) {
    suma += (JMBG[i] - '0') * (tez[i] - '0');
  }
  kz = 11 - (suma  % 11);
  if (kz == 10) kz = -1; // pogr. kontrolna znamenka
  if (kz == 11) kz = 0;
  return kz;
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
  i = Adresa (ulaz.JMBG, prim);
  // Upamti izraèunatu adresu kao poèetnu
  poc = i;
  do { // Ponavljaj dok ne upišeš ili ustanoviš da je datoteka puna    
		// Èitaj iz pretinca sve upisane zapise
    fseek (ft, i*BLOK, SEEK_SET);
    fread (pretinac, sizeof (pretinac), 1, ft);
    for (j = 0; j < C; j++) {
      if (pretinac[j].JMBG[0] != '\0') {   
				// Ako zapis nije prazan
				printf ("Vec upisani JMBG =");
				printf ("%s\n", pretinac[j].JMBG);
	      if (strncmp (pretinac[j].JMBG, ulaz.JMBG, VELJMBG) == 0) {
	      // Ako je upisani JMBG identièan ulaznom
					printf ("Vec postoji zapis s JMBG %s\n", ulaz.JMBG);
          return 1;
          }
      } else {
        // Upiši ulazni zapis na prazno mjesto
	      pretinac[j] = ulaz;
	      fseek (ft, i*BLOK, SEEK_SET);
	      printf ("U pretinac %d upisujem %d. zapis\n", i, j);
	      fwrite (pretinac, sizeof (pretinac), 1, ft);
        return 1;
      }
    }
    // U pretincu nema mjesta, prijeði ciklièki na sljedeæega
    i = (i + 1) % M;
    printf ("Nema mjesta, slijedi pretinac = %d\n", i);
  } while (i != poc); // Dok se ne ne vratiš na poèetni
  return 0;  // Niti u jednom zapisu nema mjesta
}  

void Ispis (FILE *ft) {
  // Ispis sadržaja tablice raspršenih adresa
  int i, j;
  printf("Ispis sadrzaja tablice \n");
  for (i = 0; i < M; i++) {
    fseek (ft, i*BLOK, SEEK_SET);
    fread (pretinac, sizeof (pretinac), 1, ft);
    for (j = 0; j < C; j++) {
      if (pretinac[j].JMBG[0] != '\0') {
				// Ako zapis nije prazan
				printf ("Zapis na adresi %d:", i);
				printf ("%s %s \n", pretinac[j].JMBG, pretinac[j].prezime);
      }
    }
  }
}

int Trazi (char mbr[], FILE *ft, int prim, struct zapis *ulaz) {
  int i, j, poc;
  i = Adresa (mbr, prim);
  // Upamti izraèunatu adresu kao poèetnu
  poc = i;
  do {  // Ponavljaj dok ne nadješ ili ustanoviš da ga nema
		printf ("Citam %d. zapis\n", i);
    fseek (ft, i*BLOK, SEEK_SET);
    fread (pretinac, sizeof (pretinac), 1, ft);
    for (j = 0; j < C; j++) {  
      if (pretinac[j].JMBG[0] != '\0') {
	       // Ako zapis nije prazan
				printf ("%d. upisani JMBG =%s\n", j, pretinac[j].JMBG);
 	      if (strcmp (pretinac[j].JMBG, mbr) == 0) {
	      // Ako je upisani JMBG identièan ulaznom 
					*ulaz = pretinac[j];
          return 1;
        }
      } else {
	       // Nema zapisa
	      return 0;
      }
    }
    // Pretinac je pun, prijeði ciklièki na sljedeæega
    i = (i + 1) % M;
  } while (i != poc); // Dok se ne ne vratiš na poèetni
	return 0; // Svi pretinci posjeæeni, zapis nije pronaðen
}

int main() {
  FILE *fi, *ft;
  char mbr [VELJMBG+1];
  int prim;
	if ((fi = fopen ("UlazZaHash.txt", "r")) == NULL)
		Pogreska ("Ne mogu otvoriti datoteku \"ulaz\"");
	if ((ft = fopen ("tablica","w+")) == NULL)
		Pogreska ("Ne mogu otvoriti datoteku \"tablica\"");
	printf ("Ulazni zapis je velicine %d\n", sizeof (ulaz));
  Isprazni (ft);
  Ispis (ft);
  // Odredi prim broj za dijeljenje
  prim = OdrediPrim (M);
  printf ("Prim broj za dijeljenje = %d\n", prim);
  // Èitaj slijedno JMBG, prezime, ime dok ima podataka
	getchar ();
  while (fscanf (fi, "%13s%s", ulaz.JMBG, ulaz.prezime) != EOF) {
    printf ("Procitan zapis %s %s \n", ulaz.JMBG, ulaz.prezime);
    if (Kontrola (ulaz.JMBG) == atoi (&ulaz.JMBG [12])) {
    // Ako je kontrolna znamenka ispravna
      if (!Upis (ulaz, ft, prim))
        Pogreska ("Tablica je puna\n");
    } else {
			printf ("Neispravan JMBG %s", ulaz.JMBG);
			printf(", kontrolna znamenka treba biti %d\n", Kontrola (ulaz.JMBG));
    }
		printf ("\n");
  }
  fclose (fi);
	getchar ();
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