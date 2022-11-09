
#include <stdio.h>
int main () {
	int a = 4;
	int *b; 
 
	b = &a; 
	*b = 8;
	printf ("%d %d\n", a, *b);
 
	return 0;
}
