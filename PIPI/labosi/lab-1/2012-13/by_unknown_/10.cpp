#include <stdio.h>

int main (){
    
    int n;
    int a[1001];
    
    while( 1 ){
      scanf( "%d", &n );
      if( n >= 1 && n <= 20 ) break;
    }
    
    
    
    for( int i = 0; i < n; ++i ) scanf( "%d", &a[i] );
    
    for( int i = n; i >= 0; --i )
      if( a[i] >= 10 && a[i] <= 20 ){
       if( i < 10 ) printf ( " " );
       printf( "%d: %d\n", i, a[i] );
      }
      
    
    return 0;   
}
