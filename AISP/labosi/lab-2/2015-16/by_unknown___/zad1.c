#include<stdio.h>
typedef struct zapis {
	int p_broj;
	char naziv[41];
} zapis;
void insertionSort (zapis *A, int n);
int main(void) {
	zapis Zapisi[10];
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %s", &Zapisi[i].p_broj, Zapisi[i].naziv);
	insertionSort(Zapisi, n);
	for (i = 0; i < n; i++)
		printf("%d %s\n", Zapisi[i].p_broj, Zapisi[i].naziv);
	return 0;
}
void insertionSort (zapis *A, int n) {
	int i, j;
	zapis pom;
	for (i = 1; i < n; i++) {
		pom = A[i];
		for (j = i - 1; j >= 0 && A[j].p_broj > pom.p_broj; j--) {
			A[j + 1] = A[j];
		}
		A[j + 1] = pom;
	}
}