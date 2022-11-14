#include<stdio.h>
#define MAX 100
#define MIN 0
							
int main(void){

			int n=0, z=0, max1=0, max2=0;
			while(1){
					printf("Upisi broj iz intervala [0,100]:");
					scanf("%d", &n);
					if((n<MIN) || (n>MAX)){
											if(z==1){
													printf("\nNije uneseno dovoljno brojeva iz trazenog intervala.");
													return 0;
											}
											break;
					}
					z+=1;
					if(n>max1){
								max2=max1;
								max1=n;
					}else if(n>max2){
									max2=n;
					}
			}
			if(z>1) printf("\nOstatak pri dijeljenju %d sa %d je %d.", max1, max2, (max1%max2));
			return 0;
}