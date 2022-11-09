// ElementarnaRekurzija.c
#include <stdlib.h>
#include <malloc.h>

void f (int i) {
	int p[40000];
	f (i+1);
	return;
}
int main (void) {
	f(1);
	return 0;
}
