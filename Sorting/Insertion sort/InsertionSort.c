//
//  InsertionSort.c
//  sorting-algorithms-in-c
//

#include <assert.h>
#include "GenericVector.h"
#include "InsertionSort.h"

/**
 * @brief Sorts a generic vector using the Insertion Sort algorithm.
 *
 * Insertion Sort is a simple and intuitive sorting algorithm. The idea is to divide the vector into a sorted and an
 * unsorted region. Initially, the sorted region is empty and the unsorted region contains all items.
 * The algorithm repeatedly takes the first item from the unsorted region and inserts it into the correct position
 * in the sorted region.
 *
 * @param vec Pointer to the generic vector to be sorted.
 * @param comFunc Function pointer to the comparison function used to determine the order of items.
 *
 * Complexity:
 * - Best-case time complexity: O(n) when the vector is already sorted.
 * - Average-case time complexity: O(n^2) for a random arrangement of items.
 * - Worst-case time complexity: O(n^2) when the vector is sorted in reverse order.
 */
void InsertionSort(GenVector_t* vec, ComparisonFunc comFunc) {
    assert(vec);
    assert(comFunc);

    void* currentItem;
    void* comparisonItem;
    size_t sizeVec;

    // Get the number of items in the vector
    if (GenVectorItemsNum(vec, &sizeVec) != 0) {
        // Handle error: could not get number of items
        return;
    }

    // Iterate over each item starting from the second position
    for (size_t i = 1; i < sizeVec; ++i) {
        // Get the item to be inserted
        if (GenVectorGet(vec, i + 1, &currentItem) != 0) {
            // Handle error: could not get item
            return;
        }

        // Shift elements of the sorted part of the vector to the right
        size_t j = i + 1;
        while (j > 1) {
            if (GenVectorGet(vec, j - 1, &comparisonItem) != 0) {
                // Handle error: could not get item
                return;
            }

            if (comFunc(comparisonItem, currentItem) == GREATER_THAN) {
                // Move the item to the right
                if (GenVectorSet(vec, j, comparisonItem) != 0) {
                    // Handle error: could not set item
                    return;
                }
            } else {
                // Correct position found for currentItem
                break;
            }
            --j;
        }

        // Insert the currentItem into its correct position
        if (GenVectorSet(vec, j, currentItem) != 0) {
            // Handle error: could not set item
            return;
        }
    }
}
