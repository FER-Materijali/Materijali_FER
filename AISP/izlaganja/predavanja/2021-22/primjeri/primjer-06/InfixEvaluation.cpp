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
   bool peek(T &item) {
      if (top < 0)
         return false;
      item = stack[top];
      return true;
   }
};

class Infix {
   Stack<char> operatorStack;
   Stack<double> valueStack;
   char operators[5] = "+-*/";
   char precedences[5] = "2211";
   bool isOperator(char c) {
      return c != '\0' && strchr(operators, c) != nullptr;
   }
   int precedence(char op) {
      int pos = strchr(operators, op) - operators;
      return precedences[pos];
   }
   void eval() {
      char op;
      operatorStack.pop(op);
      double v1, v2;
      valueStack.pop(v1);
      valueStack.pop(v2);
      switch (op) {
      case '+':
         valueStack.push(v2 + v1);
         break;
      case '-':
         valueStack.push(v2 - v1);
         break;
      case '*':
         valueStack.push(v2 * v1);
         break;
      case '/':
         valueStack.push(v2 / v1);
         break;
      }
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
   double evaluate(string e) {
      string token;
      char newOp, op;
      int pos = 0;
      while ((token = getNextToken(e, pos)) > "") {
         if (isOperator(token[0])) { // operator
            newOp = token[0];
            while (operatorStack.peek(op) && isOperator(op) &&
                   precedence(op) <= precedence(newOp)) {
               eval();
            }
            operatorStack.push(newOp);
         } else if (token[0] == '(') {
            operatorStack.push(token[0]);
         } else if (token[0] == ')') {
            while (operatorStack.peek(op) && op != '(') {
               eval();
            }
            operatorStack.pop(op);
         } else {
            valueStack.push(stod(token));
         }
      }
      while (operatorStack.peek(op)) {
         eval();
      }
      double result;
      valueStack.pop(result);
      return result;
   }
};

int main(void) {
   Infix r;
   double result;
   // result = r.evaluate("(1+2)*3");
   result = r.evaluate("   2+3*4");
   // result = r.evaluate("(2*(6-2))*3");
   cout << result << endl;
   return 0;
}