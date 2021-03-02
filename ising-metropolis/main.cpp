//
// Created by mmaile on 3/2/21.
//

#include "ising.h"
#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char *argv[]){
    double beta = 1.;
    if(argc >= 2){
        beta = atof(argv[1]);
    }
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    ising s(100, beta, seed);

    //s.set_all(1);
    s.random();

    s.live_simul();


    return 0;
}