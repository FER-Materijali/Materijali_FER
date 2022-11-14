#include <stdlib.h>
#include <time.h>

void simulirajIgru(int brojIgraca, int brojKrugova, int bodovi[][10])
{
	int r, kraj = 0, i ,j, k, igrac;
	int igraci[10], pocetanBroj;
	for (i = 0; i < 10; ++i)
		igraci[i] = i + 1;
	pocetanBroj = brojIgraca;
	srand(time(NULL));
	for (i = 0; i < brojKrugova && !kraj; ++i) {
		r = rand() % brojIgraca + 1;
		igrac = igraci[r - 1];
		++bodovi[0][igrac - 1];
		for (j = 0; j < pocetanBroj; ++j)
			if ((bodovi[0][igrac - 1] - bodovi[0][j]) == 2) {
				bodovi[1][igrac - 1] = i + 1;
				for(k = r - 1; k < pocetanBroj; ++k)
					igraci[k] = igraci[k + 1];
				--brojIgraca;
				break;
			}
	if (brojIgraca == 1)
		kraj = 1;
	}
}