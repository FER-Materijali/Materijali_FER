#include <stdio.h>
double f(double x, int n) {
	if (n == 0 && x != 0) return 1;
	else return f(x, n - 1) * (x / n);
}
int main(void) {
	int n;
	double x, izracun;
	printf("Unesite x i n:\n");
	scanf("%lf %d", &x, &n);
	izracun = f(x, n);
	printf("Funkcija je vratila vrijednost %lf\n", izracun);
	return 0;
}