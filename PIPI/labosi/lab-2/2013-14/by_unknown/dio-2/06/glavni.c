#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 100

int main(void){

			char su[MAX+1], si[MAX+1];
			int k=0;
			memset(su, '\0', MAX);
			memset(si, '\0', MAX);
			do{
				printf("\nUpisi niz:");
				gets(su);
			}while(brojNeSlova(su));
			do{
				printf("\nUpisi kljuc enkripcije:");
				scanf("%d", &k);
			}while((k<1) || (k>25));
			caesarEncrypt(su, si, k);
			printf("\nOriginalni niz:");
			puts(su);
			printf("\nKriptirani niz:");
			puts(si);
			return 0;
}