#include "base.hpp"

class Derived3 : public Base 
{
    public:
        virtual int solve()
        { 
            return 3;
        }
};