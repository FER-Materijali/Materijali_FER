#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (){
    
    char string[21];
    
    scanf( "%s", string );
    
    if( strlen( string ) < 10 ){ printf( "Prekratak niz\n" ); return 0; }
    
    for( int i = strlen(string); i >= 0 ; --i )
      if( isupper( string[i] ) )   
       printf( "%c\n", string[i] );
    
    
    return 0;   
}
