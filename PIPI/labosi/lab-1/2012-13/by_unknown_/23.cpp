#include <stdio.h>

int main (){
    
    int a[21];
    int n;
    
    while( 1 ){
      scanf( "%d", &n );
      if( n >= 1 && n <= 15 ) break;
    }
    
    for( int i = 0; i < n; ++i ) scanf( "%d", &a[i] );
    
    int res[16];
    int brojac = 0;
    
    for( int i = 0; i < n; ++i )
      if( a[i] >= -10 && a[i] <= 15 ){
        res[brojac] = a[i];
        ++brojac;
      }
        
    for( int i = 0; i < n; ++i ) printf( "%d ", res[i] );
    
    return 0;   
}
