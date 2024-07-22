//
//  UnitTest.c
//  sorting-algorithms-in-c
//

#include <stdio.h>
#include <stdlib.h>
#include "GenericVector.h"
#include "SelectionSort.h"
#include "ComparisonResult.h"


void SelectionSortTesting(void);
ComparisonResult CompareInt(const void* a, const void* b);
void RunSelectionSortTest(const char* testName, int* array, size_t size);

int main(void) {
    SelectionSortTesting();
    return 0;
}

// Test function for Selection Sort
void SelectionSortTesting(void) {
    // Test case 1: Already sorted array (even length)
    int sortedArrayEven[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    RunSelectionSortTest("Already sorted array (even length)", sortedArrayEven, sizeof(sortedArrayEven) / sizeof(sortedArrayEven[0]));

    // Test case 2: Unsorted array (even length)
    int unsortedArrayEven[] = {5, 3, 8, 1, 2, 7, 6, 4, 10, 9};
    RunSelectionSortTest("Unsorted array (even length)", unsortedArrayEven, sizeof(unsortedArrayEven) / sizeof(unsortedArrayEven[0]));

    // Test case 3: Array with duplicates (even length)
    int arrayWithDuplicatesEven[] = {5, 3, 8, 1, 2, 7, 8, 3, 10, 10};
    RunSelectionSortTest("Array with duplicates (even length)", arrayWithDuplicatesEven, sizeof(arrayWithDuplicatesEven) / sizeof(arrayWithDuplicatesEven[0]));

    // Test case 4: Empty array
    int emptyArray[] = {};
    RunSelectionSortTest("Empty array", emptyArray, 0);

    // Test case 5: Single element
    int singleElementArray[] = {42};
    RunSelectionSortTest("Single element", singleElementArray, sizeof(singleElementArray) / sizeof(singleElementArray[0]));

    // Test case 6: Already sorted array (odd length)
    int sortedArrayOdd[] = {1, 2, 3, 4, 5, 6, 7};
    RunSelectionSortTest("Already sorted array (odd length)", sortedArrayOdd, sizeof(sortedArrayOdd) / sizeof(sortedArrayOdd[0]));

    // Test case 7: Unsorted array (odd length)
    int unsortedArrayOdd[] = {7, 3, 5, 1, 6, 2, 4};
    RunSelectionSortTest("Unsorted array (odd length)", unsortedArrayOdd, sizeof(unsortedArrayOdd) / sizeof(unsortedArrayOdd[0]));

    // Test case 8: Array with duplicates (odd length)
    int arrayWithDuplicatesOdd[] = {5, 3, 8, 1, 2, 7, 5};
    RunSelectionSortTest("Array with duplicates (odd length)", arrayWithDuplicatesOdd, sizeof(arrayWithDuplicatesOdd) / sizeof(arrayWithDuplicatesOdd[0]));
}

// Comparator function for integers
ComparisonResult CompareInt(const void* a, const void* b) {
    int intA = *(const int*)a;
    int intB = *(const int*)b;

    if (intA < intB) return LESS_THAN;
    if (intA > intB) return GREATER_THAN;
    return EQUAL;
}

// Print function for integers
void PrintInt(const void* item) {
    printf("%d ", *(const int*)item);
}

// Helper function to print the vector
void PrintVector(GenVector_t* vec) {
    size_t numItems;
    GenVectorItemsNum(vec, &numItems);
    printf("Vector: ");
    for (size_t i = 1; i <= numItems; ++i) {
        int* item;
        GenVectorGet(vec, i, (void**)&item);
        printf("%d ", *item);
    }
    printf("\n");
}

// Helper function to run a sorting test for Selection Sort
void RunSelectionSortTest(const char* testName, int* array, size_t size) {
    printf("Test Case: %s\n", testName);
    
    GenVector_t* genVec = GenVectorCreate(size, sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        GenVectorAdd(genVec, &array[i]);
    }

    printf("Before sorting: ");
    PrintVector(genVec);

    SelectionSort(genVec, CompareInt);

    printf("After sorting: ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);
}
