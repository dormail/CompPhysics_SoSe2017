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
    std::cout << "Matrix m:\n" << m << '\n';

    Eigen::MatrixXd A = householder(m);
    std::cout << "Matrix A:\n" << A << '\n';



    return 0;
}