//
//  MutableArray.h
//  IronMan
//
//  Created by Petro Rovenskyy on 10/9/17.
//

#ifndef MutableArray_h
#define MutableArray_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} MutableArray;

int descCmpfunc(const void * lhs, const void * rhs);
int ascCmpfunc(const void * lhs, const void * rhs);

void initArray(MutableArray *array, size_t initialSize);
void insertArray(MutableArray *array, int element);
void freeArray(MutableArray *array);

#endif /* MutableArray_h */
