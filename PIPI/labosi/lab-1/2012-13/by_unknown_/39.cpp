#include <stdio.h>

int main (){
    
    unsigned int a;
    int znamenke[10] = {0};
    
    scanf( "%d", &a );
    
    int n = a;
    while( a > 0 ){
      znamenke[a%10]++;
      a /= 10;
    }
    int res = 0;
    for( int i = 1; i < 9; ++i )
      if( znamenke[i] == 1 ){
        if( n % i != 0 ){
         printf( "Broj %d nije djeljiv sa svojom najmanjom znamenkom %d", n, i );
         return 0;
        }
        else {
         printf( "Broj %d je djeljiv sa svojom najmanjom znamenkom %d", n, i );
         return 0;
        } 
      }    
    
    
    return 0;   
}
