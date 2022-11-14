#include<stdio.h>
#include<math.h>
int main (void) {
int n, i;
float suma=0, greska;
do {
	scanf("%d", &n);
} while (n<1 || n>1000);
for (i=1; i<=n; ++i) {
suma+=1.f/((2*i-1)*(2*i+1));
}
greska=fabs(suma-0.5);
printf("%f\n%f", suma, greska);
	return 0;
}