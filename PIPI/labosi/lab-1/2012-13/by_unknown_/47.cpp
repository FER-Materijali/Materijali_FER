#include <stdio.h>
#include <string.h>

int main (){
    
    char hexa[6];
    
    scanf( "%s", hexa );
    
    for( int i = 0; i < strlen( hexa ); ++i ){
      if( hexa[i] > 'F' ){ printf( "Procitani niz nije ispravno zadan.\n" ); return 0; }
    }
    
    for( char cc = '0'; cc <= '9'; ++cc ){
      for( int i = 0; i < strlen( hexa ); ++i ){
        if( cc == hexa[i] ){
          printf( "Najmanja heksadekadska znamenka koja se pojavljuje u procitanom broju je %c.\n", cc );
          return 0;
        }
      }
    } 
    
    
    for( char cc = 'A'; cc <= 'F'; ++cc ){
      for( int i = 0; i < strlen( hexa ); ++i ){
        if( cc == hexa[i] ){
          printf( "Najmanja heksadekadska znamenka koja se pojavljuje u procitanom broju je %c.\n", cc );
          return 0;
        }
      }
    }
     
    return 0;   
}
