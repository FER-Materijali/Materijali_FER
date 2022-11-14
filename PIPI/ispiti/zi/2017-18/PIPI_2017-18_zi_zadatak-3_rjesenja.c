#include <stdio.h>

void umetniznak(char *niz2, char znak){
	int i, duljina, poz;
	duljina=strlen(niz2);
	while(*(niz2+poz)!='\0' && *(niz2+poz)<znak)
		++poz;
	for(i=duljina; i>=poz; --i)
		*(niz2+i+1)=*(niz2+i);
	*(niz2+poz)=znak;
	return;
}
	
		

int main (void){
	char niz[50+1], niz2[50+1]="";
	int i, duljina;
	gets(niz);
	duljina=strlen(niz);
	for(i=0; i<duljina; ++i)
		umetniznak(niz2, niz[i]);
	printf("novi niz: %s\n", niz2);
	return 0;
}