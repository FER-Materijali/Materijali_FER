#define NULL 0

char* nadjiPodniz(char *ulaz, char *uzorak)
{
	int i, j;
	int isti = 1;
	for (i = 0; *(ulaz + i) != '\0'; ++i) {
		for (j = 0; *(uzorak + j) != '\0'; ++j)
			if (*(uzorak + j) != *(ulaz + i + j)) {
				isti = 0;
				break;
			}
		if (isti)
			return ulaz + i;
		isti = 1;
	}
	return NULL;
}

int izbaci(char *ulaz, char *uzorak)
{
	int i, j, k;
	char *pocetak;
	for (i = 0, k = 0; *(ulaz + i) != '\0'; ++i, ++k) {
		pocetak = nadjiPodniz(ulaz, uzorak);
		if (!pocetak)
			return 0;
		if (pocetak == ulaz + i)
			for (j = 0; *(uzorak + j) != '\0'; ++j, ++i);
		*(ulaz + k) = *(ulaz + i);
	}
	*(ulaz + k) = '\0';
	return 1;
}