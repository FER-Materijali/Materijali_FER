#include <stdio.h>

char *pozZnaka(char znak, char *niz){
	int i=0;
	while(*(niz+i)!='\0'){
		if(toupper(*(niz+i))==toupper(znak))
			return (niz+i);
		++i;
	}
	return NULL;
}

int main (void){
	char niz[200+1], znak, *provjera=niz;
	int brojac=0;
	gets(niz);
	scanf("%c", &znak);
	while(provjera!=NULL){
		provjera=pozZnaka(znak, provjera);
		if(provjera!=NULL){
			++provjera;
			++brojac;
		}
	}
	printf("znak %c se pojavljuje %d puta\n", znak, brojac);
	return 0;
}