#include <stdio.h>
#include "funkcije.h"
#define MAX 1500

int main( void ){
	char s[MAX+1];
	int x;
	gets(s);
	x = trazi(s);

	switch( x ){
		case 1:
			printf("Hrvatski\n");
			break;
		case 2:
			printf("Engleski\n");
			break;
		case 3:
			printf("Njemacki\n");
			break;
		default:
			printf("Nepoznat\n");
			break;
	}
	return 0;
}