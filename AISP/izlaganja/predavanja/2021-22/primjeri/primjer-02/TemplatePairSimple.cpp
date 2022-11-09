#include <iostream>
using namespace std;

class Complex {
 public:
   double real;
   double img;
   Complex() : real(0), img(0) {}
   Complex(double real, double img) : real(real), img(img) {}
};

template <class C> class Pair {
 public:
   C a;
   C b;
   Pair(C a, C b) {
      this->a = a;
      this->b = b;
   }
};

int main(void) {
   Complex x(1, 2), y(3, 4);
   Pair<Complex> p(x, y);
   cout << p.a.real << " " << p.a.img << endl;
   cout << p.b.real << " " << p.b.img << endl;
   return 0;
}