#include "asp_massh.h"
#include <stdio.h>

void ispisiPreciznost(float x, int p) {
		printf("%.*f\n", p, x);
}

int main() {
	ispisiPreciznost(15.329847143, 2);
	ispisiPreciznost(15.329847143, 3);
	ispisiPreciznost(15.329847143, 4);
	ispisiPreciznost(15.329847143, 5);
	
	return 0;
}

