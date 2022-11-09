#include <stdio.h>
#include <malloc.h>

void spojiNizove(char *A, char *B, char *Rez) {
	int i = 0, j = 0;
	while (A[i] && B[j]) {
		if (A[i] > B[j]) {
			Rez[i + j] = A[i];
			i++;
		}
		else {
			Rez[i + j] = B[j];
			j++;
		}
	}
	while (A[i]) {
		Rez[i + j] = A[i];
		i++;
	}
	while (B[j]) {
		Rez[i + j] = B[j];
		j++;
	}
	Rez[i + j] = '\0';
}

int main(void) {
	char A[] = "ecaDB", B[] = "dbECA", *Rez;
	if ((Rez = malloc(sizeof(char) * 11)) == NULL) exit(1);
	spojiNizove(A, B, Rez);
	printf("%s\n", Rez);
	return 0;
}