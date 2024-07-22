// BubbleSort.h
// Sorting algorithms in C

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "GenericVector.h"
#include "ComparisonResult.h"

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

