#include <cstring>
#include <iostream>
#include <string>
using namespace std;
// d is the maximum number of values for a character (2^8, 8 because a char is
// 8-bit)
#define D 256
#define PRIME 251

class RabinKarpSearch {
 private:
   static int mostSigDigitValue;
   static void CalculateMostSigDigitValue(int length) {
      mostSigDigitValue = 1;
      for (int i = 0; i < length - 1; i++)
         mostSigDigitValue = (mostSigDigitValue * D) % PRIME;
   }
   static int GetHash(string s, int startIndex, int length) {
      int hash = 0;
      for (int i = 0; i < length; i++) {
         hash = (D * hash + s[startIndex + i]) % PRIME;
      }
      return hash;
   }
   static int ReHash(int oldHash, char leadingDigit, char lastDigit) {
      int oldHashWithoutLeadingDigit =
          oldHash - leadingDigit * mostSigDigitValue;
      int newHashwithoutLastDigit = oldHashWithoutLeadingDigit * D;
      int newHash = (newHashwithoutLastDigit + lastDigit) % PRIME;
      if (newHash < 0) // in case new hash is negative, covert to a positive num
         newHash += PRIME;
      return newHash;
   }

 public:
   static int Search(string A, string pattern) {
      int i, j, n, m, h, p, t;
      n = A.length();
      m = pattern.length();
      p = GetHash(pattern, 0, m); // get hash for pattern
      t = GetHash(A, 0,
                  m); // get hash for the first m characters of the input string
      CalculateMostSigDigitValue(m);
      for (i = 0; i <= n - m; i++) {
         if (p == t) { // compare hash values of the input substring and the
                       // pattern string
            for (j = 0; j < m;
                 j++) { // check if the input substrings and pattern are exactly
                        // the same character by character
               if (A[i + j] != pattern[j])
                  break;
            }
            if (j == m) // both checks are OK, substring is found at index i
               return i;
         }
         if (i < n - m) {
            t = ReHash(t, A[i], A[i + m]); // create new hash for next substring
         }
      }
      return -1;
   }
};

int RabinKarpSearch ::mostSigDigitValue = 1;

int main(void) {
   try {
      string A = "ababbaabaaab";
      string pattern = "abaa";
      int foundPosition = RabinKarpSearch::Search(A, pattern);
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
