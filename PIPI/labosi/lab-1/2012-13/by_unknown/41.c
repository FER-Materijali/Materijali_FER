#include <stdio.h>
#define MAX 10
int main() {
	char niz[MAX+1];
	int i, brojac=0, k=0, l=0;
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
			if(niz[i]=='0' && niz[i+1]=='0'){
				l++;
				printf("Procitani broj sadrzi dvije ili vise uzastopnih znamenki 0.\n");
				break;
			}
		}
		if(l==0)
			printf("Procitani binarni broj ne sadrzi dvje ili vise uzastopnih znamenki 0.\n");
	}
	return 0;
}