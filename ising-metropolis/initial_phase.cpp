//
// Created by mmaile on 3/2/21.
//

#include "ising.h"
#include <string>
#include <chrono>

int main(int argc, char *argv[]){
    double beta = 1.;
    unsigned int sweeps;
    if(argc >= 2){
        beta = atof(argv[1]);
        sweeps = atof(argv[2]);
    }
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    ising grid(100, beta, seed);
    grid.set_all(1);

    std::string argv2;
    if(argc >= 4){
        grid.random();
    }

    grid.simulate_initial_phase(sweeps);

    return 0;
}