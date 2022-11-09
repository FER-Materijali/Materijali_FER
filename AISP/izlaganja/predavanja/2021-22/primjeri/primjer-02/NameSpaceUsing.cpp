#include <iostream>
namespace s1 {
float const pi = 3.14;
}
namespace s2 {
double const pi = 3.141592654;
}
using namespace s1;
int main(void) {
   std::cout << pi << " ";
   std::cout << s2::pi << std::endl;
   return 0;
}