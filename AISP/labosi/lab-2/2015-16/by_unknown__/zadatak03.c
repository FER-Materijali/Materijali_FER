#include <stdio.h>
#include <string.h>
#define MAXN 10

typedef struct {
  int sifra;
  char naziv[MAXN*5 + 1];
} zapis;

void obicanBubbleSort(zapis *A, int n);
void swap(int *x, int *y);

int main(void) {
  int n, i;
  zapis polje[MAXN + 1];

  /* postavi na 0 nazive */
  for (i = 0; i < MAXN + 1; ++i) {
    memset(polje[i].naziv, 0, sizeof(polje[i].naziv));
  }

  /* unos */
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d %s", &polje[i].sifra, polje[i].naziv);
  }

  /* sortiraj podatke */
  obicanBubbleSort(polje, n);

  /* ispis podataka */
  for (i = 0; i < n; ++i) {
    printf("%d %s\n", polje[i].sifra, polje[i].naziv);
  }

  return 0;
}

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void obicanBubbleSort(zapis *A, int n) {
  int i;
  char tmp[MAXN*5 + 1];
  char swapped = 1;

  while (swapped) {
    swapped = 0;
    for (i = 1; i < n; ++i)
      if (A[i].sifra < A[i - 1].sifra) {
        /* zamjeni brojeve */
        swap(&A[i].sifra, &A[i - 1].sifra);
        /* zamjeni string-ove */
        strcpy(tmp, A[i].naziv);
        strcpy(A[i].naziv, A[i - 1].naziv);
        strcpy(A[i - 1].naziv, tmp);
        swapped = 1;
      }
  }
}