#include <stdio.h>

float kamrac (float g, int n, float p) {
// g – glavnica
// n – trajanje oroèenja u godinama
// p – kamatna stopa u postotcima
   if (n <= 0) return g;
   else return (1 + p / 100) * kamrac(g, n - 1, p);
}

// drugi nacin
float kamrac2 (float g, int n, float p) {
    if (n<=0) return g;
    else return kamrac2(g*(1+p/100), n-1, p);
}

int main () {
	float g, p, k1, k2;
	int n;
	while (1) {
		printf ("\nUpisite iznos glavnice, broj godina orocenja i kamatnu stopu>");
		scanf ("%f %d %f", &g, &n, &p);
		if (n < 0) break;
		k1 = kamrac (g, n, p);
    k2 = kamrac2 (g, n, p);
		printf ("\nGlavnica %10.2f orocena na %d godina uz kamatnu stopu %5.2f%% rezultira iznosom %10.2f",
					g, n, p, k1);
    printf("\ndrugi nacin %10.2f", k2);
	}
	return 0;
}