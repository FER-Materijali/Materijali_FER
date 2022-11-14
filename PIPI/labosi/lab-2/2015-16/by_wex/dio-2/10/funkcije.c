int broj(char niz[], char znak) {
	int ponavljanja = 0;
	int i;
	for (i=0; niz[i]!=0; i++) {
		if (niz[i] == znak) ponavljanja++;
	}
	return ponavljanja;
}

void kodiraj(char src[], char dest[]) {
	int i;
	int dest_len = 0;
	for (i=0; src[i]!=0; i+=broj(src, src[i])) {
		dest[dest_len] = src[i];
		dest[dest_len+1] = broj(src, src[i]) + 48;
		dest_len += 2;
	}
	return;
}