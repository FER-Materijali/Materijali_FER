#include <stdio.h>

int main (){
    
    int x; scanf( "%d", &x );
    
    if( x < 5 || x > 20 ){ printf( "Neispravan broj\n" ); return 0; }
    
    for( int i = 0; i <= x; ++i ){
      if( i < 10 ) printf( " " );
      printf( "%d. red ", i );
      for( int j = 0; j <= x; ++j ){
        if( j == i ) printf( " %d ", j );
        else printf( " - " );
      }
      printf( "\n" );
    }
    
    return 0;   
}
