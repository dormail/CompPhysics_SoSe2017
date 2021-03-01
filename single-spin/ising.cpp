//
// Created by mmaile on 3/1/21.
//

#include "ising.h"
#include <iostream>
#include <random>
#include <math.h>

spin::spin(){
    s = 1;
    double H = 1;
    double T = 1;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
}

spin::spin(double b, double H_){
    s = 1;
    double H = H_;
    double beta = b;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
}

void spin::move() {
    // spin flip when DeltaE < 0
    if (s == -1){
        s = 1;
        return;
    }

    double dE = 2 * H;
    double p = dis(gen);

    if(p < exp(-1 * beta * dE)){
        s *= 1;
        return;
    }
}

