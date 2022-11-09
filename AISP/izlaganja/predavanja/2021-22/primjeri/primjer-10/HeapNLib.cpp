#include "Heap.h"
#include <iostream>
#include <new>
using namespace std;

template <typename T> class HeapN : public Heap<T> {
 private:
   void Adjust(size_t i, size_t n) {
      size_t j;
      T element;
      j = 2 * i;
      element = this->elements[i];
      while (j <= n) {
         // Compare left and right child (if they exist)
         if ((j < n) && (this->elements[j] < this->elements[j + 1]))
            j++;
         // j points to a larger child
         if (element >= this->elements[j])
            break; // element is in its position
         this->elements[j / 2] =
             this->elements[j]; // raise larger child one position up
         j *= 2;
      }
      this->elements[j / 2] = element; // store the element
   }

 public:
   HeapN(T *inputElements, size_t n) : Heap<T>(n) {
      for (size_t i = 0; i < n; i++) {
         this->elements[i + 1] = inputElements[i];
      }
   }
   template <typename K> friend class HeapSort;

   void AdjustN() {
      size_t i;
      for (i = this->size / 2; i >= 1; i--)
         Adjust(i, this->size);
   }
};
