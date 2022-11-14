#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 10

int main(void){
			
			float pr[MAX]={0}, ps[MAX]={0};
			int n=0, i=0, j=0, p[MAX][MAX];
			memset(p, 0, sizeof(p));
			do{
				printf("\nUnesite ispravnu dimenziju polja:");
				scanf("%d", &n);
			}while((n<0) || (n>MAX));
			printf("Unesite elemente polja:\n");
			for(i=0;i<n;++i){
				for(j=0;j<n;++j){
								printf("p[%d][%d]:", i, j);
								scanf("%d", &p[i][j]);
				}
			}
			printf("Matrica:\n\n");
			prosjek(&p[0][0], n, MAX, pr, ps);
			for(i=0;i<n;++i){
				printf("%.2f", pr[i]);
				for(j=0;j<n;++j){
								printf("%7d", p[i][j]);
				}
				printf("\n");
			}
			printf("    ");
			for(i=0;i<n;++i) printf("%7.2f", ps[i]);
			return 0;
}