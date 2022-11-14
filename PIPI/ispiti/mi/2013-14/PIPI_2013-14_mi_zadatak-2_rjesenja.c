#include <stdio.h>

int main (void){
	int broj;
	char niz[10+1], niz2[10+1], slovo;
	gets(niz);
	printf("koje slovo na koje mjesto: ");
	scanf("%c %d", &slovo, &broj);
	if((niz[broj]>='a' && niz[broj]<='z') || (niz[broj]>='A' && niz[broj]<='Z') ||
		(niz[broj]>='0' && niz[broj]<='9')){
		strcpy(niz2, niz);
		niz2[broj]=slovo;
	}
	else{
		strcpy(niz2, niz);
		niz2[broj]='?';
	}
	puts(niz);
	puts(niz2);
	return 0;
}