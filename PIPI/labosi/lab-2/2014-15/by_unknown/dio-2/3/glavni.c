#include<stdio.h>
#include"funkcije.h"
int main (void) {
	int n, skup1[20]={0}, skup2[20]={0}, unijas[40]={0}, i, j, brojac1=0, brojac2=0, brojacu=0, ponovljen=0;
	printf("Skup 1: ");
	scanf("%d", &n);
	i=0;
	while (n>0 && i<20) {
	    for (j=0; j<brojac1; ++j) {
			if (n==skup1[j]) {
				ponovljen=1;
				break;
			} else {
				ponovljen=0;
			}
		}
		if (!ponovljen) {
			skup1[i++]=n;
			++brojac1;
		}
		scanf("%d", &n);
	}
	printf("Skup 2: ");
	scanf("%d", &n);
	i=0;
	ponovljen=0;
	while (n>0 && i<20) {
	    for (j=0; j<brojac2; ++j) {
			if (n==skup2[j]) {
				ponovljen=1;
				break;
			} else {
				ponovljen=0;
			}
		}
		if (!ponovljen) {
			skup2[i++]=n;
			++brojac2;
		}
		scanf("%d", &n);
	}
	printf("\nSkup 1: %d", skup1[0]);
	for (i=1; i<brojac1; ++i) {
		printf(",%d", skup1[i]);
	}
	printf("\nSkup 2: %d", skup2[0]);
	for (i=1; i<brojac2; ++i) {
		printf(",%d", skup2[i]);
	}
	unija(brojac1, skup1, brojac2, skup2, &brojacu, unijas);
	printf("\nUnija: %d", unijas[0]);
	for (i=1; i<brojacu; ++i) {
		printf(",%d", unijas[i]);
	}
	printf("\n");
	return 0;
}