// BubbleSort.h
// Sorting algorithms in C

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "GenericVector.h"

// Enum to represent comparison results
typedef enum {
    LESS_THAN = -1,
    EQUAL,
    GREATER_THAN
} ComparisonResult;

// Type for comparison functions
typedef ComparisonResult (*ComparisonFunc)(const void*, const void*);

/**
 * @brief Sorts a vector using the Bubble Sort algorithm.
 *
 * @param vec A pointer to the vector to be sorted.
 * @param compareFunc A function pointer for comparing two elements.
 */
void BubbleSort(GenVector_t* vec, ComparisonFunc compareFunc);

#endif /* BUBBLESORT_H */

