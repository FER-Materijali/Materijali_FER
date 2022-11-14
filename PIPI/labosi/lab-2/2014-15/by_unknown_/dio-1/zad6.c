#include<stdio.h>
int main(void){
	int broj1, broj2, znam1, znam2;
	printf("Upisi dva dvoznamenkasta prirodna broja:");
	scanf("%d %d", &broj1, &broj2);
	znam1 = broj1%10 + broj1/10;
	znam2 = broj2%10 + broj2/10;
	if (znam1>znam2)
		printf("Broj %d ima vecu sumu znamenaka od broja %d", broj1, broj2);
	else if (znam1<znam2)
		printf("Broj %d ima vecu sumu znamenaka od broja %d", broj2, broj1);
	else
		printf("Broj %d ima jednaku sumu znamenaka kao broj %d", broj1, broj2);
	return 0;
}