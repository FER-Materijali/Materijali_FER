#include<stdio.h>
#define MAX 100
#define MIN 0
#define G 50
							
int main(void){

			int n=0, s=0, z=0;
			while(1){
					printf("Upisi broj iz intervala [0,100]:");
					scanf("%d", &n);
					if((n<MIN) || (n>MAX)){
											if(z==0) printf("\nNije unesen niti jedan broj iz trazenog intervala.");
											break;
					}
					if(n<G) s+=n;
					z=1;
			}
			if(z!=0) printf("\nZbroj svih unesenih brojeva manjih od %d je %d.", G, s);
			return 0;
}