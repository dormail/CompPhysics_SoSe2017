//
// Created by mmaile on 3/12/21.
//

/* implementation of the stuff to solve kepler problem and
 * related stuff
 */

#include "kepler.h"
#include <vector>
#include <Eigen/Dense>
#include <Eigen/StdVector>
#include <math.h>


#include <iostream>

Eigen::Vector3d F(Eigen::Vector3d r)
{
    return -1 * G * r / pow(r.norm(), 3);
}

double V(Eigen::Vector3d r)
{
    return -1 * G / r.norm();
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
        std::cout << r << '\n';
    }
}


std::vector<Eigen::Vector3d> RungeKutta4Vector(Eigen::Vector3d r0,
                                               Eigen::Vector3d v0,
                                               double const h,
                                               int const N,
                                               double const m,
                                               Eigen::Vector3d F(Eigen::Vector3d))
{
    std::vector<Eigen::Vector3d> storage_r;
    Eigen::Vector3d r(r0), v(v0), k1, k2, k3, k4;

    for(unsigned int i = 0; i<N; ++i)
    {
        r += h*v;

        k1 = h * F(r) / m;
        k2 = h * F(r + 0.5 * k1) / m;
        k3 = h * F(r + 0.5 * k2) / m;
        k4 = h * F(r + k3) / m;

        v += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        storage_r.push_back(r);
    }

    return storage_r;
}


int main()
{
    Eigen::Vector3d r0(1., 0., 0.);
    Eigen::Vector3d v0(0., 1, 0.);

    double h = 0.0015;
    int N = 2500;
    double m = 1;

    RungeKutta4(r0, v0, h, N, m, F);


    return 0;
}
