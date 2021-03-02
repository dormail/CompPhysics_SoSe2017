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
    std::mt19937 gen;
    std::uniform_real_distribution<> dis_real;
    std::uniform_int_distribution<> dis_int;

    /* varaibles for the simulation
     * beta= k_B * T
     */
    double beta;

public:
    ising(size_t n);
    ising(size_t n, double b);
    ising(size_t n, double b, unsigned int seed);

    /* randomizer seeding */
    void seed_random();

    /* get/set methods */
    int get_spin(int x, int y);
    void set_spin(int x, int y, int value);
    void set_beta(double b);
    void random(); // sets all spins to random states
    void set_all(int value);

    void flip_spin(int x, int y);

    /* print methods */
    void print();
    void print(char symbol);

    /* methods for simulation */
    int sum_next_neighbour(int x, int y);
    double energy_density();

    void move(); // offer a random spin a flip
    void sweep(); // offer a spin flip to N*N random spins
    void run(unsigned int n);

    void live_simul();
};

#endif //COMPPHYSICS_SOSE2017_ISING_H
