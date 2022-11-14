#include <stdio.h>
int main(void) {
	int a,b;
	printf("Ucitajte 2 prirodna broja");
	scanf("%d %d", &a, &b);
	if ((a%2==0) && (b%2==0)){
		if (a<b)
			printf("Manji parni broj je: %d", a);
		if (a>b)
			printf("Manji parni broj je: %d", b);
	}
	if ((a%2==0) && (b%2!=0))
		printf("Manji parni broj je: %d", a);
	if ((b%2==0) && (a%2!=0))
		printf("Manji parni broj je: %d", b);
	if ((a%2!=0) && (b%2!=0))
		printf("Niti jedan broj nije paran");
	return 0;
}
		