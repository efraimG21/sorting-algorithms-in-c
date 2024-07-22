//
//  ADTErr.c
//  sorting-algorithms-in-c
//
//  Created by efraim g on 22/07/2024.
//

#include <stdio.h>

#include "ADTErr.h"

const char* ErrDescription[] =
{
    /* General ADT Errors - Description */
    "OK",
    "General Error",
    "Initialization error",
    "Allocation error",
    "ReAllocation error",
    "Underflow error",
    "Overflow error",
    "Wrong index",
    "Missing argument",
    "Not allowed duplicatios key",
    "Wrong Key",
    "Data Not Found",
    "Duplicate Key",
};

void HandleErr(ADTErr errNum, char* msg)
{
    if (errNum >= 0 && errNum < sizeof(ErrDescription) / sizeof(ErrDescription[0]))
    {
        printf("ErrNum=%d, ErrDescription=%s, msg=%s\n", errNum, ErrDescription[errNum], msg);
    }
    else
    {
        printf("Unknown error: ErrNum=%d, msg=%s\n", errNum, msg);
    }
}
