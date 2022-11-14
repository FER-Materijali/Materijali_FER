#include <stdio.h>

int main (){
    
    int a;
    int znamenke[10] = {0};
    while( 1 ){
      scanf( "%d", &a );
      if( a >= 100 && a <= 99999 ) break;
    }
    
    while( a > 0 ){
      znamenke[a%10]++;
      a /= 10;
    }
    
    for( int i = 0; i < 10; ++i )
      if( znamenke[i] )
        printf( "Znamenka %d: %d\n", i, znamenke[i] );
        
    
    
    
    
    return 0;   
}
