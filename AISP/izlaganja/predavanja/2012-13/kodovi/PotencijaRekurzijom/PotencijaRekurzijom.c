#include <stdio.h>
int pot(int x, int y) {
  int ret;

  if (y <= 0) ret = 1;
  else ret = x * pot(x, y - 1);

  return ret;
}
int main () {
  int x, y, rez;
  while (1) {
    printf ("Upisite cijeli broj za bazu i nenegativni cijeli broj za eksponent>");
    scanf ("%d %d", &x, &y);
    if (y < 0) break;
	  rez = pot (x, y);
	  printf ("%d na potenciju %d = %d\n", x, y, rez);
  }
  printf ("\nNegativni eksponent\n");
  return 0;
}
