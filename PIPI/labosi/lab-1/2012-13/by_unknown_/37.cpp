#include <stdio.h>

int main (){
    
    int a;
    int znamenke[10] = {0};
    while( 1 ){
      scanf( "%d", &a );
      if( a >= 1 && a <= 99999 ) break;
    }
    int n = a;
    while( a > 0 ){
      znamenke[a%10]++;
      a /= 10;
    }
    int res = 0;
    for( int i = 9; i >= 0; --i )
      if( znamenke[i] == 1 )
        res += i;    
    
    printf( "%d\n", res );
    
    return 0;   
}
