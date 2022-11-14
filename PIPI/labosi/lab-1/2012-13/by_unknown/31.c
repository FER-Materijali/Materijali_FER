#include <stdio.h>
#include <math.h>
#define MAX 20
int main() {
	char niz[MAX+1];
	int i, zadnji, j, pomocna;
	gets(niz);
	for(i=0; niz[i]!='\0' && i<MAX; i++);
	zadnji=niz[i-1];
	j=i-1;
	for(i=0; niz[i]!='\0' && i<MAX; i++){
		if(niz[i]>='a' && niz[i]<='z'){
			pomocna=niz[i];
			niz[i]=zadnji;
			niz[j]=pomocna;
			break;
		}
	}
	printf("%s\n", niz);
	return 0;
}
