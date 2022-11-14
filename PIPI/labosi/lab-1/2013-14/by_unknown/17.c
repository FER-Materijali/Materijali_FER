#include<stdio.h>

int main(void){
			
			float x, k;
			int y;
			scanf("%f %d", &x, &y);
			if(x<0){
					printf("\r\n Cijena mora biti pozitivni broj.");
					return 0;
			}else if(y<=0){
						printf("\r\n Postotak snizenja mora biti prirodni broj.");
						return 0;
			}
			k=x-(x*((float)y/100));
			printf("\r\n Cijena %.2f umanjena za %d posto iznosi %.2f.", x, y, k);
			return 0;
}
			