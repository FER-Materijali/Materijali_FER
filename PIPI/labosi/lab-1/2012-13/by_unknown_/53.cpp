#include <stdio.h>

int main (){
    
    int brojac = 0;
    int sum = 0;
    char c[100];
    
    scanf( "%s", c );
    if( c[0] < '0' || c[0] > 'F' ){ printf( "Nije unesen niti jedan broj iz trazenog intervala.\n" ); return 0; } 
    if( (c[0] >= 'A' && c[0] <= 'F') || (c[0] >= 'a' && c[0] <= 'f') ) ++sum;
    while( 1 ){
      scanf( "%s", c );
      if( c[0] < '0' || c[0] > 'F' ) break;
      if( (c[0] >= 'A' && c[0] <= 'F') || (c[0] >= 'a' && c[0] <= 'f') ) ++sum;
    }
    
    printf( "Broj unesenih heksadekadskih znamenki koje nisu dekadske: %d.\n", sum );
    
    return 0;
}
