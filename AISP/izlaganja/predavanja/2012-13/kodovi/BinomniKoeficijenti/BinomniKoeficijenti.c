// BinomniKoeficijenti.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys\timeb.h>
#define MAXRED 100

// vraca niz znakova c u zadanoj duljini n
char* nc (int c, int n) {
	static char s[80+1];
	s[n] = '\0';				// prirubi
  while (--n >= 0) s[n] = c;	// popuni
	return s;
}

// vraæa faktorijela (n), broj iteracija, zastavicu pogreške
long FAKT (int n, long *freq, int *errorflag) {
  int i;
  long p;
  p = 1;
  for (i = 2; i <= n; i++) {
    p *= i;
		if (p <= 0) *errorflag = 1;
    *freq += 1;
  }
  return p;
}
// binomni koeficijenti s pomoæu faktorijela
long BINOM (int n, int m, long *freq, int *errorflag) {
	long p;
  *freq += 1;
#if 1
	p = FAKT (n, freq, errorflag); 
	p /= FAKT (m, freq, errorflag);
	p /= FAKT (n - m, freq, errorflag);
	return p;
#else
  return FAKT (n, freq, errorflag) /
		     FAKT (m, freq, errorflag) /
				 FAKT (n - m, freq, errorflag);
#endif
}

// binomni koeficijenti rekurzivno
long BINOMR (int n, int m, long *freq) {
  *freq += 1;
  if ((m == 0) || (m == n)) return 1;
  return BINOMR (n-1, m, freq) + BINOMR (n - 1, m - 1, freq);
}

// Pascalov trokut
void Blaise (int n) {
  int i, j;
  long stari[MAXRED], novi[MAXRED];
  if (n >= MAXRED) return;
	printf("\nIzracunavanje Pascalovog trokuta\n");
  novi[0] = 1;
  for (i = 0; i < n; i++) {
    novi[i+1] = 1;
    for (j = 1; j <= i; j++) 
		  novi[j] = stari[j-1] + stari[j];
	  printf("%s", nc(' ', 2*(n-i)));
    for (j = 0; j <= i+1; j++) {
			printf ("%3d ", novi[j]);
      if (novi[j] < 0) {
	      printf ("\n za i=%d i j=%d broj postane prevelik\n", i, j);
	      exit (1);
      }
      stari[j] = novi[j];
    }
    printf ("\n");
  }
}

int main (void) {
  int n, m, i, j;	// n povrh m, indeksi petlje
  int broj;				// broj ponavljanja 
  long k;					// pojedinacni rezultat
	int errorflag;	// zastavica pogreske
  float f[2][2];	// trajanje i broj iteracija
  long trajanje, freq;
  struct timeb vrijeme1, vrijeme2;

  while (1) {
		// citanje parametara
		printf ("Upisite broj obavljanja programa >");
    scanf ("%d",&broj); // npr: 1, 10000
    if (broj <= 0) {
      printf("Gotovo!\n");
      break;
    }
		do {
      printf ("Upisite n, m >"); // npr: 12 5, 13 5
      scanf ("%d %d", &n, &m);
    } while ((n < m) || (n < 0) || (m < 0) || 
			       ((m == 0) && (n == 0)));

    // inicijalizacija
	  for (i = 0; i < 2; i++)
	    for (j = 0; j < 2; j++)
		    f[i][j] = 0;
    printf ("Program ce se ponoviti %d puta\n", broj);
	  errorflag = 0;
	  // koristenjem faktorijela
	  freq = 0;
    ftime (&vrijeme1);
    for (i = 1; i <= broj; i++) 
		  k = BINOM (n, m, &freq, &errorflag);
      ftime (&vrijeme2);
      trajanje = 1000 * (vrijeme2.time - vrijeme1.time) +
                      vrijeme2.millitm - vrijeme1.millitm;
      f[0][0] += trajanje;
      f[1][0] += freq;
      printf  (" BINOM : %d povrh %d = %ld %s\n",n, m, k, 
							  errorflag ? "(pogresno)" : "");
    
	  // rekurzivno
	  freq = 0;
    ftime (&vrijeme1);
    for (i = 1; i <= broj; i++) 
		  k = BINOMR (n,m,&freq);
    ftime (&vrijeme2);
    trajanje = 1000 * (vrijeme2.time - vrijeme1.time) +
                    vrijeme2.millitm - vrijeme1.millitm;
    f[0][1] += trajanje;
    f[1][1] += freq;
    printf (    " BINOMR: %d povrh %d = %ld\n", n, m, k);
	  
    // racun prosjecnih vremena i ispis rezultata
    for (i = 0; i < 2; i++) {
      f[0][i] = f[0][i] / (float) broj;
      f[1][i] = f[1][i] / (float) broj;
    }
    printf ("\nProsjecno vrijeme za %d izvodjenja:\n BINOM: %f\nBINOMR: %f\n", 
									broj, f[0][0], f[0][1]);
    printf ("\nBroj iteracija:\n BINOM: %ld BINOMR: %ld\n", 
			            (long) f[1][0], (long) f[1][1]); 
  }
	// Pascalov trokut
	while (1) {
		printf ("Unesite broj redaka Pascalovog trokuta >"); 
		scanf ("%d", &n);	// npr: 10
		if (n <= 0 || n >= MAXRED) return 0;
	    Blaise (n);
	}
}

