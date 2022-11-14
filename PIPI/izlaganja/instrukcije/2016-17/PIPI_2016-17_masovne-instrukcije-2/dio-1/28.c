#include <stdlib.h>
#include <stdio.h>

#define MIN 0
#define MAX 100
#define SUM_MAX 50

#define TRUE 1
#define FALSE 0

int main(void)
  {
    int n;
    int sum, first;
    
    first = TRUE; sum = 0;
    while (TRUE)
      {
        printf("Input int [%d, %d]: ", MIN, MAX);
        scanf("%d", &n);
        
        /* Checks if input is NOT correct*/
        if (!((n >= MIN && n <= MAX)))
            break;
        
        /* Marks the first as false */
        first = FALSE;
        
        /* Sums if meets criteria */
        if (n < SUM_MAX)
            sum += n;
      }
    
    /* Checks the loop was broken at the first */
    if (first)
      {
        puts("No int is within requested interval.");
        exit(1);
      }
    
    /* Prints the result */
    printf("Sum of the numbers smaller than %d is: %d\n", SUM_MAX, sum);

    return 0;
    
  }
