#include <stdio.h>
#define MAXSTOG 100
struct s {
  int  sifraIspit;
  long sifraStudent;
  int  ocjena;
};
typedef struct s zapis; 

int dodaj(zapis stavka, zapis stog[], int n, 
int *vrh) {
	// ako je stog pun
	if (*vrh >= n-1) return 0;
	// ako ima mjesta na stogu
	(*vrh)++;					
	stog [*vrh] = stavka;
return 1;
} 
int skini (zapis *stavka, zapis stog[], int *vrh) {
   // ako je stog prazan
   if (*vrh < 0) return 0;
   // ako ima zapisa na stogu
   *stavka = stog[*vrh];
	(*vrh)--;
	return 1; 
}
int main() {
   zapis z, stog[MAXSTOG], pomStog[MAXSTOG];
   int i = 0, vrh = -1, pomVrh = -1;
   // ucitavanje elemenata stoga
   do {
	  printf("\nUpisite sifru ispita, sifru studenta i ocjenu>");
      scanf("%d %ld %d", &z.sifraIspit, 
                         &z.sifraStudent, &z.ocjena);
	  // prekini ucitavanje ako je za ocjenu ucitana 0 ili ako je stog pun
   } while (z.ocjena && dodaj (z, stog, MAXSTOG, &vrh));
   // brisanje zapisa s neprolaznim ocjenama koristenjem pomocnog stoga:
   // 1. premjesti sve zapise s prolaznom ocjenom na pomocni stog
   while (skini(&z, stog, &vrh)) { 
      if (z.ocjena > 1)
         dodaj(z, pomStog, MAXSTOG, &pomVrh); 
   }
   // 2. premjesti nazad na pocetni stog zapise s pomocnog stoga
   while (skini(&z, pomStog, &pomVrh)) { 
      dodaj(z, stog, MAXSTOG, &vrh); 
      // kontrolni ispis
      printf("Sifra ispit, z.sifraStudent, z.ocjena = %d\n", z.sifraIspit, z.sifraStudent, z.ocjena); 
   }
   return 0;
}
