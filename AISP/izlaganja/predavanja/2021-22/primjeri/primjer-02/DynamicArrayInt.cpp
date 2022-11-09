#include <iostream>
#include <new>
using namespace std;

class DynamicArray {
 private:
   int *p;
   size_t size;

 public:
   void initialize(int value) {
      for (int i = 0; i < size; i++) {
         p[i] = value;
      }
   }
   void resize(size_t newSize) {
      int *newP = (int *)realloc(p, newSize * sizeof(int));
      if (!newP)
         throw bad_alloc();
      else {
         p = newP;
         size = newSize;
      }
   }
   DynamicArray() {
      size = 10;
      p = (int *)malloc(size * sizeof(int));
      initialize(0);
   }
   DynamicArray(size_t n) {
      size = n;
      p = (int *)malloc(size * sizeof(int));
      initialize(0);
   }
   ~DynamicArray() { free(p); }
   int &operator[](int i) {
      if (i < 0 || i >= size) {
         throw runtime_error("Invalid index");
      } else {
         return *(p + i);
      }
   }
};

int main(void) {
   DynamicArray a;
   DynamicArray b(100);
   a[0] = 3;
   try {
      cout << a[10] << endl;
   } catch (exception &ex) {
      cout << ex.what() << endl;
   }
   try {
      b.resize(200);
   } catch (exception &ex) {
      cout << ex.what() << endl;
   }
   return 0;
}