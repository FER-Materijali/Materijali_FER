#include <stdio.h>
#include "funkcije1.h"
#define MAXGRAD 100

int main(void)
{
	int brojGrad, i, j;
	float koordinate[MAXGRAD][3];
	do {
		printf("Upisite broj gradova (od 3 do 100): ");
		scanf("%d", &brojGrad);
	} while (brojGrad < 3 || brojGrad > 100);

	for (i = 0; i < brojGrad; ++i) {
		printf("Upisite postanski broj i koordinate %d. grada: ", i + 1);
		for (j = 0; j < 3; ++j) {
			scanf("%f", &koordinate[i][j]);
			if (j != 0) {			/*drugi i treæi unost pretvara u radijane*/
				koordinate[i][j] = stupnjeviURadijane(koordinate[i][j]);
			}
		}
	}
	printf("Medjusobne udaljenost gradova:\n");
	for (i = 0; i < brojGrad; ++i) {				/*prvi grad koji usporedujemo*/
		for (j = i + 1; j < brojGrad; ++j) {		/*drugi grad koji usporedujemo*/
			printf("%.0f - %.0f: %.3f\n", koordinate[i][0], koordinate[j][0], izracunajUdaljenost(koordinate[i][1], koordinate[j][1], koordinate[i][2], koordinate[j][2]));
		}
	}
	return 0;
}