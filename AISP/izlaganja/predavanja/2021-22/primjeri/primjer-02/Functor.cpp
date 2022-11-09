#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class Print {
 public:
   string format; // razred string se brine za odgovarajuću rezervaciju memorije
   Print(string format) : format(format){};
   void operator()(int &i) {
      printf(format.c_str(), i);
   } // ali printf treba char *
};
class Multiply {
 public:
   int multiplier;
   Multiply(int multiplier) : multiplier(multiplier){};
   void operator()(int &i) { i *= multiplier; }
};

int main(void) {
   vector<int> v = {1, 2, 3, 4, 5};
   for_each(v.begin(), v.end(), Multiply(3));
   for_each(v.begin(), v.end(), Print("%03d "));
   return 0;
}