#include <stdio.h>


int main (){
    
    int n;
    int broj = 0;
    int brojac = 1;
    int a[40];
    
    
    for( int i = 0; i <= 40; ++i ) a[i] = 0;
    
    
    
    while( 1 ){
      while( 1 ){
         scanf( "%d", &n );
         if( n >= 1 && n <= 40 ) break;
      }
      
      ++broj;
      
      for( int i = 1; i <= broj; ++i ){
        if( a[i] == n ){ 
          printf( "Broj %d bio je %d. procitani broj.\n", n, i ); 
          printf( "Ukupno procitano brojeva: %d", broj );
          return 0;
        }
      }
      a[brojac] = n;
      ++brojac;
    } 
      
    
    
    return 0;   
}
