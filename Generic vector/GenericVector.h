//
//  GenericVector.h
//  sorting-algorithms-in-c
//
//  Created by efraim g on 22/07/2024.
//

#ifndef GenericVector_h
#define GenericVector_h

// Forward declaration of the generic vector structure
typedef struct GenVector GenVector_t;

// Function pointer type for printing items in the vector
typedef void (*GenPrintFunc_t)(const void*);

/*
 * Create a new generic vector.
 * Parameters:
 *   - size: The initial allocation size.
 *   - blockSize: The extension block size.
 */
GenVector_t* GenVectorCreate(size_t size, size_t blockSize);

/*
 * Destroy a generic vector.
 * Parameters:
 *   - vec: The generic vector to destroy.
 */
void GenVectorDestroy(GenVector_t* vec);

/*
 * Add an item to the end of the generic vector.
 * Parameters:
 *   - vec: The generic vector.
 *   - item: The item to add.
 */
ADTErr GenVectorAdd(GenVector_t* vec, void* item);

/*
 * Delete the last item from the generic vector.
 * Parameters:
 *   - vec: The generic vector.
 *   - item: A pointer to store the deleted item.
 */
ADTErr GenVectorDelete(GenVector_t* vec, void** item);

/*
 * Get an item from the generic vector by index.
 * Parameters:
 *   - vec: The generic vector.
 *   - index: The index of the item to get (1..numOfItems).
 *   - item: A pointer to store the retrieved item.
 */
ADTErr GenVectorGet(GenVector_t* vec, size_t index, void** item);

/*
 * Set an item in the generic vector by index.
 * Parameters:
 *   - vec: The generic vector.
 *   - index: The index of the item to set (1..numOfItems).
 *   - item: The item to set.
 */
ADTErr GenVectorSet(GenVector_t* vec, size_t index, void* item);

/*
 * Get the number of items in the generic vector.
 * Parameters:
 *   - vec: The generic vector.
 *   - numOfItems: A pointer to store the number of items.
 */
ADTErr GenVectorItemsNum(GenVector_t* vec, size_t* numOfItems);

/*
 * Unit-Test function to print details and items in the generic vector.
 * Parameters:
 *   - vec: The generic vector.
 *   - PrintFunc: The function pointer for printing items.
 */
void GenVectorPrint(GenVector_t* vec, GenPrintFunc_t PrintFunc);

#endif /* GenericVector_h */
