#include <stdio.h>

#define MIN 100
#define MAX 999

int main(void)
  {
    int i;
    int a, b;
    
    /* Prompts user for int while not within range */
    do
      {
        printf("Input int [%d, %d]: ", MIN, MAX);
        scanf("%d", &a);
      } while (!(a >= MIN && a <= MAX));
    
    /* Gives the reverse value of a to b */
    i = a; b = 0;
    while (i != 0)
      {
        b *= 10;
        b += i % 10;
        i /= 10;
      }
    
    /* Prints the inputed and reverse number */
    printf("Inputed number:  %d\n"
           "Reversed number: %d\n", a, b);

    /* Prints resulting inequality */
    if (b < a)
        printf("Number %d is smaller than the inputed number.\n", b);
    else if (b > a)
        printf("Number %d is greater than the inputed number.\n", b);
    else
        printf("Number %d is equal to the inputed number.\n", b);

    return 0;
    
  }
