#include <stdio.h>
#include <ctype.h>
#include <string.h>

int samogl( char c ){
    
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return 1;
    
    return 0;
}
char samoglasnik( char c ){
    
    if( c == 'a' ) return '9';
    if( c == 'e' ) return '8';
    if( c == 'i' ) return '7';
    if( c == 'o' ) return '6';
    if( c == 'o' ) return '5';
    
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
      if( samogl( str[i] ) )
        str[i] = samoglasnik(str[i]);
    
    for( int i = 0; i < strlen(str); ++i ) printf( "%c", string[i] );    
    
    printf( "\n%s", str );
    return 0;   
}
