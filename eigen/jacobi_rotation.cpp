//
// Created by mmaile on 3/6/21.
//

#include "diagonalization.h"
#include <math.h>
#include <iostream>

double off(Eigen::MatrixXd A)
{
    int n = A.rows();
    double sum = 0;
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            sum += pow(A(i, j), 2);
        }
    }
    return sum;
}

Eigen::MatrixXd jacobi_rotation(Eigen::MatrixXd A, double eps)
{
    return A;
}
