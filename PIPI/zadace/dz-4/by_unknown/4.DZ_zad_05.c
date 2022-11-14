#include <stdio.h>
#include <stdlib.h>

void funkcija(FILE *d3){
	FILE *d1, *d2;
	char grad[100+1], zup[60+1];
	int posta, stan, posta2, pom;

	d1=fopen("gradovi.txt", "r");
	d2=fopen("izbaciti.txt", "r");

	if((d1==NULL) || (d2==NULL)){
		printf("Greska kod otvaranja datoteke!");
		exit(1);
	}
	while(fscanf(d1, "%100[^#]%*c%d%*c%d%*c%60[^\n]%*c", &grad, &posta, &stan, &zup)==4){
		pom=1;
		while(fscanf(d2, "%d", &posta2)==1){
			if(posta2==posta) {
				pom=-2;
				break;
			}
		}
		if(pom>0)fprintf(d3, "%s#%d#%d#%s\n", grad, posta, stan, zup);
		fseek(d2, 0, SEEK_SET);                                          //rewind(d2);
	}
	fclose(d1);
	fclose(d2);
}

int main (){
	FILE *d3;

	if((d3=fopen("nova.txt", "w"))==NULL){
		printf("Greska kod otvaranja datoteke!");
		exit(1);
	}

	funkcija(d3);

	fclose(d3);
	return 0;
}