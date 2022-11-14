#include<stdio.h>

int main(void){
			
			int x, y, k;
			scanf("%d %d", &x, &y);
			if(y<x){ 
				printf("\r\n Brojevi nisu dobro zadani");
				return 0;
			}else{
				k=x;
				x=y;
				y=k;
				printf("\r\n x = %d y = %d", x, y);
			}
			return 0;
}			
			