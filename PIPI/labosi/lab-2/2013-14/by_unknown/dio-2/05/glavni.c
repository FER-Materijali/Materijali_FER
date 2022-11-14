#include"funkcije.h"
#include<stdio.h>
#define MAX 200

int main(void){

			char niz2[MAX+1];
			char niz1[3+1]={'!', '.', '?'};
			int n=0;
			for(n=0;n<MAX;++n) niz2[n]='\0';
			printf("Upisi niz:");
			gets(niz2);
			n=brojRecenica(niz2, niz1);
			if(n==0) printf("\nTekst\n'%s'\nne sadrzi niti jednu potpunu recenicu.", niz2);
			else printf("\nBroj recenica u tekstu:\n'%s'\nje %d.", niz2, n);
			return 0;
}