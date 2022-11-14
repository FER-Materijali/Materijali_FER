#include <stdio.h>
#include <string.h>

int main (){
    
    char string[21];
    
    scanf( "%s", string );
    
    for( int i = 0; i < strlen(string); ++i ){
      if( string[i] >= 'a' && string[i] <= 'z' ){
        char a = string[i];
        char t = string[strlen(string)-1];
        string[i] = t;
        string[strlen(string)-1] = a;
        printf( "%s\n", string );
        return 0;
      }
    }
    
    return 0;
}
      
