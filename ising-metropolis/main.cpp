//
// Created by mmaile on 3/2/21.
//

#include "ising.h"
#include <iostream>

int main(int argc, char *argv[]){
    ising s(20, 3);

    s.random();
    //s.random();

    std::cout << "Vor dem move:\n";
    s.print();
    std::cout << "Nach dem sweep\n";
    s.run(1e5);
    s.print();


    return 0;
}