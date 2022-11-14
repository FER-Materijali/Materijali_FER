#include <stdio.h>
int main(void) {
	int a;
	printf("Unesi broj:");
	scanf("%d", &a);
	if (a<0){
		printf("Neispravan");
	} else {
		if (a%2==0)
			printf("Paran");
		else
			printf("Neparan");
	
	}
	return 0;
}