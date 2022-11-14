#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 8

int main( void ){
			
			int n=0, h=0, m=0, s=0;
			char niz1[MAX+1]={'\0'}, niz2[3+1]={'\0'};
			while(1){
					printf("\nUnesi sekunde:");
					scanf("%d", &n);
					if(n<0) continue;
					else break;
			}
			hms(n, &h, &m, &s);
			intUNiz(h, niz2); dodajNiz(niz1, niz2);
			intUNiz(m, niz2); dodajNiz(niz1, niz2);
			intUNiz(s, niz2); dodajNiz(niz1, niz2);
			for(n=0;n<(strlen(niz1)-1);++n) printf("%c", niz1[n]);
			return 0;
}