#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXN 50

void ShellSort(char **niz, int n);

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

  /* unos nizova */
  for (i = 0; i < n; ++i) {
    scanf("%s", niz[i]);
  }

  /* sortiranje */
  ShellSort(niz, n);

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

void ShellSort(char **niz, int n) {
  int i, gap = n / 2;
  char tmp[MAXN + 1];

  while (gap) {
    for (i = n - 1; i - gap > -1; i -= gap) {
      if (strcmp(niz[i - gap], niz[i]) > 0) {
        strcpy(tmp, niz[i]);
        strcpy(niz[i], niz[i - gap]);
        strcpy(niz[i - gap], tmp);
      }
    }
    gap /= 2;
  }
}
