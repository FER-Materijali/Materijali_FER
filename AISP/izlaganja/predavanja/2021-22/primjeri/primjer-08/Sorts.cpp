#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

class StopWatch {
 private:
   chrono::time_point<chrono::steady_clock> start;

 public:
   void reset() { start = chrono::steady_clock::now(); }
   double elapsedSeconds() {
      return chrono::duration_cast<chrono::microseconds>(
                 chrono::steady_clock::now() - start)
                 .count() /
             1000000.;
   }
};

template <typename T> static void printArray(T A[], size_t n) {
   for (auto i = 0; i < n; i++) {
      cout << A[i] << " ";
   }
   cout << endl;
}

class Sorts {
 private:
   template <typename T> static inline void Swap(T *left, T *right) {
      T temp = *left;
      *left = *right;
      *right = temp;
   }

 public:
   template <typename T> static void SelectionSort(T A[], size_t n) {
      size_t i, j, min;
      for (i = 0; i < n; i++) {
         min = i;
         for (j = i + 1; j < n; j++) {
            if (A[j] < A[min])
               min = j;
         }
         Swap(&A[i], &A[min]);
      }
   }

   // Pažnja, potencijalni stack overflow, mora se prevesti s
   // -foptimize-sibling-calls or -O2, -O3, -Os
   template <typename T> static void SelectionSortRecursive(T A[], size_t n) {
      size_t i, j, min;
      if (n <= 1)
         return;
      min = 0;
      for (j = 1; j < n; j++) {
         if (A[j] < A[min])
            min = j;
      }
      Swap(&A[0], &A[min]);
      SelectionSortRecursive(A + 1, n - 1);
   }

   template <typename T> static void BubbleSort(T A[], size_t n) {
      size_t i, j;
      for (i = 0; i < n - 1; i++) {
         for (j = 0; j < n - 1 - i; j++) {
            if (A[j + 1] < A[j])
               Swap(&A[j], &A[j + 1]);
         }
      }
   }

   template <typename T> static void BubbleSortRecursive(T A[], size_t n) {
      if (n <= 1)
         return;
      for (int j = 0; j < n - 1; j++) {
         if (A[j + 1] < A[j])
            Swap(&A[j], &A[j + 1]);
      }
      BubbleSortRecursive(A, n - 1);
   }

   template <typename T> static void BubbleSortEnhanced(T A[], size_t n) {
      size_t i, j;
      bool swapHappened = true;
      for (i = 0; swapHappened; i++) {
         swapHappened = false;
         for (j = 0; j < n - 1 - i; j++) {
            if (A[j + 1] < A[j]) {
               Swap(&A[j], &A[j + 1]);
               swapHappened = true;
            }
         }
      }
   }

   template <typename T>
   static void BubbleSortEnhancedRecursive(T A[], size_t n) {
      bool swapHappened = false;
      for (int j = 0; j < n - 1; j++) {
         if (A[j + 1] < A[j]) {
            Swap(&A[j], &A[j + 1]);
            swapHappened = true;
         }
      }
      if (swapHappened) {
         BubbleSortEnhancedRecursive(A, n - 1);
      }
   }

   template <typename T> static void InsertionSort(T A[], size_t n) {
      size_t i, j;
      T temp;
      for (i = 1; i < n; i++) {
         temp = A[i];
         for (j = i; j >= 1 && A[j - 1] > temp; j--)
            A[j] = A[j - 1];
         A[j] = temp;
      }
   }

   template <typename T>
   static void InsertionSortRecursiveInternal(T A[], size_t n, int i) {
      // variant wih tail recursion
      size_t j;
      T temp;
      if (i >= n)
         return;
      temp = A[i];
      for (j = i; j >= 1 && A[j - 1] > temp; j--)
         A[j] = A[j - 1];
      A[j] = temp;
      InsertionSortRecursiveInternal(A, n, i + 1);
   }

   template <typename T>
   static void InsertionSortRecursiveInternalAlternative(T A[], size_t n) {
      // no tail recursion
      size_t j;
      T temp;
      if (n <= 1)
         return;
      InsertionSortRecursiveInternalAlternative(A, n - 1);
      temp = A[n];
      for (j = n; j >= 1 && A[j - 1] > temp; j--)
         A[j] = A[j - 1];
      A[j] = temp;
   }

   template <typename T> static void InsertionSortRecursive(T A[], size_t n) {
#if 1
      InsertionSortRecursiveInternalAlternative(A, n);
#else
      InsertionSortRecursiveInternal(A, n, 1);
#endif
   }

