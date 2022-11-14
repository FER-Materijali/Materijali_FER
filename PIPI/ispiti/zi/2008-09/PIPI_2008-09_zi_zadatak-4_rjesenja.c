#include <stdio.h>

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

	int sifra, ocjene[5] = {0}, i;

	scanf("%d", &sifra);

	anketaDat = fopen(ANKETA, "rb");
	predmetiDat = fopen(PREDMETI, "rb");

	fseek(predmetiDat, (sizeof predmet) * (sifra - 1), SEEK_SET);

	fread(&predmet, sizeof predmet, 1, predmetiDat);

	fclose(predmetiDat);

	if (predmet.sifra == 0) {
		puts("Zapis ne postoji.");
		return 0;
	}

	while(fread(&anketa, sizeof anketa, 1, anketaDat) == 1) {
		if (anketa.sifra == sifra)
			break;
	}

	fclose(anketaDat);

	for (i = 0; i < 20; i++)
		ocjene[anketa.ocjene[i] - 1]++;

	printf("%-39s%5d%5d%5d%5d%5d\n", "Predmet", 1, 2, 3, 4, 5);

	for (i = 0; i < 64; i++)
		printf("-");

	printf("\n");

	printf("%-39s", predmet.naziv);

	for (i = 0; i < 5; i++)
		printf(" %4d", ocjene[i]);

	return 0;
}
