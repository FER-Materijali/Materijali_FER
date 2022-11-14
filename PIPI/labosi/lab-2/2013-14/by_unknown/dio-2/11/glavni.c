#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 100

int main(void){

			char s[MAX+1], uz[10+1];
			int i=1;
			memset(s, '\0', MAX);
			memset(uz, '\0', 10);
			printf("Upisi ulaz:");
			gets(s);
			printf("\nUpisi uzorak:");
			gets(uz);
			printf("\nSadrzaj niza ulaz je:");
			puts(s);
			printf("\nSadrzaj niza uzorak je:");
			puts(uz);
			while(i) i=izbaci(s, uz);
			printf("\nNakon izvodenja glavnog programa sadrzaj niza ulaz je:");
			puts(s);
			return 0;
}