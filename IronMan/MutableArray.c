//
//  MutableArray.c
//  IronMan
//
//  Created by Petro Rovenskyy on 10/9/17.
//

#include "MutableArray.h"

int descCmpfunc(const void * lhs, const void * rhs) {
    return (*(int*) rhs - *(int*) lhs);
}

int ascCmpfunc(const void * lhs, const void * rhs) {
    return (*(int*) lhs - *(int*) rhs);
}

void initArray(MutableArray *array, size_t initialSize) {
    array->array = (int *)malloc(initialSize * sizeof(int));
    array->used = 0;
    array->size = initialSize;
}

void insertArray(MutableArray *array, int element) {
    // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
    // Therefore a->used can go up to a->size
    if (array->used == array->size) {
        array->size *= 2;
        array->array = (int *)realloc(array->array, array->size * sizeof(int));
    }
    array->array[array->used++] = element;
}

void freeArray(MutableArray *array) {
    free(array->array);
    array->array = NULL;
    array->used = array->size = 0;
}
