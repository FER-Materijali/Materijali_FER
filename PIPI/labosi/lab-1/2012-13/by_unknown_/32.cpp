#include <stdio.h>
#include <string.h>

int main (){
    
    char string1[21], string2[21];
    
    scanf( "%s", string1 );
    scanf( "%s", string2 );
    for( int i = 0; i < strlen(string1); i += 2 )
      string1[i] = string2[i]; 
      
    printf( "Promijenjeni niz: %s\n", string1 );
    if( strlen(string1) % 2 )
     printf( "Promijenjeno znakova%d\n", strlen(string1) / 2+1 );
    else  
    printf( "Prominjeno znakova %d\n", strlen(string1) / 2 );
    
    return 0;
}
      
