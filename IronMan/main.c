//
//  main.c
//  IronMan
//
//  Created by Petro Rovenskyy on 10/9/17.
//

#include <stdio.h>
#include "IronCMan.h"

int main(int argc, const char * argv[]) {
    int seq[] = { -5, 4, -2, 3, 1, -1, -6, -1, 0, 5}; // => 8
    size_t lenght = (sizeof(seq) / sizeof(seq[0]));
    IronCMan cMan;
    initIronCMan(&cMan);
    int armor = cMan.minInitialPower(lenght, seq, 1);
    cleanIronCMan(&cMan);
    printf("Minimum initial power to survive should be == %ld \n",(long)armor);
    return 0;
}
