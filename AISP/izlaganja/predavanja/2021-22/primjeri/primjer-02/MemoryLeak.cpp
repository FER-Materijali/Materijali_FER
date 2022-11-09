#include <iostream>
#include <memory>
using namespace std;

class SomeClass {
 public:
   string x;
   SomeClass(string x) : x(x) {
      cout << "SomeClass object " << x << " created" << endl;
   }
   ~SomeClass() { cout << "SomeClass object " << x << " destroyed" << endl; }
};

void f() {
   SomeClass *p = new SomeClass("a");
   cout << p->x << endl;
   return;
}

int main(void) {
   f();
   return 0;
}