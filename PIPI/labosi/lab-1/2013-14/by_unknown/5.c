#include<stdio.h>

int main(void){
    
			unsigned int x, y, a, b ,c;
			scanf("%u", &x);
			a=x%10;
			b=(x%100)/10;
			c=x/100;
			y=a*b*c;
			printf("\r\n Umnozak znamenaka broja %u je %u", x, y);
			return 0;
}
