#include <stdio.h>

int main (){
    
    int a[21];
    int n;
    
    while( 1 ){
      scanf( "%d", &n );
      if( n >= 1 && n <= 10 ) break;
    }
    
    for( int i = 0; i < n; ++i ) scanf( "%d", &a[i] );
    
    int res = 0;
    
    for( int i = 0; i < n; ++i )
      if( a[i] >= -20 && a[i] <= 40 ){
        ++res;
        a[i] = -100;
      }
        
    printf( "%d\n", res );
    
    return 0;   
}
