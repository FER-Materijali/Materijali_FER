#include <stdio.h>
#include <math.h>

int main (){
    
    int a;
    int znamenke[10] = {0};
    while( 1 ){
      scanf( "%d", &a );
      if( a >= 100 && a <= 999 ) break;
    }
    
    int n = a;
    int okrenuti = 0;
    int br = 100;
    
    
     while( a > 0 ){
      okrenuti += (a%10) * br;
      a /= 10;
      br /= 10;
    }
    
    if( n > okrenuti ) printf( "Broj %d je manji od ucitanog broja.\n", okrenuti );
    else if( n < okrenuti ) printf( "Broj %d je veci od ucitanog broja.\n", okrenuti );
    else printf( "Broj %d je isti kao ucitani broj.\n", okrenuti );
    
    return 0;   
}
