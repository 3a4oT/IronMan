//
//  main.c
//  IronMan
//
//  Created by Petro Rovenskyy on 10/9/17.
//

#include <stdio.h>
#include "MutableArray.h"

MutableArray powerBank;

int minInitialPower(size_t lenght, int *battleFiled, int minPowerConstraint) {
    initArray(&powerBank, lenght);
    int power = minPowerConstraint;
    insertArray(&powerBank, power);
    int powerAtLocationI = 0;
    for (int i = 0; i< lenght; i++) {
        powerAtLocationI += battleFiled[i];
        int nextLocation = i + 1;
        int powerAtNextLocation = (nextLocation < lenght) ? battleFiled[nextLocation] : 0;
        int battle = power + powerAtLocationI;
        if (battle < 0) {
            power = minPowerConstraint - (battle);
            // Really enough to survive in the next location?
            battle = power + powerAtLocationI + powerAtNextLocation;
            if (battle <= 0) {
                power += minPowerConstraint - (battle);
            }
            insertArray(&powerBank, power);
        }
    }
    
    qsort(powerBank.array, powerBank.used, sizeof(int), descCmpfunc);
    power = powerBank.array[0];
    return power;
}

int main(int argc, const char * argv[]) {
    //int seq[] = { -2, -5, 4, 1, -5, -10 }; //=> 18
    //int seq[] = { -5, 4, -2, 3, 1, -1, -6, -1, 0, 5}; // => 8
    //int seq[]  = {-5, 4, -2, 3, 1}; //=> 6
    int seq[] = { -5, 4, -2, 3, 1, -1, -6, -1, 0, -5}; // => 13
    //int seq[]  = {-2, 3, 1, 0, -1}; //=> 3
    //int seq[]  = { 100, 3, 1, 0, -200}; //=> 97
    size_t lenght = (sizeof(seq) / sizeof(seq[0]));
    int armor = minInitialPower(lenght, seq, 1);
    printf("\nMinimum initial power to survive should be == %ld \n",(long)armor);
    
    //Clean up
    freeArray(&powerBank);
    return 0;
}
