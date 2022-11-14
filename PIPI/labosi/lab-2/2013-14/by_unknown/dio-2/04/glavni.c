#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 20

int main(void){

			int ln=0;
			char s1[MAX+1], s2[(MAX*5)+1];
			memset(s1, '\0', MAX);
			memset(s2, '\0', (MAX*5));
			while(1){
					printf("\nUcitaj niz:");
					gets(s1);
					if(strlen(s1)>MAX) continue;
					if(dobarNiz(s1)==0) continue;
					if(dobarNiz(s1)==1) break;
			}
			do{
				printf("\nUpisi duljinu niza kojeg je potrebno generirati:");
				scanf("%d", &ln);
			}while((ln<0) || (ln>(5*MAX)));
			generirajNiz(s1, ln, s2);
			printf("\nUcitani niz: ");
			puts(s1);
			printf("\nGenerirani niz: ");
			puts(s2);
			return 0;
}