#include "heap.h"

#include "stats.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*Build heap: ordering the array elements such that they obey the 
 constraints of a max or min heap*/
void buildHeap(Stats *stats, uint32_t *A, uint32_t n, uint32_t i) {
    uint32_t largest = i;
    uint32_t l = 2 * i + 1;
    uint32_t r = 2 * i + 2;

    if ((cmp(stats, l, n) == -1) && (cmp(stats, A[l], A[largest])) == 1)
        largest = l;

    if ((cmp(stats, r, n) == -1) && (cmp(stats, A[r], A[largest])) == 1)
        largest = r;

    if (largest != i) {
        swap(stats, &A[i], &A[largest]);
        buildHeap(stats, A, n, largest);
    }
}

// Heap sort: utilizes a heap to sort elements
void heap_sort(Stats *stats, uint32_t *A, uint32_t n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        buildHeap(stats, A, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(stats, &A[0], &A[i]);
        buildHeap(stats, A, i, 0);
    }
}
