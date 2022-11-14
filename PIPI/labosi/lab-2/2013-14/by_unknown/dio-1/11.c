#include<stdio.h>
#define MAX 15
#define MIN 1
#define GG 15
#define DG -10
							
int main(void){

			int i=0, n=0, p[MAX]={0}, pn[MAX]={0}, pm=0;
			do{
				printf("Upisi broj clanova polja:");
				scanf("%d", &n);
			}while((n<=MIN) || (n>=MAX));
			for(i=0;i<n;++i){
							printf("\nUpisi %d. clan polja:", i);
							scanf("%d", &p[i]);
			}
			for(i=0;i<n;++i){
							if((p[i]>=DG) && (p[i]<=GG)){
														pn[pm]=p[i];
														pm+=1;
							}
			
			}
			printf("\nNovo polje:");
			for(i=0;i<pm;++i){
							printf("%4d", pn[i]);			
			}
			return 0;
}