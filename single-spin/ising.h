//
// Created by mmaile on 3/1/21.
//

#include <random>

#ifndef COMPPHYSICS_SOSE2017_ISING_H
#define COMPPHYSICS_SOSE2017_ISING_H

class spin{
private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
    int s;
    double H;
public:
    spin();
    void flip();
};

#endif //COMPPHYSICS_SOSE2017_ISING_H
