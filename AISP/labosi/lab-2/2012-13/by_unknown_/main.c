#include "sortovi.h"
#include "test.h"
#include <stdio.h>

int main() {
    const char* bubble = "buble.txt";
    const int bubble_kraj = 12500;
    const char* bubble_out = "buble_out.txt";

    const char* selection = "selection.txt";
    const int selection_kraj = 12500;
    const char* selection_out = "selection_out.txt";

    const char* quick = "quick.txt";
    const int quick_kraj = 112500;
    const char* quick_out = "quick_out.txt";

    const char* merges = "merge.txt";
    const int merges_kraj = 112500;
    const char* merges_out = "merges_out.txt";

    const char* permutacija = "permute.txt";
    const int permutaija_kraj = 11;
    const char* permutacija_out = "permute.out";

    // bubble sort
    generator_sort(bubble, bubble_kraj);
    test_sort(bubble_sort, bubble_kraj, 30, 0, 250, 0, bubble, bubble_out);

    // selection sort
    generator_sort(selection, selection_kraj);
    test_sort(selection_sort, selection_kraj, 50, 0, 250, 0, selection, selection_out);

    // quicsort
    generator_sort(quick, quick_kraj);
    test_sort(quicksort, quick_kraj, 150, 0, 1500, 0, quick, quick_out);

    // mergesort
    generator_sort(merges, merges_kraj);
    test_sort(bubble_sort, bubble_kraj, 120, 0, 1500, 0, merges, merges_out);

    // permute
    generator_permute(permutacija, permutaija_kraj);
    test_permute(permutaija_kraj, 40, 2, 1, 0, permutacija, permutacija_out);

    return 0;
}
