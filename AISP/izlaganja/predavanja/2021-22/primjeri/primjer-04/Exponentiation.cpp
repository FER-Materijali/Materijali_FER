#include <iostream>

// Compute x^y recursively
int powr(int x, int y) {
   if (y <= 0) {
      return 1;
   } else {
      return x * powr(x, y - 1);
   }
}

int main(void) {
   int x, y, res;

   while (true) {
      std::cout << "Enter a base x (an integer) and an exponent y (a "
                   "nonnegative integer):";
      std::cin >> x >> y;
      if (y < 0) {
         break;
      }
      res = powr(x, y);
      std::cout << x << "^" << y << " = " << res << std::endl;
   }
   return 0;
}
