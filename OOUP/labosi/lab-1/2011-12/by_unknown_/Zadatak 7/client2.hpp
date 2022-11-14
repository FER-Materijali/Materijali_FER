#include "abstractDatabase.hpp"

class Client2 
{
    private:
        AbstractDatabase& myDatabase;

    public:
        Client2(AbstractDatabase& db) :
            myDatabase(db) { }

        void transaction() 
        {
            myDatabase.getData();
            // ...
        }
};