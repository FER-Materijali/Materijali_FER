#include<stdio.h>
int main (void) {
int n, i, broj[40]={0}, brojac=0;

scanf("%d", &n);
while (n>=1 && n<=40) {
++brojac;
if (broj[n-1]==0) {
broj[n-1]=brojac;
}
scanf("%d", &n);
}

for (i=0; i<40; ++i) {
	if (broj[i]>0) {
		printf("Broj %d : %d\n", i+1, broj[i]);
	}
}
return 0;
}