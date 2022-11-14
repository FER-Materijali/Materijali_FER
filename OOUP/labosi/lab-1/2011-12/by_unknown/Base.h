#ifndef BASE_H
#define BASE_H

# include <iostream>

using namespace std;


class Base {
    public :
        virtual ~Base (){};
        virtual int solve ()=0;
};


#endif // BASE_H
