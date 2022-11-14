#include <stdio.h>

void unija(int n1, int *s1, int n2, int *s2, int *nrez, int *rez)
{
	int i, j, k, novi = 1;
	*nrez = n1;
	for (i = 0; i < n1; ++i)				/*preslikava sve èlanove iz prvog skupa*/
		*(rez + i) = *(s1 + i);
	for (j = 0; j < n2; ++j) {				/*prolazi kroz sve èlanove drugog skupa*/
		for (k = 0; k < n1; ++k)
			if (*(s2 + j) == *(s1 + k))		/*usporeðuje sa svim èlanovima prvog skupa*/
				novi = 0;
		if (novi) {							/*ako se pojavi novi broj, dodaje ga u uniju*/
			*(rez + i) = *(s2 + j);
			++i;
			++(*nrez);
		}
		novi = 1;
	}

}

int unos(int *skup)
{
	int i = 0, j;
	int unos = 1;
	char novi;
	while (unos >= 1) {
		scanf("%d", &unos);
		novi = 1;
		if (unos >= 1) {
			for (j = 0; j < i; ++j)					
				if (unos == *(skup + j))		/*usporeðuje unos sa prethodnim unosima*/
					novi = 0;			
			if (novi) {							/*pohranjuje broj samo ako se ne pojavljuje prije*/
				*(skup + i) = unos;
				++i;
				
			}
		}
	}
	return i;
}

void ispis(int skup[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d%c ", skup[i], (i == (n - 1)) ? '\0' : ',');
}
