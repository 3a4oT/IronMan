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
    int armor = minArmorConstraint;
    
    for (int i = 0; i< lenght; i++) {
        int pI  = arr[i];
        int pNext = (arr[i+1] < lenght)? arr[i+1] : 0;
        if (armor + pI < 0) {
            int armorForBattle = minArmorConstraint - (pI + armor);
            insertArray(&values, armorForBattle);
        }
        if ((armor + (pI + pNext)) <= 0) {
            armor += minArmorConstraint - (armor + pI + pNext);
            insertArray(&values, armor);
        }
    }
    qsort(values.array, values.used, sizeof(int), descCmpfunc);
    //DEBUG
    for (int j =0; j < values.used; j++) {
        printf("%ld,", (long) values.array[j]);
    }

    return values.array[0];
}

int main(int argc, const char * argv[]) {
    //int seq[] = { -2, -5, 4, 1, -5, -10 }; => 18
    //int seq[] = { -5, 4, -2, 3, 1, -1, -6, -1, 0, 5}; // => 8
    //int seq[]  = {-5, 4, -2, 3, 1}; //=> 6
    int seq[] = { -5, 4, -2, 3, 1, -1, -6, -1, 0, -5}; // => 13
    //int seq[]  = {-2, 3, 1, 0, -1}; //=> 3
    //int seq[]  = { 100, 3, 1, 0, -1}; //=> 3
    size_t lenght = (sizeof(seq) / sizeof(seq[0]));
    int armor = minInitialArmor(lenght, seq, 1);
    printf("Minimum initial armor to survive should be == %ld \n",(long)armor);
    
    //Clean up
    freeArray(&values);
    return 0;
}
