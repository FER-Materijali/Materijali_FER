#include <stdlib.h>
#include <time.h>
#include "funkcije.h"

void simulirajIgru(player igrac[], int broj, int krugovi) {
	int i, j;
	int max, max_indeks, min;
	int r;
	int brojac;
	
	srand((unsigned)time(NULL));
	brojac = broj;
	
	for (i=0; i<krugovi && brojac>1; i++) {
		
		do {
			r = rand() % broj;
		} while (igrac[r].ispao);
		
		igrac[r].bodovi += 1;
		
		max = 0;
		min = 100;
		
		for (j=0; j<broj; j++) {
			if (!igrac[j].ispao) {
				if (igrac[j].bodovi > max) {
					max = igrac[j].bodovi;
					max_indeks = j;
				}
				if (igrac[j].bodovi < min) min = igrac[j].bodovi;
			}
		}
		
		if (max - min >= 2) {
			igrac[max_indeks].ispao = 1;
			igrac[max_indeks].krug_ispadanja = i + 1;
			brojac--;
		}
	}
	
	return;
}