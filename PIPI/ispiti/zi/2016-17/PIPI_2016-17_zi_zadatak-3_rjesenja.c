#include <stdio.h>

void *kazaljka(char *niz){
	int duljina=strlen(niz), i;
	for(i=0; i<duljina; ++i)
		if(niz[i]>='A' && niz[i]<='Z')
			return niz+i;
	return NULL;
}

int main (void){
	char niz[50+1];
	char *niz2;
	gets(niz);
	niz2=kazaljka(niz);
	if(niz2==NULL)
		printf("nema velikog slova");
	else{
		printf("prvo veliko slovo: %c\n", *niz2);
		puts(niz2+1);
	}
	return 0;
}