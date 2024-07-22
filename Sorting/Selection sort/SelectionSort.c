//
//  SelectionSort.c
//  sorting-algorithms-in-c
//


#include <assert.h>
#include "SelectionSort.h"
#include "GenericVector.h"
#include "ComparisonResult.h"

/**
 * Selection Sort Algorithm
 *
 * Selection Sort is a simple comparison-based sorting algorithm. It divides the input list into two parts:
 * a sorted subset and an unsorted subset. Initially, the sorted subset is empty and the unsorted subset contains
 * all the items. The algorithm repeatedly selects the smallest (or largest) element from the unsorted subset and
 * moves it to the end of the sorted subset.
 *
 * The process is repeated until the entire list is sorted.
 *
 * Steps:
 * 1. Iterate over the entire list.
 * 2. For each position, find the smallest (or largest) item from the remaining unsorted portion.
 * 3. Swap the found item with the item at the current position.
 * 4. Move to the next position and repeat until the entire list is sorted.
 *
 * Time Complexity:
 * - Best Case: O(n^2), occurs when the list is already sorted. Selection Sort always performs O(n^2) comparisons
 *   regardless of the initial order of elements.
 * - Average Case: O(n^2), for an average unordered list.
 * - Worst Case: O(n^2), when the list is sorted in reverse order.
 *
 * Space Complexity:
 * - O(1), as Selection Sort is an in-place sorting algorithm and requires a constant amount of additional memory.
 *
 * @param vec The vector to be sorted.
 * @param comFunc The comparison function to determine the order of elements.
 */
void SelectionSort(GenVector_t* vec, ComparisonFunc comFunc)
{
    assert(vec && comFunc);

    void* minItem;
    void* curItem;
    void* orgItem;
    int indexMinItem;
    size_t sizeVec;
    
    if (GenVectorItemsNum(vec, &sizeVec) != 0) {
        // Handle error: could not get the number of items
        return;
    }

    for (size_t i = 1; i <= sizeVec; ++i)
    {
        indexMinItem = i;
        if (GenVectorGet(vec, indexMinItem, &orgItem) != 0) {
            // Handle error: could not get item
            return;
        }
        minItem = orgItem;

        for (size_t j = i + 1; j <= sizeVec; ++j)
        {
            if (GenVectorGet(vec, j, &curItem) != 0) {
                // Handle error: could not get item
                return;
            }

            if (comFunc(minItem, curItem) == GREATER_THAN)
            {
                minItem = curItem;
                indexMinItem = j;
            }
        }

        if (indexMinItem != i)
        {
            if (GenVectorSet(vec, i, minItem) != 0 ||
                GenVectorSet(vec, indexMinItem, orgItem) != 0) {
                // Handle error: could not set items
                return;
            }
        }
    }
}
