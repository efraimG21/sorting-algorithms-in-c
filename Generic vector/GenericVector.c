// GenericVector.c
// Data structures in C

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ADTErr.h"
#include "GenericVector.h"

#define REALLOC_FACTOR 2

// Definition of the generic vector structure
struct GenVector {
    void**  items;         // Array to store items
    size_t  originalSize;  // Initial size of the vector
    size_t  blockSize;     // Block size for reallocation
    size_t  currSize;      // Current size of the vector
    size_t  nItems;        // Number of items in the vector
};

// Function to create a new generic vector
GenVector_t* GenVectorCreate(size_t size, size_t blockSize) {
    if (size == 0 && blockSize == 0) {
        return NULL;
    }

    GenVector_t* vec = (GenVector_t*)malloc(sizeof(GenVector_t));
    if (!vec) {
        return NULL;
    }

    vec->items = (void**)malloc(sizeof(void*) * size);
    if (!vec->items) {
        free(vec);
        return NULL;
    }

    vec->currSize = size;
    vec->originalSize = size;
    vec->blockSize = blockSize;
    vec->nItems = 0;

    return vec;
}

// Function to destroy a generic vector
void GenVectorDestroy(GenVector_t* vec) {
    assert(vec);

    free(vec->items);
    free(vec);
}

// Function to add an item to the generic vector
ADTErr GenVectorAdd(GenVector_t* vec, void* item) {
    assert(vec);

    if (!item) {
        return ERR_NOT_INITIALIZED;
    }

    if (vec->nItems == vec->currSize) {
        if (vec->blockSize == 0) {
            return ERR_OVERFLOW;
        }

        void** tmp = (void**)realloc(vec->items, sizeof(void*) * (vec->currSize + vec->blockSize));
        if (!tmp) {
            return ERR_REALLOCATION_FAILED;
        }

        vec->items = tmp;
        vec->currSize += vec->blockSize;
    }

    vec->items[vec->nItems] = item;
    ++vec->nItems;

    return ERR_OK;
}

// Function to delete the last item from the generic vector
ADTErr GenVectorDelete(GenVector_t* vec, void** item) {
    assert(vec && item);

    if (vec->nItems == 0) {
        return ERR_UNDERFLOW;
    }

    if (vec->currSize > vec->originalSize &&
        vec->nItems <= (vec->currSize - (vec->blockSize * REALLOC_FACTOR))) {
        void** tmp = (void**)realloc(vec->items, sizeof(void*) * (vec->currSize - vec->blockSize));
        if (!tmp) {
            return ERR_REALLOCATION_FAILED;
        }

        vec->items = tmp;
        vec->currSize -= vec->blockSize;
    }

    *item = vec->items[vec->nItems - 1];
    --vec->nItems;

    return ERR_OK;
}

// Function to get an item from the generic vector by index
ADTErr GenVectorGet(GenVector_t* vec, size_t index, void** item) {
    if (!vec || !item) {
        return ERR_NOT_INITIALIZED;
    }

    if (index == 0 || index > vec->nItems) {
        return ERR_WRONG_INDEX;
    }

    *item = vec->items[index - 1];

    return ERR_OK;
}

// Function to set an item in the generic vector by index
ADTErr GenVectorSet(GenVector_t* vec, size_t index, void* item) {
    if (!vec) {
        return ERR_NOT_INITIALIZED;
    }

    if (index == 0 || index > vec->nItems) {
        return ERR_WRONG_INDEX;
    }

    vec->items[index - 1] = item;

    return ERR_OK;
}

// Function to get the number of items in the generic vector
ADTErr GenVectorItemsNum(GenVector_t* vec, size_t* numOfItems) {
    if (!vec || !numOfItems) {
        return ERR_NOT_INITIALIZED;
    }

    *numOfItems = vec->nItems;

    return ERR_OK;
}

// Unit-Test function to print details and items in the generic vector
void GenVectorPrint(GenVector_t* vec, GenPrintFunc_t PrintFunc) {
    if (!vec) {
        return;
    }

    printf("----------------------------------------\n");
    printf("<GenVector details> | blockSize=%zu | nItems=%zu | currSize=%zu | originalSize=%zu |\n",
           vec->blockSize, vec->nItems, vec->currSize, vec->originalSize);
    printf("----------------------------------------\n");

    for (size_t i = 0; i < vec->nItems; ++i) {
        PrintFunc(vec->items[i]);
    }
}
