//
// Created by mmaile on 3/2/21.
//

#include "ising.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <math.h>
#include <chrono>
#include <thread>
#include "my_random.h"


ising::ising(size_t n, double b) :
        grid(n*n),
        N(n),
        beta(b),
        dis_int(0, n-1),
        dis_real(0.0, 1.0)
{}

ising::ising(size_t n, double b, unsigned int seed) :
        grid(n*n),
        N(n),
        beta(b),
        dis_int(0, n-1),
        dis_real(0.0, 1.0),
        gen(seed)
{}

int ising::get_spin(int x, int y) {
    if(x >= N)
        throw std::out_of_range("ising::get_spin(x,y): x >= N");
    if(y >= N)
        throw std::out_of_range("ising::get_spin(x,y): y >= N");
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
        throw std::out_of_range("ising::flip_spin: x >= N");
    if(y >= N)
        throw std::out_of_range("ising::flip_spin: y >= N");
    grid.at(N*y + x) *= -1;
}

void ising::set_beta(double b) {
    beta = b;
}

/* calculating sum over the spins to the next neighbours of (x,y),
 * with periodic behavior at the boundries
 */
int ising::sum_next_neighbour(int x, int y) {
    int s = 0;

    if(x == 0){ // if coord is at the left end of the grid
        s += get_spin(N-1, y);
        s += get_spin(1, y);
    }
    else{
        if(x == N-1){ // if coord is at the right end of the grid
            s += get_spin(0, y);
            s += get_spin(N-2, y);
        }
        else {
            // if it is neither we can just sum up
            s += get_spin(x - 1, y);
            s += get_spin(x + 1, y);
        }
    }

    // same with up/down for y
    if(y == 0){
        s += get_spin(x, N-1);
        s += get_spin(x, 1);
    }
    else{
        if(y == N-1){
            s += get_spin(x, 0);
            s += get_spin(x, N-2);
        }
        else {
            s += get_spin(x, y - 1);
            s += get_spin(x, y + 1);
        }
    }

    return s;
}

/* a function setting every spin to a random +/-1 spin */
void ising::random() {
    for(unsigned int i = 0; i < N; ++i){
        for(unsigned int j = 0; j < N; ++j){
            if(dis_real(gen) <= 0.5)
                set_spin(i,j,1);
            else
                set_spin(i,j,-1);
        }
    }
}

/* print functions:
 * print(char symbol) prints the grid with symbol when grid(x,y) > 0
 * print() defaults to '#'
 */
void ising::print() {
    print('#');
}

void ising::print(char symbol){
    for(unsigned int i = 0; i < N; ++i){
        for(unsigned int j = 0; j < N; ++j) {
            if(get_spin(i,j) > 0)
                std::cout << symbol;
            else
                std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void ising::move() {
    // get random coordinate
    int x = dis_int(gen);
    int y = dis_int(gen);

    if (x >= N)
        std::cout << "bax x: x = " << x << "\n";

    int sum = sum_next_neighbour(x, y);


    if (get_spin(x, y) * sum < 0) {
        flip_spin(x, y);
        return;
    }

    double dE = get_spin(x, y) * sum * 2.;
    double p = dis_real(gen);
    if (p < exp(-1 * beta * dE))
    {
        flip_spin(x,y);
        return;
    }
}

void ising::sweep() {
    for (unsigned int i = 0; i < N*N; ++i)
        move();
}

void ising::run(unsigned int n){
    for(unsigned int i = 0; i < n; ++i){
        sweep();
    }
}
