#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template <typename T> class Heap {
 protected:
   size_t size;
   T *elements;
   int j;
 public:
   Heap(size_t n) {
      this->size = n;
      this->elements = new T[n + 1]; //+1 is due to an additional element space
                                     // needed in the array
   }
   void Print() {
      size_t i = 1;
      size_t k = 1;
      while (i < this->size) { // loops to the last element of the heap
         // prints until the maximum element in the heap at level k
         for (; i <= pow(2, k) - 1 && i < this->size; i++) {
            cout << " " << this->elements[i] << " ";
         }
         k++; // go to the next level
         cout << "\n";
      }
   }

   void PrintTree () { PrintTree (1, 0); }

   
   ~Heap() { delete[] this->elements; }

private:
   void PrintTree(int i, int level) {
      if (i <= this->size) {
         PrintTree(2*i+1, level + 1);  // right child
         std::string spaces(level * 2, ' ');
         std::cout << spaces << this->elements[i] << "\n";
         PrintTree(2*i, level + 1);    // left child
      }
   }
};
