#include <stdio.h>

int main (){
    
    int a[31];
    int n;
    
    while( 1 ){
      scanf( "%d", &n );
      if( n >= 1 && n <= 30 ) break;
    }
    
    for( int i = 0; i < n; ++i ) scanf( "%d", &a[i] );
    
    for( int i = 0; i < n; ++i )
      if( a[i] >= -1 && a[i] <= 22 )
        a[i] = 0;
        
    for( int i = 0; i < n; ++i ) printf( "%d ", a[i] );
    
    return 0;   
}
