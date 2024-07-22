//
//  ADTErr.h
//  sorting-algorithms-in-c
//
//  Created by efraim g on 22/07/2024.
//

#ifndef ADTErr_h
#define ADTErr_h

// Enumeration of General ADT Errors
typedef enum
{
    ERR_OK = 0,                  // No error
    ERR_GENERAL,                 // General error
    ERR_NOT_INITIALIZED,         // ADT not initialized
    ERR_ALLOCATION_FAILED,       // Memory allocation failed
    ERR_REALLOCATION_FAILED,     // Memory reallocation failed
    ERR_UNDERFLOW,               // Underflow error
    ERR_OVERFLOW,                // Overflow error
    ERR_WRONG_INDEX,             // Incorrect index
    ERR_MISSING_ARGUMENT,        // Missing argument
    ERR_DUPLICATE_KEY,           // Duplicate key
    ERR_WRONG_KEY,               // Incorrect key
    ERR_DATA_NOT_FOUND,          // Data not found
    ERR_DUPLICATIOS_KEY,         // Duplicate key

} ADTErr;

// Function to handle errors and print corresponding messages
void HandleErr(ADTErr errNum, char* msg);

#endif /* ADTErr_h */
