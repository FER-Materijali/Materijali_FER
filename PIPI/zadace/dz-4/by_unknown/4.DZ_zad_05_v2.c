#include <stdio.h>
#include <stdlib.h>

void funkcija2(FILE *d1, FILE *d2, FILE *d3){
	//FILE *d1, *d2;
	char grad[100+1], zup[60+1];
	int posta, stan, posta2, pom;

	//d1=fopen("gradovi.txt", "r");
	//d2=fopen("izbaciti.txt", "r");

	if((d1==0) || (d2==0)){
		printf("Greska kod otvaranja datoteke!");
		exit(1);
	}
	while(fscanf(d1, "%100[^#]%*c%d%*c%d%*c%60[^\n]%*c", &grad, &posta, &stan, &zup)==4){
		while(fscanf(d2, "%d", &posta2)==1){
			if(posta2==posta) {
				pom=-2;
				continue;
			}
		}
		if(pom>0)fprintf(d3, "%s#%d#%d#%s\n", grad, posta, stan, zup);
		pom=1;
		fseek(d2, 0, SEEK_SET);
	}
	fclose(d1);
	fclose(d2);
	fclose(d3);
}

int main2 (){
	FILE *d3, *d2, *d1;
	char grad[100+1], zup[60+1];
	int posta, stan, posta2;

	d1=fopen("gradovi.txt", "r");
	d2=fopen("izbaciti.txt", "r");
	d3=fopen("nova.txt", "w");

	printf("Ispis datoteke 'gradovi.txt' prije prepisivanja u novu datoteku:\n");
	while(fscanf(d1, "%100[^#]%*c%d%*c%d%*c%60[^\n]%*c", &grad, &posta, &stan, &zup)==4){
		printf("%s#%d#%d#%s\n", grad, posta, stan, zup);
	}
	printf("\n\nIspis postanskih brojeva koji ce se izbaciti iz datoteke 'gradovi.txt':\n");
	while(fscanf(d2, "%d", &posta2)==1){
		printf("%d\n", posta2);
	}

	funkcija2(d1, d2, d3);

	printf("\n\nIspis nove datoteke koja je nastala izbacivanjem gradova:\n");
	while(fscanf(d3, "%100[^#]%*c%d%*c%d%*c%60[^\n]%*c", &grad, &posta, &stan, &zup)==4){
		printf("%s#%d#%d#%s\n", grad, posta, stan, zup);
	}

}