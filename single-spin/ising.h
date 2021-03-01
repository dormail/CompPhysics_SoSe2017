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
    double beta; // beta = k_B * T

public:
    spin();
    spin(double b, double H);
    void move();
    void run(unsigned int n);
};

#endif //COMPPHYSICS_SOSE2017_ISING_H
