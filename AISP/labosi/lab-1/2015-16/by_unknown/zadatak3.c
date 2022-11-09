#include <stdio.h>
double pi(int n) {
	if (n > 1) {
		if (n % 2 == 0) return pi(n - 1) - (4 * ((double)1 / ((2 * n) - 1)));
		else return pi(n - 1) + (4 * ((double)1 / ((2 * n) - 1)));
	}
	if (n == 1) return 4;
}
int main(void) {
	int n;
	double brojpi;
	printf("Unesi n: \n");
	scanf("%d", &n);
	brojpi = pi(n);
	printf("Broj pi = %lf\n", brojpi);
	return 0;
}