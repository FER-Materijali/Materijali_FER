
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

template <class T> class Stack {
 private:
   static const int MAX = 100;
   T stack[MAX];
   int top = -1;

 public:
   bool push(T item) {
      if (top >= MAX)
         return false;
      stack[++top] = item;
      return true;
   }
   bool pop(T &item) {
      if (top < 0)
         return false;
      item = stack[top--];
      return true;
   }
};

class RPN {
   char operators[5] = "+-*/";
   bool isOperator(char c) {
      return c != '\0' && strchr(operators, c) != nullptr;
   }
   string getNextToken(string buf, int &i) {
      string token = "";
      char accepted[] = "1234567890.+-*/()";
      const char *p = buf.c_str();
      int j;
      for (; strchr(accepted, *(p + i)) == nullptr; i++)
         ;
      if (isOperator(*(p + i)) || *(p + i) == '(' || *(p + i) == ')') {
         token = *(p + i++);
         return token;
      }
      for (j = 0; *(p + i) == '.' || isdigit(*(p + i)); i++)
         token += *(p + i);
      return token;
   }

 public:
   string evaluate(string e) {
      Stack<string> s;
      string token;
      string a, b, c;
      int pos = 0, nextPos;
      while ((token = getNextToken(e, pos)) > "") {
         if (isOperator(token[0])) { // operator
            if (!(s.pop(a) && s.pop(b)))
               throw "No operand on stack";
            switch (token[0]) {
            case '+':
               s.push(to_string(stod(b) + stod(a)));
               break;
            case '-':
               s.push(to_string(stod(b) - stod(a)));
               break;
            case '*':
               s.push(to_string(stod(b) * stod(a)));
               break;
            case '/':
               s.push(to_string(stod(b) / stod(a)));
               break;
            }
         } else {
            s.push(token);
         }
      }
      if (!s.pop(token))
         throw "No result";
      return token;
   }
};

int main(void) {
   RPN r;
   string result = r.evaluate("8 9 3 + * 16 /");
   cout << result << endl;
   return 0;
}