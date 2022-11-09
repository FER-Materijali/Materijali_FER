#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXN 50

void InsertionSort(char **niz, int n);

int main() {
  int n, i;
  char **niz;

  /* unos */
  scanf("%d", &n);

  /* alociraj prostor za nizove */
  niz = (char **)malloc(n * sizeof(*niz));
  for (i = 0; i < n; ++i) {
    niz[i] = (char *)malloc((MAXN+1) * sizeof(*niz[i]));
  }

  /* postavi na 0 */
  for (i = 0; i < n; ++i) {
    memset(niz[i], 0, sizeof(*niz[i]));
  }

  /* unesi stringove */
  for (i = 0; i < n; ++i) {
    scanf("%s", niz[i]);
  }

  /* sortiraj */
  InsertionSort(niz, n);

  /* ispis */
  for (i = 0; i < n; ++i) {
    printf("%s\n", niz[i]);
  }

  /* oslobodi memoriju */
  /*free(niz);*/
  for (i = 0; i < n; ++i) {
    free(niz[i]);
  }
  free(niz);

  return 0;
}

void InsertionSort(char **niz, int n) {
  int i, j;
  char tmp[MAXN + 1];

  for (i = 1; i < n; ++i) {
    j = i - 1;
    while (j > -1 && strcmp(niz[j], niz[j + 1]) > 0) {
      /* zamjeni stringove */
      strcpy(tmp, niz[j]);
      strcpy(niz[j], niz[j + 1]);
      strcpy(niz[j + 1], tmp);
      --j;
    }
  }
}