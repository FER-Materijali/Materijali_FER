#include <stdio.h>
#include "funkcije.h"
#define MAX 9

int main( void ){
	int sol;
	char s1[MAX+1], s2[MAX+1], op;
	scanf("%s%s",s1,s2);
	scanf(" %c",&op);

	if ( matemOp( nizUInt(s1), nizUInt(s2), op, &sol ) ) printf("%d",sol);
	return 0;
}