//
// Created by mmaile on 3/12/21.
//

#include "kepler.h"
#include <Eigen/Dense>
#include <string>

int main()
{
    Eigen::Vector3d r0(1,0,0);
    Eigen::Vector3d v0(0,0.5,0);

    double h = 0.01, m = 1.;
    int N = 1000;

    v0[1] = 0.55;
    N = 170;
    StdvectorEigenvecToFile(RungeKutta4Vector(r0, v0, h, N, m, F), "dir_a/v_07.txt");

    v0[1] = 1.0;
    N = 10000;
    StdvectorEigenvecToFile(RungeKutta4Vector(r0, v0, h, N, m, F), "dir_a/v_1.txt");

    return 0;
}
