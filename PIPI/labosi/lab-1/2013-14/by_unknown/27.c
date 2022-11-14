#include<stdio.h>

int main(void){

			unsigned int x, y, a, b;
			scanf("%u %u", &x, &y);
			a=(x*10)+y;
			b=(y*10)+x;
			if((a%2==0) && (b%2==0)) printf("\r\n Parni brojevi kreirani od znamenaka %u i %u: %u %u", x, y, a, b);
			else if(a%2==0) printf("\r\n Parni brojevi kreirani od znamenaka %u i %u: %u", x, y, a);
			else if(b%2==0) printf("\r\n Parni brojevi kreirani od znamenaka %u i %u: %u", x, y, b);
			else printf("\r\n Parni brojevi kreirani od znamenaka %u i %u: -", x, y);
			return 0;
}
			