//
// Created by mmaile on 3/2/21.
//

#include "ising.h"
#include <string>
#include <chrono>

int main(int argc, char *argv[]){
    double beta = 1.;
    if(argc >= 2){
        beta = atof(argv[1]);
    }
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    ising grid(80, beta, seed);
    grid.set_all(1);

    std::string argv2;
    if(argc >= 3){
        argv2.assign(argv[2]);
        if(argv2.compare("--random") == 0)
            grid.random();
    }

    grid.live_simul();

    return 0;
}
