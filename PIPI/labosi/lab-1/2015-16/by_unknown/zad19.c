#include <stdio.h>
int main(void) {
	int a,b;
	printf("Ucitajte dva prirodna broja: ");
	scanf("%d %d", &a, &b);
	if (a==b)
		printf("Brojevi moraju biti razliciti");
	else {
		if (a>b)
			if (a%b==0)
				printf("Broj %d je visekratnik broja %d", a, b);
		if (a<b)
			if (b%a==0)
				printf("Broj %d je visekratnik broja %d", b, a);
	}
	if ((a%b!=0) && (b%a!=0))
		printf("Niti jedan broj nije visektratnik drugog broja");
	return 0;
}