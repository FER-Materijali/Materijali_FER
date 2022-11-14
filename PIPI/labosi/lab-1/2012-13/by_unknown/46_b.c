#include <stdio.h>
#define MAX 5
int main() {
	char niz[MAX+1];
	int i, brojac=0, max, k, l=0, p=0;
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
			k=0;
			if(niz[i]>='a' && niz[i]<='f'){
				k++;
				niz[i]=niz[i]-32;
			}
			if(i==0)
				max=niz[i];
			else if(niz[i]>max)
				max=niz[i];
			if(k && max==niz[i]){
				p=1;
				l=i;
			}
		}
		if(l==0 && p){
			if(max==niz[l] && 1)
				max=niz[l]+32;
		}
		else
			if(max==niz[l] && l)
				max=niz[l]+32;
		printf("Najveca heksadekadska znamenka koja se pojavljuje u procitanom broju je %c.\n", max);
	}
	return 0;
}
