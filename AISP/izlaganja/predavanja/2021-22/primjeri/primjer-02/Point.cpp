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
   Point p;
   cout << sizeof(p) << endl;
   cout << p.x << " " << p.y << endl;
   p.x = 10;
   p.y = 20;
   p.mirrorX(-1);
   cout << p.x << " " << p.y << endl;
   return 0;
}