//
// Created by mmaile on 3/11/21.
//
#include <Eigen/Dense>
#include "diffeq.h"

Eigen::Vector3d F(Eigen::Vector3d r)
{
    return -1 * r;
}

int main()
{
    Eigen::Vector3d r0(1,0,0);
    Eigen::Vector3d v0(0,0.1,0);

    euler(r0, v0, 0.1, 100, 1, F);

    return 0;
}
