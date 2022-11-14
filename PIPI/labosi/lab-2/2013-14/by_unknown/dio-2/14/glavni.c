#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 9

int main(void){
			
			char s1[MAX+1]={0}, s2[MAX+1]={0}, op=0;
			int a=0, b=0, rez=0;
			printf("Unesi prvi niz:");
			gets(s1);
			printf("\nUnesi drugi niz:");
			gets(s2);
			printf("\nUnesi operator:");
			scanf("%c", &op);
			a=nizUInt(s1);
			b=nizUInt(s2);
			if((a==-1) && (b==-1)) printf("\nOba niza su neispravno zadana.");
			else if(a==-1) printf("\nUcitani niz %s nije ispravno zadan.", s1);
			else if(b==-1) printf("\nUcitani niz %s nije ispravno zadan.", s2);
			else if(matemOp(op, a, b, &rez)==0) printf("\nOperator nije ispravno zadan.");
			else printf("\nRezultat je %d.", rez);
			return 0;
}