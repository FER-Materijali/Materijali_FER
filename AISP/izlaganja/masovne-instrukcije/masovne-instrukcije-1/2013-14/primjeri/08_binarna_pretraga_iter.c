#include "asp_massh.h"
#include <stdio.h>

int bin_pretraga(int *p, int x, int size) {
	int gornja_granica = size - 1;
	int donja_granica = 0;
	int srednji = -1;
	
	ispisiVarijablu(donja_granica);
	ispisiVarijablu(gornja_granica);
	ispisiVarijablu(srednji);
	
	while(donja_granica <= gornja_granica) {
			srednji = (donja_granica + gornja_granica)/2;
			
			if(p[srednji] > x) {
				gornja_granica = srednji - 1;
			}
			else if(p[srednji] < x) {
				donja_granica = srednji + 1;
			}
			else return srednji;
	}
	
	return -1;
}

int main() {
	int p[] = {1, 3, 5, 7, 12, 13, 15, 16, 18, 22, 25, 34, 67, 79, 90, 120, 123};
	int trazim;
	
	scanf("%d", &trazim);
	
	printf("Indeks za %d: %d\n", trazim, bin_pretraga(p, trazim, 17));
	return 0;
}
