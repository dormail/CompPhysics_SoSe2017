//
// Created by mmaile on 3/2/21.
//

#include "ising.h"
#include <iostream>

int main(int argc, char *argv[]){
    ising s(5);

    s.set_spin(1,1, 5);
    s.flip_spin(1,1);

    std::cout << s.get_spin(1,1) << '\n';


    return 0;
}