#include <stdio.h>
#define MAX 5
int main() {
	char niz[MAX+1];
	int i, brojac=0, min;
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
			if(i==0)
				min=niz[i];
			if(niz[i]<min)
				min=niz[i];
		}
		printf("Najmanja oktalna znamenka koja se pojavljuje u procitanom broju je %c.\n", min);
	}
	return 0;
}