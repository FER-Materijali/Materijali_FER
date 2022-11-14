#include<stdio.h>
#include<math.h>
#define PI 3.141593
int main (void) {
int n, i, p=1, niz[1000];
float pi, suma=0, greska;
do {
	scanf("%d", &n);
} while (n<1 || n>1000);
for (i=1; i<=n; ++i) {
	suma+=p*1.f/(2*i-1);
	p*=-1;
}
pi=4*suma;
greska=fabs(PI-pi);
printf("%f\n%f", pi, greska);
	return 0;
}