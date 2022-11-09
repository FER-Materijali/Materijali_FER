#include <stdio.h>
#include <malloc.h>

double f(double z, int k);

int main(void) {
	double z = 0.5, r;
	int k;
	
	printf("Za prekinuti unesite negativnu vrijednost.\nk: ");
	scanf("%d", &k);
	while (k >= 0) {
		r = f(z, k);
		printf("%g\n", r);
		printf("k: ");
		scanf("%d", &k);
	}
	
	return 0;
}

double f(double z, int k) {
	if (k == 0) {
		return z;
	} else {
		return ((-1) * f(z, (k-1)) * z * z / ((2*k+1)*2*k));
	}
}