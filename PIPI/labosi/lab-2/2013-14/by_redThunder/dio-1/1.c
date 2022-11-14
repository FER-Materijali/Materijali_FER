#include <stdio.h>

int main( void ){
	int x;
	int i,j;
	scanf("%d",&x);
	if (x<5 || x>20){
		printf("Neispravan broj\n");
		return 0;
	}
	for( i=0; i<=x; i++ ){
		for( j=0; j<=10*i; j+=10 ){
			printf("%2.1lf ",j/100.);
		}
		for( j=0; j<( (x-i)*4+2 ); j++ ){
			printf(" ");
		}
		printf("%2.1lf.red\n",i/10.);
	}
	return 0;
}	