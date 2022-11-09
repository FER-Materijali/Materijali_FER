#include <stdio.h>
void hanoi(char Izvor, char Odrediste, char Pomocni, int n) {
   if (n > 0) {
      hanoi (Izvor, Pomocni, Odrediste, n - 1);
      printf("\nPrebacujem element %d s tornja %c na toranj %c", 
		                                            n, Izvor, Odrediste);
      hanoi (Pomocni, Odrediste, Izvor, n - 1);
   }
}
int main() {
  int n;
  while (1) {
		printf ("\n\nUpisite broj diskova>");
		scanf ("%d", &n);
		if (n <= 0) break;
		printf("\nHanojski tornjevi (%d elementa)", n);
		hanoi('I', 'O', 'P', n);
	}
  return 0;
}