// Euklid.c
#include <stdio.h>
#include <stdlib.h>

// NZM Rekurzivno
int nzm (int a, int b) {
	printf ("nzm(%d,%d) = ", a, b);
	if(b == 0) {
		printf ("%d\n", a);
		return a;
	}
  // ostali pozivi prosljedjuju isti rezultat 
	return nzm (b, a % b); 
}
// NZM Uklanjanjem rekurzije
int nzm1 (int a, int b) {
	int t;
L1:
	printf ("nzm(%d,%d) = ", a, b);
	if (b == 0) { 
		printf ("%d\n", a);
		return a;
	}
	  // nzm (b, a % b)
  	t = b;
		b = a%b;
		a = t;
	goto L1;
}
// NZM Iterativno, izbjegavanjem goto:
int nzm2 (int a, int b) {
	int t;
	while (b != 0) {
		printf ("nzm(%d,%d) = ", a, b);
		t = b;
		b = a%b;
		a = t;
	}
  printf ("nzm(%d,%d) = ", a, b);
	printf ("%d\n", a);
  return a;
}
int main (void) {
  int a, b;

  while (1) {
    printf ("Upisite 2 cijela nenegativna broja >"); 
    scanf ("%d %d", &a, &b); // primjer: 22 8
    if ((a < 0 || b < 0) || (a == 0 && b == 0)) {
      printf("Gotovo!\n");
			break;
    } else {
			printf("Najveca zajednicka mjera brojeva %d i %d je:\n\n", a, b);
			printf("Rekurzivno           : %d\n\n", nzm(a, b));
			printf("Nerekurzivno s goto  : %d\n\n", nzm1(a, b));
			printf("Nerekurzivno bez goto: %d\n\n", nzm2(a, b));
		}
  }
	return 0;
}
