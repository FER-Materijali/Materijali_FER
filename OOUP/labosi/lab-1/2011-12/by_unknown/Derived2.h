#ifndef DERIVED2_H
#define DERIVED2_H


# include "Base.h"
# include <iostream>

using namespace std;

class Derived2 : public Base {
    public :
        virtual int solve (){ return 0;}
};

#endif // DERIVED2_H
