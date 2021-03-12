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
#include <string>
#include <fstream>
#include <math.h>
#include <iostream>


/* Force and its potential for keppler problem */
Eigen::Vector3d F(Eigen::Vector3d r)
{
    return -1 * G * r / pow(r.norm(), 3);
}

double V(Eigen::Vector3d r)
{
    return -1 * G / r.norm();
}


/* simulates a motion of a particle with Runge Kutta (4th Order)
 * Arguments:
 *   r0, v0 = initial conditions (position and velocity)
 *   h      = integration step for runge kutta
 *   N      = number of integration steps
 *   m      = mass of particle
 *   F      = Force on the particle, being a conservative for for now
 *
 *
 * untested for m!=1
 */
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


/* uses RungeKutta 4th order to solve a motion of a particle
 * but stores the result in a std::vector of Eigen::Vector3d
 *
 * meaning of arguments: see RungeKutta4(...) above
 */
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


/* stores the content of a std::vector<Eigen::Vector3d> in side a file */
void StdvectorEigenvecToFile(std::vector<Eigen::Vector3d> v, std::string filename)
{
    std::ofstream output;
    output.open(filename);
    for(auto it = std::begin(v); it != std::end(v); ++it) {
        output << *it << "\n";
    }
    output.close();
}
