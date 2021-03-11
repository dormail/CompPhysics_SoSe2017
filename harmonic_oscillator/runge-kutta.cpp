//
// Created by mmaile on 3/11/21.
//

/* implementations of runge kutta in 2nd and 4th order */

#include "diffeq.h"
#include <Eigen/Dense>
#include <iostream>

void RungeKutta2(Eigen::Vector3d r0,
                 Eigen::Vector3d v0,
                 double const h,
                 int const N,
                 double const m,
                 Eigen::Vector3d F(Eigen::Vector3d))
{
    Eigen::Vector3d r(r0);
    Eigen::Vector3d v(v0);
    Eigen::Vector3d k1;
    Eigen::Vector3d k2;

    for(unsigned int i = 0; i<N; ++i)
    {
        r += h*v;
        k1 = h * F(r);
        k2 = h * F(r + 0.5 * k1);
        v += k2;
        std::cout << r << '\n';
    }
}

void RungeKutta4(Eigen::Vector3d r0,
                 Eigen::Vector3d v0,
                 double const h,
                 double const N,
                 double const m,
                 Eigen::Vector3d F(Eigen::Vector3d))
{}

Eigen::Vector3d F(Eigen::Vector3d r)
{
    return -1 * r;
}

int main()
{
    Eigen::Vector3d r0(1,0,0);
    Eigen::Vector3d v0(0,0,0);

    double h = .1;
    int N = 30 / h;
    RungeKutta2(r0, v0, h, N , 1, F);
    //RungeKutta4(r0, v0, 0.1, 100, 1, F);

    return 0;
}
