#include <iostream>
namespace s1 {
float const pi = 3.14;
}
namespace s2 {
double const pi = 3.141592654;
}
int main(void) {
   std::cout << s1::pi << " ";
   std::cout << s2::pi << std::endl;
   return 0;
}