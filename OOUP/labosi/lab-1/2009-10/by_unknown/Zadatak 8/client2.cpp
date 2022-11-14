
#include "database.hpp"
class Client2 {
      AbstractDatabase& myDatabase;
      public:
             Client2(AbstractDatabase& db):
                                       myDatabase(db) {}
             void transaction() {
                  myDatabase.getData();
                  
                  }
};
