#include<stdio.h>
int main (void) {
int n, i, broj[30]={0};

scanf("%d", &n);
while (n>=1 && n<=30) {
++broj[n-1];
scanf("%d", &n);
}

for (i=0; i<30; ++i) {
	if (broj[i]>=2) {
		printf("broj %d: %d\n", i+1, broj[i]);
	}
}
return 0;
}