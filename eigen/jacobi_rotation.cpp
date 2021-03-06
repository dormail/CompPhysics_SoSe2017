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
    while(off(A) > eps)
    {
        std::cout << "off(A) = " << off(A) << '\n';
        A = jacobi_rotation(A);
    }
    return A;
}

Eigen::MatrixXd jacobi_rotation(Eigen::MatrixXd A)
{
    int n = A.rows();
    double c, s, theta, t;
    Eigen::MatrixXd P;

    for (int p = 0; p < n; ++p)
    {
        for (int q = p+1; q < n; ++q)
        {
            if (p == q)
                continue;
            theta = (A(q, q) - A(p, p)) / (2 * A(p, q));
            t = sgn(theta) / (abs(theta) + sqrt(pow(theta, 2) + 1));
            c = 1 / sqrt(1 + pow(t, 2));
            s = t * c;

            P = Eigen::MatrixXd::Identity(n, n);
            P(p, p) = P(q, q) = c;
            P(p, q) = s;
            P(q, p) = -1 * s;

            std::cout << "Matrix P\n" << P << '\n';

            A = P.transpose() * A * P;
            std::cout << "Matrix A\n" << A << '\n';
        }
    }

    return A;
}
