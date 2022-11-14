#include <stdio.h>
#define MAX 80

int palindrom(char *niz){
	int i, je=1, j, duljina;
	duljina=strlen(niz);
	for(i=0; i<duljina; ++i){
		if((niz[i]>='a' && niz[i]<='z') || (niz[i]>='A' && niz[i]<='Z'))
			niz[i]=tolower(niz[i]);
		else{
			while(niz[i]<'a' && niz[i]>'z'){
				j=i;
				while(niz[j]!='\0'){
					niz[j]=niz[j+1];
					++j;
				}
			}
		}
	}
	j=duljina-1;
	for(i=0; i<duljina; ++i, --j){
		if(niz[i]!=niz[j])
			je=0;
	}
	if(je==1)
		return 1;
	else
		return 0;
}

int main (void){
	char ulaz[MAX+1];
	int broj;
	gets(ulaz);
	broj=palindrom(&ulaz);
	if(broj==1)
		printf("niz je palindrom\n");
	else
		printf("niz nije palindrom\n");
	return 0;
}