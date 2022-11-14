#include <stdio.h>
#define MAX 10
int main() {
	char niz[MAX+1];
	int i, brojac=0, k=0;
	gets(niz);
	for(i=0; niz[i]!='\0' && i<MAX; i++){
		if(niz[i]!='1' && niz[i]!='0'){
			brojac++;
			printf("Procitani niz nije ispravno zadan.\n");
			break;
		}
	}
	if(brojac==0){
		for(i=0; niz[i]!='\0' && i<MAX; i++){
			if(niz[i]=='1')
				k++;
		}
		printf("Broj jedinica u zadanom binarnom broju = %d\n", k);
	}

	return 0;
}
