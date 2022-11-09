#include <stdio.h>
#include <malloc.h>

void spojiPolja(int *a, int *b, int *rez, int n1, int n2);

int main(void) {
  /* definiranje varijabli */
  int n1 = 5, n2 = 5, i;
  int a[] = {1, 3, 5, 7, 9};
  int b[] = {0, 2, 4, 6, 8};
  int *rez = (int *)malloc(sizeof(int) * (n1 + n2));

  /* spoji polja */
  spojiPolja(a, b, rez, n1, n2);

  /* ispis */
  for (i = 0; i < n1 + n2; ++i) {
    printf("%d ", rez[i]);
  }
  printf("\n");

  free(rez);

  return 0;
}

void spojiPolja(int *a, int *b, int *rez, int n1, int n2) {
  int i, j, k;

  for (i = 0, j = 0, k = 0; i < n1 || j < n2;) {
    if (i >= n1) {
      rez[k++] = b[j++];
    } else if (j >= n2) {
      rez[k++] = a[i++];
    } else {
      rez[k++] = a[i] > b[j] ? b[j++] : a[i++];
    }
  }
}