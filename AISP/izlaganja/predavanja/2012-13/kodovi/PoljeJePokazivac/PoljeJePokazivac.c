#include <stdio.h>
void f(int *x) {				// ili   void f (int x[]) {
  printf ("%d %d\n", *x, x[0]);
  ++x;						   // prvi clan postaje nulti
  printf ("%d %d %d\n", *x, x[0], *(x-1));
}
int main (void) {
  int x[4] = {1,2,3,4};
  printf ("%d %d\n", *x, *(x+1));
  f(x);
  return 0;
}

