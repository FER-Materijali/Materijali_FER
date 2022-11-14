#include <stdio.h>
#include "funkcije.h"
#define D 20
#define G 40

int main(void) {
	int s1[D] = {0}, s2[D] = {0};
	int n1, n2;
	int izlaz[G] = {0};
	int duljina;
	int i, j;
	
	printf("Skup 1: ");
	for (i=0; i<20; i++) {
		scanf(" %d", &s1[i]);
		if (s1[i] <= 0) {
			s1[i] = 0;
			break;
		} else {
			for (j=0; j<i; j++) {
				if (s1[j] == s1[i]) {
					i--;
					break;
				}
			}
		}
	}
	n1 = i;
	
	printf("Skup 2: ");
	for (i=0; i<20; i++) {
		scanf(" %d", &s2[i]);
		if (s2[i] <= 0) {
			s2[i] = 0;
			break;
		} else {
			for (j=0; j<i; j++) {
				if (s2[j] == s2[i]) {
					i--;
					break;
				}
			}
		}
	}
	n2 = i;
	
	unija(n1, s1, n2, s2, &duljina, izlaz);
	
	printf("Unija: ");
	for (i=0; i<duljina; i++) {
		printf("%d%c", izlaz[i], i==duljina-1?'\n':',');
	}
	
	return 0;
}