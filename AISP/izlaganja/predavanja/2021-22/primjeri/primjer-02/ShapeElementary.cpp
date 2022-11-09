#include <iostream>
#define _USE_MATH_DEFINES // da se može koristiti M_PI
#include <math.h>
using namespace std;
class Triangle {
 public:
   int id;
   double x;
   double y;
   double a;
   double b;
   double c;
   Triangle(int id, double x, double y, double a, double b, double c)
       : id(id), x(x), y(y), a(a), b(b), c(c) {}
   double area() { // Heronova formula
      double s = (a + b + c) / 2;
      return sqrt(s * (s - a) * (s - b) * (s - c));
   }
};
class Square {
 public:
   int id;
   double x;
   double y;
   double a;
   Square(int id, double x, double y, double a) : id(id), x(x), y(y), a(a) {}
   double area() { return a * a; }
};
class Rectangle {
 public:
   int id;
   double x;
   double y;
   double a;
   double b;
   Rectangle(int id, double x, double y, double a, double b)
       : id(id), x(x), y(y), a(a), b(b) {}
   double area() { return a * b; }
};
class Circle {
 public:
   int id;
   double x;
   double y;
   double a;
   Circle(int id, double x, double y, double a) : id(id), x(x), y(y), a(a) {}
   double area() { return a * a * M_PI; }
};
int main(void) {
   Triangle t(1, 10, 20, 3, 4, 5);
   Square s(2, 20, 30, 2);
   Rectangle r(3, 30, 40, 3, 4);
   Circle c(4, 40, 50, 4);
   cout << t.area() + s.area() + r.area() + c.area() << endl;
   return 0;
}