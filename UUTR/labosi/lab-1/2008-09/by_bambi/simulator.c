#include <stdio.h>
#include <stdlib.h>

void ispisi(char *stanje, char *izlaz) {
	char a[5]="ACPC", b[5]="ACZh", c[3]="AZ", d[4]="AZh", e[3]="PZ";
	printf("%s ", stanje);
	if(strcmp(izlaz, a)==0) printf("Autima crveno, pjesacima crveno.\n");
	if(strcmp(izlaz, b)==0) printf("Autima crveno i zuto, pjesacima crveno.\n");
	if(strcmp(izlaz, c)==0) printf("Autima zeleno, pjesacima crveno.\n");
	if(strcmp(izlaz, d)==0) printf("Autima zuto, pjesacima crveno.\n");
	if(strcmp(izlaz, e)==0) printf("Autima crveno, pjesacima zeleno.\n");
}

int main(int argc, char *argv[]) {
	int i, j, brstanja=0;
	char *ulazniniz;
	FILE *automat;
	char br[10], s[10], p[10], a[10], izlaz[5], ulaz[1], stanje[10];
	
	if(argc!=3) {
		printf("Niste naveli sve ulazne parametre (destinaciju datoteke definicije konacnog automata i ulazni niz).\n");
		exit(1);
	}
	
	automat=fopen(argv[1], "r");
	
	ulazniniz=(char*)malloc(strlen(argv[2])*sizeof(char));
	for(i=0; i<=strlen(argv[2]); i++) ulazniniz[i]=argv[2][i];
	
	fscanf(automat, "%s", &stanje);
	fseek(automat, 0, SEEK_SET);
	
	while(fscanf(automat, "%s %s %s %s %s", &br, &s, &p, &a, &izlaz)!=EOF) brstanja++;
	
	fseek(automat, 0, SEEK_SET);
	fscanf(automat, "%s %s %s %s %s", &br, &s, &p, &a, &izlaz);
	ispisi(br, izlaz);
	
	for(i=0; i<strlen(ulazniniz); i++) {
		if(ulazniniz[i]=='s') {
			strcpy(stanje, s);
			fseek(automat, 0, SEEK_SET);
			while(fscanf(automat, "%s %s %s %s %s", &br, &s, &p, &a, &izlaz)!=EOF)
				if(strcmp(br, stanje)==0) break;
			ispisi(br, izlaz);
		}
		if(ulazniniz[i]=='p') {
			strcpy(stanje, p);
			fseek(automat, 0, SEEK_SET);
			while(fscanf(automat, "%s %s %s %s %s", &br, &s, &p, &a, &izlaz)!=EOF)
				if(strcmp(br, stanje)==0) break;
			ispisi(br, izlaz);
		}
		if(ulazniniz[i]=='a') {
			strcpy(stanje, a);
			fseek(automat, 0, SEEK_SET);
			while(fscanf(automat, "%s %s %s %s %s", &br, &s, &p, &a, &izlaz)!=EOF)
				if(strcmp(br, stanje)==0) break;
			ispisi(br, izlaz);
		}
	}
	
	fclose(automat);
	
	return 0;
}
