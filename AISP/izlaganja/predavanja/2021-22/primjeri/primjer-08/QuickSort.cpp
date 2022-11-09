#include <iostream>
#define Cutoff (3)

template <typename T> static void InsertionSort(T A[], int n) {
   int i, j;
   T temp;
   for (i = 1; i < n; i++) {
      temp = A[i];
      for (j = i; j >= 1 && A[j - 1] > temp; j--)
         A[j] = A[j - 1];
      A[j] = temp;
   }
}

class QuickSort {
 private:
   template <typename T> static void Swap(T *left, T *right) {
      T temp = *left;
      *left = *right;
      *right = temp;
   }

   // QuickSort Pivot=Median
   template <typename T> static T medianOf3(T A[], size_t left, size_t right) {
      size_t middle = (left + right) / 2;
      if (A[left] > A[middle])
         Swap(&A[left], &A[middle]);
      if (A[left] > A[right])
         Swap(&A[left], &A[right]);
      if (A[middle] > A[right])
         Swap(&A[middle], &A[right]);
      // Now we have: A[left] <= A[middle] <= A[right]
      Swap(&A[middle], &A[right - 1]); // Hide pivot
      return A[right - 1];             // Return pivot
   }
   template <typename T>
   static void QSortMedianOf3(T A[], size_t left, size_t right) {
      size_t i, j;
      T pivot;
      if (left + Cutoff <= right) {
         pivot = medianOf3(A, left, right);
         i = left;
         j = right - 1;
         while (1) {
            while (A[++i] < pivot)
               ;
            while (A[--j] > pivot)
               ;
            if (i < j)
               Swap(&A[i], &A[j]);
            else
               break;
         }
         Swap(&A[i], &A[right - 1]); // Renew pivot
         QSortMedianOf3(A, left, i - 1);
         QSortMedianOf3(A, i + 1, right);
      } else {
         InsertionSort(
             A + left,
             right - left +
                 1); // If subarray is small sort it via Insertion sort
      }
   }

   // QuickSort Pivot=First element
   template <typename T>
   static void QSortFirstElement(T A[], size_t left, size_t right) {
      size_t i, j;
      i = left + 1;
      j = right;
      if (left >= right)
         return;
      while ((i <= j) && (i <= right) && (j > left)) {
         while ((A[i] < A[left]) && (i <= right))
            i++;
         while ((A[j] > A[left]) && (j > left))
            j--;
         if (i < j) {
            Swap(&A[i], &A[j]);
         }
      }
      if (i > right) { // stožer je najveći u polju
         Swap(&A[left], &A[right]);
         QSortFirstElement(A, left, right - 1);
      } else if (j <= left) { // stožer je najmanji u polju
         QSortFirstElement(A, left + 1, right);
      } else { // stožer je negdje u sredini
         Swap(&A[left], &A[j]);
         QSortFirstElement(A, left, j - 1);
         QSortFirstElement(A, j + 1, right);
      }
   }

 public:
   enum PivotStrategy { FirstElement = 1, MedianOf3 };

   template <typename T>
   static void Sort(T A[], size_t n, PivotStrategy strategy) {
      if (strategy == PivotStrategy::MedianOf3)
         QSortMedianOf3(A, 0, n - 1);
      else if (strategy == PivotStrategy::FirstElement)
         QSortFirstElement(A, 0, n - 1);
   }
};

template <typename T> static void printArray(T A[], size_t n) {
   for (auto i = 0; i < n; i++) {
      std::cout << A[i] << " ";
   }
   std::cout << std::endl;
}

int main(void) {
   try {
      int A[] = {4, 3, 5, 2, 1, 6, 7, 9, 8};
      constexpr auto n = sizeof(A) / sizeof(int);
      int tempArray[n * sizeof(int)];

      std::cout << "Array before Quick sort (median of 3):";
      memcpy(tempArray, A, n * sizeof(int));
      printArray<int>(tempArray, n);
      std::cout << "Array after Quick sort (median of 3):";
      QuickSort::Sort<int>(tempArray, n, QuickSort::PivotStrategy::MedianOf3);
      printArray<int>(tempArray, n);

      std::cout << "Array before Quick sort (first element):";
      memcpy(tempArray, A, n * sizeof(int));
      printArray<int>(tempArray, n);
      std::cout << "Array after Quick sort (first element):";
      QuickSort::Sort<int>(tempArray, n,
                           QuickSort::PivotStrategy::FirstElement);
      printArray<int>(tempArray, n);
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   std::cin.get();
   return 0;
}
