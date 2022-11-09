// ModPolja.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys\timeb.h>
#define MAXA 1000

// izravno pronalazi mod i ucestalost u a[n]
int mode0 (int a[], int n, int *f) {
  int mode, i, temp;	// mod, trenutni, privremeni
  mode = a[0]; *f = 1; temp = 1;// prvi je mod, frekvencije 1
  for (i = 1; i < n; i++) {		// provjera ostalih
    if (a[i] != a[i - 1]) {		// trenutni razlicit od prethodnog
      temp = 1;					// nadjen je novi element
    } else {
      temp++;					// povecaj ucestalost novog
      if (temp > *f) {			// da li je trenutni novi mod ?
        *f = temp; mode = a[i];	// zapamti mod i ucestalost
      }
    }
  }
  return mode;	// vrati mod
	// frekvencija se vraca kroz *f
}
// rekurzivno pronalazi mod i ucestalost u a[0:i]
int rmode0 (int a[], int i, int *f) {
  int mode;
  if (i == 0) {					// osnovni slucaj
    mode = a[0]; *f = 1;		// prvi je mod, frekvencije 1
  } else {
    mode = rmode0 (a, i - 1, f);	// rekurzivni mod svih prethodnika
    if (a[i] == a[i - *f]) {		// da li trenutnome prethodi *f jednakih? 
			// novi mod, ili stari mod, ali s uveæanom uèestalošæu
      mode = a[i]; (*f)++;			// zapamti mod i ucestalost
    }
  }
  return mode;	// vrati mod
}
// rekurzivni postupak transformiran u iterativni
int rmode1(int a[], int n, int *f) {
  int mode, i;
  mode = a[0]; *f = 1;					// prvi je mod, frekvencije 1
  for (i = 1; i < n; i++) {			
    if (a[i] == a[i - *f]) {			// da li trenutnome prethodi *f jednakih?
      mode = a[i]; (*f)++;				// zapamti mod i ucestalost
    }
  }
  return mode;	// vrati mod
}
// U sortiranom polju a pronalazi se mod i ucestalost.  
int main (void) {
  int a[MAXA], n, m;	// polje, broj clanova, najveci clan
  int i, j, pom;		// indeksi petlji, pomocna za sort
	int	broj, freq, p;	// broj ponavljanja, ucestalost, nadjeni mod
	struct timeb vrijeme1, vrijeme2; // poc. i zav. vrijeme
  long trajanje [3];	// vremena izvodjenja u ms
	// unos parametara
	// 1. n= 10, m= 5, broj=1
	// 2. n=100, m=10, broj=100000
  do {
	printf ("Upisite broj clanova polja i maks. clan >");
	scanf ("%d %d", &n, &m);
  } while (n > MAXA);
  printf ("Upisite broj obavljanja programa >");
  scanf ("%d",&broj);
  printf("Izracuni ce se ponoviti %d puta\n", broj);
  // inicijalizacija generatora pseudoslucajnih brojeva
  srand ((unsigned) time (NULL));
  // popunjavanje polja
  for (i = 0; i < n; i++) {
	// slucajne vrijednosti skalirane na maks. clan
    a[i] = rand () % (m+1);
  }
  // sortiranje polja
  for (i = 0; i < n - 1; i++) {	  // od prvog do predzadnjeg
    for (j = i; j < n; j++) {		// provjeri iza trenutnog
      if (a[i] > a[j]) {				// onaj iza je manji
		// zamjena trenutnoga i manjega koji je iza
        pom = a[i]; a[i] = a[j]; a[j] = pom;
      }
    }
  }
  // ispis polja
  for (i = 0; i < n; i++) {	
		printf ("%4d", a[i]);
  }
  // svaka od funkcija poziva se broj puta
  // mjeri se ukupno vrijeme izvrsenja za svaki algoritam
  // izravno
  ftime (&vrijeme1);
  for (i = 1; i <= broj; i++) {
    p = mode0 (a, n, &freq);
  }
  ftime (&vrijeme2);
  trajanje [0] = 1000 * (vrijeme2.time - vrijeme1.time) +
             vrijeme2.millitm - vrijeme1.millitm;
  
  // rekurzivno
  ftime (&vrijeme1);
  for (i = 1; i <= broj; i++) {
    p = rmode0 (a, n-1, &freq);
  }
  ftime (&vrijeme2);
  trajanje [1] = 1000 * (vrijeme2.time - vrijeme1.time) +
             vrijeme2.millitm - vrijeme1.millitm;
	
  // iterativna transformacija rekurzivnog
  ftime (&vrijeme1);
  for (i = 1; i <= broj; i++) {
    p = rmode1 (a, n, &freq);
  }
  ftime (&vrijeme2);                                                 
  trajanje [2] = 1000 * (vrijeme2.time - vrijeme1.time) +
             vrijeme2.millitm - vrijeme1.millitm;
  printf ("\nMod = %d, ucestalost = %3d\n", p, freq);
  printf ("\nBroj milisekundi za %d izvodjenja:\n"
		      " mode0: %d\nrmode0: %d\nrmode1: %d\n",
						broj, trajanje [0], trajanje [1], trajanje [2]); 
  return 0;
}
