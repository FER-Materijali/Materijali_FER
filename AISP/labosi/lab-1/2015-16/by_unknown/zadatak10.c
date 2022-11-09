#include <stdio.h>
double f(double z, int k) {
	if (k == 0) return z;
	return f(z, k - 1) * (z * z * -1) / ((2 * k) * (2 * k + 1));
}
int main(void) {
	int k;
	double z = 0.5;
	double rez;
	printf("Unesite k:\n");
	scanf("%d", &k);
	rez = f(z, k);
	printf ("Rezultat je : %.15lf\n", rez);
	return 0;
}