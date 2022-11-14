#include<stdio.h>
int main (void) {
int n, i, polje[30];
do {
	scanf("%d", &n);
} while (n<1 && n>30);
for (i=0; i<n; ++i) {
	scanf("%d", &polje[i]);
}
for (i=0; i<n; ++i) {
	if (polje[i]>=-1 && polje[i]<=22) {
		polje[i]=0;
	}
}
for (i=0; i<n; ++i) {
	printf("%d   ", polje[i]);
}
return 0;
}