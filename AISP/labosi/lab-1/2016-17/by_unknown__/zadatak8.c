#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXNIZ 50

char *f(char *niz){
	int n = strlen(niz), i=0, j=0;
	char *p = malloc(sizeof(char)*n);
	while(*(niz+i) != '\0'){
		if (!((*(niz+i) == ' ') && (*(niz+i+1)==' '))){
			*(p+j) = *(niz+i);
			j++;
		}
		i++;
	}
	*(p+j) = '\0';
	return p;
}

int main(void){
	char niz[MAXNIZ];
	printf("Unesite znakovni niz > ");
	gets(niz);
	printf("\nNovi niz: %s", f(niz));
	return 0;
}