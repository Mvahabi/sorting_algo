#include "insert.h"

#include "stats.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//elements one at a time, placing them in their correct, ordered position.
void insertion_sort(Stats *stats, uint32_t *A, uint32_t n) {
    for (uint32_t step = 1; step < n; step++) {
        uint32_t temp = move(stats, A[step]);
        uint32_t j = step;

        while (j > 0 && (cmp(stats, temp, A[j - 1]) == -1)) {
            uint32_t mv = move(stats, A[j - 1]);
            A[j] = mv;
            j--;
        }
        A[j] = move(stats, temp);
    }
}
