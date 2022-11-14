#include <stdio.h>
#include <string.h>
int main (){
    
    char string[21];
    
    scanf( "%s", string );
    
    if( strlen( string ) < 10 ){ printf( "Prekratak niz\n" ); return 0; }
    
    for( int i = 0; i < strlen(string); i += 2 ) printf( "%c\n", string[i] );
    
    
    return 0;   
}
