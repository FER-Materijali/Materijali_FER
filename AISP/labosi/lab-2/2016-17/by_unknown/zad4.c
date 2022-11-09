#include <stdio.h>
#include <malloc.h>

void spojiPolja(int *A, int *B, int *Rez, int n1, int n2) {
	int i=0, j=0;
	while (n1 != 0 && n2 != 0) {
		if (A[i] > B[j]) {
			Rez[i + j] = A[i];
			i++;
			n1--;
		}
		else {
			Rez[i + j] = B[j];
			j++;
			n2--;
		}
	}
	while (n1 != 0) {
		Rez[i + j] = A[i];
		i++;
		n1--;
	}
	while (n2 != 0) {
		Rez[i + j] = B[j];
		j++;
		n2--;
	}
}

int main(void) {
	int A[] = { 9,7,5,3,1 }, B[] = { 8,6,4,2,0 }, *Rez, i;
	if ((Rez = malloc(sizeof(int) * 10)) == NULL) exit(1);
	spojiPolja(A, B, Rez, 5, 5);
	for (i = 0; i < 10; i++)
		printf("%d\n", Rez[i]);
	return 0;
}