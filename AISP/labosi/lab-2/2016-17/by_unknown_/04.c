#include <stdio.h>

void spojiPolja (int *A, int *B, int *Rez, int n1, int n2);

int main (void) {
	int i, A[5] = {9, 7, 5, 3, 1}, B[5] = {8, 6, 4, 2, 0}, Rez[10];
	
	spojiPolja(A, B, Rez, 5, 5);
	
	for (i = 0; i < 10; i++) {
		printf("%d\n", Rez[i]);
	}
	
	return 0;
}

void spojiPolja (int *A, int *B, int *Rez, int n1, int n2) {
	int i, j, k;
	
	for (i = 0, j = 0, k = 0; i < n1 && j < n2;) {
		if (A[i] >= B[j]) {
			Rez[k++] = A[i++];
		} else {
			Rez[k++] = B[j++];
		}
	}
	
	if (i < n1) {
		for (; i < n1-1; i++) {
			Rez[k++] = A[i];
		}
	} else if (j < n2) {
		for (; j < n2; j++) {
			Rez[k++] = B[j];
		}
	}
}