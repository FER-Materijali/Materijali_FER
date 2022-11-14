#include <stdio.h>
#include <math.h>

#define PI 3.141593

int main (){
    
    int n;
    
    
    while( 1 ){
      scanf( "%d", &n );
      if( n >= 1 && n <= 1000 ) break;
    }
    
    double pii = 0.0;
    double t = 0.0;
    
    for( int i = 1; i <= n; ++i  ){
      if( i % 2 != 0 ) t += 1. / (2*i-1);
      else t -= 1. / (2*i-1);
      
    }
        
           
    pii = 4*t;
    
    printf( "%.5lf\n", pii );  
    printf( "%.5lf", fabs( pii - PI ) );
    
    return 0;
}
    
    
    
    
