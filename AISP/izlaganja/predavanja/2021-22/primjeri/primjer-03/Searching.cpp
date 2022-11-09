// using -std=c++11
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

struct RetValSearch {
   bool found;
   int index;

   RetValSearch() : found(false), index(-1) {}
   RetValSearch(bool newFound, int newIndex)
       : found(newFound), index(newIndex) {}
};

template <typename T> class ISearch {
 public:
   virtual RetValSearch search(const T A[], const size_t n, const T &item) = 0;
};

template <typename T> class LinearSearch : public ISearch<T> {
 public:
   RetValSearch search(const T A[], const size_t n, const T &item) override {
      bool found = false;
      int index = -1;
      for (auto i = 0; i < n; i++) {
         if (A[i] == item) {
            found = true;
            index = i;
            break;
         }
      }
      return RetValSearch{found, index};
   }
};

template <typename T> class LinearSearchRecursive : public ISearch<T> {
 public:
   RetValSearch search(const T A[], const size_t n, const T &item) override {
      int index = n - 1;
      if (index < 0) {
         return RetValSearch{false, -1};
      } else if (A[index] == item) {
         return RetValSearch{true, index};
      }
      return search(A, n - 1, item);
   }
};

template <typename T> class LinearSearchRecursiveSentinel : public ISearch<T> {
 public:
   RetValSearch search(const T A[], const size_t n, const T &item) override {
      // new temp array that includes sentinel, since we do not want to modify
      // the original array by adding an extra element
      T *A2 = new T[n + 1];
      A2[0] = item; // sentinel
      for (auto i = 0; i < n; i++)
         A2[i + 1] = A[i];

      LinearSearchRecursive<T> lsr;
      RetValSearch rvs = lsr.search(A2, n + 1, item);
      delete[] A2;

      if (rvs.index == 0) {
         return RetValSearch{}; // not found
      } else {
         return RetValSearch{true, rvs.index - 1}; // found; update index
      }
   }
};

template <typename T> class BinarySearch : public ISearch<T> {
 public:
   RetValSearch search(const T A[], const size_t n, const T &item) override {
      auto left = 0;
      auto right = n - 1;
      auto found = false;
      auto attempts = 0;
      auto index = -1;

      while (left <= right) {
         auto middle = (left + right) / 2;
         ++attempts;
         std::cout << "Searching A[" << left << " : " << right
                   << "]. Middle element: A[" << middle << "] = " << A[middle]
                   << ". Attempts: " << attempts << ".\n";
         if (A[middle] < item) {
            left = middle + 1;
         } else if (A[middle] > item) {
            right = middle - 1;
         } else {
            found = true;
            index = middle;
            break;
         }
      }
      return RetValSearch{found, index};
   }
};

template <typename T> class JumpSearch : public ISearch<T> {

 public:
   RetValSearch search(const T A[], const size_t n, const T &item) override {
      auto found = false;
      auto index = -1;
      const int blockSize = sqrt(n);
      int blockStart = 0;
      int nextBlockStart = blockSize;
      int next = std::min(nextBlockStart, (int)n - 1);

      // find the right block
      while (next < n - 1 && A[next] <= item) {
         blockStart = nextBlockStart; // start of the next block
         nextBlockStart += blockSize; // end of the next block
         next = std::min(nextBlockStart, (int)n - 1);
      }

      // search the block
      if (next == n - 1) {
         ++next;
      }
      for (auto i = blockStart; i < next; i++) {
         if (A[i] == item) {
            index = i;
            found = true;
            break;
         }
      }
      return RetValSearch{found, index};
   }
};

template <typename T> class ContextSearch {
 private:
   ISearch<T> *searchStrategy;

   void deleteSearchStrategy() {
      delete searchStrategy;
      searchStrategy = nullptr;
   }

 public:
   enum StategyType {
      Linear = 1,
      LinearRecursive,
      Binary,
      Jump,
      LinearRecursiveSentinel
   };

   ContextSearch() { // set default searching algorithm
      searchStrategy = new LinearSearch<T>();
   }

   void setSearch(int type, const T A[], const size_t n) {
      // set new strategy
      if (searchStrategy) {
         deleteSearchStrategy();
         if (type == Linear) {
            searchStrategy = new LinearSearch<T>();
         } else if (type == LinearRecursive) {
            searchStrategy = new LinearSearchRecursive<T>();
         } else if (type == Binary) {
			if (!std::is_sorted(A, A + n)) { // raise exception, since binary search can only be applied to sorted arrays
				 throw std::invalid_argument("Error: Array not sorted! Binary search cannot be used.\n");
			}
			searchStrategy = new BinarySearch<T>();
		 } else if (type == Jump) {
			if (!std::is_sorted(A, A + n)) { // raise exception, since binary search can only be applied to sorted arrays
			   throw std::invalid_argument("Error: Array not sorted! Jump search cannot be used.\n");
			}
			searchStrategy = new JumpSearch<T>();
         } else if (type == LinearRecursiveSentinel) {
            searchStrategy = new LinearSearchRecursiveSentinel<T>();
         } else {
            throw std::invalid_argument("Error: Invalid search mode.\n");
         }
      }
   }

   RetValSearch search(const T A[], const size_t n, const T &item) const {
      if (!searchStrategy) {
         throw std::runtime_error("Search strategy not set!\n");
      }
      return searchStrategy->search(A, n, item);
   }

   ~ContextSearch() {
      if (searchStrategy) {
         deleteSearchStrategy();
      }
   }
};

// Print array
template <typename T> void printArray(T A[], size_t n) {
   for (auto i = 0; i < n; i++) {
      std::cout << A[i] << " ";
   }
   std::cout << std::endl;
}

int main(void) {
   int A[] = {4, -3, 5, -2, -1, 2, 6, -2, 9, 8};
   int A2[] = {-3, 0, 2, 5, 6, 7, 9, 12, 15, 23, 45, 100, 209, 517};
   constexpr auto n = sizeof(A) / sizeof(int);
   constexpr auto n2 = sizeof(A2) / sizeof(int);
   //printArray<int>(A, n);
   printArray<int>(A2, n2);

   ContextSearch<int> cs;
   int val, index, type;
   try {
      while (true) {
         std::cout << "Enter an integer > ";
         std::cin >> val;
         if (std::cin.fail()) {
            throw std::invalid_argument("Error: Not an integer.\n");
         }
         std::cout
             << "Enter search mode:\n (1) Linear\n (2) Linear-recursive\n (3) "
                "Binary\n (4) Jump/Block\n (5) Linear-recursive-sentinel\n > ";
         std::cin >> type;
         if (std::cin.fail()) {
            throw std::invalid_argument("Error: Invalid search mode.\n");
         }
         cs.setSearch(type, A2, n2);
         auto retVal = cs.search(A2, n2, val);
         auto str = retVal.found ? " is " : " isn't ";
         auto str2 =
             retVal.found ? " at position " + std::to_string(retVal.index) : "";
         std::cout << val << str << "found in A" << str2 << "." << std::endl;
      }
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   system("pause");
   std::cin.get();
   return 0;
}
