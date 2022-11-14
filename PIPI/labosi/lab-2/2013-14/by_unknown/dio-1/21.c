#include<stdio.h>
#define MAX 99999
#define MIN 1
							
int main(void){

			int p[10]={0}, n=0, s=0;
			do{
				printf("Upisi broj iz intervala [1,99999]:");
				scanf("%d", &n);
			}while((n<MIN) || (n>MAX));
			printf("\nBroj %d - suma znamenaka koje se jednom pojavljuju:", n);
			while(n!=0){
						p[n%10]+=1;
						n/=10;
			}
			for(n=0;n<10;++n){
							if(p[n]==1) s+=n;
			}
			printf("%3d", s);
			return 0;
}