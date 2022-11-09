#include <iostream>
#define _USE_MATH_DEFINES // da se može koristiti M_PI
#include <math.h>
using namespace std;

class Shape {
 private:
   // inline static int autoNumber; // od C++17
   static int autoNumber; // do C++17 mora se deklarirati u razredu ali i
                          // definirati izvan razreda (linija 54)
   int id;

 public:
   double x;
   double y;
   double a;
   int getId() { return id; }
   Shape(double x, double y, double a) : x(x), y(y), a(a) { id = ++autoNumber; }
   virtual double area() = 0;
   static void resetAutoNumber() { autoNumber = 0; }
};

class Triangle : public Shape {
 public:
   double b;
   double c;
   Triangle(double x, double y, double a, double b, double c)
       : Shape(x, y, a), b(b), c(c) {}
   double area() { // Heronova formula
      double s = (a + b + c) / 2;
      return sqrt(s * (s - a) * (s - b) * (s - c));
   }
};

class Square : public Shape {
 public:
   Square(double x, double y, double a) : Shape(x, y, a) {}
   double area() { return a * a; }
};

class Rectangle : public Shape {
 public:
   double b;
   Rectangle(double x, double y, double a, double b) : Shape(x, y, a), b(b) {}
   double area() { return a * b; }
};

class Circle : public Shape {
 public:
   Circle(double x, double y, double a) : Shape(x, y, a) {}
   double area() { return a * a * M_PI; }
};

int Shape::autoNumber; // do C++17, od C++17 može i inline, pa ne treba
                       // definicija
int main(void) {
   Triangle t(10, 20, 3, 4, 5);
   Square s(20, 30, 2);
   Shape::resetAutoNumber();
   Rectangle r(30, 40, 3, 4);
   Circle c(40, 50, 4);
   cout << t.getId() << " " << s.getId() << " " << r.getId() << " " << c.getId()
        << endl;
   return 0;
}