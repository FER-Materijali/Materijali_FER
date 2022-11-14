#include <stdio.h>
#define MAX 5
int main() {
	char niz[MAX+1];
	int i, brojac=0, min, k, l=0, p=0;
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
				min=niz[i];
			else if(niz[i]<min)
				min=niz[i];
			if(k && min==niz[i]){
				p=1;
				l=i;
			}
		}
		if(l==0 && p){
			if(min==niz[l] && 1)
				min=niz[l]+32;
		}
		else
			if(min==niz[l] && l)
				min=niz[l]+32;
		printf("Najmanja heksadekadska znamenka koja se pojavljuje u procitanom broju je %c.\n", min);
	}
	return 0;
}