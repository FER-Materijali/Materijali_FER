#include <stdio.h>
#include <math.h>
int main (void) {
	int n, i;
	double suma=0;
	double razlika;
	do {
		printf("unesi vrijednost članova sume\n");
		scanf ("%d", &n);
	} while ((n<1) || (n>1000));

	for (i = 0; i <=n; ++i) {
		/* česta greška je u razlomak poslati int, rezultat će biti 
		int bez obzira što je suma double, zato sam u brojnik stavio 1.0. 
		pow() osigurava promjenu predznaka  */
		suma += pow(-1, i+1)*(1.0/(2*i-1));
		printf("%f\n", suma);
	}
	suma*=4;
	printf("%f\n", suma);
	razlika=suma-3.141593;
	if (razlika < 0) razlika*=(-1);
	printf("razlika iznosi: %f", razlika);
	return 0;
}
