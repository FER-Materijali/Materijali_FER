#include<stdio.h>
#define MAX 30
#define MIN 1
#define G 2
							
int main(void){

			int p[MAX]={0}, n=0;
			do{
				printf("Unesi broj iz intervala [1,30]:");
				scanf("%d", &n);
				if((n>=MIN) && (n<=MAX)) p[n-1]+=1;
			}while((n>=MIN) && (n<=MAX));
			for(n=0;n<MAX;++n){
							if(p[n]>=G){
										printf("\nBroj %2d: %d", (n+1), p[n]);
							}
			}
			return 0;
}