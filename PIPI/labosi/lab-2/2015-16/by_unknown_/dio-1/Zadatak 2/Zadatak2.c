#include <stdio.h>
#define MAX 60

int main(void){
	char niz[MAX + 1] = {'0'};
	int i = 0;
	gets(niz);
	if(niz[10] != '\0' && niz[10] != '0'){
		while(niz[i] != '\0' && niz[i] != '0'){
			if(niz[i] >= 97 && niz[i] <= 122){
				printf("%c\n", niz[i]);
			}
			i += 2;
		}
	}else{
		printf("Prekratak niz.\n");
	}
	return 0;
}