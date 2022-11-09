#include <iostream>
#include <iterator>
using namespace std;

class Point {
 public:
   int x;
   int y;
   Point(int x, int y) : x(x), y(y) {}
   friend ostream &operator<<(ostream &os, Point p) {
      os << "(" << p.x << ", " << p.y << ")";
      return os;
   }
};

template <class T> class DynamicArray {
 private:
   T *p;
   size_t size;

 public:
   void resize(size_t newSize) {
      int *newP = (T *)realloc(p, newSize * sizeof(T));
      if (!newP)
         throw bad_alloc();
      else {
         p = newP;
         size = newSize;
      }
   }
   DynamicArray() {
      size = 10;
      p = (T *)malloc(size * sizeof(T));
   }
   DynamicArray(size_t n) {
      size = n;
      p = (T *)malloc(size * sizeof(T));
   }
   ~DynamicArray() { free(p); }
   T &operator[](int i) {
      if (i < 0 || i >= size) {
         throw runtime_error("Invalid index");
      } else {
         return *(p + i);
      }
   }
   typedef T *iterator;
   iterator begin() { return p; }
   iterator end() { return p + size - 1; }
};

int main(void) {
   Point p0(1, 2), p1(3, 4), p2(5, 6);
   DynamicArray<Point> a(3);
   a[0] = p0;
   a[1] = p1;
   a[2] = p2;
   DynamicArray<Point>::iterator i;
   for (i = a.begin(); i <= a.end(); i++) {
      cout << *i << endl;
   }
   return 0;
}