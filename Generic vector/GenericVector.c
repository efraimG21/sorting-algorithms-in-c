//
//  GenericVector.c
//  data structures in c
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ADTErr.h"
#include "GenericVector.h"

#define REALLOC_FACTOR 2

// Definition of the generic vector structure
struct GenVector
{
    void**  items;         // Array to store items
    size_t  originalSize;  // Initial size of the vector
    size_t  blockSize;     // Block size for reallocation
    size_t  currSize;      // Current size of the vector
    size_t  nItems;        // Number of items in the vector
};

// Function to create a new generic vector
GenVector_t* GenVectorCreate(size_t size, size_t blockSize)
{
    GenVector_t* vec;

    // Validate input parameters
    if ((size == 0) && (blockSize == 0))
    {
        return NULL;
    }

    // Allocate memory for the vector structure
    vec = (GenVector_t*)malloc(sizeof(GenVector_t));
    if (!vec)
    {
        return NULL;
    }

    // Allocate memory for the items array
    vec->items = (void**)malloc(sizeof(void*) * size);
    if (!vec->items)
    {
        free(vec);
        return NULL;
    }

    // Initialize vector properties
    vec->currSize = size;
    vec->originalSize = size;
    vec->blockSize = blockSize;
    vec->nItems = 0;

    return vec;
}

// Function to destroy a generic vector
void GenVectorDestroy(GenVector_t* vec)
{
    assert(vec);

    // Free memory allocated for the items array and the vector structure
    free(vec->items);
    free(vec);
}

// Function to add an item to the generic vector
ADTErr GenVectorAdd(GenVector_t* vec, void* item)
{
    void** tmp;

    assert(vec);

    // Validate item
    if (!item)
    {
        return ERR_NOT_INITIALIZED;
    }

    // Check if reallocation is needed
    if (vec->nItems == vec->currSize)
    {
        // Check for overflow condition
        if (vec->blockSize == 0)
        {
            return ERR_OVERFLOW;
        }

        // Reallocate the items array with an increased size
        tmp = (void**)realloc(vec->items, sizeof(void*) * (vec->currSize + vec->blockSize));

        // Check for reallocation failure
        if (NULL == tmp)
        {
            return ERR_REALLOCATION_FAILED;
        }

        vec->items = tmp;
        vec->currSize += vec->blockSize;
    }

    // Add the item to the vector and update the number of items
    *(vec->items + vec->nItems) = item;
    ++vec->nItems;

    return ERR_OK;
}

// Function to delete the last item from the generic vector
ADTErr GenVectorDelete(GenVector_t* vec, void** item)
{
    void** tmp;

    assert(vec && item);

    // Check for underflow condition
    if (vec->nItems == 0)
    {
        return ERR_UNDERFLOW;
    }

    // Check if reallocation is needed
    if ((vec->currSize > vec->originalSize) &&
        (vec->nItems <= (vec->currSize - (vec->blockSize * REALLOC_FACTOR))))
    {
        // Reallocate the items array with a decreased size
        tmp = (void**)realloc(vec->items, sizeof(void*) * (vec->currSize - vec->blockSize));

        // Check for reallocation failure
        if (!tmp)
        {
            return ERR_REALLOCATION_FAILED;
        }

        vec->items = tmp;
        vec->currSize -= vec->blockSize;
    }

    // Update the item pointer and remove the last item from the vector
    *item = *(vec->items + vec->nItems - 1);
    --vec->nItems;

    return ERR_OK;
}

// Function to get an item from the generic vector by index
ADTErr GenVectorGet(GenVector_t* vec, size_t index, void** item)
{
    if (!vec || !item)
    {
        return ERR_NOT_INITIALIZED;
    }

    // Check for a valid index
    if (index > vec->nItems || index < 1)
    {
        return (ERR_WRONG_INDEX);
    }

    // Update the item pointer with the item at the specified index
    *item = *(vec->items + index - 1);

    return ERR_OK;
}

// Function to set an item in the generic vector by index
ADTErr GenVectorSet(GenVector_t* vec, size_t index, void* item)
{
    if (!vec)
    {
        return ERR_NOT_INITIALIZED;
    }

    // Check for a valid index
    if (index > vec->nItems || index < 1)
    {
        return (ERR_WRONG_INDEX);
    }

    // Update the item at the specified index
    *(vec->items + (index - 1)) = item;

    return ERR_OK;
}

// Function to get the number of items in the generic vector
ADTErr GenVectorItemsNum(GenVector_t* vec, size_t* numOfItems)
{
    if (!vec || !numOfItems)
    {
        return ERR_NOT_INITIALIZED;
    }

    // Update the number of items
    *numOfItems = vec->nItems;

    return ERR_OK;
}

/* Unit-Test functions */
void GenVectorPrint(GenVector_t* vec, GenPrintFunc_t PrintFunc)
{
    if (!vec)
    {
        return;
    }

    // Print vector details
    printf("----------------------------------------\n");
    printf("<GenVector details> | blockSize=%zu | nItems=%zu | currSize=%zu | originalSize=%zu | \n <GenVector item> ",
        vec->blockSize, vec->nItems, vec->currSize, vec->originalSize);
    printf("\n----------------------------------------\n");

    // Print each item in the vector using the provided print function
    for (size_t i = 0; i < vec->nItems; ++i)
    {
        PrintFunc(*(vec->items + i));
    }
}

