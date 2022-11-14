#include <stdlib.h>

void rasporedi(int *jednoPolje, int dvoPolje[][10], int n, int r, int s) {
	int i, j, rr, sr;
	for(i = 0; i < r; ++i)
		for (j = 0; j < s; ++j)
			dvoPolje[i][j] = -1;
	i = 0;
	while (i < n) {
		rr = rand() % r;
		sr = rand() % s;
		if (dvoPolje[rr][sr] == -1)
			dvoPolje[rr][sr] = jednoPolje[i++];
	}
}

void generiraj(int* polje, int n, int dg, int gg) {
	int i;
	for(i = 0; i < n; ++i)
		polje[i] = rand() % (gg - dg + 1) + dg;
}