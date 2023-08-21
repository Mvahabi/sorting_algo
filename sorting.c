#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PRINT    100
#define BIT_MASK 30
#define OPTIONS  "haeisqr:n:p:"
#define SEED     13371453
#define SIZE     100

/* This entire main function was a built up
 from the TA section video on yuja. 
 it basically takes an indirect user input
 when they run "sorting", and returns
 the  outputs that was set using switch
 case tools. every c files were imported from
 their designated  header files  that declares 
 all the functions in their C  file and therfore
 used within different user options. */

int main(int argc, char **argv) {
    //initializing variables
    Set s = empty_set();
    uint32_t seed = SEED;
    uint32_t size = SIZE;
    uint32_t print = PRINT;

    enum { HEAP, INSERTION, SHELL, QUICK };
    //initializing stats
    Stats stats;
    stats.moves = 0;
    stats.compares = 0;
    //initializing user interface work
    int opt = 0;
    int no_input = true;
    bool h_flag = false;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        no_input = false;
        switch (opt) {
        case 'h':
            printf("OPTIONS\n");
            printf("  -h              display program help and usage.\n");
            printf("  -a              enable all sorts.\n");
            printf("  -e              enable Heap Sort.\n");
            printf("  -i              enable Insertion Sort.\n");
            printf("  -s              enable Shell Sort.\n");
            printf("  -q              enable Quick Sort.\n");
            printf("  -n length       specify number of array elements (default: 100).\n");
            printf("  -p elements     specify number of elements to print (default: 100).\n");
            printf("  -r seed         specify random seed (default: 13371453).\n");
            h_flag = true;
            break;
            //applying every algorithm files into a set
        case 'a':
            s = insert_set(HEAP, s);
            s = insert_set(SHELL, s);
            s = insert_set(INSERTION, s);
            s = insert_set(QUICK, s);
            break;
            //applying individual files into personal sets
        case 'e': s = insert_set(HEAP, s); break;
        case 'i': s = insert_set(INSERTION, s); break;
        case 's': s = insert_set(SHELL, s); break;
        case 'q': s = insert_set(QUICK, s); break;
        case 'r': seed = strtoul(optarg, NULL, 10); break;
        case 'n': size = strtoul(optarg, NULL, 10); break;
        case 'p': print = strtoul(optarg, NULL, 10); break;
        }
    }
    //allocates personalized memory
    uint32_t *A = (uint32_t *) calloc(size, (sizeof(uint32_t)));

    srandom(seed);

    for (uint32_t i = 0; i < size; i++) {
        A[i] = random() & 0x3FFFFFFF;
    }

    if (h_flag || no_input) {

        printf("OPTIONS\n");
        printf("  -h              display program help and usage.\n");
        printf("  -a              enable all sorts.\n");
        printf("  -e              enable Heap Sort.\n");
        printf("  -i              enable Insertion Sort.\n");
        printf("  -s              enable Shell Sort.\n");
        printf("  -q              enable Quick Sort.\n");
        printf("  -n length       specify number of array elements (default: 100).\n");
        printf("  -p elements     specify number of elements to print (default: 100).\n");
        printf("  -r seed         specify random seed (default: 13371453).\n");
    }
    //operates the heap sorting and prints out the output in 5 columns
    if (member_set(HEAP, s)) {
        srandom(seed);
        for (uint32_t i = 0; i < size; i++) {
            A[i] = random() & 0x3FFFFFFF;
        }
        reset(&stats);
        heap_sort(&stats, A, size);
        printf("Heap Sort, %u elements, %" PRIu64 " moves, %" PRIu64 " compares\n", size,
            stats.moves, stats.compares);
        for (uint32_t k = 0; k < print; k++) {
            if (k && !(k % 5)) {
                printf("\n");
            }
            printf("%13" PRIu32, A[k]);
        }
        printf("\n");
    }
    //operates the shell sorting and prints out the output in 5 columns
    if (member_set(SHELL, s)) {
        srandom(seed);
        for (uint32_t i = 0; i < size; i++) {
            A[i] = random() & 0x3FFFFFFF;
        }
        reset(&stats);
        shell_sort(&stats, A, size);
        printf("Shell Sort, %u elements, %" PRIu64 " moves, %" PRIu64 " compares\n", size,
            stats.moves, stats.compares);
        for (uint32_t k = 0; k < print; k++) {
            if (k && !(k % 5)) {
                printf("\n");
            }
            printf("%13" PRIu32, A[k]);
        }
        printf("\n");
    }
    //operates the insert sorting and prints out the output in 5 columns
    if (member_set(INSERTION, s)) {
        srandom(seed);
        for (uint32_t i = 0; i < size; i++) {
            A[i] = random() & 0x3FFFFFFF;
        }
        reset(&stats);
        insertion_sort(&stats, A, size);
        printf("Insertion Sort, %u elements, %" PRIu64 " moves, %" PRIu64 " compares\n", size,
            stats.moves, stats.compares);
        for (uint32_t k = 0; k < print; k++) {
            if (k && !(k % 5)) {
                printf("\n");
            }
            printf("%13" PRIu32, A[k]);
        }
        printf("\n");
    }
    //operates the quick sorting and prints out the output in 5 columns
    if (member_set(QUICK, s)) {
        srandom(seed);
        for (uint32_t i = 0; i < size; i++) {
            A[i] = random() & 0x3FFFFFFF;
        }
        reset(&stats);
        quick_sort(&stats, A, size);
        printf("Quick Sort, %u elements, %" PRIu64 " moves, %" PRIu64 " compares\n", size,
            stats.moves, stats.compares);
        for (uint32_t k = 0; k < print; k++) {
            if (k && !(k % 5)) {
                printf("\n");
            }
            printf("%13" PRIu32, A[k]);
        }
        printf("\n");
    }
    //deallocate the memory
    free(A);
    return 0;
}
