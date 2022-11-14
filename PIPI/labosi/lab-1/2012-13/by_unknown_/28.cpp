#include <stdio.h>

int main (){
    
    int a[51];
    int x;
    int res = 0;
    
    
    for( int i = 0; i <= 30; ++i ) a[i] = 0;
    
    while( 1 ){
      scanf( "%d", &x );
      if( x < 1 || x > 30 ){ break; }
      a[x]++; 
    }
    
    for( int i = 0; i <= 30; ++i )
      if( a[i] >= 2 ) printf( "broj %d: %d\n", i, a[i] );
    
    
    return 0;   
}
