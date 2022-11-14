#include<stdio.h>
int main (void) {
int x, i, j;
scanf ("%d", &x);
if (x<5 || x>20) {
	printf ("Neispravan broj");
} else {
	for (i=0; i<=x; ++i) {
		for (j=0; j<=i; ++j) {
			printf ("%.1f ", (float)j/10);
		}
		printf("\n");
	}
}
	return 0;
}