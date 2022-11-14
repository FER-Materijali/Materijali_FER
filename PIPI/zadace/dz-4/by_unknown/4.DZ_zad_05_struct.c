#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char grad[100+1];
	int posta;
	int stan;
	char zup[60+1];
}podatak;


int main(){
	FILE *d1, *d2;
	podatak gradovi;

	if((d1=fopen("gradovi.txt", "r"))==NULL){
		printf("Greska kod otvaranja datoteke!");
		exit(1);
	}
	if((d2=fopen("nova.dat", "w+b"))==NULL){
		printf("Greska kod kreiranja datoteke!");
		exit(1);
	}
	while(fscanf(d1, "%100[^#]%*c%d%*c%d%*c%60[^\n]%*c", &gradovi.grad, &gradovi.posta, &gradovi.stan, &gradovi.zup)==4){
		if(fseek(d2, (long)(gradovi.posta-10000)*sizeof(gradovi), SEEK_SET)!=0) {
			printf("Greska kod pozicioniranja u datoteku!");
			exit(1);
		}
		if(fwrite(&gradovi, sizeof(gradovi), 1, d2)!=1) {
			printf("Greska kod zapisivanja u datoteku!");
			exit(1);
		}
	}
	rewind(d2);
	while(fread(&gradovi, sizeof(gradovi), 1, d2)==1){
		if(gradovi.posta!=0)printf("%-10s %-8d %-9d %-20s\n", gradovi.grad, gradovi.posta, gradovi.stan, gradovi.zup);
	}
	fclose(d1);
	fclose(d2);
	return 0;
}