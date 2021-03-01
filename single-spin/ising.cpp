//
// Created by mmaile on 3/1/21.
//

#include "ising.h"
#include <iostream>
#include <random>

spin::spin(){
    s = 1;
    double H = 1;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
}

void spin::flip() {
    double a = dis(gen);
    std::cout << a << '\n';
}