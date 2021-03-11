//
// Created by mmaile on 3/11/21.
//

/* implementations of runge kutta in 2nd and 4th order */

#include "diffeq.h"
#include <Eigen/Dense>
#include <iostream>

// potential energy
double V(Eigen::Vector3d r)
{
    return 0.5 * r.norm() * r.norm();
}


void RungeKutta2(Eigen::Vector3d r0,
                 Eigen::Vector3d v0,
                 double const h,
                 int const N,
                 double const m,
                 Eigen::Vector3d F(Eigen::Vector3d))
{
    Eigen::Vector3d r(r0);
    Eigen::Vector3d v(v0);
    Eigen::Vector3d k;

    for(unsigned int i = 0; i<N; ++i)
    {
        r += h*v;
        k = h * F(r) / m;
        k = h * F(r + 0.5 * k) / m;
        v += k;
        std::cout << r << '\n' << E(m, v, r, V) << '\n';
    }
}

void RungeKutta4(Eigen::Vector3d r0,
                 Eigen::Vector3d v0,
                 double const h,
                 int const N,
                 double const m,
                 Eigen::Vector3d F(Eigen::Vector3d))
{
    Eigen::Vector3d r(r0), v(v0), k1, k2, k3, k4;

    for(unsigned int i = 0; i<N; ++i)
    {
        r += h*v;

        k1 = h * F(r) / m;
        k2 = h * F(r + 0.5 * k1) / m;
        k3 = h * F(r + 0.5 * k2) / m;
        k4 = h * F(r + k3) / m;

        v += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        std::cout << r << '\n' << E(m, v, r, V) << '\n';
    }
}

double E(double mass,
         Eigen::Vector3d v,
         Eigen::Vector3d r,
         double V(Eigen::Vector3d))
{
    return 0.5 * mass * v.norm() * v.norm() + V(r);
}

Eigen::Vector3d F(Eigen::Vector3d r)
{
    return -1 * r;
}

int main()
{
    Eigen::Vector3d r0(1,0,0);
    Eigen::Vector3d v0(0,0,0);

    double h = 1;
    int N = 30 / h;
    RungeKutta4(r0, v0, h, N , 1, F);
    //RungeKutta4(r0, v0, 0.1, 100, 1, F);

    return 0;
}
