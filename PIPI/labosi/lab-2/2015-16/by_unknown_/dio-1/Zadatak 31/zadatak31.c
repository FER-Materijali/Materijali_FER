#include <stdio.h>
#define MAX 30

int main(void){
	char niz[MAX + 1];
	int Brojac = 0, ProvjeraZnakova = 0;
	gets(niz);
	while(niz[Brojac] != '\0'){
		if((niz[Brojac] < 48) || (niz[Brojac] > 58 && niz[Brojac] < 65) || (niz[Brojac] > 90 && niz[Brojac] < 97) || (niz[Brojac] > 122)){
			ProvjeraZnakova = 1;
			break;
		}else if(niz[Brojac] == 'a'){
			niz[Brojac] = '9';
		}else if(niz[Brojac] == 'e'){
			niz[Brojac] = '8';
		}else if(niz[Brojac] == 'i'){
			niz[Brojac] = '7';
		}
		Brojac++;
	}
	if(ProvjeraZnakova == 1){
		printf("Ucitani niz nije ispravno zadan.");
	}else{
		printf("%s", niz);
	}
	return 0;
}