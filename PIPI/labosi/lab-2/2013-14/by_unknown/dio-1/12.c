#include<stdio.h>
#define MAX 30
#define MIN -30
#define G 3
#define L (MAX-MIN+1)
							
int main(void){

			int p[L]={0}, n=0, s=0;
			while(1){
					printf("Unesi broj iz intervala [-30,30]:");
					scanf("%d", &n);
					if((n<MIN) || (n>MAX)){
										printf("\nBroj je izvan intervala.");
										return 0;
					}else{
						p[n+MAX]+=1;
						s+=1;
						for(n=0;n<L;++n){
										if(p[n]>=G){
												printf("\nUkupno je ucitano %d br.", s);
												return 0;
										}
						}
					}
			}
}