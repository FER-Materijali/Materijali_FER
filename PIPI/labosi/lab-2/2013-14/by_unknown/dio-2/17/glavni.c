#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 10

int main(void){
			
			int polje[MAX][MAX], pm[MAX]={0}, i=0, j=0, r=0, s=0;
			memset(polje, 0, sizeof(polje));
			do{
				printf("Upisi broj redaka i stupaca:");
				scanf("%d %d", &r, &s);
			}while((r<0) || (r>MAX) || (s<0) || (s>MAX));
			for(i=0;i<r;++i){
				for(j=0;j<s;++j){
								printf("\nUpisi [%d,%d] clan:", (i+1), (j+1));
								scanf("%d", &polje[i][j]);
				}
			}
			kvadrat(&polje[0][0], r, s, MAX);
			minStupac(&polje[0][0], r, s, MAX, &pm[0]);
			for(i=0;i<r;++i){
				for(j=0;j<s;++j){
								printf("%4d", polje[i][j]);
				}
			printf("\n");
			}
			for(i=0;i<s;++i) printf("%4d", pm[i]);
			return 0;
}