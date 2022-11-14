#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANKETA "anketa.bin"
#define PREDMETI "predmeti.bin"

int main()
{
	FILE *anketaDat;
	FILE *predmetiDat;

	struct {
		long sifra;
		char naziv[50 + 1];
	} predmet;

	struct {
		int sifra;
		int ocjene[20];
	} anketa;

	int i, j;

	srand(time(NULL));

	char predmeti[3][50 + 1] = {
		"Programiranje i programsko inzenjerstvo",
		"Digitalna logika",
		"Osnove elektrotehike"
	};

	anketaDat = fopen(ANKETA, "wb");
	predmetiDat = fopen(PREDMETI, "wb");

	for (i = 0; i < 3; i++) {
		predmet.sifra = i + 1;
		strcpy(predmet.naziv, predmeti[i]);
		fwrite(&predmet, sizeof predmet, 1, predmetiDat);
	}

	for (i = 0; i < 3; i++) {
		anketa.sifra = i + 1;
		for (j = 0; j < 20; j++)
			anketa.ocjene[j] = rand() % (5 - 1 + 1) + 1;

		fwrite(&anketa, sizeof anketa, 1, anketaDat);
	}

	fclose(anketaDat);
	fclose(predmetiDat);

	return 0;
}
