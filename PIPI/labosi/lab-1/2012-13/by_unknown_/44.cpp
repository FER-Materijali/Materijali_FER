#include <stdio.h>
#include <string.h>

int main (){
    
    char octal[6];
    
    scanf( "%s", octal );
    
    for( int i = 0; i < strlen( octal ); ++i ){
      if( octal[i] > '7' ){ printf( "Procitani niz nije ispravno zadan.\n" ); return 0; }
    }
    
    printf( "Prva znamenka procitanog broja je %c.\nPosljednja znamenka procitanog broja je %c.\n",octal[0], octal[ strlen( octal ) - 1 ]  );    

    return 0;   
}
