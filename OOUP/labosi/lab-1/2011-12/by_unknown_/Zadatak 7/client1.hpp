#include "concreteDatabase.hpp"

class Client1 
{
    private:
        ConcreteDatabase myDatabase;

    public:
        void transaction() 
        {
            myDatabase.getData();
            // ....
        }
};