#include <iostream>
#include <math.h>
using namespace std;
class C {
 public:
   int x;
   C() : x(0) {}
   C(int x) : x(x) {}
   ~C() { cout << " ~"; }
};
int main(int argc, char *argv[]) {
   int *p;
   C *r, *s;
   p = new int;
   r = new C;
   s = new C(4);
   cout << *p << " " << r->x << " " << s->x;
   delete p;
   delete r;
   delete s;
   return 0;
}