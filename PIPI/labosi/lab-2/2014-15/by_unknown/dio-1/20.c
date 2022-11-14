#include<stdio.h>
int main (void) {
int n, zadnja;
do {
	scanf("%d", &n);
} while (n<1 || n>99999);
printf("\nBroj %d: ", n);
zadnja=n%10;
while (n/10!=0) {
	n/=10;
}
if (n>zadnja) {
	printf("prva znamenka veca od zadnje");
} else if (n<zadnja) {
	printf("prva znamenka manja od zadnje");
} else {
	printf("prva i zadnja znamenka su jednake");
}
return 0;
}