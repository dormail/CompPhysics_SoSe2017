//
// Created by mmaile on 3/2/21.
//

#include "ising.h"
#include <vector>

ising::ising(size_t n) : grid(n*n)
{
    N = n;
    //std::vector<int> grid(n);

    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
}

int ising::get_spin(int x, int y) {
    return grid.at(N*y + x);
}

void ising::set_spin(int x, int y, int value) {
    grid.at(N*y + x) = value;
}

void ising::flip_spin(int x, int y) {
    grid.at(N*y + x) *= -1;
}
