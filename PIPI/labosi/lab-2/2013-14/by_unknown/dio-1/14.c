#include<stdio.h>
#define MAX 30
#define MIN 1
							
int main(void){

			int p[MAX]={0}, n=0, br=0;
			while(1){
					do{
						printf("Unesi broj iz intervala [1,30]:");
						scanf("%d", &n);
					}while((n<MIN) || (n>MAX));
					br+=1;
					if(p[n-1]==0){
								p[n-1]=br;
					}else{
						printf("\nBroj %d je bio %d. ucitani broj.", n, p[n-1]);
						printf("\nUkupno ucitano brojeva: %d", br);
						return 0;
					}
			}
}