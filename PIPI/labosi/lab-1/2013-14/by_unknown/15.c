#include<stdio.h>

int main(void){
			
			unsigned int x, a, b, c;
			scanf("%u", &x);
			a=x/3600;
			b=(x/60)%60;
			c=x%60;
			printf("\r\n sekunde: %u = sati-minute-sekunde: %u-%u-%u", x, a, b, c);
			return 0;
}