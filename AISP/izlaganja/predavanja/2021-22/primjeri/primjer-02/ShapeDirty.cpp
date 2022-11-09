#include <iostream>
#define _USE_MATH_DEFINES // da se može koristiti M_PI
#include <math.h>
using namespace std;
class Triangle {
 public:
   char type = 'T';
   int id;
   double x;
   double y;
   double a;
   double b;
   double c;
   Triangle(int id, double x, double y, double a, double b, double c)
       : id(id), x(x), y(y), a(a), b(b), c(c) {}
   double Area() { // Heronova formula
      double s = (a + b + c) / 2;
      return sqrt(s * (s - a) * (s - b) * (s - c));
   }
};
class Square {
 public:
   char type = 'S';
   int id;
   double x;
   double y;
   double a;
   Square(int id, double x, double y, double a) : id(id), x(x), y(y), a(a) {}
   double Area() { return a * a; }
};
class Rectangle {
 public:
   char type = 'R';
   int id;
   double x;
   double y;
   double a;
   double b;
   Rectangle(int id, double x, double y, double a, double b)
       : id(id), x(x), y(y), a(a), b(b) {}
   double Area() { return a * b; }
};
class Circle {
 public:
   char type = 'C';
   int id;
   double x;
   double y;
   double a;
   Circle(int id, double x, double y, double a) : id(id), x(x), y(y), a(a) {}
   double Area() { return a * a * M_PI; }
};
int main(void) {
   Triangle t(1, 10, 20, 3, 4, 5);
   Square s(2, 20, 30, 2);
   Rectangle r(3, 30, 40, 3, 4);
   Circle c(4, 40, 50, 4);
   void *set[4] = {&t, &s, &r, &c};
   double sum = 0;
   for (int i = 0; i < 4; i++) {
      Triangle *tmp;
      tmp = (Triangle *)set[i]; // strašna prljavština: računamo da je type
                                // uvijek na prvom mjestu
      switch (tmp->type) {
      case 'T':
         sum += tmp->Area();
         break;
      case 'S':
         sum += ((Square *)tmp)->Area();
         break;
      case 'R':
         sum += ((Rectangle *)tmp)->Area();
         break;
      case 'C':
         sum += ((Circle *)tmp)->Area();
         break;
      }
   }
   cout << sum << endl;
   return 0;
}