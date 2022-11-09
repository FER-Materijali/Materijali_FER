#include <stdio.h>
int aniz(int a0, int d, int n) {
   if (n == 0) return a0;
   else return d + aniz(a0, d, n-1);
}
int main () {
	int a0, d, n, nclan;
	while (1) {
		printf ("\nUpisite nulti clan, diferenciju i indeks zadanog clana >");
		scanf ("%d %d %d", &a0, &d, &n);
		if (n < 0) break;
		nclan = aniz (a0, d, n);
    printf ("\n %d. clan aritmetickog niza, s nultim clanom %d i diferencijom %d: %d \n", n, a0, d, nclan);
	}
	printf ("\nNegativni indeks clana %d\n", n);
	return 0;
}