   template <typename T> static void ShellSort(T A[], size_t n) {
      size_t i, j, step;
      T temp;
      for (step = n / 2; step > 0; step /= 2) {
         for (i = step; i < n; i++) {
            temp = A[i];
            for (j = i; j >= step && A[j - step] > temp; j -= step) {
               A[j] = A[j - step];
            }
            A[j] = temp;
         }
      }
   }

   // Merge sort

   template <typename T>
   static void MergeArrays(T A[], T helperArray[], size_t leftPosition,
                           size_t rightPosition, size_t rightEnd) {
      size_t i, leftEnd, numOfElements, helperPosition;
      leftEnd = rightPosition - 1;
      helperPosition = leftPosition;
      numOfElements = rightEnd - leftPosition + 1;
      while (leftPosition <= leftEnd && rightPosition <= rightEnd) {
         if (A[leftPosition] <= A[rightPosition])
            helperArray[helperPosition++] = A[leftPosition++];
         else
            helperArray[helperPosition++] = A[rightPosition++];
      }
      while (leftPosition <= leftEnd)
         helperArray[helperPosition++] =
             A[leftPosition++]; // copy the remainder of the first half
      while (rightPosition <= rightEnd)
         helperArray[helperPosition++] =
             A[rightPosition++]; // copy the remainder of the second half
      for (i = 0; i < numOfElements; i++, rightEnd--)
         A[rightEnd] = helperArray[rightEnd]; // copy temp array back to the
                                              // original array
   }

   template <typename T>
   static void MergeRecursive(T A[], T helperArray[], size_t left,
                              size_t right) {
      size_t middle;
      if (left < right) {
         middle = (left + right) / 2;
         MergeRecursive(A, helperArray, left, middle);
         MergeRecursive(A, helperArray, middle + 1, right);
         MergeArrays(A, helperArray, left, middle + 1, right);
      }
   }

 public:
   template <typename T> static void MergeSort(T A[], size_t n) {
      T *helperArray;
      helperArray = new (nothrow) T[n];
      if (helperArray != nullptr) {
         MergeRecursive(A, helperArray, 0, n - 1);
         delete[] helperArray;
      } else
         throw bad_alloc();
   }

   // auxiliary functions

   template <typename T> static void checkSort(T A[], size_t n) {
      for (int i = 1; i < n; i++) {
         if (A[i] < A[i - 1]) {
            cout << "Sort failed!!!" << endl;
            return;
         }
      }
      cout << "Sort OK." << endl;
   }

   template <typename T>
   static void testSort(void (*sort)(T A[], size_t n), T A[], size_t n,
                        string sortName) {
      StopWatch s;
      T tempArray[n];
      memcpy(tempArray, A, n * sizeof(int));
      // cout << "Array before " << sortName << ": ";
      // printArray<int>(tempArray, n);
      s.reset();
      sort(tempArray, n);
      cout << sortName << ": " << s.elapsedSeconds() << " secs. ";
      checkSort(tempArray, n);
      // cout << "Array after " << sortName << ": ";
      // printArray<int>(tempArray, n);
      s.reset();
      sort(tempArray, n);
      cout << sortName << " of sorted array: " << s.elapsedSeconds()
           << " secs. ";
      checkSort(tempArray, n);
   }
};

int main(void) {
   try {
      // int A[] = {4, 3, 5, 2, 1, 6, 7, 9, 8};
      // constexpr auto n = sizeof(A) / sizeof(int);
      int n;
      cout << "Number of array elements: ";
      cin >> n;
      int A[n];
      for (int i = 0; i < n; i++) {
         A[i] = rand() % n;
      }
      Sorts::testSort(Sorts::SelectionSort, A, n, "Selection sort");
      Sorts::testSort(Sorts::SelectionSortRecursive, A, n,
                      "Selection sort recursive");
      Sorts::testSort(Sorts::BubbleSort, A, n, "Bubble sort");
      Sorts::testSort(Sorts::BubbleSortRecursive, A, n,
                      "Bubble sort recursive");
      Sorts::testSort(Sorts::BubbleSortEnhanced, A, n, "Bubble sort enhanced");
      Sorts::testSort(Sorts::BubbleSortEnhancedRecursive, A, n,
                      "Bubble sort enhanced recursive");
      Sorts::testSort(Sorts::InsertionSort, A, n, "Insertion sort");
      Sorts::testSort(Sorts::InsertionSortRecursive, A, n,
                      "Insertion sort recursive");
      Sorts::testSort(Sorts::ShellSort, A, n, "Shell sort");
      Sorts::testSort(Sorts::MergeSort, A, n, "Merge sort");
   } catch (exception &e) {
      cerr << e.what();
   }
   return 0;
}
