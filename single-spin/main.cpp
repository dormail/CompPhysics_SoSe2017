//
// Created by mmaile on 3/1/21.
//

#include "spin.h"
#include <iostream>

int main(int argc, char *argv[]){
    spin s(1, 1.2);
    double a;

    for(double H = -5.; H < 5; H += 0.001){
        s.set_H(H);
        a = s.run(100000);
        std::cout << a << '\n';
    }

    return 0;
}