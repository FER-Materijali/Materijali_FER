#include "Heap.h"
#include <iostream>
#include <new>
using namespace std;

template <typename T> class HeapNLogN : public Heap<T> {
 private:
   void InsertLogN() {
      size_t i, k;
      size_t newElementIndex;
      k = this->j;
      i = this->j / 2;
      newElementIndex = this->elements[this->j];
      while ((i > 0) && (this->elements[i] < newElementIndex)) {
         this->elements[k] =
             this->elements[i]; // push parent to the lower level
         k = i;
         i /= 2; // parent of A[i] is at A[i/2]
      }
      this->elements[k] = newElementIndex;
   }

 public:
   HeapNLogN(size_t n) : Heap<T>(n) { this->j = 1; }
   void Add(T &element) {
      if (this->j >= (this->size + 1))
         throw std::runtime_error("Allocated heap space is full!");
      this->elements[this->j] = element;
      this->InsertLogN();
      this->j++;
   }
};

int main(void) {
   try {
      int A[] = {40, 80, 35, 90, 45, 50, 70, 10, 30,
                 15, 33, 77, 88, 99, 11, 37, 55};
      constexpr auto n = sizeof(A) / sizeof(int);
      HeapNLogN<int> h(n);
      for (int i = 0; i < n; i++) {
         h.Add(A[i]);
      }
      h.Print();
      h.PrintTree();
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   std::cin.get();
   return 0;
}
