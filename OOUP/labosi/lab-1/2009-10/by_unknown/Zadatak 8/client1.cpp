
#include "database.hpp"
class Client1 {
      ConcreteDatabase myDatabase;
      public:
             Client1(): myDatabase() {}
      public:
             void transaction() {
                  myDatabase.getData();
                  
                  }
};
