#include"funkcije.h"
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
void simulirajIgru (int brojIgraca, int brojKrugova) {
	int i, j, k, igrac, uigri=0, negbod[10]={0}, ispao[10]={0};
	srand((unsigned)time(NULL));
	for (i=0; i<brojKrugova; ++i) {
	    do {
	         igrac=rand()%brojIgraca;
		} while (ispao[igrac]!=0);
	    ++negbod[igrac];
		for (j=0; j<brojIgraca-1; ++j) {
			for (k=j+1; k<brojIgraca; ++k) {
				if (ispao[j]==0 && ispao[k]==0) {
				   if (negbod[j]==negbod[k]+2) {
					   ispao[j]=i+1;
					   goto dalje;
				   } else if (negbod[j]+2==negbod[k]) {
				   	         ispao[k]=i+1;
					         goto dalje;
				   }
				}
			}
		}
		dalje:
		for (j=0; j<brojIgraca; ++j) {
			if (ispao[j]==0) {
				++uigri;
			}
		}
		if (uigri==1) {
			break;
		} else {
			uigri=0;
		}
	}
	printf("\nigrac   negativnih bodova");
	for (j=0; j<brojIgraca; ++j) {
		printf("\n%3d     %3d", j+1, negbod[j]);
		if (ispao[j]!=0) {
			printf(" - ispao u %d. krugu", ispao[j]);
		}
	}
	printf("\n");
}