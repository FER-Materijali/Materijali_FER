#include <iostream>

// Function f: finishes when the stack is full
void f(int i) {
   // int v;
   int p[40000]; // increase system stack size

   std::cout << i << "\n";
   f(i + 1);
}

int main(void) {
   f(1);
   std::cin.get();
   return 0;
}
