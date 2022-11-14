#include<stdio.h>
#define MAX 1000
#define MIN 1
#define BR 0.5

float absf(float x);
				
int main(void){

			int n=0, i=0;
			float br=0;
			do{
				printf("Unesi broj clanova niza:");
				scanf("%d", &n);
			}while((n<MIN) || (n>MAX));
			for(i=1;i<=n;++i){
							br+=1.f/(((2*i)-1)*((2*i)+1));
			}
			printf("\nVrijednost broja 1/2 odredena parcijalnom sumom: %f", (br));
			printf("\nApsolutna pogreska: %f", absf(br-BR));
			return 0;
}

float absf(float x){
					if(x<0) x=-x;
					return x;
}