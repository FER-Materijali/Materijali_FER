#include <stdio.h>

int main (){
    
    int a[100001];
    
    int brojac = 0;
    int min = 1000;
    int max = 0;
    
    scanf( "%d", &a[brojac] );
    if( a[brojac] < 0 || a[brojac] > 100 ){ printf( "Nije unesen niti jedan broj iz trazenog intervala.\n" ); return 0; } 
    ++brojac;
    
    while( 1 ){
      scanf( "%d", &a[brojac] );
      if( a[brojac] < 0 || a[brojac] > 100 ) break;
      
      if( a[brojac] % 4 == 0 ){
        if( min > a[brojac] ) min = a[brojac];
      } 
      if( a[brojac] % 4 == 0 ){
        if( max < a[brojac] ) max = a[brojac];
      }
      ++brojac;
    }
    
    printf( "Zbroj najveceg i najmanjeg unesenog broja djeljivog s 4 je %d.\n", min + max );
    
    return 0;
}
