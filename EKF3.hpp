//#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "eigen-3.4.0/Eigen/Core"
#include "eigen-3.4.0/Eigen/LU"

class EKF
{
private:
    const double m_sigmaWr;
    const double m_sigmaWl;
    const double m_sigmaax;
    const double m_sigmaay;
    const double m_T;
    const double m_theta;
    const double m_Rr;
    const double m_Rl;
    const double m_dt;

    Eigen::MatrixXd V;
    Eigen::MatrixXd H;
    Eigen::MatrixXd Q;
    Eigen::MatrixXd R;
    Eigen::MatrixXd x;
    Eigen::MatrixXd y;
    Eigen::MatrixXd I;
    Eigen::MatrixXd P;
    Eigen::MatrixXd Phat;
    Eigen::MatrixXd K;

public:
    EKF();
    ~EKF();
    Eigen::MatrixXd f();
    Eigen::MatrixXd h();
    Eigen::MatrixXd filtering();
};
