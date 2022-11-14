#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){
    
    char string[21];
    
    scanf( "%s", string );
    
    if( strlen( string ) < 8 ){ printf( "Prekratak\n" ); return 0; }
    
    int flag = 0;
    
    for( int i = 0; i < strlen(string); ++i )
      if( isalpha( string[i] ) ) flag = 1;
      
      
    if( flag ) printf( "Zadovoljava uvjete\n" );
    else printf( "Ne sadrzi slovo\n" );
    
    return 0;   
}
