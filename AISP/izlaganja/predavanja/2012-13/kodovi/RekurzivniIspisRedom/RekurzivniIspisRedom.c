#include <stdio.h>
// Rješenja s dva ulazna argumenta:

// Ispisuje uzlazno (od n1 do n2)
void ispis_u2a (int n1, int n2) {
   if (n1 <= n2) {
      printf("\n%d", n1);
      ispis_u2a (n1 + 1, n2);
   }
}
// Ispisuje uzlazno (od n1 do n2)
void ispis_u2b (int n1, int n2) {
   if (n1 <= n2) {
      ispis_u2b (n1, n2 - 1);
      printf("\n%d", n2);
   }
}
// Ispisuje silazno (od n2 do n1)
void ispis_s2a (int n1, int n2) {
   if (n1 <= n2) {
      printf("\n%d", n2);
      ispis_s2a (n1, n2 - 1);
    }
}
// Ispisuje silazno (od n2 do n1)
void ispis_s2b( int n1, int n2) {
   if (n1 <= n2) {
      ispis_s2b (n1 + 1, n2);
      printf("\n%d", n1);
   }
}
// Rješenja s jednim ulaznim argumentom:

// Ispisuje uzlazno (od 1 do n2)
void ispis_u1 (int n) {
   if (n >= 1) {
      ispis_u1 (n - 1);
      printf("\n%d", n);
   }
}
// Ispisuje silazno (od n2 do 1)
void ispis_s1 (int n) {
   if (n >= 1) {
      printf("\n%d", n);
      ispis_s1 (n - 1);
   }
}

int main () {
  int n;
  printf ("Upisite najveci cijeli broj za ispis >");
  scanf ("%d", &n);
  ispis_u2a (1, n);
  getchar (); getchar (); // drugi char da bi progutao ENTER od gornjeg scanf-a
  ispis_u2b(1, n);
  getchar ();
  ispis_s2a (1, n);
  getchar ();
  ispis_s2b(1, n);
  getchar ();
  ispis_u1 (n);
  getchar ();
  ispis_s1 (n);
  return 0;
}
