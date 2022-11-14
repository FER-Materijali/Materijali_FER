#include<stdio.h>
#include"funkcije.h"
int main (void) {
	int brigraca, brkrugova;
	printf("\nUnesite broj igraca: ");
	scanf("%d", &brigraca);
	printf("\nUnesite broj krugova: ");
	scanf("%d", &brkrugova);
	simulirajIgru(brigraca, brkrugova);
	return 0;
}