#include<stdio.h>
#define MAX 40
#define MIN 1
							
int main(void){

			int p[MAX]={0}, n=0, i=0;
			do{
				printf("Unesi broj iz intervala [1,40]:");
				scanf("%d", &n);
				if((n>=MIN) && (n<=MAX) && (p[n-1]==0)){
										i+=1;
										p[n-1]=i;
				}
			}while((n>=MIN) && (n<=MAX));
			for(i=0;i<MAX;++i){
							if(p[i]!=0) printf("\nBroj %2d:%2d", (i+1), p[i]);
			}
			return 0;
}