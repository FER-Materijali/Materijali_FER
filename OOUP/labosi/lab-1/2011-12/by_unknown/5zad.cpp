# include "Client.h"
# include "Derived3.h"
# include <iostream>

using namespace std;

int main (){
    Derived3 d;
    Client c(d);
    c. operate ();
}
