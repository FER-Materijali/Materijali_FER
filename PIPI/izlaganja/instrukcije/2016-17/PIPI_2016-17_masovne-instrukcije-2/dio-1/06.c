#include <stdio.h>

int main (void) {
	double suma=0, razlika;
	int n, i;
	do {
		printf("unesi broj članova\n");
		scanf("%d", &n);
	} while ((n<1) || (n>1000));

	for (i = 1; i <= n; ++i)
	{
		/* opet je u brojniku 1.0 kao u prošlom zadatku */
		suma+= 1.0/((2*i-1)*(2*i+1));
	}
	razlika = suma-0.5;
	if (razlika<0) razlika*=(-1);
	printf("razlika iznosti: %f", razlika);
	return 0;
}
