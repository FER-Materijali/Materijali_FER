#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
void selection2Sort (int *A, int n);
int main(void) {
	int n, *A, i;
	scanf("%d", &n);
	A = malloc(n * sizeof(int));
	srand((unsigned) time(NULL));
	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;
	selection2Sort(A, n);
	for(i = 0; i < n; i++)
		printf("%d\n", A[i]);
	return 0;
}
void swap (int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void selection2Sort (int *A, int n) {
	int i, j, k, min, max;
	for (i = 0, j = n - 1; i < j; i++, j--) {
		min = i;
		max = j;
		for (k = i + 1; k < j; k++) {
			min = A[k] < A[min] ? k : min;
		}
		swap(A + min, A + i);
		for (k = j - 1; k >= i; k--) {
			max = A[k] > A[max] ? k : max;
		}
		swap(A + max, A + j);
	}
}