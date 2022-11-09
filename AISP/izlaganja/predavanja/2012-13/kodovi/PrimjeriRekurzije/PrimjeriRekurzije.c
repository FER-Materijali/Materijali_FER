// PrimjeriRekurzije.c
#include <stdio.h>

void pisi1 (int broj, int n) {
  broj++;
  if (broj > n) return;
  pisi1 (broj, n);
  printf( "%d", broj);
}

void pisi2 (int broj, int n) {
  broj++;
  if (broj > n) return;
  printf( "%d", broj);
  pisi2 (broj, n);
}

void pisi3 (int *broj, int n) {
  (*broj)++;
  if (*broj > n) return;
  pisi3 (broj, n);
  printf( "%d", *broj);
}

void pisi4 (int *broj, int n) {
  (*broj)++;
  if (*broj > n) return;
  printf( "%d", *broj);
  pisi4 (broj, n);
}

void pisi5 (int *broj, int n) {
  (*broj)--;
  if (*broj < 0) return;
  pisi5 (broj, n);
  printf( "%d", *broj);
}

int main (void) {
  int nula;
	
	nula = 0; pisi1 (nula, 5);	
	printf(" Nakon pisi1 nula = %d\n", nula);
	
	pisi2 (nula, 5);
	printf(" Nakon pisi2 nula = %d\n", nula);

  nula = 0; pisi3 (&nula, 5);
	printf(" Nakon pisi3 nula = %d\n", nula);
  
	nula = 0; pisi4 (&nula, 5);
	printf(" Nakon pisi4 nula = %d\n", nula);
	
	pisi5 (&nula, 5);
	printf(" Nakon pisi5 nula = %d\n", nula);
	
	return 0;
} 
/*
a)  Kakav tip podatka sadrži *broj?
b)  Kakav tip podatka sadrži broj?
c)  Kakav tip podatka sadrži &nula?
d)  Koju vrijednost sadrži nula nakon povratka iz funkcije pisi1?
e)  Što ae program ispisati na zaslonu raeunala?
*/
