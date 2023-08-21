#include "stats.h"

#include <stdint.h>
#include <stdio.h>

// partion divides arrays into two sub-arrays by selecting an
//element from the array and designating it as a pivot.

int partition(Stats *stats, uint32_t *A, uint32_t low, uint32_t high) {
    uint32_t i = (low - 1);

    for (uint32_t j = low; j <= high - 1; j++) {
        if (cmp(stats, A[j - 1], A[high - 1]) == -1) {
            i++;
            swap(stats, &A[i - 1], &A[j - 1]);
        }
    }
    swap(stats, &A[i], &A[high - 1]);
    return (i + 1);
}

//A recursive helper function for Quicksort
void quick_sorter(Stats *stats, uint32_t *A, uint32_t low, uint32_t high) {
    if (low < high) {
        uint32_t p = partition(stats, A, low, high);
        quick_sorter(stats, A, low, p - 1);
        quick_sorter(stats, A, p + 1, high);
    }
}

//e operates on 1-based indexing, subtracting one to account for 0-based indexing
//whenever array elements are accessed.
void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {
    quick_sorter(stats, A, 1, n);
}
