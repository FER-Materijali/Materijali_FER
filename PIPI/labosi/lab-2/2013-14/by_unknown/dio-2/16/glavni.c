#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 20

int main(void){
			
			int polje[MAX][MAX], i=0, j=0, r=0, s=0, min=0, max=0;
			memset(polje, 0, sizeof(polje));
			do{
				printf("\nUpisi broj redaka i stupaca:");
				scanf("%d %d", &r, &s);
			}while(dobreDimenzije(r, s, MAX, MAX)==0);
			for(i=0;i<r;++i){
				for(j=0;j<s;++j){
								printf("\nUpisi (%d,%d) clan:", (i+1), (j+1));
								scanf("%d", &polje[i][j]);
				}
			}
			printf("\n");
			minMax(*polje, r, s, &min, &max, MAX);
			for(i=0;i<r;++i){
				for(j=0;j<s;++j){
								printf("%4d", polje[i][j]);
				}
				printf("\n");
			}
			printf("\nNajveci clan polja:%d\nNajmanji clan polja:%d", max, min);
			return 0;
}