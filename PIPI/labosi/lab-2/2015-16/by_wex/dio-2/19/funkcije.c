#include <time.h>
#include <stdlib.h>

void rasporedi(int *one_d, int *two_d, int max_stup, int n, int r, int s) {
	int i, j;
	int broj_ispunjenih = 0;
	
	do {
		i = rand() % r;
		j = rand() % s;
		
		if (*(two_d+i*max_stup+j) == 0) {
			*(two_d+i*max_stup+j) = *(one_d+broj_ispunjenih);
			broj_ispunjenih++;
		}
	} while (broj_ispunjenih < n);
	
	if (n < r*s) {
		for (i=0; i<r; i++)
			for (j=0; j<s; j++)
				if (*(two_d+i*max_stup+j) == 0) *(two_d+i*max_stup+j) = -1;
	}
	
	return;
}

void generiraj(int *polje, int n, int dg, int gg) {
	int i;
	
	srand((unsigned)time(NULL));
	
	for (i=0; i<n; i++) {
		*(polje+i) = rand() % (gg - dg + 1) + dg;
	}
	
	return;
}