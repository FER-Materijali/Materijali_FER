#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){
    
    char string[31];
    
    scanf( "%s", string );
    
    int flagchars = 0;
    int flagnumbers = 0;
    
    for( int i = 0; i < strlen(string); ++i ){
      if( string[i] >= 'a' && string[i] <= 'z' ) ++flagchars;
      if( string[i] >= '0' && string[i] <= '9' ) ++flagnumbers;
    }
    
      
      
    if( flagchars >= 7 && flagnumbers >= 2 ) printf( "Zadovoljava uvjete\n" );
    else printf( "Ne zadovoljava uvjete\n" );
    
    return 0;   
}
