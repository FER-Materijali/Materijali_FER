#include <stdio.h>

int main (){
    
    int a[100001];
    
    int brojac = 0;
    int sum = 0;
    
    scanf( "%d", &a[brojac] );
    if( a[brojac] % 17 == 0 ) ++sum;
    if( a[brojac] < 0 || a[brojac] > 100 ){ printf( "Nije unesen niti jedan broj iz trazenog intervala.\n" ); return 0; } 
    ++brojac;
    
    while( 1 ){
      scanf( "%d", &a[brojac] );
      if( a[brojac] < 0 || a[brojac] > 100 ) break;
      if( a[brojac] % 17 == 0 ) ++sum;
      ++brojac;
    }
    
    printf( "Broj unesenih brojeva djeljivih sa 17 je %d.\n", sum );
    
    return 0;
}
