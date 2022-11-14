#include <stdio.h>

int main (){
    
    int n;
    float a[1001];
    
    while( 1 ){
      scanf( "%d", &n );
      if( n >= 1 && n <= 20 ) break;
    }
    
    
    
    for( int i = 0; i < n; ++i ) scanf( "%f", &a[i] );
    
    for( int i = n; i >= 0; --i )
      if( a[i] >= 6.5 && a[i] <= 10.5 ){
       if( i < 10 ) printf ( " " );
       printf( "%d: %.3f\n", i, a[i] );
      }
      
    
    return 0;   
}
