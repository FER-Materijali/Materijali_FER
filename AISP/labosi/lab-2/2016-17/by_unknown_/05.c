#include <stdio.h>

void spojiNizove (char *A, char *B, char *Rez);

int main (void) {
	char A[6] = "ecaDB";
	char B[6] = "dbECA";
	char Rez[11];
	
	spojiNizove(A, B, Rez);
	
	printf("%s\n", Rez);
	
	return 0;
}

void spojiNizove (char *A, char *B, char *Rez) {
	int i, j, k;
	
	for (i = 0, j = 0, k = 0; *(A+i) != '\0' && *(B+j) != '\0'; k++) {
		if (*(A+i) >= *(B+j)) {
			*(Rez+k) = *(A+i++);
		} else {
			*(Rez+k) = *(B+j++);
		}
	}
	
	if (*(A+i) != '\0') {
		for (; *(A+i) != '\0'; i++, k++) {
			*(Rez+k) = *(A+i);
		}
	}else if (*(B+j) != '\0') {
		for (; *(B+j) != '\0'; j++, k++) {
			*(Rez+k) = *(B+j);
		}
	}
	
	*(Rez+k) = '\0';
}