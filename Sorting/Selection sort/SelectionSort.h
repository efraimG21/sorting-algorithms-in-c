//
//  SelectionSort.h
//  sorting-algorithms-in-c
//


#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "ComparisonResult.h"
#include "GenericVector.h"

// Type for comparison functions
typedef ComparisonResult (*ComparisonFunc)(const void*, const void*);

/**
 * Sorts a vector using the Selection Sort algorithm.
 *
 * @param vec The vector to be sorted.
 * @param comFunc The comparison function to determine the order of elements.
 */
void SelectionSort(GenVector_t* vec, ComparisonFunc comFunc);

#endif /* SELECTIONSORT_H */
