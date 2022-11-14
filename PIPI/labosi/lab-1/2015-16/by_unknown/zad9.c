#include <stdio.h>
int main(void) {
	int a;
	printf("Ucitajte prirodan broj");
	scanf("%d", &a);
	if (a%10==8) {
		if (a%3==0)
			printf("Broj je djeljiv s 3 i zadnja znamenka mu je 8");
		else
			printf("Broj nije djeljiv s 3, ali zadnja znamenka mu je 8");
	}else {
		if (a%3==0)
			printf("Broj nema zadnju znameku 8, ali je djeljiv sa 3");
		else
			printf("Broj nema zadnju znameku 8 niti je djeljiv sa 3");	
	}
	return 0;
}