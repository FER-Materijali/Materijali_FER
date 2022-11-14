#include <stdio.h>
#define MAX 5
int main() {
	char niz[MAX+1];
	int i, brojac=0, max;
	gets(niz);
	for(i=0; niz[i]!='\0' && i<MAX; i++){
		if((niz[i]<'0' || niz[i]>'9') && (niz[i]<'A' || niz[i]>'F') && (niz[i]<'a' || niz[i]>'f')){
			brojac++;
			printf("Procitani niz nije ispravno zadan.\n");
			break;
		}
	}
	if(brojac==0){
		for(i=0; niz[i]!='\0' && i<MAX; i++){
			if(niz[i]>='a' && niz[i]<='z')
				niz[i]=niz[i]-32;
			if(i==0)
				max=niz[i];
			if(niz[i]>max)
				max=niz[i];
		}
		printf("Najveca heksadekadska znamenka koja se pojavljuje u procitanom broju je %c.\n", max);
	}
	return 0;
}