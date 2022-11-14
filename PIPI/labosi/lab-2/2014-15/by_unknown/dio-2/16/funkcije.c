#include"funkcije.h"
void minMax (int *polje, int red, int stup, int *min, int *max) {
	int i, j;
	*min=*polje;
	*max=*polje;
	for (i=0; i<red; ++i) {
		for (j=0; j<stup; ++j) {
			if (*(polje+i*stup+j)<*min) {
				*min=*(polje+i*stup+j);
			} else if (*(polje+i*stup+j)>*max) {
				*max=*(polje+i*stup+j);
			}
		}
	}
}
int dobreDimenzije (int red, int stup, int maxred, int maxstup) {
	if (red<=maxred && stup <=maxstup) {
		return 1;
	} else {
		return 0;
	}
}