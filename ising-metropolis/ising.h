//
// Created by mmaile on 3/2/21.
//
#include <random>
#include <vector>

#ifndef COMPPHYSICS_SOSE2017_ISING_H
#define COMPPHYSICS_SOSE2017_ISING_H

/* class to represent a quadratic ising grid */
class ising{
private:
    unsigned int N; // side length of the grid
    std::vector<int> grid;

    /* rng stuff */
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;

public:
    ising(size_t n);

    int get_spin(int x, int y);
    void set_spin(int x, int y, int value);
    void flip_spin(int x, int y);
};

#endif //COMPPHYSICS_SOSE2017_ISING_H
