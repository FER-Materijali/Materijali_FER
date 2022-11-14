#include <stdio.h>

int main( void ){
	int n1,n2=0,pom,pot=100;
	scanf("%d",&n1);
	pom=n1;
	while(pom){
		n2 += (pom%10)*pot;
		pot /= 10;
		pom /= 10;
	}
	printf("Broj %d je %s od ucitanog broja.\n",n2,( n2>n1 ? "veci" : "manji" ));
	return 0;
}