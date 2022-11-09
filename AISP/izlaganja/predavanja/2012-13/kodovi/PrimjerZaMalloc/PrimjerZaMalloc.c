// PrimjerZaMalloc.c
#include <stdlib.h>
#include <malloc.h>
int main (void) {

  short *i;
  i = (short *) malloc (sizeof (short));
  *i = 7;

  free((void*) i);

  //*i = 7;

  //i = NULL;

  return 0;
}	