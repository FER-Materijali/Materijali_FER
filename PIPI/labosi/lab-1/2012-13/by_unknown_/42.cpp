#include <stdio.h>
#include <string.h>

int main (){
    
    char binary[11];
    int jedinice = 0;
    
    scanf( "%s", binary );
    
    for( int i = 0; i < strlen( binary ); ++i ){
      if( binary[i] > '1' ){ printf( "Procitani niz nije ispravno zadan.\n" ); return 0; }
    }
    
    if( binary[ strlen(binary)-1 ] == '0' ) printf( "Posljednja znamenka procitanog broja je 0.\n" );
    else printf( "Posljednja znamenka procitanog broja nije 0.\n" );
      

    return 0;   
}
