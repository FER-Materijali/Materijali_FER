#include <stdio.h> 
void ispisi(int A[], int n) {
	int i;
	for (i = 0; i < n; i++) 
    printf("%d\n", A[i]);
}

// funkcija koja traži element u polju
// vraæa 1 ako se element nalazi u polju, a 0 inaèe
int trazi(int A[], int n, int trazeni) {
  int i;
  for (i=0; i<n; i++) {
    if (trazeni == A[i]) 
      return 1;
  }
  return 0;
}

int main () {
	int A [] = {4, -3, 5, -2, -1, 2, 6, -2};
	int b, c;
	ispisi (A, 8);
	while (1) {
		printf("Upisite trazeni broj\n");
		scanf ("%d2", &b);
		c = trazi (A, 8, b);
		printf ("Trazeni broj %d se ", b);
		if (!c) printf ("ne ");
		printf ("nalazi u polju A\n");
	}
}
