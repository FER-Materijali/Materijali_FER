#include <stdio.h>
#include <string.h>

int main (){
    
    char octal[6];
    int cetvorke = 0;
    
    scanf( "%s", octal );
    
    for( int i = 0; i < strlen( octal ); ++i ){
      if( octal[i] > '7' ){ printf( "Procitani niz nije ispravno zadan.\n" ); return 0; }
      if( octal[i] == '4' ) ++cetvorke;
    }
    
    printf( "%d\n", cetvorke );    

    return 0;   
}
