#include <stdio.h>
#include <string.h>

int main (){
    
    char binary[11];
    int jedinice = 0;
    int flag = 0;
    
    scanf( "%s", binary );
    
    for( int i = 1; i < strlen( binary ); ++i ){
      if( binary[i] > '1' ){ printf( "Procitani niz nije ispravno zadan.\n" ); return 0; }
      if( binary[i] == '0' && binary[i-1] == '0' ) flag = 1;
    }
    
    if( flag ) printf(  "Procitani binarni broj sadrzi dvije ili vise uzastopnih znamenki 0.\n" );
    else printf( "Procitani binarni broj ne sadrzi dvije ili vise uzastopnih znamenki 0.\n" );

    return 0;   
}
