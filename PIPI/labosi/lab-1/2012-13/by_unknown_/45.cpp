#include <stdio.h>
#include <string.h>

int main (){
    
    char octal[6];
    
    scanf( "%s", octal );
    
    for( int i = 0; i < strlen( octal ); ++i ){
      if( octal[i] > '7' ){ printf( "Procitani niz nije ispravno zadan.\n" ); return 0; }
    }
    
    for( char c = '0'; c < '8'; ++c ){
      for( int i = 0; i < strlen( octal ); ++i ){
        if( c == octal[i] ){
          printf( "Najmanja oktalna znamenka koja se pojavljuje u procitanom broju je %c.\n", c );
          return 0;
        }
      }
    } 
    return 0;   
}
