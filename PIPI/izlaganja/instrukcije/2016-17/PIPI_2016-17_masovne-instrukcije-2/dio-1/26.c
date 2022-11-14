#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define HEX_SIZE 5

int main(void)
  {
    int i, max;
    char hex[HEX_SIZE];
    char c;
    
    printf("Input hex string: ");
    gets(hex);
    
    max = 0;
    for (i = 0; hex[i] != '\0'; i++)
      {
        /* Checks if it is NOT a hex */
        if ( !isxdigit(hex[i]) )
          {
            puts("Invalid input.");
            exit(1);
          }
          
        /* Checks if it is greater than the latest hex[max].
           Assumes that all letters in the ASCII table are above numbers,
           and that all letters are upper case. */
        if (toupper(hex[i]) > hex[max])
            max = i;
      }
    
    printf("The largest hex digit is: %c\n", hex[max]);
    
    return 0;
  }