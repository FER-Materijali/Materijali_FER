#include <stdio.h>
#include <ctype.h>
#include <string.h>

int samogl( char c ){
    
    if( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ) return 1;
    
    return 0;
}
char samoglasnik( char c ){
    
    if( c == 'A' ) return '0';
    if( c == 'E' ) return '1';
    if( c == 'I' ) return '2';
    if( c == 'O' ) return '3';
    if( c == 'U' ) return '4';
    
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
