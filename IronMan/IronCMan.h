//
//  IronCMan.h
//  IronMan
//
//  Created by Petro Rovenskyy on 10/11/17.
//

#ifndef IronCMan_h
#define IronCMan_h

#include <stdio.h>
typedef struct {
    int (*minInitialPower)(size_t lenght, int* battleFiled, int minPowerConstraint);
} IronCMan;

void initIronCMan(IronCMan* iCM);
void cleanIronCMan(IronCMan* iCM);

#endif /* IronCMan_h */
