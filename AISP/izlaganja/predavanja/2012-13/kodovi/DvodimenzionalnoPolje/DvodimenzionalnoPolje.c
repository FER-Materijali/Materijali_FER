// DvodimenzionalnoPolje.c
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define MAX_STU 8
#define MAX_RED 10
 
int polje(int a[], int max_s, int m, int n, int i, int j) {
	// a    : polje
	// max_s: deklarirani broj stupaca, potreban radi nalazenja pocetka retka
	// m, n : radne dimenzije matrice
	// i, j : indeksi retka i stupca clana

  printf("Ulaz: max_s=%d, m=%d, n=%d, i=%d, j=%d \n", max_s, m, n, i, j);
  if (i < 0 || i >= m || j < 0 || j >= n) {
    printf("\n\nNedopustena vrijednost indeksa\n");
    return 0;
  } else {
    printf ("Clan [ %d ][ %d ] polja s maksimalno %d stupaca \n",
                     i,    j,                    max_s);
    printf ("ekvivalentan je clanu jednodimenzionalnog polja [%d]=%d\n",
                                                 i*max_s+j, a[i*max_s+j]);
    return 1;
  }
}
int main (void) {
  FILE *fi;
  int i, j, m, n, a[MAX_RED][MAX_STU];
  fi = fopen ("UlazZaDvodimenzionalnoPolje.txt", "r");
  if (!fi) {
    printf ("Nema ulazne datoteke");
	return 1;
  }
  fscanf (fi, "%d %d\n", &m, &n);
  printf ("m=%d, n=%d\n", m, n);
	printf ("Dvodimenzionalno Jednodimenzionalno\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      fscanf (fi, "%d", &a[i][j]);
      printf("a[%d][%d]=%3d \t a[%2d]\n", 
								i, j, a[i][j], i*MAX_STU+j);
    }
  }
  fclose (fi);
  while (1) {
    printf("\nUpisite i, j >"); 
    scanf("%d %d", &i, &j);
    if (polje (&a[0][0], MAX_STU, m, n, i, j) != 1) break;
	  // Polje se predaje kao pokazivac na pocetak matrice da izostane upozorenje
  }
	return 0;
}

