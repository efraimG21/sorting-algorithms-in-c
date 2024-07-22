//
//  InsertionSort.h
//  sorting-algorithms-in-c
//


#ifndef InsertionSort_h
#define InsertionSort_h

#include "ComparisonResult.h"

// Function pointer type for comparison functions
typedef ComparisonResult (*ComparisonFunc)(const void*, const void*);

/**
 * @brief Sorts a generic vector using the Insertion Sort algorithm.
 *
 * Insertion Sort is an in-place, comparison-based sorting algorithm. It builds the sorted array one item at a time by
 * repeatedly picking the next item and inserting it into the correct position in the already sorted part of the array.
 * It is particularly efficient for small datasets or nearly sorted data.
 *
 * @param vec Pointer to the generic vector to be sorted.
 * @param comFunc Function pointer to the comparison function used to determine the order of items.
 */
void InsertionSort(GenVector_t* vec, ComparisonFunc comFunc);

#endif /* InsertionSort_h */
