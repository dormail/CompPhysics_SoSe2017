//
// Created by mmaile on 3/1/21.
//

#include "spin.h"
#include <iostream>
#include <random>
#include <math.h>

spin::spin(){
    s = 1;
    double H = 1;
    double b = 1;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
}

void spin::random_test() {
    std::cout << dis(gen) << '\n';
    std::cout << dis(gen) << '\n';
    std::cout << dis(gen) << '\n';
    std::cout << dis(gen) << '\n';
}

spin::spin(double b, double H_){
    H = H_;
    beta = b;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    s = 1;
}

void spin::move() {
    //std::cout << s << "\n";

    // spin flip when DeltaE < 0
    if (s * H < 0){
        s *= -1;
        return;
    }

    double dE = abs(2 * H);
    double p = dis(gen);

    if(p < exp(-1 * beta * dE)){
        s *= -1;
        return;
    }
}

void spin::set_H(double H_new){
    H = H_new;
}

double spin::run(unsigned int n){
    int m = 0;
    for(unsigned int i = 0; i < n; ++i){
        move();
        m += s;
    }
    return m/100000.;
}
