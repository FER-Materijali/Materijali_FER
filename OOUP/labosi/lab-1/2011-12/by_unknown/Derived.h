#ifndef DERIVED_H
#define DERIVED_H


# include "Base.h"
# include <iostream>

using namespace std;

class Derived : public Base {
    public :
        virtual int solve (){return 42;}
};


#endif // DERIVED_H
