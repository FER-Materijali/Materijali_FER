#include <iostream>
using namespace std;

template <typename T> class Point {
 public:
   T x;
   T y;
   Point() : x(0), y(0) {}         // pretpostavljeni konstruktor
   Point(T x, T y) : x(x), y(y) {} // konstruktor s parametrima
};

template <class C1, class C2> class Pair {
 public:
   C1 a;
   C2 b;
   Pair(C1 a, C2 b) {
      this->a = a;
      this->b = b;
   }
};

int main(void) {
   Point<int> pi1(1, 2), pi2(3, 4);
   Point<double> pd1(1.1, 2.2), pd2(3.3, 4.4);
   Pair<Point<int>, Point<int>> ppi(pi1, pi2);
   Pair<Point<double>, Point<double>> ppd(pd1, pd2);
   cout << ppi.a.x << " " << ppi.a.y << endl;
   cout << ppd.a.x << " " << ppd.a.y << endl;
   return 0;
}