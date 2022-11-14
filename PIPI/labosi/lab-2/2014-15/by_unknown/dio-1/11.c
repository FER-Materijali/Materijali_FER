#include<stdio.h>
int main (void) {
int n, i, j=0, niz[15], niz2[15];
do {
	scanf("%d", &n);
} while (n<1 || n>15);
for (i=0; i<n; ++i) {
	scanf("%d", &niz[i]);
}
for (i=0; i<n; ++i) {
	if (niz[i]>=-10 && niz[i]<=15) {
		niz2[j]=niz[i];
		++j;
		}
	}
for (i=0; i<j; ++i) {
printf ("%d ", niz2[i]);
}
return 0;
}