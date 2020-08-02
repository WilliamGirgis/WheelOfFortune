#include "wheels.h"
#include <time.h>
//
// Created by Samwil on 15/04/2020.
//

char *playWheel() {
    srand(time(NULL));
    int r  = rand()% 24;
    if(atoi(w[r])) {
        atoi(w[r]);
        return w[r];
    } else if (w[r] == "Bankrupt") {
        return w[r];
    } else if(w[r] == "Lose a Turn") {
        return w[r];
    } else if(w[r] == "Extra Turn") {
        return  w[r];
    }
}