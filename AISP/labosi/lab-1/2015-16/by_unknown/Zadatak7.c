#include <stdio.h>
#include <math.h>
#include <malloc.h>
int *kvadriraj(int *polje, int n) {
	int *novopolje;
	int i;
	novopolje = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) *(novopolje + i) = pow(*(polje + i), 2);
	return novopolje;
}
int main(void) {
	int i, n, *niz, *novi;
	printf("Unesi broj clanova niza:\n");
	scanf("%d", &n);
	niz = (int*)malloc(n*sizeof(int));
	printf("Unesi clanove niza:\n");
	for (i = 0; i < n; i++) scanf("%d", &*(niz + i));
	novi = kvadriraj(niz, n);
	printf("Clanovi kvadriranog niza:\n");
	for (i = 0; i < n; i++) printf("%d ", *(novi + i));
	free(novi);
	return 0;
}
