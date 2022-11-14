#include<stdio.h>
#define MAX 100
#define MIN 0
							
int main(void){

			int n=0, min=MAX, max=MIN, z=0;
			while(1){
					printf("Upisi broj iz intervala [0,100]:");
					scanf("%d", &n);
					if((n<MIN) || (n>MAX)){
											printf("\nBroj je izvan intervala.");
											break;
					}
					if((n>=max) && (n%4==0)) max=n;
					if((n<=min) && (n%4==0)) min=n;
					z=1;
			}
			if(z==1) printf("\nZbroj najveceg(%d) i najmanjeg(%d) unesenog broja djeljivog s 4 je %d.", max, min, (min+max));
			return 0;
}