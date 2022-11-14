#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char generirajZnak(int vrsta) {
	char znak;
	
	if (vrsta == 1) {
		do {
			znak = rand() % 58 + 65;
		} while (!isalpha(znak));
	} else if (vrsta == 2) {
		znak = rand() % 10 + 48;
	} else if (vrsta == 3) {
		znak = rand() % 3;
		if (znak == 0) znak = '!';
		else if (znak == 1) znak = '?';
		else if (znak == 2) znak = '/';
	}
	
	return znak;
}
void generirajLozinku(int ns, int nb, int ni, char izl[]) {
	int pozicija;
	char znak;
	int broj_slova = 0, broj_brojeva = 0, broj_interpunkc = 0;
	
	srand((unsigned)time(NULL));
	
	do {
		if (broj_slova < ns) {
			znak = generirajZnak(1);
			broj_slova++;
		} else if (broj_brojeva < nb) {
			znak = generirajZnak(2);
			broj_brojeva++;
		} else if (broj_interpunkc < ni) {
			znak = generirajZnak(3);
			broj_interpunkc++;
		}
		
		do {
			pozicija = rand() % (ns + nb + ni);
		} while (izl[pozicija]!=0);
		
		izl[pozicija] = znak;
	} while (broj_slova < ns || broj_brojeva < nb || broj_interpunkc < ni);
	
	return;
}