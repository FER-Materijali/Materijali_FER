#include <stdio.h>
#include <malloc.h>

void selection2sort (int *A, int n, char smjer);

int main (void) {
	int n, i, *p;
	char smjer;
	
	printf("n smjer:\n");
	scanf("%d %c", &n, &smjer);
	while (n <= 0 || n > 10 || (smjer != '0' && smjer != '1')) {
		printf("n smjer:\n");
		scanf("%d %c", &n, &smjer);
	}
	
	p = (int *)malloc(sizeof(int) * n);
	if (!p) {
		printf("Nema dovoljno memorije!\n");
		return 1;
	}
	
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	
	selection2sort(p, n, smjer);
	
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d\n", p[i]);
	}
	
	free(p);
	return 0;
}

void selection2sort (int *A, int n, char smjer) {
	int start, end, max, min, i, pom1, pom2;
	
	if (smjer == '0') {
		for (start = 0, end = n-1; start < end; start++, end--) {
			for (max = start, min = start, i = start+1; i <= end; i++) {
				if (A[max] < A[i]) {
					max = i;
				} else if (A[min] > A[i]) {
					min = i;
				}
			}
			pom1 = A[max];
			pom2 = A[min];
			A[max] = A[end];
			A[min] = A[start];
			A[end] = pom1;
			A[start] = pom2;
		}
	} else if (smjer == '1') {
		for (start = 0, end = n-1; start < end; start++, end--) {
			for (max = start, min = start, i = start+1; i <= end; i++) {
				if (A[max] < A[i]) {
					max = i;
				} else if (A[min] > A[i]) {
					min = i;
				}
			}
			pom1 = A[max];
			pom2 = A[min];
			A[max] = A[start];
			A[min] = A[end];
			A[start] = pom1;
			A[end] = pom2;
		}
	}
}