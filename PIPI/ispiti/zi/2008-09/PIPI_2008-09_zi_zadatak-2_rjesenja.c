#include <stdio.h>
#include <ctype.h>

#define MAXM 100

void statistika_matrice(char *matrica, int n, int *brZnam, int *brSlova);


int main() {

	char mat[MAXM][MAXM] = {{'1', '2', 'Z', '9', 'z'},
						   {'m', '*', 'a', 'a', '6'},
						   {'0', '0', 'b', 'k', '$'},
						   {'3', 'H', '0', 'D', '#'},
						   {'p', 'K', 'g', '!', 'D'}};

	int broj_znamenki, broj_slova;

	//Ovo je poziv
	statistika_matrice(&mat[0][0], 5, &broj_znamenki, &broj_slova);

	printf("Broj znamenki iznad dijagonale je %d, a broj slova je %d", broj_znamenki, broj_slova);

	return 0;
}


void statistika_matrice(char *matrica, int n, int *brZnam, int *brSlova)
{
	int i, j, od = 1, znam = 0, slova = 0;
	char temp;

	for (i = 0; i < n; i++) {
		for (j = i * 1 + 1; j < n; j++) {
			temp = *(matrica + i*MAXM + j);

			if (isdigit(temp))
				znam++;

			if (isalpha(temp))
				slova++;

		}
	}

	*brZnam = znam;
	*brSlova = slova;
}
