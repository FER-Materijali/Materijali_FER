void minMax(int m, int n, int stup, int *polje, int *min, int *max) {
	int i, j;
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			if (*(polje + i*stup + j) > *max || (i == 0 && j == 0)) *max = *(polje + i*stup + j);
			if (*(polje + i*stup + j) < *min || (i == 0 && j == 0)) *min = *(polje + i*stup + j); /* ne moze ici else if zbo mogucnosti polja velicine 1x1*/
		}
	}
	return;
}

int dobreDimenzije(int m, int n, int def_m, int def_n) {
	return (m <= 0 || m > def_m || n <= 0 || n > def_n) ? 0 : 1;
}