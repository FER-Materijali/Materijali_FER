// ideja je da uèitane brojeve promatramo kao pozicije u polju, ako recimo uèitamo 5 puta broj 2, na poziciji u polju a[2] æe stajati 5
// dalje je dovoljno samo provjeriti jesmo li došli do 5 i ako jesmo ubijemo program

#include <stdio.h>

int main (){
    
    int a[101];
    int x;
    int brojac = 0;
    
    // na poèetku polje u kojem brojimo koliko je puta neki broj bio uèitan mora biti nula
    for( int i = 0; i <= 100; ++i ) a[i] = 0;
    
    while( 1 ){
      scanf( "%d", &x );
      if( x < 1 || x > 100 ){ printf( "Ne valjali broj\n" ); return 0; }
      a[x]++; // povecamo polje s indeksom x za jedan
      for( int i = 0; i <= 100; ++i )
        if( a[i] == 5 ){ printf( "Broj koji se procitao 5 puta: %d", i ); return 0; }
    }
    
    return 0;   
}
