// This is the main project file for VC++ application project 
// generated using an Application Wizard.

#include <stdio.h>
#include <sys\timeb.h>

int main()
{
  int i, j, n;

  struct timeb vrijeme1, vrijeme2; long trajanjems;

  while (scanf("%d", &n)==1 && n > 0) {
    ftime (&vrijeme1);

    for (i = 1; i < n; ++i) {
      if (i % 100 == 0) printf (".");

      for (j = 0; j < i; ++j)
        ;

    }

    ftime (&vrijeme2);
    trajanjems = 1000 * (vrijeme2.time - vrijeme1.time) +
                  vrijeme2.millitm - vrijeme1.millitm;
    printf("\n%ld ms\n", trajanjems);
  }

	return 0;
}