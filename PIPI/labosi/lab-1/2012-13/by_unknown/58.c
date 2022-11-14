#include <stdio.h>
#define MAX 30
int main() {
	char niz[MAX+1];
	int i, pom=1;
	gets(niz);
	printf("\n\nUcitani niz je:\n");
	printf("%s\n", niz);
	for(i=0; niz[i]!='\0' && i<MAX; i++){
		if(niz[i]>='A' && niz[i]<='Z' || niz[i]>='a' && niz[i]<='z' || niz[i]>='0' && niz[i]<='9'){
			switch(niz[i]){
			case '5':
				niz[i]='a'; break;
			case '6':
				niz[i]='e'; break;
			case '7':
				niz[i]='i'; break;
			case '8':
				niz[i]='o'; break;
			case '9':
				niz[i]='u'; break;
			default:
				break;
			}
		}
		else{
			printf("Procitani niz nije ispravno zadan.\n");
			pom=0;
			break;
		}
	}
	if(pom){
		printf("\n\nNiz nakon zamjene:\n");
		printf("%s\n", niz);
	}
	return 0;
}