#include <stdio.h>
#include <math.h>

int main(){
	int n, i=1, x;

	printf("Unesi n: ");
	scanf("%d", &n);
	x=n;

	printf("\nIspis prostih faktora: ");
	if(n==0) printf("Broj nema prostih faktora.");
	else if(i==n) printf("%d", i);
	else {
		i++;
		do{
			if(!(n%i)) {
				if(i==x) {
					printf("Zadali ste prosti broj!");
					break;
				}
				printf("%d  ", i);
				n/=i;
			}
			if(n%i) i++;
		}while(n!=1);
	}

	printf("\n\n\n");

	return 0;
}