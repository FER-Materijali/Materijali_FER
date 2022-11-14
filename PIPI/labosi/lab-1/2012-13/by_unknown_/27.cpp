#include <stdio.h>

int main (){
    
    int a[51];
    int x;
    int res = 0;
    
    
    for( int i = 0; i <= 40; ++i ) a[i] = 0;
    
    while( 1 ){
      scanf( "%d", &x );
      if( x < 1 || x > 40 ){ printf( "Ne valjali broj\n" ); return 0; }
      a[x]++; 
      for( int i = 0; i <= 40; ++i )
        if( a[i] == 4 ){ 
          for( int j = 0; j <= 40; ++j ){
            if( a[j] > 0 ){
              printf( "broj " ); 
              if( j < 0 ) printf( " " );
              printf( "%d: %d\n", j, a[j] );
            }
          }
          return 0;
        } 
    }
    
    return 0;   
}
