#include <iostream>
#include <new>
using namespace std;

template <class T> class DynamicArray {
 private:
   T *p;
   size_t size;

 public:
   void initialize(int value) {
      for (int i = 0; i < size; i++) {
         p[i] = value;
      }
   }
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
      initialize(0);
   }
   DynamicArray(size_t n) {
      size = n;
      p = (T *)malloc(size * sizeof(T));
      initialize(0);
   }
   ~DynamicArray() { free(p); }
   T &operator[](int i) {
      if (i < 0 || i >= size) {
         throw runtime_error("Invalid index");
      } else {
         return *(p + i);
      }
   }
};

int main(void) {
   DynamicArray<float> a;
   DynamicArray<int> b(100);
   a[0] = 3;
   try {
      cout << a[0] << endl;
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