#include <iostream>
#include <math.h>
using namespace std;
class C {
 public:
   int x;
   C() : x(0) {}
   C(int x) : x(x) {}
   ~C() { cout << "~ "; }
};
int main(void) {
   C *r;
   r = new C[5];
   cout << r[0].x << " ";
   delete[] r;
   return 0;
}