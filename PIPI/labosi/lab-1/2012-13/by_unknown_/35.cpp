#include <stdio.h>

int main (){
    
    int a;
    int znamenke[10] = {0};
    while( 1 ){
      scanf( "%d", &a );
      if( a >= 1 && a <= 99999 ) break;
    }
    int n = a;
    while( a > 9 ){
      znamenke[a%10]++;
      a /= 10;
    }
    if( a > n % 10 ) printf( "Broj %d: prva znamenka je veca od zadnje.\n", n );
    else if( a < n % 10 ) printf( "Broj %d: prva znamenka je manja od zadnje.\n", n );
    else printf( "Broj %d: prva znamenka je jednaka zadnjoj.\n", n );   
    
    return 0;   
}
