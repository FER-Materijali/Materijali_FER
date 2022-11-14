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
			case '0':
				niz[i]='A'; break;
			case '1':
				niz[i]='E'; break;
			case '2':
				niz[i]='I'; break;
			case '3':
				niz[i]='O'; break;
			case '4':
				niz[i]='U'; break;
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
