//
// Created by mmaile on 3/12/21.
//

#ifndef COMPPHYSICS_SOSE2017_KEPLER_H
#define COMPPHYSICS_SOSE2017_KEPLER_H

#include <Eigen/Dense>
#include <Eigen/StdVector>
#include <string>

EIGEN_DEFINE_STL_VECTOR_SPECIALIZATION(Eigen::Vector3d)
#define G 1 // gravitational constant

/* functions to solve stuff with the kepler problem
 * we work with
 *  * a generalized force F := F/m = -G * \vec{r} / r^3
 *     => potential V(r) = -G / r
 */

Eigen::Vector3d F(Eigen::Vector3d r);
double V(Eigen::Vector3d r);


void RungeKutta4(Eigen::Vector3d r0,
                 Eigen::Vector3d v0,
                 double const h,
                 int const N,
                 double const m,
                 Eigen::Vector3d F(Eigen::Vector3d));

std::vector<Eigen::Vector3d> RungeKutta4Vector(Eigen::Vector3d r0,
                 Eigen::Vector3d v0,
                 double const h,
                 int const N,
                 double const m,
                 Eigen::Vector3d F(Eigen::Vector3d));


void StdvectorEigenvecToFile(std::vector<Eigen::Vector3d> vec, std::string filename);

#endif //COMPPHYSICS_SOSE2017_KEPLER_H
