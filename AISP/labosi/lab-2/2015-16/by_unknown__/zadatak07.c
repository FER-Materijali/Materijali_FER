#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXN 50

void SelectionSort(char **niz, int n);

int main(void) {
  int n, i;
  char **niz;

  /* unesi broj nizova */
  scanf("%d", &n);

  /* alociraj prostor za nizove */
  niz = (char **)malloc(n * sizeof(*niz));
  for (i = 0; i < n; ++i) {
    niz[i] = (char *)malloc((MAXN+1) * sizeof(*niz[i]));
  }

  /* postavi nizove na 0 */
  for (i = 0; i < n; ++i) {
    memset(niz[i], 0, sizeof(*niz[i]));
  }

  /* unesi nizove */
  for (i = 0; i < n; ++i)
    scanf("%s", niz[i]);

  /* sortiraj */
  SelectionSort(niz, n);

  /* ispisi */
  for (i = 0; i < n; ++i)
    printf("%s\n", niz[i]);

  /* oslobodi memoriju */
  for (i = 0; i < n; ++i) {
    free(niz[i]);
  }
  free(niz[i]);

  return 0;
}

void SelectionSort(char **niz, int n) {
  int i, j, min;
  char tmp[MAXN+1];

  for (i = 0; i < n - 1; ++i) {
    min = i;
    for (j = i + 1; j < n; ++j) {
      if (strcmp(niz[min], niz[j]) > 0) {
        min = j;
      }
    }
    /* zamjeni */
    strcpy(tmp, niz[i]);
    strcpy(niz[i], niz[min]);
    strcpy(niz[min], tmp);
  }
}
