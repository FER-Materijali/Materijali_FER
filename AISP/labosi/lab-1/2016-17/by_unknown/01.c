#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void ispis (float *polje, int n);

int main (void) {
	int n, i;
	float *p;
	
	printf("n: ");
	scanf("%d", &n);
	
	p = (float *)malloc(sizeof(float) * n);
	if (!p) {
		printf("Nema dovoljno memorije!\n");
		exit(1);
	}
	
	printf("Polje:\n");
	for (i = 0; i < n; i++) {
		scanf("%f", (p+i));
	}
	
	ispis(p, n);
	
	free(p);
	
	return 0;
}

void ispis (float *polje, int n) {
	if (*polje < 0) {
		printf("%f\n", *polje);
	}
	if (n > 1) {
		ispis((polje+1), (n-1));
	}
}