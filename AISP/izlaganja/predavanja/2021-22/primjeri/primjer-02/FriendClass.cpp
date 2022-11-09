#include <iostream>
using namespace std;

class Shape {
 private:
   int id;
   friend class SomeClass;
 public:
   int getId() { return id; }
};

class SomeClass {
public:
  void setId(Shape &s, int newId) { s.id = newId; }
};

int main(void) {
   Shape s;
   SomeClass c;
   c.setId(s, 10);
   cout << s.getId() << endl;
   return 0;
}