#include<stdio.h>

int main(void){

			int x, a, c;
			scanf("%d", &x);
			a=x/100;
			c=x%10;
			if(a==c) printf("\r\n Broj %d je palindrom.", x);
			else
			printf("\r\n Broj %d nije palindrom.", x);
			return 0;
}