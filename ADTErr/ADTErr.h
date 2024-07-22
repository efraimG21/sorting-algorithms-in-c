// ADTErr.h
// Sorting algorithms in C

#ifndef ADTERR_H
#define ADTERR_H

// Enumeration of General ADT Errors
typedef enum {
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
} ADTErr;

// Function to handle errors and print corresponding messages
void HandleErr(ADTErr errNum, const char* msg);

#endif /* ADTERR_H */
