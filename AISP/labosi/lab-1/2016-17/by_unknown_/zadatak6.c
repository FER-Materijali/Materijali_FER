#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *ostaviSlova(char *niz){
	char *p;
	int i=0, j = 0, n = strlen(niz);
	p = malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		if((*(niz+i) >= 'a' && *(niz+i) <= 'z') ||
		   (*(niz+i) >= 'A' && *(niz+i) <= 'Z')){
			   *(p+j) = *(niz+i);
			   j++;
		   }
	*(p+j) = '\0';
	return p;
}

int main(void){
	char *niz="asp12_i_ASP13";
	printf("Novi niz: %s", ostaviSlova(niz));
	return 0;
}