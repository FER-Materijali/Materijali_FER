#include<stdio.h>
#define MAX 1000
#define MIN 1
#define PI 3.141593

float absf(float x);

int main(void){

			int n=0, i=0;
			float pi=0;
			do{
				printf("Unesi broj clanova niza:");
				scanf("%d", &n);
			}while((n<MIN) || (n>MAX));
			for(i=1;i<=n;++i){
							if(i%2==0){
										pi-=1.f/((2*i)-1);
							}else{
									pi+=1.f/((2*i)-1);
							}
			}
			pi*=4;
			printf("\nVrijednost konstante PI odredene parcijalnom sumom: %f", pi);
			printf("\nApsolutna pogreska: %f", absf(pi-PI));
			return 0;
}

float absf(float x){
					if(x<0) x=-x;
					return x;
}