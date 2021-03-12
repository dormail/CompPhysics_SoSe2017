//
// Created by mmaile on 3/12/21.
//

#ifndef COMPPHYSICS_SOSE2017_KEPLER_H
#define COMPPHYSICS_SOSE2017_KEPLER_H

#include <Eigen/Dense>
#define G 1 // gravitational constant

/* functions to solve stuff with the kepler problem
 * we work with
 *  * a generalized force F := F/m = -G * \vec{r} / r^3
 *     => potential V(r) = -G / r
 */

Eigen::Vector3d F(Eigen::Vector3d r);
double V(Eigen::Vector3d r);


#endif //COMPPHYSICS_SOSE2017_KEPLER_H
