#include <stdio.h>
#define MAX 60
int main() {
	char niz[MAX+1];
	int i,j;
	gets(niz);
	for(i=1; niz[i]!='\0' && i<MAX; i++);
	niz[i+1]='\0';
	if(i<10)
		printf("prekratak niz.\n");
	else {
		for(j=0; niz[j]!='\0' && j<MAX; j=j+2)
			printf("%c \n", niz[j]);	
	}
	return 0;
}