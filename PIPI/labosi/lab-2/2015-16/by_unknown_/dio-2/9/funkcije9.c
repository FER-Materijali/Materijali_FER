void genPodniz(char *niz, char *podNiz, int pocPozicija, int duljPodniz)
{
	int i, j;
	for (i = pocPozicija, j = 0; j < duljPodniz; ++i, ++j) {
		*(podNiz + j) = *(niz + i);
		if (*(niz + i) == '\0')
			break;
	}
	*(podNiz + j) = '\0';
}

int sadrziPodniz(char *niz, char *podNiz)
{
	int i, j, sadrzi = 1;
	for (i = 0; *(niz + i) != '\0'; ++i) {
		sadrzi = 1;
		for (j = 0; *(podNiz + j) != '\0'; ++j)
			if (*(niz + i + j) != *(podNiz + j)) {
				sadrzi = 0;
				break;
			}
		if (sadrzi)
			return 1;
	}
	return 0;
}