//
// Created by mmaile on 3/11/21.
//

/* implementations of runge kutta in 2nd and 4th order */

#include "diffeq.h"


void RungeKutta2(Eigen::Vector3d r0,
                 Eigen::Vector3d v0,
                 double const step,
                 double const N,
                 double const m,
                 Eigen::Vector3d F(Eigen::Vector3d))
{

}

void RungeKutta4(Eigen::Vector3d r0,
                 Eigen::Vector3d v0,
                 double const step,
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
    Eigen::Vector3d v0(0,0.1,0);

    RungeKutta2(r0, v0, 0.1, 100, 1, F);
    RungeKutta4(r0, v0, 0.1, 100, 1, F);

    return 0;
}
