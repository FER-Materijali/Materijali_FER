#include <stdio.h>
#define MAX 5
int main() {
	char niz[MAX+1];
	int i, brojac=0, k=0;
	gets(niz);
	for(i=0; niz[i]!='\0' && i<MAX; i++){
		if(niz[i]<'0' || niz[i]>'7'){
			brojac++;
			printf("Procitani niz nije ispravno zadan.\n");
			break;
		}
	}
	if(brojac==0){
		for(i=0; niz[i]!='\0' && i<MAX; i++){
			if(niz[i]=='4')
				k++;
		}
		printf("Znamenka 4 se u procitanom broju pojavljuje %d puta.\n", k);
	}
	return 0;
}