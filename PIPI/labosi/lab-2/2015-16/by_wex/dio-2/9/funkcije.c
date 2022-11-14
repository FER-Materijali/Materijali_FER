void gen(char *niz, char *podniz, int pozicija, int duljina) {
	int i;
	for (i=0; i<duljina; i++) {
		*(podniz + i) = *(niz + pozicija + i);
	}
	return;
}

int sadrzi(char *niz, char *podniz) {
	int i, j;
	int sadrzan;
	for (i=0; *(niz+i)!=0; i++) {
		sadrzan = 1;
		for (j=0; *(podniz+j)!=0; j++) {
			if (*(podniz + j) != *(niz + i + j)) {
				sadrzan = 0;
				break;
			}
		}
		if (sadrzan == 1) break;
	}
	return sadrzan;
}