#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int koeficijent;
	int potencija;
}polinom;


int main(){
	FILE *d1, *d2;
	polinom x;

	if((d1=fopen("izlaz.txt", "r"))==NULL){
		printf("Greska kod otvaranja datoteke!");
		exit(1);
	}
	if((d2=fopen("nova.dat", "w+b"))==NULL){
		printf("Greska kod kreiranja datoteke!");
		exit(1);
	}
	while(fscanf(d1, "%d%3*c%d\n", &x.koeficijent, &x.potencija)==2){
		if(fseek(d2, (long)(x.potencija)*sizeof(x), SEEK_SET)!=0) {
			printf("Greska kod pozicioniranja u datoteku!");
			exit(1);
		}
		if(fwrite(&x, sizeof(x), 1, d2)!=1) {
			printf("Greska kod zapisivanja u datoteku!");
			exit(1);
		}
	}
	rewind(d2);
	while(fread(&x, sizeof(x), 1, d2)==1){
		if(x.koeficijent!=0 || x.potencija!=0)printf("%3d*x^%2d\n", x.koeficijent, x.potencija);
	}
	fclose(d1);
	fclose(d2);
	return 0;
}