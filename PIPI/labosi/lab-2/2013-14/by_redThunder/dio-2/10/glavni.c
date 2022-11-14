#include <stdio.h>
#include "funkcije.h"
#define MAX 100

int main( void ){
	char s1[MAX+1], s2[MAX+1];
	scanf("%s",s1);
	kodiraj(s1,s2);
	printf("%s -> %s\n",s1,s2);
	return 0;
}