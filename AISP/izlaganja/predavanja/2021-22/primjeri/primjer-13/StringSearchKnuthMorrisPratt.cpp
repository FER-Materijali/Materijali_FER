#include <cstring>
#include <iostream>
#include <string>
using namespace std;

template <typename T> static void printArray(T A[], size_t n) {
   for (auto i = 0; i < n; i++) {
      std::cout << A[i] << " ";
   }
   std::cout << std::endl;
}

class KnuthMorrisPrattSearch {
 private:
   static int *computeLPSArray(string pattern) {
      int *lps = new int[pattern.length()];
      int len = 0;
      lps[0] = 0; // lps[0] is always 0
      int i = 1;
      int m = pattern.length();
      while (i < m) {
         if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
         } else {
            if (len != 0) {
               len = lps[len - 1];
            } else {
               lps[i] = 0;
               i++;
            }
         }
      }
      return lps;
   }

 public:
   static int Search(string A, string pattern) {
      int M = pattern.length();
      int N = A.length();
      int *lps = computeLPSArray(pattern);
      int i = 0; // index for A
      int j = 0; // index for pattern
      cout << "LPS array:";
      printArray(lps, pattern.length());
      cout << "\n";
      while (i < N) {
         cout << "New algorithm iteration started! i=" << i << ", j=" << j;
         cout << "\n";
         cout << "A = " << A << "\n";
         cout << "pattern = " << pattern << "\n";
         if (pattern[j] == A[i]) {
            cout << "pattern[j] == A[i] - do j++ and i++";
            j++;
            i++;
         }
         if (j == M) {
            cout << "j == M. Pattern is found";
            cout << "j = lps[j-1] = lps[" << j - 1 << "] = " << lps[j - 1];
            return i - j;
            // j = lps[j - 1]; //this is only needed if multiple occurences need
            // to be found
         } else if (i < N && pattern[j] != A[i]) {
            if (j != 0) {
               cout << "\nA[i] and pattern[j] do not match and j > 0, change"
                       "only j\n";
               cout << "j = lps[j-1] = lps[" << j - 1 << "] = " << lps[j - 1];
               j = lps[j - 1];
            } else {
               cout << "A[i] and pattern[j] do not match and j = 0, do i++";
               i = i + 1;
            }
         }
         cout << "\n\n";
      }
      return -1;
   }
};

int main(void) {
   try {
      string A = "ababbaabaaab";
      string pattern = "aaab";
      int foundPosition = KnuthMorrisPrattSearch::Search(A, pattern);
      if (foundPosition != -1) {
         std::cout << "\n\nPattern found at position " << foundPosition;
      } else {
         std::cout << "\n\nPattern was not found in the input string";
      }
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   std::cin.get();
   return 0;
}
