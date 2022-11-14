#include <time.h>
#include <stdlib.h>
#include <ctype.h>


int udaljenost(char niz1[], char niz2[], int n) {
	int i, broj = 0;
	for (i=0; i<n; i++) {
		if (niz1[i] != niz2[i]) broj++;
	}
	return broj;
}

void slucajni(int n, char s[]) {
	static int init = 0;
	int i;
	char letter;
	if (init == 0) {
		srand((unsigned)time(NULL));
		init = 1;
	}
	for (i=0; i<n; i++) {
		do {
			letter = rand() % 128; /*moze i bolje, npr rand() % 58 + 65, samo 6 znakova iz ovog intervala nisu iz abecede*/
		} while (!isalpha(letter));
		s[i] = letter;
	}
	return;
}