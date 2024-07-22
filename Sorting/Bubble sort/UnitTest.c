// UnitTest.c
// Sorting algorithms in C

#include <stdio.h>
#include <stdlib.h>
#include "GenericVector.h"
#include "BubbleSort.h"

void BubbleSortTesting(void);
int CompareInt(const void* a, const void* b);
void PrintVector(GenVector_t* vec);


int main(void) {
    BubbleSortTesting();
    return 0;
}

// Test function for BubbleSort
void BubbleSortTesting(void) {
    // Test case 1: Sorted array
    printf("Test Case 1: Already sorted array\n");
    GenVector_t* genVec = GenVectorCreate(10, 4);
    if (!genVec) {
        printf("Failed to create vector.\n");
        return;
    }

    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (size_t i = 0; i < sizeof(sortedArray) / sizeof(sortedArray[0]); ++i) {
        if (GenVectorAdd(genVec, &sortedArray[i]) != ERR_OK) {
            printf("Failed to add item to vector.\n");
            GenVectorDestroy(genVec);
            return;
        }
    }

    printf("Before sorting: ");
    PrintVector(genVec);

    BubbleSort(genVec, CompareInt);

    printf("After sorting:  ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);

    // Test case 2: Unsorted array
    printf("\nTest Case 2: Unsorted array\n");
    genVec = GenVectorCreate(10, 4);
    if (!genVec) {
        printf("Failed to create vector.\n");
        return;
    }

    int unsortedArray[] = {5, 3, 8, 1, 2, 7, 6, 4, 10, 9};
    for (size_t i = 0; i < sizeof(unsortedArray) / sizeof(unsortedArray[0]); ++i) {
        if (GenVectorAdd(genVec, &unsortedArray[i]) != ERR_OK) {
            printf("Failed to add item to vector.\n");
            GenVectorDestroy(genVec);
            return;
        }
    }

    printf("Before sorting: ");
    PrintVector(genVec);

    BubbleSort(genVec, CompareInt);

    printf("After sorting:  ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);

    // Test case 3: Array with duplicates
    printf("\nTest Case 3: Array with duplicates\n");
    genVec = GenVectorCreate(10, 4);
    if (!genVec) {
        printf("Failed to create vector.\n");
        return;
    }

    int arrayWithDuplicates[] = {5, 3, 8, 1, 2, 7, 8, 3, 10, 10};
    for (size_t i = 0; i < sizeof(arrayWithDuplicates) / sizeof(arrayWithDuplicates[0]); ++i) {
        if (GenVectorAdd(genVec, &arrayWithDuplicates[i]) != ERR_OK) {
            printf("Failed to add item to vector.\n");
            GenVectorDestroy(genVec);
            return;
        }
    }

    printf("Before sorting: ");
    PrintVector(genVec);

    BubbleSort(genVec, CompareInt);

    printf("After sorting:  ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);

    // Test case 4: Empty array
    printf("\nTest Case 4: Empty array\n");
    genVec = GenVectorCreate(0, 4);
    if (!genVec) {
        printf("Failed to create vector.\n");
        return;
    }

    printf("Before sorting: ");
    PrintVector(genVec);

    BubbleSort(genVec, CompareInt);

    printf("After sorting:  ");
    PrintVector(genVec);
    GenVectorDestroy(genVec);

    // Test case 5: Single element
    printf("\nTest Case 5: Single element\n");
    genVec = GenVectorCreate(1, 4);
    if (!genVec) {
        printf("Failed to create vector.\n");
        return;
    }

    int singleElement = 42;
    if (GenVectorAdd(genVec, &singleElement) != ERR_OK) {
        printf("Failed to add item to vector.\n");
        GenVectorDestroy(genVec);
        return;
    }

    printf("Before sorting: ");
    PrintVector(genVec);

    BubbleSort(genVec, CompareInt);

    printf("After sorting:  ");
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
    if (GenVectorItemsNum(vec, &numItems) != ERR_OK) {
        printf("Error retrieving number of items.\n");
        return;
    }

    if (numItems == 0) {
        printf("Vector is empty.\n");
        return;
    }

    printf("Vector: ");
    for (size_t i = 0; i < numItems; ++i) {
        int* item;
        if (GenVectorGet(vec, i + 1, (void**)&item) != ERR_OK) {
            printf("Error retrieving item at index %zu.\n", i + 1);
            return;
        }
        printf("%d ", *item);
    }
    printf("\n");
}
