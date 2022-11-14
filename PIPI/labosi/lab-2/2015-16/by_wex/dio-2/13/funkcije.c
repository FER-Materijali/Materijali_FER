int convert(int broj, char *niz) {
	if (broj >= 0 && broj <= 59) {
		if (broj < 10) {
			*niz = 48;
			*(niz+1) = broj + 48;
		} else {
			*niz = broj / 10 + 48;
			*(niz+1) = broj % 10 + 48;
		}
		return 1;
	}
	return 0;
}

char *append(char *prvi, char *drugi) {
	int i, j;
	for (i=0; ; i++) {
		if (*(prvi+i) == 0) {
			for (j=0; j<2; j++) {
				*(prvi+i+j) = *(drugi+j);
			}
			break;
		}
	}
	return prvi;
}

void s_time(int sekunde, int *h, int *m, int *s) {
	*h = sekunde / 3600;
	*m = (sekunde / 60) % 60;
	*s = sekunde % 60;
	return;
}