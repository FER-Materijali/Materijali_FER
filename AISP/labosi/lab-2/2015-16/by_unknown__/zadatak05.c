#include <stdio.h>
#include <string.h>
#include <malloc.h>

void spojiNizove(char *a, char *b, char *rez);

int main(void) {
  char a[] = "BDace";
  char b[] = "ACEbd";

  int len_a = strlen(a);
  int len_b = strlen(b);

  char *rez = (char *)malloc(sizeof(char) * (len_a + len_b + 1));

  spojiNizove(a, b, rez);

  printf("%s\n", rez);

  free(rez);

  return 0;
}

void spojiNizove(char *a, char *b, char *rez) {
  int i, j, k;
  int len_a = strlen(a);
  int len_b = strlen(b);

  for (i = 0, j = 0, k = 0; i < len_a || j < len_b;) {
    if (i >= len_a) {
      rez[k++] = b[j++];
    } else if (j >= len_b) {
      rez[k++] = a[i++];
    } else  {
      rez[k++] = a[i] > b[j] ? b[j++] : a[i++];
    }
  }
  rez[k] = '\0';
}