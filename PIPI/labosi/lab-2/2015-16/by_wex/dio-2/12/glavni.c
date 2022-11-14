#include <stdio.h>
#include "funkcije.h"

int main(void) {
	char ulaz[1500+1] = {0};
	int stat[26] = {0};
	int i;
	int max1 = 0, max2 = 0, max3 = 0, max1_indeks = 0, max2_indeks = 0, max3_indeks = 0;
	
	printf("Upisite tekst:\n");
	scanf(" %1500[^\n]", ulaz);
	
	brojac(stat, ulaz);
	
	for (i=0; i<26; i++) {
		if (stat[i] > max1) {
			max3 = max2;
			max2 = max1;
			max1 = stat[i];
			max3_indeks = max2_indeks;
			max2_indeks = max1_indeks;
			max1_indeks = i;
		} else if (stat[i] > max2) {
			max3 = max2;
			max2 = stat[i];
			max3_indeks = max2_indeks;
			max2_indeks = i;
		} else if (stat[i] > max3) {
			max3 = stat[i];
			max3_indeks = i;
		}
	}
	
	if ((max1_indeks == 0 && max2_indeks == 'I' - 'A') || (max2_indeks == 0 && max1_indeks == 'I' - 'A')) printf("Hrvatski\n");
	else if (max1_indeks == 'E' - 'A' && max2_indeks == 'T' - 'A') printf("Engleski\n");
	else if (max1_indeks == 'E' - 'A' && (max2_indeks == 'N' - 'A' || (max2 = max3 && max3_indeks == 'N' - 'A'))) printf("Njemacki\n");
	else printf("Nepoznat\n");
	
	return 0;
}