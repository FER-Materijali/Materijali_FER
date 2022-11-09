#include <stdio.h>
#include <malloc.h>

typedef struct {
	int sifra;
	char naziv[51];
} zapis;

void obicanBubbleSort (zapis *A, int n, char smjer);

int main (void) {
	int n, i;
	char smjer, nl;
	zapis *p;
	
	printf("n smjer:\n");
	scanf("%d %c", &n, &smjer);
	while (n < 1 || n >10 || (smjer != '0' && smjer != '1')) {
		printf("n smjer:\n");
		scanf("%d %c", &n, &smjer);
	}
	
	p = (zapis *)malloc(sizeof(zapis) * n);
	if (!p) {
		printf("Nema dovoljno memorije!\n");
		return 1;
	}
	
	for (i = 0; i < n; i++) {
		printf("sifra: ");
		scanf("%d%c", &p[i].sifra, &nl);
		printf("naziv: ");
		fgets(p[i].naziv, 51, stdin);
	}
	
	obicanBubbleSort(p, n, smjer);
	
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d %s", p[i].sifra, p[i].naziv);
	}
	
	free(p);
	return 0;
}

void obicanBubbleSort (zapis *A, int n, char smjer) {
	int i, j;
	zapis pom;
	
	if (smjer == '0') {
		for (i = n; i > 1; i--) {
			for (j = 0; j < n-1; j++) {
				if (A[j].sifra > A[j+1].sifra) {
					pom = A[j];
					A[j] = A[j+1];
					A[j+1] = pom;
				}
			}
		}
	} else if (smjer == '1') {
		for (i = n; i > 1; i--) {
			for (j = 0; j < n-1; j++) {
				if (A[j].sifra < A[j+1].sifra) {
					pom = A[j];
					A[j] = A[j+1];
					A[j+1] = pom;
				}
			}
		}
	}
}