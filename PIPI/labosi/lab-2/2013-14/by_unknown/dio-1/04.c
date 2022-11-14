#include<stdio.h>
#define MAX 20
#define MIN 1
#define GG 20
#define DG 10

int main(void){

			int n=0, p[MAX]={0}, i=0;
			do{
				printf("Upisi broj clanova polja:");
				scanf("%d", &n);
			}while((n<MIN) || (n>MAX));
			for(i=0;i<n;++i){
							printf("\nUpisi %d. clan polja:", i);
							scanf("%d", &p[i]);
			}
			for(i=0;i<n;++i){
							if((p[i]>=DG) && (p[i]<=GG)){
														printf("\n%2d. %d", i, p[i]);
							}
			}
			return 0;
}