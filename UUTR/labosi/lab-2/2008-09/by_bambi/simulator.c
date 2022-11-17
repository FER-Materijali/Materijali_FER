#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stog[100];
int duljinastoga=0;
int pokazivac=0;

void fjaprijelaza(char *stanje, char *ulaz, char vrhstoga, char *stog) {
	char pomstanje[3], pomulaz, pomvrhs, novostanje[3], novivrhs[5], pomstog[100], novivrhstoga;
	int pomduljina, i, brojac=0;
	FILE *automat;
	
	automat=fopen("./automat.txt", "r");
	pomduljina=duljinastoga;
	for (i=0; i<duljinastoga; i++) pomstog[i]=stog[i];
	
	while(fscanf(automat, "%s %c %c %s %s", &pomstanje, &pomulaz, &pomvrhs, &novostanje, &novivrhs)==5) {
		if(pomulaz=='e') pomulaz='\0';
		if(strcmp(stanje, pomstanje)==0 && *ulaz==pomulaz && vrhstoga==pomvrhs) {
			printf("Znak koji trenutno ucitava: %c\n", *ulaz);
			printf("Stanje u kojem se trenutno nalazi: %s\n", stanje);
			printf("Sadrzaj stoga: ");
			for (i=0; i<duljinastoga; i++) printf("%c", *(stog+i));
			printf("%c", vrhstoga);
			printf("\n");
			printf("Prijelaz koji obavlja: D(%s,%c,%c)=(%s,%s)\n", pomstanje, pomulaz, pomvrhs, novostanje, novivrhs);
			
			if(*novivrhs!='e') while(*(novivrhs+brojac++)!='\0') stog[duljinastoga++]=*(novivrhs+brojac-1);
			printf("Novo stanje u koje prelazi: %s\n", novostanje);
			printf("Novi sadrzaj stoga: ");
			for (i=0; i<duljinastoga; i++) printf("%c", *(stog+i));
			printf("\n");
			printf("Prihvaca li se dosad ucitani dio ulaznog niza? ");
			if(strcmp(novostanje, "qf")==0) printf("DA\n");
			else printf("NE\n");
			printf("\n");
			
			if(strcmp(novostanje, "qf")==0 &&  *(ulaz+1)=='\0') pokazivac=1;

			novivrhstoga=stog[duljinastoga-1];
			duljinastoga--;			
			fjaprijelaza(novostanje, ulaz+1, novivrhstoga, stog);
			duljinastoga=pomduljina;
			for(i=0; i<duljinastoga; i++) stog[i]=pomstog[i];
		}
	}
}

int main(int argc, char *argv[]) {
	int i;
	char ulazniniz[100], stanje[3], vrhstoga;
	
	printf("Ulazni niz? ");
	scanf("%s", &ulazniniz);
	printf("\n");
	
	strcpy(stanje, "q0");
	
	stog[duljinastoga++]='K';
	vrhstoga=stog[duljinastoga-1];
	duljinastoga--;
	
	fjaprijelaza(stanje, ulazniniz, vrhstoga, stog);
	
	printf("Prihvaca li se cijeli niz? ");
	if(pokazivac==1) printf("DA\n");
	else printf("NE\n");
	printf("\n");

	return 0;
}
