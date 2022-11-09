#include <stdio.h>
#define MAXN 10

void selection2Sort(int *polje, int n);
void swap(int *x, int *y);

int main(void) {
  int n, i;
  int polje[MAXN+1];

  /* unos */
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &polje[i]);
  }

  /* sortiraj */
  selection2Sort(polje, n);

  /* ispis */
  for (i = 0; i < n; ++i) {
    printf("%d ", polje[i]);
  }
  printf("\n");

  return 0;
}

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void selection2Sort(int *polje, int n) {
  int i, j, min;

  for (i = 0; i < n - 1; ++i) {
    min = i;
    for (j = i + 1; j < n; ++j) {
      if (polje[min] > polje[j]) {
        min = j;
      }
    }
    swap(polje + i, polje + min);
  }
}