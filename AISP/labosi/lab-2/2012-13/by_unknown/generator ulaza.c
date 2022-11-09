#include <stdio.h>
#include <stdlib.h>
#define JMBAG 36474895
int main(){
	FILE *f;
	int i,broj;
	if((f=fopen("ulaz_brojevi1.txt","w"))==NULL)
		return -1;
	srand((unsigned)JMBAG);
	for(i=0;i<15000;i++){
		broj=rand();
		fprintf(f,"%d\n",broj);
	}
	fclose(f);
	if((f=fopen("ulaz_brojevi2.txt","w"))==NULL)
		return -2;
	for(i=0;i<150000;i++){
		broj=rand();
		fprintf(f,"%d\n",broj);
	}
	fclose(f);
	f=fopen("ulaz_string.txt","w");
	fprintf(f,"abcdefghijk");
	return 0;
}
