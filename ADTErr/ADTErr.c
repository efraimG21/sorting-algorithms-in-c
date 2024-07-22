// ADTErr.c
// Sorting algorithms in C

#include <stdio.h>
#include <stddef.h> // For NULL

#include "ADTErr.h"

// Array of error descriptions
static const char* ErrDescription[] = {
    "OK",
    "General Error",
    "Initialization Error",
    "Allocation Error",
    "Reallocation Error",
    "Underflow Error",
    "Overflow Error",
    "Wrong Index",
    "Missing Argument",
    "Duplicate Key",
    "Wrong Key",
    "Data Not Found"
};

void HandleErr(ADTErr errNum, const char* msg) {
    if (msg == NULL) {
        msg = "No additional information provided";
    }

    if (errNum >= 0 && errNum < (sizeof(ErrDescription) / sizeof(ErrDescription[0]))) {
        printf("Error Number: %d, Description: %s, Message: %s\n", errNum, ErrDescription[errNum], msg);
    } else {
        printf("Unknown Error Number: %d, Message: %s\n", errNum, msg);
    }
}
