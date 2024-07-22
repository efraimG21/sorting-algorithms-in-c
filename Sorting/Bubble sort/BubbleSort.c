// BubbleSort.c
// Sorting algorithms in C

#include <assert.h>
#include <stddef.h>

#include "BubbleSort.h"
#include "ComparisonResult.h"
#include "GenericVector.h"

/**
 * @brief Sorts a generic vector using the Bubble Sort algorithm.
 *
 * Bubble Sort is a simple comparison-based sorting algorithm. It works by repeatedly
 * stepping through the vector, comparing adjacent elements, and swapping them if they
 * are in the wrong order. Each pass through the vector moves the next largest element
 * to its correct position. The process continues until the vector is sorted.
 *
 * Time Complexity:
 * - Best Case: O(n) when the vector is already sorted. The algorithm makes a single pass without performing any swaps.
 * - Average Case: O(n^2) where n is the number of elements. This occurs when the vector is unordered.
 * - Worst Case: O(n^2) when the vector is sorted in reverse order.
 *
 * Space Complexity:
 * - O(1) because Bubble Sort is an in-place sorting algorithm, meaning it requires a constant amount of extra space.
 *
 * @param vec Pointer to the generic vector to be sorted.
 * @param compareFunc Function pointer to the comparison function used to determine the order of items.
 */


void BubbleSort(GenVector_t* vec, ComparisonFunc compareFunc) {
    assert(vec != NULL);
    assert(compareFunc != NULL);

    size_t numItems;
    if (GenVectorItemsNum(vec, &numItems) != 0) {
        // Handle error: could not get number of items
        return;
    }

    if (numItems < 2) {
        // No need to sort if the vector has less than 2 items
        return;
    }

    int swapped;

    for (size_t i = 1; i <= numItems ; ++i) {
        swapped = 1;
        for (size_t j = 1; j <= numItems - i; ++j) {
            void* firstItem;
            void* secondItem;

            if (GenVectorGet(vec, j, &firstItem) != 0 ||
                GenVectorGet(vec, j + 1, &secondItem) != 0) {
                // Handle error: could not get items
                return;
            }

            if (compareFunc(firstItem, secondItem) == GREATER_THAN) {
                if (GenVectorSet(vec, j, secondItem) != 0 ||
                    GenVectorSet(vec, j + 1, firstItem) != 0) {
                    // Handle error: could not set items
                    return;
                }
                swapped = 1;
            }
        }

        if (!swapped) {
            // No swaps were made, so the vector is sorted
            break;
        }
    }
}
