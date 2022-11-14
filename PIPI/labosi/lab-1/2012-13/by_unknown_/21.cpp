#include <stdio.h>

int main (){
    
    int a[21];
    int n;
    
    while( 1 ){
      scanf( "%d", &n );
      if( n >= 1 && n <= 20 ) break;
    }
    
    for( int i = 0; i < n; ++i ) scanf( "%d", &a[i] );
    
    int sum = 0;
    
    for( int i = 0; i < n; ++i )
      if( a[i] >= -10 && a[i] <= 10 ){
        sum += a[i];
        a[i] = 0;
      }
        
    printf( "%d\n", sum );
    
    return 0;   
}
