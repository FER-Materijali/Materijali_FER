#include <stdio.h>

int main (){
    
    int x; scanf( "%d", &x );
    
    if( x < 5 || x > 20 ){ printf( "Neispravan broj\n" ); return 0; }
    
    for( int i = 0; i <= x; ++i ){
      if( i < 10 ) printf( " " );
      printf( "%d. red: ", i );
      double s = 0.0;   
      for( int j = 0 ; j <= i; ++j, s += 0.1 ){
         printf( "%.1lf ", s );
      }
      printf( "\n" );
    }
    
    return 0;   
}
