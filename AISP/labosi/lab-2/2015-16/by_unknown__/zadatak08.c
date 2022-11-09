#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXN 50

void BubbleSortPoboljsani(char **niz, int n);

int main(void) {
  int n, i;
  char **niz;

  /* unos */
  scanf("%d", &n);

  /* alociranje prostora */
  niz = (char **)malloc(n * sizeof(*niz));
  for (i = 0; i < n; ++i) {
    niz[i] = (char *)malloc((MAXN+1) * sizeof(*niz[i]));
  }

  /* postavljanje na 0 */
  for (i = 0; i < n; ++i) {
    memset(niz[i], 0, sizeof(*niz[i]));
  }

  /* unos */
  for (i = 0; i < n; ++i)
    scanf("%s", niz[i]);

  /* sortiraj */
  BubbleSortPoboljsani(niz, n);

  /* ispis */
  for (i = 0; i < n; ++i)
    printf("%s\n", niz[i]);

  /* oslobadanje memorije */
  for (i = 0; i < n; ++i) {
    free(niz[i]);
  }
  free(niz);

  return 0;
}

void BubbleSortPoboljsani(char **niz, int n) {
  int i, newn;
  char tmp[MAXN+1];

  while (n != 0) {
    newn = 0;
    for (i = 1; i < n; ++i) {
      if (strcmp(niz[i - 1], niz[i]) > 0) {
        strcpy(tmp, niz[i - 1]);
        strcpy(niz[i - 1], niz[i]);
        strcpy(niz[i], tmp);
        newn = i;
      }
    }
    n = newn;
  }
}
