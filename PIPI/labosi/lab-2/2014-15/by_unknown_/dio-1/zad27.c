#include<stdio.h>
int main(void){
	int a, b;
	printf("Upisi dva jednoznamenkasta prirodna broja: ");
	scanf("%d %d", &a, &b);
	if ((a%2==0) && (b%2==0))
		printf("Parni brojevi kreirani od znamenaka %d i %d: %d %d", a, b, a*10+b, b*10+a);
	else if ((a%2==0) && (b%2!=0))
		printf("Parni brojevi kreirani od znamenaka %d i %d: %d", a, b, b*10+a);	
	else if ((a%2!=0) && (b%2==0))
		printf("Parni brojevi kreirani od znamenaka %d i %d: %d", a, b, a*10+b);
	else
		printf("Parni brojevi kreirani od znamenaka %d i %d: - ", a, b);
	return 0;
}