#include <stdio.h>
#include <math.h>

int main(){
	int x, n, i=2, j=1;

	do{
		printf("Unesi n: ");
		scanf("%d", &n);
		printf("\nUnesi x: ");
		scanf("%d", &x);

		do{
			if(!(n%i)){
				i++;
			}
			if(n%i)i++;
		}while(n!=1);





	}while();