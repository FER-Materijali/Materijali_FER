#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define MAXBUF 512

void fatal (char *poruka) {
  fputs (poruka, stderr); fputs ("\n", stderr);
  exit (1);
}

int main (int argc, char *argv[]) {
	FILE *du, *di;
	long *polje;
	char buf [MAXBUF+1];
	int i, n;

  if (argc != 3)
		fatal ("Poziv programa: realloc stara.txt nova.txt");
	if ((du = fopen (argv[1], "r")) == NULL)
		fatal ("Ne moze se otvoriti ulazna datoteka");

  n = 0; polje = NULL;
  do {
		polje = (long *) realloc (polje, (n+1)*sizeof (long));
		if (polje == NULL)  fatal ("Nedovoljno memorije");
		polje[n++] = ftell (du);
	} while (fgets (buf, MAXBUF, du) != NULL);

  if ((di = fopen (argv[2], "w")) == NULL)
		fatal ("Ne moze se stvoriti izlazna datoteka");

  for (i = n-2; i >= 0; i--) {
		fseek (du, (long) polje[i], SEEK_SET);
		fgets (buf, MAXBUF, du);
		fputs (buf, di);
	}
	free (polje);  fclose (du); fclose (di);
	return 0;
}

