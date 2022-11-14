#include <stdio.h>


int main (){
    
    int n;
    int broj = 1;
    int brojac = 1;
    int a[40];
    
    
    for( int i = 0; i <= 40; ++i ) a[i] = 0;
    
    
    
    while( 1 ){
      scanf( "%d", &n );
      if( n < 1 || n > 40 ) break; 
      
      ++broj;
      
      if( !a[broj] ){
       a[n] = broj;
      }
    }
    
    for( int i = 0; i <= 40; ++i )
      if( a[i] ) printf( "Broj %d: %d\n", i, a[i]-1);       
    
      
    
    
    return 0;   
}
