#include <iostream>
#include <string.h>
using namespace std;

class Point {
 public:
   double x;
   double y;
   void mirrorX(double xValue) { x = xValue - (x - xValue); }
   void mirrorY(double yValue) { y = yValue - (y - yValue); }
};

int main(void) {
   Point p, r, s;
   cout << sizeof(p) << endl;
   cout << p.x << " " << p.y << endl;
   p.x = 10;
   p.y = 20;
   r = p;
   cout << r.x << " " << r.y << endl;
   memcpy(&s, &p, sizeof(p));
   cout << s.x << " " << s.y << endl;
   return 0;
}