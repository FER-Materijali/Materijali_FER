#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 2000

int main(void){

			int i=0;
			char tekst[MAX+1];
			memset(tekst, '\0', MAX);
			for(i=0;i<MAX;++i) scanf("%c", &tekst[i]);
			if(br_rijeci(tekst)==0) printf("\n Zadani tekst ne sadrzi rijeci!");
			else printf("\nZadani tekst sadrzi rijeci/odlomaka: %d/%d.", br_rijeci(tekst), br_odlomaka(tekst));
			return 0;
}