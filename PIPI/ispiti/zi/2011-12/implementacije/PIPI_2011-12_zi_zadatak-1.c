#include <stdio.h>

void izbaci_znak(char *niz, int *pozicija, char *znak){
	int i, duljina;
	duljina=strlen(niz);
	*pozicija=rand()%duljina;
	if(duljina==0){
		*znak='\0';
		*pozicija=-1;
		return;
	}
	for(i=0; i<duljina; ++i){
		if(i==*pozicija){
			*znak=niz[i];
			niz[i]=niz[i+1];
		}
		else if(i>*pozicija)
			if(niz[i]!='\0')
				niz[i]=niz[i+1];
	}
}

int main (void){
	char niz[100+1], znak;
	int pozicija, duljina, i;
	srand((unsigned)time(NULL));
	gets(niz);
	duljina=strlen(niz);
	for(i=0; i<duljina; ++i){
		izbaci_znak(&niz, &pozicija, &znak);
		printf("novi niz: %s, izbacen je znak %c s pozicije %d\n", niz, znak, pozicija);
	}
	return 0;
}