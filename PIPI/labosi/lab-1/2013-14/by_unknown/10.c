#include<stdio.h>

int main(void){

			int x, y, a, b, c;
			scanf("%d", &x);
			a=x/100;
			b=(x/10)%10;
			c=x%10;
			y=(a*a*a)+(b*b*b)+(c*c*c);
			if(x==y) printf("\r\n Broj %d je Armstrongov broj.", x);
			else printf("\r\n Broj %d nije Armstrongov broj.", x);
			return 0;
}