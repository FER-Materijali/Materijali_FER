// ideja kao u prethodnom samo što ovdje brojimo koliko smo brojeva uèitali

#include <stdio.h>

int main (){
    
    int a[51];
    int x;
    int res = 0;
    
    
    for( int i = 0; i <= 50; ++i ) a[i] = 0;
    
    while( 1 ){
      scanf( "%d", &x );
      if( x < 1 || x > 50 ){ printf( "Ne valjali broj\n" ); return 0; }
      a[x]++; 
      ++res;
      for( int i = 0; i <= 50; ++i )
        if( a[i] == 6 ){ printf( "%d\n", res ); return 0; }
    }
    
    return 0;   
}
