#include "extended_kalman_filter.hpp"


EKF::EKF()
    : m_sigmaax(0.08)
    , m_sigmaay(0.08)
    , m_sigmavx(0.05)
    , m_sigmavy(0.05)
    , m_dt(0.1)
{
    // 誤差の設定
    m_V = Eigen::MatrixXd::Zero(2, 2);
    m_V(0, 0) = m_dt;
    m_V(1, 1) = m_dt;
    m_Q = Eigen::MatrixXd::Zero(2, 2);
    m_Q(0, 0) = m_sigmaax * m_sigmaax;
    m_Q(1, 1) = m_sigmaay * m_sigmaay;
    m_Q = m_V * m_Q * m_V.transpose();

    // 観測値の分散
    m_R = Eigen::MatrixXd::Zero(2, 2);
    m_R(0, 0) = m_sigmavx * m_sigmavx;
    m_R(1, 1) = m_sigmavy * m_sigmavy;

    // 状態値と観測値の初期値
    m_xhat = f();

    m_I = Eigen::MatrixXd::Identity(2, 2); // 単位行列
    m_Phat = Eigen::MatrixXd::Zero(2, 2); // 事後誤差共分散行列
}

EKF::~EKF()
{
}

Eigen::MatrixXd EKF::f()
{
    Eigen::Matrix<double, 2, 1> x(2, 1);
    // get (ax, ay)*dt = (dvx, dvy) from Gyro
    // Vec2 dv = Gyro::getdeltaVelocity();
    // x(0, 0) = dv[0] + m_xhat(0, 0);
    // x(1, 0) = dv[1] + m_xhat(1, 0);
    x(0, 0) = 1.8; // test value
    x(1, 0) = 0.5; // test value
    return x;
}

Eigen::Matrix<double, 2, 1> EKF::h()
{
    Eigen::Matrix<double, 2, 1> x(2, 1);
    // get V from WheelOdometryTask and calc Vx, Vy 
    // double v = WheelOdometryTask::getVelocity;
    x(0, 0) = 1.6; // test value
    x(1, 0) = 0.1; // test value
    return x;
}

Eigen::Matrix<double, 2, 1> EKF::filtering()
{
    //Prediction Step
    m_x = f(); // Predixt State Value
    m_y = h(); // Observation Value
    m_P = m_Phat + m_Q;
    
    // Filtering Step
    m_K = m_P * ( m_P + m_R ).inverse();
    m_xhat = m_x + m_K * ( m_y - m_x ); // estimate State Value
    m_Phat = ( m_I - m_K ) * m_P; // update Phat
    return m_xhat;
}