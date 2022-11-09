#include <iostream>
using namespace std;

class Point {
 public:
   double x;
   double y;
   Point() { // pretpostavljeni (default) konstruktor
      x = 0;
      y = 0;
   }
   Point(double xIn, double yIn) { // konstruktor s parametrima
      x = xIn;
      y = yIn;
   }
};

int main(void) {
   Point p, r(1, 2);
   cout << p.x << " " << p.y << endl;
   cout << r.x << " " << r.y << endl;
   return 0;
}