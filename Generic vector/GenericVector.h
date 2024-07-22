// GenericVector.h
// Data structures in C

#ifndef GENERICVECTOR_H
#define GENERICVECTOR_H

#include "ADTErr.h"

// Forward declaration of the generic vector structure
typedef struct GenVector GenVector_t;

// Function pointer type for printing items in the vector
typedef void (*GenPrintFunc_t)(const void*);

/**
 * @brief Creates a new generic vector.
 *
 * @param size The initial allocation size.
 * @param blockSize The extension block size.
 * @return Pointer to the newly created vector, or NULL on failure.
 */
GenVector_t* GenVectorCreate(size_t size, size_t blockSize);

/**
 * @brief Destroys a generic vector.
 *
 * @param vec The generic vector to destroy.
 */
void GenVectorDestroy(GenVector_t* vec);

/**
 * @brief Adds an item to the end of the generic vector.
 *
 * @param vec The generic vector.
 * @param item The item to add.
 * @return Error code.
 */
ADTErr GenVectorAdd(GenVector_t* vec, void* item);

/**
 * @brief Deletes the last item from the generic vector.
 *
 * @param vec The generic vector.
 * @param item Pointer to store the deleted item.
 * @return Error code.
 */
ADTErr GenVectorDelete(GenVector_t* vec, void** item);

/**
 * @brief Gets an item from the generic vector by index.
 *
 * @param vec The generic vector.
 * @param index The index of the item to get (1..numOfItems).
 * @param item Pointer to store the retrieved item.
 * @return Error code.
 */
ADTErr GenVectorGet(GenVector_t* vec, size_t index, void** item);

/**
 * @brief Sets an item in the generic vector by index.
 *
 * @param vec The generic vector.
 * @param index The index of the item to set (1..numOfItems).
 * @param item The item to set.
 * @return Error code.
 */
ADTErr GenVectorSet(GenVector_t* vec, size_t index, void* item);

/**
 * @brief Gets the number of items in the generic vector.
 *
 * @param vec The generic vector.
 * @param numOfItems Pointer to store the number of items.
 * @return Error code.
 */
ADTErr GenVectorItemsNum(GenVector_t* vec, size_t* numOfItems);

/**
 * @brief Unit-test function to print details and items in the generic vector.
 *
 * @param vec The generic vector.
 * @param PrintFunc Function pointer for printing items.
 */
void GenVectorPrint(GenVector_t* vec, GenPrintFunc_t PrintFunc);

#endif /* GENERICVECTOR_H */
