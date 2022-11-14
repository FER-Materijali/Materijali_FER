void unija (int n1, int *s1, int n2, int *s2, int *nrez, int *rez) {
	int i, j;
	int found;
	
	*nrez = 0;
	
	for (i=0; i<n1; i++) {
		*(rez+*nrez) = *(s1+i);
		(*nrez)++;
	}
	
	for (i=0; i<n2; i++) {
		found = 0;
		for (j=0; j<*nrez; j++) {
			if (*(rez+j) == *(s2+i)) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			*(rez+*nrez) = *(s2+i);
			(*nrez)++;
		}
	}

	return;
}