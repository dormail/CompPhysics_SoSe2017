//
// Created by mmaile on 3/12/21.
//

/* implementation of the stuff to solve kepler problem and
 * related stuff
 */

#include "kepler.h"
#include <Eigen/Dense>
#include <math.h>


Eigen::Vector3d F(Eigen::Vector3d r)
{
    return -1 * G * r / pow(r.norm(), 3);
}

double V(Eigen::Vector3d r)
{
    return -1 * G / r.norm();
}

int main()
{}
