void minmax(int *min, int *max, int *ary, int x, int y, int xmax, int ymax) {
	int i, j;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (j == 0 && i == 0) {
				*min = *(ary + j + i * ymax);
				*max = *(ary + j + i * ymax);
			}
			
			if (*(ary + j + i * ymax) > *max) { *max = *(ary + j + (i * ymax)); }
			if (*(ary + j + i * ymax) < *min) { *min = *(ary + j + (i * ymax)); }
		}
	}
	
	return;
}

int dobreDimenzije(int x, int y, int xmax, int ymax) {
	if (x > xmax) return 0;
	if (y > ymax) return 0;
	return 1;	
}