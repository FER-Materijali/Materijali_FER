#include "asp_massh.h"
#include <stdio.h>

void zamjeni_sadrzaj(int *a, int *b);
void zamjeni_pointere(int **a, int **b);
void pogresno_zamjeni_pointere(int *a, int *b);

int main() {
	int a = 15, b = 33, *pA, *pB;
	pA = &a;
	pB = &b;
	
	noviDio("Pocetno stanje");
	ispisiVarijablu(a);
	ispisiVarijablu(b);
	ispisiPointer(pA);
	ispisiPointer(pB);
	ispisiVrijednostPokazivanogSa(pA);
	ispisiVrijednostPokazivanogSa(pB);

	
	noviDio("Zamjena vrijednosti");
	zamjeni_sadrzaj(&a, &b);
	ispisiVarijablu(a);
	ispisiVarijablu(b);
	ispisiPointer(pA);
	ispisiPointer(pB);
	ispisiVrijednostPokazivanogSa(pA);
	ispisiVrijednostPokazivanogSa(pB);
	
	noviDio("Zamjena pointera - lose");
	pogresno_zamjeni_pointere(pA, pB);
	ispisiVarijablu(a);
	ispisiVarijablu(b);
	ispisiPointer(pA);
	ispisiPointer(pB);
	ispisiVrijednostPokazivanogSa(pA);
	ispisiVrijednostPokazivanogSa(pB);
	
	noviDio("Zamjena pointera - dobro");
	zamjeni_pointere(&pA, &pB);
	ispisiVarijablu(a);
	ispisiVarijablu(b);
	ispisiPointer(pA);
	ispisiPointer(pB);
	ispisiVrijednostPokazivanogSa(pA);
	ispisiVrijednostPokazivanogSa(pB);

	return 0;
}

void zamjeni_sadrzaj(int *a, int *b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void zamjeni_pointere(int **a, int **b) {
	int *p;
	
	p = *b;
	*b = *a;
	*a = p;
}

void pogresno_zamjeni_pointere(int *a, int *b) {
	int *p;
	
	p = a;
	a = b;
	b = p;
}

