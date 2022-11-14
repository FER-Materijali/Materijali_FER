#include<stdio.h>
int main (void) {
int n, broj[30]={0}, brojac=0, ponovljen=0;

while (ponovljen==0) {
do {
scanf("%d", &n);
} while (n<1 || n>30);
++brojac;
if (broj[n-1]==0) {
broj[n-1]=brojac;	
} else {
	ponovljen=1;
}
}

printf("Broj %d bio je %d. ucitani broj.\nUkupno ucitano brojeva: %d", n, broj[n-1], brojac);
return 0;
}