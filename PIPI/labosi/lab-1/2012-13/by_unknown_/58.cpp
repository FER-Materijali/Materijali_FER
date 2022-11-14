#include <stdio.h>
#include <ctype.h>
#include <string.h>

int numbr( char c ){
    
    if( c == '5' || c == '6' || c == '7' || c == '8' || c == '9' ) return 1;
    
    return 0;
}
char number( char c ){
    
    if( c == '5' ) return 'a';
    if( c == '6' ) return 'e';
    if( c == '7' ) return 'i';
    if( c == '8' ) return 'o';
    if( c == '9' ) return 'u';
    
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
