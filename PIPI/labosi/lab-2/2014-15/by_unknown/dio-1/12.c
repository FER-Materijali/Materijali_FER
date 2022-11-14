#include<stdio.h>
int main (void) {
int broj[61]={0}, n, brojac=0;

while (brojac<=123) {
scanf("%d", &n);
if (n<-30 || n>30) {
	printf("Unesen je broj izvan intervala");
	break;
} else {
	++broj[n+30];
	++brojac;
		if (broj[n+30]>=3) {
			printf("Ukupno je ucitano %d brojeva", brojac);
			break;
		}
}
}
return 0;
}