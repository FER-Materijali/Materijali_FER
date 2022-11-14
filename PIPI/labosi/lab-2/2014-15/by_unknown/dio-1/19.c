#include<stdio.h>
int main (void) {
int n, max=0;
do {
	scanf("%d", &n);
} while (n<100 || n>99999);
printf("\nU broju %d najveca znamenka je: ", n);
while (n!=0) {
	if (n%10>max) {
		max=n%10;
	}
	n/=10;
}
printf("%d\n", max);
return 0;
}