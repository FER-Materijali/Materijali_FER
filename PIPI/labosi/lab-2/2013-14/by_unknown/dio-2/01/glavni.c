#include"funkcije.h"
#include<stdio.h>
#define MAX 100
#define MIN 3
						
int main(void){

			int i=0, j=0, n=0, post[MAX]={0};
			double latitude[MAX]={0}, longtitude[MAX]={0};
			do{
				printf("Upisi broj gradova(od 3 do 100):");
				scanf("%d", &n);
			}while((n<MIN) || (n>MAX));
			for(i=0;i<n;++i){
							do{
								printf("\nUpisite postanski broj i koordinate %d. grada:", (i+1));
								scanf("%d %lf %lf", &post[i], &latitude[i], &longtitude[i]);
							}while(((latitude[i]<-180) || (latitude[i]>180)) || ((longtitude[i]<-90) || (longtitude[i]>90)) || (post[i]<0));
			}
			printf("\nMedjusobne udaljenosti gradova:");
			for(i=0;i<n;++i){
				for(j=i+1;j<n;++j){
								printf("\n%d - %d: %lf km", post[i], post[j], izracunajUdaljenost(latitude[i], latitude[j], longtitude[i], longtitude[j]));
				}
			}
			return 0;
}