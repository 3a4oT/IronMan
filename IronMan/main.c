//
//  main.c
//  IronMan
//
//  Created by Petro Rovenskyy on 10/9/17.
//

#include <stdio.h>
#include "MutableArray.h"

MutableArray values;

int minInitialArmor(size_t lenght, int *arr, int minArmorConstraint) {
    initArray(&values, lenght);
    int armor = 0;
    for (int i = 0; i< lenght; i++) {
        int pI = arr[i];
        int pNext = 0;
        if ((i + 1) < lenght) {
            pNext = arr[i + 1];
        }
        armor = minArmorConstraint - (pI + pNext);
        insertArray(&values, armor);
    }

    qsort(values.array, values.used, sizeof(int), descCmpfunc);
    //DEBUG
    for (int j =0; j < values.used; j++) {
        printf("%ld,", (long) values.array[j]);
    }

    return values.array[0];
}

int main(int argc, const char * argv[]) {
    int seq[] = { -2, -5, 4, 1, -5, -10 };
    size_t lenght = (sizeof(seq) / sizeof(seq[0]));
    int armor = minInitialArmor(lenght, seq, 1);
    printf("Minimum initial armor to survive should be == %ld \n",(long)armor);
    
    //Clean up
    freeArray(&values);
    return 0;
}
