#include <stdlib.h>
#include <stdio.h>

#define MAX 100
#define MIN 0

#define TRUE 1
#define FALSE 0

int main(void)
  {
    int n;
    int count, max, max2;
    
    count = 0; max = MIN; max2 = MIN;
    while (TRUE)
      {
        printf("Input int [%d, %d]: ", MIN, MAX);
        scanf("%d", &n);
        
        /* Checks if input is NOT correct*/
        if (!((n >= MIN && n <= MAX)))
            break;
        
        /* Increments count */
        count++;
        
        /* Checks if new max or new max2 */
        if (n > max)
          {
            max2 = max;
            max = n;
          }
        else if (n > max2) max2 = n;            	
      }
    
    /* Checks the loop was broken at too early */
    if (count < 2)
      {
        puts("First two int are not within requested interval.");
        exit(1);
      }
    
    /* Prints the result */
    printf("Remainder when dividing %d with %d is: %d\n",
           max, max2, max%max2);

    return 0;
    
  }
