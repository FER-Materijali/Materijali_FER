#include<stdio.h>
void spojiNizove(char *A, char *B, char *Rez);
int main(void) {
	char A[] = "BDace", B[] = "ACEbd", Rez[11];
	int i;
	spojiNizove(A, B, Rez);
	for (i = 0; i < 10; i++)
		printf("%c", Rez[i]);
	printf("\n");
	return 0;
}
void spojiNizove(char *A, char *B, char *Rez) {
	int i = 0, j = 0, k = 0;
	while (A[i] != 0 && B[j] != 0)
		if (A[i] < B[j]) {
			Rez[k++] = A[i++];
		} else {
			Rez[k++] = B[j++];
		}
	while(A[i] != 0) Rez[k++] = A[i++];
	while(B[j] != 0) Rez[k++] = B[j++];
}