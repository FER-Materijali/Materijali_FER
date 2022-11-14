#include <ctype.h>
int brojNeSlova (char *niz) {
	int broj = 0;
	int i;
	for (i=0; niz[i]!=0; i++) {
		if (!isalpha(niz[i])) broj++;
	}
	return broj;
}
void caesarEncrypt (char *nizUlaz, char *nizIzlaz, int kljucKriptiranja) {
	int i;
	for (i=0; nizUlaz[i]!=0; i++) {
		if ((kljucKriptiranja + nizUlaz[i] > 122 && islower(nizUlaz[i])) || (kljucKriptiranja + nizUlaz[i] > 90 && isupper(nizUlaz[i]))) {
			nizIzlaz[i] = nizUlaz[i] - 26 + kljucKriptiranja;
		} else nizIzlaz[i] = nizUlaz[i] + kljucKriptiranja;
	}
	return;
}