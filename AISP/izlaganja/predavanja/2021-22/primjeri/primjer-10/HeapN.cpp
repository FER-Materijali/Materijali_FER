#include "HeapNLib.cpp"
#include <iostream>
#include <new>
using namespace std;

int main(void) {
   try {
      int A[] = {40, 80, 35, 90, 45, 50, 70, 10, 30,
                 15, 33, 77, 88, 99, 11, 37, 55};
      constexpr auto n = sizeof(A) / sizeof(int);
      HeapN<int> h(A, n);
      h.AdjustN();
      h.PrintTree();
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   std::cin.get();
   return 0;
}
