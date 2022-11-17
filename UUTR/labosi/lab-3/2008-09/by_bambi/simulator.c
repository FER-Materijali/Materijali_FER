#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int psmin, psmax, vs=0, duljina=0, glava;
char *traka;

void povecaj_traku(int smjer) {
	int i;
	traka=(char*)realloc(traka, (strlen(traka)+1)*sizeof(char));
	duljina++;
	if(smjer==1) {
		traka[duljina-1]='B';
		traka[duljina]='\0';
	}
	if(smjer==0) {
		for(i=duljina; i>0; i--) traka[i]=traka[i-1];
		traka[0]='B';
	}
}

void automat(FILE *ts) {
	int i, pom;
	char stanje[11], znak_na_traci[2], novo_stanje[11], novi_znak_na_traci[2], smjer_pomaka_glave[2];
	char prijelaz[101], trenutno_stanje[10], pozicija[11];
	
	fscanf(ts, "%s", &trenutno_stanje);
	
	while(fscanf(ts, "%s", &prijelaz)==1) {
		for(i=0; i<100; i++) {
			stanje[i]=prijelaz[i];
			if(prijelaz[i+1]=='#') break;
		}
		stanje[i+1]='\0';
		pom=i+2;
		znak_na_traci[0]=prijelaz[pom];
		znak_na_traci[1]='\0';
		pom=pom+2;
		for(i=0; i<100; i++) {
			novo_stanje[i]=prijelaz[pom+i];
			if(prijelaz[pom+i+1]=='#') break;
		}
		novo_stanje[i+1]='\0';
		pom=pom+i+2;
		novi_znak_na_traci[0]=prijelaz[pom];
		novi_znak_na_traci[1]='\0';
		pom=pom+2;
		smjer_pomaka_glave[0]=prijelaz[pom];
		smjer_pomaka_glave[1]='\0';
		
		printf("%s %s %s %s %s\n", stanje, znak_na_traci, novo_stanje, novi_znak_na_traci, smjer_pomaka_glave);
		
		if(strcmp(trenutno_stanje, stanje)==0 && traka[glava]==znak_na_traci[0]) {
			strcpy(trenutno_stanje, novo_stanje);
			traka[glava]=novi_znak_na_traci[0];
			
			if(smjer_pomaka_glave[0]=='D') {
				glava++;
				vs++;
				if(glava>psmax) psmax=glava;
				if(glava==duljina) povecaj_traku(1);
			}
			if(smjer_pomaka_glave[0]=='L') {
				glava--;
				vs++;
				if(glava<psmin) psmin=glava;
				if(glava<0) {
					povecaj_traku(0);
					glava++;
				}
			}
			
			fseek(ts, 0, SEEK_SET);
			fscanf(ts, "%s", &pozicija);
		}
	}
}

int main(int argc, char *argv[]) {
	FILE *ts;
	int i, pokazivac;
	
	if(argc!=4) {
		printf("Niste naveli sve ulazne parametre!\n");
		exit(1);
	}
	
	ts=fopen(argv[1], "r");
	
	traka=(char*)malloc(strlen(argv[2])*sizeof(char));
	for(i=0; i<=strlen(argv[2]); i++) {
		traka[i]=argv[2][i];
		if(traka[i]!='\0') duljina++;
	}
	
	glava=atoi(argv[3]);
	
	if(glava<0) while(glava!=0) {
		povecaj_traku(0);
		glava++;
		i;
	}
	
	if(glava>=duljina) while(glava>=duljina) povecaj_traku(1);
	
	psmin=glava;
	psmax=glava;
	
	automat(ts);
	
	printf("Prostorna slozenost: %d\n", psmax-psmin+1);
	printf("Vremenska slozenost: %d\n", vs);
	
	return 0;
}
