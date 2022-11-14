#include<stdio.h>

int main(void){
			
			int x, y;
			float k;
			scanf("%d %d", &x, &y);
			if((x+y)>0){
					k=((float)x+(float)y)/2;
					printf("\r\n Aritmeticka sredina brojeva %d i %d: %.4f", x, y, k);
					}else{
						k=(1./x)+(1./y);
						if(k<0) k=-k;
						printf("\r\n Izracunata vrijednost: %.4f", k);
			}
			return 0;
}
								
						