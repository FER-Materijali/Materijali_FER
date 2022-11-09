#include <stdio.h>
#include <malloc.h>

typedef struct {
	int broj;
	char naziv[41];
} zapis;

void insertionSort (zapis *A, int n, char smjer);

int main (void) {
	int n, i;
	char c, nl;
	zapis *p;
	
	printf("n c:\n");
	scanf("%d %c", &n, &c);
	while (n > 10 || n <= 0 || (c != '0' && c != '1')) {
		printf("n c\n");
		scanf("%d %c", &n, &c);
	}
	
	p = (zapis *)malloc(sizeof(zapis) * n);
	if (!p) {
		printf("Nema dovoljno memorije!\n");
		return 1;
	}
	
	printf("clanovi polja:\n");
	for (i = 0; i < n; i++) {
		printf("broj mjesta:\n");
		scanf("%d%c", &p[i].broj, &nl);
		printf("naziv mjesta:\n");
		fgets(p[i].naziv, 41, stdin);
	}
	
	insertionSort(p, n, c);
	
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d %s", p[i].broj, p[i].naziv);
	}
	
	free(p);
	return 0;
}

void insertionSort (zapis *A, int n, char smjer) {
	int i, j;
	zapis pom;
	
	if (smjer == '0') {
		for (i = 1; i < n; i++) {
			pom = A[i];
			for (j = i-1; j >= 0 && pom.broj < A[j].broj; j--) {
				A[j+1] = A[j];
			}
			A[j+1] = pom;
		}
	} else if (smjer == '1') {
		for (i = 1; i < n; i++) {
			pom = A[i];
			for (j = i-1; j >= 0 && pom.broj > A[j].broj; j--) {
				A[j+1] = A[j];
			}
			A[j+1] = pom;
		}
	}
}