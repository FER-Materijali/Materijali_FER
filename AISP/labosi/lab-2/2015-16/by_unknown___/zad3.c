#include<stdio.h>
typedef struct zapis {
	int sifra;
	char ime[51];
} zapis;
void obicanBubbleSort (zapis *A, int n);
int main(void) {
	zapis Zapisi[20];
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %s", &Zapisi[i].sifra, Zapisi[i].ime);
	obicanBubbleSort(Zapisi, n);
	for (i = 0; i < n; i++)
		printf("%d %s\n", Zapisi[i].sifra, Zapisi[i].ime);
	return 0;
}
void swap(zapis *a, zapis *b) {
	zapis t = *a;
	*a = *b;
	*b = t;
}
void obicanBubbleSort (zapis *A, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (A[j].sifra > A[j + 1].sifra) swap(A + j, A + j + 1);
		}
	}
}