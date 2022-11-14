#include <stdio.h>
#include <ctype.h>
#include <string.h>

int numbr( char c ){
    
    if( c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ) return 1;
    
    return 0;
}
char number( char c ){
    
    if( c == '0' ) return 'A';
    if( c == '1' ) return 'E';
    if( c == '2' ) return 'I';
    if( c == '3' ) return 'O';
    if( c == '4' ) return 'U';
    
}

int main (){
    
    char str[31];
    
    scanf( "%s", str );
    
    char string[31];
    
    for( int i = 0; i < strlen(str); ++i ) string[i] = str[i];
    
    for( int i = 0; i < strlen(str); ++i )
      if( !isalpha(str[i]) && !isalnum(str[i]) ){
        printf( "Procitani niz nije ispravno zadan.\n" ); return 0;
      }
    
    for( int i = 0; i < strlen(str); ++i )
      if( numbr( str[i] ) )
        str[i] = number(str[i]);
    
    for( int i = 0; i < strlen(str); ++i ) printf( "%c", string[i] );    
    
    printf( "\n%s", str );
    return 0;   
}
