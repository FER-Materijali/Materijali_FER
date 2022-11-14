#include <stdio.h>
#define MAX 5
int main() {
	int broj, suma=0, i=0, pomocna=0;
	do{
		scanf("%d", &broj);
		if(broj>=0 && broj<=100){
			pomocna=1;
			if(broj%17==0)
				i++;
		}
		else if(pomocna==0){
			printf("Nije unesen niti jedan broj iz trazenog intervala.\n");
		}
	}while(broj>=0 && broj<=100);
	if(i)
		printf("Broj unesenih brojeva djeljivih sa 17 je %d.\n", i);
	return 0;
}
