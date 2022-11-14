#include <stdio.h>

int main(void) {
	int broj, i, varijabla;
	scanf("%d", &broj);


	if ((broj > 20) || (broj < 5)) {
		printf("Neispravan broj\n");
		return 0;	
		/*osigurava završetak programa kad je unesen neispravan broj */
	}

	/* u ispisu se traži da se kroz redove jedna varijabla inkrementira	*/

	for (i = 0; i < broj; ++i)
	{
		varijabla=0;
		while (varijabla <= i) {
			printf("0.%d ", varijabla);
			varijabla++;
		}
		printf("\n");
	}
	return 0;
}
