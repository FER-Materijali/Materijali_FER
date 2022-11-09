#include <iostream>
using namespace std;
// exception ima samo default konstruktor
class MyException : public runtime_error {
 private:
   int number;

 public:
   MyException(const char *message, int number)
       : runtime_error(message), number(number){};
   int code() { return number; }
};
int main(void) {
   try {
      throw MyException("Tekst", 3);
   } catch (MyException &ex) {
      cout << ex.code() << " " << ex.what() << endl;
   }
   return 0;
}