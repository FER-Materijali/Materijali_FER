#include "HeapNLib.cpp"
#include <iostream>
#include <new>
using namespace std;

template <typename T> static void printArray(T A[], size_t n) {
   for (auto i = 0; i < n; i++) {
      std::cout << A[i] << " ";
   }
   std::cout << std::endl;
}

template <typename T> static void Swap(T *left, T *right) {
   T temp = *left;
   *left = *right;
   *right = temp;
}

template <typename T> class HeapSort {
 private:
   HeapN<T> *h;
   size_t n;

 public:
   HeapSort(T *elements, size_t n) {
      this->h = new HeapN<T>(elements, n);
      this->n = n;
      h->AdjustN();
   }
   void Sort() {
      for (size_t i = n; i >= 2; i--) {
         // Exchange the root with the last leadrt and shorten the array by 1,
         // then adjust the heap
         Swap(&h->elements[1], &h->elements[i]);
         h->Adjust(1, i - 1);
      }
   }
   void Print() { printArray(&h->elements[1], h->size); }
   ~HeapSort() { delete h; }
};

int main(void) {
   try {
      int A[] = {4, 3, 5, 2, 1, 6, 7, 9, 8};
      constexpr auto n = sizeof(A) / sizeof(int);
      int tempArray[n * sizeof(int)];
      HeapSort<int> h(A, n);
      std::cout << "Array before HeapSort:";
      h.Print();
      std::cout << "Array after HeapSort:";
      h.Sort();
      h.Print();
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   std::cin.get();
   return 0;
}
