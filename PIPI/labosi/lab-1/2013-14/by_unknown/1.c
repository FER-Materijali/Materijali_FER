#include<stdio.h>

int main(void){
    
			int x, y, z;
			printf("Upisi troznamenkasti prirodni broj:\r\n");
			scanf("%d", &x);
			y=x % 10;
			z=x % 100;
			if(y<5){
				printf("\r\n Zadnja znamenka broja %d je %d", x, y);
			}else{
				printf("\r\n Zadnje dvije znamenke broja %d su %d", x, z);
			}
			return 0;
}
