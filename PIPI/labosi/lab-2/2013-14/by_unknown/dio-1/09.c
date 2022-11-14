#include<stdio.h>
#define MAX 30
#define MIN 1
#define GG 22
#define DG -1
				
int main(void){

			int i=0, n=0, p[MAX]={0};
			do{
				printf("Upisi broj clanova polja:");
				scanf("%d", &n);
			}while((n<=MIN) || (n>=MAX));
			for(i=0;i<n;++i){
							printf("\nUpisi %d. clan polja:", i);
							scanf("%d", &p[i]);
			}
			for(i=0;i<n;++i){
							if((p[i]>=DG) && (p[i]<=GG)) p[i]=0;
			}
			printf("\nPromijenjeno polje:");
			for(i=0;i<n;++i){
							printf("%4d", p[i]);
			}
			return 0;
}