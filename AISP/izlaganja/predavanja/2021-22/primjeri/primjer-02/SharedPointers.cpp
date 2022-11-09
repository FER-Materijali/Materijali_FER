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
   shared_ptr<SomeClass> p(new SomeClass("a"));
   cout << p->x << " " << p.use_count() << endl;
   p = make_shared<SomeClass>("b");
   cout << p->x << " " << p.use_count() << endl;
   {
      shared_ptr<SomeClass> r = p;
      cout << p->x << " " << p.use_count() << endl;
      cout << r->x << " " << r.use_count() << endl;
   }
   cout << p->x << " " << p.use_count() << endl;
   return;
}

int main(void) {
   f();
   return 0;
}