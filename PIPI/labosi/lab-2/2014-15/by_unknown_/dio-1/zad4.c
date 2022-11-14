#include<stdio.h>
int main(void){
	int a;
	printf("Upisi cijeli broj:");
	scanf("%d", &a);
	if (a<1) 
	printf("Neispravan broj");
	else if (a%2==0) printf("Broj je paran.");
	else printf("Broj je neparan.");
	return 0;
}