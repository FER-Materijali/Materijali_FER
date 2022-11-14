#include <stdio.h>
#include "funkcije.h"
#define MAX 100

int main( void ){
	char s1[MAX+1],s2[MAX+1];
	int key;
	do{
		printf("Upisi niz: ");
		gets(s1);
	}while( brojNeSlova(s1) );

	do{
		printf("Upisi kljuc kriptiranja: ");
		scanf("%d",&key);
	}while (key<1 || key>25);

	caesarEncrypt( s1, s2, key );
	printf("Kriptiran niz: %s\nOriginalni niz: %s\n",s2,s1);
	return 0;
}