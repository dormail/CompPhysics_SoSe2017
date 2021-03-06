//
// Created by mmaile on 3/6/21.
//

#ifndef COMPPHYSICS_SOSE2017_JACOBI_ROTATION_H
#define COMPPHYSICS_SOSE2017_JACOBI_ROTATION_H

#include <Eigen/Dense>

Eigen::MatrixXd householder(Eigen::MatrixXd A);

double off(Eigen::MatrixXd A);
Eigen::MatrixXd jacobi_rotation(Eigen::MatrixXd A);
Eigen::MatrixXd jacobi_rotation(Eigen::MatrixXd A, double eps);

// helper functions
double sgn(double x);

#endif //COMPPHYSICS_SOSE2017_JACOBI_ROTATION_H
