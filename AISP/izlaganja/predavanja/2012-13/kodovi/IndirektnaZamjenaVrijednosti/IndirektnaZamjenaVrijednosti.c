// IndirektnaZamjenaVrijednosti.c
#include <stdlib.h>
int main (void) {
	short a, b;
	short *p;
	p = &a;
	*p = 7;
	b = a;
	return 0;
}


