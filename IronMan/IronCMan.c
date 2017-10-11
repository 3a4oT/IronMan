//
//  IronCMan.c
//  IronMan
//
//  Created by Petro Rovenskyy on 10/11/17.
//

#include "IronCMan.h"
#include "MutableArray.h"

MutableArray powerBank;

int minInitialPower(size_t lenght, int *battleFiled, int minPowerConstraint) {
    initArray(&powerBank, lenght);
    int power = minPowerConstraint;
    insertArray(&powerBank, power);
    int powerAtLocationI = 0;
    for (int i = 0; i < lenght; i++) {
        powerAtLocationI += battleFiled[i];
        int nextLocation = i + 1;
        int powerAtNextLocation = (nextLocation < lenght) ? battleFiled[nextLocation] : 0;
        int battle = power + powerAtLocationI;
        if (battle < 0) {
            power += minPowerConstraint - (battle);
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
    //Clean up
    freeArray(&powerBank);
    return power;
}

void initIronCMan(IronCMan* iCM) {
    iCM->minInitialPower = minInitialPower;
}

void cleanIronCMan(IronCMan* iCM) {
    iCM->minInitialPower = NULL;
}
