#include <stdio.h>
#include <string.h>

int main (){
    
    char binary[11];
    int jedinice = 0;
    
    scanf( "%s", binary );
    
    for( int i = 0; i < strlen( binary ); ++i ){
      if( binary[i] > '1' ){ printf( "Procitani niz nije ispravno zadan.\n" ); return 0; }
      if( binary[i] == '1' ) ++jedinice;
    }
    
    printf( "%d\n", jedinice );    

    return 0;   
}
