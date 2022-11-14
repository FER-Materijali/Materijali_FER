#include<stdio.h>
int main (void) {
int n, i, suma=0, frekv[10]={0};
do {
	scanf("%d", &n);
} while (n<1 || n>99999);
printf("\nBroj %d - ", n);
while (n!=0) {
    ++frekv[n%10];
	n/=10;
}
for (i=0; i<10; ++i) {
	if (frekv[i]==1) {
		suma+=i;
	}
}
printf("suma znamenaka koje se jednom pojavljuju: %d\n", suma);
return 0;
}