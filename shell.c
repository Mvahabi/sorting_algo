#include "shell.h"

#include "stats.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>

/* Each iteration of Shell Sort
decreases the gap until a gap, distance between two pairs of 
elements, of 1 is used. At this point, the elements are sorted. */

void shell_sort(Stats *stats, uint32_t *A, uint32_t n) {

    for (uint32_t random = log(3 + 2 * n) / log(3); random > 0; random--) {
        uint32_t gap = floor((pow(3, random) - 1) / 2);
        for (uint32_t i = gap; i < n; i += 1) {
            uint32_t temp = move(stats, A[i]);
            uint32_t j;
            for (j = i; j >= gap && (cmp(stats, A[j - gap], temp) == 1); j -= gap) {
                A[j] = move(stats, A[j - gap]);
            }
            A[j] = move(stats, temp);
        }
    }
}
