
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define r(i,j) r[(i)*n+(j)]

void fatal (char *poruka) {
  fputs (poruka, stderr); fputs ("\n", stderr);
  exit (1);
}

int main() {
  int *p, n, pom, i, j;
  long *r;
  FILE *d;
  d = fopen ("polje", "r");
  if (d == NULL) fatal("Ne mogu otvoriti datoteku");
  for (n = 0; fscanf(d, "%d", &pom) == 1; n++);
  fseek (d, 0L, SEEK_SET);

  p = (int *) malloc (n * sizeof (int));
  if (p == NULL) 
    fatal ("Nema dovoljno memorije za ucitati polje");

  for (n = 0; fscanf(d, "%d", &p[n]) == 1; n++);
  fclose (d);

  if ((r = (long *) malloc (n*n*sizeof(long))) == NULL)
    fatal ("Nema dovoljno memorije za rezultat");
  for (j = 0; j < n; j++) {
    r(0,j) = p[j];
    for (i = 1; i < n; i++) {
      r(i,j) = r(i-1,j) * r(0,j);
    }
  }
  free (p);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf ("%10ld", r(i,j));
    }
    printf ("\n");
  }
  d = fopen ("npolje", "wb");
  
  fwrite (&n, sizeof (int), 1, d);
  fwrite (r, sizeof (long), n*n, d);
  
  fclose (d);
  free (r);
  return 0;
}




