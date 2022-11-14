#include<stdio.h>
#define MAX 20
#define MIN 1
#define GG 10
#define DG -10
							
int main(void){

			int i=0, n=0, p[MAX]={0}, s=0;
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
														s+=p[i];
														p[i]=0;
							}
			}
			printf("\nZbroj vrijednosti promijenjenih elemenata: %d", s);
			return 0;
}