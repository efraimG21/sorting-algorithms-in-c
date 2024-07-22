//
//  UnitTest.c
//  sorting-algorithms-in-c
//


#include <stdio.h>
#include <stdlib.h>
#include "GenericVector.h"
#include "ComparisonResult.h"
#include "InsertionSort.h"

void InsertionSortTesting(void);
int CompareInt(const void* a, const void* b);
void PrintVector(GenVector_t* vec);

int main(void) {
    // Run Insertion Sort tests
    InsertionSortTesting();
    
    return 0;
}

// Test function for InsertionSort
void InsertionSortTesting(void) {
    // Test case 1: Sorted array
    printf("Test Case 1: Already sorted array (Insertion Sort)\n");
    GenVector_t* genVec = GenVectorCreate(10, sizeof(int));
    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (size_t i = 0; i < sizeof(sortedArray) / sizeof(sortedArray[0]); ++i) {
        GenVectorAdd(genVec, &sortedArray[i]);
    }
    printf("Before sorting: ");
    PrintVector(genVec);
    InsertionSort(genVec, CompareInt);
    printf("After sorting: ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);

    // Test case 2: Unsorted array
    printf("Test Case 2: Unsorted array (Insertion Sort)\n");
    genVec = GenVectorCreate(10, sizeof(int));
    int unsortedArray[] = {5, 3, 8, 1, 2, 7, 6, 4, 10, 9};
    for (size_t i = 0; i < sizeof(unsortedArray) / sizeof(unsortedArray[0]); ++i) {
        GenVectorAdd(genVec, &unsortedArray[i]);
    }
    printf("Before sorting: ");
    PrintVector(genVec);
    InsertionSort(genVec, CompareInt);
    printf("After sorting: ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);

    // Test case 3: Array with duplicates
    printf("Test Case 3: Array with duplicates (Insertion Sort)\n");
    genVec = GenVectorCreate(10, sizeof(int));
    int arrayWithDuplicates[] = {5, 3, 8, 1, 2, 7, 8, 3, 10, 10};
    for (size_t i = 0; i < sizeof(arrayWithDuplicates) / sizeof(arrayWithDuplicates[0]); ++i) {
        GenVectorAdd(genVec, &arrayWithDuplicates[i]);
    }
    printf("Before sorting: ");
    PrintVector(genVec);
    InsertionSort(genVec, CompareInt);
    printf("After sorting: ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);

    // Test case 4: Empty array
    printf("Test Case 4: Empty array (Insertion Sort)\n");
    genVec = GenVectorCreate(0, sizeof(int));
    printf("Before sorting: ");
    PrintVector(genVec);
    InsertionSort(genVec, CompareInt);
    printf("After sorting: ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);

    // Test case 5: Single element
    printf("Test Case 5: Single element (Insertion Sort)\n");
    genVec = GenVectorCreate(1, sizeof(int));
    int singleElement = 42;
    GenVectorAdd(genVec, &singleElement);
    printf("Before sorting: ");
    PrintVector(genVec);
    InsertionSort(genVec, CompareInt);
    printf("After sorting: ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);
}

// Comparator function for integers
int CompareInt(const void* a, const void* b) {
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
    for (size_t i = 0; i < numItems; ++i) {
        int* item;
        GenVectorGet(vec, i + 1, (void**)&item);
        printf("%d ", *item);
    }
    printf("\n");
}

