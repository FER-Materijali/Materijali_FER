#include <stdio.h>
#include <string.h>
#define MAXN 10

typedef struct {
  int postanski_broj;
  char naziv_mjesta[MAXN*4 + 1];
} zapis;

void insertionSort(zapis *A, int n);
void swap(int *x, int *y);

int main(void) {

  int n, i;
  zapis polje[MAXN+1];

  /* postavi 0 na naziv_mjesta */
  for (i = 0; i < MAXN + 1; ++i) {
    memset(polje[i].naziv_mjesta, 0, sizeof(polje[i].naziv_mjesta));
  }

  /* unos podataka */
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d %s", &polje[i].postanski_broj, polje[i].naziv_mjesta);
  }

  /* sortiraj podatke */
  insertionSort(polje, n);

  /* ispis */
  for (i = 0; i < n; ++i) {
    printf("%d %s\n", polje[i].postanski_broj, polje[i].naziv_mjesta);
  }

  return 0;
}

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void insertionSort(zapis *A, int n) {
  int i, j;
  char tmp[MAXN*4 + 1];

  for (i = 1; i < n; ++i) {
    j = i - 1;
    while (j > -1 && (A[j].postanski_broj > A[j + 1].postanski_broj)) {
      /* zamjeni postanski broj */
      swap(&A[j].postanski_broj, &A[j + 1].postanski_broj);
      /* zamjeni znakove*/
      strcpy(tmp, A[j].naziv_mjesta);
      strcpy(A[j].naziv_mjesta, A[j + 1].naziv_mjesta);
      strcpy(A[j + 1].naziv_mjesta, tmp);
      --j;
    }
  }
}