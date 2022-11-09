// AritmetikaPokazivaca.c
#include <stdlib.h>

int main (void) {
  char *c; short *s; int *i; float *f; double *d;
  void *v;
	long dugi; double dupli;		
	long *pdugi; double *pdupli;
	short veldugi, veldupli;
  c = 0; s = 0; i = 0; f = 0; d = 0; v= 0;
  // Inkrement za 1
  c++;
  s++;
  i++;
  f++;
  d++;
  // v++; Javlja pogresku jer se ne zna velièina
 
  
	veldugi = sizeof (dugi);
	pdugi = &dugi;				
	++pdugi;

	veldupli = sizeof (dupli);
	pdupli = &dupli;					
	pdupli = pdupli + 2;

	return 0;
}
