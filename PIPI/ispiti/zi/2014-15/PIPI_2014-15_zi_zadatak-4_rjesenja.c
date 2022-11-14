#include <stdio.h>

void izbaciZnakove(char *niz, char znak){
	int duljina=strlen(niz);
	int i, j;
	for(j=0; niz[j]==znak; ++j);
	for(i=0; i<duljina-j+1; ++i)
			niz[i]=niz[i+j];
}

int main (void){
	char niz[30+1];
	scanf("%30c", niz);
	izbaciZnakove(niz, 't');
	puts(niz);
	return 0;
}