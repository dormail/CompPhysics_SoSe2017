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
    std::cout << "Matrix after householder:\n" << A << '\n';

    for (int i = 0; i < 20; ++i)
        A = jacobi_rotation(A);
    std::cout << "Matrix after jacobi rotation:\n" << A << '\n';

    std::cout << "Computation with the Eigen library:\n" << m.eigenvalues() << '\n';




    return 0;
}