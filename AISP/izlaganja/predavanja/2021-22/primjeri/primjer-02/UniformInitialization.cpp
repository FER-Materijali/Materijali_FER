#include <iostream>
#include <math.h>
using namespace std;

class Point {
 public:
   double x;
   double y;
   double distance(Point other) {
      return sqrt((x - other.x) * (x - other.x) +
                  (y - other.y) * (y - other.y));
   }
   Point swapXY() { return {y, x}; }
};

int main(void) {
   int i{4};
   int x[]{1, 2, 3};
   cout << i << " " << x[0] << endl;
   Point a{7, 8};
   cout << a.x << " " << a.y << endl;
   Point b{9};
   cout << b.x << " " << b.y << endl;
   Point p[]{{1, 2}, {3, 4}, {5, 6}};
   cout << p[1].x << " " << p[1].y << endl;
   cout << a.distance({8, 9}) << endl;
   Point c = a.swapXY();
   cout << c.x << " " << c.y << endl;
   return 0;
}