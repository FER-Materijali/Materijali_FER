#include <iostream>
#include <string.h>
#include <string>
using namespace std;

template <class T> class Queue {
 private:
   static const int MAX = 100;
   T queue[MAX];
   int write = 0;
   int read = 0;

 public:
   bool enqueue(T item) {
      if ((write + 1) % MAX == read)
         return false;
      queue[write] = item;
      write = (write + 1) % MAX;
      return true;
   }
   bool dequeue(T &item) {
      if (write == read)
         return false;
      item = queue[read];
      read = (read + 1) % MAX;
      return true;
   }
};

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

class RPN {
   char operators[5] = "+-*/";
   char precedences[5] = "2211";
   bool isOperator(char c) { return c != '\0' && strchr(operators, c) != nullptr; }
   int precedence(char op) {
      int pos = strchr(operators, op) - operators;
      return precedences[pos];
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
   string convert(string e) {
      Stack<string> s;
      Queue<string> q;
      int pos = 0;
      string token, tokenS;
      while ((token = getNextToken(e, pos)) > "") {
         if (token == "(") {
            s.push(token);
         } else if (token == ")") {
            while (s.pop(token)) {
               if (token == "(")
                  break;
               q.enqueue(token);
            }
         } else if (isOperator(token[0])) {
            while (s.peek(tokenS)) {
               if (!isOperator(tokenS[0]))
                  break;
               if (precedence(token[0]) > precedence(tokenS[0]))
                  break;
               s.pop(tokenS);
               q.enqueue(tokenS);
            }
            s.push(token);
         } else {
            q.enqueue(token);
         }
      }
      while (s.pop(token)) {
         q.enqueue(token);
      }
      string r = "";
      while (q.dequeue(token)) {
         if (r > "")
            r += " ";
         r += token;
      }
      return r;
   }

   string evaluate(string e) {
      Stack<string> s;
      string a, b, c, token;
      int pos = 0;
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
   string result;
   result = r.convert("(1+2)*3");
   cout << result << endl;
   result = r.evaluate(result);
   cout << result << endl;
   return 0;
}