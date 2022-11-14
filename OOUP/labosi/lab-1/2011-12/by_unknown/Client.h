#ifndef CLIENT_H
#define CLIENT_H

# include <iostream >
# include "Base.h"

using namespace std;

class Client {
    public :
        Client (Base & b): solver_ (b){}
        void operate (){
            cout << solver_ .solve() <<"\n";
        }
    private :
        Base & solver_ ;
};


#endif // CLIENT_H
