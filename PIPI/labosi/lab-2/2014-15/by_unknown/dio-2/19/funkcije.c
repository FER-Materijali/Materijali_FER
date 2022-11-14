#include"funkcije.h"
#include<stdlib.h>
#include<time.h>
void rasporedi (int *niz, int duljina, int *polje, int red, int stup, int maxstup) {
	int i, j, tmpred, tmpstup;
	for (i=0; i<red; ++i) {
		for (j=0; j<stup; ++j) {
			polje[i*maxstup+j]=-1;
		}
	}
	srand((unsigned)time(NULL));
	for (i=0; i<duljina; ++i) {
		do {
			tmpred=rand()%red;
			tmpstup=rand()%stup;
		} while (polje[tmpred*maxstup+tmpstup]!=-1);
		polje[tmpred*maxstup+tmpstup]=niz[i];
	}
}
void generiraj(int *polje, int n, int dg, int gg) {
	int i=0;
	srand((unsigned)time(NULL));
	for (i=0; i<n; ++i) {
		polje[i]=rand()%(gg-dg+1)+dg;
	}
}