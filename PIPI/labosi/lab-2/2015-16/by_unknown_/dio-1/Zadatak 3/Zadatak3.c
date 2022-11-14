#include <stdio.h>
#define MAX 60

int main(void){
	char niz[MAX + 1] = {'0'};
	int i, Duzina = 0;
	gets(niz);
	while(niz[Duzina] != '\0'){
		Duzina += 1;
	}
	if(niz[9] != '\0' && niz[9] != '0'){
		for(i = (Duzina - 1); i >= 0; i--){
			if((niz[i] <= 90 && niz[i] >= 65) || (niz[i] <= 57 && niz[i] >= 48)){
				printf("%c\n", niz[i]);
			}
		}
	}else{
		printf("Prekratak niz.\n");
	}
	return 0;
}