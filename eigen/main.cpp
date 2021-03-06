//
// Created by mmaile on 3/6/21.
//

#include "diagonalization.h"
#include <iostream>

int main()
{
    Eigen::MatrixXd m(5,5);
    m <<    1, 1, 1, 1, 1,
            1, 2, 1, 1, 1,
            1, 1, 3, 1, 1,
            1, 1, 1, 4, 1,
            1, 1, 1, 1, 5;
    std::cout << m << '\n';

    return 0;
}