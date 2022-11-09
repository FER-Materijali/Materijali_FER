#include <iostream>
using namespace std;

class Shape {
 private:
   int id;
   friend void setId(Shape &s, int newId);

 public:
   int getId() { return id; }
};

void setId(Shape &s, int newId) { s.id = newId; }

int main(void) {
   Shape s;
   setId(s, 10);
   cout << s.getId() << endl;
   return 0;
}