//
// Created by mmaile on 3/11/21.
//

#ifndef COMPPHYSICS_SOSE2017_DIFFEQ_H
#define COMPPHYSICS_SOSE2017_DIFFEQ_H

#include <Eigen/Dense>

/* functions solving differential equations with different techniques
 * Input:
 * r0, v0 = initial conditions
 * step = length of each integration step
 * N = amount of integration steps
 * m = mass of the particle
 * F = Force on the particle
 */

void euler(Eigen::Vector3d r0,
           Eigen::Vector3d v0,
           double const step,
           double const N,
           double const m,
           Eigen::Vector3d F(Eigen::Vector3d));

void RungeKutta2(Eigen::Vector3d r0,
           Eigen::Vector3d v0,
           double const step,
           int const N,
           double const m,
           Eigen::Vector3d F(Eigen::Vector3d));

void RungeKutta4(Eigen::Vector3d r0,
           Eigen::Vector3d v0,
           double const step,
           int const N,
           double const m,
           Eigen::Vector3d F(Eigen::Vector3d));

double E(double mass,
         Eigen::Vector3d v,
         Eigen::Vector3d r,
         double V(Eigen::Vector3d));

#endif //COMPPHYSICS_SOSE2017_DIFFEQ_H
