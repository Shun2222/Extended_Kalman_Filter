//#pragma once
#include <iostream>
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
    const double m_dt;
    const double m_theta;
    const double m_Rr;
    const double m_Rr;
    const double m_T;

    Eigen::Matrix<double, 2, 2> m_V;
    Eigen::Matrix<double, 2, 2> m_Q;
    Eigen::Matrix<double, 2, 2> m_R;
    Eigen::Matrix<double, 2, 1> m_x;
    Eigen::Matrix<double, 2, 1> m_y;
    Eigen::Matrix<double, 2, 2> m_K;

public:
    EKF();
    ~EKF();

    // 状態を求める関数
    Eigen::MatrixXd f();
    // 観測値を求める関数
    Eigen::MatrixXd h();
    // filteringの実施
    Eigen::MatrixXd filtering();
};
