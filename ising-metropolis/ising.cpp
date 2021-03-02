//
// Created by mmaile on 3/2/21.
//

#include "ising.h"
#include <vector>
#include <stdexcept>

ising::ising(size_t n) : grid(n*n), N(n)
{
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
}

ising::ising(size_t n, double b) :
grid(n*n),
N(n),
beta(b)
{
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
}

int ising::get_spin(int x, int y) {
    if(x >= N)
        throw std::out_of_range("x >= N");
    if(y >= N)
        throw std::out_of_range("y >= N");
    return grid.at(N*y + x);
}

void ising::set_spin(int x, int y, int value) {
    if(x >= N)
        throw std::out_of_range("x >= N");
    if(y >= N)
        throw std::out_of_range("y >= N");
    grid.at(N*y + x) = value;
}

void ising::flip_spin(int x, int y) {
    if(x >= N)
        throw std::out_of_range("x >= N");
    if(y >= N)
        throw std::out_of_range("y >= N");
    grid.at(N*y + x) *= -1;
}

void ising::set_beta(double b) {
    beta = b;
}