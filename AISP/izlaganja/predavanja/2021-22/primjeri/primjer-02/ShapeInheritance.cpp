#include <iostream>
#define _USE_MATH_DEFINES // da se može koristiti M_PI
#include <math.h>
using namespace std;

class Shape {
 private:
   int id;

 public:
   double x;
   double y;
   double a;
   int getId() { return id; }
   Shape(int id, double x, double y, double a) : id(id), x(x), y(y), a(a) {}
   virtual double area() = 0; // čista virtualna funkcija, razredi koji
                              // nasljeđuju moraju je stvarno implementirati
};

class Triangle : public Shape {
 public:
   double b;
   double c;
   Triangle(int id, double x, double y, double a, double b, double c)
       : Shape(id, x, y, a), b(b), c(c) {}
   double area() { // Heronova formula
      double s = (a + b + c) / 2;
      return sqrt(s * (s - a) * (s - b) * (s - c));
   }
};

class Square : public Shape {
 public:
   Square(int id, double x, double y, double a)
       : Shape(id, x, y, a) {} // ili C++11: using Shape::Shape;
   double area() { return a * a; }
};

class Rectangle : public Shape {
 public:
   double b;
   Rectangle(int id, double x, double y, double a, double b)
       : Shape(id, x, y, a), b(b) {} // ili C++11: using Shape::Shape;
   double area() { return a * b; }
};

class Circle : public Shape {
 public:
   Circle(int id, double x, double y, double a)
       : Shape(id, x, y, a) {} // ili C++11: using Shape::Shape;
   double area() { return a * a * M_PI; }
};

int main(void) {
   Triangle t(1, 10, 20, 3, 4, 5);
   Square s(2, 20, 30, 2);
   Rectangle r(3, 30, 40, 3, 4);
   Circle c(4, 40, 50, 4);
   cout << t.getId() << " " << t.x << " " << t.y << " " << t.a << endl;
   Shape *set[4] = {&t, &s, &r, &c};
   double sum = 0;
   for (int i = 0; i < 4; i++) {
      sum += set[i]->area();
   }
   cout << sum << endl;
   return 0;
}