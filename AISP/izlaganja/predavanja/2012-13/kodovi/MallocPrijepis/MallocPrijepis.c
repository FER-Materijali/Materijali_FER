#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
void fatal (char *poruka) {
  fputs (poruka, stderr); fputs ("\n", stderr);
  exit (1);
}
#define MAXREDAKA 1000
#define MAXBUF 512
int main (int argc, char *argv[]) {
  FILE *d;
  char *redak[MAXREDAKA];
  char buf[MAXBUF+1];
  int i, n;
  if (argc != 3)
    fatal ("Poziv programa: prijepis stara nova");
  if ((d = fopen (argv[1], "r")) == NULL)
    fatal ("Ne moze se otvoriti ulazna datoteka");
  n = 0;
  while (fgets (buf, MAXBUF, d) != NULL && n < MAXREDAKA) {
    redak [n] = (char *) malloc (strlen (buf) + 1);
    if (redak[n] == NULL)fatal ("Nedovoljno memorije!");
    strcpy (redak[n], buf);
    n++;
  }
  fclose (d);
  if ((d = fopen (argv[2], "w")) == NULL)
    fatal ("Ne moze se stvoriti izlazna datoteka");
  for (i = n-1; i >= 0; i--) {
    fputs (redak[i], d);  free (redak[i]);
  }
  fclose (d);
  return 0;
}


