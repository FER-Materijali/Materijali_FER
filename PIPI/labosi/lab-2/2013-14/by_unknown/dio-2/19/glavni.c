#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 200
#define maxR 100
#define maxS 20

int main(void){
			
			char niz[MAX+1]={0}, polje[maxR+1][maxS+1];
			int i=0, j=0, br=0, n=0, d=0, maxr=0;
			memset(polje, '\0', sizeof(polje));
			printf("Upisi niz:");
			gets(niz);
			printf("\nUpisi broj rijeci, duljinu rijeci i max rijeci:");
			scanf("%d %d %d", &br, &d, &maxr);
			rastavi(niz, br, maxr, d, &polje[0][0]);
			n=brojRijeci(&polje[0][0]);
			printf("\nBroj rijeci u polju je:%d\n", n);
			 for(i=0;i<maxr;++i){
				if(polje[i][j]=='\0') break;
				for(j=0;j<d;++j){
										printf("%c", polje[i][j]);
				}
				printf("\n");
				j=0;
			}
			return 0;
}