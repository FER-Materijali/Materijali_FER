#include <stdio.h>

int main (){
    
    int a[100001];
    scanf( "%d%d", &a[0], &a[1] );
    
    if( ( a[0] < 0 || a[0] > 100 ) || ( a[1] < 0 || a[1] > 100 ) ){ printf( "Nije uneseno dovoljno brojeva iz trazenog intervala\n" ); return 0; } 
    
    int brojac = 2;
    int max1 = 0;
    int max2 = 0;
    
    while( 1 ){
      scanf( "%d", &a[brojac] );
      if( a[brojac] < 0 || a[brojac] > 100 ) break;
      ++brojac;
    }
    printf( "%d\n", brojac );
    for( int i = 0; i < brojac; ++i )
      if( a[i] > max1 ) max1 = a[i];
    
    for( int i = 0; i < brojac; ++i )
      if( a[i] > max2 && a[i] != max1 ) max2 = a[i];
    
    printf( "Ostatak pri dijeljenju %d s %d je %d.\n", max1, max2, max1%max2 );
    
    return 0;   
}
