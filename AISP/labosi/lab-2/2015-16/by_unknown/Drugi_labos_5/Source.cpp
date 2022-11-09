#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spojiNizove(char *A, char *B, char *rez) {
	int i, j, k, n1, n2, suma;
	n1 = strlen(A);	n2 = strlen(B);
	suma = n1 + n2;
	rez[suma] = '\0';
	for (i = 0, j = 0, k = 0; k < suma; ++k) {
		if (i < n1 && j < n2) {
			if (A[i] <= B[j]) {
				rez[k] = A[i];
				++i;
			
			}
			else {
				rez[k] = B[j];
				++j;
			}
		}
		else if (i < n1) {
			rez[k] = A[i];
				++i;
		}
		else
		{
			rez[k] = B[j];
			++j;
		}
	}
}

int main() {
	char A[50];
	char B[50];
	char rez[50];
	printf("Upisite prvi niz\n");
	gets(A);
	printf("Upisite drugi niz\n");
	gets(B);
	puts("Prije zamjene");
	puts(A);
	puts(B);
	spojiNizove(A, B, rez);
	puts("Nakon zamjene");
	puts(rez);
	return 1;
}