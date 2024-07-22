// BubbleSort.c
// Sorting algorithms in C

#include <assert.h>
#include <stddef.h>

#include "BubbleSort.h"
#include "GenericVector.h"

// Bubble Sort algorithm
// Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through
// the list, compares adjacent elements, and swaps them if they are in the wrong order.
// The pass through the list is repeated until the list is sorted.
// The algorithm gets its name because smaller elements "bubble" to the top of the list with each pass.


// * Time Complexity:
// * - Best Case: O(n) when the list is already sorted. The algorithm makes a single pass without swaps.
// * - Average Case: O(n^2) where n is the number of elements. This happens when the list is unordered.
// * - Worst Case: O(n^2) when the list is sorted in reverse order.
//
// * Space Complexity:
// * - O(1) because Bubble Sort is an in-place sorting algorithm, meaning it requires a constant amount of extra space.


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
