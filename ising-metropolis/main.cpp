//
// Created by mmaile on 3/2/21.
//

#include "ising.h"
#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char *argv[]){
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    ising s(100, 2.27, seed);

    s.random();

    s.print();
    s.live_simul();


    return 0;
}