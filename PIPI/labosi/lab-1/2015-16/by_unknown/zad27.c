#include <stdio.h>
int main(void) {
	int a,b,b1,b2;
	printf("Unesite 2 jednoznamenkasta broja\n");
	scanf("%d %d", &a, &b);
	b1=a*10+b;
	b2=b*10+a;
	if ((b1%2==0) && (b2%2==0))
		printf("Parni brojevi kreirani od znamenaka %d i %d: %d %d",a , b, b1, b2);
	if ((b1%2==0) && (b2%2!=0))
		printf("Parni brojevi kreirani od znamenaka %d i %d: %d",a , b, b1);
	if ((b1%2!=0) && (b2%2==0))
		printf("Parni brojevi kreirani od znamenaka %d i %d: %d",a , b, b2);
	if ((b1%2!=0) && (b2%2!=0))
		printf("Parni brojevi kreirani od znamenaka %d i %d: -",a , b);
	return 0;
}
		
		
	
	