#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class NaiveStringSearch {
 public:
   static int Search(string A, string pattern) {
      int i, j, n, m;
      n = A.length();
      m = pattern.length();
      for (j = 0; j <= n - m; j++) {
         for (i = 0; i < m && pattern[i] == A[i + j]; i++)
            ;
         if (i >= m)
            return j;
      }
      return -1;
   }
};

int main(void) {
   try {
      string A = "ababbaabaaab";
      string pattern = "abaa";
      int foundPosition = NaiveStringSearch::Search(A, pattern);
      if (foundPosition != -1) {
         std::cout << "Pattern found at position " << foundPosition;
      } else {
         std::cout << "Pattern was not found in the input string";
      }
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   std::cin.get();
   return 0;
}
