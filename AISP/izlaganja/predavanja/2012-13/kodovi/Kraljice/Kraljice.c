#include <stdio.h>

// ispis znaka c u zadanoj duljini n
void nznak (int c, int n) {
  while (--n >= 0) putchar(c);
}
int NeNapadaju(int x1, int y1, int x2, int y2) {
	// funkcija koja utvrdjuje da li se dvije kraljice, 
	// postavljene na polja (x1, y1) i (x2, y2) 
	// medjusobno ne napadaju
	int ne_napadaju = 1;
	if (x1 == x2) ne_napadaju = 0;
	if (y1 == y2) ne_napadaju = 0;
	if (x1 + y2 == x2 + y1) ne_napadaju = 0;
	if (x1 - y2 == x2 - y1) ne_napadaju = 0;
	return ne_napadaju;
}

int K8(int *k, int i, int n) {
  int a, b;
  int dobar;
  if (i == n) return 1; // rubni uvjet
  nznak(' ', i); printf ("Kraljica=%d\n", i+1); 
  for (a = 0; a < n; a++) { // potencijalni retci
    dobar = 1;
    for (b = 0; b < i; b++) { // prethodne i-tu u a-tom
      if (!NeNapadaju(b + 1, k[b] + 1, i + 1, a + 1)) {
        dobar = 0;
        break;
      }
    }
    if (dobar) {
      k[i] = a; // redak i-te dobre  
      nznak(' ', i); printf ("?? (%d %d)\n", i+1, a+1);
      if (K8(k,i+1,n) == 1) {
        nznak(' ', i); printf ("OK (%d %d)\n", i+1, a+1);
        return 1; // dobar do kraja
      } else {
        nznak(' ', i); printf ("-- (%d %d)\n", i+1, a+1);        
      }
    }
  }
  nznak(' ', i); printf ("<< (%d, *)\n", i+1);
  return 0;
}
int main() {
  int k[8] = {0}, i;

  K8(k, 0, 8);
  for (i = 0; i < 8; i++) 
    printf("(%d, %d)\n", i + 1, k[i] + 1);

  return 0;
}

