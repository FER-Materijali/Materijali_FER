#ifndef DERIVED3_H
#define DERIVED3_H

# include "Base.h"
# include <iostream>

using namespace std;

class Derived3: public Base{
    public:
        virtual int solve (){ return 22;}
};

#endif // DERIVED3_H
