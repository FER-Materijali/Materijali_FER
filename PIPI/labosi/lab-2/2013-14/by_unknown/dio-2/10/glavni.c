#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 100

int main(void){

			char s1[MAX+1], s2[MAX+1];
			memset(s1, '\0', MAX);
			memset(s2, '\0', MAX);
			printf("Upisi niz:");
			gets(s1);
			kodiraj(s1, s2);
			printf("\nOriginalni niz:");
			puts(s1);
			printf("\nKodirani niz:");
			puts(s2);
			return 0;
}