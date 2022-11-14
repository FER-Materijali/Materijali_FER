#include"funkcije.h"
#include<stdio.h>
#include<string.h>
#define MAX 300

int main(void){

			int n=0, i=0, j=0, br1=0, br2=0;
			float sl=0;
			char niz1[MAX+1], niz2[MAX+1], pniz1[5+1], pniz2[5+1];
			memset(niz1, '\0', MAX);
			memset(niz2, '\0', MAX);
			memset(pniz1, '\0', MAX);
			memset(pniz2, '\0', MAX);
			printf("Upisi prvi niz:");
			gets(niz1);
			printf("\nUpisi drugi niz:");
			gets(niz2);
			do{
				printf("\nNa podskupove od koliko znakova zelis rastavljati nizove:");
				scanf("%d", &n);
			}while((n<2) || (n>5));
			for(i=0;i<=(strlen(niz1)-n);++i){
										genPodniz(niz1, pniz1, i, n);
										br1=i+1;
										for(j=0;j<=(strlen(niz2)-n);++j){
																	genPodniz(niz2, pniz2, j, n);
																	br2=j+1;
																	sl+=nizoviJednaki(pniz1, pniz2);
										}
			}
			sl=(sl*2)/(br1+br2);
			printf("\nSlicnost nizova %s i %s iznosi %f", niz1, niz2, sl);
			return 0;
}