#include <stdio.h>
#include "funkcije.h"
#define MAX 100

int main( void ){
	char s[MAX+1], u[MAX+1];
	int hrenic;
	scanf("%s%s",s,u);

	do{
		hrenic = izbaci(s,u);
	}while(hrenic);

	printf("%s\n",s);
	return 0;


}