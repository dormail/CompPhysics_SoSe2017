//
// Created by mmaile on 3/6/21.
//

#include "diagonalization.h"
#include <math.h>
#include <iostream>

double sgn(double x)
{
    if (x > 0)
        return 1;
    if (x< 0)
        return -1;
    return 0;
}

Eigen::MatrixXd householder(Eigen::MatrixXd A)
{
    int n = A.rows();
    // first step
    Eigen::VectorXd a = A.block(1,0, A.rows()-1, 1);
    std::cout << a << '\n';
    double sum = a.adjoint() * a;
    double alpha = -1 * sgn(A(1,0)) * sqrt(sum);

    double r = sqrt(0.5 * alpha * (alpha - A(1,0)));

    Eigen::VectorXd v = A.col(0);
    v(0) = 0;
    v(1) = (v(1) - alpha) / (2*r);
    v.tail(n-2) /= 2*r;

    Eigen::MatrixXd P(n,n);
    P = Eigen::MatrixXd::Identity(n,n);
    //std::cout << P << '\n';
    P -= 2 * v * v.adjoint();

    std::cout << "v:\n" << v << '\n';
    std::cout << "P:\n" << P << '\n';

    A = P * A * P;

    return A;
}
