#include<stdio.h>
int main (void) {
int n, i, frekv[10]={0};
do {
	scanf("%d", &n);
} while (n<100 || n>99999);
printf("\nZnamenke u broju %d su:\n", n);
while (n!=0) {
	++frekv[n%10];
	n/=10;
}
for (i=0; i<10; ++i) {
	 if (frekv[i]>0) {
	 	printf("   -  znamenka %d: %d\n", i, frekv[i]);
	 }
}
return 0;
}