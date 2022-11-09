#include <stdio.h>
#include <malloc.h>

double exp(double x, int n, int *fakt, double *xpot);

int main (void) {
	int n, *fakt, i;
	float x, *A;
	double *xpot;
	
	printf("n: ");
	scanf("%d", &n);
	printf("x: ");
	scanf("%f", &x);
	
	A = (float *)malloc(sizeof(float) * (n));
	fakt = (int *)malloc(sizeof(int) * (n));
	xpot = (double *)malloc(sizeof(double) * (n));
	
	*(fakt) = 1;
	*(xpot) = 1;
	*(A) = (float)exp(x, 0, fakt, xpot);
	printf("  0: %f\n", *A);
	for (i = 1; i < n; i++) {
		*(fakt + i) = *(fakt + i - 1) * i;
		*(xpot + i) = *(xpot + i - 1) * (double)x;
		*(A + i) = (float)exp(x, i, fakt, xpot);
		printf("%3d: %f\n", i, *(A + i));
	}
	
	free(fakt);
	free(A);
	free(xpot);
	return 0;
}

double exp(double x, int n, int *fakt, double *xpot) {
	if (!n) {
		return 1;
	} else {
		return ((double)*(xpot+n)/((double)*(fakt + n)) + exp(x, n-1, fakt, xpot));
	}
}