#include<stdio.h>

int main(void){
			
			int x, a, b, c;
			scanf("%d", &x);
			a=x%10;
			b=(x/10)%10;
			c=x/100;
			printf("\r\n Broj dobiven obrnutim poretkom znamenaka broja %d je %d%d%d", x, a, b, c);
			return 0;
}
			
			