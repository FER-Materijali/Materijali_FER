#include<stdio.h>

int main(void){
    
			int x, y, z;
			scanf("%d", &x);
			y=x%10;
			z=x/10;
			if((z!=5) && (z>0)) printf("\r\n Prva znamenka broja %d je %d", x, z);
			else if((z!=5) && (z<0)) printf("\r\n Prva znamenka broja %d je %d", x, -z);
			else printf("\r\n Zadnja znamenka broja %d je %d", x, y);
			return 0;
}
