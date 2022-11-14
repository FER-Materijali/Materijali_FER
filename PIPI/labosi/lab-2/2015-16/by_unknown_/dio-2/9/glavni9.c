#include <stdio.h>
#include <string.h>
#include "funkcije9.h"
#define MAXLEN 300

int main(void)
{
	char unos1[MAXLEN + 1], unos2[MAXLEN + 2], podNiz[6];
	int duljPod, brojac = 0, i;
	printf("Prvi niz: ");
	gets(unos1);
	printf("Drugi niz: ");
	gets(unos2);
	do {
		printf("Duljina podniza za usporedbu nizova: ");
		scanf("%d", &duljPod);
	} while (duljPod > 5 || duljPod < 2 || duljPod > strlen(unos1) || duljPod > strlen(unos2));

	for (i = 0; i <= strlen(unos1) - duljPod; ++i) {
		genPodniz(unos1, podNiz, i, duljPod);
		if (sadrziPodniz(unos2, podNiz))
			++brojac;
	}
	printf("Slicnost nizova '%s' i '%s' iznosi %f\n", unos1, unos2, (float)brojac / i);

	return 0;
}