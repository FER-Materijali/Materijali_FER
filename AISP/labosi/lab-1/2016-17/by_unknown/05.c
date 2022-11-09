#include <stdio.h>
#include <malloc.h>

int binarnoTrazi(float *polje, int n, float x);

int main(void) {
	int n, i, indeks;
	float x, *A;
	
	printf("n: ");
	scanf("%d", &n);
	printf("x: ");
	scanf("%f", &x);
	
	A = (float *)malloc(sizeof(float) * n);
	
	for (i = 0; i < n; i++) {
		*(A + i) = (float)i*1.1;
		printf("%f\n", *(A + i));
	}
	
	indeks = binarnoTrazi(A, n, x);
	
	if (indeks == -1) {
		printf("Broj se ne nalazi u polju.\n");
	} else {
		printf("indeks: %d\n", indeks);
	}
	
	free(A);
	return 0;
}

int binarnoTrazi(float *polje, int n, float x) {
	int dolje = 0, gore;
	gore = (n-1);
	
	while (dolje <= gore) {
		if (*(polje + (gore-dolje)/2 + dolje) < x) {
			dolje = (gore-dolje)/2 + dolje + 1;
		} else if(*(polje + (gore-dolje)/2 + dolje) > x) {
			gore = (gore-dolje)/2 + dolje - 1;
		} else {
			return ((gore-dolje)/2 + dolje);
		}
	}
	
	return -1;
}