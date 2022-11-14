#include<stdio.h>
int main(void){
	int broj1, broj2;
	printf("Upisi dva prirodna broja:");
	scanf("%d %d", &broj1, &broj2);
	if (broj1==broj2)
		printf("Brojevi moraju biti razliciti.");
	else if (broj1%broj2==0)
		printf("Broj %d je visekratnik broja %d", broj1, broj2);
	else if (broj2%broj1==0)
		printf("Broj %d je visekratnik broja %d", broj2, broj1);
	else
		printf("Niti jedan ucitani broj nije visekratnik drugog ucitanog broja.");
	return 0;
}