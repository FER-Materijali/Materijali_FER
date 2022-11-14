int sazetak(char *ulaz) {
	int s = 0, i;
	for (i=0; *(ulaz+i)!=0; i++) {
		s += *(ulaz+i);
	}
	s %= 128;
	return s;
}

void dodajZnak(char *ulaz, int broj) {
	int i;
	for (i=0;; i++) {
		if (*(ulaz+i) == 0) {
			*(ulaz+i) = broj;
			return;
		}
	}
}