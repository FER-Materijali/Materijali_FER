#include"funkcije.h"
#include<stdio.h>
#define MAX 20
						
int main(void){

			int n=0, i=0, j=0, p=0, skup1[MAX]={0}, skup2[MAX]={0}, rez[2*MAX]={0}, ls1=0, ls2=0, lsr=(2*MAX);
			for(i=0;i<MAX;++i){
								printf("\nUpisi %d. clan skupa 1:", (i+1));
								scanf("%d", &n);
								if(n<=0) break;
								p=0;
								skup1[i]=n;
								for(j=0;j<MAX;++j){
												if(skup1[i]==skup1[j]) p+=1;
								}
								if(p>1){
										skup1[i]=0;
										i-=1;
								}
			}
			for(i=0;i<MAX;++i){
								printf("\nUpisi %d. clan skupa 2:", (i+1));
								scanf("%d", &n);
								if(n<=0) break;
								p=0;
								skup2[i]=n;
								for(j=0;j<MAX;++j){
												if(skup2[i]==skup2[j]) p+=1;
								}
								if(p>1){
										skup2[i]=0;
										i-=1;
								}
			}
			for(i=0;i<MAX;++i){
								if(skup1[i]==0){
												ls1=i;
												break;
								}
			}
			for(i=0;i<MAX;++i){
								if(skup2[i]==0){
												ls2=i;
												break;
								}
			}
			unija(ls1, skup1, ls2, skup2, lsr, rez);
			if(je_podskup(ls1, skup1, ls2, skup2)==1){ 
													printf("\nSkup 1 JE podskup skupa 2.");
			}else{
				printf("\nSkup 1 NIJE podskup skupa 2.");
			}
			if(je_podskup(ls2, skup2, ls1, skup1)==1){
													printf("\nSkup 2 JE podskup skupa 1.");
			}else{
				printf("\nSkup 2 NIJE podskup skupa 1.");
			}
			return 0;
}