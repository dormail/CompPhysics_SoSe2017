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
    double sum = a.adjoint() * a;
    double alpha = -1 * sgn(A(1,0)) * sqrt(sum);

    double r = sqrt(0.5 * alpha * (alpha - A(1,0)));

    Eigen::VectorXd v = A.col(0);
    v(0) = 0;
    v(1) = (v(1) - alpha) / (2*r);
    v.tail(n-2) /= 2*r;

    Eigen::MatrixXd P(n,n);
    P = Eigen::MatrixXd::Identity(n,n);
    P -= 2 * v * v.adjoint();

    A = P * A * P;


    // next steps as a iteration
    for (int k = 1; k < n-2; ++k)
    {
        // coefficients
        a = A.block(k+1, k, n-(k+1), 1);
        sum = a.adjoint() * a;
        alpha = -1 * sgn(A(k+1, k)) * sqrt(sum);
        double r = sqrt(0.5 * alpha * (alpha - A(k+1,k)));

        // vector v
        Eigen::VectorXd v = A.col(k);
        v.tail(n-(k+2)) /= 2*r;
        v.head(k+1) = Eigen::MatrixXd::Zero(k+1, 1);
        v(k + 1) = (A(k+1, k) - alpha) / (2*r);

        P = Eigen::MatrixXd::Identity(n,n);
        P -= 2 * v * v.adjoint();
        A = P * A * P;

    }

    return A;
}
