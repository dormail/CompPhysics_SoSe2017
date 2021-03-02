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

    /* varaibles for the simulation
     * beta= k_B * T
     */
    double beta;

public:
    ising(size_t n);
    ising(size_t n, double b);

    int get_spin(int x, int y);
    void set_spin(int x, int y, int value);
    void flip_spin(int x, int y);

    void set_beta(double b);

    void print();
    void print(char symbol);

    /* methods for simulation */
    void random();
    int sum_next_neighbour(int x, int y);
    void move();
};

#endif //COMPPHYSICS_SOSE2017_ISING_H
