#include<stdio.h>
void spojiPolja(int *A, int *B, int *Rez, int n1, int n2);
int main(void) {
	int A[] = {1, 3, 5, 7, 9}, B[] = {0, 2, 4, 6, 8}, Rez[10], i;
	spojiPolja(A, B, Rez, 5, 5);
	for (i = 0; i < 10; i++)
		printf("%d\n", Rez[i]);
	return 0;
}
void spojiPolja(int *A, int *B, int *Rez, int n1, int n2) {
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2)
		if (A[i] < B[j]) {
			Rez[k++] = A[i++];
		} else {
			Rez[k++] = B[j++];
		}
	while(i < n1) Rez[k++] = A[i++];
	while(j < n2) Rez[k++] = B[j++];
}