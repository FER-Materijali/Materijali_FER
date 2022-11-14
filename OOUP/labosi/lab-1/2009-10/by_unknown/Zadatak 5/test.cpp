#include <iostream>
#include "myarray.hpp"
#include <assert.h>
#define NDEBUG

int main() {
    Array<std::string> mojNizStringova(2);
    mojNizStringova[0] = "bok bok";
    mojNizStringova[1] = "kaj ima?";
    
    
    for(int i=0; i<3; i++) //prekoraæenje indexa 
            std::cout<<"mojNizStringova["<<i<<"] = "<<mojNizStringova[i]<<"\n";
}
