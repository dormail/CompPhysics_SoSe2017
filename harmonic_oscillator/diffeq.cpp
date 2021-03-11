//
// Created by mmaile on 3/11/21.
//

#include <Eigen/Dense>
#include <iostream>
#include "diffeq.h"

void euler(Eigen::Vector3d r0,
           Eigen::Vector3d v0,
           double const step,
           double const N,
           double const m,
           Eigen::Vector3d F(Eigen::Vector3d))
{
    Eigen::Vector3d r(r0);
    Eigen::Vector3d v(v0);
    for (unsigned int i = 0; i < N; ++i)
    {
        r += step * v;
        v += step * F(r) / m;
        std::cout << r << '\n';
    }
}
