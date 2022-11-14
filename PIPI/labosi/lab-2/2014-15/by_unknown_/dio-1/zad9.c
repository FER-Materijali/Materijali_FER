#include<stdio.h>
int main(void){
	int broj;
	printf("Upisi prirodni broj:");
	scanf("%d", &broj);
	if ((broj%3==0) && (broj%10==8))
		printf("Broj %d je djeljiv s 3 i zadnja znamenka mu je 8.", broj);
	else if ((broj%3!=0) && (broj%10==8))
		printf("Broj %d nije djeljiv s 3 i zadnja znamenka mu je 8.", broj);
	else if ((broj%3==0) && (broj%10!=8))
		printf("Broj %d je djeljiv s 3 i zadnja znamenka mu nije 8.", broj);
	else
		printf("Broj %d nije djeljiv s 3 i zadnja znamenka mu nije 8.", broj);
	return 0;
}