
#include <stdio.h>

int main (){
    
    int a[61];
    int x;
    
    for( int i = 0; i <= 60; ++i ) a[i] = 0;
    
    while( 1 ){
      scanf( "%d", &x );
      if( x < -30 || x > 30 ){ printf( "Ne valjali broj\n" ); return 0; }
      if( x < 0 ) a[-1*x+30]++;
      else a[x]++; 
      for( int i = 0; i <= 60; ++i ){
        if( a[i] == 3 && i > 30 ){ printf( "Broj koji se procitao 3 puta: %d", -1*(i%30) ); return 0; }
        if( a[i] == 3 ){ printf( "Broj koji se procitao 3 puta: %d", i ); return 0; }
      }
    }
    
    return 0;   
}
