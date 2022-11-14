#include <stdio.h>

int main( void ){
	int x,t,prva,zadnja;
	do{
		scanf("%d",&x);
	}while(x<1 && x>99999);
	
	t=x;
	zadnja = t%10;
	while(t){
		prva=t%10;
		t/=10;
	}
	
	if (prva==zadnja) printf("Broj %d: prva i zadnja znamenka su jednake\n",x);
	else if (prva>zadnja) printf("Broj %d: prva znamenka veca od zadnje\n",x);
	else printf("Broj %d: zadnja znamenka veca od prve\n",x);
	return 0;
}