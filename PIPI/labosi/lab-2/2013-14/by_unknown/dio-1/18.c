#include<stdio.h>
#define MAX 99999
#define MIN 100
							
int main(void){

			int p[10]={0}, n=0;
			do{
				printf("Upisi broj iz intervala [100,99999]:");
				scanf("%d", &n);
			}while((n<MIN) || (n>MAX));
			printf("\nZnamenke u broju %d su:\n", n);
			while(n!=0){
						p[n%10]+=1;
						n/=10;
			}
			for(n=0;n<10;++n){
							if(p[n]!=0) printf("\n-  znamenka %d:%2d", n, p[n]);
			}
			return 0;
}