#include<stdio.h>
#include"funkcije.h"
int main (void) {
	int n, postbroj[100], i, j;
	double latitude[100], longitude[100];
	do {
	    printf("Upisite broj gradova (od 3 do 100):");
		scanf("%d", &n);
	} while (n<3 || n>100);
	printf("\n");
	for (i=0; i<n; ++i) {
	do {
		printf("Upisite postanski broj i koordinate %d. grada:", i+1);
		scanf("%d %lf %lf", &postbroj[i], &latitude[i], &longitude[i]);
		} while (latitude[i]<-180 || latitude[i]>180 || longitude[i]<-90 || longitude[i]>90);
	}
	printf("\nMedjusobne udaljenosti gradova:\n");
	for (i=0; i<n-1; ++i) {
		for (j=i+1; j<n; ++j) {
			printf("%d - %d: %lf km\n", postbroj[i], postbroj[j], izracunajUdaljenost(latitude[i], latitude[j], longitude[i], longitude[j]));
		}
	}
	return 0;
}